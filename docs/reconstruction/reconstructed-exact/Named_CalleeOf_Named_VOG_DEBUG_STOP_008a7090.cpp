// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_008a7090
// -----------------------------------------------------------------------------
// Stable ID: aa_008a7090
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x008a7090  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_008a7090.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

void __fastcall Named_CalleeOf_Named_VOG_DEBUG_STOP_008a7090(uint32_t /* width from decompiler */ param_1,char param_2)



{

  int *piVar1;

  int in_EAX;

  

  piVar1 = *(int **)(in_EAX + 0x530);

  *(char *)(in_EAX + 0x4fc) = param_2;

  if (piVar1 != (int *)0x0) {

    if (param_2 != '\0') {

      (**(code **)(*piVar1 + 0xcc))(1);

      return;

    }

    (**(code **)(*piVar1 + 0xcc))(0);

  }

  return;

}
