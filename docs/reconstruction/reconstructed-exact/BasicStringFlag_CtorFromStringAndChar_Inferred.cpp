// =============================================================================
// BasicStringFlag_CtorFromStringAndChar_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00401d30
// Address:   0x00401d30–0x00401d83 inclusive (84 B / 0x54)
// Module:    autoassault.exe, image base 0x400000
// Ghidra:    FUN_00401d30
// System:    missions-progression partition parent; unit = shared aggregate ctor
// Wave:      MEGA-065 OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler + disassemble_function +
//            read_memory. Not modernization. Bit-for-bit / runtime: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Construct-from-parts { basic_string<char> @+0 (0x1c); uint8_t flag @+0x1c }.
 * - ABI: stack dest*, src string*, char*; return dest* in EAX; RET 0xC.
 * - Sole callee: IAT basic_string copy-ctor [0x009c62ec]
 *   demangle: ??0?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QAE@ABV01@@Z
 * - SEH frame LAB_009bbfb9 (shared with 00402040 copy twin / 004020f0 dtor).
 * - Sole caller: FUN_00980160 @ 009801af (substr → this → copy twin 00402040).
 * - Retire Named_CalleeOf_Named_CalleeOf_Mission_Attempting_to_open_null_d_00401d30
 *   (xref-seed scaffold; not mission-dialog logic).
 * - Decompiler typed param_3 as basic_string*; assembly is single-byte load/store.
 */

#include <cstdint>

// MSVC basic_string<char> footprint in this binary (SSO layout opaque here).
struct BasicString_0x1c {
    std::uint8_t raw[0x1C];
};

struct BasicStringFlag {
    BasicString_0x1c str;  // +0x00
    std::uint8_t     flag; // +0x1C
};

// Retail IAT [0x009c62ec] → basic_string::basic_string(const basic_string&)
extern "C" BasicString_0x1c* __thiscall
BasicString_CopyCtor(BasicString_0x1c* self, const BasicString_0x1c* other);

// Retail: three stack formals, callee cleans 12 bytes (RET 0xC).
extern "C" BasicStringFlag* __stdcall
BasicStringFlag_CtorFromStringAndChar_Inferred(
    BasicStringFlag* dest,
    const BasicString_0x1c* src,
    const std::uint8_t* flag_src)
{
    // SEH: PUSH -1; PUSH LAB_009bbfb9; FS:[0] chain (omitted in managed port)
    BasicString_CopyCtor(&dest->str, src);
    dest->flag = *flag_src;
    return dest; // EAX; RET 0xC
}
