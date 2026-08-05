// READABILITY (auto CF):
//  - Body size: ~112 non-empty decompiler lines.
//  - Control keywords: if×14, for×6, while×2, do×1, return×1.
//  - Notable callees: FUN_007a4480×12, FUN_004a6390×2, FUN_004eb3b0×2, FUN_00403450, FUN_00540610, FUN_0054a260, block.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_00540610
// -----------------------------------------------------------------------------
// Stable ID: aa_00540610
// Address:   0x00540610  (autoassault.exe, image base 0x400000)
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

/* WARNING: Removing unreachable block (ram,0x00540706) */



void __fastcall Named_VOG_DEBUG_STOP_00540610(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint8_t local_8c [128];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a3fa5;

  pvStack_c = ExceptionList;

  iVar2 = *(int *)(param_1 + 0xf10);

  ExceptionList = &pvStack_c;

  if (*(char *)(iVar2 + 0x1d) != '\0') {

    ExceptionList = &pvStack_c;

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar2 + 0x1d) = 1;

  iVar2 = *(int *)(param_1 + 0xf10);

  if (*(char *)(iVar2 + 0x1d) == '\0') {

    FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  iVar2 = *(int *)(iVar2 + 0x14);

  if (iVar2 == 0) {

    iVar3 = 0;

  }

  else {

    iVar3 = *(int *)(iVar2 + 8);

  }

  while (iVar3 != 0) {

    FUN_004eb3b0();

    if (*(int *)(iVar3 + 0x88) != 0) {

      iVar3 = *(int *)(iVar3 + 0x3c);

      uVar1 = (*(code *)PTR_FUN_00af8c9c)();

      FUN_00403450(iVar3 + 0x316,uVar1);

      uStack_4 = 0;

      FUN_004eb3b0();

      FUN_004a6390(local_8c);

      uStack_4 = 0xffffffff;

    }

    iVar3 = *(int *)(param_1 + 0xf10);

    if (*(char *)(iVar3 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar2 == 0) {

      iVar2 = *(int *)(iVar3 + 0x14);

    }

    else {

      iVar2 = *(int *)(iVar2 + 0x14);

    }

    if (iVar2 == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = *(int *)(iVar2 + 8);

    }

  }

  *(uint8_t *)(*(int *)(param_1 + 0xf10) + 0x1d) = 0;

  iVar2 = *(int *)(param_1 + 0xf0c);

  if (*(char *)(iVar2 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar2 + 0x1d) = 1;

  iVar2 = *(int *)(param_1 + 0xf0c);

  if (*(char *)(iVar2 + 0x1d) == '\0') {

    FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  iVar2 = *(int *)(iVar2 + 0x14);

  if (iVar2 == 0) {

    puVar4 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    puVar4 = *(uint32_t /* width from decompiler */ **)(iVar2 + 8);

  }

  if (puVar4 == (uint32_t /* width from decompiler */ *)0x0) {

    *(uint8_t *)(*(int *)(param_1 + 0xf0c) + 0x1d) = 0;

  }

  else {

    do {

      uVar1 = FUN_0054a260(*puVar4);

      FUN_004a6390(uVar1);

      iVar3 = *(int *)(param_1 + 0xf0c);

      if (*(char *)(iVar3 + 0x1d) == '\0') {

        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      if (iVar2 == 0) {

        iVar2 = *(int *)(iVar3 + 0x14);

      }

      else {

        iVar2 = *(int *)(iVar2 + 0x14);

      }

      if (iVar2 == 0) {

        puVar4 = (uint32_t /* width from decompiler */ *)0x0;

      }

      else {

        puVar4 = *(uint32_t /* width from decompiler */ **)(iVar2 + 8);

      }

    } while (puVar4 != (uint32_t /* width from decompiler */ *)0x0);

    *(uint8_t *)(*(int *)(param_1 + 0xf0c) + 0x1d) = 0;

  }

  ExceptionList = pvStack_c;

  return;

}
