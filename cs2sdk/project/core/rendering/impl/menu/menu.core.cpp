#include <pch/pch.hpp>
#include <utilities/memory/memory.hpp>
#include <core/settings.hpp>
#include <core/features/features.hpp>
#include "../../rendering.hpp"

namespace rendering {

	void menu::draw( )
	{
		if ( m_open != m_last_open )
		{
			if ( addresses::globals::input_system )
			{
				if ( m_open )
				{
					m_saved_relative_mouse = memory::read<std::uint8_t>( addresses::globals::input_system + 84 );
					memory::call_vfunc<void>( addresses::globals::input_system, 76, false );
					apply_saved_cursor( );
				}
				else
				{
					m_has_saved_cursor = GetCursorPos( &m_saved_cursor ) != FALSE;
					memory::call_vfunc<void>( addresses::globals::input_system, 76, m_saved_relative_mouse != 0 );
				}
			}
			m_last_open = m_open;
		}

		xui::begin( );
		if ( m_open && xui::begin_window( "CS2 SDK", m_x, m_y, m_w, m_h, true, 540.0f, 360.0f ) )
		{
			xui::text( "Framework", { 173, 192, 255, 255 } );
			xui::keybind( "Menu key", settings::menu_key.value );
			if ( settings::menu_key.value == 0 ) settings::menu_key.value = VK_DELETE;
			xui::text_input( "Profile", m_config_name, 64 );
			const std::wstring profile( m_config_name.begin( ), m_config_name.end( ) );
			if ( xui::button( "Save profile", 180.0f, 30.0f ) )
				m_status = !profile.empty( ) && config::registry::save( profile ) ? "Profile saved" : "Save failed";
			if ( xui::button( "Load profile", 180.0f, 30.0f ) )
				m_status = !profile.empty( ) && config::registry::load( profile ) ? "Profile loaded" : "Load failed";
			if ( !m_status.empty( ) ) xui::text( m_status, { 190, 190, 200, 255 } );
			features::on_menu( );
			xui::end_window( );
		}
		xui::end( );
	}

	void menu::shutdown( ) const
	{
		if ( m_last_open && addresses::globals::input_system )
			memory::call_vfunc<void>( addresses::globals::input_system, 76, m_saved_relative_mouse != 0 );
	}

	void menu::apply_saved_cursor( )
	{
		if ( m_has_saved_cursor ) SetCursorPos( m_saved_cursor.x, m_saved_cursor.y );
		SetCursor( LoadCursor( nullptr, IDC_ARROW ) );
	}

} // namespace rendering
