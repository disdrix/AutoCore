// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_effDeviceEff_00447d90
// -----------------------------------------------------------------------------
// Stable ID: aa_00447d90
// Callee of Named_CalleeOf_Named_CalleeOf_Named_effDeviceEffect
// Address:   0x00447d90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_effDeviceEffect: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: for×1, if×1, return×1.
//  - Notable callees: FUN_00447660, FUN_00447a30, FUN_00447d90.
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_effDeviceEff_00447d90(int param_1)



{

  int in_EAX;

  int unaff_ESI;

  int local_4;

  

  local_4 = param_1;

  for (; param_1 != unaff_ESI; param_1 = param_1 + 0xc) {

    if (param_1 != in_EAX) {

      FUN_00447660(&local_4,**(uint32_t /* width from decompiler */ **)(param_1 + 4),*(uint32_t /* width from decompiler */ **)(param_1 + 4));

      FUN_00447a30();

    }

  }

  return;

}
