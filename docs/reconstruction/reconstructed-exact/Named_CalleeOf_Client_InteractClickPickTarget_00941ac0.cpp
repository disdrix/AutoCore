// =============================================================================
// Named_CalleeOf_Client_InteractClickPickTarget_00941ac0
// -----------------------------------------------------------------------------
// Stable ID: aa_00941ac0
// Callee of Client_InteractClickPickTarget
// Address:   0x00941ac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_InteractClickPickTarget: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0093b7f0, FUN_0093bac0, FUN_00941ac0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_InteractClickPickTarget
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

void Named_CalleeOf_Client_InteractClickPickTarget_00941ac0(void *param_1)



{

  char cVar1;

  int *unaff_ESI;

  int unaff_EDI;

  

  cVar1 = FUN_0093b7f0();

  if (cVar1 == '\0') {

    Client_RequestCastSkill

              (*(int *)(unaff_EDI + 0x30c0),*unaff_ESI,unaff_ESI[1],unaff_ESI[2],unaff_ESI[3],

               param_1);

  }

  FUN_0093bac0(unaff_EDI,0);

  return;

}
