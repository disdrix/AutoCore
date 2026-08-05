// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_00857100
// -----------------------------------------------------------------------------
// Stable ID: aa_00857100
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x00857100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, switch×1, while×1.
//  - Notable callees: ROUND×8, FUN_00857100.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */

Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_00857100(float param_1,float param_2,float param_3,float param_4,int param_5,int param_6,

            int param_7,int param_8,float *param_9)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  float fVar9;

  int local_10;

  

  iVar1 = 0;

  iVar3 = 0;

  iVar7 = (int)ROUND(param_2) - (int)ROUND(param_4);

  iVar2 = 0;

  iVar6 = 0;

  iVar8 = (int)ROUND(param_1) - (int)ROUND(param_3);

  local_10 = 0;

  do {

    switch(local_10) {

    case 0:

      iVar6 = param_8 + -1;

      iVar1 = param_5;

      iVar2 = param_6;

      iVar3 = param_5;

      break;

    case 1:

      iVar1 = param_7 + -1;

      iVar2 = param_6;

      iVar3 = param_7 + -1;

      iVar6 = param_8 + -1;

      break;

    case 2:

      iVar1 = param_5;

      iVar2 = param_6;

      iVar3 = param_7 + -1;

      iVar6 = param_6;

      break;

    case 3:

      iVar1 = param_5;

      iVar2 = param_8 + -1;

      iVar3 = param_7 + -1;

      iVar6 = param_8 + -1;

    }

    fVar9 = (float)(iVar8 * (iVar6 - iVar2) - iVar7 * (iVar3 - iVar1));

    if ((DAT_00aaa664 < fVar9) || (fVar9 < DAT_00aaa6b4)) {

      iVar4 = (int)ROUND(param_4) - iVar2;

      iVar5 = (int)ROUND(param_3) - iVar1;

      if ((0.0 <= (float)(iVar4 * (iVar3 - iVar1) - iVar5 * (iVar6 - iVar2)) * (g_flOne / fVar9)) &&

         ((fVar9 = (float)(iVar4 * iVar8 - iVar5 * iVar7) * (g_flOne / fVar9), 0.0 <= fVar9 &&

          (fVar9 <= g_flOne)))) {

        *param_9 = (float)((int)ROUND((float)(iVar3 - iVar1) * fVar9) + iVar1);

        param_9[1] = (float)((int)ROUND((float)(iVar6 - iVar2) * fVar9) + iVar2);

        return 1;

      }

    }

    local_10 = local_10 + 1;

    if (3 < local_10) {

      return 0;

    }

  } while( true );

}
