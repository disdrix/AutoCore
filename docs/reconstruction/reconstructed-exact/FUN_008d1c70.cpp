// =============================================================================
// FUN_008d1c70
// -----------------------------------------------------------------------------
// Stable ID: aa_008d1c70
// Address:   0x008d1c70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008d1c70 @ 0x008d1c70
// Stable ID: aa_008d1c70
// Embedded strings (evidence for future rename):
//   - "HashError:TraversalLock, already locked for traversal"
//   - "VOG_DEBUG_STOP"
//   - "HashError:TraverseToNext, not locked for traversal"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~432 non-empty decompiler lines.
//  - Control keywords: if×63, for×14, return×8, do×7, goto×7, while×7.
//  - Notable callees: FUN_007a4480×28, FUN_00419880×7, FUN_008d1c70.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 8.

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

void __fastcall FUN_008d1c70(int *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int in_EAX;

  int *piVar3;

  int iVar4;

  int *local_4;

  

  iVar4 = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x840) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x824) = 0;

  local_4 = param_1;

  if (*(void **)(in_EAX + 0x8e0) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(in_EAX + 0x8e0));

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x8e0) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x8e4) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x8e8) = 0;

  iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x544) + 4) + 4) + 0xac +

                                    *(int *)(in_EAX + 0x544)) + 0x3c) + 0x538);

  if (*(char *)(iVar1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar1 + 0x1d) = 1;

  do {

    iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x544) + 4) + 4) + 0xac +

                                      *(int *)(in_EAX + 0x544)) + 0x3c) + 0x538);

    if (*(char *)(iVar1 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar4 == 0) {

      iVar4 = *(int *)(iVar1 + 0x14);

      if (iVar4 == 0) goto LAB_008d1d49;

      piVar3 = *(int **)(iVar4 + 8);

    }

    else {

      iVar4 = *(int *)(iVar4 + 0x14);

      if (iVar4 == 0) {

LAB_008d1d49:

        piVar3 = (int *)0x0;

      }

      else {

        piVar3 = *(int **)(iVar4 + 8);

      }

    }

    local_4 = piVar3;

    if (piVar3 == (int *)0x0) break;

    iVar1 = *(int *)(in_EAX + 0x8e0);

    if ((iVar1 == 0) ||

       ((uint)(*(int *)(in_EAX + 0x8e8) - iVar1 >> 2) <=

        (uint)(*(int *)(in_EAX + 0x8e4) - iVar1 >> 2))) {

      FUN_00419880(in_EAX + 0x8dc,*(uint32_t /* width from decompiler */ *)(in_EAX + 0x8e4),&local_4);

    }

    else {

      puVar2 = *(uint32_t /* width from decompiler */ **)(in_EAX + 0x8e4);

      *puVar2 = piVar3;

      *(uint32_t /* width from decompiler */ **)(in_EAX + 0x8e4) = puVar2 + 1;

    }

    if (*piVar3 == *(int *)(*(int *)(in_EAX + 0x544) + 0x6f8)) {

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x824) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x840);

    }

    *(int *)(in_EAX + 0x840) = *(int *)(in_EAX + 0x840) + 1;

  } while( true );

  iVar4 = 0;

  *(uint8_t *)

   (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x544) + 4) + 4) + 0xac +

                              *(int *)(in_EAX + 0x544)) + 0x3c) + 0x538) + 0x1d) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x828) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x80c) = 0;

  if (*(void **)(in_EAX + 0x880) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(in_EAX + 0x880));

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x880) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x884) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x888) = 0;

  iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x544) + 4) + 4) + 0xac +

                                    *(int *)(in_EAX + 0x544)) + 0x3c) + 0x544);

  if (*(char *)(iVar1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar1 + 0x1d) = 1;

  do {

    iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x544) + 4) + 4) + 0xac +

                                      *(int *)(in_EAX + 0x544)) + 0x3c) + 0x544);

    if (*(char *)(iVar1 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar4 == 0) {

      iVar4 = *(int *)(iVar1 + 0x14);

      if (iVar4 == 0) goto LAB_008d1eab;

      piVar3 = *(int **)(iVar4 + 8);

    }

    else {

      iVar4 = *(int *)(iVar4 + 0x14);

      if (iVar4 == 0) {

LAB_008d1eab:

        piVar3 = (int *)0x0;

      }

      else {

        piVar3 = *(int **)(iVar4 + 8);

      }

    }

    local_4 = piVar3;

    if (piVar3 == (int *)0x0) break;

    iVar1 = *(int *)(in_EAX + 0x880);

    if ((iVar1 == 0) ||

       ((uint)(*(int *)(in_EAX + 0x888) - iVar1 >> 2) <=

        (uint)(*(int *)(in_EAX + 0x884) - iVar1 >> 2))) {

      FUN_00419880(in_EAX + 0x87c,*(uint32_t /* width from decompiler */ *)(in_EAX + 0x884),&local_4);

    }

    else {

      puVar2 = *(uint32_t /* width from decompiler */ **)(in_EAX + 0x884);

      *puVar2 = piVar3;

      *(uint32_t /* width from decompiler */ **)(in_EAX + 0x884) = puVar2 + 1;

    }

    if (*piVar3 == *(int *)(*(int *)(in_EAX + 0x544) + 0x700)) {

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x80c) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x828);

    }

    *(int *)(in_EAX + 0x828) = *(int *)(in_EAX + 0x828) + 1;

  } while( true );

  iVar4 = 0;

  *(uint8_t *)

   (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x544) + 4) + 4) + 0xac +

                              *(int *)(in_EAX + 0x544)) + 0x3c) + 0x544) + 0x1d) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x82c) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x810) = 0;

  if (*(void **)(in_EAX + 0x890) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(in_EAX + 0x890));

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x890) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x894) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x898) = 0;

  iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x544) + 4) + 4) + 0xac +

                                    *(int *)(in_EAX + 0x544)) + 0x3c) + 0x54c);

  if (*(char *)(iVar1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar1 + 0x1d) = 1;

  do {

    iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x544) + 4) + 4) + 0xac +

                                      *(int *)(in_EAX + 0x544)) + 0x3c) + 0x54c);

    if (*(char *)(iVar1 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar4 == 0) {

      iVar4 = *(int *)(iVar1 + 0x14);

      if (iVar4 == 0) goto LAB_008d200d;

      piVar3 = *(int **)(iVar4 + 8);

    }

    else {

      iVar4 = *(int *)(iVar4 + 0x14);

      if (iVar4 == 0) {

LAB_008d200d:

        piVar3 = (int *)0x0;

      }

      else {

        piVar3 = *(int **)(iVar4 + 8);

      }

    }

    local_4 = piVar3;

    if (piVar3 == (int *)0x0) break;

    iVar1 = *(int *)(in_EAX + 0x890);

    if ((iVar1 == 0) ||

       ((uint)(*(int *)(in_EAX + 0x898) - iVar1 >> 2) <=

        (uint)(*(int *)(in_EAX + 0x894) - iVar1 >> 2))) {

      FUN_00419880(in_EAX + 0x88c,*(uint32_t /* width from decompiler */ *)(in_EAX + 0x894),&local_4);

    }

    else {

      puVar2 = *(uint32_t /* width from decompiler */ **)(in_EAX + 0x894);

      *puVar2 = piVar3;

      *(uint32_t /* width from decompiler */ **)(in_EAX + 0x894) = puVar2 + 1;

    }

    if (*piVar3 == *(int *)(*(int *)(in_EAX + 0x544) + 0x704)) {

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x810) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x82c);

    }

    *(int *)(in_EAX + 0x82c) = *(int *)(in_EAX + 0x82c) + 1;

  } while( true );

  iVar4 = 0;

  *(uint8_t *)

   (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x544) + 4) + 4) + 0xac +

                              *(int *)(in_EAX + 0x544)) + 0x3c) + 0x54c) + 0x1d) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x830) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x814) = 0;

  if (*(void **)(in_EAX + 0x8a0) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(in_EAX + 0x8a0));

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x8a0) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x8a4) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x8a8) = 0;

  iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x544) + 4) + 4) + 0xac +

                                    *(int *)(in_EAX + 0x544)) + 0x3c) + 0x53c);

  if (*(char *)(iVar1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar1 + 0x1d) = 1;

  do {

    iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x544) + 4) + 4) + 0xac +

                                      *(int *)(in_EAX + 0x544)) + 0x3c) + 0x53c);

    if (*(char *)(iVar1 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar4 == 0) {

      iVar4 = *(int *)(iVar1 + 0x14);

      if (iVar4 == 0) goto LAB_008d2179;

      piVar3 = *(int **)(iVar4 + 8);

    }

    else {

      iVar4 = *(int *)(iVar4 + 0x14);

      if (iVar4 == 0) {

LAB_008d2179:

        piVar3 = (int *)0x0;

      }

      else {

        piVar3 = *(int **)(iVar4 + 8);

      }

    }

    local_4 = piVar3;

    if (piVar3 == (int *)0x0) break;

    iVar1 = *(int *)(in_EAX + 0x8a0);

    if ((iVar1 == 0) ||

       ((uint)(*(int *)(in_EAX + 0x8a8) - iVar1 >> 2) <=

        (uint)(*(int *)(in_EAX + 0x8a4) - iVar1 >> 2))) {

      FUN_00419880(in_EAX + 0x89c,*(uint32_t /* width from decompiler */ *)(in_EAX + 0x8a4),&local_4);

    }

    else {

      puVar2 = *(uint32_t /* width from decompiler */ **)(in_EAX + 0x8a4);

      *puVar2 = piVar3;

      *(uint32_t /* width from decompiler */ **)(in_EAX + 0x8a4) = puVar2 + 1;

    }

    if (*piVar3 == *(int *)(*(int *)(in_EAX + 0x544) + 0x708)) {

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x814) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x830);

    }

    *(int *)(in_EAX + 0x830) = *(int *)(in_EAX + 0x830) + 1;

  } while( true );

  iVar4 = 0;

  *(uint8_t *)

   (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x544) + 4) + 4) + 0xac +

                              *(int *)(in_EAX + 0x544)) + 0x3c) + 0x53c) + 0x1d) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x834) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x818) = 0;

  if (*(void **)(in_EAX + 0x8b0) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(in_EAX + 0x8b0));

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x8b0) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x8b4) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x8b8) = 0;

  iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x544) + 4) + 4) + 0xac +

                                    *(int *)(in_EAX + 0x544)) + 0x3c) + 0x540);

  if (*(char *)(iVar1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar1 + 0x1d) = 1;

  do {

    iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x544) + 4) + 4) + 0xac +

                                      *(int *)(in_EAX + 0x544)) + 0x3c) + 0x540);

    if (*(char *)(iVar1 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar4 == 0) {

      iVar4 = *(int *)(iVar1 + 0x14);

      if (iVar4 == 0) goto LAB_008d22db;

      piVar3 = *(int **)(iVar4 + 8);

    }

    else {

      iVar4 = *(int *)(iVar4 + 0x14);

      if (iVar4 == 0) {

LAB_008d22db:

        piVar3 = (int *)0x0;

      }

      else {

        piVar3 = *(int **)(iVar4 + 8);

      }

    }

    local_4 = piVar3;

    if (piVar3 == (int *)0x0) break;

    iVar1 = *(int *)(in_EAX + 0x8b0);

    if ((iVar1 == 0) ||

       ((uint)(*(int *)(in_EAX + 0x8b8) - iVar1 >> 2) <=

        (uint)(*(int *)(in_EAX + 0x8b4) - iVar1 >> 2))) {

      FUN_00419880(in_EAX + 0x8ac,*(uint32_t /* width from decompiler */ *)(in_EAX + 0x8b4),&local_4);

    }

    else {

      puVar2 = *(uint32_t /* width from decompiler */ **)(in_EAX + 0x8b4);

      *puVar2 = piVar3;

      *(uint32_t /* width from decompiler */ **)(in_EAX + 0x8b4) = puVar2 + 1;

    }

    if (*piVar3 == *(int *)(*(int *)(in_EAX + 0x544) + 0x70c)) {

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x818) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x834);

    }

    *(int *)(in_EAX + 0x834) = *(int *)(in_EAX + 0x834) + 1;

  } while( true );

  iVar4 = 0;

  *(uint8_t *)

   (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x544) + 4) + 4) + 0xac +

                              *(int *)(in_EAX + 0x544)) + 0x3c) + 0x540) + 0x1d) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x838) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x81c) = 0;

  if (*(void **)(in_EAX + 0x8c0) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(in_EAX + 0x8c0));

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x8c0) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x8c4) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x8c8) = 0;

  iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x544) + 4) + 4) + 0xac +

                                    *(int *)(in_EAX + 0x544)) + 0x3c) + 0x548);

  if (*(char *)(iVar1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar1 + 0x1d) = 1;

  do {

    iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x544) + 4) + 4) + 0xac +

                                      *(int *)(in_EAX + 0x544)) + 0x3c) + 0x548);

    if (*(char *)(iVar1 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar4 == 0) {

      iVar4 = *(int *)(iVar1 + 0x14);

      if (iVar4 == 0) goto LAB_008d243d;

      piVar3 = *(int **)(iVar4 + 8);

    }

    else {

      iVar4 = *(int *)(iVar4 + 0x14);

      if (iVar4 == 0) {

LAB_008d243d:

        piVar3 = (int *)0x0;

      }

      else {

        piVar3 = *(int **)(iVar4 + 8);

      }

    }

    local_4 = piVar3;

    if (piVar3 == (int *)0x0) break;

    iVar1 = *(int *)(in_EAX + 0x8c0);

    if ((iVar1 == 0) ||

       ((uint)(*(int *)(in_EAX + 0x8c8) - iVar1 >> 2) <=

        (uint)(*(int *)(in_EAX + 0x8c4) - iVar1 >> 2))) {

      FUN_00419880(in_EAX + 0x8bc,*(uint32_t /* width from decompiler */ *)(in_EAX + 0x8c4),&local_4);

    }

    else {

      puVar2 = *(uint32_t /* width from decompiler */ **)(in_EAX + 0x8c4);

      *puVar2 = piVar3;

      *(uint32_t /* width from decompiler */ **)(in_EAX + 0x8c4) = puVar2 + 1;

    }

    if (*piVar3 == *(int *)(*(int *)(in_EAX + 0x544) + 0x710)) {

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x81c) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x838);

    }

    *(int *)(in_EAX + 0x838) = *(int *)(in_EAX + 0x838) + 1;

  } while( true );

  iVar4 = 0;

  *(uint8_t *)

   (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x544) + 4) + 4) + 0xac +

                              *(int *)(in_EAX + 0x544)) + 0x3c) + 0x548) + 0x1d) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x83c) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x820) = 0;

  if (*(void **)(in_EAX + 0x8d0) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(in_EAX + 0x8d0));

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x8d0) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x8d4) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x8d8) = 0;

  iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x544) + 4) + 4) + 0xac +

                                    *(int *)(in_EAX + 0x544)) + 0x3c) + 0x550);

  if (*(char *)(iVar1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar1 + 0x1d) = 1;

  do {

    iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x544) + 4) + 4) + 0xac +

                                      *(int *)(in_EAX + 0x544)) + 0x3c) + 0x550);

    if (*(char *)(iVar1 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar4 == 0) {

      iVar4 = *(int *)(iVar1 + 0x14);

      if (iVar4 == 0) goto LAB_008d25a9;

      piVar3 = *(int **)(iVar4 + 8);

    }

    else {

      iVar4 = *(int *)(iVar4 + 0x14);

      if (iVar4 == 0) {

LAB_008d25a9:

        piVar3 = (int *)0x0;

      }

      else {

        piVar3 = *(int **)(iVar4 + 8);

      }

    }

    if (piVar3 == (int *)0x0) {

      *(uint8_t *)

       (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x544) + 4) + 4) + 0xac +

                                  *(int *)(in_EAX + 0x544)) + 0x3c) + 0x550) + 0x1d) = 0;

      return;

    }

    iVar1 = *(int *)(in_EAX + 0x8d0);

    local_4 = piVar3;

    if ((iVar1 == 0) ||

       ((uint)(*(int *)(in_EAX + 0x8d8) - iVar1 >> 2) <=

        (uint)(*(int *)(in_EAX + 0x8d4) - iVar1 >> 2))) {

      FUN_00419880(in_EAX + 0x8cc,*(uint32_t /* width from decompiler */ *)(in_EAX + 0x8d4),&local_4);

    }

    else {

      puVar2 = *(uint32_t /* width from decompiler */ **)(in_EAX + 0x8d4);

      *puVar2 = piVar3;

      *(uint32_t /* width from decompiler */ **)(in_EAX + 0x8d4) = puVar2 + 1;

    }

    if (*piVar3 == *(int *)(*(int *)(in_EAX + 0x544) + 0x714)) {

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x820) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x83c);

    }

    *(int *)(in_EAX + 0x83c) = *(int *)(in_EAX + 0x83c) + 1;

  } while( true );

}
