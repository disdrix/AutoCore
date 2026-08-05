// =============================================================================
// GfxView_UnprojectScreenToWorldRay_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0075c340
// Address:   0x0075c340  (autoassault.exe, image base 0x400000)
// System:    input-drive-control (secondary camera / pick ray)
// Generated: 2026-07-29 dual A/B refine from live Ghidra decompile
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE:
//   gfxView method: integer screen pixel (x,y) → world ray.
//   - outWorldNear (param_3): world-space point of camera-local near-plane sample
//   - outWorldDir  (param_4): unit world direction (mode 0 / perspective)
//                            or basis triple at +0x20 (mode 1 / ortho)
//   Sibling FUN_0075b7f0 (projection ensure) carries path string
//   C:\vog\1_code\palantir\palantir\graphics\gfxView.cpp
//
// Callers include Client_Input_DriveControlTick (×3) and Client_InteractClickPickTarget.
// Does NOT write vehicle drive axes (+0x614 / +0x618 / +0x61c).
//
// Constants (read_memory 2026-07-29):
//   g_flOne @ 0x00a0f2a0              = 1.0  (LE 00 00 80 3f)
//   g_flLevelUpUiBase_Inferred @ 0x00a10e74 = 2.0  (LE 00 00 00 40)  // NDC scale; name misnomer

// READABILITY:
//  - Control keywords: if×4, return×3 (matches raw).
//  - Callees: FUN_0075b7f0, FUN_00972fa0, FUN_0076f5f0, FUN_00972e50, FUN_009729d0.
//  - CF must remain ≡ raw/live decompile.

/*
 * Behavioral notes:
 * - NDC: (pixel / viewport) * 2 - 1; Y flipped when building local.y.
 * - Always calls FUN_0075b7f0 to refresh +0xf8/+0xfc near extents when projection dirty.
 * - Mode this+0xec: 0 = perspective dir path; 1 = ortho basis triple; else param_4 untouched.
 * - Dirty bit (*(this+8)+0xbc & 1) triggers FUN_00972e50 before using basis.
 * - Runtime / differential verification: OPEN.
 */

// External symbols (Ghidra names preserved where not dualed)
extern float g_flLevelUpUiBase_Inferred; // 2.0 @ 0x00a10e74
extern float g_flOne;                    // 1.0 @ 0x00a0f2a0
extern void FUN_0075b7f0(void);          // EnsureProjection / rebuild near extents (thiscall)
extern void *FUN_00972fa0(float *local); // Transform local point → world (register-arg messy)
extern float *FUN_0076f5f0(float *dst, float *src); // Normalize3
extern int FUN_00972e50(void);           // Rebuild dirty basis (thiscall on basis)
extern void FUN_009729d0(float *dir);    // Transform direction by camera basis

void __thiscall GfxView_UnprojectScreenToWorldRay_Inferred(
    int param_1,              // this = gfxView*
    int *param_2,             // screenXY[2]
    unsigned int *param_3,    // outWorldNear as 3×u32/f32
    float *param_4)           // outWorldDir / ortho triple
{
  unsigned int *puVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float local_18;
  float local_14;
  float local_10;

  // pixel → NDC [-1,1]
  fVar3 = ((float)*param_2 / (float)*(int *)(param_1 + 0xdc)) * g_flLevelUpUiBase_Inferred - g_flOne;
  fVar4 = ((float)param_2[1] / (float)*(int *)(param_1 + 0xe0)) * g_flLevelUpUiBase_Inferred -
          g_flOne;

  FUN_0075b7f0(); // this still in ECX

  // camera-local near-plane point (Y flipped)
  local_18 = *(float *)(param_1 + 0xf8) * fVar3;
  local_14 = *(float *)(param_1 + 0xfc) * (0.0 - fVar4);
  local_10 = *(float *)(param_1 + 0xf0);

  // world near point
  puVar1 = (unsigned int *)FUN_00972fa0(&local_18);
  *param_3 = *puVar1;
  param_3[1] = puVar1[1];
  param_3[2] = puVar1[2];

  if (*(int *)(param_1 + 0xec) == 0) {
    // perspective: unit world direction from local ray
    *param_4 = local_18;
    param_4[1] = local_14;
    param_4[2] = local_10;
    FUN_0076f5f0(param_4, param_4);
    if ((*(byte *)(*(int *)(param_1 + 8) + 0xbc) & 1) != 0) {
      FUN_00972e50();
      FUN_009729d0(param_4);
      return;
    }
    FUN_009729d0(param_4);
  }
  else if (*(int *)(param_1 + 0xec) == 1) {
    // ortho: copy basis triple (+0x20..+0x28)
    iVar2 = *(int *)(param_1 + 8);
    if ((*(byte *)(iVar2 + 0xbc) & 1) != 0) {
      iVar2 = FUN_00972e50();
    }
    *param_4 = *(float *)(iVar2 + 0x20);
    param_4[1] = *(float *)(iVar2 + 0x24);
    param_4[2] = *(float *)(iVar2 + 0x28);
    return;
  }
  // mode ∉ {0,1}: param_4 unchanged
  return;
}
