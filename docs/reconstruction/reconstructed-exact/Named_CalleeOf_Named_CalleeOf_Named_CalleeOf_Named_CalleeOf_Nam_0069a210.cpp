// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0069a210
// -----------------------------------------------------------------------------
// Stable ID: aa_0069a210
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x0069a210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_0069a210.
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0069a210(int param_1,int *param_2,float param_3)



{

  int iVar1;

  float *pfVar2;

  

  if ((*(int *)(param_1 + 0x18) != 0) && (1 < *(int *)(param_1 + 0x1c))) {

    *param_2 = 0;

    iVar1 = 1;

    if (1 < *(int *)(param_1 + 0x1c)) {

      pfVar2 = (float *)(*(int *)(param_1 + 0x18) + 0x88);

      do {

        if (param_3 < *pfVar2) {

          *param_2 = iVar1 + -1;

          break;

        }

        iVar1 = iVar1 + 1;

        pfVar2 = pfVar2 + 0x12;

      } while (iVar1 < *(int *)(param_1 + 0x1c));

    }

    iVar1 = *(int *)(param_1 + 0x18) + *param_2 * 0x48;

    param_2[1] = (int)((param_3 - *(float *)(*(int *)(param_1 + 0x18) + 0x40 + *param_2 * 0x48)) /

                      (*(float *)(iVar1 + 0x88) - *(float *)(iVar1 + 0x40)));

  }

  return;

}
