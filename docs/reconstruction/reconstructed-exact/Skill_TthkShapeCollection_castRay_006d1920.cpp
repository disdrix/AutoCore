// =============================================================================
// Skill_TthkShapeCollection_castRay_006d1920
// -----------------------------------------------------------------------------
// Stable ID: aa_006d1920
// Address:   0x006d1920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Skill_TthkShapeCollection_castRay_006d1920 @ 0x006d1920
// Stable ID: aa_006d1920
// Embedded strings (evidence for future rename):
//   - "TthkShapeCollection::castRay"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×4, for×2, return×1.
//  - Notable callees: rdtsc×2, Skill_TthkShapeCollection_castRay_006d1920.
//  - Strings: "TthkShapeCollection::castRay".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "TthkShapeCollection::castRay"
 * Domain alias of FUN_006d1920 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Skill_TthkShapeCollection_castRay_006d1920(int *param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  uint64_t uVar1;

  int iVar2;

  char *pcVar3;

  int *piVar4;

  int *local_128;

  uint32_t /* width from decompiler */ uStack_124;

  uint32_t /* width from decompiler */ uStack_120;

  int iStack_11c;

  uint8_t auStack_110 [268];

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TthkShapeCollection::castRay";

    uVar1 = rdtsc();

    local_128 = (int *)uVar1;

    DAT_00bc5644[1] = local_128;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  if (*(int *)(param_2 + 0x24) == 0) {

    for (iVar2 = (**(code **)(*param_1 + 0x2c))(); iVar2 != -1;

        iVar2 = (**(code **)(*param_1 + 0x30))(iVar2)) {

      local_128 = (int *)(**(code **)(*param_1 + 0x34))(iVar2,auStack_110);

      uStack_120 = *(uint32_t /* width from decompiler */ *)(param_3 + 8);

      iStack_11c = param_3;

      uStack_124 = iVar2;

      (**(code **)(*local_128 + 0x24))(param_2,&local_128,param_4);

    }

  }

  else {

    for (iVar2 = (**(code **)(*param_1 + 0x2c))(); iVar2 != -1;

        iVar2 = (**(code **)(*param_1 + 0x30))(iVar2)) {

      pcVar3 = (char *)(**(code **)**(uint32_t /* width from decompiler */ **)(param_2 + 0x24))

                                 ((int)&uStack_124 + 3,param_2,param_1,iVar2);

      if (*pcVar3 != '\0') {

        piVar4 = (int *)(**(code **)(*param_1 + 0x34))(iVar2,&uStack_120);

        (**(code **)(*piVar4 + 0x24))(param_2,&stack0xfffffec8,param_4);

      }

    }

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar1 = rdtsc();

    DAT_00bc5644[1] = (int)uVar1;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
