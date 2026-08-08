// =============================================================================
// FUN_00402040  (alias of BasicStringFlag_CopyCtor_EdiSrc_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00402040
// Address:   0x00402040–0x0040208c inclusive (77 B / 0x4D)
// Module:    autoassault.exe, image base 0x400000
// System:    missions-progression partition parent; unit = shared aggregate copy-ctor
// Wave:      MEGA-080 OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler + disassemble_function +
//            read_memory. Not modernization. Bit-for-bit / runtime: DEFERRED.
// Canonical: docs/reconstruction/reconstructed-exact/BasicStringFlag_CopyCtor_EdiSrc_Inferred.cpp
// =============================================================================

/*
 * Behavioral notes:
 * - Copy-construct { basic_string<char> @+0 (0x1c); uint8_t flag @+0x1c }.
 * - ABI: stack dest*; EDI = const source*; return dest* in EAX; RET 4.
 * - Sole callee: IAT [0x009c62ec] basic_string copy-ctor.
 * - SEH LAB_009bbfb9; callers FUN_00401fe0 / FUN_00980160.
 */

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

// Ghidra FUN_00402040 — register ABI still applies (EDI = source).
extern "C" BasicStringFlag* FUN_00402040(
    BasicStringFlag* dest /* stack */,
    const BasicStringFlag* src /* EDI */)
{
    BasicString_CopyCtor(&dest->str, &src->str);
    dest->flag = src->flag;
    return dest;
}
