#include <pch/pch.hpp>
#include <utilities/memory/memory.hpp>
#include <utilities/logging/logging.hpp>
#include <protection/game_addresses.hpp>
#include <core/rendering/rendering.hpp>
#include <core/features/features.hpp>
#include <core/settings.hpp>
#include "../hooks.hpp"

namespace hooks {

	bool cheat::initialize( )
	{
		if ( !hooking::manager::create( {
			{ &m_present, reinterpret_cast<void*>( &present ), "present", addresses::functions::present },
			{ &m_resize_buffers, reinterpret_cast<void*>( &resize_buffers ), "resize_buffers", addresses::functions::resize_buffers }
		} ) )
			return false;

		const hooking::manager::entry framework_hooks[] {
			{ &m_frame_stage_notify, reinterpret_cast<void*>( &frame_stage_notify ), "frame_stage_notify", PATTERN( patterns::frame_stage_notify ) },
			{ &m_create_move, reinterpret_cast<void*>( &create_move ), "create_move", PATTERN( patterns::create_move ) },
			{ &m_add_entity, reinterpret_cast<void*>( &add_entity ), "add_entity", PATTERN( patterns::add_entity ) },
			{ &m_remove_entity, reinterpret_cast<void*>( &remove_entity ), "remove_entity", PATTERN( patterns::remove_entity ) },
			{ &m_render_view, reinterpret_cast<void*>( &render_view ), "render_view", PATTERN( patterns::render_view ) },
			{ &m_level_initialization, reinterpret_cast<void*>( &level_initialization ), "level_initialization", PATTERN( patterns::level_initialization ) },
			{ &m_level_shutdown, reinterpret_cast<void*>( &level_shutdown ), "level_shutdown", PATTERN( patterns::level_shutdown ) },
		};
		for ( const auto& entry : framework_hooks )
		{
			if ( !hooking::manager::create( { entry } ) )
			{
				logging::console::print( xs( "required framework hook unavailable: {}" ), entry.name );
				shutdown( );
				return false;
			}
		}
		return true;
	}

	void cheat::shutdown( )
	{
		m_present.reset( );
		m_resize_buffers.reset( );
		m_wnd_proc.reset( );
		m_om_set_render_targets.reset( );
		m_cmd_interpreter.reset( );
		m_frame_stage_notify.reset( );
		m_on_client_frame_simulate.reset( );
		m_send_tick_packet.reset( );
		m_create_move.reset( );
		m_handle_view_angles.reset( );
		m_add_entity.reset( );
		m_remove_entity.reset( );
		m_render_view.reset( );
		m_draw_skybox_array.reset( );
		m_light_scene_object.reset( );
		m_draw_scene_object_array.reset( );
		m_draw_scene_object.reset( );
		m_is_glowing.reset( );
		m_get_glow_color.reset( );
		m_generate_primitives.reset( );
		m_parse_report_hit.reset( );
		m_setup_fog.reset( );
		m_set_shader_param.reset( );
		m_set_postprocess_vec.reset( );
		m_override_view.reset( );
		m_update_fov_sensitivity.reset( );
		m_render_scope.reset( );
		m_render_crosshair.reset( );
		m_prepare_scene_material.reset( );
		m_post_network_data_received.reset( );
		m_draw_overhead.reset( );
		m_draw_legs.reset( );
		m_get_transforms_for_hitbox_list.reset( );
		m_sort_primitives.reset( );
		m_get_inaccuracy.reset( );
		m_get_interpolated_shoot_position.reset( );
		m_level_initialization.reset( );
		m_level_shutdown.reset( );
		m_read_frame_input.reset( );
		m_process_input_event.reset( );
		m_render_decals.reset( );
		m_render_smoke.reset( );
		m_render_smoke_map.reset( );
		m_render_smoke_unmap.reset( );
		m_draw_flash_effect.reset( );
		m_set_info.reset( );
	}

