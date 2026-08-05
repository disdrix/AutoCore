// =============================================================================
// GfxView_EnsureProjection_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0075b7f0
// Address:   0x0075b7f0  (autoassault.exe, image base 0x400000)
// System:    graphics / client camera (feeds unproject near extents)
// Generated: 2026-07-29 dual A/B refine from live Ghidra decompile
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE:
//   gfxView method: dirty-gated projection rebuild.
//   - Sync zoom cache (+0x58) from +0x0c; set dirty +0x48 when they differ.
//   - Fail if |far-near| < 0.01 (log gfxView.cpp:0xa9).
//   - Mode 0 perspective: FOV→cot(halfFOV)×aspect×zoom → scales +0x110/+0x114;
//     optional Z scale 10000/(10000-near) when +0x14d==0; write 4×4 via FUN_0043f210;
//     near extents +0xf8/+0xfc = near/scaleX|Y; atan plane block.
//   - Mode 1 ortho: invZoom; FUN_0043f2e0; extents from rect×invZ×0.5.
//   - Clear dirty; set ready +0xcc.
//
// Path string in body:
//   C:\vog\1_code\palantir\palantir\graphics\gfxView.cpp
//
// Sibling consumer: GfxView_UnprojectScreenToWorldRay_Inferred (0x0075c340) always calls this.
//
// Constants (read_memory 2026-07-29):
//   DAT_00a0f718 @ 0x00a0f718 = 0.01   (near/far epsilon)
//   DAT_00a0f298 @ 0x00a0f298 = 0.5    (half FOV / half width)
//   g_flOne      @ 0x00a0f2a0 = 1.0
//   DAT_00aaa880 @ 0x00aaa880 = 10000.0
//   DAT_00aaa668 @ 0x00aaa668 = -1.0

// READABILITY:
//  - Control keywords: if×7, return×3, goto×1 (matches raw).
//  - Callees: vog_LogMessage, FUN_0043f210, FUN_0043f2e0, fptan/fpatan/fcos/fsin, ABS.
//  - CF must remain ≡ raw/live decompile.

/*
 * Behavioral notes:
 * - __thiscall: this in ECX (decompiler param_1).
 * - Returns 0 on success/skip, 0xffffffff when near/far too close.
 * - FUN_0043f210 = 16-float matrix copy (dest via ECX at call — offset open).
 * - FUN_0043f2e0 ortho path is register/XMM messy; treated as black-box matrix fill.
 * - Runtime / differential verification: OPEN.
 */

extern float DAT_00a0f718; // 0.01
extern float DAT_00a0f298; // 0.5
extern float g_flOne;      // 1.0
extern float DAT_00aaa880; // 10000.0
extern float DAT_00aaa668; // -1.0
extern void vog_LogMessage(const char *file, int line, int level, const char *msg);
extern void FUN_0043f210(/* 16 matrix floats; thiscall dest */);
extern void FUN_0043f2e0(float bottomScaled, float nearZ, float farZ);
extern float ABS(float);

// x87 helpers as used by decompiler
typedef long double float10;
extern float10 fptan(float10);
extern float10 fpatan(float10 y, float10 x);
extern float10 fcos(float10);
extern float10 fsin(float10);

