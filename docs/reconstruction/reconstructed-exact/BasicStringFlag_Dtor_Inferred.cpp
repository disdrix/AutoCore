// =============================================================================
// BasicStringFlag_Dtor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004020f0
// Address:   0x004020f0–0x00402126 inclusive (55 B / 0x37)
// Module:    autoassault.exe, image base 0x400000
// Ghidra:    FUN_004020f0
// System:    missions-progression partition parent; unit = shared aggregate dtor
// Wave:      R10-018 OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler + disassemble_function +
//            read_memory. Not modernization. Bit-for-bit / runtime: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Destroy { basic_string<char> @+0 (0x1c); uint8_t flag @+0x1c }.
 * - Body only runs basic_string dtor (flag is POD — no write/free).
 * - ABI: stack object*; nested thiscall ECX=object; void; RET 4.
 * - Sole callee: IAT basic_string dtor [0x009c62f4]
 *   Ghidra: ~basic_string<char,char_traits<char>,allocator<char>>
 * - SEH frame LAB_009bbfb9 (shared with 00401d30 ctor / 00402040 copy).
 * - Callers: 7 Unwind@* sites only (MSVC exception cleanup).
 * - Family twins (dualed):
 *     00401d30 BasicStringFlag_CtorFromStringAndChar_Inferred (MEGA-065)
 *     00402040 BasicStringFlag_CopyCtor_EdiSrc_Inferred (MEGA-080)
 */

#include <cstdint>

// MSVC basic_string<char> footprint in this binary (SSO layout opaque here).
struct BasicString_0x1c {
    std::uint8_t raw[0x1C];
};

struct BasicStringFlag {
    BasicString_0x1c str;  // +0x00
    std::uint8_t     flag; // +0x1C  (POD)
};

// Retail IAT [0x009c62f4] → basic_string::~basic_string()
extern "C" void __thiscall BasicString_Dtor(BasicString_0x1c* self);

// Retail: one stack formal, callee cleans 4 bytes (RET 4).
extern "C" void __stdcall BasicStringFlag_Dtor_Inferred(BasicStringFlag* obj)
{
    // SEH: PUSH -1; PUSH LAB_009bbfb9; FS:[0] chain (omitted in managed port)
    BasicString_Dtor(&obj->str);
    // flag @ +0x1c: no work
    // RET 4
}
