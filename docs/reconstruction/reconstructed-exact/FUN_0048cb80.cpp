// =============================================================================
// FUN_0048cb80
// -----------------------------------------------------------------------------
// Stable ID: aa_0048cb80
// Address:   0x0048cb80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048cb80 @ 0x0048cb80
// Stable ID: aa_0048cb80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, switch×1.
//  - Notable callees: FUN_0048cb80.
//  - Return sites: 3.

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

void FUN_0048cb80(uint param_1,int param_2,int *param_3)



{

  byte *pbVar1;

  byte local_1c [28];

  

  local_1c[0] = 0;

  local_1c[1] = 0;

  local_1c[2] = 0;

  local_1c[3] = 0;

  local_1c[4] = 0;

  local_1c[5] = 0;

  local_1c[6] = 0;

  local_1c[7] = 0;

  local_1c[8] = 0xc0;

  local_1c[9] = 0;

  local_1c[10] = 0;

  local_1c[0xb] = 0;

  local_1c[0xc] = 0xe0;

  local_1c[0xd] = 0;

  local_1c[0xe] = 0;

  local_1c[0xf] = 0;

  local_1c[0x10] = 0xf0;

  local_1c[0x11] = 0;

  local_1c[0x12] = 0;

  local_1c[0x13] = 0;

  local_1c[0x14] = 0xf8;

  local_1c[0x15] = 0;

  local_1c[0x16] = 0;

  local_1c[0x17] = 0;

  local_1c[0x18] = 0xfc;

  local_1c[0x19] = 0;

  local_1c[0x1a] = 0;

  local_1c[0x1b] = 0;

  if (param_1 < 0x80) {

    *param_3 = 1;

  }

  else if (param_1 < 0x800) {

    *param_3 = 2;

  }

  else if (param_1 < 0x10000) {

    *param_3 = 3;

  }

  else {

    if (0x1fffff < param_1) {

      *param_3 = 0;

      return;

    }

    *param_3 = 4;

  }

  pbVar1 = (byte *)(param_2 + *param_3);

  switch(*param_3) {

  case 4:

    pbVar1 = pbVar1 + -1;

    *pbVar1 = (byte)param_1 & 0x3f | 0x80;

    param_1 = param_1 >> 6;

  case 3:

    pbVar1 = pbVar1 + -1;

    *pbVar1 = (byte)param_1 & 0x3f | 0x80;

    param_1 = param_1 >> 6;

  case 2:

    pbVar1 = pbVar1 + -1;

    *pbVar1 = (byte)param_1 & 0x3f | 0x80;

    param_1 = param_1 >> 6;

  case 1:

    pbVar1[-1] = local_1c[*param_3 * 4] | (byte)param_1;

    return;

  default:

    return;

  }

}
