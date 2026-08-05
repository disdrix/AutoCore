// =============================================================================
// Named_CalleeOf_Named_netTcpConnection_00681a90
// -----------------------------------------------------------------------------
// Stable ID: aa_00681a90
// Callee of Named_netTcpConnection
// Address:   0x00681a90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_netTcpConnection: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00681a90.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_netTcpConnection
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

void __thiscall Named_CalleeOf_Named_netTcpConnection_00681a90(int param_1,uint param_2)



{

  void *pvVar1;

  

  if ((*(uint *)(param_1 + 0x38) < param_2) && (param_2 != 0)) {

    if (*(void **)(param_1 + 0x34) != (void *)0x0) {

      operator_delete__(*(void **)(param_1 + 0x34));

    }

    pvVar1 = operator_new__(param_2);

    *(void **)(param_1 + 0x34) = pvVar1;

    *(uint *)(param_1 + 0x38) = param_2;

  }

  return;

}
