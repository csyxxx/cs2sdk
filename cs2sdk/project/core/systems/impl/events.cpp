#include <pch/pch.hpp>
#include <utilities/memory/memory.hpp>
#include <utilities/addresses/addresses.hpp>
#include <utilities/diag.hpp>
#include <protection/game_addresses.hpp>
#include <core/features/features.hpp>

#include "../systems.hpp"

namespace systems {

	bool events::initialize( )
	{
		// Register only the framework dispatcher; no gameplay handlers are installed.
		if ( !register_listener( "bullet_impact", []( void* event ) { features::on_game_event( "bullet_impact", event ); } ) )
		{
			shutdown( );
			return false;
		}
		if ( !register_listener( "player_hurt", []( void* event ) { features::on_game_event( "player_hurt", event ); } ) )
		{
			shutdown( );
			return false;
		}
		if ( !register_listener( "round_start", []( void* event ) { features::on_game_event( "round_start", event ); } ) )
		{
			shutdown( );
			return false;
		}
		if ( !register_listener( "player_death", []( void* event ) { features::on_game_event( "player_death", event ); } ) )
		{
			shutdown( );
			return false;
		}
		if ( !register_listener( "weapon_fire", []( void* event ) { features::on_game_event( "weapon_fire", event ); } ) )
		{
			shutdown( );
			return false;
		}
		if ( !register_listener( "weapon_reload", []( void* event ) { features::on_game_event( "weapon_reload", event ); } ) )
		{
			shutdown( );
			return false;
		}
		if ( !register_listener( "item_purchase", []( void* event ) { features::on_game_event( "item_purchase", event ); } ) )
		{
			shutdown( );
			return false;
		}
		if ( !register_listener( "item_pickup", []( void* event ) { features::on_game_event( "item_pickup", event ); } ) )
		{
			shutdown( );
			return false;
		}
		if ( !register_listener( "player_spawn", []( void* event ) { features::on_game_event( "player_spawn", event ); } ) )
		{
			shutdown( );
			return false;
		}
		if ( !register_listener( "player_blind", []( void* event ) { features::on_game_event( "player_blind", event ); } ) )
		{
			shutdown( );
			return false;
		}
		if ( !register_listener( "player_footstep", []( void* event ) { features::on_game_event( "player_footstep", event ); } ) )
		{
			shutdown( );
			return false;
		}
		if ( !register_listener( "round_prestart", []( void* event ) { features::on_game_event( "round_prestart", event ); } ) )
		{
			shutdown( );
			return false;
		}
		if ( !register_listener( "round_freeze_end", []( void* event ) { features::on_game_event( "round_freeze_end", event ); } ) )
		{
			shutdown( );
			return false;
		}
		if ( !register_listener( "round_end", []( void* event ) { features::on_game_event( "round_end", event ); } ) )
		{
			shutdown( );
			return false;
		}
		if ( !register_listener( "bomb_beginplant", []( void* event ) { features::on_game_event( "bomb_beginplant", event ); } ) )
		{
			shutdown( );
			return false;
		}
		if ( !register_listener( "bomb_abortplant", []( void* event ) { features::on_game_event( "bomb_abortplant", event ); } ) )
		{
			shutdown( );
			return false;
		}
		if ( !register_listener( "bomb_planted", []( void* event ) { features::on_game_event( "bomb_planted", event ); } ) )
		{
			shutdown( );
			return false;
		}
		if ( !register_listener( "bomb_begindefuse", []( void* event ) { features::on_game_event( "bomb_begindefuse", event ); } ) )
		{
			shutdown( );
			return false;
		}
		if ( !register_listener( "bomb_abortdefuse", []( void* event ) { features::on_game_event( "bomb_abortdefuse", event ); } ) )
		{
			shutdown( );
			return false;
		}
		if ( !register_listener( "bomb_defused", []( void* event ) { features::on_game_event( "bomb_defused", event ); } ) )
		{
			shutdown( );
			return false;
		}
		if ( !register_listener( "bomb_exploded", []( void* event ) { features::on_game_event( "bomb_exploded", event ); } ) )
		{
			shutdown( );
			return false;
		}
		if ( !register_listener( "grenade_thrown", []( void* event ) { features::on_game_event( "grenade_thrown", event ); } ) )
		{
			shutdown( );
			return false;
		}
		if ( !register_listener( "inferno_startburn", []( void* event ) { features::on_game_event( "inferno_startburn", event ); } ) )
		{
			shutdown( );
			return false;
		}
		if ( !register_listener( "inferno_expire", []( void* event ) { features::on_game_event( "inferno_expire", event ); } ) )
		{
			shutdown( );
			return false;
		}
		return true;
	}

	void events::shutdown( )
	{
		for ( auto& entry : m_listeners )
		{
			if ( entry->registered )
			{
				memory::call_vfunc<void>( addresses::globals::game_event_manager, 5, &entry->listener );
				entry->registered = false;
			}
		}

		m_listeners.clear( );
	}

	bool events::register_listener( const char* event_name, handler_fn handler )
	{
		if ( !event_name || !handler || !addresses::globals::game_event_manager )
		{
			return false;
		}

		auto current_entry = std::make_unique<entry>( );
		current_entry->handler = handler;
		current_entry->name = event_name;
		current_entry->registered = false;

		current_entry->vtable_data[ 0 ] = nullptr;
		current_entry->vtable_data[ 1 ] = reinterpret_cast< void* >( &fire_event );
		current_entry->vtable_data[ 2 ] = reinterpret_cast< void* >( &get_debug_id );

		current_entry->listener.vtable = current_entry->vtable_data;
		current_entry->listener.debug_id = static_cast< int >( m_listeners.size( ) + 1 );

		const auto success = memory::call_vfunc<bool>( addresses::globals::game_event_manager, 3, &current_entry->listener, event_name, false );
		if ( !success )
		{
			return false;
		}

		current_entry->registered = true;
		m_listeners.push_back( std::move( current_entry ) );

		return true;
	}

	void events::unregister_listener( const char* event_name )
	{
		if ( !event_name )
		{
			return;
		}

		for ( auto it = m_listeners.begin( ); it != m_listeners.end( ); ++it )
		{
			if ( std::strcmp( ( *it )->name, event_name ) == 0 && ( *it )->registered )
			{
				memory::call_vfunc<void>( addresses::globals::game_event_manager, 5, &( *it )->listener );
				( *it )->registered = false;
				m_listeners.erase( it );
				return;
			}
		}
	}

	void* __fastcall events::fire_event( void* self, void* event )
	{
		const auto current_listener = reinterpret_cast< listener* >( self );

		for ( const auto& entry : m_listeners )
		{
			if ( entry->listener.debug_id == current_listener->debug_id && entry->handler )
			{
				entry->handler( event );
				break;
			}
		}

		return nullptr;
	}

	int __fastcall events::get_debug_id( void* self )
	{
		const auto current_listener = reinterpret_cast< listener* >( self );
		return current_listener->debug_id;
	}

} // namespace systems
