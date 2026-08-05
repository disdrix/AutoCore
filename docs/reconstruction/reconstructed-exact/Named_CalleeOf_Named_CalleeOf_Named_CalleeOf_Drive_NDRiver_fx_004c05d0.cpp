// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx_004c05d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c05d0
// Callee of Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx
// Address:   0x004c05d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_004c05d0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Drive_NDRiver_fx_004c05d0(int param_1,short *param_2)



{

  short sVar1;

  uint uVar2;

  

  uVar2 = 0;

  sVar1 = 0;

  if (*(int *)(param_1 + 0xbc) != 0) {

    do {

      *param_2 = sVar1;

      param_2[1] = sVar1 + 1;

      param_2[2] = sVar1 + 2;

      param_2[3] = sVar1 + 3;

      param_2[4] = sVar1 + 3;

      sVar1 = sVar1 + 4;

      param_2[5] = sVar1;

      uVar2 = uVar2 + 1;

      param_2 = param_2 + 6;

    } while (uVar2 < *(uint *)(param_1 + 0xbc));

  }

  return;

}
