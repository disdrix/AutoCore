// =============================================================================
// Client_Map_RaySegmentHitDistance_Inferred  (Ghidra: FUN_00916090)
// -----------------------------------------------------------------------------
// Stable ID: aa_00916090
// Address:   0x00916090  (autoassault.exe, image base 0x400000)
// Span:      00916090 – 00916225 (405 B; stdcall RET 0x18; ST0 return)
// System:    client camera / map collision query
// Dual A/B:  2026-07-29 accept-with-gaps (W23-O)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Contract (dual-sealed):
 *   Cast world segment (sx,sy,sz) → (ex,ey,ez) through map collision context
 *   *(DAT_00d1b644 + 0xe4a4) via FUN_0055e530, filter=7.
 *   On hit: optional *ESI = hitToken; return |lerp(start,end,t) - start|.
 *   On miss: optional *ESI = 0; return 0.0f.
 *
 * Callees:
 *   FUN_0055e530 @ 0x0055e530 — map cast wrapper (see fn_004cfe60_castTerrain.md)
 *   FUN_004e9530 @ 0x004e9530 — Math_CopyFloat3ToFloat4_Inferred (start XYZ copy)
 *
 * Pool constants (read_memory):
 *   g_flOne  @ 0x00a0f2a0 = 1.0f
 *   g_flZero @ 0x00a0f518 = 0.0f
 *
 * Prior scaffold name Named_CalleeOf_Named_VOG_DEBUG_STOP_00916090 is too narrow.
 *
 * Note: decompiler shows FUN_0055e530(&ray, result) without ECX; live bytes load
 * ECX from [DAT_00d1b644+0xe4a4] immediately before the CALL.
 */

// SECTION: args — start XYZ, end XYZ; ESI optional hitOut; ST0 distance
float10 FUN_00916090(float param_1, float param_2, float param_3,
                     float param_4, float param_5, float param_6)
{
  int *unaff_ESI;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float local_80;
  float local_7c;
  float local_78;
  float local_70;
  float local_6c;
  float local_68;
  uint32_t local_64;
  float local_60;
  float local_5c;
  float local_58;
  uint32_t local_54;
  uint8_t local_50;
  uint32_t local_4c;
  uint8_t local_40[20];
  float local_2c;
  int local_20;

  local_70 = param_1;
  local_6c = param_2;
  local_68 = param_3;
  local_60 = param_4;
  local_64 = 0;
  local_5c = param_5;
  local_54 = 0;
  local_50 = 0;
  local_4c = 7;
  local_58 = param_6;
  local_2c = g_flOne;
  local_20 = 0;
  /* ECX = *(DAT_00d1b644 + 0xe4a4) — loaded at call site in machine code */
  FUN_0055e530(&local_70, local_40);
  if (local_20 != 0) {
    if (unaff_ESI != (int *)0x0) {
      *unaff_ESI = local_20;
    }
    fVar1 = g_flOne - local_2c;
    fVar2 = fVar1 * local_70;
    fVar5 = local_60 * local_2c;
    fVar3 = local_5c * local_2c;
    fVar6 = local_6c * fVar1;
    fVar4 = local_58 * local_2c;
    fVar1 = local_68 * fVar1;
    FUN_004e9530(&local_80, &param_1);
    local_80 = (fVar2 + fVar5) - local_80;
    local_7c = (fVar3 + fVar6) - local_7c;
    local_78 = (fVar4 + fVar1) - local_78;
    return SQRT((float10)local_80 * (float10)local_80 +
                (float10)local_7c * (float10)local_7c +
                (float10)local_78 * (float10)local_78);
  }
  if (unaff_ESI != (int *)0x0) {
    *unaff_ESI = 0;
  }
  return (float10)g_flZero;
}