	HRESULT __fastcall cheat::present( IDXGISwapChain* thisptr, UINT sync_interval, UINT flags )
	{
		rendering::g_context.on_present( thisptr );

		if ( !m_wnd_proc.is_enabled( ) && rendering::g_context.get_window( ) )
		{
			if ( m_wnd_proc.create( reinterpret_cast< void* >( GetWindowLongPtrW( rendering::g_context.get_window( ), GWLP_WNDPROC ) ), reinterpret_cast<void*>( &wnd_proc ) ) )
			{
				m_wnd_proc.enable( );
			}
		}

		if ( !m_om_set_render_targets.is_enabled( ) && rendering::g_context.is_initialized( ) )
		{
			const auto om_addr = memory::get_vfunc( reinterpret_cast< std::uintptr_t >( rendering::g_context.get_context( ) ), 33 );
			if ( m_om_set_render_targets.create( reinterpret_cast< void* >( om_addr ), reinterpret_cast<void*>( &om_set_render_targets ) ) )
			{
				m_om_set_render_targets.enable( );
			}
		}

		return m_present.call<HRESULT>( thisptr, sync_interval, flags );
	}

	HRESULT __fastcall cheat::resize_buffers( IDXGISwapChain* thisptr, UINT buffer_count, UINT width, UINT height, DXGI_FORMAT new_format, UINT swap_chain_flags )
	{
		rendering::g_context.on_resize_buffers( );

		const auto result = m_resize_buffers.call<long>( thisptr, buffer_count, width, height, new_format, swap_chain_flags );
		if ( SUCCEEDED( result ) )
		{
			rendering::g_context.on_resize_buffers_post( thisptr );
		}

		return result;
	}

	LRESULT __stdcall cheat::wnd_proc( HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam )
	{
		if ( msg == WM_ACTIVATE && LOWORD( wparam ) != WA_INACTIVE && rendering::g_menu.is_open( ) && rendering::g_context.get_window( ) == hwnd )
		{
			if ( addresses::globals::input_system )
			{
				memory::call_vfunc<void>( addresses::globals::input_system, 76, false );
			}

			SetCursor( LoadCursor( nullptr, IDC_ARROW ) );
			rendering::g_menu.apply_saved_cursor( );
		}

		if ( msg == WM_KEYDOWN && !( lparam & ( 1 << 30 ) ) && static_cast< int >( wparam ) == settings::menu_key.value )
		{
			rendering::g_menu.toggle( );
			return 0;
		}

		xui::wndproc( msg, wparam, lparam );

		if ( rendering::g_menu.is_open( ) )
		{
			switch ( msg )
			{
			case WM_LBUTTONDOWN: case WM_LBUTTONUP: case WM_LBUTTONDBLCLK:
			case WM_RBUTTONDOWN: case WM_RBUTTONUP: case WM_RBUTTONDBLCLK:
			case WM_MBUTTONDOWN: case WM_MBUTTONUP: case WM_MBUTTONDBLCLK:
			case WM_MOUSEWHEEL: case WM_MOUSEHWHEEL:
			case WM_MOUSEMOVE:
				return 0;
			default:
				break;
			}
		}

		return m_wnd_proc.call<LRESULT>( hwnd, msg, wparam, lparam );
	}

	void __stdcall cheat::om_set_render_targets( ID3D11DeviceContext* ctx, UINT num_views, ID3D11RenderTargetView* const* rtvs, ID3D11DepthStencilView* dsv )
	{
		m_om_set_render_targets.call<void>( ctx, num_views, rtvs, dsv );
	}


	void __fastcall cheat::frame_stage_notify( std::uintptr_t thisptr, int stage )
	{
		if ( systems::g_entities.is_empty( ) )
			systems::g_entities.force_update( );
		systems::g_local.update( );
		features::on_frame_stage( stage );
		m_frame_stage_notify.call<void>( thisptr, stage );
	}

	void __fastcall cheat::create_move( std::uintptr_t thisptr, int slot, bool active )
	{
		m_create_move.call<void>( thisptr, slot, active );
		if ( slot != 0 || !active )
			return;
		systems::g_local.update( );
		systems::g_input.update( );
		if ( auto* cmd = systems::g_input.get( ); cmd && features::on_create_move( cmd ) )
			systems::g_input.apply( );
	}

	void __fastcall cheat::add_entity( std::uintptr_t thisptr, std::uintptr_t entity, std::uint32_t handle )
	{
		systems::g_entities.on_add_entity( entity, handle );
		m_add_entity.call<void>( thisptr, entity, handle );
	}

	void __fastcall cheat::remove_entity( std::uintptr_t thisptr, std::uintptr_t entity, std::uint32_t handle )
	{
		systems::g_entities.on_remove_entity( entity, handle );
		m_remove_entity.call<void>( thisptr, entity, handle );
	}

	void __fastcall cheat::render_view( std::uintptr_t thisptr )
	{
		m_render_view.call<void>( thisptr );
		systems::g_view.update( thisptr + 0x10 );
		systems::g_frame_data.update( );
	}

