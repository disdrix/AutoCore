// =============================================================================
// Named_CalleeOf_Mission_Received_Connect_Request_8x_0042e380
// -----------------------------------------------------------------------------
// Stable ID: aa_0042e380
// Callee of Mission_Received_Connect_Request_8x
// Address:   0x0042e380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Received_Connect_Request_8x: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~161 non-empty decompiler lines.
//  - Control keywords: if×20, do×4, while×4, return×1.
//  - Notable callees: FUN_0042e380, free, malloc.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_Received_Connect_Request_8x
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

void Named_CalleeOf_Mission_Received_Connect_Request_8x_0042e380(void)



{

  int *piVar1;

  int *piVar2;

  uint uVar3;

  void *_Memory;

  uint8_t *puVar4;

  void *pvVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int iVar7;

  int iVar8;

  uint32_t /* width from decompiler */ *puVar9;

  int iVar10;

  uint8_t *unaff_ESI;

  uint8_t *unaff_EDI;

  int iStack_c;

  

  *unaff_ESI = *unaff_EDI;

  unaff_ESI[1] = unaff_EDI[1];

  unaff_ESI[2] = unaff_EDI[2];

  unaff_ESI[3] = unaff_EDI[3];

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 4) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 4);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 8);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xc) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xc);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x10);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x14);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x18);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x1c);

  piVar2 = *(int **)(unaff_ESI + 0x20);

  iVar10 = *(int *)(unaff_EDI + 0x20);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 2;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  *(int *)(unaff_ESI + 0x20) = iVar10;

  if (iVar10 != 0) {

    *(int *)(iVar10 + 8) = *(int *)(iVar10 + 8) + 1;

  }

  piVar2 = *(int **)(unaff_ESI + 0x24);

  iVar10 = *(int *)(unaff_EDI + 0x24);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 2;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  *(int *)(unaff_ESI + 0x24) = iVar10;

  if (iVar10 != 0) {

    *(int *)(iVar10 + 8) = *(int *)(iVar10 + 8) + 1;

  }

  piVar2 = *(int **)(unaff_ESI + 0x28);

  iVar10 = *(int *)(unaff_EDI + 0x28);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 2;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  *(int *)(unaff_ESI + 0x28) = iVar10;

  if (iVar10 != 0) {

    *(int *)(iVar10 + 8) = *(int *)(iVar10 + 8) + 1;

  }

  piVar2 = *(int **)(unaff_ESI + 0x2c);

  iVar10 = *(int *)(unaff_EDI + 0x2c);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 2;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  *(int *)(unaff_ESI + 0x2c) = iVar10;

  if (iVar10 != 0) {

    *(int *)(iVar10 + 8) = *(int *)(iVar10 + 8) + 1;

  }

  unaff_ESI[0x30] = unaff_EDI[0x30];

  unaff_ESI[0x31] = unaff_EDI[0x31];

  puVar4 = unaff_ESI + 0x32;

  iVar10 = 0x10;

  do {

    *puVar4 = puVar4[(int)unaff_EDI - (int)unaff_ESI];

    puVar4 = puVar4 + 1;

    iVar10 = iVar10 + -1;

  } while (iVar10 != 0);

  puVar4 = unaff_ESI + 0x42;

  iVar10 = 0x10;

  do {

    *puVar4 = puVar4[(int)unaff_EDI - (int)unaff_ESI];

    puVar4 = puVar4 + 1;

    iVar10 = iVar10 + -1;

  } while (iVar10 != 0);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x54) = 0;

  uVar3 = *(uint *)(unaff_EDI + 0x54);

  if (*(uint *)(unaff_ESI + 0x58) < uVar3) {

    iVar10 = uVar3 + (0x10 - (uVar3 & 0xf));

    pvVar5 = malloc(iVar10 * 0x14);

    _Memory = *(void **)(unaff_ESI + 0x5c);

    iStack_c = *(int *)(unaff_ESI + 0x54);

    *(void **)(unaff_ESI + 0x5c) = pvVar5;

    if (iStack_c != 0) {

      iVar7 = 0;

      do {

        puVar6 = (uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x5c) + iVar7);

        if (puVar6 != (uint32_t /* width from decompiler */ *)0x0) {

          puVar9 = (uint32_t /* width from decompiler */ *)((int)_Memory + iVar7);

          *puVar6 = *puVar9;

          puVar6[1] = puVar9[1];

          puVar6[2] = puVar9[2];

          puVar6[3] = puVar9[3];

          puVar6[4] = puVar9[4];

        }

        iVar7 = iVar7 + 0x14;

        iStack_c = iStack_c + -1;

      } while (iStack_c != 0);

    }

    *(void **)(unaff_ESI + 0x5c) = _Memory;

    free(_Memory);

    *(void **)(unaff_ESI + 0x5c) = pvVar5;

    *(int *)(unaff_ESI + 0x58) = iVar10;

  }

  iVar10 = *(int *)(unaff_EDI + 0x5c);

  iVar7 = *(int *)(unaff_EDI + 0x54);

  if (iVar7 != 0) {

    iVar8 = 0;

    do {

      puVar6 = (uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x5c) + iVar8);

      if (puVar6 != (uint32_t /* width from decompiler */ *)0x0) {

        puVar9 = (uint32_t /* width from decompiler */ *)(iVar10 + iVar8);

        *puVar6 = *puVar9;

        puVar6[1] = puVar9[1];

        puVar6[2] = puVar9[2];

        puVar6[3] = puVar9[3];

        puVar6[4] = puVar9[4];

      }

      iVar8 = iVar8 + 0x14;

      iVar7 = iVar7 + -1;

    } while (iVar7 != 0);

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x54) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x54);

  unaff_ESI[0x60] = unaff_EDI[0x60];

  unaff_ESI[0x61] = unaff_EDI[0x61];

  piVar2 = *(int **)(unaff_ESI + 100);

  iVar10 = *(int *)(unaff_EDI + 100);

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 2;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  *(int *)(unaff_ESI + 100) = iVar10;

  if (iVar10 != 0) {

    *(int *)(iVar10 + 8) = *(int *)(iVar10 + 8) + 1;

  }

  unaff_ESI[0x68] = unaff_EDI[0x68];

  return;

}
