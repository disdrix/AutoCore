// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_effDeviceEffect_004484e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004484e0
// Callee of Named_CalleeOf_Named_effDeviceEffect
// Address:   0x004484e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_effDeviceEffect: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~129 non-empty decompiler lines.
//  - Control keywords: if×13, while×3, goto×3, do×1, return×1.
//  - Notable callees: FUN_004484e0, FUN_00448bd0.
//  - Return sites: 1.

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

void Named_CalleeOf_Named_CalleeOf_Named_effDeviceEffect_004484e0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3,code *param_4)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  char cVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ *puVar9;

  uint32_t /* width from decompiler */ *local_1c;

  

  puVar7 = param_2 + (((int)param_3 - (int)param_2 >> 3) - ((int)param_3 - (int)param_2 >> 0x1f) >>

                     1) * 2;

  FUN_00448bd0(param_2,puVar7,param_3 + -2);

  puVar3 = puVar7;

  while (local_1c = puVar3, param_2 < local_1c) {

    puVar3 = local_1c + -2;

    cVar4 = (*param_4)(puVar3,local_1c);

    if ((cVar4 != '\0') || (cVar4 = (*param_4)(local_1c,puVar3), cVar4 != '\0')) break;

  }

  do {

    puVar7 = puVar7 + 2;

    puVar3 = puVar7;

    puVar8 = local_1c;

    puVar6 = local_1c;

    if (param_3 <= puVar7) break;

    cVar4 = (*param_4)(puVar7,local_1c);

    if ((cVar4 != '\0') || (cVar4 = (*param_4)(local_1c,puVar7), cVar4 != '\0')) break;

  } while( true );

joined_r0x00448574:

  puVar9 = puVar6;

  if (param_3 <= puVar3) {

joined_r0x004485be:

    while (param_2 < puVar6) {

      puVar5 = puVar9 + -2;

      cVar4 = (*param_4)(puVar5,puVar8);

      puVar6 = puVar8;

      if (cVar4 == '\0') {

        cVar4 = (*param_4)(puVar8,puVar5);

        puVar6 = local_1c;

        if (cVar4 != '\0') break;

        uVar1 = puVar8[-2];

        uVar2 = puVar8[-1];

        puVar6 = puVar8 + -2;

        *puVar6 = *puVar5;

        puVar8[-1] = puVar9[-1];

        *puVar5 = uVar1;

        puVar9[-1] = uVar2;

      }

      local_1c = local_1c + -2;

      puVar8 = puVar6;

      puVar9 = puVar5;

      puVar6 = local_1c;

    }

    if (puVar6 == param_2) {

      if (puVar3 == param_3) {

        *param_1 = puVar8;

        param_1[1] = puVar7;

        return;

      }

      if (puVar7 != puVar3) {

        uVar1 = *puVar8;

        uVar2 = puVar8[1];

        *puVar8 = *puVar7;

        puVar8[1] = puVar7[1];

        *puVar7 = uVar1;

        puVar7[1] = uVar2;

      }

      uVar1 = *puVar8;

      uVar2 = puVar8[1];

      *puVar8 = *puVar3;

      puVar8[1] = puVar3[1];

      *puVar3 = uVar1;

      puVar3[1] = uVar2;

      puVar7 = puVar7 + 2;

      puVar3 = puVar3 + 2;

      puVar8 = puVar8 + 2;

    }

    else {

      local_1c = puVar6 + -2;

      if (puVar3 == param_3) {

        puVar9 = puVar8 + -2;

        if (local_1c != puVar9) {

          uVar1 = *local_1c;

          uVar2 = puVar6[-1];

          *local_1c = *puVar9;

          puVar6[-1] = puVar8[-1];

          *puVar9 = uVar1;

          puVar8[-1] = uVar2;

        }

        uVar1 = *puVar9;

        uVar2 = puVar8[-1];

        *puVar9 = puVar7[-2];

        puVar8[-1] = puVar7[-1];

        puVar7[-2] = uVar1;

        puVar7[-1] = uVar2;

        puVar7 = puVar7 + -2;

        puVar8 = puVar9;

        puVar6 = local_1c;

      }

      else {

        uVar1 = puVar3[1];

        uVar2 = *puVar3;

        *puVar3 = *local_1c;

        puVar3[1] = puVar6[-1];

        *local_1c = uVar2;

        puVar6[-1] = uVar1;

        puVar3 = puVar3 + 2;

        puVar6 = local_1c;

      }

    }

    goto joined_r0x00448574;

  }

  cVar4 = (*param_4)(puVar8,puVar3);

  if (cVar4 == '\0') {

    cVar4 = (*param_4)(puVar3,puVar8);

    if (cVar4 != '\0') goto joined_r0x004485be;

    uVar1 = puVar7[1];

    uVar2 = *puVar7;

    *puVar7 = *puVar3;

    puVar7[1] = puVar3[1];

    puVar7 = puVar7 + 2;

    *puVar3 = uVar2;

    puVar3[1] = uVar1;

  }

  puVar3 = puVar3 + 2;

  goto joined_r0x00448574;

}