	std::uintptr_t __fastcall cheat::level_initialization( std::uintptr_t a1, const char* new_map )
	{
		systems::g_input.reset_weapon_select_state( );
		const auto result = m_level_initialization.call<std::uintptr_t>( a1, new_map );
		features::on_level_init( new_map );
		return result;
	}

	std::uintptr_t __fastcall cheat::level_shutdown( std::uintptr_t a1 )
	{
		features::on_level_shutdown( );
		systems::g_input.reset_weapon_select_state( );
		systems::g_local.reset( );
		systems::g_frame_data.update( );
		systems::g_view.update( 0 );
		return m_level_shutdown.call<std::uintptr_t>( a1 );
	}

	// Optional engine detours retain the source ABI and forward unchanged.
	// They are deliberately not installed by initialize().
	void __fastcall cheat::cmd_interpreter( std::uintptr_t render_thread, std::uintptr_t item, std::uint8_t flag )
	{
		return m_cmd_interpreter.call<void>( render_thread, item, flag );
	}

	void __fastcall cheat::on_client_frame_simulate( std::uintptr_t thisptr, std::uintptr_t event )
	{
		return m_on_client_frame_simulate.call<void>( thisptr, event );
	}

	void __fastcall cheat::send_tick_packet( std::uintptr_t thisptr, int reason )
	{
		return m_send_tick_packet.call<void>( thisptr, reason );
	}

	void __fastcall cheat::handle_view_angles( std::uintptr_t thisptr, int a2 )
	{
		return m_handle_view_angles.call<void>( thisptr, a2 );
	}

	void __fastcall cheat::draw_skybox_array( std::uintptr_t thisptr, std::uintptr_t a2, std::uintptr_t mesh_array, int mesh_count, int a5, std::uintptr_t a6, std::uintptr_t a7, std::uintptr_t a8 )
	{
		return m_draw_skybox_array.call<void>( thisptr, a2, mesh_array, mesh_count, a5, a6, a7, a8 );
	}

	std::uintptr_t __fastcall cheat::light_scene_object( std::uintptr_t thisptr, std::uintptr_t object, std::uintptr_t a3 )
	{
		return m_light_scene_object.call<std::uintptr_t>( thisptr, object, a3 );
	}

	void __fastcall cheat::draw_scene_object_array( std::uintptr_t thisptr, std::uintptr_t a2, std::uintptr_t object_array )
	{
		return m_draw_scene_object_array.call<void>( thisptr, a2, object_array );
	}

	std::uintptr_t __fastcall cheat::draw_scene_object( std::uintptr_t a1, std::uintptr_t a2, std::uintptr_t batch, int batch_count, int a5, std::uintptr_t a6, std::uintptr_t a7, std::uintptr_t a8 )
	{
		return m_draw_scene_object.call<std::uintptr_t>( a1, a2, batch, batch_count, a5, a6, a7, a8 );
	}

	bool __fastcall cheat::is_glowing( std::uintptr_t glow_property )
	{
		return m_is_glowing.call<bool>( glow_property );
	}

	void __fastcall cheat::get_glow_color( std::uintptr_t glow_property, float* color )
	{
		return m_get_glow_color.call<void>( glow_property, color );
	}

	void __fastcall cheat::generate_primitives( std::uintptr_t thisptr, std::uintptr_t scene_object, std::uintptr_t scene_view, std::uintptr_t primitive_buffer )
	{
		return m_generate_primitives.call<void>( thisptr, scene_object, scene_view, primitive_buffer );
	}

	std::uintptr_t __fastcall cheat::parse_report_hit( std::uintptr_t thisptr, std::uint8_t deleting )
	{
		// Legacy ABI from the source checkout; known stale. Keep uninstalled
		// until the target signature and prototype have been reverified.
		return m_parse_report_hit.call<std::uintptr_t>( thisptr, deleting );
	}

	std::uintptr_t __fastcall cheat::setup_fog( __m128i* output, int* mode )
	{
		return m_setup_fog.call<std::uintptr_t>( output, mode );
	}

	std::uintptr_t __fastcall cheat::set_shader_param( __m128i* map, std::uint32_t hash, __m128i* value )
	{
		return m_set_shader_param.call<std::uintptr_t>( map, hash, value );
	}

	std::uintptr_t __fastcall cheat::set_postprocess_vec( __m128i* map, std::uint32_t hash, __m128i* value )
	{
		return m_set_postprocess_vec.call<std::uintptr_t>( map, hash, value );
	}

