// =============================================================================
// Named_CalleeOf_Client_MaybeShowFirstTimeTip_0092f000
// -----------------------------------------------------------------------------
// Stable ID: aa_0092f000
// Callee of Client_MaybeShowFirstTimeTip
// Address:   0x0092f000  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_MaybeShowFirstTimeTip: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_007fc6c0, FUN_0092f000.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_MaybeShowFirstTimeTip
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

void Named_CalleeOf_Client_MaybeShowFirstTimeTip_0092f000(void)



{

  int in_EAX;

  

  if (*(int *)(in_EAX + 0x9b8) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x9b8) + 0x94))();

  }

  if (*(int *)(in_EAX + 0x1144) != 0) {

    (**(code **)(**(int **)(in_EAX + 0x1144) + 0x94))();

    if (*(char *)(in_EAX + 0x9da) != '\0') {

      FUN_007fc6c0(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x302c),*(uint32_t /* width from decompiler */ *)(in_EAX + 0x3030));

    }

  }

  if (*(int *)(in_EAX + 0x1168) != 0) {

                    /* WARNING: Could not recover jumptable at 0x0092f05f. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(**(int **)(in_EAX + 0x1168) + 0x94))();

    return;

  }

  return;

}
