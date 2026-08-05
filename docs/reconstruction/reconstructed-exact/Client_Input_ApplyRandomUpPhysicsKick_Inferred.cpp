// =============================================================================
// Client_Input_ApplyRandomUpPhysicsKick_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0091d460
// Address:   0x0091d460 – 0x0091d655  (autoassault.exe, image base 0x400000)
// System:    input-drive-control
// Generated: 2026-07-29 dual A/B refine (prior scaffold FUN_0091d460 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler + asm CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Edge-triggered secondary path from Client_Input_DriveControlTick.
//   If local vehicle is drive-enabled and physics-ready, apply a mostly-upward
//   randomized physics kick: X/Z ∈ ≈[-0.3,0.3], Y base 1, normalize, scale by
//   (1/mass)*12, then FUN_00404cb0(physics=entity+8, &vec) → body vtbl+0x5c.
//   Does NOT write thr/steer/handbrake axes.
//
// CALLERS:
//   Client_Input_DriveControlTick @ 0x009223b0 (sole; ActionMap edge + rate gate)
//
// CALLEES:
//   0x007a4330  RNG host getter (Ghidra: CVOGReaction_RandomUnitScalar) ×2
//   0x00404cb0  Physics apply shell (vtbl+0x5c; sibling of ApplyImpulseVector)
//
// CONSTANTS (read_memory 2026-07-29):
//   DAT_00aaaaf0 @ 0x00aaaaf0 ≈ 0.6/65535   (u16 scale)
//   g_flOverheatCoolFrac @ 0x00a0f714 = 0.3  (random center; shared name)
//   DAT_00aaaad0 @ 0x00aaaad0 = 12.0
//   g_flOne @ 0x00a0f2a0 = 1.0
//   DAT_00afda50 block = (0, 1, 0, 0)
//
// ABI: void; no stack args; plain RET.
// =============================================================================

void Client_Input_ApplyRandomUpPhysicsKick_Inferred(void)
{
  ushort uVar1;
  int entity;
  char blocked;
  int rng;
  float invLen;
  float rz;
  float scale;
  float vec_x;
  float vec_y;
  float vec_z;
  float vec_w;

  entity = *(int *)(DAT_00d1b6d8 + 0x250);
  if (((entity != 0) && (*(int *)(entity + 8) != 0)) && (*(char *)(entity + 0x101) == '\0')) {
    blocked = (**(code **)(*(int *)(*(int *)(*(int *)(entity + 4) + 4) + 4 + entity) + 0x198))();
    if (blocked == '\0') {
      // base (0, 1, 0, 0)
      vec_x = DAT_00afda50;
      vec_y = DAT_00afda54;
      vec_z = (float)DAT_00afda58;
      vec_w = DAT_00afda5c;

      // random X ≈ [-0.3, 0.3]
      rng = CVOGReaction_RandomUnitScalar();
      if (0xfffff < *(int *)(rng + 0xc)) {          // ≡ index >= 0x100000
        *(undefined4 *)(rng + 0xc) = 0;
      }
      uVar1 = *(ushort *)(*(int *)(rng + 8) + *(int *)(rng + 0xc) * 2);
      *(int *)(rng + 0xc) = *(int *)(rng + 0xc) + 1;
      vec_x = (float)uVar1 * DAT_00aaaaf0 - g_flOverheatCoolFrac;

      // random Z ≈ [-0.3, 0.3]
      rng = CVOGReaction_RandomUnitScalar();
      if (0xfffff < *(int *)(rng + 0xc)) {
        *(undefined4 *)(rng + 0xc) = 0;
      }
      uVar1 = *(ushort *)(*(int *)(rng + 8) + *(int *)(rng + 0xc) * 2);
      *(int *)(rng + 0xc) = *(int *)(rng + 0xc) + 1;
      rz = (float)uVar1 * DAT_00aaaaf0 - g_flOverheatCoolFrac;

      invLen = rz * rz + vec_y * vec_y + vec_x * vec_x;
      if (invLen == 0.0) {
        invLen = 0.0;
      }
      else {
        invLen = g_flOne / SQRT(invLen);
      }

      // mass @ body+0x2c; asm keeps ECX = *(entity+8) for FUN_00404cb0 thiscall
      scale = *(float *)(*(int *)(*(int *)(entity + 8) + 0x3c) + 0x2c);
      if (scale == 0.0) {
        scale = 0.0;
      }
      else {
        scale = g_flOne / scale;
      }
      scale = scale * DAT_00aaaad0;   // * 12.0f

      vec_x = scale * invLen * vec_x;
      vec_y = invLen * vec_y * scale;
      vec_z = invLen * rz * scale;
      vec_w = invLen * vec_w * scale;

      // thiscall: ECX=*(entity+8) (live from mass load path); arg=&vec
      FUN_00404cb0(&vec_x);
    }
  }
  return;
}
