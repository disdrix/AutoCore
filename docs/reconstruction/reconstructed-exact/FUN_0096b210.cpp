// =============================================================================
// FUN_0096b210
// -----------------------------------------------------------------------------
// Stable ID: aa_0096b210
// Address:   0x0096b210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096b210 @ 0x0096b210
// Stable ID: aa_0096b210
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_0096b150, FUN_0096b210, FUN_0096dfb0.
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

void FUN_0096b210(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  

  if (*(int *)(param_1 + 0xc) == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = *(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc) >> 2;

  }

  FUN_0096b150(param_2,iVar2);

  iVar1 = 0;

  if (0 < iVar2) {

    do {

      FUN_0096dfb0(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xc) + iVar1 * 4));

      iVar1 = iVar1 + 1;

    } while (iVar1 < iVar2);

  }

  *(int *)(param_2 + 0x1c) = *(int *)(param_2 + 0x1c) + 1;

  *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) | 3;

  return;

}
