// =============================================================================
// FUN_0091ce80 / Client_Camera_ModeDispatchUpdate_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0091ce80
// Address:   0x0091ce80  (autoassault.exe, image base 0x400000)
// Body:      0x0091ce80–0x0091d433 (1459 B); RET 4
// Dual A/B:  2026-07-29 accept-with-gaps (W25-B)
// System:    client camera / mode dispatch tick
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// ABI: EAX = CameraController* on entry; one stack float dt_or_scale; RET 4.
// Mode switch on cam[0x331] (+0xCC4).
// Named twin: Client_Camera_ModeDispatchUpdate_Inferred.cpp
//

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

#include <cstdint>

extern int DAT_00d1b6d8;
extern int DAT_00d17944;
extern int DAT_00d1b644;
extern float _DAT_00a240ec;
extern float DAT_00aaa690;   // 4.0
extern float DAT_00aaa68c;   // 1.5
extern float DAT_00a10e78;   // 0.05
extern float DAT_00a0f720;   // 0.4
extern float DAT_00aaa668;   // -1.0
extern float DAT_00afe288;   // 1.5
extern float DAT_00afe28c;   // 1.5
extern float DAT_00afe290;   // 1.5
extern float _DAT_00d20c4c;
extern float g_flOne;
extern char DAT_00d1b0ac;
extern float DAT_00d1b0a8;
extern float _DAT_00d1b0a4;
extern float DAT_00d1b0a0;
extern float DAT_00d1b09c;
extern float DAT_00a27c54;   // pi/180

extern void FUN_00917cd0(void *, void *, void *, void *);
extern void *FUN_004e88e0(void *, uint32_t);
extern char FUN_00917700(void);
extern void FUN_009141e0(void);
extern void FUN_00914930(float, float, float, float);
extern void FUN_0091b1c0(float, float, float, float, float);
extern void FUN_00914980(float, float, float, float, float);
extern void FUN_009168d0(int *, float *, float, float, float);
extern void FUN_0091c220(float, float, float, float, float, float, float);
extern void D3DXVec3Normalize(void *, void *);
extern void FUN_0090e1b0(float, float, float);
extern void FUN_0091b0d0(void);
extern float SQRT(float);

