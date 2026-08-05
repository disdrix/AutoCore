// =============================================================================
// FUN_0096a9d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0096a9d0
// Address:   0x0096a9d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096a9d0 @ 0x0096a9d0
// Stable ID: aa_0096a9d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_0096a9d0×2.
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

int __thiscall FUN_0096a9d0(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 0xc) + param_2 * 4) + 0x150);

  iVar2 = 1;

  param_2 = param_2 + 1;

  if (0 < iVar3) {

    do {

      iVar1 = FUN_0096a9d0(param_2);

      iVar2 = iVar2 + iVar1;

      iVar3 = iVar3 + -1;

      param_2 = *(int *)(*(int *)(*(int *)(param_1 + 0xc) + param_2 * 4) + 0x14c);

    } while (iVar3 != 0);

  }

  return iVar2;

}
