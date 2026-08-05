// =============================================================================
// FUN_00784230
// -----------------------------------------------------------------------------
// Stable ID: aa_00784230
// Address:   0x00784230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00784230 @ 0x00784230
// Stable ID: aa_00784230
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~88 non-empty decompiler lines.
//  - Control keywords: if×14, for×2, return×2, goto×1, do×1, while×1.
//  - Notable callees: CONCAT31×2, FUN_00784230.
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

uint32_t /* width from decompiler */ __fastcall FUN_00784230(uint32_t /* width from decompiler */ param_1,uint *param_2,int param_3,ushort param_4)



{

  uint uVar1;

  uint uVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  uint uVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint local_4;

  

  local_4 = 0;

  if ((char)param_2[4] == '\0') {

    uVar4 = *param_2;

    if (uVar4 <= param_2[1]) {

      uVar4 = param_2[3];

    }

    uVar4 = uVar4 - param_2[1];

  }

  else {

    uVar4 = 0;

  }

  uVar5 = (uint)param_4;

  if (uVar4 < uVar5) {

    if ((char)param_2[4] != '\0') goto LAB_00784335;

    uVar4 = param_2[1];

    if (uVar4 < *param_2) {

      uVar5 = *param_2 - uVar4;

    }

    else {

      uVar5 = (uint)(ushort)((short)param_2[3] - (short)uVar4);

    }

  }

  if ((short)uVar5 != 0) {

    do {

      if (param_4 <= (ushort)local_4) break;

      uVar1 = local_4 + uVar5;

      puVar7 = (uint32_t /* width from decompiler */ *)((local_4 & 0xffff) + param_3);

      puVar8 = (uint32_t /* width from decompiler */ *)(param_2[5] + param_2[1]);

      for (uVar4 = (uVar5 & 0xffff) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

        *puVar8 = *puVar7;

        puVar7 = puVar7 + 1;

        puVar8 = puVar8 + 1;

      }

      for (uVar4 = uVar5 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

        *(uint8_t *)puVar8 = *(uint8_t *)puVar7;

        puVar7 = (uint32_t /* width from decompiler */ *)((int)puVar7 + 1);

        puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

      }

      param_2[1] = param_2[1] + (uVar5 & 0xffff);

      uVar2 = param_2[3];

      if (uVar2 <= param_2[1]) {

        param_2[1] = 0;

        *(uint8_t *)((int)param_2 + 0x11) = 1;

      }

      uVar4 = param_2[1];

      uVar3 = *param_2;

      if (uVar4 == uVar3) {

        *(uint8_t *)(param_2 + 4) = 1;

        uVar6 = 0;

      }

      else if ((char)param_2[4] == '\0') {

        uVar6 = uVar3;

        if (uVar3 <= uVar4) {

          uVar6 = uVar2;

        }

        uVar6 = uVar6 - uVar4;

      }

      else {

        uVar6 = 0;

      }

      uVar5 = (uint)param_4 - (uVar1 & 0xffff);

      if (uVar6 < uVar5) {

        if ((char)param_2[4] != '\0') break;

        if (uVar4 < uVar3) {

          uVar5 = uVar3 - uVar4;

        }

        else {

          uVar5 = uVar2 - uVar4;

        }

      }

      local_4 = uVar1;

    } while ((short)uVar5 != 0);

    return CONCAT31((int3)(uVar4 >> 8),1);

  }

LAB_00784335:

  return CONCAT31((int3)(uVar4 >> 8),1);

}
