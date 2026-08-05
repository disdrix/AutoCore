// =============================================================================
// FUN_0042b3f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0042b3f0
// Address:   0x0042b3f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042b3f0 @ 0x0042b3f0
// Stable ID: aa_0042b3f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: BitStream_readBits, FUN_0042b3f0.
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

uint __fastcall FUN_0042b3f0(int param_1)



{

  uint uVar1;

  int in_EAX;

  byte bVar2;

  uint local_4;

  

  param_1 = param_1 + in_EAX * 3;

  uVar1 = *(uint *)(&DAT_00d179a8 + param_1 * 4);

  local_4 = 0;

  BitStream_readBits(uVar1 & 0xff,&local_4);

  bVar2 = (byte)uVar1;

  if (bVar2 != 0x20) {

    local_4 = (1 << (bVar2 & 0x1f)) - 1U & local_4;

  }

  if ((uint)(&DAT_00d1ea08)[param_1 * 3] <= local_4) {

    local_4 = 0xffffffff;

  }

  return local_4;

}
