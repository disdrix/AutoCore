// =============================================================================
// FUN_0078e8c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0078e8c0
// Address:   0x0078e8c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0078e8c0 @ 0x0078e8c0
// Stable ID: aa_0078e8c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0078e8c0.
//  - Return sites: 1.

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

void __thiscall FUN_0078e8c0(int *param_1,float param_2)



{

  int iVar1;

  float10 fVar2;

  

  iVar1 = *param_1;

  fVar2 = (float10)(**(code **)(iVar1 + 0x458))(1);

  (**(code **)(iVar1 + 0x454))((float)((float10)param_2 * (float10)(float)param_1[0x141] + fVar2));

  return;

}
