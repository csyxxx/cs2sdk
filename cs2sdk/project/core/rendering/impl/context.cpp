#include <pch/pch.hpp>
#include <core/systems/systems.hpp>
#include <core/features/features.hpp>

#include "../rendering.hpp"

namespace rendering {

	bool context::try_bind_ui_assets( )
	{
		if ( this->m_ui_assets_ready )
		{
			return true;
		}

		g_fonts.initialize( );

		this->m_ui_assets_ready = true;
		return true;
	}

	bool context::initialize( IDXGISwapChain* swap_chain )
	{
		if ( this->m_initialized )
		{
			return true;
		}

		if ( FAILED( swap_chain->GetDevice( __uuidof( ID3D11Device ), reinterpret_cast< void** >( &this->m_device ) ) ) )
		{
			return false;
		}

		this->m_device->GetImmediateContext( &this->m_context );

		DXGI_SWAP_CHAIN_DESC desc{};
		if ( FAILED( swap_chain->GetDesc( &desc ) ) )
		{
			this->shutdown( );
			return false;
		}

		this->m_window = desc.OutputWindow;

		this->create_rtv( swap_chain );
		if ( !this->m_rtv || !this->setup_zdraw( this->m_window ) )
		{
			this->shutdown( );
			return false;
		}

		g_menu.initialize_graphics( );
		this->try_bind_ui_assets( );

		this->m_initialized = true;
		return true;
	}

	void context::shutdown( )
	{
		if ( this->m_rtv )
		{
			this->m_rtv->Release( );
			this->m_rtv = nullptr;
		}

		if ( this->m_context )
		{
			this->m_context->Release( );
			this->m_context = nullptr;
		}

		if ( this->m_device )
		{
			this->m_device->Release( );
			this->m_device = nullptr;
		}

		this->m_window = nullptr;
		this->m_initialized = false;
	}

	void context::on_present( IDXGISwapChain* swap_chain )
	{
		if ( !this->m_initialized ) [[unlikely]]
		{
			if ( !this->initialize( swap_chain ) ) [[unlikely]]
			{
				return;
			}
		}

		this->try_bind_ui_assets( );
		if ( !this->m_rtv )
			return;

		m_context->OMSetRenderTargets( 1, &this->m_rtv, nullptr );
		xdraw::begin_frame( true );
		features::on_render( xdraw::get( xdraw::layer::bottom ) );
		g_menu.draw( );
		xdraw::end_frame( );
	}

	void context::on_resize_buffers( )
	{
		if ( this->m_rtv )
		{
			this->m_rtv->Release( );
			this->m_rtv = nullptr;
		}
	}

	void context::on_resize_buffers_post( IDXGISwapChain* swap_chain )
	{
		if ( this->m_initialized ) this->create_rtv( swap_chain );
	}

	void context::create_rtv( IDXGISwapChain* swap_chain )
	{
		if ( !this->m_device || !this->m_context ) return;
		ID3D11Texture2D* back_buffer{ nullptr };
		if ( SUCCEEDED( swap_chain->GetBuffer( 0, __uuidof( ID3D11Texture2D ), reinterpret_cast< void** >( &back_buffer ) ) ) )
		{
			this->m_device->CreateRenderTargetView( back_buffer, nullptr, &this->m_rtv );

			D3D11_TEXTURE2D_DESC back_buffer_desc{};
			back_buffer->GetDesc( &back_buffer_desc );

			D3D11_VIEWPORT viewport{};
			viewport.TopLeftX = 0.0f;
			viewport.TopLeftY = 0.0f;
			viewport.Width = static_cast< float >( back_buffer_desc.Width );
			viewport.Height = static_cast< float >( back_buffer_desc.Height );
			viewport.MinDepth = 0.0f;
			viewport.MaxDepth = 1.0f;
			this->m_context->RSSetViewports( 1, &viewport );

			back_buffer->Release( );
		}
	}

	bool context::setup_zdraw( HWND window )
	{
		if ( !xdraw::initialize( this->m_device, this->m_context ) )
		{
			return false;
		}

		return xui::initialize( window );
	}

} // namespace rendering
