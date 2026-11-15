#pragma once

#include <cstddef>
#include <string>
#include <vector>

namespace rendering {

	class context
	{
	public:
		bool initialize( IDXGISwapChain* swap_chain );
		void shutdown( );
		void on_present( IDXGISwapChain* swap_chain );
		void on_resize_buffers( );
		void on_resize_buffers_post( IDXGISwapChain* swap_chain );

		[[nodiscard]] HWND get_window( ) const { return this->m_window; }
		[[nodiscard]] ID3D11Device* get_device( ) const { return this->m_device; }
		[[nodiscard]] ID3D11DeviceContext* get_context( ) const { return this->m_context; }
		[[nodiscard]] bool is_initialized( ) const { return this->m_initialized; }
		[[nodiscard]] bool ui_assets_ready( ) const { return this->m_ui_assets_ready; }
        ID3D11RenderTargetView* get_rtv( ) const { return this->m_rtv; }

	private:
		void create_rtv( IDXGISwapChain* swap_chain );
		bool setup_zdraw( HWND window );
		bool try_bind_ui_assets( );

		ID3D11Device* m_device{ nullptr };
		ID3D11DeviceContext* m_context{ nullptr };
		ID3D11RenderTargetView* m_rtv{ nullptr };
		HWND m_window{ nullptr };
		bool m_initialized{ false };
		bool m_ui_assets_ready{ false };
	};

	class menu
	{
	public:
		void initialize_graphics( ) {}
		void draw( );
		void shutdown( ) const;
		void toggle( ) { m_open = !m_open; }
		[[nodiscard]] bool is_open( ) const { return m_open; }
		void apply_saved_cursor( );

	private:
		bool m_open{};
		bool m_last_open{};
		std::uint8_t m_saved_relative_mouse{};
		POINT m_saved_cursor{};
		bool m_has_saved_cursor{};
		float m_x{100.0f}, m_y{100.0f}, m_w{660.0f}, m_h{420.0f};
		std::string m_config_name{"default"};
		std::string m_status{};
	};

	class fonts
	{
	public:
		enum class size : std::uint8_t
		{
			petite,
			normal,
			big,
			count
		};

		struct family_t
		{
			std::array<xdraw::font*, static_cast< std::size_t >( size::count )> sizes{ };

			xdraw::font* operator[]( size size ) const { return this->sizes[ static_cast< std::size_t >( size ) ]; }
			xdraw::font*& operator[]( size size ) { return this->sizes[ static_cast< std::size_t >( size ) ]; }
		};

		void initialize( );

		family_t inter_medium{};
		family_t inter_bold{};
		family_t smallest_pixel7{};

	private:
		family_t cjk_fallback{};
		std::vector<std::byte> cjk_font_data{};

		void load_family( family_t& family, std::span<const std::byte> data, const std::array<float, static_cast< std::size_t >( size::count )>& sizes );
	};

	inline context g_context{};
	inline menu g_menu{};
	inline fonts g_fonts{};

} // namespace rendering
