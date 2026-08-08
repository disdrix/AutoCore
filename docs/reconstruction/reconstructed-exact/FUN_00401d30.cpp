// =============================================================================
// FUN_00401d30  (Ghidra alias of BasicStringFlag_CtorFromStringAndChar_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00401d30
// Address:   0x00401d30–0x00401d83 inclusive (84 B / 0x54)
// Module:    autoassault.exe, image base 0x400000
// Preferred: BasicStringFlag_CtorFromStringAndChar_Inferred
// Wave:      MEGA-065 OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving; see named clean for full notes.
// =============================================================================

#include <cstdint>

struct BasicString_0x1c {
    std::uint8_t raw[0x1C];
};

struct BasicStringFlag {
    BasicString_0x1c str;
    std::uint8_t     flag;
};

extern "C" BasicString_0x1c* __thiscall
BasicString_CopyCtor(BasicString_0x1c* self, const BasicString_0x1c* other);

// Ghidra name — same body / ABI as named clean.
// Stack: dest*, src string*, char*; EAX=dest; RET 0xC.
extern "C" BasicStringFlag* __stdcall FUN_00401d30(
    BasicStringFlag* dest,
    const BasicString_0x1c* src,
    const std::uint8_t* flag_src)
{
    BasicString_CopyCtor(&dest->str, src);
    dest->flag = *flag_src;
    return dest;
}
