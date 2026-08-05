// =============================================================================
// Client_Camera_ApplyLookOffset
// -----------------------------------------------------------------------------
// Stable ID: aa_0091a5f0
// Address:   0x0091a5f0  (autoassault.exe, image base 0x400000)
// System:    input-drive-control (camera / look apply)
// Generated: 2026-07-29 dual A/B seal (from live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN.
//
// Callers (only):
//   Client_Input_DriveControlTick @ 0x0092278b  (local_d4, &local_d0)
//   Client_Input_DriveControlTick @ 0x00922f13  (1.0f, &fStack_a0)
//
// Convention:
//   Stack: float lookScale, float *lookVec
//   ESI:   look-helper object*  (DCT piStack_a8)
//
// NOT a drive-axis writer (+0x614/+0x618/+0x61c). Soft 0.2 DAT here damps
// zero-xz look path; soft-steer ±0.5 is unrelated (UF-006).
// =============================================================================

// Constants sealed via Ghidra read_memory 2026-07-29:
//   DAT_00aaa668 = -1.0f
//   DAT_00aaa6fc = 25.0f
//   DAT_00aaa7dc ≈ 6.283185f (2π)
//   DAT_00aaa948 ≈ 0.99999f   mode deadband low
//   DAT_00aaa9bc ≈ 1.00001f   mode deadband high
//   DAT_00a0f70c = 0.2f       damp scale (shared DAT with soft-look step; different role)
//   DAT_00a0f298 = 0.5f       half-angle (inside FUN_00567ce0)
//   DAT_00afda60..68 = (0,0,1) world Z
//   DAT_00afda70..78 = (1,0,0) world X

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Client_Camera_ApplyLookOffset(float lookScale, float *lookVec)
{
  uint8_t modeByte;
  int iVar2;
  uint32_t *puVar3;
  int pHelper; /* unaff_ESI — look helper object* */
  float10 fVar4;
  float fVar5;
  uint8_t uStack_62;
  uint8_t uStack_61;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  uint32_t local_50;
  uint32_t local_4c;
  uint32_t local_48;
  uint32_t local_44;
  float local_40;
  float local_3c;
  float local_38;
  float fStack_34;
  uint32_t local_30;
  uint32_t uStack_2c;
  uint32_t uStack_28;
  uint32_t uStack_24;
  uint8_t local_20[28];

  /* dt-like scale from global manager */
  local_54 = *(float *)(DAT_00d09874 + 0x30);

  if ((pHelper == 0) || (*(int *)(pHelper + 8) == 0)) {
    return;
  }

  /* --- scale ≠ 1.0: orientation update from object forward + folded scale --- */
  if (lookScale != g_flOne) {
    iVar2 = *(int *)(*(int *)(pHelper + 8) + 0x3c); /* rigid body */
    local_50 = *(uint32_t *)(iVar2 + 0x30); /* quat xyzw */
    local_4c = *(uint32_t *)(iVar2 + 0x34);
    local_48 = *(uint32_t *)(iVar2 + 0x38);
    local_44 = *(uint32_t *)(iVar2 + 0x3c);

    FUN_004e8a40(&local_50, &local_40); /* forward (+Z) */

    /* pitchDot = forward · worldZ (0,0,1) */
    local_60 = local_38 * DAT_00afda68 + local_3c * DAT_00afda64 + local_40 * DAT_00afda60;
    fVar5 = g_flOne;
    if ((g_flOne < local_60) || (fVar5 = DAT_00aaa668 /* -1 */, local_60 < DAT_00aaa668)) {
      local_60 = fVar5;
    }
    fVar4 = (float10)FUN_0040d0a0(local_60); /* safe acos */
    local_5c = (float)fVar4;
    iVar2 = _finite((double)fVar4);
    if (iVar2 == 0) {
      local_5c = 0.0f;
    }

    FUN_004e8ad0(&local_50, local_20); /* right (+X) into tmp */

    /* hemisphere: if forward · worldX (1,0,0) < 0 → pitch = 2π - pitch */
    if (local_38 * _DAT_00afda78 + local_3c * _DAT_00afda74 + local_40 * _DAT_00afda70 < 0.0f) {
      local_5c = DAT_00aaa7dc - local_5c; /* TAU - pitch */
    }

    /* fold lookScale about 1.0 → magnitude in [-1,1] + sign local_58 */
    local_58 = g_flOne;
    local_60 = lookScale;
    if (g_flOne < lookScale) {
      local_58 = DAT_00aaa668; /* -1 */
      local_60 = g_flOne - (lookScale - g_flOne); /* 2 - lookScale */
    }
    if (local_60 < DAT_00aaa668) {
      local_60 = DAT_00aaa668;
    }
    fVar4 = (float10)FUN_0040d0a0(local_60);
    local_60 = (float)fVar4;
    iVar2 = _finite((double)fVar4);
    fVar5 = 0.0f;
    if (iVar2 != 0) {
      fVar5 = local_60;
    }

    /* half-angle quat build: angle = dtLike * 25 * acos(|fold|) * sign + pitch */
    FUN_00567ce0(&DAT_00afda50, local_54 * DAT_00aaa6fc * fVar5 * local_58 + local_5c);
    FUN_00404dc0();
  }

  /* --- mode byte from lookScale deadband around 1.0 --- */
  if (DAT_00aaa948 /* ~0.99999 */ <= lookScale) {
    if (lookScale <= _DAT_00aaa9bc /* ~1.00001 */) {
      modeByte = 0;
    } else {
      modeByte = 0xff;
    }
  } else {
    modeByte = 1;
  }
  *(uint8_t *)(pHelper + 0x14c) = modeByte;

  /* --- look vector world offset apply --- */
  if (((*lookVec != 0.0f) || (lookVec[2] != 0.0f)) || (*(char *)(pHelper + 0x304) != '\0')) {
    if ((*(int *)(pHelper + 8) != 0) &&
        (iVar2 = (**(code **)(**(int **)(*(int *)(pHelper + 8) + 0x3c) + 0x18))(), iVar2 == 6)) {
      FUN_0053d970();
      uStack_61 = 1;
      uStack_62 = 0;
      CVOGSpawnPoint_SetObjectActiveState(
          *(int *)(*(int *)(pHelper + 4) + 4) + 4 + pHelper, &uStack_61, &uStack_62);
    }

    iVar2 = *(int *)(pHelper + 8);
    if (iVar2 == 0) {
      puVar3 = (uint32_t *)(*(int *)(*(int *)(pHelper + 4) + 4) + 0x84 + pHelper); /* pos fallback */
    } else {
      puVar3 = (uint32_t *)(*(int *)(iVar2 + 0x3c) + 0xb0); /* rb pos */
    }
    local_50 = *puVar3;
    local_4c = puVar3[1];
    local_48 = puVar3[2];
    local_44 = puVar3[3];

    if (iVar2 == 0) {
      puVar3 = (uint32_t *)(*(int *)(*(int *)(pHelper + 4) + 4) + 0x94 + pHelper); /* quat fallback */
    } else {
      puVar3 = (uint32_t *)(*(int *)(iVar2 + 0x3c) + 0x30); /* rb quat */
    }
    local_30 = *puVar3;
    uStack_2c = puVar3[1];
    uStack_28 = puVar3[2];
    uStack_24 = puVar3[3];

    FUN_004e8bf0(&local_50, &local_30, lookVec, local_20); /* world = pos + R*lookVec */
    FUN_004c3a40();

    if ((lookVec[2] == 0.0f) && (*lookVec == 0.0f)) {
      FUN_004e8a40(&local_30, &local_40); /* forward */
      local_40 = local_40 * DAT_00a0f70c; /* * 0.2 damp */
      local_3c = local_3c * DAT_00a0f70c;
      local_38 = local_38 * DAT_00a0f70c;
      fStack_34 = fStack_34 * DAT_00a0f70c;
      local_50 = 0;
      local_4c = 0;
      local_48 = 0;
      local_44 = 0;
      FUN_004c3a40();
      return;
    }
    *(uint8_t *)(pHelper + 0x304) = 1; /* sticky look-active */
  }
  return;
}
