// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_Set_00560a30
// -----------------------------------------------------------------------------
// Stable ID: aa_00560a30
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveSta
// Address:   0x00560a30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveSta: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~121 non-empty decompiler lines.
//  - Control keywords: if×17, do×4, while×4, return×2.
//  - Notable callees: FUN_005b3300×4, FUN_0055eb80×2, FUN_00560750, FUN_00560a30.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_SetObjectActiveSta
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSpawnPoint_Set_00560a30(int param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  if (param_2 != param_3) {

    if (*(char *)((int)param_2 + 0x29) == '\0') {

      FUN_0055eb80(param_2);

    }

    if (*(char *)((int)param_3 + 0x29) == '\0') {

      FUN_0055eb80(param_3);

    }

    FUN_00560750(param_3 + 0x1a);

    iVar3 = param_2[0x10];

    iVar4 = param_3[0x10] + iVar3;

    if ((int)(param_2[0x11] & 0x7fffffff) < iVar4) {

      iVar2 = (param_2[0x11] & 0x7fffffff) * 2;

      if (iVar2 <= iVar4) {

        iVar2 = iVar4;

      }

      FUN_005b3300(param_2 + 0xf,iVar2,4);

    }

    iVar2 = 0;

    param_2[0x10] = iVar4;

    if (0 < (int)param_3[0x10]) {

      do {

        *(uint32_t /* width from decompiler */ *)(param_2[0xf] + iVar3 * 4) = *(uint32_t /* width from decompiler */ *)(param_3[0xf] + iVar2 * 4);

        *(uint32_t /* width from decompiler */ **)(*(int *)(param_3[0xf] + iVar2 * 4) + 0x44) = param_2;

        *(int *)(*(int *)(param_3[0xf] + iVar2 * 4) + 0x58) = iVar3;

        iVar2 = iVar2 + 1;

        iVar3 = iVar3 + 1;

      } while (iVar2 < (int)param_3[0x10]);

    }

    iVar3 = param_2[0x14];

    iVar4 = param_3[0x14] + iVar3;

    if ((int)(param_2[0x15] & 0x7fffffff) < iVar4) {

      iVar2 = (param_2[0x15] & 0x7fffffff) * 2;

      if (iVar2 <= iVar4) {

        iVar2 = iVar4;

      }

      FUN_005b3300(param_2 + 0x13,iVar2,4);

    }

    iVar2 = 0;

    param_2[0x14] = iVar4;

    if (0 < (int)param_3[0x14]) {

      iVar3 = iVar3 * 4;

      do {

        *(uint32_t /* width from decompiler */ *)(iVar3 + param_2[0x13]) = *(uint32_t /* width from decompiler */ *)(param_3[0x13] + iVar2 * 4);

        iVar4 = iVar2 * 4;

        iVar2 = iVar2 + 1;

        *(uint32_t /* width from decompiler */ **)(*(int *)(param_3[0x13] + iVar4) + 0x10) = param_2;

        iVar3 = iVar3 + 4;

      } while (iVar2 < (int)param_3[0x14]);

    }

    iVar3 = param_2[0x17];

    iVar4 = param_3[0x17] + iVar3;

    if ((int)(param_2[0x18] & 0x7fffffff) < iVar4) {

      iVar2 = (param_2[0x18] & 0x7fffffff) * 2;

      if (iVar2 <= iVar4) {

        iVar2 = iVar4;

      }

      FUN_005b3300(param_2 + 0x16,iVar2,4);

    }

    iVar2 = 0;

    param_2[0x17] = iVar4;

    if (0 < (int)param_3[0x17]) {

      iVar3 = iVar3 * 4;

      do {

        iVar4 = *(int *)(param_3[0x16] + iVar2 * 4);

        *(int *)(iVar3 + param_2[0x16]) = iVar4;

        iVar2 = iVar2 + 1;

        *(uint32_t /* width from decompiler */ **)(iVar4 + 0x14) = param_2;

        iVar3 = iVar3 + 4;

      } while (iVar2 < (int)param_3[0x17]);

    }

    iVar3 = param_3[2];

    if ((int)param_3[2] < (int)param_2[2]) {

      iVar3 = param_2[2];

    }

    param_2[2] = iVar3;

    param_2[3] = param_2[3] + param_3[3];

    param_2[4] = param_2[4] + param_3[4];

    param_2[6] = param_2[6] + param_3[6];

    param_2[5] = param_2[5] + param_3[5];

    iVar3 = param_2[0x1e];

    iVar4 = param_3[0x1e] + iVar3;

    if ((int)(param_2[0x1f] & 0x7fffffff) < iVar4) {

      iVar2 = (param_2[0x1f] & 0x7fffffff) * 2;

      if (iVar2 <= iVar4) {

        iVar2 = iVar4;

      }

      FUN_005b3300(param_2 + 0x1d,iVar2,8);

    }

    iVar2 = 0;

    param_2[0x1e] = iVar4;

    if (0 < (int)param_3[0x1e]) {

      iVar3 = iVar3 * 8;

      do {

        iVar4 = param_3[0x1d];

        iVar1 = param_2[0x1d];

        *(uint32_t /* width from decompiler */ *)(iVar3 + iVar1) = *(uint32_t /* width from decompiler */ *)(iVar4 + iVar2 * 8);

        *(uint32_t /* width from decompiler */ *)(iVar3 + 4 + iVar1) = *(uint32_t /* width from decompiler */ *)(iVar4 + 4 + iVar2 * 8);

        iVar2 = iVar2 + 1;

        iVar3 = iVar3 + 8;

      } while (iVar2 < (int)param_3[0x1e]);

    }

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + param_3[9] * 4) =

         *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + -4 + *(int *)(param_1 + 0xc) * 4);

    *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 8) + param_3[9] * 4) + 0x24) = param_3[9];

    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + -1;

    if ((*(char *)(param_2 + 10) == '\0') && (*(char *)(param_3 + 10) == '\0')) {

      *(uint8_t *)(param_2 + 10) = 0;

      (**(code **)*param_3)(1);

      return param_2;

    }

    *(uint8_t *)(param_2 + 10) = 1;

    (**(code **)*param_3)(1);

  }

  return param_2;

}
