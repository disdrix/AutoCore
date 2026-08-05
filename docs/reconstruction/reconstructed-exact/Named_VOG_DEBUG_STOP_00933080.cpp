// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×8, for×3, return×2.
//  - Notable callees: FUN_007a4480×6, FUN_00411900×3, CVOGReaction_GiveItemByCbid, FUN_0051fae0, FUN_00933080.
//  - Strings: "Offline"; "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_00933080
// -----------------------------------------------------------------------------
// Stable ID: aa_00933080
// Address:   0x00933080  (autoassault.exe, image base 0x400000)
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

int Named_VOG_DEBUG_STOP_00933080(void)



{

  int iVar1;

  int in_EAX;

  int *piVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  

  piVar2 = (int *)CVOGReaction_GiveItemByCbid(in_EAX);

  if (piVar2 != (int *)0x0) {

    (**(code **)(*piVar2 + 8))();

    if (*(int *)(piVar2[0x2a] + 0x38) == 0x14) {

      iVar3 = (**(code **)(*piVar2 + 0x1dc))();

      iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0xac + iVar3) + 0x3c);

      *(uint8_t *)(iVar1 + 0x532) = *(uint8_t *)(iVar1 + 0x532);

      iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0xac + iVar3) + 0x3c);

      *(uint8_t *)(iVar1 + 0x531) = *(uint8_t *)(iVar1 + 0x531);

      FUN_0051fae0("Offline");

      iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0xac + iVar3) + 0x3c) +

                      0x538);

      if (*(char *)(iVar1 + 0x1d) != '\0') {

        FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      *(uint8_t *)(iVar1 + 0x1d) = 1;

      puVar4 = (uint32_t /* width from decompiler */ *)FUN_00411900(&stack0xfffffff8);

      *(uint8_t *)

       (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0xac + iVar3) + 0x3c) + 0x538

                ) + 0x1d) = 0;

      iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0xac + iVar3) + 0x3c) +

                      0x544);

      if (*(char *)(iVar1 + 0x1d) != '\0') {

        FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      *(uint8_t *)(iVar1 + 0x1d) = 1;

      puVar5 = (uint32_t /* width from decompiler */ *)FUN_00411900(&stack0xfffffff8);

      *(uint8_t *)

       (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0xac + iVar3) + 0x3c) + 0x544

                ) + 0x1d) = 0;

      iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0xac + iVar3) + 0x3c) +

                      0x548);

      if (*(char *)(iVar1 + 0x1d) != '\0') {

        FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      *(uint8_t *)(iVar1 + 0x1d) = 1;

      puVar6 = (uint32_t /* width from decompiler */ *)FUN_00411900(&stack0xfffffff8);

      *(uint8_t *)

       (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 0xac + iVar3) + 0x3c) + 0x548

                ) + 0x1d) = 0;

      if (puVar4 != (uint32_t /* width from decompiler */ *)0x0) {

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x6f8) = *puVar4;

      }

      if (puVar5 != (uint32_t /* width from decompiler */ *)0x0) {

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x700) = *puVar5;

      }

      if (puVar6 != (uint32_t /* width from decompiler */ *)0x0) {

        *(uint32_t /* width from decompiler */ *)(iVar3 + 0x710) = *puVar6;

      }

      return iVar3;

    }

  }

  return 0;

}
