// =============================================================================
// Named_CalleeOf_Named_A_new_network_client_has_been_received_hos_0063fd00
// -----------------------------------------------------------------------------
// Stable ID: aa_0063fd00
// Callee of Named_A_new_network_client_has_been_received_host_name
// Address:   0x0063fd00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_A_new_network_client_has_been_received_hos: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0063fd00, FUN_00652b30.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_A_new_network_client_has_been_received_host_name
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_A_new_network_client_has_been_received_hos_0063fd00(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2)



{

  short *psVar1;

  

  *(uint16_t *)((int)param_1 + 6) = 1;

  *param_1 = &PTR_FUN_009e3fc4;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = 0x80000000;

  param_1[6] = param_2;

  FUN_00652b30();

  param_1[10] = 0;

  param_1[0xb] = 0;

  param_1[0xc] = 0x80000000;

  param_1[0xd] = 0;

  param_1[0xe] = 0;

  param_1[0xf] = 0x80000000;

  if (param_1[6] != 0) {

    psVar1 = (short *)(param_1[6] + 6);

    *psVar1 = *psVar1 + 1;

  }

  return param_1;

}
