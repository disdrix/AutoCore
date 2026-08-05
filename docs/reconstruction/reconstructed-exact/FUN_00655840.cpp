// =============================================================================
// FUN_00655840
// -----------------------------------------------------------------------------
// Stable ID: aa_00655840
// Address:   0x00655840  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00655840 @ 0x00655840
// Stable ID: aa_00655840
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: while×1, return×1.
//  - Notable callees: FUN_00655840.
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

void __fastcall FUN_00655840(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x20);

  while (iVar1 = iVar1 + -1, -1 < iVar1) {

    (**(code **)(**(int **)(param_1 + 0x10) + 0x10))

              (*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1c) + iVar1 * 8),

               *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1c) + 4 + iVar1 * 8),DAT_00d0351c);

    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -1;

  }

  return;

}
