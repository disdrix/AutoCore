// =============================================================================
// FUN_0040dfb0
// -----------------------------------------------------------------------------
// Stable ID: aa_0040dfb0
// Address:   0x0040dfb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040dfb0 @ 0x0040dfb0
// Stable ID: aa_0040dfb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0040dfb0, FUN_0040e7c0.
//  - Return sites: 1.

// READABILITY:
// Control-flow (from raw @ 0x0040dfb0; evidence only — no invented semantics):
//  - Entry: `void FUN_0040dfb0(int param_1)`.
//  - Calls: FUN_0040e7c0(&param_1,**(param_1 + 4),*(param_1 + 4)); operator_delete(*(iVar1 + 4)).
//  - Void function; no value return in raw.
//  - Assign `local_4 = 0xffffffff`.




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

void FUN_0040dfb0(int param_1)



{

  int iVar1;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar1 = param_1;

  puStack_8 = &LAB_009bcfc8;

  pvStack_c = ExceptionList;

  local_4 = 0xffffffff;

  ExceptionList = &pvStack_c;

  FUN_0040e7c0(&param_1,**(uint32_t /* width from decompiler */ **)(param_1 + 4),*(uint32_t /* width from decompiler */ **)(param_1 + 4));

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(iVar1 + 4));

}
