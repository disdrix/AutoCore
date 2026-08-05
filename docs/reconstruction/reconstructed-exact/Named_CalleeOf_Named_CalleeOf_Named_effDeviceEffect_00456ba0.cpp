// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_effDeviceEffect_00456ba0
// -----------------------------------------------------------------------------
// Stable ID: aa_00456ba0
// Callee of Named_CalleeOf_Named_effDeviceEffect
// Address:   0x00456ba0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_effDeviceEffect: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×7, return×2, do×1, while×1.
//  - Notable callees: FUN_00439810×2, stoChunkWriter_BeginChunk×2, stoChunkWriter_EndChunk×2, CONCAT31, FUN_00436f80, FUN_00456ba0, FUN_00767160, FUN_0096a6f0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_effDeviceEffect
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_effDeviceEffect_00456ba0(uint32_t /* width from decompiler */ *param_1,char *param_2)



{

  int *piVar1;

  int iVar2;

  undefined *puVar3;

  uint uVar4;

  uint uVar5;

  uint local_18;

  uint32_t /* width from decompiler */ *local_14;

  uint32_t /* width from decompiler */ *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009be6c0;

  local_c = ExceptionList;

  if (*param_2 != '\0') {

    ExceptionList = &local_c;

    local_10 = param_1;

    stoChunkWriter_BeginChunk(0x50465844,1);

    local_4 = 0;

    FUN_00439810();

    if (*(int *)(param_2 + 0xc) == 0) {

      local_18 = 0;

    }

    else {

      local_18 = *(int *)(param_2 + 0x10) - *(int *)(param_2 + 0xc) >> 2;

    }

    FUN_00439810();

    uVar5 = 0;

    if (local_18 != 0) {

      do {

        piVar1 = (int *)(*(int *)(param_2 + 0xc) + uVar5 * 4);

        if (DAT_00d1a560 == (code *)0x0) {

          local_14 = param_1;

          stoChunkWriter_BeginChunk(DAT_00d1ed20,1);

          local_4 = CONCAT31(local_4._1_3_,1);

          puVar3 = (undefined *)*piVar1;

          if (puVar3 == (undefined *)0x0) {

            puVar3 = PTR_DAT_00afa2bc;

          }

          if (param_1[7] == 0) {

            uVar4 = FUN_00436f80(param_1,puVar3);

            param_1[1] = param_1[1] | uVar4;

          }

          else {

            uVar4 = FUN_00767160(&DAT_00a9d6f8,puVar3);

            param_1[1] = param_1[1] | uVar4;

            uVar4 = (**(code **)(*(int *)*param_1 + 0x18))(&DAT_00a97b84,2);

            param_1[8] = 0;

            param_1[1] = uVar4 | param_1[1];

          }

          local_4 = local_4 & 0xffffff00;

          stoChunkWriter_EndChunk();

        }

        else {

          local_14 = (uint32_t /* width from decompiler */ *)0x0;

          iVar2 = (*DAT_00d1a560)(piVar1,&local_14);

          if (-1 < iVar2) {

            FUN_0096a6f0(param_1,0);

          }

        }

        uVar5 = uVar5 + 1;

      } while (uVar5 < local_18);

    }

    local_4 = 0xffffffff;

    stoChunkWriter_EndChunk();

    ExceptionList = local_c;

    return 0;

  }

  return 0xffffffff;

}
