// =============================================================================
// FUN_006fae60
// -----------------------------------------------------------------------------
// Stable ID: aa_006fae60
// Address:   0x006fae60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006fae60 @ 0x006fae60
// Stable ID: aa_006fae60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_006f8590, FUN_006f8720, FUN_006f87d0, FUN_006f8f00, FUN_006f91d0, FUN_006fabe0, FUN_006fae60, FUN_006fb0c0.
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

void FUN_006fae60(uint8_t *param_1,float *param_2)



{

  float fVar1;

  char *pcVar2;

  int iVar3;

  uint8_t uVar4;

  ushort local_ec [2];

  uint16_t local_e8;

  uint8_t local_e1;

  float local_e0;

  float local_dc;

  float local_d8;

  float local_d4;

  float local_d0;

  float local_cc;

  float local_c8;

  float local_c4;

  uint8_t local_b0 [56];

  ushort local_78;

  uint8_t local_70 [108];

  

  uVar4 = 0;

  FUN_006fb0c0();

  local_e8 = 0;

  FUN_006f8f00();

  pcVar2 = (char *)FUN_006f91d0(&local_e1);

  if (*pcVar2 != '\0') {

    iVar3 = FUN_006fabe0(local_70,local_ec,local_b0);

    if (iVar3 != 2) {

      *param_1 = 0;

      return;

    }

    uVar4 = 1;

    if (local_78 < 3) {

      FUN_006f8590(&local_e0,local_ec,local_b0);

    }

    else if (local_78 < 6) {

      FUN_006f8720(&local_e0,local_ec,local_b0);

    }

    else {

      FUN_006f87d0(&local_e0,local_ec,local_b0);

    }

    if (2 < local_ec[0]) {

      fVar1 = -local_d4;

      local_e0 = local_d0 * fVar1 + local_e0;

      local_dc = local_cc * fVar1 + local_dc;

      local_d8 = local_c8 * fVar1 + local_d8;

      local_d4 = local_c4 * fVar1 + local_d4;

    }

    param_2[4] = local_d0;

    param_2[5] = local_cc;

    param_2[6] = local_c8;

    param_2[7] = local_c4;

    param_2[2] = local_d8;

    param_2[3] = local_d4;

    *param_2 = local_e0;

    param_2[1] = local_dc;

    param_2[3] = local_d4;

  }

  *param_1 = uVar4;

  return;

}
