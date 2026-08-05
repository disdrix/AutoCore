// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_004fbef0
// -----------------------------------------------------------------------------
// Stable ID: aa_004fbef0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa
// Address:   0x004fbef0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004fbef0, VehicleEntity_PushDriveAxesToController.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_004fbef0(int param_1,char param_2)



{

  if (param_2 != *(char *)(param_1 + 0x10a)) {

    *(char *)(param_1 + 0x10a) = param_2;

    *(char *)(param_1 + 0x109) = param_2;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x614) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x618) = 0;

    *(char *)(param_1 + 0x61c) = param_2;

    VehicleEntity_PushDriveAxesToController();

    *(uint8_t *)(param_1 + 0x101) = *(uint8_t *)(param_1 + 0x10a);

  }

  return;

}
