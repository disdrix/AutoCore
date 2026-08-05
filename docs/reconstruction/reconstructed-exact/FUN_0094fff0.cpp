// =============================================================================
// FUN_0094fff0
// -----------------------------------------------------------------------------
// Stable ID: aa_0094fff0
// Address:   0x0094fff0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0094fff0 @ 0x0094fff0
// Stable ID: aa_0094fff0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×6, return×4.
//  - Notable callees: FUN_004c22a0, FUN_0094bfe0, FUN_0094fff0, strtok.
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

uint32_t /* width from decompiler */ __thiscall FUN_0094fff0(int param_1,uint32_t /* width from decompiler */ param_2,char *param_3)



{

  int iVar1;

  char *pcVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  

  if ((*(int *)(param_1 + 0xe98) != 0) && (*(int *)(param_1 + 0x31f0) != 0)) {

    iVar1 = *(int *)(param_1 + 0xe98);

    iVar3 = *(int *)(*(int *)(iVar1 + 4) + 4);

    iVar1 = FUN_004c22a0(*(uint32_t /* width from decompiler */ *)(iVar3 + 0x164 + iVar1),

                         *(uint32_t /* width from decompiler */ *)(iVar3 + 0x168 + iVar1));

    if ((iVar1 != 0) && (1 < *(int *)(iVar1 + 0x24))) {

      uVar4 = 0xffffffff;

      uVar5 = 0xffffffff;

      pcVar2 = strtok((char *)0x0,param_3);

      if (pcVar2 == (char *)0x0) {

        if (*(int **)(param_1 + 0x3048) == (int *)0x0) {

          return 1;

        }

        iVar1 = (**(code **)(**(int **)(param_1 + 0x3048) + 0x210))(0);

        if (iVar1 == 0) {

          return 1;

        }

        iVar3 = (**(code **)(**(int **)(param_1 + 0x3048) + 0x210))(0);

        iVar1 = *(int *)(*(int *)(iVar3 + 4) + 4);

        uVar4 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x164 + iVar3);

        uVar5 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x168 + iVar3);

        iVar1 = (**(code **)(**(int **)(param_1 + 0x3048) + 0x210))(0);

        iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x160))();

        if (iVar1 == 0) {

          return 1;

        }

      }

      FUN_0094bfe0(uVar4,uVar5);

    }

  }

  return 1;

}