	void __fastcall cheat::override_view( std::uintptr_t thisptr, std::uintptr_t view_setup )
	{
		return m_override_view.call<void>( thisptr, view_setup );
	}

	void __fastcall cheat::update_fov_sensitivity( std::uintptr_t thisptr )
	{
		return m_update_fov_sensitivity.call<void>( thisptr );
	}

	void __fastcall cheat::render_scope( std::uintptr_t a1, std::uintptr_t a2 )
	{
		return m_render_scope.call<void>( a1, a2 );
	}

	bool __fastcall cheat::render_crosshair( std::uintptr_t a1 )
	{
		return m_render_crosshair.call<bool>( a1 );
	}

	float __fastcall cheat::prepare_scene_material( std::uintptr_t material, void* a2, float a3 )
	{
		return m_prepare_scene_material.call<float>( material, a2, a3 );
	}

	void __fastcall cheat::post_network_data_received( std::uintptr_t thisptr )
	{
		return m_post_network_data_received.call<void>( thisptr );
	}

	bool __fastcall cheat::draw_overhead( std::uintptr_t pawn, std::uint32_t player_slot )
	{
		return m_draw_overhead.call<bool>( pawn, player_slot );
	}

	std::uintptr_t __fastcall cheat::draw_legs( std::uintptr_t a1, std::uintptr_t a2, std::uintptr_t a3, std::uintptr_t a4, std::uintptr_t a5 )
	{
		return m_draw_legs.call<std::uintptr_t>( a1, a2, a3, a4, a5 );
	}

	bool __fastcall cheat::get_transforms_for_hitbox_list( std::uintptr_t a1, std::uintptr_t a2, int* a3 )
	{
		return m_get_transforms_for_hitbox_list.call<bool>( a1, a2, a3 );
	}

	void __fastcall cheat::sort_primitives( std::uintptr_t thisptr, std::uintptr_t a2, std::uintptr_t a3, std::uint32_t a4 )
	{
		return m_sort_primitives.call<void>( thisptr, a2, a3, a4 );
	}

	float __fastcall cheat::get_inaccuracy( std::uintptr_t thisptr, float* a2, float* a3 )
	{
		return m_get_inaccuracy.call<float>( thisptr, a2, a3 );
	}

	float* __fastcall cheat::get_interpolated_shoot_position( std::uintptr_t thisptr, float* out, int* tick_frac )
	{
		return m_get_interpolated_shoot_position.call<float*>( thisptr, out, tick_frac );
	}

	void __fastcall cheat::read_frame_input( std::uintptr_t a1, std::uint32_t a2 )
	{
		return m_read_frame_input.call<void>( a1, a2 );
	}

	void __fastcall cheat::process_input_event( std::uintptr_t csgo_input, int slot, float frametime )
	{
		return m_process_input_event.call<void>( csgo_input, slot, frametime );
	}

	std::uintptr_t __fastcall cheat::render_decals( std::uintptr_t render_context, std::uintptr_t** render_view, bool pass_flag_a, bool pass_flag_b )
	{
		return m_render_decals.call<std::uintptr_t>( render_context, render_view, pass_flag_a, pass_flag_b );
	}

	void __fastcall cheat::render_smoke( std::uintptr_t a1, std::uintptr_t a2, int a3, int a4, std::uintptr_t a5, std::uintptr_t a6 )
	{
		return m_render_smoke.call<void>( a1, a2, a3, a4, a5, a6 );
	}

	std::uintptr_t __fastcall cheat::render_smoke_map( std::uintptr_t thisptr, std::size_t size, std::uintptr_t* out_ptr )
	{
		return m_render_smoke_map.call<std::uintptr_t>( thisptr, size, out_ptr );
	}

	void __fastcall cheat::render_smoke_unmap( std::uintptr_t thisptr, std::uintptr_t ctx, std::size_t size )
	{
		return m_render_smoke_unmap.call<void>( thisptr, ctx, size );
	}

	char __fastcall cheat::set_info( std::uintptr_t rcx, std::uintptr_t a2 )
	{
		return m_set_info.call<char>( rcx, a2 );
	}

	void __fastcall cheat::draw_flash_effect( std::uintptr_t a1, int a2, std::uintptr_t* a3, std::uintptr_t a4, __m128* a5 )
	{
		return m_draw_flash_effect.call<void>( a1, a2, a3, a4, a5 );
	}

} // namespace hooks
