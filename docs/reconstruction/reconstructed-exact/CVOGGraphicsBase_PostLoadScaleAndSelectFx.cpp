// =============================================================================
// CVOGGraphicsBase_PostLoadScaleAndSelectFx
// -----------------------------------------------------------------------------
// Stable ID: aa_00585e00
// Address:   0x00585e00 – 0x00586056 (599 B inclusive last RET)
// Module:    autoassault.exe base 0x400000
// System:    client / graphics / select-fx / LogicUI
// Generated: 2026-07-29 W26-N dual seal (live decompile ≡ raw 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// =============================================================================
//
// PURPOSE: After CVOGGraphicsBase::InitializeGraphics loads an asset (flag bit0
//   at object+0x188), apply reciprocal mesh scale, feed world position into the
//   graphics object (vtbl+0x10 mode 3), optionally play near-range pickup SpecialFX
//   and emit LogicUI packet type 0x1F.
//
// Convention: MSVC __thiscall
//   this        CVOGGraphicsBase* (ECX); graphics object at this+8
//   skipSideFx  char stack (non-zero skips FX + LogicUI); RET 4
//   return      x87 ST0 float (scale); early-out ST0 = 0.0f
//
// Constants (read_memory 2026-07-29):
//   0x00a10e74 = 2.0f  (cancels in base/(s*base) → 1/s)  [Ghidra: g_flLevelUpUiBase_Inferred]
//   0x00a0f298 = 0.5f  (scratch intermediate)
//   0x00a0f524 = 50.0f near-distance gate
//   0x009da8a4 = 3.5f  LogicUI payload
//   0x00a0f518 = 0.0f  g_flZero
//
// Dual A/B: reviews/A_aa_00585e00_*.md + B_aa_00585e00_*.md (W26-N)
// =============================================================================

#include <stdint.h>

// Ghidra labels retained where product English is open.
extern float g_flLevelUpUiBase_Inferred; // 0x00a10e74 = 2.0f (misnomer residual)
extern float DAT_00a0f298;               // 0.5f
extern float DAT_00a0f524;               // 50.0f
extern float _DAT_009da8a4;              // 3.5f
extern float g_flZero;                   // 0x00a0f518

extern char FUN_005130e0(int arg); // thiscall ECX=MI composite (see bytes LEA)
extern float *FUN_004e88e0(void *out, void *in_vec4);
extern void FUN_0040cf90(uint32_t mode);
extern float FUN_00404bd0(void *vec);
extern uint32_t FUN_00516c40(int obj); // thiscall
// FUN_0051aed0 — dual-sealed Object_PlayPickupSpecialFX (thiscall, RET 8)
extern void Object_PlayPickupSpecialFX(char bPlayAudio, char bForceQuestFx);
extern void Client_SendLogicUiPacket(void *packet);

// float10 modeled as float for port readability; retail returns on x87 ST0.
float __thiscall CVOGGraphicsBase_PostLoadScaleAndSelectFx(int this_obj, char skipSideFx)
{
  int *piVar1;
  char cVar2;
  int iVar3;
  float *pfVar4;
  uint32_t *puVar5;
  int iVar6;
  float fVar7;
  float fVar9;
  uint32_t uVar10;
  float fStack_190;
  float fStack_18c;
  float fStack_188;
  uint32_t uStack_184;
  float fStack_180;
  uint32_t uStack_17c;
  uint32_t uStack_178;
  uint32_t uStack_174;
  uint32_t uStack_170;
  uint32_t uStack_16c;
  uint8_t auStack_15c[4];
  uint8_t auStack_158[8];
  uint8_t auStack_150[12];
  uint32_t uStack_144;
  uint32_t uStack_134;
  uint32_t uStack_128;
  uint32_t uStack_124;
  uint32_t uStack_120;
  uint32_t uStack_11c;

  if ((*(int *)(this_obj + 8) != 0) && (cVar2 = FUN_005130e0(1), cVar2 != '\0')) {
    iVar3 = (**(int (**)(void))(**(int **)(this_obj + 8) + 0x48))();
    // sealed: 2.0/(s*2.0) == 1/s  (g_flLevelUpUiBase_Inferred @ 0x00a10e74 = 2.0f)
    fVar9 = g_flLevelUpUiBase_Inferred /
            (*(float *)(iVar3 + 0xc) * g_flLevelUpUiBase_Inferred);
    fStack_190 = fVar9 * DAT_00a0f298;
    (**(void (**)(float))(*(int *)(*(int *)(*(int *)(this_obj + 4) + 4) + 4 + this_obj) + 0xb8))(
        fVar9);
    iVar3 = *(int *)(*(int *)(this_obj + 4) + 4);
    uStack_184 = *(uint32_t *)(iVar3 + 0x84 + this_obj);
    iVar3 = iVar3 + 0x84 + this_obj;
    uStack_17c = *(uint32_t *)(iVar3 + 8);
    fStack_180 = *(float *)(iVar3 + 4) + fVar9;
    uStack_178 = *(uint32_t *)(iVar3 + 0xc);
    pfVar4 = (float *)FUN_004e88e0(auStack_158, &uStack_184);
    fStack_190 = *pfVar4;
    fStack_18c = pfVar4[1];
    fStack_188 = pfVar4[2];
    uVar10 = 3;
    (**(void (**)(uint32_t, float *))(**(int **)(this_obj + 8) + 0x10))(3, &fStack_190);
    FUN_0040cf90(uVar10);
    if (skipSideFx == '\0') {
      iVar3 = *(int *)(*(int *)(*(int *)(this_obj + 4) + 4) + 0xa8 + this_obj);
      if (((iVar3 != 0) && (piVar1 = *(int **)(iVar3 + 0xe8a0), piVar1 != (int *)0x0)) &&
          (iVar3 = (**(int (**)(void))(*piVar1 + 0x1dc))(), *(int *)(iVar3 + 0x250) != 0)) {
        puVar5 = (uint32_t *)(
            **(int (**)(void))(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 0x1a0))();
        uStack_178 = *puVar5;
        uStack_174 = puVar5[1];
        uStack_170 = puVar5[2];
        uStack_16c = puVar5[3];
        FUN_004e88e0(auStack_15c, &uStack_178);
        fVar7 = FUN_00404bd0(auStack_15c);
        uVar10 = FUN_00516c40(iVar3);
        // thiscall ECX=object (iVar3 path); stack (distNear, flag) — see W25-J dual
        Object_PlayPickupSpecialFX((char)(fVar7 < DAT_00a0f524), (char)uVar10);
      }
      iVar3 = *(int *)(*(int *)(this_obj + 4) + 4);
      iVar6 = iVar3 + this_obj;
      if (*(int *)(iVar3 + 0xa8 + this_obj) != 0) {
        uStack_128 = *(uint32_t *)(iVar6 + 0x164);
        uStack_124 = *(uint32_t *)(iVar6 + 0x168);
        uStack_120 = *(uint32_t *)(iVar6 + 0x16c);
        uStack_11c = *(uint32_t *)(iVar6 + 0x170);
        uStack_134 = 0x1f;
        uStack_144 = *(uint32_t *)&_DAT_009da8a4;
        Client_SendLogicUiPacket(auStack_150);
      }
    }
    return fVar9;
  }
  return g_flZero;
}
