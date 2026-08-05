// =============================================================================
// FUN_006f0e30
// -----------------------------------------------------------------------------
// Stable ID: aa_006f0e30
// Address:   0x006f0e30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f0e30 @ 0x006f0e30
// Stable ID: aa_006f0e30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×1.
//  - Notable callees: FUN_006f0d10×3, FUN_006f0e30.
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

void __thiscall FUN_006f0e30(int param_1,uint32_t /* width from decompiler */ param_2,float param_3,float *param_4)



{

  int iVar1;

  int local_20;

  int local_1c;

  int local_14;

  

  *param_4 = 3.4028235e+38;

  param_4[1] = 3.4028235e+38;

  param_4[2] = 3.4028235e+38;

  param_4[3] = 0.0;

  param_4[4] = -3.4028235e+38;

  param_4[5] = -3.4028235e+38;

  param_4[6] = -3.4028235e+38;

  param_4[7] = 0.0;

  local_14 = 0;

  if (0 < *(int *)(param_1 + 0x2c)) {

    local_1c = 0;

    do {

      iVar1 = *(int *)(param_1 + 0x28);

      local_20 = 0;

      if (0 < *(int *)(iVar1 + 0x18 + local_1c)) {

        do {

          FUN_006f0d10(param_2);

          FUN_006f0d10(param_2);

          FUN_006f0d10(param_2);

          local_20 = local_20 + 1;

        } while (local_20 < *(int *)(iVar1 + local_1c + 0x18));

      }

      local_14 = local_14 + 1;

      local_1c = local_1c + 0x30;

    } while (local_14 < *(int *)(param_1 + 0x2c));

  }

  param_3 = param_3 + *(float *)(param_1 + 0x20);

  *param_4 = *param_4 - param_3;

  param_4[1] = param_4[1] - param_3;

  param_4[2] = param_4[2] - param_3;

  param_4[3] = param_4[3] - param_3;

  param_4[4] = param_3 + param_4[4];

  param_4[5] = param_3 + param_4[5];

  param_4[6] = param_3 + param_4[6];

  param_4[7] = param_3 + param_4[7];

  return;

}
