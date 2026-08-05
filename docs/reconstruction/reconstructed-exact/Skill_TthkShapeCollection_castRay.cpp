// =============================================================================
// Skill_TthkShapeCollection_castRay
// -----------------------------------------------------------------------------
// Stable ID: aa_006d1700
// Address:   0x006d1700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Skill_TthkShapeCollection_castRay @ 0x006d1700
// Stable ID: aa_006d1700
// Embedded strings (evidence for future rename):
//   - "TthkShapeCollection::castRay"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×6, for×2, return×2.
//  - Notable callees: rdtsc×2, Skill_TthkShapeCollection_castRay.
//  - Strings: "TthkShapeCollection::castRay".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "TthkShapeCollection::castRay"
 * Domain alias of FUN_006d1700 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Skill_TthkShapeCollection_castRay(int *param_1,uint8_t *param_2,int param_3,int param_4)



{

  uint64_t uVar1;

  int iVar2;

  int *piVar3;

  char *pcVar4;

  uint8_t auStack_120 [3];

  uint8_t uStack_11d;

  uint local_11c;

  uint8_t auStack_110 [268];

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TthkShapeCollection::castRay";

    uVar1 = rdtsc();

    local_11c = (uint)uVar1;

    DAT_00bc5644[1] = local_11c;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  local_11c = local_11c & 0xffffff00;

  if (*(int *)(param_3 + 0x24) == 0) {

    for (iVar2 = (**(code **)(*param_1 + 0x2c))(); iVar2 != -1;

        iVar2 = (**(code **)(*param_1 + 0x30))(iVar2)) {

      piVar3 = (int *)(**(code **)(*param_1 + 0x34))(iVar2,auStack_110);

      pcVar4 = (char *)(**(code **)(*piVar3 + 0x20))(&stack0xfffffedb,param_3,param_4);

      if (*pcVar4 != '\0') {

        *(int *)(param_4 + 0x10) = iVar2;

      }

    }

  }

  else {

    for (iVar2 = (**(code **)(*param_1 + 0x2c))(); iVar2 != -1;

        iVar2 = (**(code **)(*param_1 + 0x30))(iVar2)) {

      pcVar4 = (char *)(**(code **)**(uint32_t /* width from decompiler */ **)(param_3 + 0x24))

                                 (&uStack_11d,param_3,param_1,iVar2);

      if (*pcVar4 != '\0') {

        piVar3 = (int *)(**(code **)(*param_1 + 0x34))(iVar2,auStack_120);

        pcVar4 = (char *)(**(code **)(*piVar3 + 0x20))(&stack0xfffffed3,param_3,param_4);

        if (*pcVar4 != '\0') {

          *(int *)(param_4 + 0x10) = iVar2;

        }

      }

    }

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar1 = rdtsc();

    DAT_00bc5644[1] = (int)uVar1;

    DAT_00bc5644 = DAT_00bc5644 + 3;

    *param_2 = (uint8_t)local_11c;

    return;

  }

  *param_2 = (uint8_t)local_11c;

  return;

}
