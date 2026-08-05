// =============================================================================
// FUN_004f4800
// -----------------------------------------------------------------------------
// Stable ID: aa_004f4800
// Address:   0x004f4800  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004f4800 @ 0x004f4800
// Stable ID: aa_004f4800
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_004f4800.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall FUN_004f4800(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  if ((char)param_1[0x9b] != '\0') {

    (**(code **)(*param_1 + 0x18))(param_2);

    return;

  }

  if ((int *)param_1[0x86] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0x86] + 0x18))(param_2);

  }

  if ((int *)param_1[0x8b] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0x8b] + 0x18))(param_2);

  }

  (**(code **)(*(int *)(*(int *)(param_1[-0xf] + 4) + -0x3c + (int)param_1) + 0x104))(param_2);

  (**(code **)(*param_1 + 0x18))(param_2);

  return;

}
