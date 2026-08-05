// =============================================================================
// Object_ApplyFxWithTargetBind_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Vtbl method: resolve/apply FX (full nfx or light ensure), set flag
//           bit 2, optionally bind target TFID+offset, attach via vtbl+0xf8,
//           post via FUN_004b7e50.
//
// Address:  0x00512d10  (autoassault.exe, image base 0x400000)
// Body:     0x00512d10–0x00512ead (~413 bytes)
// Stable:   aa_00512d10
// System:   client-fx / skills-abilities
// Ghidra:   FUN_00512d10
//
// ABI:      __thiscall  ret 0x20  (8 stack args)
// Exactness: CF mirrors raw + selected read_memory sites; fixed-width types.
//            Decompiler under-models some thiscall ECX for FX callees — machine
//            uses ESI/param_9 as FX this for 004b68c0 / 004b7e50.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W21-A seal).
// =============================================================================

#include <cstdint>

extern "C" uint32_t *DAT_00d1f050;   // subsystem host pointer
extern "C" void *DAT_00b041fc;      // FxCache apply host
extern "C" float DAT_00aaa5dc;      // 2^32 = 4294967296.0f @ 0x00aaa5dc

// Dual-sealed callees (not owned here)
extern "C" uint32_t __thiscall FxCache_ApplyWithNfxEnsure(
    void *host, uint32_t a, uint32_t b, uint32_t c, uint32_t d,
    int *target, void *applyObj, int offsetComp);
extern "C" uint32_t *__thiscall FxCache_EnsureMasterAndResolve(
    void *host, uint32_t a, uint32_t b, uint32_t mode);
extern "C" void __thiscall NDSpecialFX_SetTargetTfidAndOffset_Inferred(
    void *fx, uint32_t t0, uint32_t t1, uint32_t t2, uint32_t t3, float *offset4);
extern "C" void __thiscall FUN_004b7e50(
    void *fx, char a, int b, uint8_t *c, float d, float e, float f);

// Ghidra FUN aliases used in body
#define FUN_00542790 FxCache_ApplyWithNfxEnsure
#define FUN_005408f0 FxCache_EnsureMasterAndResolve
#define FUN_004b68c0 NDSpecialFX_SetTargetTfidAndOffset_Inferred

/* Object_ApplyFxWithTargetBind_Inferred

   Returns: 1 on light-path success; 0 on resolve fail; or full-apply result. */

uint32_t __thiscall Object_ApplyFxWithTargetBind_Inferred(
    int *thisObj,
    uint32_t param_2,
    uint32_t param_3,
    uint32_t param_4,
    uint32_t param_5,
    int *pTargetEntity,
    int offsetComponent,
    char skipFullNfx,
    uint32_t *pFxInOut)
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

  if ((skipFullNfx == '\0') && (*(int *)((char *)DAT_00d1f050 + 0x6c) != 0)) {
    if (pFxInOut == nullptr) {
      // machine tail: ECX = *DAT_00b041fc (host), not thisObj
      uVar3 = FUN_00542790(
          DAT_00b041fc, param_3, param_2, param_4, param_5,
          pTargetEntity, thisObj, offsetComponent);
      return uVar3;
    }
  }
  else {
    if (pFxInOut != nullptr) {
      goto LAB_apply;
    }
    pFxInOut = FUN_005408f0(DAT_00b041fc, param_3, param_2, 1);
  }
  if (pFxInOut == nullptr) {
    return 0;
  }

LAB_apply:
  *pFxInOut = *pFxInOut | 2u;

  if (pTargetEntity != nullptr) {
    iVar2 = (*(int (__thiscall **)(int *))(*pTargetEntity + 0x19c))(pTargetEntity);
    // FILD unsigned path: float(offsetComponent) with +2^32 if signed-negative
    fStack_18 = (float)offsetComponent;
    uStack_1c = 0;
    uStack_20 = 0;
    if (iVar2 == 0) {
      if (offsetComponent < 0) {
        fStack_18 = fStack_18 + DAT_00aaa5dc; // 2^32
      }
      // entity TFID_16 at +0x160
      iVar2 = pTargetEntity[0x58];
      iVar4 = pTargetEntity[0x59];
      iVar5 = pTargetEntity[0x5a];
      iVar6 = pTargetEntity[0x5b];
    }
    else {
      if (offsetComponent < 0) {
        fStack_18 = fStack_18 + DAT_00aaa5dc;
      }
      // nested object TFID at adj+0x164
      piVar1 = (int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0x164 + iVar2);
      iVar2 = *piVar1;
      iVar4 = piVar1[1];
      iVar5 = piVar1[2];
      iVar6 = piVar1[3];
    }
    uStack_14 = 0;
    // machine: ECX = pFxInOut
    FUN_004b68c0(pFxInOut, iVar2, iVar4, iVar5, iVar6,
                 reinterpret_cast<float *>(&uStack_20));
  }

  iVar2 = (*(int (__thiscall **)(int *))(*thisObj + 0x19c))(thisObj);
  if (iVar2 == 0) {
    (*(void (__thiscall **)(int *, uint32_t *, int, int))(*thisObj + 0xf8))(
        thisObj, pFxInOut, 1, 0);
  }
  else {
    // Nested attach: vtbl+0xf8 on adjusted object (arg packing residual vs decompiler)
    int *nested = (int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2);
    (*(void (__thiscall **)(int *))(*nested + 0xf8))(nested);
  }

  // machine: ECX = pFxInOut; six zero stack args
  FUN_004b7e50(pFxInOut, 0, 0, nullptr, 0.0f, 0.0f, 0.0f);
  return 1;
}

// Ghidra alias
extern "C" uint32_t __thiscall FUN_00512d10(
    int *param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4,
    uint32_t param_5, int *param_6, int param_7, char param_8, uint32_t *param_9)
{
  return Object_ApplyFxWithTargetBind_Inferred(
      param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9);
}
