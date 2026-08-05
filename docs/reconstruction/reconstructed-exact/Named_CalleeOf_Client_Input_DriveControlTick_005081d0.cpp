// =============================================================================
// Named_CalleeOf_Client_Input_DriveControlTick_005081d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005081d0
// Callee of Client_Input_DriveControlTick (+2 other named callers)
// Address:   0x005081d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_Input_DriveControlTick: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_Input_DriveControlTick (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_005081d0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Client_Input_DriveControlTick (+2 other named callers)
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

void __fastcall Named_CalleeOf_Client_Input_DriveControlTick_005081d0(int *param_1)



{

  if (*(char *)((int)param_1 + 0x21) == '\0') {

    *(uint8_t *)((int)param_1 + 0x21) = 1;

                    /* WARNING: Could not recover jumptable at 0x005081dc. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (**(code **)(*param_1 + 0x10))();

    return;

  }

  return;

}
