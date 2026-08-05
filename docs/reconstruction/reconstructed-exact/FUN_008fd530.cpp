// =============================================================================
// FUN_008fd530
// -----------------------------------------------------------------------------
// Stable ID: aa_008fd530
// Address:   0x008fd530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008fd530 @ 0x008fd530
// Stable ID: aa_008fd530
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00410420×2, FUN_008fd530.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall FUN_008fd530(int param_1)



{

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4b8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4bc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4b4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x504) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x508) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x514) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x520) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x524) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x52c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x528) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x530) = 0xfffffffe;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x550) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x534) = 0xfffffffe;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x554) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x538) = 0xfffffffe;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x558) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x53c) = 0xfffffffe;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x55c) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x540) = 0xfffffffe;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x560) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x544) = 0xfffffffe;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x564) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x548) = 0xfffffffe;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x568) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x54c) = 0xfffffffe;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x56c) = 0xffffffff;

  FUN_00410420(0,0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c8) = 0xffffffff;

  FUN_00410420(0,0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7e0) = 0xffffffff;

  *(uint8_t *)(param_1 + 0x604) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x600) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5fc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x708) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x70c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x710) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x714) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x718) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x71c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x720) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x724) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x728) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x72c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x730) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x734) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x738) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x73c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x740) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x744) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x748) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x74c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x750) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x754) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x758) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x75c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x760) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x764) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x768) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x76c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x770) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x774) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x778) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x77c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x780) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x784) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x788) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7b4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x7cc) = 0;

  return;

}
