// =============================================================================
// Named_CalleeOf_Named_stoChunk_00435f30
// -----------------------------------------------------------------------------
// Stable ID: aa_00435f30
// Callee of Named_stoChunk
// Address:   0x00435f30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_stoChunk: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×4, for×4, return×3.
//  - Notable callees: FUN_00435df0, FUN_00435f30.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_stoChunk
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_stoChunk_00435f30(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,uint param_3)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ unaff_EBX;

  uint32_t /* width from decompiler */ *puVar5;

  

  iVar3 = param_1[1];

  iVar1 = param_1[3];

  if (iVar1 < (int)(iVar3 + param_3)) {

    if ((int)param_1[4] < (int)param_3) {

      if (iVar3 < iVar1) {

        uVar2 = iVar1 - iVar3;

        puVar5 = (uint32_t /* width from decompiler */ *)(iVar3 + 0x18 + (int)param_1);

        for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

          *param_2 = *puVar5;

          puVar5 = puVar5 + 1;

          param_2 = param_2 + 1;

        }

        for (uVar4 = uVar2 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

          *(uint8_t *)param_2 = *(uint8_t *)puVar5;

          puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

          param_2 = (uint32_t /* width from decompiler */ *)((int)param_2 + 1);

        }

        param_1[1] = param_1[1] + uVar2;

        param_3 = param_3 - uVar2;

      }

      (**(code **)(*(int *)*param_1 + 4))(param_1[2] + param_1[1],0);

      (**(code **)(*(int *)*param_1 + 0x14))(unaff_EBX,param_3);

      param_1[1] = param_1[1] + param_3;

      return 0;

    }

    iVar3 = FUN_00435df0(param_1[2] + iVar3);

    if (iVar3 < 0) {

      return 0xffffffff;

    }

  }

  puVar5 = (uint32_t /* width from decompiler */ *)((int)param_1 + param_1[1] + 0x18);

  for (uVar2 = param_3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

    *param_2 = *puVar5;

    puVar5 = puVar5 + 1;

    param_2 = param_2 + 1;

  }

  for (uVar2 = param_3 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {

    *(uint8_t *)param_2 = *(uint8_t *)puVar5;

    puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

    param_2 = (uint32_t /* width from decompiler */ *)((int)param_2 + 1);

  }

  param_1[1] = param_1[1] + param_3;

  return 0;

}
