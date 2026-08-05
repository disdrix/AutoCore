// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_Load_004e7130
// -----------------------------------------------------------------------------
// Stable ID: aa_004e7130
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile
// Address:   0x004e7130  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile: config/load helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, while×1, goto×1.
//  - Notable callees: FUN_00404840, FUN_004e70e0, FUN_004e7130.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile
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

uint __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_Load_004e7130(uint param_1,uint param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint uVar7;

  

  if (param_2 != param_1) {

    puVar1 = *(uint32_t /* width from decompiler */ **)(param_2 + 4);

    puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

    puVar3 = (uint32_t /* width from decompiler */ *)*puVar2;

    puVar6 = (uint32_t /* width from decompiler */ *)*puVar1;

    uVar7 = param_1;

    while (puVar3 != puVar2) {

      if (puVar6 == puVar1) {

        return uVar7;

      }

      uVar7 = puVar6[2];

      iVar4 = puVar3[2];

      if (uVar7 == 0) {

LAB_004e7197:

        puVar5 = (uint32_t /* width from decompiler */ *)*puVar6;

        FUN_00404840(1);

        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + -1;

        *(uint32_t /* width from decompiler */ **)puVar6[1] = puVar5;

        *(uint32_t /* width from decompiler */ **)puVar5[1] = puVar3;

        *(uint32_t /* width from decompiler */ **)puVar3[1] = puVar6;

        uVar7 = puVar3[1];

        puVar3[1] = puVar5[1];

        puVar5[1] = puVar6[1];

        puVar6[1] = uVar7;

        puVar6 = puVar5;

      }

      else {

        if (iVar4 != 0) {

          if ((*(int *)(uVar7 + 0x164) <= *(int *)(iVar4 + 0x164)) &&

             ((*(int *)(uVar7 + 0x164) < *(int *)(iVar4 + 0x164) ||

              (uVar7 = *(uint *)(uVar7 + 0x160), uVar7 < *(uint *)(iVar4 + 0x160)))))

          goto LAB_004e7197;

        }

        puVar3 = (uint32_t /* width from decompiler */ *)*puVar3;

      }

    }

    if (puVar6 != puVar1) {

      param_1 = FUN_004e70e0(puVar2,param_2,puVar6,puVar1,*(uint32_t /* width from decompiler */ *)(param_2 + 8));

    }

  }

  return param_1;

}
