// =============================================================================
// FUN_008f62a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008f62a0
// Address:   0x008f62a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008f62a0 @ 0x008f62a0
// Stable ID: aa_008f62a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~85 non-empty decompiler lines.
//  - Control keywords: if×10, goto×2, do×1, return×1, while×1.
//  - Notable callees: FUN_00866df0×2, FUN_00866da0, FUN_008f62a0.
//  - Return sites: 1.

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

void FUN_008f62a0(int param_1)



{

  int *piVar1;

  int iVar2;

  char cVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int *piVar6;

  uint8_t *puVar7;

  int iVar8;

  uint32_t /* width from decompiler */ uStack_3c;

  uint8_t local_20 [16];

  uint8_t auStack_10 [8];

  uint8_t auStack_8 [8];

  

  iVar2 = param_1;

  if (*(int *)(param_1 + 0x10f0) < *(int *)(param_1 + 0x10ec) - *(int *)(param_1 + 0x10e4)) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10f4) = 0;

  }

  iVar8 = *(int *)(param_1 + 0x10f4) + *(int *)(param_1 + 0x10ec);

  param_1 = 0;

  do {

    iVar4 = *(int *)(iVar2 + 0x50c) - param_1;

    if (iVar4 < 0) {

      iVar4 = iVar4 + 0x96;

    }

    piVar1 = *(int **)(iVar2 + 0xe88 + iVar4 * 4);

    if (piVar1 != (int *)0x0) {

      uStack_3c = 1;

      iVar4 = (**(code **)(*piVar1 + 0x140))(local_20);

      iVar4 = *(int *)(iVar4 + 4);

      iVar8 = iVar8 - iVar4;

      puVar5 = (uint32_t /* width from decompiler */ *)(**(code **)(*piVar1 + 0x120))(local_20,1,0);

      uStack_3c = *puVar5;

      (**(code **)(*piVar1 + 0x110))(&uStack_3c);

      if ((iVar8 < *(int *)(iVar2 + 0x10ec)) && (*(int *)(iVar2 + 0x10e4) < iVar4 + iVar8)) {

        uStack_3c = 0x8f6358;

        cVar3 = FUN_00866df0();

        if (cVar3 == '\0') {

          uStack_3c = 1;

LAB_008f636b:

          FUN_00866da0();

        }

      }

      else {

        uStack_3c = 0x8f6365;

        cVar3 = FUN_00866df0();

        if (cVar3 == '\x01') {

          uStack_3c = 0;

          goto LAB_008f636b;

        }

      }

      if (((iVar8 < *(int *)(iVar2 + 0x10e4)) && (*(int *)(iVar2 + 0x10e4) < iVar4 + iVar8)) ||

         ((iVar8 < *(int *)(iVar2 + 0x10ec) && (*(int *)(iVar2 + 0x10ec) < iVar4 + iVar8)))) {

        if (*(char *)((int)piVar1 + 0x8d) == '\0') {

          uStack_3c = 1;

          (**(code **)(*piVar1 + 0x24))();

        }

        uStack_3c = 0x8f63ae;

        (**(code **)(*piVar1 + 0x34c))();

        piVar1[0x149] = *(int *)(iVar2 + 0x10e4) - iVar8;

        piVar1[0x14b] = *(int *)(iVar2 + 0x10ec) - iVar8;

        piVar1[0x148] = 0;

        puVar7 = auStack_10;

      }

      else {

        if (*(char *)((int)piVar1 + 0x8d) != '\x01') goto LAB_008f6423;

        uStack_3c = 0;

        (**(code **)(*piVar1 + 0x24))();

        (**(code **)(*piVar1 + 0x34c))();

        piVar1[0x149] = 0;

        piVar1[0x14b] = iVar4;

        piVar1[0x148] = 0;

        puVar7 = auStack_8;

      }

      uStack_3c = 1;

      piVar6 = (int *)(**(code **)(*piVar1 + 0x140))(puVar7);

      piVar1[0x14a] = *piVar6;

    }

LAB_008f6423:

    param_1 = param_1 + 1;

    if (0x95 < param_1) {

      return;

    }

  } while( true );

}
