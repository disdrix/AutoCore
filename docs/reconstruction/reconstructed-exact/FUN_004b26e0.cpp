// =============================================================================
// FUN_004b26e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004b26e0
// Address:   0x004b26e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b26e0 @ 0x004b26e0
// Stable ID: aa_004b26e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: return×7, if×6.
//  - Notable callees: FUN_004b0d60, FUN_004b26e0, FUN_0076f5f0, FUN_007a2410, FUN_007a2450, FUN_007a2490, FUN_007a24c0, FUN_007a24f0.
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

void __fastcall FUN_004b26e0(int *param_1)



{

  byte bVar1;

  int iVar2;

  float local_5c;

  float local_58;

  float local_54;

  float local_50;

  float local_4c;

  float local_48;

  float local_44;

  float local_40;

  float local_3c;

  uint8_t local_34 [16];

  int local_24;

  int local_20;

  float local_1c;

  float local_18;

  float local_14;

  float local_c;

  float local_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar2 = *param_1;

  local_44 = (*(float *)(iVar2 + 0x838) + (float)param_1[0x5e]) * DAT_00a0f298;

  local_40 = (*(float *)(iVar2 + 0x83c) + (float)param_1[0x5f]) * DAT_00a0f298;

  local_3c = (*(float *)(iVar2 + 0x840) + (float)param_1[0x60]) * DAT_00a0f298;

  local_5c = (float)param_1[0x5e] - *(float *)(iVar2 + 0x838);

  local_58 = (float)param_1[0x5f] - *(float *)(iVar2 + 0x83c);

  local_54 = (float)param_1[0x60] - *(float *)(iVar2 + 0x840);

  local_8 = SQRT(local_5c * local_5c + local_58 * local_58 + local_54 * local_54) *

            (float)param_1[6];

  local_50 = local_5c;

  local_4c = local_58;

  local_48 = local_54;

  FUN_0076f5f0(&local_5c,&local_5c);

  local_1c = local_5c;

  local_18 = local_58;

  local_14 = local_54;

  FUN_004b0d60(local_34,param_1[0x20]);

  local_20 = param_1[0xc];

  local_24 = param_1[0xd];

  iVar2 = *param_1;

  local_c = *(float *)(iVar2 + 0x8bc) * (float)param_1[4];

  local_4 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x8f4);

  if (*(char *)((int)param_1 + 0x241) != '\0') {

    if ((*(byte *)(iVar2 + 0x989) & 0x80) != 0) {

      FUN_007a24f0(&local_44);

      return;

    }

    FUN_007a24c0(&local_44);

    return;

  }

  bVar1 = *(byte *)(iVar2 + 0x98a);

  if ((bVar1 & 2) != 0) {

    FUN_007a2550(&local_44);

    return;

  }

  if ((bVar1 & 4) != 0) {

    FUN_007a2450(&local_44);

    return;

  }

  if ((bVar1 & 8) != 0) {

    FUN_007a2410(&local_44);

    return;

  }

  if ((*(byte *)(iVar2 + 0x989) & 0x80) != 0) {

    FUN_007a2520(&local_44);

    return;

  }

  FUN_007a2490(&local_44);

  return;

}
