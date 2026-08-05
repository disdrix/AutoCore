// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_effDeviceEff_00448340
// -----------------------------------------------------------------------------
// Stable ID: aa_00448340
// Callee of Named_CalleeOf_Named_CalleeOf_Named_effDeviceEffect
// Address:   0x00448340  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_effDeviceEffect: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: while×1, if×1, return×1.
//  - Notable callees: FUN_00447660, FUN_00447a30, FUN_00448340.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_effDeviceEffect
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

int __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_effDeviceEff_00448340(int param_1)



{

  int iVar1;

  int in_EAX;

  int unaff_ESI;

  int local_4;

  

  local_4 = param_1;

  while (iVar1 = in_EAX, unaff_ESI != param_1) {

    param_1 = param_1 + -0xc;

    in_EAX = iVar1 + -0xc;

    if (in_EAX != param_1) {

      FUN_00447660(&local_4,**(uint32_t /* width from decompiler */ **)(iVar1 + -8),*(uint32_t /* width from decompiler */ **)(iVar1 + -8));

      FUN_00447a30();

    }

  }

  return iVar1;

}
