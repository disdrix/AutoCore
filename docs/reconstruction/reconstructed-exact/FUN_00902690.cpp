// =============================================================================
// FUN_00902690
// -----------------------------------------------------------------------------
// Stable ID: aa_00902690
// Address:   0x00902690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00902690 @ 0x00902690
// Stable ID: aa_00902690
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1.
//  - Notable callees: FUN_00790730, FUN_00902690.
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

uint32_t /* width from decompiler */ __thiscall FUN_00902690(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  int *piVar4;

  int iVar5;

  int iStack_3c;

  uint8_t local_38 [4];

  uint8_t auStack_34 [4];

  uint8_t auStack_30 [16];

  uint8_t auStack_20 [4];

  uint8_t auStack_1c [4];

  uint8_t auStack_18 [20];

  

  iVar5 = 0;

  if (0 < *(int *)(param_1 + 0x524)) {

    do {

      if ((*(int *)(*(int *)(param_1 + 0x56c) + iVar5 * 4) != 0) &&

         (iVar1 = (**(code **)(**(int **)(*(int *)(param_1 + 0x56c) + iVar5 * 4) + 0x120))

                            (local_38,1,1), *(int *)(iVar1 + 4) < DAT_00d1d870)) {

        piVar3 = *(int **)(*(int *)(param_1 + 0x56c) + iVar5 * 4);

        uVar2 = (**(code **)(**(int **)(*(int *)(param_1 + 0x56c) + iVar5 * 4) + 0x120))

                          (auStack_30,1,1);

        iVar1 = (**(code **)(*piVar3 + 0x140))(auStack_34,1);

        if ((DAT_00d1d870 < *(int *)(iStack_3c + 4) + *(int *)(iVar1 + 4)) &&

           (piVar3 = (int *)(**(code **)(**(int **)(*(int *)(param_1 + 0x56c) + iVar5 * 4) + 0x120))

                                      (auStack_20,1,1,uVar2), *piVar3 < DAT_00d1d86c)) {

          piVar3 = (int *)(**(code **)(**(int **)(*(int *)(param_1 + 0x56c) + iVar5 * 4) + 0x120))

                                    (auStack_18,1,1);

          piVar4 = (int *)(**(code **)(**(int **)(*(int *)(param_1 + 0x56c) + iVar5 * 4) + 0x140))

                                    (auStack_1c,1);

          if (DAT_00d1d86c < *piVar4 + *piVar3) {

            return 1;

          }

        }

      }

      iVar5 = iVar5 + 1;

    } while (iVar5 < *(int *)(param_1 + 0x524));

  }

  uVar2 = FUN_00790730(param_2,param_3);

  return uVar2;

}
