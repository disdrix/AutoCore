// =============================================================================
// FUN_0094ff20
// -----------------------------------------------------------------------------
// Stable ID: aa_0094ff20
// Address:   0x0094ff20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0094ff20 @ 0x0094ff20
// Stable ID: aa_0094ff20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×7, return×4.
//  - Notable callees: FUN_004c22a0, FUN_004c2310, FUN_0094c150, FUN_0094ff20, strtok.
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ __thiscall FUN_0094ff20(int param_1,uint32_t /* width from decompiler */ param_2,char *param_3)



{

  int iVar1;

  char *pcVar2;

  uint *puVar3;

  int iVar4;

  uint uVar5;

  uint uVar6;

  

  if ((*(int *)(param_1 + 0xe98) != 0) && (*(int *)(param_1 + 0x31f0) != 0)) {

    iVar1 = *(int *)(param_1 + 0xe98);

    iVar4 = *(int *)(*(int *)(iVar1 + 4) + 4);

    iVar1 = FUN_004c22a0(*(uint32_t /* width from decompiler */ *)(iVar4 + 0x164 + iVar1),

                         *(uint32_t /* width from decompiler */ *)(iVar4 + 0x168 + iVar1));

    if ((iVar1 != 0) && (1 < *(int *)(iVar1 + 0x24))) {

      pcVar2 = strtok((char *)0x0,param_3);

      if (pcVar2 == (char *)0x0) {

        if (*(int **)(param_1 + 0x3048) == (int *)0x0) {

          return 1;

        }

        iVar1 = (**(code **)(**(int **)(param_1 + 0x3048) + 0x210))(0);

        if (iVar1 == 0) {

          return 1;

        }

        iVar4 = (**(code **)(**(int **)(param_1 + 0x3048) + 0x210))(0);

        iVar1 = *(int *)(*(int *)(iVar4 + 4) + 4);

        uVar6 = *(uint *)(iVar1 + 0x164 + iVar4);

        uVar5 = *(uint *)(iVar1 + 0x168 + iVar4);

      }

      else {

        puVar3 = (uint *)FUN_004c2310(pcVar2);

        if (puVar3 == (uint *)0x0) {

          return 1;

        }

        uVar6 = *puVar3;

        uVar5 = puVar3[1];

      }

      if ((uVar6 & uVar5) != 0xffffffff) {

        FUN_0094c150(uVar6,uVar5);

      }

    }

  }

  return 1;

}
