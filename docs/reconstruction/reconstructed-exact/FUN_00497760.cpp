// =============================================================================
// FUN_00497760
// -----------------------------------------------------------------------------
// Stable ID: aa_00497760
// Address:   0x00497760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00497760 @ 0x00497760
// Stable ID: aa_00497760
// Embedded strings (evidence for future rename):
//   - "../maps/"
//   - "_den.pgm"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00793a10×2, FUN_00497760, FUN_00787730, FUN_00793aa0, FUN_00793f30.
//  - Strings: "../maps/"; "_den.pgm".
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

uint __thiscall FUN_00497760(char *param_1,uint32_t /* width from decompiler */ param_2)



{

  uint in_EAX;

  uint uVar1;

  uint8_t local_800 [1024];

  uint8_t local_400 [1024];

  

  if (*param_1 != '\0') {

    return in_EAX & 0xffffff00;

  }

  FUN_00793f30(local_400,local_800,param_2,&DAT_00a285c4,0x400);

  FUN_00793aa0(local_800,"../maps/",0x400);

  FUN_00793a10(local_800,local_800,local_400,0x400);

  FUN_00793a10(local_800,local_800,"_den.pgm",0x400);

  uVar1 = FUN_00787730(local_800);

  return uVar1 | 1;

}
