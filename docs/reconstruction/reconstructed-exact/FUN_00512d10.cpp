// =============================================================================
// FUN_00512d10 — scaffold alias → Object_ApplyFxWithTargetBind_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00512d10
// Address:   0x00512d10
// Canonical: Object_ApplyFxWithTargetBind_Inferred
//            (see Object_ApplyFxWithTargetBind_Inferred.cpp for authoritative clean)
// Dual A/B:  accept-with-gaps (2026-07-29 W21-A)
// =============================================================================

#include <cstdint>

extern "C" uint32_t *DAT_00d1f050;
extern "C" void *DAT_00b041fc;
extern "C" float DAT_00aaa5dc;

extern "C" uint32_t __thiscall FUN_00542790(
    void *host, uint32_t a, uint32_t b, uint32_t c, uint32_t d,
    int *target, void *applyObj, int offsetComp);
extern "C" uint32_t *__thiscall FUN_005408f0(
    void *host, uint32_t a, uint32_t b, uint32_t mode);
extern "C" void __thiscall FUN_004b68c0(
    void *fx, uint32_t t0, uint32_t t1, uint32_t t2, uint32_t t3, float *offset4);
extern "C" void __thiscall FUN_004b7e50(
    void *fx, char a, int b, uint8_t *c, float d, float e, float f);

extern "C" uint32_t __thiscall FUN_00512d10(
    int *param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4,
    uint32_t param_5, int *param_6, int param_7, char param_8, uint32_t *param_9)
{
  int *piVar1;
  int iVar2;
  uint32_t uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint32_t uStack_20;
  uint32_t uStack_1c;
  float fStack_18;
  uint32_t uStack_14;

  if ((param_8 == '\0') && (*(int *)((char *)DAT_00d1f050 + 0x6c) != 0)) {
    if (param_9 == nullptr) {
      uVar3 = FUN_00542790(
          DAT_00b041fc, param_3, param_2, param_4, param_5, param_6, param_1, param_7);
      return uVar3;
    }
  }
  else {
    if (param_9 != nullptr) {
      goto LAB_00512d62;
    }
    param_9 = FUN_005408f0(DAT_00b041fc, param_3, param_2, 1);
  }
  if (param_9 == nullptr) {
    return 0;
  }
LAB_00512d62:
  *param_9 = *param_9 | 2u;
  if (param_6 != nullptr) {
    iVar2 = (*(int (__thiscall **)(int *))(*param_6 + 0x19c))(param_6);
    fStack_18 = (float)param_7;
    uStack_1c = 0;
    uStack_20 = 0;
    if (iVar2 == 0) {
      if (param_7 < 0) {
        fStack_18 = fStack_18 + DAT_00aaa5dc;
      }
      iVar2 = param_6[0x58];
      iVar4 = param_6[0x59];
      iVar5 = param_6[0x5a];
      iVar6 = param_6[0x5b];
    }
    else {
      if (param_7 < 0) {
        fStack_18 = fStack_18 + DAT_00aaa5dc;
      }
      piVar1 = (int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0x164 + iVar2);
      iVar2 = *piVar1;
      iVar4 = piVar1[1];
      iVar5 = piVar1[2];
      iVar6 = piVar1[3];
    }
    uStack_14 = 0;
    FUN_004b68c0(param_9, iVar2, iVar4, iVar5, iVar6,
                 reinterpret_cast<float *>(&uStack_20));
  }
  iVar2 = (*(int (__thiscall **)(int *))(*param_1 + 0x19c))(param_1);
  if (iVar2 == 0) {
    (*(void (__thiscall **)(int *, uint32_t *, int, int))(*param_1 + 0xf8))(
        param_1, param_9, 1, 0);
  }
  else {
    int *nested = (int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2);
    (*(void (__thiscall **)(int *))(*nested + 0xf8))(nested);
  }
  FUN_004b7e50(param_9, 0, 0, nullptr, 0.0f, 0.0f, 0.0f);
  return 1;
}
