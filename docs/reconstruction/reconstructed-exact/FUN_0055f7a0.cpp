// =============================================================================
// FUN_0055f7a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0055f7a0
// Address:   0x0055f7a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0055f7a0 @ 0x0055f7a0
// Stable ID: aa_0055f7a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~126 non-empty decompiler lines.
//  - Control keywords: if×18, do×3, while×3, return×1.
//  - Notable callees: FUN_005b3370×2, FUN_0055f7a0, FUN_0062d960.
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

void __thiscall FUN_0055f7a0(int param_1,int *param_2,char param_3)



{

  int iVar1;

  int *piVar2;

  char *pcVar3;

  uint uVar4;

  int iVar5;

  uint8_t uStack_71;

  int iStack_70;

  int iStack_6c;

  int iStack_68;

  uint uStack_64;

  uint uStack_60;

  int iStack_5c;

  uint uStack_58;

  uint uStack_54;

  int iStack_50;

  int iStack_4c;

  int iStack_48;

  int local_44;

  int iStack_40;

  uint8_t auStack_34 [4];

  uint8_t local_30 [44];

  

  FUN_0062d960(*(uint32_t /* width from decompiler */ *)(param_1 + 0x234));

  (**(code **)(*param_2 + 0x18))(local_30);

  (**(code **)(**(int **)(param_1 + 0xc4) + 0x24))(auStack_34,&iStack_48);

  iStack_5c = 0;

  uStack_58 = 0;

  uStack_54 = 0x80000000;

  iStack_68 = 0;

  uStack_64 = 0;

  uStack_60 = 0x80000000;

  iStack_6c = 0;

  if (0 < iStack_4c) {

    do {

      if (param_2 + 3 == (int *)0x0) {

        piVar2 = (int *)0x0;

      }

      else {

        piVar2 = param_2 + 7;

      }

      iStack_70 = iStack_6c * 8;

      if (*(int **)(iStack_70 + 4 + iStack_50) != piVar2) {

        iVar5 = *(int *)(iStack_70 + 4 + iStack_50);

        if (iVar5 == 0) {

          iVar5 = 0;

        }

        else {

          iVar5 = iVar5 + -0x10;

        }

        pcVar3 = (char *)(*(code *)**(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0xd0) + 8))

                                   (&uStack_71,param_2 + 3,iVar5);

        iVar5 = *(int *)(iStack_70 + 4 + iStack_50);

        if (*pcVar3 == '\0') {

          if (iVar5 == 0) {

            iVar5 = 0;

          }

          else {

            iVar5 = iVar5 + -0x10;

          }

          if (uStack_64 == (uStack_60 & 0x7fffffff)) {

            FUN_005b3370(&iStack_68,4);

          }

          *(int *)(iStack_68 + uStack_64 * 4) = iVar5;

          uStack_64 = uStack_64 + 1;

        }

        else {

          if (iVar5 == 0) {

            iVar5 = 0;

          }

          else {

            iVar5 = iVar5 + -0x10;

          }

          if (uStack_58 == (uStack_54 & 0x7fffffff)) {

            FUN_005b3370(&iStack_5c,4);

          }

          *(int *)(iStack_5c + uStack_58 * 4) = iVar5;

          uStack_58 = uStack_58 + 1;

        }

      }

      iStack_6c = iStack_6c + 1;

    } while (iStack_6c < iStack_4c);

    if ((uStack_64 != 0) && (iVar5 = 0, 0 < (int)uStack_64)) {

      do {

        (**(code **)(*param_2 + 0x20))(*(uint32_t /* width from decompiler */ *)(iStack_68 + iVar5 * 4));

        iVar1 = *(int *)(iStack_68 + iVar5 * 4);

        if (*(int *)(iVar1 + 0x18) == 2) {

          (**(code **)(**(int **)(iVar1 + 0x20) + 0x20))(param_2 + 3);

        }

        iVar5 = iVar5 + 1;

      } while (iVar5 < (int)uStack_64);

    }

  }

  if (param_3 != '\0') {

    (**(code **)(*param_2 + 0x24))();

  }

  if ((uStack_58 != 0) && (iVar5 = 0, 0 < (int)uStack_58)) {

    do {

      (**(code **)(*param_2 + 0x1c))(*(uint32_t /* width from decompiler */ *)(iStack_5c + iVar5 * 4),1);

      iVar1 = *(int *)(iStack_5c + iVar5 * 4);

      if (*(int *)(iVar1 + 0x18) == 2) {

        (**(code **)(**(int **)(iVar1 + 0x20) + 0x1c))(param_2 + 3,1);

      }

      iVar5 = iVar5 + 1;

    } while (iVar5 < (int)uStack_58);

  }

  if (-1 < (int)uStack_60) {

    (**(code **)(*DAT_00b05060 + 0x14))(iStack_68,uStack_60 * 4,0x12);

  }

  if (-1 < (int)uStack_54) {

    (**(code **)(*DAT_00b05060 + 0x14))(iStack_5c,uStack_54 * 4,0x12);

  }

  piVar2 = DAT_00b05060;

  uVar4 = iStack_40 * 8 + 0xfU & 0xfffffff0;

  if ((uVar4 == 0) || ((local_44 != DAT_00b05060[5] && (DAT_00b05060[5] != 0)))) {

    DAT_00b05060[2] = DAT_00b05060[2] - uVar4;

    piVar2[3] = piVar2[3] + uVar4;

  }

  else {

    (**(code **)(*DAT_00b05060 + 0x28))(local_44,uVar4);

  }

  if (-1 < iStack_48) {

    (**(code **)(*DAT_00b05060 + 0x14))(iStack_50,iStack_48 * 8,0x12);

  }

  return;

}
