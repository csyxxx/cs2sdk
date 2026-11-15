#include <pch/pch.hpp>
#include "memory.hpp"

namespace memory {

    std::string read_string( std::uintptr_t address, std::size_t max_length )
    {
        if ( address < 0x10000 || max_length == 0 ||
            max_length > std::numeric_limits<std::uintptr_t>::max( ) - address )
            return {};

        std::string result;
        std::array<char, 256> buffer{};
        while ( result.size( ) < max_length )
        {
            const auto cursor = address + result.size( );
            MEMORY_BASIC_INFORMATION region{};
            if ( !VirtualQuery( reinterpret_cast<const void*>( cursor ), &region, sizeof( region ) ) ||
                region.State != MEM_COMMIT || ( region.Protect & ( PAGE_NOACCESS | PAGE_GUARD ) ) )
                return {};
            const auto protection = region.Protect & 0xffu;
            if ( protection != PAGE_READONLY && protection != PAGE_READWRITE && protection != PAGE_WRITECOPY &&
                protection != PAGE_EXECUTE_READ && protection != PAGE_EXECUTE_READWRITE && protection != PAGE_EXECUTE_WRITECOPY )
                return {};

            const auto base = reinterpret_cast<std::uintptr_t>( region.BaseAddress );
            if ( cursor < base || cursor - base >= region.RegionSize )
                return {};
            const auto size = std::min( { buffer.size( ), max_length - result.size( ),
                region.RegionSize - static_cast<std::size_t>( cursor - base ) } );
            SIZE_T copied{};
            // Copy without dereferencing game pointers or raising first-chance faults.
            if ( !ReadProcessMemory( GetCurrentProcess( ), reinterpret_cast<const void*>( cursor ),
                buffer.data( ), size, &copied ) || copied != size )
                return {};

            const auto end = std::find( buffer.begin( ), buffer.begin( ) + size, '\0' );
            result.append( buffer.data( ), static_cast<std::size_t>( end - buffer.begin( ) ) );
            if ( end != buffer.begin( ) + size )
                return result;
        }
        return result;
    }
}
