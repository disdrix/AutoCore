// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00688580
// -----------------------------------------------------------------------------
// Stable ID: aa_00688580
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x00688580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_00688580.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00688580(int param_1,float *param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  int iVar12;

  int *piVar13;

  

  piVar13 = *(int **)(param_1 + 4);

  if (piVar13 != *(int **)(param_1 + 8)) {

    do {

      fVar1 = (float)piVar13[1];

      fVar2 = (float)piVar13[2];

      fVar3 = (float)piVar13[3];

      fVar4 = param_2[1];

      fVar5 = param_2[9];

      fVar6 = param_2[5];

      fVar7 = param_2[0xd];

      fVar8 = param_2[10];

      fVar9 = param_2[6];

      fVar10 = param_2[2];

      fVar11 = param_2[0xe];

      piVar13[1] = (int)(fVar2 * param_2[4] + fVar3 * param_2[8] + fVar1 * *param_2 + param_2[0xc]);

      piVar13[2] = (int)(fVar2 * fVar6 + fVar3 * fVar5 + fVar1 * fVar4 + fVar7);

      piVar13[3] = (int)(fVar1 * fVar10 + fVar2 * fVar9 + fVar3 * fVar8 + fVar11);

      iVar12 = *piVar13;

      if (iVar12 == 0) {

        piVar13[4] = (int)(*param_2 * (float)piVar13[4]);

      }

      else if (iVar12 == 1) {

        piVar13[4] = (int)(*param_2 * (float)piVar13[4]);

        piVar13[5] = (int)(*param_2 * (float)piVar13[5]);

      }

      else if (iVar12 == 2) {

        piVar13[4] = (int)(*param_2 * (float)piVar13[4]);

        piVar13[5] = (int)(param_2[5] * (float)piVar13[5]);

        piVar13[6] = (int)(param_2[10] * (float)piVar13[6]);

      }

      piVar13 = piVar13 + 7;

    } while (piVar13 != *(int **)(param_1 + 8));

  }

  return;

}
