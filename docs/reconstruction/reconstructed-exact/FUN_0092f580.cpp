// =============================================================================
// FUN_0092f580
// -----------------------------------------------------------------------------
// Stable ID: aa_0092f580
// Address:   0x0092f580  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092f580 @ 0x0092f580
// Stable ID: aa_0092f580
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0092f580.
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



void FUN_0092f580(void)



{

  int in_EAX;

  

  *(uint8_t *)(in_EAX + 0x3162) = 0xff;

  *(uint8_t *)(in_EAX + 0x3161) = 0xff;

  *(uint8_t *)(in_EAX + 0x3160) = 0xff;

  *(uint8_t *)(in_EAX + 0x3163) = 0xff;

  *(uint8_t *)(in_EAX + 0x3166) = 0xcc;

  *(uint8_t *)(in_EAX + 0x3167) = 0xff;

  *(uint8_t *)(in_EAX + 0x3165) = 0;

  *(uint8_t *)(in_EAX + 0x3164) = 0;

  *(uint8_t *)(in_EAX + 0x3169) = 0xff;

  *(uint8_t *)(in_EAX + 0x3168) = 0x99;

  *(uint8_t *)(in_EAX + 0x316b) = 0xff;

  *(uint8_t *)(in_EAX + 0x316a) = 0x33;

  *(uint8_t *)(in_EAX + 0x316f) = 0x33;

  *(uint8_t *)(in_EAX + 0x316e) = 0xff;

  *(uint8_t *)(in_EAX + 0x316d) = 0xff;

  *(uint8_t *)(in_EAX + 0x316c) = 0xff;

  *(uint8_t *)(in_EAX + 0x3171) = 0x33;

  *(uint8_t *)(in_EAX + 0x3172) = 0;

  *(uint8_t *)(in_EAX + 0x3170) = 0xcc;

  *(uint8_t *)(in_EAX + 0x3173) = 0xff;

  *(uint8_t *)(in_EAX + 0x3176) = 0xff;

  *(uint8_t *)(in_EAX + 0x3175) = 0xff;

  *(uint8_t *)(in_EAX + 0x3174) = 0xcc;

  *(uint8_t *)(in_EAX + 0x3177) = 0xff;

  *(uint8_t *)(in_EAX + 0x3178) = 0x33;

  *(uint8_t *)(in_EAX + 0x317a) = 0;

  *(uint8_t *)(in_EAX + 0x3179) = 0xcc;

  *(uint8_t *)(in_EAX + 0x317b) = 0xff;

  *(uint8_t *)(in_EAX + 0x3152) = 0;

  *(uint8_t *)(in_EAX + 0x3151) = 0;

  *(uint8_t *)(in_EAX + 0x3150) = 0;

  *(uint8_t *)(in_EAX + 0x3153) = 0;

  *(uint8_t *)(in_EAX + 0x3156) = 0;

  *(uint8_t *)(in_EAX + 0x3155) = 0;

  *(uint8_t *)(in_EAX + 0x3154) = 0x66;

  *(uint8_t *)(in_EAX + 0x3157) = 0xff;

  *(uint8_t *)(in_EAX + 0x315a) = 0;

  *(uint8_t *)(in_EAX + 0x3159) = 0x66;

  *(uint8_t *)(in_EAX + 0x3158) = 0x99;

  *(uint8_t *)(in_EAX + 0x315b) = 0x99;

  *(uint8_t *)(in_EAX + 0x315e) = 0x33;

  *(uint8_t *)(in_EAX + 0x315d) = 0x33;

  *(uint8_t *)(in_EAX + 0x315c) = 0x33;

  *(uint8_t *)(in_EAX + 0x315f) = 0x99;

  _DAT_00afdabc = DAT_00afdef0;

  DAT_00afdaca = 0x33;

  DAT_00afdac9 = 0x33;

  DAT_00afdac8 = 0x33;

  DAT_00afdaba = 0xf;

  DAT_00afdab9 = 0xf;

  DAT_00afdab8 = 0xf;

  DAT_00afdabb = 0xff;

  DAT_00afdac2 = 0xf;

  DAT_00afdac1 = 0xf;

  DAT_00afdac0 = 0xf;

  DAT_00afdac3 = 0x66;

  DAT_00afdac6 = 0;

  DAT_00afdac5 = 0;

  DAT_00afdac4 = 0;

  DAT_00afdac7 = 0x66;

  DAT_00afdacb = 0xff;

  return;

}
