// =============================================================================
// Named_CalleeOf_Named_A_new_network_client_has_been_received_hos_006419a0
// -----------------------------------------------------------------------------
// Stable ID: aa_006419a0
// Callee of Named_A_new_network_client_has_been_received_host_name
// Address:   0x006419a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_A_new_network_client_has_been_received_hos: callee helper. Evidence string: "UNKNOWN". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "UNKNOWN"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00641900×3, FUN_00641680×2, FUN_00641860×2, FUN_00638060, FUN_006416b0, FUN_006418e0, FUN_006419a0, FUN_006560d0.
//  - Strings: "UNKNOWN".
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_A_new_network_client_has_been_received_hos_006419a0(void)



{

  uint uVar1;

  uint32_t /* width from decompiler */ unaff_ESI;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ uStack_4;

  

  local_2c = 0;

  local_28 = 0;

  local_24 = 0x80000000;

  FUN_006560f0(&local_2c);

  FUN_006416b0(0x90);

  FUN_00641900(DAT_00af4ff0);

  FUN_00641900(DAT_00af4fec);

  uVar1 = FUN_00638060("UNKNOWN");

  if (0xffff < (int)uVar1) {

    uVar1 = 0xffff;

  }

  FUN_006418e0(uVar1);

  FUN_00641860("UNKNOWN");

  FUN_006560d0(uStack_4);

  FUN_00641900(unaff_ESI);

  FUN_00641860(uVar1,unaff_ESI);

  FUN_00641680();

  FUN_00641680();

  if (-1 < (int)uVar1) {

    (**(code **)(*DAT_00b05060 + 0x14))(unaff_ESI,uVar1 & 0x7fffffff,0x12);

  }

  return 0;

}
