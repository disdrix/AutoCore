// =============================================================================
// FUN_005d83a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005d83a0
// Address:   0x005d83a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d83a0 @ 0x005d83a0
// Stable ID: aa_005d83a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004d0e90, FUN_005081f0, FUN_005d83a0.
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

void __fastcall FUN_005d83a0(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x18);

  if ((((iVar1 != 0) && (*(char *)(param_1 + 0x20) == '\0')) && (*(int *)(iVar1 + 0xac) == 0)) &&

     (*(char *)(*(int *)(iVar1 + 0xa4) + 0x7e) != '\0')) {

    FUN_004d0e90(*(uint32_t /* width from decompiler */ *)(param_1 + 0x18));

  }

  FUN_005081f0();

  return;

}
