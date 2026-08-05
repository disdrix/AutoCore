// =============================================================================
// FUN_008e4430  (twin of UI_FormatObjectDifficultyTier_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_008e4430
// Address:   0x008e4430  (autoassault.exe, image base 0x400000)
// Body:      0x008e4430–0x008e4726 (758 B)
// System:    client mission / target UI difficulty
// Generated: 2026-07-29 W29-J OWN dual (refined from 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler CF + byte ABI fix.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <stdint.h>
#include <stdio.h>

extern uint8_t *DAT_00d1b6d8;
extern float DAT_00aaa954, DAT_00aaa950, DAT_00a0f524, DAT_00a0f694, g_flZero, DAT_00aaa6f8;
extern float DAT_00d1b424[4], DAT_00d1b434[4], DAT_00d1b444[4];
extern float DAT_00d1b454[4], DAT_00d1b464[4], DAT_00d1b474[4], DAT_00d1b484[4];

extern int FUN_0052ada0(int resourceKey);
extern float FUN_0052b080(void *character /*ecx*/, void *target);
extern void *FUN_007a69d0(void);
extern const char *FUN_007a6de0(void *locale /*ecx*/, const char *key, int lang);
extern void FUN_00973590(float a, float b, float c, float d);
extern void FUN_00973820(uint8_t *dest /*ecx*/, const float *src);

// Image ABI: EAX=target, ESI=textBuf|null, stack uint32_t* out; plain ret.
// Decompiler always-*out=-1 tail rejected; success stores packed color.
void FUN_008e4430(void *target /*eax*/, char *textBuf /*esi*/, uint32_t *outPackedColor)
{
  uint8_t packed[4] = {0xFF, 0xFF, 0xFF, 0xFF};
  const char *label = 0;
  int required = 0;

  if (target == 0 || DAT_00d1b6d8 == 0) {
    *outPackedColor = 0xFFFFFFFFu;
    return;
  }

  int *objA8 = *(int **)((uint8_t *)target + 0xa8);
  int *clone = *(int **)((uint8_t *)objA8 + 0x3c);
  required = *(int *)((uint8_t *)clone + 0x4b0);
  int playerVal = FUN_0052ada0(*(int *)((uint8_t *)clone + 0x4ac));
  float score = FUN_0052b080(DAT_00d1b6d8, target);
  void *locale = FUN_007a69d0();

  if (playerVal < required) {
    // Image: mov eax, &packed; call FUN_00973590(palette*255) — EAX dest.
    float s = DAT_00aaa6f8;
    (void)packed;
    FUN_00973590(DAT_00d1b484[0] * s, DAT_00d1b484[1] * s,
                 DAT_00d1b484[2] * s, DAT_00d1b484[3] * s);
    label = "Impossible";
  } else if (score > DAT_00aaa954) {
    FUN_00973820(packed, DAT_00d1b474);
    label = "Very Hard";
  } else if (score > DAT_00aaa950) {
    FUN_00973820(packed, DAT_00d1b464);
    label = "Hard";
  } else if (score > DAT_00a0f524) {
    FUN_00973820(packed, DAT_00d1b454);
    label = "Moderate";
  } else if (score > DAT_00a0f694) {
    FUN_00973820(packed, DAT_00d1b444);
    label = "Easy";
  } else if (score > g_flZero) {
    FUN_00973820(packed, DAT_00d1b434);
    label = "Trivial";
  } else {
    FUN_00973820(packed, DAT_00d1b424);
    label = "Trivial";
  }

  if (textBuf != 0) {
    const char *loc = FUN_007a6de0(locale, label, -1);
    sprintf(textBuf, "%s: %d", loc, required);
  }

  *outPackedColor = *(uint32_t *)packed;
}
