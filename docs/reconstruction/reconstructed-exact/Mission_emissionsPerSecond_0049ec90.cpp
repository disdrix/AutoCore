// READABILITY (auto CF):
//  - Body size: ~224 non-empty decompiler lines.
//  - Control keywords: if×23, return×3, for×1.
//  - Notable callees: FUN_00799300×8, _wcsicmp×4, FUN_007994c0×3, FUN_00499ee0×2, FUN_004a6930×2, FUN_00798bb0×2, FUN_007996d0×2, CONCAT22.
//  - Strings: "dimensionX"; "dimensionY"; "emissionsPerSecond"; "randomAngle".
//  - Return sites: 3.

// =============================================================================
// Mission_emissionsPerSecond_0049ec90
// -----------------------------------------------------------------------------
// Stable ID: aa_0049ec90
// Address:   0x0049ec90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "emissionsPerSecond"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Mission_emissionsPerSecond_0049ec90(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  int iVar2;

  float *pfVar3;

  float *pfVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint16_t in_FPUControlWord;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  int local_2a4;

  char cStack_29d;

  float fStack_29c;

  void *pvStack_298;

  float fStack_294;

  float fStack_290;

  float fStack_28c;

  float fStack_288;

  uint8_t auStack_284 [12];

  float fStack_278;

  float fStack_274;

  float fStack_270;

  float fStack_268;

  float fStack_264;

  float fStack_260;

  float fStack_258;

  float fStack_254;

  float fStack_250;

  float fStack_234;

  float fStack_224;

  wchar_t awStack_220 [2];

  uint32_t /* width from decompiler */ auStack_21c [130];

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009a0f79;

  pvStack_14 = ExceptionList;

  ExceptionList = &pvStack_14;

  if (((param_1 != (int *)0x0) &&

      (ExceptionList = &pvStack_14, iVar2 = (**(code **)(*param_1 + 0x44))(param_1,&local_2a4),

      iVar2 == 0)) && (local_2a4 != 0)) {

    pvStack_298 = operator_new(0x84);

    uStack_c = 0;

    if (pvStack_298 == (void *)0x0) {

      pfVar3 = (float *)0x0;

    }

    else {

      pfVar3 = (float *)FUN_00498b00(param_2);

    }

    uStack_c = 0xffffffff;

    cVar1 = FUN_00799300(local_2a4,L"dimensionX",&fStack_29c);

    if (cVar1 != '\0') {

      pfVar3[0x10] = fStack_29c;

    }

    cVar1 = FUN_00799300(local_2a4,L"dimensionY",&fStack_29c);

    if (cVar1 != '\0') {

      pfVar3[0x11] = fStack_29c;

    }

    cVar1 = FUN_00799300(local_2a4,L"emissionsPerSecond",&fStack_29c);

    if (cVar1 != '\0') {

      pfVar3[0x17] = fStack_29c;

    }

    cVar1 = FUN_00799300(local_2a4,L"randomAngle",&fStack_29c);

    if (cVar1 != '\0') {

      pfVar3[0x15] = fStack_29c;

    }

    cVar1 = FUN_00799300(local_2a4,L"velocity",&fStack_29c);

    if (cVar1 != '\0') {

      pfVar3[0x16] = fStack_29c;

    }

    cVar1 = FUN_00799300(local_2a4,L"totalParticles",&fStack_29c);

    if (cVar1 != '\0') {

      fStack_294 = (float)CONCAT22(fStack_294._2_2_,in_FPUControlWord);

      pvStack_298 = (void *)(int)ROUND(fStack_29c);

      pfVar3[0xe] = (float)pvStack_298;

    }

    cVar1 = FUN_00799300(local_2a4,L"particleLifetime",&fStack_29c);

    if (cVar1 != '\0') {

      pfVar3[0x18] = fStack_29c;

    }

    cVar1 = FUN_00799300(local_2a4,L"lifetime",&fStack_29c);

    if (cVar1 != '\0') {

      pfVar3[0x1e] = fStack_29c;

    }

    cVar1 = FUN_007994c0(local_2a4,L"randomPos",auStack_284,0,0,0);

    if (cVar1 != '\0') {

      pfVar4 = (float *)FUN_004a6930(auStack_284);

      pfVar3[0x12] = *pfVar4;

      pfVar3[0x13] = pfVar4[1];

      pfVar3[0x14] = pfVar4[2];

    }

    fStack_278 = g_flOne;

    *pfVar3 = g_flOne;

    pfVar3[1] = 0.0;

    pfVar3[2] = 0.0;

    pfVar3[3] = 0.0;

    pfVar3[4] = fStack_278;

    pfVar3[5] = 0.0;

    pfVar3[6] = 0.0;

    pfVar3[7] = 0.0;

    pfVar3[8] = fStack_278;

    pfVar3[0xb] = 0.0;

    pfVar3[10] = 0.0;

    pfVar3[9] = 0.0;

    fStack_274 = 0.0;

    fStack_270 = 0.0;

    fStack_268 = 0.0;

    fStack_264 = fStack_278;

    fStack_260 = 0.0;

    fStack_258 = 0.0;

    fStack_254 = 0.0;

    fStack_250 = fStack_278;

    cVar1 = FUN_007994c0(local_2a4,L"direction",&fStack_290,0,0,0);

    fVar6 = fStack_260;

    fVar7 = fStack_278;

    fVar8 = fStack_274;

    fVar9 = fStack_258;

    fVar10 = fStack_250;

    fVar11 = fStack_254;

    fVar12 = fStack_264;

    fVar13 = fStack_270;

    if (cVar1 != '\0') {

      fStack_294 = SQRT(fStack_288 * fStack_288 + fStack_28c * fStack_28c + fStack_290 * fStack_290)

      ;

      if (fStack_294 != g_flZero) {

        fVar6 = g_flOne / fStack_294;

        fStack_288 = fVar6 * fStack_288;

        fStack_290 = fVar6 * fStack_290;

        fStack_28c = fVar6 * fStack_28c;

      }

      fVar8 = fStack_290 * DAT_00a0f718 - fStack_288 * DAT_00a0f718;

      fVar7 = fStack_288 * DAT_009c8354 - fStack_28c * DAT_00a0f718;

      fStack_224 = fStack_28c * DAT_00a0f718 - fStack_290 * DAT_009c8354;

      fStack_268 = fStack_28c * fStack_224 - fStack_288 * fVar8;

      pvStack_298 = (void *)(fStack_288 * fVar7);

      fStack_234 = (float)pvStack_298 - fStack_290 * fStack_224;

      fVar6 = fStack_290 * fVar8 - fStack_28c * fVar7;

      fVar9 = fStack_290;

      fVar10 = fStack_288;

      fVar11 = fStack_28c;

      fVar12 = fStack_234;

      fVar13 = fStack_224;

    }

    *pfVar3 = fVar7;

    pfVar3[7] = fVar6;

    pfVar3[1] = fStack_268;

    pfVar3[2] = fVar9;

    pfVar3[3] = fVar8;

    pfVar3[4] = fVar12;

    pfVar3[5] = fVar11;

    pfVar3[6] = fVar13;

    pfVar3[8] = fVar10;

    pfVar3[9] = 0.0;

    pfVar3[10] = 0.0;

    pfVar3[0xb] = 0.0;

    cVar1 = FUN_007994c0(local_2a4,L"offset",auStack_284,0,0,0);

    if (cVar1 != '\0') {

      pfVar4 = (float *)FUN_004a6930(auStack_284);

      pfVar3[9] = *pfVar4;

      pfVar3[10] = pfVar4[1];

      pfVar3[0xb] = pfVar4[2];

    }

    cVar1 = FUN_007996d0(local_2a4,L"attached",&cStack_29d);

    if (cVar1 != '\0') {

      *(char *)(pfVar3 + 0x1f) = cStack_29d;

    }

    cVar1 = FUN_007996d0(local_2a4,L"addVelocity",&cStack_29d);

    if (cVar1 != '\0') {

      if (cStack_29d == '\0') {

        pfVar3[0x19] = (float)((uint)pfVar3[0x19] & 0xfffffff7);

      }

      else {

        pfVar3[0x19] = (float)((uint)pfVar3[0x19] | 8);

      }

    }

    awStack_220[0] = L'\0';

    awStack_220[1] = L'\0';

    puVar5 = auStack_21c;

    for (iVar2 = 0x81; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar5 = 0;

      puVar5 = puVar5 + 1;

    }

    cVar1 = FUN_00798bb0(local_2a4,L"type",awStack_220);

    if (cVar1 != '\0') {

      iVar2 = _wcsicmp(awStack_220,L"pressure");

      if (iVar2 == 0) {

        pfVar3[0xd] = 1.4013e-45;

      }

      else {

        iVar2 = _wcsicmp(awStack_220,L"constant");

        if (iVar2 == 0) {

          pfVar3[0xd] = 2.8026e-45;

        }

      }

    }

    cVar1 = FUN_00798bb0(local_2a4,L"shape",awStack_220);

    if (cVar1 != '\0') {

      iVar2 = _wcsicmp(awStack_220,L"elipse");

      if (iVar2 == 0) {

        pfVar3[0xf] = 2.8026e-45;

        FUN_00499ee0(pfVar3);

        ExceptionList = pvStack_14;

        return 1;

      }

      iVar2 = _wcsicmp(awStack_220,L"rectangle");

      if (iVar2 == 0) {

        pfVar3[0xf] = 1.4013e-45;

      }

    }

    FUN_00499ee0(pfVar3);

    ExceptionList = pvStack_14;

    return 1;

  }

  FUN_007a4480(0,"VOG_DEBUG_STOP");

  ExceptionList = pvStack_14;

  return 0;

}
