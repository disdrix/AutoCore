// =============================================================================
// FUN_00789870
// -----------------------------------------------------------------------------
// Stable ID: aa_00789870
// Address:   0x00789870  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00789870 @ 0x00789870
// Stable ID: aa_00789870
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~124 non-empty decompiler lines.
//  - Control keywords: if×8, while×3, do×2, return×2.
//  - Notable callees: FUN_00423f40×2, FUN_00404d80, FUN_004294f0, FUN_00789870, LeaveCriticalSection.
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

void FUN_00789870(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ *unaff_EBX;

  char *pcVar7;

  uint32_t /* width from decompiler */ uStack_60;

  uint32_t /* width from decompiler */ uStack_5c;

  uint32_t /* width from decompiler */ uStack_58;

  uint32_t /* width from decompiler */ uStack_54;

  uint32_t /* width from decompiler */ uStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  uint32_t /* width from decompiler */ *puStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  undefined *puStack_3c;

  uint32_t /* width from decompiler */ uStack_24;

  

  if ((param_2 != (uint32_t /* width from decompiler */ *)0x0) && (unaff_EBX != (uint32_t /* width from decompiler */ *)0x0)) {

    uVar5 = *param_2;

    uVar6 = param_2[1];

    *param_2 = *unaff_EBX;

    param_2[1] = unaff_EBX[1];

    *unaff_EBX = uVar5;

    unaff_EBX[1] = uVar6;

    if (((int *)param_2[2] != (int *)0x0) && (unaff_EBX[2] != 0)) {

      pcVar7 = (char *)0x0;

      iVar2 = (**(code **)(*(int *)param_2[2] + 0x1dc))();

      if (iVar2 != 0) {

        pcVar3 = (char *)(**(code **)(*(int *)param_2[2] + 0x1dc))();

        pcVar7 = pcVar3 + 1;

        do {

          cVar1 = *pcVar3;

          pcVar3 = pcVar3 + 1;

        } while (cVar1 != '\0');

        uStack_24 = 0x7898e5;

        pcVar7 = operator_new__((uint)(pcVar3 + (1 - (int)pcVar7)));

        pcVar4 = (char *)(**(code **)(*(int *)param_2[2] + 0x1dc))();

        pcVar3 = pcVar7;

        do {

          cVar1 = *pcVar4;

          *pcVar3 = cVar1;

          pcVar4 = pcVar4 + 1;

          pcVar3 = pcVar3 + 1;

        } while (cVar1 != '\0');

      }

      iVar2 = *(int *)param_2[2];

      uStack_24 = 1;

      (**(code **)(*(int *)unaff_EBX[2] + 0x1dc))();

      (**(code **)(iVar2 + 0x1d8))();

      (**(code **)(*(int *)unaff_EBX[2] + 0x1d8))();

      if (pcVar7 != (char *)0x0) {

                    /* WARNING: Subroutine does not return */

        puStack_3c = &UNK_0078993d;

        operator_delete(pcVar7);

      }

      puStack_3c = (undefined *)0x3;

      uStack_40 = 4;

      puStack_44 = &uStack_24;

      uStack_48 = 0x789953;

      FUN_00404d80();

      puStack_3c = (undefined *)0x789960;

      (**(code **)(*(int *)param_2[2] + 0x164))();

      puStack_3c = (undefined *)0x1;

      uStack_40 = 0x789973;

      (**(code **)(*(int *)param_2[2] + 0x164))();

      uStack_40 = 2;

      puStack_44 = (uint32_t /* width from decompiler */ *)0x789986;

      (**(code **)(*(int *)param_2[2] + 0x164))();

      puStack_44 = (uint32_t /* width from decompiler */ *)0x789997;

      uVar5 = (**(code **)(*(int *)param_2[2] + 0x1b8))();

      iVar2 = *(int *)param_2[2];

      puStack_44 = (uint32_t /* width from decompiler */ *)0x0;

      uStack_48 = 0x7899ab;

      uStack_48 = (**(code **)(*(int *)unaff_EBX[2] + 0x164))();

      uStack_4c = 0;

      uStack_50 = 0x7899b7;

      (**(code **)(iVar2 + 0x154))();

      iVar2 = *(int *)param_2[2];

      uStack_50 = 1;

      uStack_54 = 0x7899c9;

      uStack_54 = (**(code **)(*(int *)unaff_EBX[2] + 0x164))();

      uStack_58 = 1;

      uStack_5c = 0x7899d5;

      (**(code **)(iVar2 + 0x154))();

      iVar2 = *(int *)param_2[2];

      uStack_5c = 2;

      uStack_60 = 0x7899e7;

      uStack_60 = (**(code **)(*(int *)unaff_EBX[2] + 0x164))();

      (**(code **)(iVar2 + 0x154))(2);

      iVar2 = *(int *)param_2[2];

      uVar6 = (**(code **)(*(int *)unaff_EBX[2] + 0x1b8))();

      (**(code **)(iVar2 + 0x1b4))(uVar6);

      (**(code **)(*(int *)unaff_EBX[2] + 0x15c))(0,&uStack_58);

      (**(code **)(*(int *)unaff_EBX[2] + 0x15c))(1,&uStack_5c);

      (**(code **)(*(int *)unaff_EBX[2] + 0x15c))(2,&uStack_60);

      (**(code **)(*(int *)unaff_EBX[2] + 0x1b4))(uVar5);

    }

    FUN_004294f0();

    uStack_24 = 0x789a76;

    iVar2 = FUN_00423f40();

    while (iVar2 == 0) {

      if (param_2 != (uint32_t /* width from decompiler */ *)0x0) {

        if ((uint32_t /* width from decompiler */ *)param_2[7] == param_2) {

          param_2[7] = unaff_EBX;

        }

        else if ((uint32_t /* width from decompiler */ *)param_2[7] == unaff_EBX) {

          param_2[7] = param_2;

        }

      }

      uStack_24 = 0x789aa9;

      iVar2 = FUN_00423f40();

    }

    if (*(char *)(param_1 + 0x534) != '\0') {

      *(uint8_t *)(param_1 + 0x534) = 0;

      uStack_24 = 0x789ac1;

      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x510));

    }

  }

  return;

}
