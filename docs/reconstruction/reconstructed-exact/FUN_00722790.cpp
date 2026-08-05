// =============================================================================
// FUN_00722790  (scaffold twin of CSoundManager_AppendOggOrLxxExt_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00722790
// Address:   0x00722790  (autoassault.exe, image base 0x400000)
// Body:      0x00722790–0x007227de (0x4E / 78 bytes)
// System:    client audio / sound path extension
// Generated: 2026-07-23 scaffold; refined 2026-08-04 W38-AG dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical clean: CSoundManager_AppendOggOrLxxExt_Inferred.cpp
// Dual: reviews/A|B_aa_00722790_CSoundManager_AppendOggOrLxxExt_Inferred.md
// =============================================================================

#include <cstdint>

// PURPOSE: Append ".ogg" or "_lxx.ogg" to pathBuf based on host+0x308.
// ABI: thiscall ECX=host*, stack char* pathBuf, RET 4, void, leaf.
// Strings: 0x00A9D9A4 ".ogg"; 0x00AA91A0 "_lxx.ogg"

void __thiscall FUN_00722790(void* host, char* pathBuf)
{
    const char* suffix_start;
    const char* suffix_end;
    char* dst;
    std::uint32_t n_dwords;
    std::uint32_t n_bytes;

    // Default suffix = "_lxx.ogg"; replace with ".ogg" when flag@+0x308 == 0.
    suffix_start = "_lxx.ogg";
    if (*reinterpret_cast<char*>(reinterpret_cast<char*>(host) + 0x308) == '\0') {
        suffix_start = ".ogg";
    }

    // strlen(suffix) + 1 (walk past NUL so length includes terminator)
    suffix_end = suffix_start;
    while (*suffix_end != '\0') {
        ++suffix_end;
    }
    ++suffix_end; // one past NUL → length includes NUL for copy

    // Find end of pathBuf
    dst = pathBuf;
    while (*dst != '\0') {
        ++dst;
    }

    // rep movsd + residual rep movsb (MSVC strcat of fixed literal)
    {
        const auto len = static_cast<std::uint32_t>(suffix_end - suffix_start);
        const char* src = suffix_start;
        n_dwords = len >> 2;
        while (n_dwords != 0) {
            *reinterpret_cast<std::uint32_t*>(dst) =
                *reinterpret_cast<const std::uint32_t*>(src);
            src += 4;
            dst += 4;
            --n_dwords;
        }
        n_bytes = len & 3;
        while (n_bytes != 0) {
            *dst = *src;
            ++src;
            ++dst;
            --n_bytes;
        }
    }
}
