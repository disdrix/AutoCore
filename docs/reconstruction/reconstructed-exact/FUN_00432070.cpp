// =============================================================================
// FUN_00432070
// -----------------------------------------------------------------------------
// Stable ID: aa_00432070
// Address:   0x00432070  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00432070 @ 0x00432070
// Stable ID: aa_00432070
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00432070.
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

void __fastcall FUN_00432070(int param_1)



{

  uint32_t /* width from decompiler */ *in_EAX;

  

  in_EAX[1] = 0;

  in_EAX[2] = 0;

  *in_EAX = &PTR_LAB_009d7b00;

  in_EAX[4] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x10);

  in_EAX[3] = *(uint32_t /* width from decompiler */ *)(param_1 + 0xc);

  *(uint8_t *)(in_EAX + 5) = 0;

  return;

}
