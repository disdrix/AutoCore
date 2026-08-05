// =============================================================================
// FUN_00653d20
// -----------------------------------------------------------------------------
// Stable ID: aa_00653d20
// Address:   0x00653d20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00653d20 @ 0x00653d20
// Stable ID: aa_00653d20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00653d20.
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

void __thiscall FUN_00653d20(int param_1,int param_2)



{

  float *pfVar1;

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  

  pfVar1 = *(float **)(param_2 + 0x14);

  local_20 = *pfVar1 + pfVar1[4];

  local_1c = pfVar1[1] + pfVar1[5];

  local_18 = pfVar1[2] + pfVar1[6];

  local_14 = pfVar1[3] + pfVar1[7];

  (**(code **)(**(int **)(param_1 + -4) + 0x1c))

            (*(uint32_t /* width from decompiler */ *)(param_2 + 0x14),&local_20,0xffff0000,DAT_00d03508);

  return;

}
