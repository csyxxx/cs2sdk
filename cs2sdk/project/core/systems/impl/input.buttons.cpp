#include <pch/pch.hpp>
#include <core/systems/systems.hpp>

namespace systems {

	void input::clear_attack( usercmd* cmd ) const
	{
		if ( !cmd )
			return;
		constexpr auto attacks = cstypes::command_buttons::in_attack | cstypes::command_buttons::in_second_attack;
		cmd->buttons.value &= ~attacks;
		cmd->buttons.value_changed |= attacks;
		cmd->buttons.value_scroll &= ~attacks;
		cmd->csgo_user_cmd.set_attack1_start_history_index( -1 );
		cmd->csgo_user_cmd.set_attack2_start_history_index( -1 );
		const auto base = cmd->csgo_user_cmd.mutable_base( );
		if ( !base )
			return;
		if ( const auto buttons = base->mutable_buttons_pb( ) )
		{
			buttons->set_buttonstate1( cmd->buttons.value );
			buttons->set_buttonstate2( cmd->buttons.value_changed );
			buttons->set_buttonstate3( cmd->buttons.value_scroll );
		}
		for ( int i = 0; i < base->subtick_moves_size( ); ++i )
		{
			const auto step = base->mutable_subtick_moves( i );
			if ( step && step->m_has_bits.test( 0x1u ) && ( step->button( ) & attacks ) )
			{
				step->set_button( step->button( ) & ~attacks );
				if ( step->button( ) == 0 )
					step->set_pressed( false );
			}
		}
	}
}
