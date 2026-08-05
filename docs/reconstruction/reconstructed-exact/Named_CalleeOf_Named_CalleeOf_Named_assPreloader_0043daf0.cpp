// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_assPreloader_0043daf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0043daf0
// Callee of Named_CalleeOf_Named_assPreloader
// Address:   0x0043daf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_assPreloader: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×9, return×7, goto×1.
//  - Notable callees: FUN_00438140×6, FUN_004129f0, FUN_0043daf0, FUN_00458510, FUN_0046f100.
//  - Return sites: 7.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_assPreloader
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_assPreloader_0043daf0(int param_1,int *param_2)



{

  int *piVar1;

  uint *in_EAX;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *unaff_ESI;

  uint8_t local_8 [8];

  

  piVar1 = *(int **)(param_1 + 4);

  if (*(int *)(param_1 + 8) == 0) {

    FUN_00438140(unaff_ESI,1,piVar1,in_EAX);

    return;

  }

  if (param_2 == (int *)*piVar1) {

    if (*in_EAX < (uint)param_2[3]) {

LAB_0043db2b:

      FUN_00438140(unaff_ESI,1,param_2,in_EAX);

      return;

    }

  }

  else if (param_2 == piVar1) {

    if (*(uint *)(piVar1[2] + 0xc) < *in_EAX) {

      FUN_00438140(unaff_ESI,0,piVar1[2],in_EAX);

      return;

    }

  }

  else {

    if ((*in_EAX < (uint)param_2[3]) && (FUN_004129f0(), (uint)param_2[3] < *in_EAX)) {

      if (*(char *)(param_2[2] + 0x15) != '\0') {

        FUN_00438140(unaff_ESI,0,param_2,in_EAX);

        return;

      }

      goto LAB_0043db2b;

    }

    if (((uint)param_2[3] < *in_EAX) &&

       ((FUN_0046f100(), param_2 == *(int **)(param_1 + 4) || (*in_EAX < (uint)param_2[3])))) {

      if (*(char *)(param_2[2] + 0x15) == '\0') {

        FUN_00438140(unaff_ESI,1,param_2,in_EAX);

        return;

      }

      FUN_00438140(unaff_ESI,0,param_2,in_EAX);

      return;

    }

  }

  puVar2 = (uint32_t /* width from decompiler */ *)FUN_00458510(local_8);

  *unaff_ESI = *puVar2;

  return;

}
