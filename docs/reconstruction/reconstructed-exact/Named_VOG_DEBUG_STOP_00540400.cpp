// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×7, for×3, return×3, while×1.
//  - Notable callees: FUN_007a4480×4, FUN_00540400, FUN_007df470.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 3.

// =============================================================================
// Named_VOG_DEBUG_STOP_00540400
// -----------------------------------------------------------------------------
// Stable ID: aa_00540400
// Address:   0x00540400  (autoassault.exe, image base 0x400000)
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

int __thiscall Named_VOG_DEBUG_STOP_00540400(int param_1,uint param_2,uint param_3,int param_4)



{

  int iVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  

  iVar5 = 0;

  piVar2 = operator_new(0xc);

  puVar3 = operator_new(0x3b4);

  puVar6 = puVar3;

  for (iVar4 = 0xed; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar6 = 0;

    puVar6 = puVar6 + 1;

  }

  *piVar2 = param_4;

  *(uint8_t *)((int)piVar2 + 9) = (uint8_t)param_3;

  *(uint8_t *)((int)piVar2 + 10) = (uint8_t)param_2;

  FUN_007df470(piVar2,puVar3);

  if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

    iVar4 = *(int *)(param_1 + 0xf10);

    if (*(char *)(iVar4 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar4 + 0x1d) = 1;

    while( true ) {

      iVar4 = *(int *)(param_1 + 0xf10);

      if (*(char *)(iVar4 + 0x1d) == '\0') {

        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      if (iVar5 == 0) {

        iVar5 = *(int *)(iVar4 + 0x14);

      }

      else {

        iVar5 = *(int *)(iVar5 + 0x14);

      }

      if (iVar5 == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = *(int *)(iVar5 + 8);

      }

      if (iVar4 == 0) break;

      if ((((*(int *)(iVar4 + 0x38) == 0x14) && (iVar1 = *(int *)(iVar4 + 0x3c), iVar1 != 0)) &&

          (*(byte *)(iVar1 + 0x532) == param_2)) &&

         ((*(byte *)(iVar1 + 0x531) == param_3 && (*(int *)(iVar1 + 0x528) == param_4)))) {

        *(uint8_t *)(*(int *)(param_1 + 0xf10) + 0x1d) = 0;

        return iVar4;

      }

    }

    *(uint8_t *)(*(int *)(param_1 + 0xf10) + 0x1d) = 0;

                    /* WARNING: Subroutine does not return */

    operator_delete(piVar2);

  }

  return 0;

}
