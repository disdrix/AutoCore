// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004c4cf0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c4cf0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
// Address:   0x004c4cf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×7, return×2, while×1, goto×1.
//  - Notable callees: FUN_004c4cf0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli
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

float10 __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004c4cf0(int param_1,short *param_2)



{

  short *psVar1;

  int iVar2;

  

  psVar1 = param_2;

  if (param_2 == (short *)0x0) {

    return (float10)g_flZero;

  }

  param_2 = (short *)0x0;

  iVar2 = 0;

  while ((iVar2 == 2 || (psVar1[iVar2] < 1))) {

    iVar2 = iVar2 + 1;

    if (5 < iVar2) {

LAB_004c4d35:

      if ((0 < *psVar1) && ((float)param_2 < *(float *)(param_1 + 0x164))) {

        param_2 = (short *)*(float *)(param_1 + 0x164);

      }

      if ((0 < psVar1[1]) && ((float)param_2 < *(float *)(param_1 + 0x168))) {

        param_2 = (short *)*(float *)(param_1 + 0x168);

      }

      if ((0 < psVar1[3]) && ((float)param_2 < *(float *)(param_1 + 0x170))) {

        param_2 = (short *)*(float *)(param_1 + 0x170);

      }

      if ((0 < psVar1[4]) && ((float)param_2 < *(float *)(param_1 + 0x174))) {

        param_2 = (short *)*(float *)(param_1 + 0x174);

      }

      if ((0 < psVar1[5]) && ((float)param_2 < *(float *)(param_1 + 0x178))) {

        param_2 = (short *)*(float *)(param_1 + 0x178);

      }

      return (float10)(float)param_2;

    }

  }

  param_2 = *(short **)(param_1 + 0x164 + iVar2 * 4);

  goto LAB_004c4d35;

}