uint32_t /* width from decompiler */ __fastcall GfxView_EnsureProjection_Inferred(int param_1)
{
  int iVar1;
  int iVar2;
  uint32_t uVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  float10 Var8;
  float10 Var9;
  float fVar10;
  float fVar11;
  float fVar12;

  // zoom cache sync → dirty
  if (*(float *)(param_1 + 0x58) != *(float *)(param_1 + 0xc)) {
    *(uint8_t *)(param_1 + 0x48) = 1;
    *(uint32_t *)(param_1 + 0x58) = *(uint32_t *)(param_1 + 0xc);
  }
  if (*(char *)(param_1 + 0x48) == '\0') {
    return 0;
  }

  // near/far too close
  if (ABS(*(float *)(param_1 + 0xf4) - *(float *)(param_1 + 0xf0)) < DAT_00a0f718) {
    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxView.cpp", 0xa9, 3,
                   "Couldn't create projection matrix, near and far planes too close.");
    return 0xffffffff;
  }

  if (*(int *)(param_1 + 0xec) == 0) {
    // perspective
    iVar1 = *(int *)(param_1 + 0xdc); // width
    iVar2 = *(int *)(param_1 + 0xe0); // height
    fVar4 = (float10)fptan((float10)*(float *)(param_1 + 0x10c) * (float10)DAT_00a0f298);
    fVar12 = (float)((float10)g_flOne / fVar4); // cot(halfFOV)
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
    FUN_0043f210(fVar11, 0, 0, 0, 0, fVar10, 0, 0, 0, 0, fVar12, 0x3f800000, 0, 0,
                 0.0f - *(float *)(param_1 + 0xf0) * fVar12, 0);

    fVar12 = g_flOne;
    fVar11 = g_flOne / *(float *)(param_1 + 0x110);
    Var8 = fpatan((float10)fVar11, (float10)1);
    fVar10 = g_flOne / *(float *)(param_1 + 0x114);
    // near extents
    *(float *)(param_1 + 0xf8) = *(float *)(param_1 + 0xf0) * fVar11;
    *(uint8_t *)(param_1 + 0x49) = 1;
    *(float *)(param_1 + 0xfc) = *(float *)(param_1 + 0xf0) * fVar10;
    *(float *)(param_1 + 0x68) = 0.0f - *(float *)(param_1 + 0xf0);
    *(float *)(param_1 + 100) = fVar12;
    uVar3 = *(uint32_t *)&DAT_00aaa668;
    *(uint32_t *)(param_1 + 0x5c) = 0;
    *(uint32_t *)(param_1 + 0x60) = 0;
    *(uint32_t *)(param_1 + 0x74) = uVar3;
    *(uint32_t *)(param_1 + 0x78) = *(uint32_t *)(param_1 + 0xf4);
    *(uint32_t *)(param_1 + 0x6c) = 0;
    *(uint32_t *)(param_1 + 0x70) = 0;
    *(uint32_t *)(param_1 + 0x7c) = 0;
    *(uint32_t *)(param_1 + 0x88) = 0;
    Var9 = fpatan((float10)fVar10, (float10)1);
    fVar4 = (float10)fcos(Var9);
    fVar5 = (float10)fsin(Var9);
    *(float *)(param_1 + 0x80) = 0.0f - (float)fVar4;
    *(float *)(param_1 + 0x84) = (float)fVar5;
    fVar6 = (float10)fcos(Var8);
    fVar7 = (float10)fsin(Var8);
    *(float *)(param_1 + 0xac) = (float)fVar6;
    *(uint32_t *)(param_1 + 0xb0) = 0;
    *(float *)(param_1 + 0xb4) = (float)fVar7;
    *(uint32_t *)(param_1 + 0xb8) = 0;
    *(uint32_t *)(param_1 + 0x9c) = 0;
    *(float *)(param_1 + 0xa0) = (float)fVar4;
    *(float *)(param_1 + 0xa4) = (float)fVar5;
    *(uint32_t *)(param_1 + 0xa8) = 0;
    *(float *)(param_1 + 0x8c) = 0.0f - (float)fVar6;
    *(float *)(param_1 + 0x94) = (float)fVar7;
    *(uint32_t *)(param_1 + 0x98) = 0;
  }
  else {
    if (*(int *)(param_1 + 0xec) != 1) goto LAB_0075bcb7;
    // ortho
    fVar10 = g_flOne / *(float *)(param_1 + 0x58);
    FUN_0043f2e0(*(float *)(param_1 + 0x120) * fVar10, *(float *)(param_1 + 0xf0),
                 *(float *)(param_1 + 0xf4));
    uVar3 = *(uint32_t *)&DAT_00aaa668;
    fVar11 = g_flOne;
    fVar12 = DAT_00a0f298;
    *(float *)(param_1 + 0xf8) =
         (*(float *)(param_1 + 0x11c) - *(float *)(param_1 + 0x118)) * fVar10 * DAT_00a0f298;
    *(uint8_t *)(param_1 + 0x49) = 1;
    *(float *)(param_1 + 0xfc) =
         (*(float *)(param_1 + 0x124) - *(float *)(param_1 + 0x120)) * fVar10 * fVar12;
    *(float *)(param_1 + 0x68) = 0.0f - *(float *)(param_1 + 0xf0);
    *(uint32_t *)(param_1 + 0x5c) = 0;
    *(uint32_t *)(param_1 + 0x60) = 0;
    *(float *)(param_1 + 100) = fVar11;
    *(uint32_t *)(param_1 + 0x78) = *(uint32_t *)(param_1 + 0xf4);
    *(uint32_t *)(param_1 + 0x6c) = 0;
    *(uint32_t *)(param_1 + 0x70) = 0;
    *(uint32_t *)(param_1 + 0x74) = uVar3;
    *(uint32_t *)(param_1 + 0x7c) = 0;
    *(uint32_t *)(param_1 + 0x80) = uVar3;
    *(uint32_t *)(param_1 + 0x84) = 0;
    *(float *)(param_1 + 0x88) = *(float *)(param_1 + 0x124) * fVar10;
    *(float *)(param_1 + 0xac) = fVar11;
    *(uint32_t *)(param_1 + 0xb0) = 0;
    *(uint32_t *)(param_1 + 0xb4) = 0;
    *(float *)(param_1 + 0xb8) = 0.0f - *(float *)(param_1 + 0x118) * fVar10;
    *(uint32_t *)(param_1 + 0x9c) = 0;
    *(uint32_t *)(param_1 + 0xa0) = 0;
    *(float *)(param_1 + 0xa4) = fVar11;
    *(float *)(param_1 + 0xa8) = 0.0f - *(float *)(param_1 + 0x120) * fVar10;
    *(uint32_t *)(param_1 + 0x8c) = uVar3;
    *(uint32_t *)(param_1 + 0x94) = 0;
    *(float *)(param_1 + 0x98) = *(float *)(param_1 + 0x11c) * fVar10;
  }
  *(uint32_t *)(param_1 + 0x90) = 0;
LAB_0075bcb7:
  *(uint8_t *)(param_1 + 0x48) = 0;
  *(uint8_t *)(param_1 + 0xcc) = 1;
  return 0;
}
