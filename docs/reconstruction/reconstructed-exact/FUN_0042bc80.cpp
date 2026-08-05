// =============================================================================
// FUN_0042bc80
// -----------------------------------------------------------------------------
// Stable ID: aa_0042bc80
// Address:   0x0042bc80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042bc80 @ 0x0042bc80
// Stable ID: aa_0042bc80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: BitStream_writeBits, FUN_0042bc80, FUN_0077dcb0, FUN_0077f960, FUN_0077fb80, FUN_007837e0.
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

void FUN_0042bc80(int param_1)



{

  int in_EAX;

  int unaff_EBX;

  uint uVar1;

  uint8_t local_130 [32];

  uint8_t local_110 [272];

  

  uVar1 = *(int *)(in_EAX + 0x18) + 7U >> 3;

  *(uint *)(in_EAX + 0x18) = uVar1 * 8;

  FUN_0077dcb0(local_110);

  FUN_0077fb80(local_110,*(uint32_t /* width from decompiler */ *)(in_EAX + 0xc),uVar1);

  FUN_0077f960(local_110,local_130);

  BitStream_writeBits(param_1 * 8,local_130);

  FUN_007837e0((*(int *)(in_EAX + 0x18) + 7U >> 3) - unaff_EBX);

  return;

}
