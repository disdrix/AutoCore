// =============================================================================
// FUN_004c56a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c56a0
// Address:   0x004c56a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c56a0 @ 0x004c56a0
// Stable ID: aa_004c56a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004c4e20, FUN_004c56a0.
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

float10 __fastcall FUN_004c56a0(int param_1)



{

  uint uVar1;

  float fVar2;

  float10 fVar3;

  float local_4;

  

  uVar1 = *(uint *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb8 + param_1);

  local_4 = *(float *)(param_1 + 0x1f8);

  fVar2 = DAT_00a0f71c;

  if (((uVar1 & 0x1000) != 0) || (fVar2 = DAT_00aaab3c, (uVar1 & 0x4000) != 0)) {

    local_4 = local_4 * fVar2;

  }

  fVar3 = (float10)FUN_004c4e20();

  return (fVar3 * (float10)DAT_00a0f298 + (float10)g_flOne) * (float10)local_4;

}
