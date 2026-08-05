// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004af630
// -----------------------------------------------------------------------------
// Stable ID: aa_004af630
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x004af630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~133 non-empty decompiler lines.
//  - Control keywords: if×11, while×4, do×2, goto×2, return×1.
//  - Notable callees: FUN_004af010, FUN_004af630.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004af630(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3,code *param_4)



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

  uint32_t /* width from decompiler */ *puVar10;

  uint32_t /* width from decompiler */ *puStack_1c;

  

  puVar7 = param_2 + (((int)param_3 - (int)param_2 >> 3) - ((int)param_3 - (int)param_2 >> 0x1f) >>

                     1) * 2;

  FUN_004af010(param_2,puVar7,param_3 + -2,param_4);

  puStack_1c = puVar7;

  while (((param_2 < puStack_1c &&

          (cVar4 = (*param_4)(puStack_1c[-2],puStack_1c[-1],*puStack_1c,puStack_1c[1]),

          cVar4 == '\0')) &&

         (cVar4 = (*param_4)(*puStack_1c,puStack_1c[1],puStack_1c[-2],puStack_1c[-1]), cVar4 == '\0'

         ))) {

    puStack_1c = puStack_1c + -2;

  }

  do {

    puVar7 = puVar7 + 2;

    puVar3 = puVar7;

    puVar8 = puStack_1c;

    puVar6 = puStack_1c;

    if ((param_3 <= puVar7) ||

       (cVar4 = (*param_4)(*puVar7,puVar7[1],*puStack_1c,puStack_1c[1]), cVar4 != '\0')) break;

    cVar4 = (*param_4)(*puStack_1c,puStack_1c[1],*puVar7,puVar7[1]);

  } while (cVar4 == '\0');

joined_r0x004af6ea:

  do {

    puVar10 = puVar6;

    if (param_3 <= puVar3) {

joined_r0x004af750:

      while (param_2 < puVar6) {

        puVar5 = puVar10 + -2;

        cVar4 = (*param_4)(*puVar5,puVar10[-1],*puVar8,puVar8[1]);

        puVar9 = puVar8;

        if (cVar4 == '\0') {

          cVar4 = (*param_4)(*puVar8,puVar8[1],*puVar5,puVar10[-1]);

          puVar6 = puStack_1c;

          if (cVar4 != '\0') break;

          uVar1 = puVar8[-2];

          uVar2 = puVar8[-1];

          puVar9 = puVar8 + -2;

          *puVar9 = *puVar5;

          puVar8[-1] = puVar10[-1];

          *puVar5 = uVar1;

          puVar10[-1] = uVar2;

        }

        puVar6 = puStack_1c + -2;

        puVar10 = puVar5;

        puVar8 = puVar9;

        puStack_1c = puVar6;

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

        puStack_1c = puVar6 + -2;

        if (puVar3 == param_3) {

          puVar10 = puVar8 + -2;

          if (puStack_1c != puVar10) {

            uVar1 = *puStack_1c;

            uVar2 = puVar6[-1];

            *puStack_1c = *puVar10;

            puVar6[-1] = puVar8[-1];

            *puVar10 = uVar1;

            puVar8[-1] = uVar2;

          }

          uVar1 = *puVar10;

          uVar2 = puVar8[-1];

          *puVar10 = puVar7[-2];

          puVar8[-1] = puVar7[-1];

          puVar7[-2] = uVar1;

          puVar7[-1] = uVar2;

          puVar7 = puVar7 + -2;

          puVar8 = puVar10;

          puVar6 = puStack_1c;

        }

        else {

          uVar1 = puVar3[1];

          uVar2 = *puVar3;

          *puVar3 = *puStack_1c;

          puVar3[1] = puVar6[-1];

          *puStack_1c = uVar2;

          puVar6[-1] = uVar1;

          puVar3 = puVar3 + 2;

          puVar6 = puStack_1c;

        }

      }

      goto joined_r0x004af6ea;

    }

    cVar4 = (*param_4)(*puVar8,puVar8[1],*puVar3,puVar3[1]);

    if (cVar4 == '\0') {

      cVar4 = (*param_4)(*puVar3,puVar3[1],*puVar8,puVar8[1]);

      if (cVar4 != '\0') goto joined_r0x004af750;

      uVar1 = puVar7[1];

      uVar2 = *puVar7;

      *puVar7 = *puVar3;

      puVar7[1] = puVar3[1];

      puVar7 = puVar7 + 2;

      *puVar3 = uVar2;

      puVar3[1] = uVar1;

    }

    puVar3 = puVar3 + 2;

  } while( true );

}
