// READABILITY (auto CF):
//  - Body size: ~129 non-empty decompiler lines.
//  - Control keywords: if×7, return×3, goto×1.
//  - Notable callees: fcos×2, fpatan×2, fsin×2, ABS, FUN_0043f210, FUN_0043f2e0, FUN_0075b7f0, fptan.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxView.cpp".
//  - Return sites: 3.

// =============================================================================
// Named_gfxView_0075b7f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0075b7f0
// Address:   0x0075b7f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxView"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall Named_gfxView_0075b7f0(int param_1)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  float10 fVar4;

  float10 fVar5;

  float10 fVar6;

  float10 fVar7;

  unkbyte10 Var8;

  unkbyte10 Var9;

  float fVar10;

  float fVar11;

  float fVar12;

  

  if (*(float *)(param_1 + 0x58) != *(float *)(param_1 + 0xc)) {

    *(uint8_t *)(param_1 + 0x48) = 1;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x58) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xc);

  }

  if (*(char *)(param_1 + 0x48) == '\0') {

    return 0;

  }

  if (ABS(*(float *)(param_1 + 0xf4) - *(float *)(param_1 + 0xf0)) < DAT_00a0f718) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxView.cpp",0xa9,3,

                   "Couldn\'t create projection matrix, near and far planes too close.");

    return 0xffffffff;

  }

  if (*(int *)(param_1 + 0xec) == 0) {

    iVar1 = *(int *)(param_1 + 0xdc);

    iVar2 = *(int *)(param_1 + 0xe0);

    fVar4 = (float10)fptan((float10)*(float *)(param_1 + 0x10c) * (float10)DAT_00a0f298);

    fVar12 = (float)((float10)g_flOne / fVar4);

    if (iVar2 < iVar1) {

      *(float *)(param_1 + 0x110) = fVar12;

      *(float *)(param_1 + 0x114) = ((float)iVar1 * fVar12) / (float)iVar2;

    }

    else {

      *(float *)(param_1 + 0x110) = ((float)iVar2 * fVar12) / (float)iVar1;

      *(float *)(param_1 + 0x114) = fVar12;

    }

    fVar11 = *(float *)(param_1 + 0x110) * *(float *)(param_1 + 0x58);

    *(float *)(param_1 + 0x110) = fVar11;

    fVar10 = *(float *)(param_1 + 0x114) * *(float *)(param_1 + 0x58);

    *(float *)(param_1 + 0x114) = fVar10;

    fVar12 = g_flOne;

    if (*(char *)(param_1 + 0x14d) == '\0') {

      fVar12 = DAT_00aaa880 / (DAT_00aaa880 - *(float *)(param_1 + 0xf0));

    }

    FUN_0043f210(fVar11,0,0,0,0,fVar10,0,0,0,0,fVar12,0x3f800000,0,0,

                 0.0 - *(float *)(param_1 + 0xf0) * fVar12,0);

    fVar12 = g_flOne;

    fVar11 = g_flOne / *(float *)(param_1 + 0x110);

    Var8 = fpatan((float10)fVar11,(float10)1);

    fVar10 = g_flOne / *(float *)(param_1 + 0x114);

    *(float *)(param_1 + 0xf8) = *(float *)(param_1 + 0xf0) * fVar11;

    *(uint8_t *)(param_1 + 0x49) = 1;

    *(float *)(param_1 + 0xfc) = *(float *)(param_1 + 0xf0) * fVar10;

    *(float *)(param_1 + 0x68) = 0.0 - *(float *)(param_1 + 0xf0);

    *(float *)(param_1 + 100) = fVar12;

    uVar3 = DAT_00aaa668;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x74) = uVar3;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xf4);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x70) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x88) = 0;

    Var9 = fpatan((float10)fVar10,(float10)1);

    fVar4 = (float10)fcos(Var9);

    fVar5 = (float10)fsin(Var9);

    *(float *)(param_1 + 0x80) = 0.0 - (float)fVar4;

    *(float *)(param_1 + 0x84) = (float)fVar5;

    fVar6 = (float10)fcos(Var8);

    fVar7 = (float10)fsin(Var8);

    *(float *)(param_1 + 0xac) = (float)fVar6;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xb0) = 0;

    *(float *)(param_1 + 0xb4) = (float)fVar7;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xb8) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x9c) = 0;

    *(float *)(param_1 + 0xa0) = (float)fVar4;

    *(float *)(param_1 + 0xa4) = (float)fVar5;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xa8) = 0;

    *(float *)(param_1 + 0x8c) = 0.0 - (float)fVar6;

    *(float *)(param_1 + 0x94) = (float)fVar7;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x98) = 0;

  }

  else {

    if (*(int *)(param_1 + 0xec) != 1) goto LAB_0075bcb7;

    fVar10 = g_flOne / *(float *)(param_1 + 0x58);

    FUN_0043f2e0(*(float *)(param_1 + 0x120) * fVar10,*(uint32_t /* width from decompiler */ *)(param_1 + 0xf0),

                 *(uint32_t /* width from decompiler */ *)(param_1 + 0xf4));

    uVar3 = DAT_00aaa668;

    fVar11 = g_flOne;

    fVar12 = DAT_00a0f298;

    *(float *)(param_1 + 0xf8) =

         (*(float *)(param_1 + 0x11c) - *(float *)(param_1 + 0x118)) * fVar10 * DAT_00a0f298;

    *(uint8_t *)(param_1 + 0x49) = 1;

    *(float *)(param_1 + 0xfc) =

         (*(float *)(param_1 + 0x124) - *(float *)(param_1 + 0x120)) * fVar10 * fVar12;

    *(float *)(param_1 + 0x68) = 0.0 - *(float *)(param_1 + 0xf0);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = 0;

    *(float *)(param_1 + 100) = fVar11;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x78) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xf4);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x70) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x74) = uVar3;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x80) = uVar3;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x84) = 0;

    *(float *)(param_1 + 0x88) = *(float *)(param_1 + 0x124) * fVar10;

    *(float *)(param_1 + 0xac) = fVar11;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xb0) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xb4) = 0;

    *(float *)(param_1 + 0xb8) = 0.0 - *(float *)(param_1 + 0x118) * fVar10;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x9c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xa0) = 0;

    *(float *)(param_1 + 0xa4) = fVar11;

    *(float *)(param_1 + 0xa8) = 0.0 - *(float *)(param_1 + 0x120) * fVar10;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x8c) = uVar3;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x94) = 0;

    *(float *)(param_1 + 0x98) = *(float *)(param_1 + 0x11c) * fVar10;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x90) = 0;

LAB_0075bcb7:

  *(uint8_t *)(param_1 + 0x48) = 0;

  *(uint8_t *)(param_1 + 0xcc) = 1;

  return 0;

}
