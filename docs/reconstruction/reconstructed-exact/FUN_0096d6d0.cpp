// =============================================================================
// FUN_0096d6d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0096d6d0
// Address:   0x0096d6d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096d6d0 @ 0x0096d6d0
// Stable ID: aa_0096d6d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: while×1, return×1.
//  - Notable callees: FUN_0096d6d0×2, FUN_0096d550.
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

int __fastcall FUN_0096d6d0(int param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  int iVar4;

  

  iVar4 = 0;

  while ((piVar1 = *(int **)(param_1 + 0x6c), piVar1 != (int *)0x0 &&

         (*(int *)(param_1 + 0x70) - (int)piVar1 >> 2 != 0))) {

    uVar2 = *(uint32_t /* width from decompiler */ *)(*piVar1 + 8);

    iVar3 = FUN_0096d6d0();

    FUN_0096d550(uVar2);

    iVar4 = iVar4 + iVar3 + 1;

  }

  return iVar4;

}
