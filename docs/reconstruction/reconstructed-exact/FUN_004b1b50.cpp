// =============================================================================
// FUN_004b1b50
// -----------------------------------------------------------------------------
// Stable ID: aa_004b1b50
// Address:   0x004b1b50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b1b50 @ 0x004b1b50
// Stable ID: aa_004b1b50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: return×7, if×6.
//  - Notable callees: FUN_004b0d60, FUN_004b1b50, FUN_0079e680, FUN_0079e6b0, FUN_0079e6e0, FUN_0079e710, FUN_0079e740, FUN_0079e770.
//  - Return sites: 7.

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

void __fastcall FUN_004b1b50(int *param_1)



{

  byte bVar1;

  int local_34;

  int local_30;

  int local_2c;

  uint8_t local_24 [16];

  int local_14;

  int local_10;

  int local_c;

  float local_8;

  float local_4;

  

  local_8 = (float)param_1[4] * *(float *)(*param_1 + 0x8bc);

  local_4 = (float)param_1[6] * *(float *)(*param_1 + 0x8bc);

  local_34 = param_1[0x5e];

  local_30 = param_1[0x5f];

  local_2c = param_1[0x60];

  FUN_004b0d60(local_24,param_1[0x20]);

  local_c = param_1[0xb];

  local_14 = param_1[0xd];

  local_10 = param_1[0xc];

  if (*(char *)((int)param_1 + 0x241) != '\0') {

    if ((*(byte *)(*param_1 + 0x989) & 0x80) != 0) {

      FUN_0079e740(&local_34);

      return;

    }

    FUN_0079e710(&local_34);

    return;

  }

  bVar1 = *(byte *)(*param_1 + 0x98a);

  if ((bVar1 & 2) != 0) {

    FUN_0079e7a0(&local_34);

    return;

  }

  if ((bVar1 & 4) != 0) {

    FUN_0079e6b0(&local_34);

    return;

  }

  if ((bVar1 & 8) != 0) {

    FUN_0079e680(&local_34);

    return;

  }

  if ((*(byte *)(*param_1 + 0x989) & 0x80) != 0) {

    FUN_0079e770(&local_34);

    return;

  }

  FUN_0079e6e0(&local_34);

  return;

}
