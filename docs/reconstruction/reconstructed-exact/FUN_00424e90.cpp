// =============================================================================
// FUN_00424e90
// -----------------------------------------------------------------------------
// Stable ID: aa_00424e90
// Address:   0x00424e90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00424e90 @ 0x00424e90
// Stable ID: aa_00424e90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: BitStream_writeBits, FUN_00424e90.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall FUN_00424e90(int param_1,int param_2)



{

  int in_EAX;

  uint uVar1;

  int local_8;

  float local_4;

  

  uVar1 = (in_EAX - param_2) + 1;

  local_4 = (float)(int)uVar1;

  if ((int)uVar1 < 0) {

    local_4 = local_4 + _DAT_00aaa5dc;

  }

  local_8 = param_1 - param_2;

  BitStream_writeBits(((uVar1 & in_EAX - param_2) != 0) + (char)((uint)local_4 >> 0x17) + -0x7f,

                      &local_8);

  return;

}
