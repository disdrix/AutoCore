// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×8, for×2, return×2.
//  - Notable callees: FUN_007a4480×4, FUN_00546800, FUN_0060b4d0, block.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_0060b4d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0060b4d0
// Address:   0x0060b4d0  (autoassault.exe, image base 0x400000)
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

/* WARNING: Removing unreachable block (ram,0x0060b554) */



void __fastcall Named_VOG_DEBUG_STOP_0060b4d0(int *param_1)



{

  int iVar1;

  void *pvVar2;

  

  if ((uint32_t /* width from decompiler */ *)param_1[3] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[3])(1);

  }

  param_1[3] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[2] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[2])(1);

  }

  param_1[2] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[1] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[1])(1);

  }

  iVar1 = *param_1;

  param_1[1] = 0;

  if (*(char *)(iVar1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar1 + 0x1d) = 1;

  iVar1 = *param_1;

  if (*(char *)(iVar1 + 0x1d) == '\0') {

    FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  iVar1 = *(int *)(iVar1 + 0x14);

  if (iVar1 == 0) {

    pvVar2 = (void *)0x0;

  }

  else {

    pvVar2 = *(void **)(iVar1 + 8);

  }

  if (pvVar2 == (void *)0x0) {

    *(uint8_t *)(*param_1 + 0x1d) = 0;

    if ((uint32_t /* width from decompiler */ *)*param_1 != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)*param_1)(1);

    }

    *param_1 = 0;

    return;

  }

  FUN_00546800();

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar2);

}
