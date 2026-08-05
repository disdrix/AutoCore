// =============================================================================
// FUN_00802170
// -----------------------------------------------------------------------------
// Stable ID: aa_00802170
// Address:   0x00802170  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00802170 @ 0x00802170
// Stable ID: aa_00802170
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~111 non-empty decompiler lines.
//  - Control keywords: if×16, do×1, while×1, return×1.
//  - Notable callees: CVOGHBBase_Start, CVOGHBList_Enqueue, Client_MaybeShowFirstTimeTip, FUN_0040ada0, FUN_0048a780, FUN_005b3210, FUN_007fb4a0, FUN_007fbbb0.
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

void __fastcall FUN_00802170(int param_1)



{

  int iVar1;

  int *piVar2;

  char cVar3;

  void *pvVar4;

  int *piVar5;

  CVOGHBBase *pAction;

  int iStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009bb4a2;

  local_c = ExceptionList;

  if ((((*(char *)(param_1 + 0xaa) != '\0') && (*(char *)(DAT_00d1b6d8 + 0x4f1) == '\0')) &&

      (*(int *)(param_1 + 0xe98) != 0)) &&

     (((iVar1 = *(int *)(*(int *)(param_1 + 0xe98) + 0x250), iVar1 == 0 ||

       ((*(uint *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0x180 + iVar1) >> 10 & 1) == 0)) &&

      (*(char *)(DAT_00d1b644 + 0xf6) == '\0')))) {

    ExceptionList = &local_c;

    if ((*(int *)(param_1 + 0x10ac) != 0) &&

       (iVar1 = *(int *)(*(int *)(param_1 + 0x10ac) + 0x590), ExceptionList = &local_c, iVar1 != 0))

    {

      ExceptionList = &local_c;

      FUN_0083c7b0(iVar1);

    }

    if (*(int *)(param_1 + 0xf38) != 0) {

      *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xf38) + 0x758) = 0;

    }

    piVar5 = *(int **)(param_1 + 0x10f0);

    if ((piVar5 != (int *)0x0) && (cVar3 = (**(code **)(*piVar5 + 0x3d8))(), cVar3 != '\0')) {

      (**(code **)(*piVar5 + 0x448))();

    }

    FUN_007fc970();

    FUN_007fbbb0();

    FUN_0093e120(0);

    piVar5 = (int *)(param_1 + 0x1030);

    iStack_10 = 0x3a;

    do {

      piVar2 = (int *)*piVar5;

      if (((piVar2 != (int *)0x0) && (cVar3 = (**(code **)(*piVar2 + 0x3d8))(), cVar3 != '\0')) &&

         (piVar2[0x140] == 1)) {

        FUN_007fca10();

      }

      piVar5 = piVar5 + 1;

      iStack_10 = iStack_10 + -1;

    } while (iStack_10 != 0);

    Client_MaybeShowFirstTimeTip(7);

    pAction = (CVOGHBBase *)0x0;

    if (*(int *)(param_1 + 0x3c10) != 0) {

      FUN_0048a780(PTR_s_LED_FX_LED_FX_death_xml_00b00258,*(int *)(param_1 + 0x3c10));

    }

    if ((*(int *)(param_1 + 0x1158) != 0) && (*(int *)(param_1 + 0x114c) != 0)) {

      iVar1 = *(int *)(param_1 + 0x1150);

      if (iVar1 != 0) {

        if (*(int *)(iVar1 + 0x2b0) != 0) {

          (**(code **)(**(int **)(iVar1 + 0x2b0) + 0xb0))(iVar1);

        }

        (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(param_1 + 0xf40) + 0xa8))

                  (*(uint32_t /* width from decompiler */ *)(param_1 + 0x1150));

        (**(code **)(**(int **)(param_1 + 0x1150) + 0xfc))(1,0x3fc00000);

      }

      iVar1 = *(int *)(param_1 + 0x1154);

      if (iVar1 != 0) {

        if (*(int *)(iVar1 + 0x2b0) != 0) {

          (**(code **)(**(int **)(iVar1 + 0x2b0) + 0xb0))(iVar1);

        }

        (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(param_1 + 0xf40) + 0xa8))

                  (*(uint32_t /* width from decompiler */ *)(param_1 + 0x1154));

        (**(code **)(**(int **)(param_1 + 0x1154) + 0xfc))(1,0x3fc00000);

      }

      iVar1 = *(int *)(param_1 + 0x114c);

      if (*(int *)(iVar1 + 0x2b0) != 0) {

        (**(code **)(**(int **)(iVar1 + 0x2b0) + 0xb0))(iVar1);

      }

      (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(param_1 + 0xf40) + 0xa8))

                (*(uint32_t /* width from decompiler */ *)(param_1 + 0x114c));

      (**(code **)(**(int **)(param_1 + 0x114c) + 0xfc))(1,0x3fc00000);

      FUN_0040ada0();

      (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(param_1 + 0xf40) + 0x3f4))(1);

      iVar1 = *(int *)(param_1 + 0x1158);

      if (*(int *)(iVar1 + 0x2b0) != 0) {

        (**(code **)(**(int **)(iVar1 + 0x2b0) + 0xb0))(iVar1);

      }

      (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(param_1 + 0xf40) + 0xa8))

                (*(uint32_t /* width from decompiler */ *)(param_1 + 0x1158));

      (**(code **)(**(int **)(param_1 + 0x1158) + 0xd4))(1);

      (**(code **)(**(int **)(param_1 + 0x1158) + 0xfc))(1,0x3fc00000);

      if (*(int *)(param_1 + 0xf38) != 0) {

        (**(code **)(**(int **)(param_1 + 0xf38) + 0x3c4))(1);

      }

      FUN_0092f000();

      (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) + 4 +

                           *(int *)(param_1 + 0xe98)) + 0x1ac))();

      FUN_007fb4a0();

    }

    if (*(int *)(param_1 + 0xd38) != 0) {

      pvVar4 = operator_new(0x24);

      uStack_4 = 0;

      if (pvVar4 != (void *)0x0) {

        pAction = (CVOGHBBase *)FUN_005b3210(*(uint32_t /* width from decompiler */ *)(param_1 + 0xe98),300000);

      }

      uStack_4 = 0xffffffff;

      CVOGHBList_Enqueue(*(void **)(param_1 + 0xd38),pAction);

      CVOGHBBase_Start(pAction);

    }

  }

  ExceptionList = local_c;

  return;

}
