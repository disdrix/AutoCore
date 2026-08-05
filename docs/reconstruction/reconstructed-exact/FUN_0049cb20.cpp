// =============================================================================
// FUN_0049cb20
// -----------------------------------------------------------------------------
// Stable ID: aa_0049cb20
// Address:   0x0049cb20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0049cb20 @ 0x0049cb20
// Stable ID: aa_0049cb20
// Embedded strings (evidence for future rename):
//   - "%d%s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: return×5, switch×1.
//  - Notable callees: FUN_0049cb20, swscanf.
//  - Strings: "%d%s".
//  - Return sites: 5.

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

int FUN_0049cb20(wchar_t *param_1)



{

  int iVar1;

  int local_20c;

  uint16_t local_208 [260];

  

  local_208[0] = 0;

  local_20c = 0;

  swscanf(param_1,L"%d%s",&local_20c,local_208);

  switch(local_208[0]) {

  case 0x41:

  case 0x61:

    iVar1 = (int)DAT_00a1e8b0;

    return (iVar1 + (local_20c / iVar1) * 4) * iVar1 + (local_20c % iVar1) * 2;

  case 0x42:

  case 0x62:

    iVar1 = (int)DAT_00a1e8b0;

    return (iVar1 + (local_20c / iVar1) * 4) * iVar1 + 1 + (local_20c % iVar1) * 2;

  case 0x43:

  case 99:

    iVar1 = (int)DAT_00a1e8b0;

    return (iVar1 + 2 + (local_20c / iVar1) * 4) * iVar1 + (local_20c % iVar1) * 2;

  case 0x44:

  case 100:

    iVar1 = (int)DAT_00a1e8b0;

    return (iVar1 + 2 + (local_20c / iVar1) * 4) * iVar1 + 1 + (local_20c % iVar1) * 2;

  default:

    return local_20c;

  }

}
