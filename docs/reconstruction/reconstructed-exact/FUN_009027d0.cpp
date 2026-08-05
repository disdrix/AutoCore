// =============================================================================
// FUN_009027d0
// -----------------------------------------------------------------------------
// Stable ID: aa_009027d0
// Address:   0x009027d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009027d0 @ 0x009027d0
// Stable ID: aa_009027d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×9, goto×5, return×2, do×1, while×1.
//  - Notable callees: FUN_007907b0, FUN_009027d0.
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

void __thiscall FUN_009027d0(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int *piVar4;

  int *piVar5;

  int iVar6;

  int unaff_EDI;

  uint8_t auStack_3c [4];

  uint8_t auStack_38 [12];

  uint8_t auStack_2c [4];

  uint8_t auStack_28 [4];

  uint8_t auStack_24 [32];

  

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar1 == '\0') {

    return;

  }

  iVar6 = 0;

  if (0 < param_1[0x149]) {

    do {

      iVar2 = param_1[0x15b];

      if ((iVar2 != 0) && (*(int *)(iVar2 + iVar6 * 4) != 0)) {

        iVar2 = (**(code **)(**(int **)(iVar2 + iVar6 * 4) + 0x120))(auStack_38,1,1);

        if (*(int *)(iVar2 + 4) < DAT_00d1d870) {

          piVar4 = *(int **)(param_1[0x15b] + iVar6 * 4);

          uVar3 = (**(code **)(**(int **)(param_1[0x15b] + iVar6 * 4) + 0x120))(auStack_3c,1,1);

          iVar2 = (**(code **)(*piVar4 + 0x140))(&stack0xffffffc0,1);

          if (*(int *)(unaff_EDI + 4) + *(int *)(iVar2 + 4) <= DAT_00d1d870) goto LAB_0090290e;

          piVar4 = (int *)(**(code **)(**(int **)(param_1[0x15b] + iVar6 * 4) + 0x120))

                                    (auStack_2c,1,1,uVar3);

          if (DAT_00d1d86c <= *piVar4) goto LAB_0090290e;

          piVar4 = (int *)(**(code **)(**(int **)(param_1[0x15b] + iVar6 * 4) + 0x120))

                                    (auStack_24,1,1);

          piVar5 = (int *)(**(code **)(**(int **)(param_1[0x15b] + iVar6 * 4) + 0x140))

                                    (auStack_28,1);

          if (*piVar5 + *piVar4 <= DAT_00d1d86c) goto LAB_0090290e;

          cVar1 = (**(code **)(**(int **)(param_1[0x15b] + iVar6 * 4) + 0x3c0))();

          if (cVar1 != '\0') goto LAB_00902947;

          piVar4 = *(int **)(param_1[0x15b] + iVar6 * 4);

          uVar3 = 1;

        }

        else {

LAB_0090290e:

          cVar1 = (**(code **)(**(int **)(param_1[0x15b] + iVar6 * 4) + 0x3c0))();

          if (cVar1 != '\x01') goto LAB_00902947;

          piVar4 = *(int **)(param_1[0x15b] + iVar6 * 4);

          uVar3 = 0;

        }

        (**(code **)(*piVar4 + 0x3cc))(uVar3);

        (**(code **)(**(int **)(param_1[0x15b] + iVar6 * 4) + 0x34c))();

      }

LAB_00902947:

      iVar6 = iVar6 + 1;

    } while (iVar6 < param_1[0x149]);

  }

  FUN_007907b0(param_2,param_3);

  return;

}
