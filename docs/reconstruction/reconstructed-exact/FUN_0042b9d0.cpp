// =============================================================================
// FUN_0042b9d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0042b9d0
// Address:   0x0042b9d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042b9d0 @ 0x0042b9d0
// Stable ID: aa_0042b9d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×4, return×4.
//  - Notable callees: BitStream_readBits×2, FUN_0042b9d0.
//  - Return sites: 4.

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

uint FUN_0042b9d0(void)



{

  uint uVar1;

  char in_AL;

  byte bVar2;

  int unaff_ESI;

  uint local_4;

  

  uVar1 = *(uint *)(unaff_ESI + 0x18);

  if (*(uint *)(unaff_ESI + 0x2c) < uVar1) {

    *(uint8_t *)(unaff_ESI + 0x1c) = 1;

  }

  else {

    bVar2 = *(byte *)((uVar1 >> 3) + *(int *)(unaff_ESI + 0xc));

    *(uint *)(unaff_ESI + 0x18) = uVar1 + 1;

    if ((bVar2 & (byte)(1 << ((byte)uVar1 & 7))) != 0) {

      bVar2 = in_AL - 1;

      local_4 = 0;

      BitStream_readBits(bVar2,&local_4);

      if (bVar2 == 0x20) {

        return -local_4;

      }

      return -((1 << (bVar2 & 0x1f)) - 1U & local_4);

    }

  }

  bVar2 = in_AL - 1;

  local_4 = 0;

  BitStream_readBits(bVar2,&local_4);

  if (bVar2 == 0x20) {

    return local_4;

  }

  return (1 << (bVar2 & 0x1f)) - 1U & local_4;

}