// RET 4; EAX = cam* on entry (decompiler residual in_EAX)
void FUN_0091ce80(float param_1)
{
  int iVar1;
  char cVar2;
  int *in_EAX; // cam*
  uint32_t uVar3;
  float *pfVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fStack_58;
  float fStack_54;
  float local_50;
  float local_4c;
  float local_48;
  uint8_t local_44[12];
  uint8_t local_38[12];
  uint8_t local_2c[12];
  uint8_t local_20[28];

  local_50 = 0.0f;
  local_4c = 0.0f;
  local_48 = 0.0f;
  FUN_00917cd0(local_38, local_44, &local_50, local_20);
  if ((local_48 * local_48 + local_50 * local_50 + local_4c * local_4c < _DAT_00a240ec) &&
     (DAT_00d1b6d8 != 0)) {
    uVar3 = (*(uint32_t (**)(void))(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +
                        0x1a0))();
    pfVar4 = (float *)FUN_004e88e0(local_2c, uVar3);
    local_50 = *pfVar4;
    local_4c = pfVar4[1] + DAT_00aaa690;
    local_48 = pfVar4[2];
  }
  if (*(char *)(DAT_00d1b644 + 0xf5) == '\0') {
    local_4c = local_4c + DAT_00aaa68c;
  }
  cVar2 = FUN_00917700();
  if (cVar2 == '\0') {
    return;
  }
  FUN_009141e0();
  fStack_58 = (float)in_EAX[0x14b];
  fStack_54 = fStack_58;
  if ((char)in_EAX[0x338] == '\0') {
    fStack_54 = (float)in_EAX[0x333] * (float)in_EAX[0x14a];
    fStack_58 = (float)in_EAX[0x334] * (float)in_EAX[0x14a];
  }
  switch (in_EAX[0x331]) {
  case 1:
    FUN_00914930(local_50, local_4c, local_48, fStack_58);
    break;
  case 2:
  case 5:
  case 7:
    FUN_0091b1c0(local_50, local_4c, local_48, fStack_54, fStack_58);
    break;
  case 3:
    FUN_00914980(local_50, local_4c, local_48, fStack_54, fStack_58);
    break;
  default:
    FUN_009168d0(in_EAX, &local_50, fStack_54, fStack_58, param_1);
    break;
  case 8:
    FUN_0091c220(local_50, local_4c, local_48, param_1, 0.0f, DAT_00aaa668, 0.0f);
  }
  iVar1 = DAT_00d17944;
  fVar7 = DAT_00a10e78;
  iVar5 = in_EAX[0x331];
  if ((iVar5 == 4) || (iVar5 == 5)) {
    fVar6 = (fStack_54 - (float)in_EAX[0x149]) / ((float)in_EAX[0x14a] - (float)in_EAX[0x149]);
    *(float *)(DAT_00d17944 + 0x22c) = (fVar6 + DAT_00a0f720) * fStack_54 + local_4c;
    if (fVar6 < fVar7) {
      fVar6 = fVar7;
    }
    *(float *)(iVar1 + 0x21c) = local_50 - *(float *)(iVar1 + 0x228);
    *(float *)(iVar1 + 0x220) = *(float *)(iVar1 + 0x22c) * fVar6 * DAT_00aaa668;
  }
  else {
    if (iVar5 == 8) goto LAB_0091d1dd;
    *(float *)(DAT_00d17944 + 0x21c) = local_50 - *(float *)(DAT_00d17944 + 0x228);
    *(float *)(iVar1 + 0x220) = local_4c - *(float *)(iVar1 + 0x22c);
  }
  *(float *)(iVar1 + 0x224) = local_48 - *(float *)(iVar1 + 0x230);
LAB_0091d1dd:
  _DAT_00d20c4c = DAT_00afe290;
  if (*(char *)(DAT_00d1b644 + 0xf5) == '\0') {
    _DAT_00d20c4c = DAT_00afe28c;
  }
  local_48 = local_48 - *(float *)(iVar1 + 0x230);
  local_4c = local_4c - *(float *)(iVar1 + 0x22c);
  local_50 = local_50 - *(float *)(iVar1 + 0x228);
  fStack_54 = SQRT(local_50 * local_50 + local_4c * local_4c + local_48 * local_48) - DAT_00afe288;
  fVar7 = _DAT_00d20c4c;
  if (_DAT_00d20c4c <= fStack_54) {
    fVar7 = fStack_54;
  }
  if (DAT_00afe288 <= fVar7) {
    fStack_54 = DAT_00afe288;
  }
  else if (fStack_54 < _DAT_00d20c4c) {
    fStack_54 = _DAT_00d20c4c;
  }
  iVar5 = (*(int (**)(void))(*in_EAX + 0x1a0))();
  if (fStack_54 != *(float *)(iVar5 + 0xf0)) {
    iVar5 = (*(int (**)(void))(*in_EAX + 0x1a0))();
    *(float *)(iVar5 + 0xf0) = fStack_54;
    *(uint8_t *)(iVar5 + 0x48) = 1;
    *(uint8_t *)(iVar5 + 0xcc) = 1;
  }
  if (((*(char *)((int)in_EAX + 0xa81) != '\x02') && (*(char *)((int)in_EAX + 0xa81) != '\x03')) ||
     (in_EAX[0x331] != 8)) {
    D3DXVec3Normalize((void *)(DAT_00d17944 + 0x21c), (void *)(DAT_00d17944 + 0x21c));
    FUN_0090e1b0(0.0f, DAT_00aaa668, 0.0f);
    D3DXVec3Normalize((void *)(DAT_00d17944 + 0x21c), (void *)(DAT_00d17944 + 0x21c));
    FUN_0091b0d0();
  }
  if (((DAT_00d1b0ac != '\0') && (DAT_00d1b6d8 != 0)) &&
     ((*(int *)(DAT_00d1b6d8 + 0x250) != 0 &&
      (iVar5 = *(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 8), iVar5 != 0)))) {
    iVar5 = *(int *)(iVar5 + 0x3c);
    fVar7 = g_flOne - (DAT_00d1b0a8 -
                      (SQRT(*(float *)(iVar5 + 0x40) * *(float *)(iVar5 + 0x40) +
                            *(float *)(iVar5 + 0x44) * *(float *)(iVar5 + 0x44) +
                            *(float *)(iVar5 + 0x48) * *(float *)(iVar5 + 0x48)) - _DAT_00d1b0a4)) /
                      DAT_00d1b0a8;
    if ((g_flOne <= fVar7) || (0.0f < fVar7)) {
      if (g_flOne <= fVar7) {
        fVar7 = g_flOne;
      }
    }
    else {
      fVar7 = 0.0f;
    }
    iVar5 = *(int *)(*(int *)(DAT_00d1b644 + 0xe894) + 0xc0);
    *(float *)(iVar5 + 0x10c) =
         ((DAT_00d1b0a0 - DAT_00d1b09c) * fVar7 + DAT_00d1b09c) * DAT_00a27c54;
    *(uint8_t *)(iVar5 + 0x48) = 1;
    *(uint8_t *)(iVar5 + 0xcc) = 1;
  }
  return;
}
