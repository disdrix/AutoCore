// =============================================================================
// FUN_004102c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004102c0
// Address:   0x004102c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004102c0 @ 0x004102c0
// Stable ID: aa_004102c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_004102c0, FUN_00415e90.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x004102c0; evidence only — no invented semantics):
//  - Entry: `void __fastcall FUN_004102c0(undefined4 *param_1)`.
//  - Calls: FUN_00415e90(); operator_delete(param_1[0x123]).
//  - Writes: *param_1 = &PTR_FUN_00a42a3c.
//  - Void function; no value return in raw.




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

void __fastcall FUN_004102c0(uint32_t /* width from decompiler */ *param_1)



{

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bf0d5;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00a42a3c;

  local_4 = 0;

  FUN_00415e90();

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)param_1[0x123]);

}
