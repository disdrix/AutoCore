// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004a94e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004a94e0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x004a94e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×5, return×4.
//  - Notable callees: block×11, FUN_007a4480×2, ROUND×2, FUN_004a94e0, FUN_005be7a0.
//  - Return sites: 4.

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

/* WARNING: Removing unreachable block (ram,0x004a9714) */

/* WARNING: Removing unreachable block (ram,0x004a95f3) */

/* WARNING: Removing unreachable block (ram,0x004a9683) */

/* WARNING: Removing unreachable block (ram,0x004a96ba) */

/* WARNING: Removing unreachable block (ram,0x004a96c3) */

/* WARNING: Removing unreachable block (ram,0x004a96f0) */

/* WARNING: Removing unreachable block (ram,0x004a96fe) */

/* WARNING: Removing unreachable block (ram,0x004a9630) */

/* WARNING: Removing unreachable block (ram,0x004a963a) */

/* WARNING: Removing unreachable block (ram,0x004a9643) */

/* WARNING: Removing unreachable block (ram,0x004a972b) */



uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004a94e0(int *param_1,int *param_2)



{

  int unaff_EDI;

  

  if (param_2 == (int *)0x0) {

    return 0xffffffff;

  }

  (**(code **)(*param_2 + 0x14))();

  *param_1 = unaff_EDI;

  if (unaff_EDI != 0x3e) {

    if (unaff_EDI < 4) {

      FUN_007a4480();

      return 0xffffffff;

    }

    if (0x3e < unaff_EDI) {

      FUN_007a4480();

      return 0xffffffff;

    }

  }

  if (0x1a < unaff_EDI) {

    (**(code **)(*param_2 + 0x14))();

  }

  (**(code **)(*param_2 + 0x14))();

  (**(code **)(*param_2 + 0x14))();

  (**(code **)(*param_2 + 0x14))();

  FUN_005be7a0((int)ROUND(DAT_00aaa688 / (float)param_1[6]) *

               (int)ROUND(DAT_00aaa688 / (float)param_1[6]) * 100);

  (**(code **)(*param_2 + 0x14))(param_1 + 7,1);

  (**(code **)(*param_2 + 0x14))((int)param_1 + 0x1d);

  (**(code **)(*param_2 + 0x14))((int)param_1 + 0x32e,6);

  return 1;

}
