// =============================================================================
// FUN_0099e6c0  (clean twin of PalVisibleBoundingShape_EffectMaterialInit_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0099e6c0
// Address:   0x0099e6c0  (autoassault.exe, image base 0x400000)
// Body:      0x0099e6c0–0x0099e894 (469 B)
// System:    mesh host FX / material init
// Generated: 2026-07-29 W36-H dual seal
// Exactness: Behavior-preserving; ECX this; returns status OR.
// Named twin: PalVisibleBoundingShape_EffectMaterialInit_Inferred.cpp
// =============================================================================

/*
 * ECX = mesh host (after FUN_00748960 + dual-vtbl override).
 * See named twin for full material-bind factoring.
 */

#include <stdint.h>

extern void *ExceptionList;
extern void *LAB_009b2d4b;
extern float g_flOne;
extern uint32_t DAT_00d1a6c0;
extern uint32_t DAT_00d1a6c4;
extern uint32_t DAT_00d1a6c8;

extern void FUN_00989e00(void *out, const char *path);
extern uint32_t FUN_009701d0(void *fx_name_obj);
extern void FUN_0098ef00(void *tmp);
extern void FUN_0098f2b0(int n);
extern uint32_t FUN_00749d10(void *tmp);
extern int *FUN_00752370(void *out, const char *param_name);
extern uint32_t FUN_0096fff0(int *res_slot, int param_index);
extern int *FUN_0073d940(int handle);
extern void FUN_00457a00(void *tmp);

uint32_t __fastcall FUN_0099e6c0(int param_1 /* ECX */)
{
  int local_68;
  uint8_t local_64[4], local_60[4], local_5c[4], local_58[4];
  uint8_t local_54[48];
  uint32_t local_24, local_20, local_1c;
  float local_18;
  void *pvStack_c;
  void *puStack_8;
  uint32_t local_4;
  int *piVar1;
  int *piVar6;
  uint32_t uVar4, uVar5, uVar7, uVar8, uVar9, uVar10;

  local_4 = 0xFFFFFFFFu;
  puStack_8 = &LAB_009b2d4b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;

  FUN_00989e00(&local_68, "PalVisibleBoundingShape.fx");
  piVar1 = (int *)(param_1 + 0x20);
  uVar4 = FUN_009701d0(&local_68);
  FUN_0098ef00(local_54);
  local_4 = 0;
  local_24 = DAT_00d1a6c0;
  local_20 = DAT_00d1a6c4;
  local_1c = DAT_00d1a6c8;
  local_18 = g_flOne;
  FUN_0098f2b0(200);
  uVar5 = FUN_00749d10(local_54);

  if (*piVar1 == 0) { local_68 = -1; piVar6 = &local_68; }
  else { piVar6 = FUN_00752370(local_64, "SolidMatDiffuse"); }
  uVar7 = (*piVar6 < 0) ? 0xFFFFFFFFu : FUN_0096fff0(piVar1, *piVar6);

  if (*piVar1 == 0) { local_68 = -1; piVar6 = &local_68; }
  else { piVar6 = FUN_00752370(local_60, "SolidMatEmissive"); }
  uVar8 = (*piVar6 < 0) ? 0xFFFFFFFFu : FUN_0096fff0(piVar1, *piVar6);

  if (*piVar1 == 0) { local_68 = -1; piVar6 = &local_68; }
  else { piVar6 = FUN_00752370(local_5c, "WireMatDiffuse"); }
  uVar9 = (*piVar6 < 0) ? 0xFFFFFFFFu : FUN_0096fff0(piVar1, *piVar6);

  if (*piVar1 == 0) { local_68 = -1; piVar6 = &local_68; }
  else { piVar6 = FUN_00752370(local_58, "WireMatEmissive"); }
  uVar10 = (*piVar6 < 0) ? 0xFFFFFFFFu : FUN_0096fff0(piVar1, *piVar6);

  piVar6 = FUN_0073d940(*piVar1);
  if (piVar6 != 0) {
    piVar6[1] = piVar6[1] + 1;
    if (piVar6[1] == 1) {
      ((void (*)(void))(*(void **)*piVar6)[1])();
    }
    {
      int *old = (int *)*piVar1;
      if (old != 0) {
        old[1] = old[1] - 1;
        if (old[1] == 0) {
          ((void (*)(void))(*(void **)*old)[2])();
        }
      }
    }
    *piVar1 = (int)(uintptr_t)piVar6;
  }

  local_4 = 0xFFFFFFFFu;
  FUN_00457a00(local_54);
  ExceptionList = pvStack_c;
  return uVar4 | uVar5 | uVar7 | uVar8 | uVar9 | uVar10;
}
