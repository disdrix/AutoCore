// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_Input_DriveControlTick_0040ce50
// -----------------------------------------------------------------------------
// Stable ID: aa_0040ce50
// Callee of Named_CalleeOf_Client_Input_DriveControlTick
// Address:   0x0040ce50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_Input_DriveControlTick: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0040ce50.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_Input_DriveControlTick
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_CalleeOf_Client_Input_DriveControlTick_0040ce50(int param_1)



{

  if (*(int *)(param_1 + 0x270) != 0) {

    return *(uint32_t /* width from decompiler */ *)

            (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x270) + 4) + 4) + 0xac +

                              *(int *)(param_1 + 0x270)) + 0x3c) + 0x3bc);

  }

  return 0xffffffff;

}
