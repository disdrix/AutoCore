// =============================================================================
// Named_CalleeOf_Named_Server_needs_an_update_00943b80
// -----------------------------------------------------------------------------
// Stable ID: aa_00943b80
// Callee of Named_Server_needs_an_update (+2 other named callers)
// Address:   0x00943b80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Server_needs_an_update: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_Server_needs_an_update (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~84 non-empty decompiler lines.
//  - Control keywords: if×9, while×3, do×2, return×2.
//  - Notable callees: FUN_00415e90×2, FUN_004bae00×2, CONCAT31, FUN_004040a0, FUN_00406b80, FUN_00418700, FUN_00418790, FUN_004962b0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_Server_needs_an_update (+2 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_Server_needs_an_update_00943b80(char param_1)



{

  void *pvVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  int unaff_EDI;

  bool bVar5;

  uint uStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  *(uint8_t *)(*(int *)(*(int *)(unaff_EDI + 0xe04) + 0xe894) + 0x8c) = 0;

  if ((*(int *)(unaff_EDI + 0xe04) != 0) && (*(int *)(*(int *)(unaff_EDI + 0xe04) + 0xe898) != 0)) {

    FUN_004962b0();

  }

  FUN_0093e120(0);

  FUN_00997120(unaff_EDI);

  if (param_1 != '\0') {

    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_EDI + 0xe98) + 4) + 4) + 4 +

                         *(int *)(unaff_EDI + 0xe98)) + 0x2a8))(*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xd34));

    FUN_0051f400();

  }

  FUN_00415e90();

  FUN_00415e90();

  if (param_1 != '\0') {

    iVar4 = *(int *)(unaff_EDI + 0xf00);

    uStack_8 = *(uint *)(*(int *)(unaff_EDI + 0xe98) + 0x250);

    iVar3 = FUN_00418700(iVar4,*(uint32_t /* width from decompiler */ *)(iVar4 + 4),&uStack_8);

    FUN_00418790();

    *(int *)(iVar4 + 4) = iVar3;

    **(int **)(iVar3 + 4) = iVar3;

  }

  FUN_009306d0();

  FUN_008026a0();

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xe08) = 0;

  if ((*(int *)(unaff_EDI + 0xf38) != 0) && (param_1 == '\0')) {

    *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_EDI + 0xf38) + 0xc70) = 0;

  }

  uStack_8 = **(int **)(unaff_EDI + 0xd28);

  if ((int *)uStack_8 != *(int **)(unaff_EDI + 0xd28)) {

    do {

      if (*(int **)(uStack_8 + 0x20) != (int *)0x0) {

        (**(code **)(**(int **)(uStack_8 + 0x20) + 4))(1);

      }

      FUN_004040a0();

    } while (uStack_8 != *(uint *)(unaff_EDI + 0xd28));

  }

  pvVar1 = *(void **)(*(int *)(unaff_EDI + 0xd28) + 4);

  if (*(char *)((int)pvVar1 + 0x29) != '\0') {

    *(int *)(*(int *)(unaff_EDI + 0xd28) + 4) = *(int *)(unaff_EDI + 0xd28);

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xd2c) = 0;

    *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xd28) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xd28);

    *(int *)(*(int *)(unaff_EDI + 0xd28) + 8) = *(int *)(unaff_EDI + 0xd28);

    if (*(int *)(unaff_EDI + 0xe04) != 0) {

      FUN_004bfcb0();

    }

    bVar5 = false;

    uStack_8 = uStack_8 & 0xffffff00;

    iVar4 = 2;

    do {

      uVar2 = uStack_8;

      uStack_4 = 0;

      iVar3 = FUN_004bae00(uStack_8,&uStack_4);

      while (iVar3 != 0) {

        FUN_00933370(unaff_EDI);

        iVar3 = FUN_004bae00(uVar2,&uStack_4);

      }

      bVar5 = bVar5 == false;

      iVar4 = iVar4 + -1;

      uVar2 = uStack_8 >> 8;

      uStack_8 = CONCAT31((int3)uVar2,bVar5);

    } while (iVar4 != 0);

    FUN_004bbeb0();

    FUN_0092f3b0();

    if (param_1 != '\0') {

      (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_EDI + 0xe98) + 4) + 4) + 4 +

                           *(int *)(unaff_EDI + 0xe98)) + 0x2a4))

                (*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xd34));

    }

    return;

  }

  FUN_00406b80(*(uint32_t /* width from decompiler */ *)((int)pvVar1 + 8));

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar1);

}
