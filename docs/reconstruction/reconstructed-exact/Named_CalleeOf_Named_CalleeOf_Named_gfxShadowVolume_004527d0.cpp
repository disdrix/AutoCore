// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxShadowVolume_004527d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004527d0
// Callee of Named_CalleeOf_Named_gfxShadowVolume
// Address:   0x004527d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxShadowVolume: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×10, return×6, goto×2.
//  - Notable callees: FUN_00450f30×5, FUN_00454310×5, FUN_004527d0, FUN_00454100, FUN_004555b0, FUN_004558a0.
//  - Return sites: 6.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxShadowVolume
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_CalleeOf_Named_gfxShadowVolume_004527d0(int param_1,uint32_t /* width from decompiler */ *param_2,int *param_3)



{

  char cVar1;

  float *in_EAX;

  uint32_t /* width from decompiler */ *puVar2;

  uint8_t local_8 [8];

  

  if (*(int *)(param_1 + 8) == 0) {

    FUN_00454310(param_2,1,in_EAX);

    return param_2;

  }

  if (param_3 == (int *)**(int **)(param_1 + 4)) {

    if ((*in_EAX <= (float)param_3[3] && (float)param_3[3] != *in_EAX) ||

       ((*in_EAX < (float)param_3[3] || *in_EAX == (float)param_3[3] &&

        ((in_EAX[1] <= (float)param_3[4] && (float)param_3[4] != in_EAX[1] ||

         ((in_EAX[1] < (float)param_3[4] || in_EAX[1] == (float)param_3[4] &&

          ((in_EAX[2] <= (float)param_3[5] && (float)param_3[5] != in_EAX[2] ||

           ((in_EAX[2] < (float)param_3[5] || in_EAX[2] == (float)param_3[5] &&

            ((in_EAX[3] <= (float)param_3[6] && (float)param_3[6] != in_EAX[3] ||

             ((in_EAX[3] < (float)param_3[6] || in_EAX[3] == (float)param_3[6] &&

              ((in_EAX[4] <= (float)param_3[7] && (float)param_3[7] != in_EAX[4] ||

               ((in_EAX[4] < (float)param_3[7] || in_EAX[4] == (float)param_3[7] &&

                (in_EAX[5] <= (float)param_3[8] && (float)param_3[8] != in_EAX[5])))))))))))))))))))

       ) {

LAB_0045289f:

      FUN_00454310(param_2,1,in_EAX);

      return param_2;

    }

  }

  else if (param_3 == *(int **)(param_1 + 4)) {

    cVar1 = FUN_00450f30();

    if (cVar1 != '\0') {

LAB_004528cf:

      FUN_00454310(param_2,0,in_EAX);

      return param_2;

    }

  }

  else {

    cVar1 = FUN_00450f30();

    if (cVar1 != '\0') {

      FUN_004558a0();

      cVar1 = FUN_00450f30();

      if (cVar1 != '\0') {

        if (*(char *)(param_3[2] + 0x81) != '\0') {

          FUN_00454310(param_2,0,in_EAX);

          return param_2;

        }

        goto LAB_0045289f;

      }

    }

    cVar1 = FUN_00450f30();

    if ((cVar1 != '\0') &&

       ((FUN_004555b0(), param_3 == *(int **)(param_1 + 4) ||

        (cVar1 = FUN_00450f30(), cVar1 != '\0')))) {

      if (*(char *)(param_3[2] + 0x81) == '\0') {

        FUN_00454310(param_2,1,in_EAX);

        return param_2;

      }

      goto LAB_004528cf;

    }

  }

  puVar2 = (uint32_t /* width from decompiler */ *)FUN_00454100(local_8);

  *param_2 = *puVar2;

  return param_2;

}
