// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0083edf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0083edf0
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x0083edf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×1, for×1, return×1.
//  - Notable callees: FUN_0083edf0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0083edf0(void)



{

  int in_EAX;

  int iVar1;

  int *unaff_EBX;

  int *piVar2;

  int *piVar3;

  

  unaff_EBX[0x145] = in_EAX;

  if (in_EAX == 0) {

    *(uint8_t *)(unaff_EBX + 0x13f) = 0;

  }

  else {

    piVar2 = (int *)(in_EAX + 0x24);

    piVar3 = unaff_EBX + 0x146;

    for (iVar1 = 0x18c; iVar1 != 0; iVar1 = iVar1 + -1) {

      *piVar3 = *piVar2;

      piVar2 = piVar2 + 1;

      piVar3 = piVar3 + 1;

    }

    *(uint8_t *)(unaff_EBX + 0x13f) = 1;

  }

  (**(code **)(*unaff_EBX + 0x444))();

                    /* WARNING: Could not recover jumptable at 0x0083ee2c. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*unaff_EBX + 0x34c))();

  return;

}
