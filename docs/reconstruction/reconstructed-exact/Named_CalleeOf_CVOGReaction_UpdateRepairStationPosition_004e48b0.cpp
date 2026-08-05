// =============================================================================
// Named_CalleeOf_CVOGReaction_UpdateRepairStationPosition_004e48b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004e48b0
// Callee of CVOGReaction_UpdateRepairStationPosition
// Address:   0x004e48b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_UpdateRepairStationPosition: event/reaction helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, do×1, while×1.
//  - Notable callees: FUN_004e37e0×2, FUN_004e48b0, FUN_005adff0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of CVOGReaction_UpdateRepairStationPosition
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

void __thiscall Named_CalleeOf_CVOGReaction_UpdateRepairStationPosition_004e48b0(int param_1,uint32_t /* width from decompiler */ *param_2,uint *param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  bool bVar2;

  uint *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ local_4;

  

  puVar3 = param_3;

  puVar5 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  bVar2 = true;

  local_4 = 1;

  if (*(char *)((int)puVar5[1] + 0x21) == '\0') {

    puVar4 = (uint32_t /* width from decompiler */ *)puVar5[1];

    do {

      puVar5 = puVar4;

      if (((int)puVar5[5] < (int)param_3[1]) ||

         (((int)puVar5[5] <= (int)param_3[1] && ((uint)puVar5[4] <= *param_3)))) {

        puVar4 = (uint32_t /* width from decompiler */ *)puVar5[2];

        bVar2 = false;

        local_4 = 0;

      }

      else {

        puVar4 = (uint32_t /* width from decompiler */ *)*puVar5;

        bVar2 = true;

        local_4 = 1;

      }

    } while (*(char *)((int)puVar4 + 0x21) == '\0');

  }

  param_3 = puVar5;

  if (bVar2) {

    if (puVar5 == (uint32_t /* width from decompiler */ *)**(int **)(param_1 + 4)) {

      puVar5 = (uint32_t /* width from decompiler */ *)FUN_004e37e0(&param_3,1,puVar5,puVar3);

      uVar1 = *puVar5;

      *(uint8_t *)(param_2 + 1) = 1;

      *param_2 = uVar1;

      return;

    }

    FUN_005adff0();

  }

  if (((int)param_3[5] <= (int)puVar3[1]) &&

     (((int)param_3[5] < (int)puVar3[1] || (param_3[4] < *puVar3)))) {

    puVar5 = (uint32_t /* width from decompiler */ *)FUN_004e37e0(&param_3,local_4,puVar5,puVar3);

    *param_2 = *puVar5;

    *(uint8_t *)(param_2 + 1) = 1;

    return;

  }

  *(uint8_t *)(param_2 + 1) = 0;

  *param_2 = param_3;

  return;

}
