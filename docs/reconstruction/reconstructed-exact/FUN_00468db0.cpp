// =============================================================================
// FUN_00468db0
// -----------------------------------------------------------------------------
// Stable ID: aa_00468db0
// Address:   0x00468db0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00468db0 @ 0x00468db0
// Stable ID: aa_00468db0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~112 non-empty decompiler lines.
//  - Control keywords: if×11, while×4, do×2, goto×2, return×1.
//  - Notable callees: FUN_00468c50×8, FUN_00468db0, FUN_00468fd0.
//  - Return sites: 1.

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

void FUN_00468db0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ param_4)



{

  uint32_t /* width from decompiler */ uVar1;

  char cVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ *local_c;

  uint32_t /* width from decompiler */ *local_8;

  

  puVar4 = param_2 + (((int)param_3 - (int)param_2 >> 2) - ((int)param_3 - (int)param_2 >> 0x1f) >>

                     1);

  FUN_00468fd0(param_2,puVar4,param_3 + -1,param_4);

  puVar3 = puVar4;

  while (((param_2 < puVar3 && (cVar2 = FUN_00468c50(), cVar2 == '\0')) &&

         (cVar2 = FUN_00468c50(), cVar2 == '\0'))) {

    puVar3 = puVar3 + -1;

  }

  do {

    puVar4 = puVar4 + 1;

    puVar5 = puVar4;

    local_c = puVar4;

    local_8 = puVar3;

    puVar8 = puVar3;

    if ((param_3 <= puVar4) || (cVar2 = FUN_00468c50(), cVar2 != '\0')) break;

    cVar2 = FUN_00468c50();

  } while (cVar2 == '\0');

joined_r0x00468e55:

  do {

    puVar6 = puVar3;

    if (param_3 <= puVar4) {

joined_r0x00468e93:

      while (puVar7 = puVar5, param_2 < puVar3) {

        puVar6 = puVar6 + -1;

        cVar2 = FUN_00468c50();

        if (cVar2 == '\0') {

          cVar2 = FUN_00468c50();

          puVar3 = local_8;

          puVar7 = local_c;

          if (cVar2 != '\0') break;

          uVar1 = puVar8[-1];

          puVar8 = puVar8 + -1;

          *puVar8 = *puVar6;

          *puVar6 = uVar1;

        }

        local_8 = local_8 + -1;

        puVar5 = local_c;

        puVar3 = local_8;

      }

      if (puVar3 == param_2) {

        if (puVar4 == param_3) {

          *param_1 = puVar8;

          param_1[1] = puVar7;

          return;

        }

        if (puVar7 != puVar4) {

          uVar1 = *puVar8;

          *puVar8 = *puVar7;

          *puVar7 = uVar1;

        }

        uVar1 = *puVar8;

        *puVar8 = *puVar4;

        *puVar4 = uVar1;

        puVar4 = puVar4 + 1;

        puVar5 = puVar7 + 1;

        local_c = puVar7 + 1;

        puVar8 = puVar8 + 1;

      }

      else {

        puVar3 = puVar3 + -1;

        local_8 = puVar3;

        if (puVar4 == param_3) {

          puVar8 = puVar8 + -1;

          if (puVar3 != puVar8) {

            uVar1 = *puVar3;

            *puVar3 = *puVar8;

            *puVar8 = uVar1;

          }

          uVar1 = *puVar8;

          puVar5 = puVar7 + -1;

          *puVar8 = puVar7[-1];

          *puVar5 = uVar1;

          local_c = puVar5;

        }

        else {

          uVar1 = *puVar4;

          *puVar4 = *puVar3;

          puVar4 = puVar4 + 1;

          *puVar3 = uVar1;

          puVar5 = puVar7;

        }

      }

      goto joined_r0x00468e55;

    }

    cVar2 = FUN_00468c50();

    puVar3 = local_8;

    if (cVar2 == '\0') {

      cVar2 = FUN_00468c50();

      puVar6 = local_8;

      local_c = puVar5;

      if (cVar2 != '\0') goto joined_r0x00468e93;

      uVar1 = *puVar5;

      *puVar5 = *puVar4;

      puVar5 = puVar5 + 1;

      *puVar4 = uVar1;

    }

    puVar4 = puVar4 + 1;

    local_c = puVar5;

  } while( true );

}
