// =============================================================================
// FUN_006387d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006387d0
// Address:   0x006387d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006387d0 @ 0x006387d0
// Stable ID: aa_006387d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: if×10, for×4, do×3, while×3, return×2.
//  - Notable callees: FUN_00638370, FUN_006383e0, FUN_006384a0, FUN_00638560, FUN_006386a0, FUN_006387d0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __thiscall

FUN_006387d0(uint32_t /* width from decompiler */ *param_1,int param_2,uint param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ *param_5,

            uint param_6,uint param_7,int param_8)



{

  char cVar1;

  uint uVar2;

  uint uVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int local_8;

  

  if (param_5 == (uint32_t /* width from decompiler */ *)0x0) {

    param_6 = 0;

  }

  cVar1 = FUN_006386a0(param_3,param_6,param_7);

  if (cVar1 == '\0') {

    local_8 = 0;

  }

  else {

    uVar3 = param_3;

    if (param_8 != 0) {

      uVar3 = param_3 - 1;

    }

    FUN_00638370(*param_1,param_7);

    local_8 = param_1[1];

    uVar4 = 0;

    if (param_7 != 0) {

      uVar2 = 0;

      do {

        *(uint *)(local_8 + uVar2 * 4) = uVar2;

        uVar2 = uVar2 + 1;

      } while (uVar2 < param_7);

    }

    if (uVar3 != 0) {

      do {

        FUN_006383e0(uVar4 + param_2,param_4,param_1[(uVar4 & 1) + 1],param_1[(~uVar4 & 1) + 1],

                     param_7);

        uVar4 = uVar4 + 1;

      } while (uVar4 < uVar3);

    }

    if (param_8 == 1) {

      FUN_006384a0(uVar3 + param_2,param_1[(~uVar3 & 1) + 1],param_7);

    }

    else if (param_8 == 2) {

      FUN_00638560(uVar3 + param_2,param_4,param_1[(uVar3 & 1) + 1],param_1[(~uVar3 & 1) + 1],

                   param_7);

    }

    if ((param_5 != (uint32_t /* width from decompiler */ *)0x0) && (param_6 != 0)) {

      if ((param_3 & 1) != 0) {

        local_8 = param_1[2];

      }

      puVar5 = param_5;

      puVar6 = (uint32_t /* width from decompiler */ *)param_1[3];

      for (uVar3 = param_6 * param_7 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

        *puVar6 = *puVar5;

        puVar5 = puVar5 + 1;

        puVar6 = puVar6 + 1;

      }

      uVar3 = 0;

      for (uVar4 = param_6 * param_7 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

        *(uint8_t *)puVar6 = *(uint8_t *)puVar5;

        puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

        puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

      }

      if (param_7 != 0) {

        do {

          puVar5 = (uint32_t /* width from decompiler */ *)(*(int *)(local_8 + uVar3 * 4) * param_6 + param_1[3]);

          puVar6 = param_5;

          for (uVar4 = param_6 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

            *puVar6 = *puVar5;

            puVar5 = puVar5 + 1;

            puVar6 = puVar6 + 1;

          }

          for (uVar4 = param_6 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

            *(uint8_t *)puVar6 = *(uint8_t *)puVar5;

            puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

            puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

          }

          uVar3 = uVar3 + 1;

          param_5 = (uint32_t /* width from decompiler */ *)((int)param_5 + param_6);

        } while (uVar3 < param_7);

      }

      return local_8;

    }

  }

  return local_8;

}
