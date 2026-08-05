// =============================================================================
// FUN_0094fdc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0094fdc0
// Address:   0x0094fdc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0094fdc0 @ 0x0094fdc0
// Stable ID: aa_0094fdc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×7, return×6.
//  - Notable callees: FUN_004c2310, FUN_0094c200, FUN_0094fdc0, strtok.
//  - Return sites: 6.

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

uint32_t /* width from decompiler */ __thiscall FUN_0094fdc0(int param_1,uint32_t /* width from decompiler */ param_2,char *param_3)



{

  char *pcVar1;

  uint *puVar2;

  int iVar3;

  int iVar4;

  uint uVar5;

  uint uVar6;

  

  if (*(int *)(param_1 + 0xe98) == 0) {

    return 1;

  }

  if (*(int *)(param_1 + 0x31f0) == 0) {

    return 1;

  }

  pcVar1 = strtok((char *)0x0,param_3);

  if (pcVar1 == (char *)0x0) {

    if (*(int **)(param_1 + 0x3048) == (int *)0x0) {

      return 1;

    }

    iVar3 = (**(code **)(**(int **)(param_1 + 0x3048) + 0x210))(0);

    if (iVar3 == 0) {

      return 1;

    }

    iVar4 = (**(code **)(**(int **)(param_1 + 0x3048) + 0x210))(0);

    iVar3 = *(int *)(*(int *)(iVar4 + 4) + 4);

    uVar6 = *(uint *)(iVar3 + 0x164 + iVar4);

    uVar5 = *(uint *)(iVar3 + 0x168 + iVar4);

  }

  else {

    puVar2 = (uint *)FUN_004c2310(pcVar1);

    if (puVar2 == (uint *)0x0) {

      return 1;

    }

    uVar6 = *puVar2;

    uVar5 = puVar2[1];

  }

  if ((uVar6 & uVar5) != 0xffffffff) {

    FUN_0094c200(uVar6,uVar5);

  }

  return 1;

}
