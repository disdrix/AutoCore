// READABILITY (auto CF):
//  - Body size: ~355 non-empty decompiler lines.
//  - Control keywords: if×57, return×27, for×3, while×3.
//  - Notable callees: FUN_00497360×6, FUN_007a4480×6, FUN_0040b020×4, FUN_004e7200×2, FUN_004e7350×2, FUN_004bcbf0, FUN_004d2970, FUN_004d64d0.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal"; "HashError:Destroy, already locked for traversal".
//  - Return sites: 27.

// =============================================================================
// Named_VOG_DEBUG_STOP_004d64d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004d64d0
// Address:   0x004d64d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall Named_VOG_DEBUG_STOP_004d64d0(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  void *pvVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  void *pvStack_4;

  

  *param_1 = &PTR_FUN_009cc770;

  param_1[0x3a04] = 0;

  _DAT_00b037e4 = _DAT_00b037e4 + -1;

  if ((void *)param_1[0x3a1d] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x3a1d]);

  }

  param_1[0x3a1d] = 0;

  param_1[0x3a1e] = 0;

  param_1[0x3a1f] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x3a45] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x3a45])(1);

  }

  iVar3 = param_1[0x3971];

  param_1[0x3a45] = 0;

  iVar5 = 0;

  if (*(char *)(iVar3 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar3 + 0x1d) = 1;

  while( true ) {

    iVar3 = param_1[0x3971];

    if (*(char *)(iVar3 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar5 == 0) {

      iVar5 = *(int *)(iVar3 + 0x14);

    }

    else {

      iVar5 = *(int *)(iVar5 + 0x14);

    }

    if (iVar5 == 0) {

      puVar4 = (uint32_t /* width from decompiler */ *)0x0;

    }

    else {

      puVar4 = *(uint32_t /* width from decompiler */ **)(iVar5 + 8);

    }

    if (puVar4 == (uint32_t /* width from decompiler */ *)0x0) break;

    uVar1 = *puVar4;

    if (*(char *)(param_1[0x3971] + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:Destroy, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    iVar3 = FUN_004e3610(uVar1,&pvStack_4);

    if (-1 < iVar3) {

                    /* WARNING: Subroutine does not return */

      operator_delete(pvStack_4);

    }

  }

  *(uint8_t *)(param_1[0x3971] + 0x1d) = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x3971] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x3971])(1);

  }

  param_1[0x3971] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x3973] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x3973])(1);

  }

  param_1[0x3973] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x3974] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x3974])(1);

  }

  param_1[0x3974] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x3975] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x3975])(1);

  }

  param_1[0x3975] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x3976] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x3976])(1);

  }

  param_1[0x3976] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x3972] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x3972])(1);

  }

  param_1[0x3972] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x3947] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x3947])(1);

  }

  param_1[0x3947] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x3949] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x3949])(1);

  }

  param_1[0x3949] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x3970] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x3970])(1);

  }

  param_1[0x3970] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x3948] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x3948])(1);

  }

  pvVar2 = (void *)param_1[0x3942];

  param_1[0x3948] = 0;

  if (pvVar2 != (void *)0x0) {

    FUN_005b0680();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar2);

  }

  iVar3 = param_1[0x397f];

  param_1[0x3942] = 0;

  if (iVar3 != 0) {

    iVar5 = FUN_0040b020();

    while (iVar5 != 0) {

      iVar5 = FUN_0040b020();

    }

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0;

    if ((uint32_t /* width from decompiler */ *)param_1[0x397f] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x397f])(1);

    }

    param_1[0x397f] = 0;

  }

  iVar3 = param_1[0x3991];

  if (iVar3 != 0) {

    puVar4 = (uint32_t /* width from decompiler */ *)FUN_0040b020();

    while (puVar4 != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)*puVar4)(1);

      puVar4 = (uint32_t /* width from decompiler */ *)FUN_0040b020();

    }

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc) = 0;

    if ((uint32_t /* width from decompiler */ *)param_1[0x3991] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x3991])(1);

    }

    param_1[0x3991] = 0;

  }

  if ((uint32_t /* width from decompiler */ *)param_1[0x3992] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x3992])(1);

  }

  param_1[0x3992] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x3993] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x3993])(1);

  }

  param_1[0x3993] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x397e] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x397e])(1);

  }

  param_1[0x397e] = 0;

  FUN_004d2970();

  if ((uint32_t /* width from decompiler */ *)param_1[0x3943] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x3943])(1);

  }

  param_1[0x3943] = 0;

  FUN_005bf720();

  if ((uint32_t /* width from decompiler */ *)param_1[0x3a3d] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x3a3d])(1);

  }

  param_1[0x3a3d] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x3a26] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x3a26])(1);

  }

  param_1[0x3a26] = 0;

  if (param_1[0x3a27] != 0) {

    *(uint32_t /* width from decompiler */ *)(param_1[0x3a27] + 0x2e4) = 0;

    (**(code **)(**(int **)(param_1[0x3a27] + 0x2c) + 0x10))();

  }

  if ((uint32_t /* width from decompiler */ *)param_1[0x3a25] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x3a25])(1);

  }

  param_1[0x3a25] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x3a24] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x3a24])(1);

  }

  param_1[0x3a24] = 0;

  if ((void *)param_1[0x3a42] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x3a42]);

  }

  param_1[0x3a42] = 0;

  param_1[0x3a43] = 0;

  param_1[0x3a44] = 0;

  FUN_004e7380();

  FUN_00497360();

  FUN_00497360();

  if ((void *)param_1[0x3a33] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x3a33]);

  }

  param_1[0x3a33] = 0;

  param_1[0x3a34] = 0;

  param_1[0x3a35] = 0;

  if ((void *)param_1[0x3a2f] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x3a2f]);

  }

  param_1[0x3a2f] = 0;

  param_1[0x3a30] = 0;

  param_1[0x3a31] = 0;

  if ((void *)param_1[0x3a2a] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x3a2a]);

  }

  param_1[0x3a2a] = 0;

  param_1[0x3a2b] = 0;

  param_1[0x3a2c] = 0;

  if ((void *)param_1[0x3a21] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x3a21]);

  }

  param_1[0x3a21] = 0;

  param_1[0x3a22] = 0;

  param_1[0x3a23] = 0;

  if ((void *)param_1[0x3a1d] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x3a1d]);

  }

  param_1[0x3a1d] = 0;

  param_1[0x3a1e] = 0;

  param_1[0x3a1f] = 0;

  if ((void *)param_1[0x3a19] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x3a19]);

  }

  param_1[0x3a19] = 0;

  param_1[0x3a1a] = 0;

  param_1[0x3a1b] = 0;

  FUN_004e7350();

  FUN_004e7350();

  if (-1 < (int)param_1[0x3a05]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[0x3a03],param_1[0x3a05] * 4,0x12);

  }

  if ((void *)param_1[0x39ff] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x39ff]);

  }

  param_1[0x39ff] = 0;

  param_1[0x3a00] = 0;

  param_1[0x3a01] = 0;

  if ((void *)param_1[0x39ea] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x39ea]);

  }

  param_1[0x39ea] = 0;

  param_1[0x39eb] = 0;

  param_1[0x39ec] = 0;

  if ((void *)param_1[0x39e6] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x39e6]);

  }

  param_1[0x39e6] = 0;

  param_1[0x39e7] = 0;

  param_1[0x39e8] = 0;

  if ((void *)param_1[0x39e2] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x39e2]);

  }

  param_1[0x39e2] = 0;

  param_1[0x39e3] = 0;

  param_1[0x39e4] = 0;

  FUN_00497360();

  if ((void *)param_1[0x39db] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x39db]);

  }

  param_1[0x39db] = 0;

  param_1[0x39dc] = 0;

  param_1[0x39dd] = 0;

  if ((void *)param_1[0x39d7] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x39d7]);

  }

  param_1[0x39d7] = 0;

  param_1[0x39d8] = 0;

  param_1[0x39d9] = 0;

  if ((void *)param_1[0x39d3] == (void *)0x0) {

    param_1[0x39d3] = 0;

    param_1[0x39d4] = 0;

    param_1[0x39d5] = 0;

    FUN_004e7320();

    if ((void *)param_1[0x39cc] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete((void *)param_1[0x39cc]);

    }

    param_1[0x39cc] = 0;

    param_1[0x39cd] = 0;

    param_1[0x39ce] = 0;

    if ((void *)param_1[0x39c8] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete((void *)param_1[0x39c8]);

    }

    param_1[0x39c8] = 0;

    param_1[0x39c9] = 0;

    param_1[0x39ca] = 0;

    FUN_00497360();

    if ((void *)param_1[0x39c1] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete((void *)param_1[0x39c1]);

    }

    param_1[0x39c1] = 0;

    param_1[0x39c2] = 0;

    param_1[0x39c3] = 0;

    if ((void *)param_1[0x39bd] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete((void *)param_1[0x39bd]);

    }

    param_1[0x39bd] = 0;

    param_1[0x39be] = 0;

    param_1[0x39bf] = 0;

    FUN_004e4460();

    FUN_004e4410();

    FUN_004bcbf0();

    FUN_00497360();

    if ((void *)param_1[0x3978] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete((void *)param_1[0x3978]);

    }

    param_1[0x3978] = 0;

    param_1[0x3979] = 0;

    param_1[0x397a] = 0;

    FUN_004e7200();

    FUN_004e7200();

    if ((void *)param_1[0x3953] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete((void *)param_1[0x3953]);

    }

    param_1[0x3953] = 0;

    param_1[0x3954] = 0;

    param_1[0x3955] = 0;

    if ((void *)param_1[0x394f] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete((void *)param_1[0x394f]);

    }

    param_1[0x394f] = 0;

    param_1[0x3950] = 0;

    param_1[0x3951] = 0;

    if ((void *)param_1[0x394b] == (void *)0x0) {

      param_1[0x394b] = 0;

      param_1[0x394c] = 0;

      param_1[0x394d] = 0;

      FUN_004e72f0();

      FUN_00497360();

      if ((void *)param_1[0x15] == (void *)0x0) {

        param_1[0x15] = 0;

        param_1[0x16] = 0;

        param_1[0x17] = 0;

        FUN_004e72c0();

        FUN_004e7290();

        return;

      }

                    /* WARNING: Subroutine does not return */

      operator_delete((void *)param_1[0x15]);

    }

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x394b]);

  }

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)param_1[0x39d3]);

}
