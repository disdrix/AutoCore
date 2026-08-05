// =============================================================================
// FUN_0090dd50  (alias plate → ClientCamera_ApplyModeDistanceBand)
// -----------------------------------------------------------------------------
// Stable ID: aa_0090dd50
// Address:   0x0090dd50
// See:       reconstructed-exact/ClientCamera_ApplyModeDistanceBand.cpp
// Dual A/B:  2026-07-29 W17-H
// =============================================================================

// Prefer ClientCamera_ApplyModeDistanceBand / ClientCamera_ApplyModeDistanceBand_On.
// Body below matches raw decompiler CF with sealed float constants.

extern float _DAT_00af9150;
extern float DAT_00af9154;
extern float DAT_00af9158;
extern float DAT_00af915c;
extern float DAT_00af9160;
extern float DAT_00af9164;
extern float DAT_00af9168;
extern float DAT_00af916c;
extern float DAT_00af9170;
extern float DAT_00a0f298;
extern float g_flOne;
extern char DAT_00d1b26c;
extern int DAT_00d1b6d8;

void FUN_0090dd50(void)
{
  undefined4 uVar1;
  int in_EAX;
  float fVar2;
  float fVar3;
  float fVar4;

  if (*(int *)(in_EAX + 0x60c) == 0) {
    *(undefined4 *)(in_EAX + 0x524) = DAT_00af9154; /* 2.0f */
    fVar2 = DAT_00af915c; /* 16.0f */
    if (DAT_00d1b26c == '\0') {
      fVar2 = DAT_00af9158; /* 11.0f */
    }
    fVar4 = g_flOne / _DAT_00af9150; /* 1/16 */
    *(float *)(in_EAX + 0x528) = fVar2;
    *(float *)(in_EAX + 0x534) = (fVar2 - *(float *)(in_EAX + 0x524)) * fVar4;
    if ((DAT_00d1b6d8 != 0) && (*(char *)(DAT_00d1b6d8 + 0x6b9) != '\0')) {
      fVar2 = DAT_00af9168; /* 30.0f */
      if (DAT_00d1b26c == '\0') {
        fVar2 = DAT_00af9164; /* 20.0f */
      }
      fVar2 = fVar2 - DAT_00af9160; /* -6 */
      fVar3 = fVar2 * DAT_00a0f298; /* *0.5 */
      *(float *)(in_EAX + 0x52c) = fVar3;
      *(float *)(in_EAX + 0x530) = fVar2 * fVar4 + fVar3;
    }
  }
  else {
    if (*(int *)(in_EAX + 0x60c) == 1) {
      *(float *)(in_EAX + 0x524) = DAT_00af9160; /* 6.0f */
      fVar2 = DAT_00af9168; /* 30.0f */
      if (DAT_00d1b26c == '\0') {
        fVar2 = DAT_00af9164; /* 20.0f */
      }
      *(float *)(in_EAX + 0x528) = fVar2;
    }
    else {
      *(undefined4 *)(in_EAX + 0x524) = DAT_00af916c; /* 12.0f */
      uVar1 = DAT_00af9170; /* 20.0f */
      *(undefined4 *)(in_EAX + 0x528) = DAT_00af9170;
      *(undefined4 *)(in_EAX + 0x530) = uVar1;
      *(undefined4 *)(in_EAX + 0x52c) = uVar1;
    }
    *(float *)(in_EAX + 0x534) =
         (*(float *)(in_EAX + 0x528) - *(float *)(in_EAX + 0x524)) / _DAT_00af9150;
  }
  /* clamp +0x530 into [+0x524, +0x528] */
  if (*(float *)(in_EAX + 0x530) < *(float *)(in_EAX + 0x528) ||
      *(float *)(in_EAX + 0x530) == *(float *)(in_EAX + 0x528)) {
    if (*(float *)(in_EAX + 0x530) <= *(float *)(in_EAX + 0x524) &&
        *(float *)(in_EAX + 0x524) != *(float *)(in_EAX + 0x530)) {
      *(undefined4 *)(in_EAX + 0x530) = *(undefined4 *)(in_EAX + 0x524);
    }
  }
  else {
    *(undefined4 *)(in_EAX + 0x530) = *(undefined4 *)(in_EAX + 0x528);
  }
  /* clamp +0x52c into [+0x524, +0x528] */
  if (*(float *)(in_EAX + 0x528) <= *(float *)(in_EAX + 0x52c) &&
      *(float *)(in_EAX + 0x52c) != *(float *)(in_EAX + 0x528)) {
    *(undefined4 *)(in_EAX + 0x52c) = *(undefined4 *)(in_EAX + 0x528);
    return;
  }
  if (*(float *)(in_EAX + 0x52c) <= *(float *)(in_EAX + 0x524) &&
      *(float *)(in_EAX + 0x524) != *(float *)(in_EAX + 0x52c)) {
    *(undefined4 *)(in_EAX + 0x52c) = *(undefined4 *)(in_EAX + 0x524);
  }
  return;
}
