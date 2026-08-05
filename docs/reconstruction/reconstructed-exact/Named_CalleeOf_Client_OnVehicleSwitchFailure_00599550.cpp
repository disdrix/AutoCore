// =============================================================================
// Named_CalleeOf_Client_OnVehicleSwitchFailure_00599550
// -----------------------------------------------------------------------------
// Stable ID: aa_00599550
// Callee of Client_OnVehicleSwitchFailure (+1 other named callers)
// Address:   0x00599550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_OnVehicleSwitchFailure: vehicle/entity helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_OnVehicleSwitchFailure (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~7 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00599550, FUN_00636bd0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_OnVehicleSwitchFailure (+1 other named callers)
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Client_OnVehicleSwitchFailure_00599550(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  FUN_00636bd0(param_2);

  *param_1 = &PTR_FUN_009d5590;

  param_1[0x10] = param_3;

  return param_1;

}
