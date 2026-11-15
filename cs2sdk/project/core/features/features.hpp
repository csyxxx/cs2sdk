#pragma once

#include <memory>
#include <vector>
#include <core/systems/systems.hpp>

namespace features {

	// Register modules in initialize(), before hooks are installed. Callbacks run
	// on the host's game/render threads; modules must synchronize shared state.
	class module
	{
	public:
		virtual ~module( ) = default;
		// Return true only after changing the command, to request apply()/CRC.
		virtual bool on_create_move( systems::input::usercmd* ) { return false; }
		virtual void on_frame_stage( int ) {}
		virtual void on_render( xdraw::draw_list& ) {}
		virtual void on_menu( ) {}
		virtual void on_game_event( const char*, void* ) {}
		virtual void on_level_init( const char* ) {}
		virtual void on_level_shutdown( ) {}
	};

	inline std::vector<std::unique_ptr<module>> modules{};
	void initialize( );

	inline bool on_create_move( systems::input::usercmd* cmd )
	{
		bool modified{};
		for ( const auto& entry : modules )
			modified = entry->on_create_move( cmd ) || modified;
		return modified;
	}

	inline void on_frame_stage( int stage )
	{
		for ( const auto& entry : modules ) entry->on_frame_stage( stage );
	}
	inline void on_render( xdraw::draw_list& list )
	{
		for ( const auto& entry : modules ) entry->on_render( list );
	}
	inline void on_menu( )
	{
		for ( const auto& entry : modules ) entry->on_menu( );
	}
	inline void on_game_event( const char* name, void* event )
	{
		for ( const auto& entry : modules ) entry->on_game_event( name, event );
	}
	inline void on_level_init( const char* name )
	{
		for ( const auto& entry : modules ) entry->on_level_init( name );
	}
	inline void on_level_shutdown( )
	{
		for ( const auto& entry : modules ) entry->on_level_shutdown( );
	}

} // namespace features
