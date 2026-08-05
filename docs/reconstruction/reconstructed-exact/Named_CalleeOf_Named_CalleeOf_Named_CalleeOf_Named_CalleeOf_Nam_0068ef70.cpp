// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068ef70
// -----------------------------------------------------------------------------
// Stable ID: aa_0068ef70
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0068ef70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_00685e60, FUN_0068ef70.
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0068ef70(int param_1,ushort param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float *pfVar6;

  float *pfVar7;

  int iVar8;

  int iVar9;

  float *pfVar10;

  int iVar11;

  uint8_t local_c [12];

  

  if (((((*(int *)(param_1 + 4) != 0) && (param_2 < *(ushort *)(param_1 + 0x28))) &&

       (*(char *)(param_1 + 1) != '\0')) &&

      ((*(int *)(param_1 + 0x2c) != 0 &&

       (iVar11 = (uint)param_2 * 0x44 + *(int *)(param_1 + 0x2c), iVar11 != 0)))) &&

     ((*(int *)(iVar11 + 0x40) != 0 &&

      ((*(int *)(iVar11 + 0x18) != 0 && (iVar8 = 0, *(short *)(iVar11 + 0xc) != 0)))))) {

    iVar9 = 0;

    do {

      fVar1 = *(float *)(*(int *)(iVar11 + 0x34) + iVar8 * 4);

      pfVar10 = (float *)(*(int *)(iVar11 + 0x40) + iVar9);

      pfVar6 = (float *)FUN_00685e60(local_c,(uint)*(byte *)(iVar8 + *(int *)(iVar11 + 0x38)) * 0x40

                                             + DAT_00d08eac);

      fVar2 = pfVar10[2];

      fVar4 = pfVar6[1];

      fVar3 = pfVar10[1];

      fVar5 = pfVar6[2];

      pfVar7 = (float *)(*(int *)(iVar11 + 0x18) + iVar9);

      iVar8 = iVar8 + 1;

      iVar9 = iVar9 + 0xc;

      *pfVar7 = (*pfVar6 - *pfVar10) * fVar1 + *pfVar10;

      pfVar7[1] = (fVar4 - fVar3) * fVar1 + fVar3;

      pfVar7[2] = (fVar5 - fVar2) * fVar1 + fVar2;

    } while (iVar8 < (int)(uint)*(ushort *)(iVar11 + 0xc));

  }

  return;

}
