// =============================================================================
// Skill_TtPhantom_castRay
// -----------------------------------------------------------------------------
// Stable ID: aa_00580ed0
// Address:   0x00580ed0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Skill_TtPhantom_castRay @ 0x00580ed0
// Stable ID: aa_00580ed0
// Embedded strings (evidence for future rename):
//   - "TtPhantom::castRay"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~78 non-empty decompiler lines.
//  - Control keywords: if×7, do×1, while×1, return×1.
//  - Notable callees: rdtsc×2, Skill_TtPhantom_castRay, FUN_005d6ae0.
//  - Strings: "TtPhantom::castRay".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "TtPhantom::castRay"
 * Domain alias of FUN_00580ed0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Skill_TtPhantom_castRay(int param_1,float *param_2,int param_3)



{

  int *piVar1;

  int iVar2;

  uint64_t uVar3;

  int *piVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  int local_48;

  char local_44 [4];

  float local_40;

  float local_3c;

  float local_38;

  float local_30;

  float local_2c;

  float local_28;

  float local_20;

  int local_1c;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtPhantom::castRay";

    uVar3 = rdtsc();

    DAT_00bc5644[1] = (int)uVar3;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  local_20 = param_2[9];

  if ((*(char *)(param_2 + 8) == '\0') ||

     (local_1c = *(int *)(*(int *)(param_1 + 8) + 0xd0), local_1c == 0)) {

    local_1c = 0;

  }

  else {

    local_1c = local_1c + 0x10;

  }

  local_48 = *(int *)(param_1 + 0x84);

  piVar4 = *(int **)(param_1 + 0x80);

  if (-1 < local_48 + -1) {

    do {

      piVar1 = *(int **)*piVar4;

      if (piVar1 != (int *)0x0) {

        iVar2 = ((int *)*piVar4)[2];

        fVar6 = param_2[1] - *(float *)(iVar2 + 0x54);

        fVar7 = param_2[2] - *(float *)(iVar2 + 0x58);

        fVar5 = *param_2 - *(float *)(iVar2 + 0x50);

        local_40 = *(float *)(iVar2 + 0x28) * fVar7 + *(float *)(iVar2 + 0x24) * fVar6 +

                   *(float *)(iVar2 + 0x20) * fVar5;

        local_3c = *(float *)(iVar2 + 0x38) * fVar7 + *(float *)(iVar2 + 0x34) * fVar6 +

                   fVar5 * *(float *)(iVar2 + 0x30);

        local_38 = *(float *)(iVar2 + 0x48) * fVar7 + *(float *)(iVar2 + 0x44) * fVar6 +

                   fVar5 * *(float *)(iVar2 + 0x40);

        fVar7 = param_2[6] - *(float *)(iVar2 + 0x58);

        fVar6 = param_2[5] - *(float *)(iVar2 + 0x54);

        fVar5 = param_2[4] - *(float *)(iVar2 + 0x50);

        local_30 = *(float *)(iVar2 + 0x28) * fVar7 + *(float *)(iVar2 + 0x24) * fVar6 +

                   *(float *)(iVar2 + 0x20) * fVar5;

        local_2c = *(float *)(iVar2 + 0x38) * fVar7 + *(float *)(iVar2 + 0x34) * fVar6 +

                   fVar5 * *(float *)(iVar2 + 0x30);

        local_28 = *(float *)(iVar2 + 0x48) * fVar7 + *(float *)(iVar2 + 0x44) * fVar6 +

                   fVar5 * *(float *)(iVar2 + 0x40);

        (**(code **)(*piVar1 + 0x20))(local_44,&local_40,param_3);

        if (local_44[0] != '\0') {

          *(int *)(param_3 + 0x20) = *piVar4;

        }

      }

      piVar4 = piVar4 + 1;

      local_48 = local_48 + -1;

    } while (local_48 != 0);

  }

  if (*(int *)(param_3 + 0x20) != 0) {

    FUN_005d6ae0(*(int *)(*(int *)(param_3 + 0x20) + 8) + 0x20,param_3);

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar3 = rdtsc();

    DAT_00bc5644[1] = (int)uVar3;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
