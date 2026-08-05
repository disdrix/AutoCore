// =============================================================================
// FUN_0042b7d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0042b7d0
// Address:   0x0042b7d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042b7d0 @ 0x0042b7d0
// Stable ID: aa_0042b7d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: BitStream_writeBits×2, FUN_0042b7d0.
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

uint FUN_0042b7d0(void)



{

  uint in_EAX;

  uint uVar1;

  int unaff_EBX;

  uint local_4;

  

  uVar1 = *(uint *)(unaff_EBX + 0x10);

  if (0x3ff < uVar1) {

    return in_EAX & 0xffffff00;

  }

  local_4 = uVar1;

  BitStream_writeBits(10,&local_4);

  uVar1 = BitStream_writeBits(uVar1 * 8,*(uint32_t /* width from decompiler */ *)(unaff_EBX + 0xc));

  return uVar1;

}
