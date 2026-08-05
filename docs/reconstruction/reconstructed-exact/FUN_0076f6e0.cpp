// =============================================================================
// FUN_0076f6e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0076f6e0
// Address:   0x0076f6e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076f6e0 @ 0x0076f6e0
// Stable ID: aa_0076f6e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: ABS×6, FUN_0076f240, FUN_0076f6e0.
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



void FUN_0076f6e0(void)



{

  float *in_EAX;

  float *pfVar1;

  float *unaff_EBX;

  float local_2c;

  float local_28 [2];

  float local_20;

  float local_1c;

  float local_18;

  float local_14;

  

  local_20 = *in_EAX;

  local_1c = in_EAX[1];

  local_18 = in_EAX[2];

  local_14 = 1.0;

  FUN_0076f240(&local_20);

  if (_DAT_00a240ec < ABS(local_14 - g_flOne)) {

    pfVar1 = &local_2c;

    local_28[0] = ABS((float)_DAT_00aaa5f8);

    local_2c = ABS(local_14);

    if (ABS(local_14) <= ABS((float)_DAT_00aaa5f8)) {

      pfVar1 = local_28;

    }

    if ((*pfVar1 * _DAT_00a240ec < ABS(local_14 - g_flOne)) &&

       ((_DAT_00a240ec <= local_14 || (local_14 <= DAT_00aaa640)))) {

      local_14 = g_flOne / local_14;

      *unaff_EBX = local_14 * local_20;

      unaff_EBX[1] = local_14 * local_1c;

      unaff_EBX[2] = local_14 * local_18;

      return;

    }

  }

  *unaff_EBX = local_20;

  unaff_EBX[1] = local_1c;

  unaff_EBX[2] = local_18;

  return;

}
