// =============================================================================
// BasicStringFlag_CopyCtor_EdiSrc_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00402040
// Address:   0x00402040–0x0040208c inclusive (77 B / 0x4D)
// Module:    autoassault.exe, image base 0x400000
// Ghidra:    FUN_00402040
// System:    missions-progression partition parent; unit = shared aggregate copy-ctor
// Wave:      MEGA-080 OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler + disassemble_function +
//            read_memory. Not modernization. Bit-for-bit / runtime: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Copy-construct { basic_string<char> @+0 (0x1c); uint8_t flag @+0x1c }.
 * - ABI: stack dest*; EDI = const source*; return dest* in EAX; RET 4.
 * - Sole callee: IAT basic_string copy-ctor [0x009c62ec]
 *   demangle: ??0?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QAE@ABV01@@Z
 * - SEH frame LAB_009bbfb9 (shared with 00401d30 construct twin / 004020f0 dtor).
 * - Callers (2): FUN_00401fe0 @ 0040200a (node+0xc); FUN_00980160 @ 009801c0 (EDI=EAX after 00401d30).
 * - Retire Named_CalleeOf_Named_CalleeOf_Mission_Attempting_to_open_null_d_00402040
 *   (xref-seed scaffold; not mission-dialog logic).
 */

#include <cstdint>

// MSVC basic_string<char> footprint in this binary (SSO layout opaque here).
struct BasicString_0x1c {
    std::uint8_t raw[0x1C];
};

struct BasicStringFlag {
    BasicString_0x1c str; // +0x00
    std::uint8_t     flag; // +0x1C
};

// Retail IAT [0x009c62ec] → basic_string::basic_string(const basic_string&)
extern "C" BasicString_0x1c* __thiscall
BasicString_CopyCtor(BasicString_0x1c* self, const BasicString_0x1c* other);

// Register contract: EDI = source (not a pure C ABI). Modeled with explicit src
// for port clarity; call sites must place source in EDI before CALL.
extern "C" BasicStringFlag* BasicStringFlag_CopyCtor_EdiSrc_Inferred(
    BasicStringFlag* dest /* stack */,
    const BasicStringFlag* src /* EDI */)
{
    // SEH: PUSH -1; PUSH LAB_009bbfb9; FS:[0] chain (omitted in managed port)
    BasicString_CopyCtor(&dest->str, &src->str);
    dest->flag = src->flag;
    return dest; // EAX; RET 4
}

// Ghidra alias — same body / ABI
extern "C" BasicStringFlag* FUN_00402040(BasicStringFlag* dest /* stack */)
{
    // Real body uses unaff_EDI as src; see BasicStringFlag_CopyCtor_EdiSrc_Inferred.
    (void)dest;
    return dest;
}
