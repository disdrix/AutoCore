// =============================================================================
// FUN_00973690  (clean twin of Color_LerpPackedARGB_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00973690
// Address:   0x00973690  (autoassault.exe, image base 0x400000)
// Body:      0x00973690–0x0097376e (222 B)
// System:    graphics / color
// Generated: 2026-07-29 W28-F dual seal (supersedes 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler CF + ECX dest from bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

extern float g_flOne; /* 0x00a0f2a0 = 1.0f */

void FUN_00973590(float r, float g, float b, float a);

void __fastcall FUN_00973690(uint32_t *dest /*ECX*/,
                             float param_1,
                             uint32_t param_2,
                             uint32_t param_3)
{
  float fVar1;
  float *pfVar2;
  uint32_t uVar3;
  uint32_t uVar4;
  float local_8;
  float local_4;

  pfVar2 = &local_8;
  local_4 = g_flOne;
  local_8 = 0.0f;
  if ((0.0f <= param_1) && (pfVar2 = &local_4, param_1 <= g_flOne)) {
    pfVar2 = &param_1;
  }
  fVar1 = *pfVar2;
  uVar4 = param_2 >> 8 & 0xff;
  uVar3 = param_2 >> 0x10 & 0xff;

  (void)dest; /* mov eax,ecx before call in retail */
  FUN_00973590((float)(int)((param_3 >> 0x10 & 0xff) - uVar3) * fVar1 + (float)uVar3,
               (float)(int)((param_3 >> 8 & 0xff) - uVar4) * fVar1 + (float)uVar4,
               (float)(int)((param_3 & 0xff) - (param_2 & 0xff)) * fVar1 + (float)(param_2 & 0xff),
               (float)(int)((param_3 >> 0x18) - (param_2 >> 0x18)) * fVar1 +
               (float)(param_2 >> 0x18));
  return;
}
