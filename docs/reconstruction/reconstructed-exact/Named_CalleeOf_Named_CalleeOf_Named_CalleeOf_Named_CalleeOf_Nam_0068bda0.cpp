// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068bda0
// -----------------------------------------------------------------------------
// Stable ID: aa_0068bda0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0068bda0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_0068bda0.
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

float * __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068bda0(int param_1,float *param_2)



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

  uint uVar13;

  uint uVar14;

  float *pfVar15;

  int iVar16;

  

  if (*(int *)(param_1 + 100) == 0) {

    uVar13 = 0;

  }

  else {

    uVar13 = *(int *)(param_1 + 0x68) - *(int *)(param_1 + 100) >> 2;

  }

  uVar14 = uVar13 / 3 & 0xffff;

  pfVar15 = (float *)(uVar13 * -0x55555555);

  if (uVar14 != 0) {

    iVar16 = 0;

    do {

      fVar1 = *(float *)(*(int *)(param_1 + 100) + iVar16);

      pfVar15 = (float *)(*(int *)(param_1 + 100) + iVar16);

      fVar2 = pfVar15[1];

      fVar3 = pfVar15[2];

      fVar4 = param_2[1];

      fVar5 = param_2[9];

      fVar6 = param_2[5];

      fVar7 = param_2[0xd];

      fVar8 = param_2[2];

      fVar9 = param_2[10];

      fVar10 = param_2[6];

      fVar11 = param_2[0xe];

      *pfVar15 = fVar1 * *param_2 + fVar2 * param_2[4] + fVar3 * param_2[8] + param_2[0xc];

      pfVar15[1] = fVar2 * fVar6 + fVar3 * fVar5 + fVar1 * fVar4 + fVar7;

      pfVar15[2] = fVar2 * fVar10 + fVar3 * fVar9 + fVar1 * fVar8 + fVar11;

      if (((*(char *)(param_1 + 8) != '\0') && (iVar12 = *(int *)(param_1 + 0x74), iVar12 != 0)) &&

         (*(int *)(param_1 + 0x78) - iVar12 >> 2 != 0)) {

        fVar1 = *(float *)(iVar12 + iVar16);

        pfVar15 = (float *)(iVar12 + iVar16);

        fVar2 = pfVar15[1];

        fVar3 = pfVar15[2];

        fVar4 = param_2[1];

        fVar5 = param_2[9];

        fVar6 = param_2[5];

        fVar7 = param_2[0xd];

        fVar8 = param_2[2];

        fVar9 = param_2[10];

        fVar10 = param_2[6];

        fVar11 = param_2[0xe];

        *pfVar15 = fVar1 * *param_2 + fVar2 * param_2[4] + fVar3 * param_2[8] + param_2[0xc];

        pfVar15[1] = fVar2 * fVar6 + fVar3 * fVar5 + fVar1 * fVar4 + fVar7;

        pfVar15[2] = fVar2 * fVar10 + fVar3 * fVar9 + fVar1 * fVar8 + fVar11;

      }

      iVar16 = iVar16 + 0xc;

      uVar14 = uVar14 - 1;

      pfVar15 = param_2;

    } while (uVar14 != 0);

  }

  return pfVar15;

}
