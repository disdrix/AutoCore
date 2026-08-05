// =============================================================================
// FUN_007fb3b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fb3b0
// Address:   0x007fb3b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fb3b0 @ 0x007fb3b0
// Stable ID: aa_007fb3b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, switch×1.
//  - Notable callees: FUN_007fb3b0.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint FUN_007fb3b0(float param_1)



{

  bool bVar1;

  uint in_EAX;

  uint uVar2;

  float in_XMM1_Da;

  float local_4;

  

  if (*(code **)(in_EAX + 0xdd4) != (code *)0x0) {

    bVar1 = false;

    local_4 = g_flOne;

    if (DAT_00aaa688 <= in_XMM1_Da) {

      if (DAT_00a0f6a4 <= in_XMM1_Da) {

        bVar1 = true;

      }

      else {

        local_4 = DAT_00a0f71c;

      }

    }

    else {

      local_4 = g_flOverheatCoolFrac;

    }

    switch(param_1) {

    case 2.8026e-45:

      local_4 = local_4 * _DAT_00aaa684;

      break;

    case 4.2039e-45:

      local_4 = local_4 * DAT_00a0f704;

      break;

    case 5.60519e-45:

      local_4 = local_4 * DAT_00aaa680;

      break;

    case 7.00649e-45:

      local_4 = local_4 * DAT_00a0f734;

      break;

    case 8.40779e-45:

      local_4 = local_4 * DAT_00a0f298;

    }

    param_1 = local_4;

    if (!bVar1) {

      param_1 = 0.0;

    }

    uVar2 = (**(code **)(in_EAX + 0xdd4))(param_1,local_4,local_4 * g_flLevelUpUiBase_Inferred);

    return uVar2;

  }

  return in_EAX & 0xffffff00;

}
