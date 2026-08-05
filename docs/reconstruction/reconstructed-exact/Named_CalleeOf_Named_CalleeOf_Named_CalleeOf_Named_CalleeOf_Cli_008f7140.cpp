// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_008f7140
// -----------------------------------------------------------------------------
// Stable ID: aa_008f7140
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_OnBadCharac
// Address:   0x008f7140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_OnBadCharac: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_008f6990, FUN_008f7140.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_OnBadCharac
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_008f7140(void)



{

  int in_EAX;

  int iVar1;

  uint8_t local_8 [8];

  

  if (*(int *)(in_EAX + 0x534) != 0) {

    if (DAT_00af9214 == -1) {

      iVar1 = (**(code **)(**(int **)(in_EAX + 0x534) + 0x124))(local_8);

      DAT_00af9214 = (int)*(float *)(iVar1 + 4);

    }

    FUN_008f6990();

  }

  return;

}
