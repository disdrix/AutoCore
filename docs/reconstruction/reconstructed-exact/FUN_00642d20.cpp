// =============================================================================
// FUN_00642d20
// -----------------------------------------------------------------------------
// Stable ID: aa_00642d20
// Address:   0x00642d20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00642d20 @ 0x00642d20
// Stable ID: aa_00642d20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_006380a0×2, FUN_00642c30, FUN_00642d20.
//  - Return sites: 2.

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

int __thiscall FUN_00642d20(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar1 = *(int *)(param_1 + 0x10);

  iVar3 = *(int *)(param_1 + 0x14) - iVar1;

  iVar2 = param_3;

  if (iVar3 < param_3) {

    do {

      FUN_006380a0(param_2,*(int *)(param_1 + 0xc) + iVar1,iVar3);

      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + iVar3;

      param_2 = param_2 + iVar3;

      iVar2 = iVar2 - iVar3;

      iVar1 = FUN_00642c30();

      if (iVar1 != 0) {

        return param_3 - iVar2;

      }

      iVar1 = *(int *)(param_1 + 0x10);

      iVar3 = *(int *)(param_1 + 0x14) - iVar1;

    } while (iVar3 < iVar2);

  }

  FUN_006380a0(param_2,*(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x10),iVar2);

  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + iVar2;

  return param_3;

}
