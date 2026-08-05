// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGTacArc_InitializeMesh_00744ea0
// -----------------------------------------------------------------------------
// Stable ID: aa_00744ea0
// Callee of Named_CalleeOf_CVOGTacArc_InitializeMesh
// Address:   0x00744ea0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGTacArc_InitializeMesh: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~142 non-empty decompiler lines.
//  - Control keywords: if×18, while×9, do×5, return×2.
//  - Notable callees: FUN_00426f60×5, FUN_0044d630×2, FUN_0044d920×2, FUN_00744ea0×2, FUN_0044d8c0, FUN_0044dc00, FUN_00744cc0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGTacArc_InitializeMesh
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_CVOGTacArc_InitializeMesh_00744ea0(int param_1,int *param_2,char param_3)



{

  char cVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ *puVar9;

  uint32_t /* width from decompiler */ *puStack_18;

  uint32_t /* width from decompiler */ *local_14;

  uint8_t auStack_10 [4];

  uint local_c;

  

  FUN_00426f60();

  iVar4 = FUN_0044d920();

  if (iVar4 == 1) {

    FUN_00426f60();

    FUN_0044d8c0();

    if (local_14[6] == *(int *)(param_1 + 4)) {

      FUN_0044d630(param_1 + 0x1c,&local_14,local_14);

    }

  }

  FUN_00426f60();

  iVar4 = FUN_0044d920();

  if (iVar4 != 0) {

    return 0;

  }

  piVar2 = *(int **)(param_1 + 0x54);

  piVar5 = *(int **)(param_1 + 0x50);

  if (piVar5 != piVar2) {

    do {

      if (*piVar5 == *param_2) break;

      piVar5 = piVar5 + 1;

    } while (piVar5 != piVar2);

    if (piVar5 != piVar2) {

      FUN_00744cc0(piVar5);

    }

  }

  FUN_00426f60();

  puVar9 = (uint32_t /* width from decompiler */ *)(*(uint32_t /* width from decompiler */ **)(param_1 + 0x14))[1];

  cVar1 = *(char *)((int)puVar9 + 0x25);

  puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x14);

  while (cVar1 == '\0') {

    if ((uint)puVar9[3] < local_c) {

      puVar6 = (uint32_t /* width from decompiler */ *)puVar9[2];

      puVar9 = puVar3;

    }

    else {

      puVar6 = (uint32_t /* width from decompiler */ *)*puVar9;

    }

    puVar3 = puVar9;

    puVar9 = puVar6;

    cVar1 = *(char *)((int)puVar6 + 0x25);

  }

  local_14 = puVar3;

  FUN_00426f60();

  puStack_18 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x14);

  cVar1 = *(char *)((int)puStack_18[1] + 0x25);

  puVar9 = (uint32_t /* width from decompiler */ *)puStack_18[1];

  while (cVar1 == '\0') {

    if (local_c < (uint)puVar9[3]) {

      puVar6 = (uint32_t /* width from decompiler */ *)*puVar9;

      puStack_18 = puVar9;

    }

    else {

      puVar6 = (uint32_t /* width from decompiler */ *)puVar9[2];

    }

    puVar9 = puVar6;

    cVar1 = *(char *)((int)puVar6 + 0x25);

  }

  do {

    if (puVar3 == puStack_18) {

      return 1;

    }

    puVar9 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x20);

    if (*(char *)((int)puVar9[1] + 0x25) == '\0') {

      puVar6 = (uint32_t /* width from decompiler */ *)puVar9[1];

      do {

        if ((uint)puVar6[3] < (uint)puVar3[6]) {

          puVar7 = (uint32_t /* width from decompiler */ *)puVar6[2];

        }

        else {

          puVar7 = (uint32_t /* width from decompiler */ *)*puVar6;

          puVar9 = puVar6;

        }

        puVar6 = puVar7;

      } while (*(char *)((int)puVar7 + 0x25) == '\0');

    }

    puVar6 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x20);

    if (*(char *)((int)puVar6[1] + 0x25) == '\0') {

      puVar7 = (uint32_t /* width from decompiler */ *)puVar6[1];

      do {

        if ((uint)puVar3[6] < (uint)puVar7[3]) {

          puVar8 = (uint32_t /* width from decompiler */ *)*puVar7;

          puVar6 = puVar7;

        }

        else {

          puVar8 = (uint32_t /* width from decompiler */ *)puVar7[2];

        }

        puVar7 = puVar8;

      } while (*(char *)((int)puVar8 + 0x25) == '\0');

    }

    if (puVar9 != puVar6) {

      do {

        if (puVar9[6] == *param_2) {

          FUN_0044d630(param_1 + 0x1c,auStack_10,puVar9);

          if (param_3 != '\0') {

            Named_CalleeOf_Named_CalleeOf_CVOGTacArc_InitializeMesh_00744ea0(puVar3 + 6,1);

          }

          break;

        }

        if (*(char *)((int)puVar9 + 0x25) == '\0') {

          puVar7 = (uint32_t /* width from decompiler */ *)puVar9[2];

          if (*(char *)((int)puVar7 + 0x25) == '\0') {

            cVar1 = *(char *)((int)*puVar7 + 0x25);

            puVar9 = puVar7;

            puVar7 = (uint32_t /* width from decompiler */ *)*puVar7;

            while (cVar1 == '\0') {

              cVar1 = *(char *)((int)*puVar7 + 0x25);

              puVar9 = puVar7;

              puVar7 = (uint32_t /* width from decompiler */ *)*puVar7;

            }

          }

          else {

            cVar1 = *(char *)((int)puVar9[1] + 0x25);

            puVar8 = (uint32_t /* width from decompiler */ *)puVar9[1];

            puVar7 = puVar9;

            while ((puVar9 = puVar8, cVar1 == '\0' && (puVar7 == (uint32_t /* width from decompiler */ *)puVar9[2]))) {

              cVar1 = *(char *)((int)puVar9[1] + 0x25);

              puVar8 = (uint32_t /* width from decompiler */ *)puVar9[1];

              puVar7 = puVar9;

            }

          }

        }

      } while (puVar9 != puVar6);

    }

    FUN_0044dc00();

    puVar3 = local_14;

  } while( true );

}
