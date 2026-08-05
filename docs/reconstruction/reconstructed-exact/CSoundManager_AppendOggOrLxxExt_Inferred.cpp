// =============================================================================
// CSoundManager_AppendOggOrLxxExt_Inferred  (was FUN_00722790)
// -----------------------------------------------------------------------------
// Stable ID: aa_00722790
// Address:   0x00722790  (autoassault.exe, image base 0x400000)
// Body:      0x00722790–0x007227de (0x4E / 78 bytes)
// System:    client audio / sound path extension
//
// ABI (Confirmed):
//   thiscall: ECX = host* (byte flag @ +0x308)
//   Stack:    char* pathBuf
//   RET 4; void
//
// Semantics (Confirmed):
//   if (*(char*)(host+0x308) == 0) strcat(pathBuf, ".ogg");
//   else                           strcat(pathBuf, "_lxx.ogg");
//   Suffix strings at 0x00A9D9A4 / 0x00AA91A0; copy includes NUL.
//   No bounds check on pathBuf.
//
// Name INFERRED — structural; product symbol open.
// Dual: reviews/A|B_aa_00722790_CSoundManager_AppendOggOrLxxExt_Inferred.md
// Exactness: CF mirrors decompile + full body hex; not modernization.
// Bit-for-bit / runtime / diff: DEFERRED.
// =============================================================================

#include <cstdint>
#include <cstring>

// Retail host: CSoundManager this, or Client_GetMissionCompleteAudioTable()
// singleton (&DAT_00d20210) which shares the +0x308 flag byte.
struct SoundHostFlag308 {
    // ... layout elided ...
    // char flag_ogg_variant; // @ +0x308
};

// Modeled with explicit this; retail binds host in ECX.
extern "C" void __thiscall CSoundManager_AppendOggOrLxxExt_Inferred(
    SoundHostFlag308* host,
    char* pathBuf)
{
    const char* suffix;
    const auto* bytes = reinterpret_cast<const std::uint8_t*>(host);
    if (bytes[0x308] == 0) {
        suffix = ".ogg";        // image VA 0x00A9D9A4
    } else {
        suffix = "_lxx.ogg";    // image VA 0x00AA91A0
    }

    // Retail: strlen-style walks + rep movsd/movsb (includes terminating NUL).
    std::strcat(pathBuf, suffix);
}

// Ghidra symbol twin (scaffold name retained for xref).
extern "C" void __thiscall FUN_00722790(SoundHostFlag308* host, char* pathBuf)
{
    CSoundManager_AppendOggOrLxxExt_Inferred(host, pathBuf);
}
