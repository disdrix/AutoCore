// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGTerrain_LoadTintMap_004336c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004336c0
// Callee of Named_CalleeOf_CVOGTerrain_LoadTintMap (+1 other named callers)
// Address:   0x004336c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGTerrain_LoadTintMap: config/load helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_CVOGTerrain_LoadTintMap (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: FUN_004334b0×2, FUN_004336c0×2, CONCAT11, CONCAT12, CONCAT13, FUN_004332b0, FUN_00433530.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGTerrain_LoadTintMap (+1 other named callers)
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

uint32_t /* width from decompiler */ * __thiscall

Named_CalleeOf_Named_CalleeOf_CVOGTerrain_LoadTintMap_004336c0(int param_1,uint32_t /* width from decompiler */ *param_2,int param_3,int param_4,char param_5)



{

  uint8_t uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ local_4;

  

  uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x150);

  if ((((*(int *)(param_1 + 4) == 0) || (param_3 < 0)) || (param_4 < 0)) ||

     ((*(int *)(param_1 + 0xc) <= param_3 || (*(int *)(param_1 + 0x10) <= param_4)))) {

    local_4 = uVar2;

    if (*(int *)(param_1 + 0x14c) == -1) {

      if (*(int *)(param_1 + 4) != 0) {

        Named_CalleeOf_Named_CalleeOf_CVOGTerrain_LoadTintMap_004336c0(param_2,0,0,1);

        return param_2;

      }

    }

    else if (*(ushort *)(param_1 + 0x16) < 0x18) {

      FUN_004334b0(*(uint8_t *)(param_1 + 0x14c));

      return param_2;

    }

  }

  else {

    if (*(int *)(param_1 + 0x28) == 0) {

      iVar4 = *(int *)(param_1 + 0x30) * param_4 + *(int *)(param_1 + 0x34);

      iVar5 = iVar4 + param_3 * 3;

      local_4._3_1_ = (uint8_t)((uint)uVar2 >> 0x18);

      local_4._0_3_ =

           CONCAT12(*(uint8_t *)(iVar5 + 2),

                    CONCAT11(*(uint8_t *)(iVar5 + 1),*(uint8_t *)(iVar4 + param_3 * 3)));

    }

    else {

      uVar2 = FUN_00433530();

      puVar3 = (uint32_t /* width from decompiler */ *)FUN_004334b0(uVar2);

      local_4 = *puVar3;

    }

    if ((*(int *)(param_1 + 0x1b0) != 0) && (param_5 != '\0')) {

      uVar1 = FUN_004332b0();

      local_4 = CONCAT13(uVar1,(undefined3)local_4);

    }

  }

  *param_2 = local_4;

  return param_2;

}
