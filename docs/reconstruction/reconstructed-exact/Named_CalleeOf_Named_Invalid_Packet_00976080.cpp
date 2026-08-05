// =============================================================================
// Named_CalleeOf_Named_Invalid_Packet_00976080
// -----------------------------------------------------------------------------
// Stable ID: aa_00976080
// Callee of Named_Invalid_Packet (+1 other named callers)
// Address:   0x00976080  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Invalid_Packet: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_Invalid_Packet (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0077bad0, FUN_0077bb70, FUN_0077bc40, FUN_00976080.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Invalid_Packet (+1 other named callers)
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

uint Named_CalleeOf_Named_Invalid_Packet_00976080(void)



{

  uint local_4;

  

  if (DAT_00d179d9 == '\0') {

    DAT_00d179d9 = '\x01';

    FUN_0077bc40(&DAT_00d0a3b8);

    FUN_0077bb70(&DAT_00d0a3b8);

  }

  FUN_0077bad0(&local_4,4,&DAT_00d0a3b8);

  return (((local_4 & 0xff) << 8 | local_4 >> 8 & 0xff) << 8 | local_4 >> 0x10 & 0xff) << 8 |

         local_4 >> 0x18;

}
