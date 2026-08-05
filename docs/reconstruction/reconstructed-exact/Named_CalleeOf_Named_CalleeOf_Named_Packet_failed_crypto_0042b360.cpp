// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Packet_failed_crypto_0042b360
// -----------------------------------------------------------------------------
// Stable ID: aa_0042b360
// Callee of Named_CalleeOf_Named_Packet_failed_crypto
// Address:   0x0042b360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Packet_failed_crypto: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0042b360, realloc.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Packet_failed_crypto
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_Packet_failed_crypto_0042b360(int param_1,uint param_2)



{

  void *pvVar1;

  

  if (*(uint *)(param_1 + 0x10) < param_2) {

    if (*(char *)(param_1 + 0x14) != '\0') {

      *(uint *)(param_1 + 0x10) = param_2;

      pvVar1 = realloc(*(void **)(param_1 + 0xc),param_2);

      *(void **)(param_1 + 0xc) = pvVar1;

      return 1;

    }

  }

  else {

    *(uint *)(param_1 + 0x10) = param_2;

  }

  return 0;

}
