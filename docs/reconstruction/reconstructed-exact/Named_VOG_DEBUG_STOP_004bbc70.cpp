// READABILITY (auto CF):
//  - Body size: ~127 non-empty decompiler lines.
//  - Control keywords: if×21, for×4, return×4, while×3.
//  - Notable callees: FUN_007a4480×8, FUN_004024d0×2, FUN_0040b020×2, InitializeCriticalSection×2, FUN_004bb970, FUN_004bbc70, FUN_004bcbf0.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 4.

// =============================================================================
// Named_VOG_DEBUG_STOP_004bbc70
// -----------------------------------------------------------------------------
// Stable ID: aa_004bbc70
// Address:   0x004bbc70  (autoassault.exe, image base 0x400000)
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

void __fastcall Named_VOG_DEBUG_STOP_004bbc70(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  int iVar2;

  _RTL_CRITICAL_SECTION local_34;

  _RTL_CRITICAL_SECTION local_1c;

  uint32_t /* width from decompiler */ local_4;

  

  *param_1 = &PTR_FUN_009cb448;

  iVar2 = 0;

  local_4 = 0xffffffff;

  InitializeCriticalSection(&local_34);

  InitializeCriticalSection(&local_1c);

  iVar1 = param_1[1];

  if (*(char *)(iVar1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar1 + 0x1d) = 1;

  while( true ) {

    iVar1 = param_1[1];

    if (*(char *)(iVar1 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar2 == 0) {

      iVar2 = *(int *)(iVar1 + 0x14);

    }

    else {

      iVar2 = *(int *)(iVar2 + 0x20);

    }

    if (iVar2 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = *(int *)(iVar2 + 0xc);

    }

    if (iVar1 == 0) break;

    if (*(int *)(iVar1 + 0xac) != 0) {

      FUN_004024d0(iVar1);

    }

  }

  *(uint8_t *)(param_1[1] + 0x1d) = 0;

  iVar1 = param_1[2];

  iVar2 = 0;

  if (*(char *)(iVar1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar1 + 0x1d) = 1;

  while( true ) {

    iVar1 = param_1[2];

    if (*(char *)(iVar1 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar2 == 0) {

      iVar2 = *(int *)(iVar1 + 0x14);

    }

    else {

      iVar2 = *(int *)(iVar2 + 0x20);

    }

    if (iVar2 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = *(int *)(iVar2 + 0xc);

    }

    if (iVar1 == 0) break;

    if (*(int *)(iVar1 + 0xac) != 0) {

      FUN_004024d0(iVar1);

    }

  }

  *(uint8_t *)(param_1[2] + 0x1d) = 0;

  iVar1 = FUN_0040b020();

  while (iVar1 != 0) {

    FUN_004bb970(*(uint8_t *)(iVar1 + 0x168),*(uint32_t /* width from decompiler */ *)(iVar1 + 0x160),

                 *(uint32_t /* width from decompiler */ *)(iVar1 + 0x164));

    iVar1 = FUN_0040b020();

  }

  if ((uint32_t /* width from decompiler */ *)param_1[6] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[6])(1);

  }

  param_1[6] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[7] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[7])(1);

  }

  param_1[7] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[8] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[8])(1);

  }

  param_1[8] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[9] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[9])(1);

  }

  param_1[9] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[1] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[1])(1);

  }

  param_1[1] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[2] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[2])(1);

  }

  param_1[2] = 0;

  FUN_004bcbf0();

  if ((void *)param_1[0x13] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x13]);

  }

  param_1[0x13] = 0;

  param_1[0x14] = 0;

  param_1[0x15] = 0;

  if ((void *)param_1[0xf] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0xf]);

  }

  param_1[0xf] = 0;

  param_1[0x10] = 0;

  param_1[0x11] = 0;

  if ((void *)param_1[0xb] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0xb]);

  }

  param_1[0xb] = 0;

  param_1[0xc] = 0;

  param_1[0xd] = 0;

  return;

}
