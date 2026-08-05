// =============================================================================
// FUN_0076eee0
// -----------------------------------------------------------------------------
// Stable ID: aa_0076eee0
// Address:   0x0076eee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076eee0 @ 0x0076eee0
// Stable ID: aa_0076eee0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~117 non-empty decompiler lines.
//  - Control keywords: if×8, for×1, return×1.
//  - Notable callees: ABS×6, FUN_00412d80, FUN_0076eb00, FUN_0076eee0.
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



void __thiscall FUN_0076eee0(float *param_1,float param_2,float *param_3)



{

  bool bVar1;

  bool bVar2;

  float fVar3;

  float *in_EAX;

  float *pfVar4;

  int iVar5;

  float *unaff_EBX;

  float *pfVar6;

  float local_5c;

  float local_58 [2];

  float local_50 [4];

  float local_40;

  float local_3c;

  float local_38;

  float local_30;

  float local_2c;

  float local_28;

  float local_20;

  float local_1c;

  float local_18;

  

  if (in_EAX == (float *)0x0) {

    unaff_EBX[0xc] = 0.0;

    unaff_EBX[0xd] = 0.0;

    unaff_EBX[0xe] = 0.0;

  }

  else {

    unaff_EBX[0xc] = *in_EAX;

    unaff_EBX[0xd] = in_EAX[1];

    unaff_EBX[0xe] = in_EAX[2];

  }

  bVar2 = false;

  if ((param_3 != (float *)0x0) &&

     (((*param_3 != 0.0 || (param_3[1] != 0.0)) || (param_3[2] != 0.0)))) {

    unaff_EBX[0xc] = *param_3 + unaff_EBX[0xc];

    unaff_EBX[0xd] = param_3[1] + unaff_EBX[0xd];

    unaff_EBX[0xe] = param_3[2] + unaff_EBX[0xe];

    bVar2 = true;

  }

  fVar3 = g_flOne;

  bVar1 = false;

  if ((param_1 == (float *)0x0) ||

     (((*param_1 == 0.0 && (param_1[1] == 0.0)) && ((param_1[2] == 0.0 && (param_1[3] == g_flOne))))

     )) {

    *unaff_EBX = g_flOne;

    unaff_EBX[1] = 0.0;

    unaff_EBX[2] = 0.0;

    unaff_EBX[4] = 0.0;

    unaff_EBX[5] = fVar3;

    unaff_EBX[6] = 0.0;

    unaff_EBX[8] = 0.0;

    unaff_EBX[9] = 0.0;

    unaff_EBX[10] = fVar3;

  }

  else {

    FUN_0076eb00(local_50,param_1);

    *unaff_EBX = local_50[0];

    unaff_EBX[1] = local_50[1];

    unaff_EBX[2] = local_50[2];

    unaff_EBX[4] = local_40;

    unaff_EBX[5] = local_3c;

    unaff_EBX[6] = local_38;

    unaff_EBX[8] = local_30;

    unaff_EBX[9] = local_2c;

    unaff_EBX[10] = local_28;

    bVar1 = true;

  }

  if (bVar2) {

    if (bVar1) {

      local_20 = 0.0 - *param_3;

      pfVar4 = (float *)&DAT_00afdf70;

      pfVar6 = local_50;

      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {

        *pfVar6 = *pfVar4;

        pfVar4 = pfVar4 + 1;

        pfVar6 = pfVar6 + 1;

      }

      local_1c = 0.0 - param_3[1];

      local_18 = 0.0 - param_3[2];

      FUN_00412d80();

    }

    else {

      unaff_EBX[0xc] = unaff_EBX[0xc] - *param_3;

      unaff_EBX[0xd] = unaff_EBX[0xd] - param_3[1];

      unaff_EBX[0xe] = unaff_EBX[0xe] - param_3[2];

    }

  }

  if (_DAT_00a240ec < ABS(param_2 - g_flOne)) {

    pfVar4 = &local_5c;

    local_58[0] = ABS((float)_DAT_00aaa5f8);

    local_5c = ABS(param_2);

    if (ABS(param_2) <= ABS((float)_DAT_00aaa5f8)) {

      pfVar4 = local_58;

    }

    if (*pfVar4 * _DAT_00a240ec < ABS(param_2 - g_flOne)) {

      *unaff_EBX = *unaff_EBX * param_2;

      unaff_EBX[1] = unaff_EBX[1] * param_2;

      unaff_EBX[2] = unaff_EBX[2] * param_2;

      unaff_EBX[3] = param_2 * unaff_EBX[3];

      unaff_EBX[4] = unaff_EBX[4] * param_2;

      unaff_EBX[5] = unaff_EBX[5] * param_2;

      unaff_EBX[6] = unaff_EBX[6] * param_2;

      unaff_EBX[7] = unaff_EBX[7] * param_2;

      unaff_EBX[8] = unaff_EBX[8] * param_2;

      unaff_EBX[9] = unaff_EBX[9] * param_2;

      unaff_EBX[10] = unaff_EBX[10] * param_2;

      unaff_EBX[0xb] = param_2 * unaff_EBX[0xb];

      unaff_EBX[0xc] = unaff_EBX[0xc] * param_2;

      unaff_EBX[0xd] = unaff_EBX[0xd] * param_2;

      unaff_EBX[0xe] = unaff_EBX[0xe] * param_2;

      unaff_EBX[0xf] = unaff_EBX[0xf] * param_2;

    }

  }

  return;

}
