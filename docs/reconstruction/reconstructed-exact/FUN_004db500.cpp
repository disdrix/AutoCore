// =============================================================================
// FUN_004db500
// -----------------------------------------------------------------------------
// Stable ID: aa_004db500
// Address:   0x004db500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004db500 @ 0x004db500
// Stable ID: aa_004db500
// Embedded strings (evidence for future rename):
//   - "DoRoadAutoSplitting"
//   - "HashError:TraversalLock, already locked for traversal"
//   - "VOG_DEBUG_STOP"
//   - "HashError:TraverseToNext, not locked for traversal"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~119 non-empty decompiler lines.
//  - Control keywords: if×17, for×4, while×3, return×2, do×1.
//  - Notable callees: FUN_007a4480×8, FUN_004d5820, FUN_004db500, FUN_004e76d0, FUN_007a4390, FUN_007a4400.
//  - Strings: "DoRoadAutoSplitting"; "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
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

void __fastcall FUN_004db500(int param_1)



{

  int iVar1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  float fVar5;

  uint8_t auStack_224 [4];

  int *local_220;

  int *local_21c;

  uint32_t /* width from decompiler */ local_218;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a230c;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_007a4400("DoRoadAutoSplitting");

  iVar4 = 0;

  local_220 = (int *)0x0;

  local_21c = (int *)0x0;

  local_218 = 0;

  fVar5 = *(float *)(param_1 + 0xe7c0);

  local_4 = 1;

  if (*(float *)(param_1 + 0xe7c4) <= fVar5) {

    fVar5 = *(float *)(param_1 + 0xe7c4);

  }

  if (*(char *)(param_1 + 0xe575) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(param_1 + 0xe575) = 1;

  while( true ) {

    if (*(char *)(param_1 + 0xe575) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar4 == 0) {

      iVar4 = *(int *)(param_1 + 0xe56c);

    }

    else {

      iVar4 = *(int *)(iVar4 + 0x14);

    }

    if (iVar4 == 0) {

      piVar3 = (int *)0x0;

    }

    else {

      piVar3 = *(int **)(iVar4 + 8);

    }

    if (piVar3 == (int *)0x0) break;

    iVar1 = (**(code **)(*piVar3 + 0x20))();

    if (iVar1 == 0) {

      piVar2 = (int *)(**(code **)(*piVar3 + 0x1c))();

      if (piVar2 == (int *)0x0) {

        piVar3 = (int *)(**(code **)(*piVar3 + 0x24))();

        (**(code **)(*piVar3 + 0xa8))(fVar5);

      }

      else {

        (**(code **)(*piVar2 + 0xa8))(fVar5);

      }

    }

  }

  *(uint8_t *)(param_1 + 0xe575) = 0;

  iVar4 = 0;

  if (*(char *)(param_1 + 0xe575) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(param_1 + 0xe575) = 1;

  while( true ) {

    if (*(char *)(param_1 + 0xe575) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar4 == 0) {

      iVar4 = *(int *)(param_1 + 0xe56c);

    }

    else {

      iVar4 = *(int *)(iVar4 + 0x14);

    }

    if (iVar4 == 0) {

      piVar3 = (int *)0x0;

    }

    else {

      piVar3 = *(int **)(iVar4 + 8);

    }

    if (piVar3 == (int *)0x0) break;

    iVar1 = (**(code **)(*piVar3 + 0x20))();

    if (iVar1 == 0) {

      piVar2 = (int *)(**(code **)(*piVar3 + 0x1c))();

      if (piVar2 == (int *)0x0) {

        piVar2 = (int *)(**(code **)(*piVar3 + 0x24))();

      }

      (**(code **)(*piVar2 + 0xa4))(fVar5,auStack_224);

    }

  }

  *(uint8_t *)(param_1 + 0xe575) = 0;

  piVar3 = local_220;

  if (local_220 != local_21c) {

    do {

      iVar4 = *piVar3;

      FUN_004e76d0(*(uint32_t /* width from decompiler */ *)(iVar4 + 0x134),iVar4,0);

      FUN_004d5820(iVar4);

      piVar3 = piVar3 + 1;

    } while (piVar3 != local_21c);

  }

  if (local_220 == (int *)0x0) {

    local_220 = (int *)0x0;

    local_21c = (int *)0x0;

    local_218 = 0;

    local_4 = 0xffffffff;

    FUN_007a4390();

    ExceptionList = pvStack_c;

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(local_220);

}
