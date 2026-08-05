// READABILITY (auto CF):
//  - Body size: ~95 non-empty decompiler lines.
//  - Control keywords: if×17, return×3, for×2, while×1, goto×1.
//  - Notable callees: FUN_007a4480×4, FUN_0049cad0, FUN_00542c20, FUN_00545db0, FUN_00569af0, FUN_0060b4d0, FUN_007b7ea0.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 3.

// =============================================================================
// Named_VOG_DEBUG_STOP_00542c20
// -----------------------------------------------------------------------------
// Stable ID: aa_00542c20
// Address:   0x00542c20  (autoassault.exe, image base 0x400000)
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

void __fastcall Named_VOG_DEBUG_STOP_00542c20(uint32_t /* width from decompiler */ *param_1)



{

  void *pvVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  char *pcVar5;

  

  *param_1 = &PTR_FUN_009d057c;

  if ((void *)param_1[0x3c8] != (void *)0x0) {

    operator_delete__((void *)param_1[0x3c8]);

  }

  param_1[0x3c8] = 0;

  (**(code **)(*(int *)param_1[0x3c7] + 4))();

  if ((uint32_t /* width from decompiler */ *)param_1[0x3c7] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x3c7])(1);

  }

  param_1[0x3c7] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x3bc] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x3bc])(1);

  }

  param_1[0x3bc] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x3c4] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x3c4])(1);

  }

  param_1[0x3c4] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x3c5] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x3c5])(1);

  }

  param_1[0x3c5] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x3c3] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x3c3])(1);

  }

  pvVar1 = (void *)param_1[0x3c6];

  param_1[0x3c3] = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_0060b4d0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  param_1[0x3c6] = 0;

  FUN_0049cad0();

  DAT_00b04690 = DAT_00b04690 + -1;

  if (DAT_00b04690 == 0) {

    pcVar5 = (char *)((int)DAT_00b04698 + 0x1d);

    iVar4 = 0;

    if (*pcVar5 != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *pcVar5 = '\x01';

    while( true ) {

      puVar3 = DAT_00b04698;

      if (*(char *)((int)DAT_00b04698 + 0x1d) == '\0') {

        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      if (iVar4 == 0) {

        iVar4 = puVar3[5];

      }

      else {

        iVar4 = *(int *)(iVar4 + 0x14);

      }

      if (iVar4 == 0) {

        puVar3 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        puVar3 = *(uint32_t /* width from decompiler */ **)(iVar4 + 8);

      }

      if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) break;

      iVar2 = puVar3[2];

      if (iVar2 == 0xe) {

LAB_00542d71:

        (**(code **)*puVar3)(0);

      }

      else if (iVar2 == 0x12) {

        (**(code **)*puVar3)(0);

      }

      else if (iVar2 == 0x14) goto LAB_00542d71;

    }

    *(uint8_t *)((int)DAT_00b04698 + 0x1d) = 0;

    (**(code **)*DAT_00b04698)(1);

    DAT_00b04698 = (uint32_t /* width from decompiler */ *)0x0;

    FUN_00569af0();

  }

  pvVar1 = DAT_00b0469c;

  if (DAT_00b0469c != (void *)0x0) {

    FUN_007b7ea0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  DAT_00b0469c = (void *)0x0;

  FUN_00545db0();

                    /* WARNING: Subroutine does not return */

  operator_delete((void *)param_1[0x3ca]);

}
