// =============================================================================
// FUN_0075bcd0
// -----------------------------------------------------------------------------
// Stable ID: aa_0075bcd0
// Address:   0x0075bcd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075bcd0 @ 0x0075bcd0
// Stable ID: aa_0075bcd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~96 non-empty decompiler lines.
//  - Control keywords: if×9, return×2.
//  - Notable callees: FUN_00414a50, FUN_0043f410, FUN_0043f4b0, FUN_00734550, FUN_00746520, FUN_0074f360, FUN_0075bcd0, FUN_0075e8e0.
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

uint32_t /* width from decompiler */ FUN_0075bcd0(void)



{

  float fVar1;

  float fVar2;

  int in_EAX;

  int iVar3;

  float *pfVar4;

  int iVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float local_18;

  float local_14;

  

  local_18 = 0.0;

  local_14 = 0.0;

  iVar3 = *(int *)(in_EAX + 0x13c);

  fVar6 = (float)*(int *)(in_EAX + 0xe4) - DAT_00a0f298;

  fVar8 = (float)*(int *)(in_EAX + 0xe8) - DAT_00a0f298;

  fVar9 = (float)*(int *)(in_EAX + 0xdc) + fVar6;

  fVar7 = (float)*(int *)(in_EAX + 0xe0) + fVar8;

  if (iVar3 == 0) {

    iVar5 = 1;

    iVar3 = 1;

  }

  else {

    iVar5 = *(int *)(iVar3 + 0x1c);

    iVar3 = *(int *)(iVar3 + 0x20);

  }

  if (*(int *)(in_EAX + 0x140) == 0) {

    local_18 = g_flOne;

  }

  else if (*(int *)(in_EAX + 0x140) == 1) {

    local_18 = (float)*(int *)(in_EAX + 0xdc) / (float)iVar5;

  }

  if (*(int *)(in_EAX + 0x144) == 0) {

    local_14 = g_flOne;

  }

  else if (*(int *)(in_EAX + 0x144) == 1) {

    local_14 = (float)*(int *)(in_EAX + 0xe0) / (float)iVar3;

  }

  if (*(int *)(*(int *)(in_EAX + 0x130) + 0x10) != 0) {

    pfVar4 = (float *)FUN_00746520(*(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x130) + 0x14),4,1);

    fVar2 = g_flOne;

    if (pfVar4 != (float *)0x0) {

      *pfVar4 = fVar6;

      pfVar4[1] = fVar8;

      fVar1 = *(float *)(in_EAX + 0x100);

      pfVar4[3] = fVar2;

      pfVar4[2] = fVar1;

      pfVar4[7] = fVar9;

      pfVar4[8] = fVar8;

      fVar8 = *(float *)(in_EAX + 0x100);

      pfVar4[0xe] = fVar6;

      pfVar4[10] = fVar2;

      pfVar4[0xf] = fVar7;

      pfVar4[9] = fVar8;

      fVar6 = *(float *)(in_EAX + 0x100);

      pfVar4[0x11] = fVar2;

      pfVar4[0x10] = fVar6;

      pfVar4[0x16] = fVar7;

      pfVar4[0x15] = fVar9;

      fVar6 = *(float *)(in_EAX + 0x100);

      pfVar4[0x18] = fVar2;

      pfVar4[0x17] = fVar6;

      pfVar4[4] = *(float *)(in_EAX + 0x148);

      pfVar4[5] = 0.0;

      pfVar4[6] = 0.0;

      fVar6 = *(float *)(in_EAX + 0x148);

      pfVar4[0xd] = 0.0;

      pfVar4[0xb] = fVar6;

      pfVar4[0xc] = local_18;

      fVar6 = *(float *)(in_EAX + 0x148);

      pfVar4[0x13] = 0.0;

      pfVar4[0x12] = fVar6;

      pfVar4[0x14] = local_14;

      pfVar4[0x19] = *(float *)(in_EAX + 0x148);

      pfVar4[0x1a] = local_18;

      pfVar4[0x1b] = local_14;

      FUN_00414a50();

      FUN_0096f800(2);

      FUN_0043f410();

      if (*(int *)(in_EAX + 0x130) != 0) {

        FUN_0043f4b0();

      }

      if (*(int *)(*(int *)(in_EAX + 0x130) + 0x34) == 0) {

        FUN_00967150(*(int *)(in_EAX + 0x130) + 0x24);

      }

      FUN_00734550();

      FUN_0075e8e0(5,0,2);

      FUN_0074f360();

      return 0;

    }

  }

  return 0xffffffff;

}
