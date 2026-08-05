// =============================================================================
// FUN_004250a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004250a0
// Address:   0x004250a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004250a0 @ 0x004250a0
// Stable ID: aa_004250a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~82 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_004250a0, FUN_004260b0, FUN_0077bad0, FUN_0077bb70, FUN_0077bc40, FUN_00976080, htonl.
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

void FUN_004250a0(void)



{

  u_long uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ *unaff_ESI;

  bool bVar3;

  

  *unaff_ESI = &PTR_LAB_00a978a4;

  unaff_ESI[1] = 0;

  unaff_ESI[2] = 0;

  unaff_ESI[0x2d] = 0;

  *(uint16_t *)(unaff_ESI + 0x3e) = 0;

  *(uint16_t *)((int)unaff_ESI + 0xfa) = 0;

  unaff_ESI[0x42] = 0;

  unaff_ESI[0x41] = 0;

  unaff_ESI[0x40] = 0;

  uVar1 = htonl(0);

  unaff_ESI[0x3f] = uVar1;

  unaff_ESI[0x4a] = 0;

  unaff_ESI[0x55] = 0;

  unaff_ESI[0x56] = 0;

  unaff_ESI[0x57] = 0;

  unaff_ESI[0x58] = 0;

  unaff_ESI[100] = 0;

  unaff_ESI[0x62] = 0;

  unaff_ESI[99] = 0;

  unaff_ESI[0x66] = 0;

  *(uint8_t *)(unaff_ESI + 0x65) = 0;

  *(uint8_t *)((int)unaff_ESI + 0x137) = 0;

  *(uint8_t *)((int)unaff_ESI + 0x135) = 0;

  *(uint8_t *)((int)unaff_ESI + 0x136) = 0;

  *(uint8_t *)(unaff_ESI + 0x4d) = 0;

  *(uint8_t *)(unaff_ESI + 0x67) = 0;

  *(uint8_t *)((int)unaff_ESI + 0x195) = 0;

  unaff_ESI[0x6a] = 0;

  unaff_ESI[0x6d] = 0;

  uVar2 = FUN_00976080();

  bVar3 = DAT_00d179d9 == '\0';

  unaff_ESI[0x28] = uVar2;

  if (bVar3) {

    DAT_00d179d9 = '\x01';

    FUN_0077bc40(&DAT_00d0a3b8);

    FUN_0077bb70(&DAT_00d0a3b8);

  }

  FUN_0077bad0(unaff_ESI + 0x4e,8,&DAT_00d0a3b8);

  unaff_ESI[0x36] = 0x9c4;

  unaff_ESI[0x35] = 0x9c4;

  unaff_ESI[0x34] = 0x60;

  unaff_ESI[0x33] = 0x60;

  unaff_ESI[0x37] = unaff_ESI[0x33];

  unaff_ESI[0x38] = unaff_ESI[0x34];

  unaff_ESI[0x39] = unaff_ESI[0x35];

  unaff_ESI[0x3a] = unaff_ESI[0x36];

  unaff_ESI[0x69] = 0;

  unaff_ESI[0x43] = 0;

  unaff_ESI[0x47] = 0;

  unaff_ESI[0x31] = 0;

  unaff_ESI[0x32] = 0;

  unaff_ESI[0x46] = 0;

  unaff_ESI[0x2e] = 0;

  unaff_ESI[0x2f] = 0;

  unaff_ESI[0x30] = 0;

  unaff_ESI[0x6e] = 0;

  unaff_ESI[0x48] = 0;

  unaff_ESI[0x49] = 0;

  *(uint8_t *)(unaff_ESI + 0x3b) = 1;

  FUN_004260b0();

  unaff_ESI[0x6f] = g_flLevelUpUiBase_Inferred;

  uVar2 = DAT_00a0f694;

  unaff_ESI[0x44] = 0;

  unaff_ESI[0x45] = 0;

  unaff_ESI[0x23] = 0;

  unaff_ESI[0x24] = unaff_ESI[0x28];

  unaff_ESI[0x25] = unaff_ESI[0x28];

  unaff_ESI[0x26] = 0;

  unaff_ESI[0x27] = 0;

  unaff_ESI[0x71] = 0;

  unaff_ESI[0x73] = 0;

  unaff_ESI[0x70] = uVar2;

  unaff_ESI[0x2b] = 5000;

  unaff_ESI[0x2c] = 10;

  return;

}
