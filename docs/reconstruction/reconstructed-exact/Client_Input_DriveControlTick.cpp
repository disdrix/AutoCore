// READABILITY (auto CF):
//  - Body size: ~580 non-empty decompiler lines.
//  - Control keywords: if×100, goto×17, return×4, do×1, while×1.
//  - Notable callees: VehicleEntity_SetHandbrake×6, VehicleEntity_SetSteerInput×6, ABS×5, VehicleEntity_SetLongitudinalInput×5, SQRT×4, VehicleEntity_SetFlag_109×4, FUN_0075c340×3, Client_QuickBarActivateSkillSlot×2.
//  - Return sites: 4.

// =============================================================================
// Client_Input_DriveControlTick
// -----------------------------------------------------------------------------
// Stable ID: aa_009223b0
// Address:   0x009223b0  (autoassault.exe, image base 0x400000)
// System:    input-drive-control
// Generated: 2026-07-23 from raw capture
// Refined:   2026-07-23 human-refine - clear ACCEL / REVERSE / STEER(hard+soft) /
//            HANDBRAKE section banners; CF ≡ raw (no modernization).
//            2026-07-29 soft-steer/analog residual seal: ±0.5 immediates confirmed via
//            image push @ 0x00922c48 (0xbf000000) / 0x00922cf8 (0x3f000000); UF-006
//            label polarity remains open (SoftL=-0.5 vs HardL=+1) — no invented fix.
//            2026-07-29 camera look-offset residual: local_d* are look locals (not steer
//            axis); SECTION 7 interleaves SetSteerInput with local_d4/d0/c8 mode tables;
//            hard ±0.03 (DAT_00aaa8fc), soft ±0.2 (DAT_00a0f70c); apply FUN_0091a5f0;
//            SECTION 15 world camera slots. Dual: *_camera_refresh.md.
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Runtime / differential: OPEN.
//
// Fresh Ghidra re-decompile (2026-07-23 + 2026-07-29 soft pass, decompile_function 0x009223b0):
//   Confirms body matches raw aa_009223b0 (same CF / setters / ActionMap DAT_* / soft ±0.5).
//
// Primary callees (drive axes - thiscall on vehicle entity pVehicle):
//   VehicleEntity_SetSteerInput          0x004f5620  aa_004f5620  → entity+0x618 (gated 0xC7)
//   VehicleEntity_SetLongitudinalInput   0x004f5650  aa_004f5650  → entity+0x614 (gated 0xC7)
//   VehicleEntity_SetHandbrake           0x004f3620  aa_004f3620  → entity+0x61c (ungated)
//   VehicleEntity_PushDriveAxesToController 0x004fbc10           thr+HB → controller
//
// Related clean sources:
//   docs/reconstruction/reconstructed-exact/VehicleEntity_SetSteerInput.cpp
//   docs/reconstruction/reconstructed-exact/VehicleEntity_SetLongitudinalInput.cpp
//   docs/reconstruction/reconstructed-exact/VehicleEntity_SetHandbrake.cpp
// System map:
//   docs/reconstruction/systems/input-drive-control.md
// Dual reviews:
//   docs/reconstruction/reviews/A_aa_009223b0_Client_Input_DriveControlTick.md
//   docs/reconstruction/reviews/B_aa_009223b0_Client_Input_DriveControlTick.md
// =============================================================================

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 * - Section comments document gates and ActionMap→setter contracts only; they do not
 *   invent branches. Sign convention (caller-owned hex immediates):
 *     Accel=-1 (0xbf800000), Reverse=+1 (0x3f800000),
 *     SteerL=+1 (0x3f800000), SteerR=-1 (0xbf800000),
 *     Soft L=-0.5 (0xbf000000), Soft R=+0.5 (0x3f000000) - UF-006 soft polarity open.
 *
 * Section index (drive-axis focus):
 *   1  Prologue look-vector locals
 *   2  UI/modal early-out
 *   3  Analog device path → setters or camera
 *   4  Require vehicle entity + mode setup
 *   5  ACCELERATE     DAT_00d1bc26 → thr -1
 *   6  REVERSE        DAT_00d1bc5a → thr +1 / clear 0
 *   7  STEER          hard-R / hard-L / soft-L / soft-R / clear  (sub 7a-7e)
 *   7f Post-steer thr damp join (LAB_00922d94)
 *   8  Brake-edge air-stab (edge; not continuous HB)
 *   9  Terrain cast / airborne impulse
 *  10  Airborne early return
 *  11  Combat / skill modes
 *  12  Secondary weapons
 *  13  HANDBRAKE      DAT_00d1bd5e / analog ch8 continuous latch
 *  14  PushDriveAxes
 *  15  Camera aim epilogue
 *
 * pClient  - client/controller (VOGClient-related; type tentative; decomp param_1)
 * pVehicle - vehicle entity pointer, or 0 (decomp param_2)
 *
 * Key ActionMap held-flag DATs (name-3 bind slots):
 *   DAT_00d1bc26 Accel → thr -1 · DAT_00d1bc5a Reverse → thr +1
 *   DAT_00d1bc8e SteerL → +1 · DAT_00d1bcc2 SteerR → -1
 *   Soft L/R ±0.5 · DAT_00d1bd5e Brake → handbrake +0x61c
 * Entity axes: +0x614 thr, +0x618 steer, +0x61c HB; gate char +0x101 often.
 * End: PushDriveAxes when vehicle+0x101==0 (section 14).
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WI-MOV-001 DriveControlTick: held flags at ActionMap(VOGClient+0x116c) name-3:
   Accel@d1bc26→ent+0x614=-1; Reverse@d1bc5a→+614=+1; SteerL@d1bc8e→+618=+1;
   SteerR@d1bcc2→+618=-1; SoftL/R ±0.5; Brake@d1bd5e→+0x61c handbrake. Setters:
   VehicleEntity_SetLongitudinalInput 4f5650 / SetSteerInput 4f5620 / SetHandbrake 4f3620. */
uint32_t /* width from decompiler */ Client_Input_DriveControlTick(int *pClient,int pVehicle)
{
  int iVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  float *pfVar6;
  int *piVar7;
  void *pvVar8;
  DWORD DVar9;
  float10 fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float fStack_b4;
  uint32_t /* width from decompiler */ uStack_b0;
  int *piStack_a8;
  float local_a4;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  uint32_t /* width from decompiler */ uStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  uint32_t /* width from decompiler */ uStack_54;
  TFID_16 aTStack_40 [3];
  
  // ---------------------------------------------------------------------------
  // SECTION 1: Prologue - seed look / camera vector locals from globals
  // local_d0..local_c4 ← DAT_00d1a640..; local_d4 = 1.0; scale local_a4 by mode flag.
  // ---------------------------------------------------------------------------
  local_d0 = DAT_00d1a640;
  local_cc = DAT_00d1a644;
  local_c8 = DAT_00d1a648;
  local_c4 = DAT_00d1a64c;
  local_d4 = g_flOne;
  local_a4 = DAT_00aaacc8;
  if (*(char *)(DAT_00d1b644 + 0xf5) == '\0') {
    local_a4 = (float)g_nInferredThreatDefault;
  }
  // ---------------------------------------------------------------------------
  // SECTION 2: UI / modal early-out gate
  // If DAT_00d1b6d8[0x7f] object vtbl+0x3c returns non-zero → return 1 (skip all axes).
  // ---------------------------------------------------------------------------
  if (((DAT_00d1b6d8 != (int *)0x0) && ((int *)DAT_00d1b6d8[0x7f] != (int *)0x0)) &&
     (iVar5 = (**(code **)(*(int *)DAT_00d1b6d8[0x7f] + 0x3c))(), iVar5 != 0)) {
    return 1;
  }
  // ---------------------------------------------------------------------------
  // SECTION 3: Analog device path (DAT_00d1b618 present+active, sample via DAT_00d1b620)
  // If no vehicle or vehicle+0x101 != 0: camera/look offsets only (vtbl pClient+0x44c).
  // Else: clear +0x109 / handbrake if set; clamp thr; SetLongitudinalInput + SetSteerInput.
  // Cross-ref: VehicleEntity_SetLongitudinalInput 0x004f5650, SetSteerInput 0x004f5620,
  //            SetHandbrake 0x004f3620.
  // ---------------------------------------------------------------------------
  if ((DAT_00d1b618 != (code *)0x0) && (cVar4 = (*DAT_00d1b618)(), cVar4 != '\0')) {
    fVar10 = (float10)(*DAT_00d1b620)(7);
    fStack_b4 = (float)fVar10;
    fVar10 = (float10)(*DAT_00d1b620)(6);
    piStack_a8 = (int *)(float)((float10)fStack_b4 - fVar10);
    fVar10 = (float10)(*DAT_00d1b620)(9);
    fStack_b4 = (float)fVar10;
    fVar10 = (float10)(*DAT_00d1b620)(10);
    fStack_b4 = (float)((float10)fStack_b4 - fVar10);
    if ((pVehicle == 0) || (*(char *)(pVehicle + 0x101) != '\0')) {
      piVar7 = piStack_a8;
      if (((float)piStack_a8 == 0.0) && (fStack_b4 != 0.0)) {
        piVar7 = (int *)DAT_00aaa6d4;
      }
      fVar12 = 0.0;
      fVar11 = g_flHardKillInterpolate;
      if (*(char *)(DAT_00d1b644 + 0xf5) == '\0') {
        fVar12 = fStack_b4 * DAT_00aaa688;
        fVar11 = DAT_00aaa8fc;
      }
      local_d4 = fStack_b4 * fVar11 + g_flOne;
      local_d0 = fVar12 + local_d0;
      local_c8 = (0.0 - (float)piVar7 * local_a4) + local_c8;
      fVar10 = (float10)(*DAT_00d1b620)(0xb);
      fStack_b4 = (float)fVar10;
      fVar10 = (float10)(*DAT_00d1b620)(0xc);
      fStack_b4 = (float)((float10)fStack_b4 - fVar10);
      (**(code **)(*pClient + 0x44c))(fStack_b4);
    }
    else {
      if (*(char *)(pVehicle + 0x109) != '\0') {
        VehicleEntity_SetFlag_109(0);
      }
      if (*(char *)(pVehicle + 0x61c) != '\0') {
        VehicleEntity_SetHandbrake(0);
      }
      fVar11 = DAT_00aaa668;
      if (((float)piStack_a8 < DAT_00aaa668) || (fVar11 = g_flOne, g_flOne < (float)piStack_a8)) {
        piStack_a8 = (int *)fVar11;
      }
      VehicleEntity_SetLongitudinalInput(piStack_a8);
      VehicleEntity_SetSteerInput(fStack_b4);
    }
  }
  if (((*(char *)(*(int *)(*(int *)(DAT_00d1b6d8[1] + 4) + 0xa8 + (int)DAT_00d1b6d8) + 0xf5) != '\0'
       ) && (DAT_00d1b6d8[2] != 0)) && ((char)DAT_00d1b6d8[0xc1] == '\0')) {
    fStack_a0 = 0.0;
    fStack_9c = 0.0;
    fStack_98 = 0.0;
    fStack_94 = 0.0;
    FUN_0040d040(&fStack_a0);
  }
  // ---------------------------------------------------------------------------
  // SECTION 4: Require vehicle entity (pVehicle). Null → return 1 (no digital axes).
  // Mode setup for look helper (piStack_a8) + drive-path eligibility gate below.
  // ---------------------------------------------------------------------------
  piVar7 = DAT_00d1b6d8;
  if (pVehicle == 0) {
    return 1;
  }
  piStack_a8 = (int *)0x0;
  if (*(char *)((int)DAT_00d1b6d8 + 0x6b9) == '\0') {
    if (*(char *)(DAT_00d1b644 + 0xf5) != '\0') {
      *(uint8_t *)(DAT_00d1b6d8 + 0x1af) = 0;
      piStack_a8 = piVar7;
    }
  }
  else {
    piVar7 = *(int **)(*(int *)(DAT_00d1b6d8[1] + 4) + 0xa4 + (int)DAT_00d1b6d8);
    if (piVar7 != (int *)0x0) {
      piStack_a8 = (int *)(**(code **)(*piVar7 + 0x1d8))();
    }
  }
  piVar7 = piStack_a8;
  *(uint8_t *)((int)pClient + 0xa86) = 0;
  cVar4 = DAT_00d1b222;
  if (((((DAT_00d1b644 == 0) || (*(char *)(DAT_00d1b644 + 0xf5) == '\0')) ||
       (cVar4 = DAT_00d1d866, DAT_00d1b221 == '\0')) && (cVar4 == '\0')) ||
     ((DAT_00d1a859 == '\0' && ((pClient[0x31c] == 0 || (*(char *)(pClient[0x31c] + 0x21) != '\0')))
      ))) {
    if ((DAT_00d1bf32 != '\0') && (DAT_00d1bf33 != '\0')) {
      DAT_00d1bf33 = '\0';
      *(bool *)(pClient + 0x319) = (char)pClient[0x319] == '\0';
    }
    bVar2 = false;
    bVar3 = false;
    // ---------------------------------------------------------------------------
    // SECTION 5: ACCELERATE - DAT_00d1bc26 held (or auto-drive latch pClient[0x319])
    //   SetLongitudinalInput(0xbf800000 = -1.0f)  via aa_004f5650 → entity+0x614
    //   Gate: vehicle+0x101 == 0 (suppressDriveAxisApply, Probable).
    //   Also clears +0x109 hard-stop and handbrake (+0x61c) if engaged before thr write.
    //   Side-effect: local_c8 += local_a4; bVar2 = true (accel active for reverse-clear / look).
    // ---------------------------------------------------------------------------
    if (DAT_00d1bc26 == '\0') {
      if ((char)pClient[0x319] != '\0') goto LAB_009228c6;
    }
    else {
      *(uint8_t *)(pClient + 0x319) = 0;
LAB_009228c6:
      if (*(char *)(pVehicle + 0x101) == '\0') {
        if (*(char *)(pVehicle + 0x109) != '\0') {
          VehicleEntity_SetFlag_109(0);
        }
        if (*(char *)(pVehicle + 0x61c) != '\0') {
          VehicleEntity_SetHandbrake(0);
        }
        VehicleEntity_SetLongitudinalInput(0xbf800000);
      }
      local_c8 = local_c8 + local_a4;
      bVar2 = true;
    }
    // ---------------------------------------------------------------------------
    // SECTION 6: REVERSE - DAT_00d1bc5a held
    //   Held: SetLongitudinalInput(0x3f800000 = +1.0f) via aa_004f5650 → entity+0x614
    //         Gate vehicle+0x101==0; clears +0x109 / handbrake if set (same as accel).
    //   Not held + accel inactive + no analog + drive-enabled: SetLongitudinalInput(0).
    //   Side-effect: look offset; bVar3 = true (reverse active).
    // ---------------------------------------------------------------------------
    if (DAT_00d1bc5a == '\0') {
      if ((!bVar2) &&
         (((DAT_00d1b618 == (code *)0x0 || (cVar4 = (*DAT_00d1b618)(), cVar4 == '\0')) &&
          (*(char *)(pVehicle + 0x101) == '\0')))) {
        VehicleEntity_SetLongitudinalInput(0);
      }
    }
    else {
      *(uint8_t *)(pClient + 0x319) = 0;
      if (*(char *)(pVehicle + 0x101) == '\0') {
        if (*(char *)(pVehicle + 0x109) != '\0') {
          VehicleEntity_SetFlag_109(0);
        }
        if (*(char *)(pVehicle + 0x61c) != '\0') {
          VehicleEntity_SetHandbrake(0);
        }
        VehicleEntity_SetLongitudinalInput(0x3f800000);
      }
      fVar11 = DAT_00aaacc4;
      if ((*(char *)(DAT_00d1b644 + 0xf5) != '\0') ||
         (fVar12 = 0.0 - local_a4, *(char *)((int)DAT_00d1b6d8 + 0x6b9) != '\0')) {
        *(uint8_t *)(DAT_00d1b6d8 + 0x1af) = 1;
        fVar12 = fVar11;
      }
      local_c8 = fVar12 + local_c8;
      bVar3 = true;
    }
    // ---------------------------------------------------------------------------
    // SECTION 7: STEER (priority order; all axis writes gated by vehicle+0x101==0)
    //   7a hard-R  DAT_00d1bcc2 → SetSteerInput(0xbf800000 = -1.0f)  aa_004f5620 → +0x618
    //   7b hard-L  DAT_00d1bc8e → SetSteerInput(0x3f800000 = +1.0f)
    //   7c soft-L  DAT_00d1bd2a → SetSteerInput(0xbf000000 = -0.5f)  // UF-006 polarity open
    //   7d soft-R  DAT_00d1bcf6 → SetSteerInput(0x3f000000 = +0.5f)
    //   7e none (+ no analog) → SetSteerInput(0)
    // Camera look-offset side-effects (local_d*) interleave; NOT axis stores.
    // Residual seal 2026-07-29: local_d4 hard ±DAT_00aaa8fc(0.03) / soft ±DAT_00a0f70c(0.2);
    // local_d0/c8 mode tables; apply later via FUN_0091a5f0 — independent of +0x618.
    // ---------------------------------------------------------------------------
    // --- 7a HARD STEER RIGHT ---
    if (DAT_00d1bcc2 != '\0') {
      if (*(char *)(pVehicle + 0x101) == '\0') {
        VehicleEntity_SetSteerInput(0xbf800000);
      }
      if ((*(char *)(DAT_00d1b644 + 0xf5) == '\0') && (*(char *)((int)DAT_00d1b6d8 + 0x6b9) == '\0')
         ) {
        local_d4 = local_d4 - DAT_00aaa8fc;
        fVar11 = DAT_00aaa688;
        fVar12 = local_a4;
      }
      else if (((*(char *)((int)pClient + 0x493) == '\0') && ((char)pClient[0x125] != '\0')) ||
              (DAT_00d1b21b != '\0')) {
        fVar11 = DAT_00aaa68c;
        fVar12 = _DAT_009da8a4;
        if ((!bVar3) && (fVar11 = 0.0, fVar12 = local_a4, bVar2)) {
          fVar12 = local_a4 - g_flLevelUpUiBase_Inferred;
          fVar11 = DAT_00a12f70;
        }
      }
      else {
        local_d4 = local_d4 - _DAT_00aaa878;
        fVar12 = 0.0;
        fVar11 = 0.0;
        if (bVar2) {
          fVar11 = g_flOne;
        }
      }
      local_c8 = fVar11 + local_c8;
      local_d0 = fVar12 + local_d0;
      goto LAB_00922d94;
    }
    // --- 7b HARD STEER LEFT (else of hard-R; DAT_00d1bc8e held → +1.0f) ---
    // When hard-L not held, fall through to soft L/R / clear below.
    if (DAT_00d1bc8e == '\0') {
      // --- 7c SOFT STEER LEFT - DAT_00d1bd2a → -0.5f (0xbf000000); UF-006 label open ---
      if (DAT_00d1bd2a != '\0') {
        if (*(char *)(pVehicle + 0x101) == '\0') {
          VehicleEntity_SetSteerInput(0xbf000000);
        }
        if ((*(char *)(DAT_00d1b644 + 0xf5) == '\0') &&
           (*(char *)((int)DAT_00d1b6d8 + 0x6b9) == '\0')) {
          local_d4 = local_d4 - DAT_00a0f70c;
          fVar12 = local_a4;
          fVar13 = 0.0;
        }
        else {
          if (DAT_00d1b21b != '\0') {
            local_d4 = local_d4 - _DAT_00aaa878;
            goto LAB_00922be7;
          }
          fVar12 = _DAT_009da8a4;
          fVar13 = DAT_00aaa68c;
          if ((!bVar3) && (fVar12 = local_a4, fVar13 = 0.0, bVar2)) {
            fVar12 = local_a4 - g_flLevelUpUiBase_Inferred;
            fVar13 = DAT_00a12f70;
          }
        }
        goto LAB_00922bfc;
      }
      // --- 7d SOFT STEER RIGHT - DAT_00d1bcf6 → +0.5f (0x3f000000) ---
      if (DAT_00d1bcf6 != '\0') {
        if (*(char *)(pVehicle + 0x101) == '\0') {
          VehicleEntity_SetSteerInput(0x3f000000);
        }
        fVar11 = 0.0 - local_a4;
        if ((*(char *)(DAT_00d1b644 + 0xf5) != '\0') ||
           (*(char *)((int)DAT_00d1b6d8 + 0x6b9) != '\0')) {
          if (DAT_00d1b21b == '\0') goto joined_r0x00922d58;
          goto LAB_00922bdf;
        }
        local_d4 = local_d4 + DAT_00a0f70c;
        fVar12 = fVar11;
        fVar13 = 0.0;
        goto LAB_00922bfc;
      }
      // --- 7e STEER CLEAR - no hard/soft held; if no analog active, SetSteerInput(0) ---
      if ((DAT_00d1b618 != (code *)0x0) && (cVar4 = (*DAT_00d1b618)(), cVar4 != '\0'))
      goto LAB_00922d94;
      if (*(char *)(pVehicle + 0x101) == '\0') {
        VehicleEntity_SetSteerInput(0);
        goto LAB_00922d94;
      }
    }
    else {
      // hard-L held branch body: SetSteerInput(+1.0f)
      if (*(char *)(pVehicle + 0x101) == '\0') {
        VehicleEntity_SetSteerInput(0x3f800000);
      }
      fVar11 = 0.0 - local_a4;
      if ((*(char *)(DAT_00d1b644 + 0xf5) == '\0') && (*(char *)((int)DAT_00d1b6d8 + 0x6b9) == '\0')
         ) {
        local_d4 = local_d4 + DAT_00aaa8fc;
        fVar12 = fVar11;
        fVar13 = DAT_00aaa688;
      }
      else if (((*(char *)((int)pClient + 0x493) == '\0') && ((char)pClient[0x125] != '\0')) ||
              (DAT_00d1b21b != '\0')) {
joined_r0x00922d58:
        fVar12 = DAT_00aaa87c;
        fVar13 = DAT_00aaa68c;
        if ((!bVar3) && (fVar12 = fVar11, fVar13 = 0.0, bVar2)) {
          fVar12 = fVar11 + g_flLevelUpUiBase_Inferred;
          fVar13 = DAT_00a12f70;
        }
      }
      else {
LAB_00922bdf:
        local_d4 = local_d4 + _DAT_00aaa878;
LAB_00922be7:
        fVar12 = 0.0;
        fVar13 = 0.0;
        if (bVar2) {
          fVar12 = 0.0;
          fVar13 = g_flOne;
        }
      }
LAB_00922bfc:
      local_d0 = fVar12 + local_d0;
      local_c8 = fVar13 + local_c8;
    // ---------------------------------------------------------------------------
    // SECTION 7f: Post-steer join (LAB_00922d94) - thr damp when |thr| small and steer != 0
    // SetLongitudinalInput(DAT_00afe2b0); SetHandbrake(0); clear +0xa31; SetFlag_109(0).
    // ---------------------------------------------------------------------------
LAB_00922d94:
      if (((*(char *)(pVehicle + 0x101) == '\0') &&
          (ABS(*(float *)(pVehicle + 0x614)) < g_flMultiKillCountBlend)) &&
         (*(float *)(pVehicle + 0x618) != g_flZero)) {
        VehicleEntity_SetLongitudinalInput(DAT_00afe2b0);
        VehicleEntity_SetHandbrake(0);
        *(uint8_t *)((int)pClient + 0xa31) = 0;
        VehicleEntity_SetFlag_109(0);
      }
    }
    if (piStack_a8 != (int *)0x0) {
      fVar11 = local_cc * local_cc + local_c8 * local_c8 + local_d0 * local_d0;
      if (_DAT_00a158d0 < SQRT(fVar11)) {
        if (fVar11 == 0.0) {
          fVar11 = 0.0;
        }
        else {
          fVar11 = g_flOne / SQRT(fVar11);
        }
        local_d0 = fVar11 * local_d0;
        local_cc = fVar11 * local_cc;
        local_c8 = fVar11 * local_c8;
        local_c4 = fVar11 * local_c4;
      }
      fStack_b4 = DAT_00a0f74c;
      if (!bVar3) {
        fStack_b4 = g_flOne;
      }
      fVar10 = (float10)FUN_004c55e0();
      fVar10 = fVar10 * (float10)fStack_b4;
      local_d0 = (float)((float10)local_d0 * fVar10);
      local_cc = (float)((float10)local_cc * fVar10);
      local_c8 = (float)((float10)local_c8 * fVar10);
      local_c4 = (float)(fVar10 * (float10)local_c4);
      if (ABS(local_d4 - g_flOne) < DAT_00aaa620) {
        *(uint8_t *)(DAT_00d1b6d8 + 0x1af) = 1;
      }
      FUN_0091a5f0(local_d4,&local_d0);
    }
    if ((DAT_00aaa664 < ABS(local_d0)) || (DAT_00aaa664 < ABS(local_c8))) {
      *(uint8_t *)((int)pClient + 0xa86) = 1;
    }
  }
  else if (piStack_a8 != (int *)0x0) {
    if ((*(char *)((int)pClient + 0x493) == '\0') && (*(char *)((int)DAT_00d1b6d8 + 0x6b9) == '\0'))
    {
      fStack_a0 = DAT_00d1a640;
      fStack_9c = DAT_00d1a644;
      fStack_98 = DAT_00d1a648 + local_a4;
      fStack_94 = DAT_00d1a64c;
      if (DAT_00d1b6d8 != (int *)0x0) {
        *(uint8_t *)((int)pClient + 0xa86) = 1;
        FUN_0091a5f0(0x3f800000,&fStack_a0);
      }
    }
    else {
      fStack_b4 = DAT_00d1d86c;
      uStack_b0 = DAT_00d1d870;
      FUN_0075c340(&fStack_b4,&fStack_88,&fStack_7c);
      fStack_a0 = fStack_7c;
      fStack_9c = fStack_78;
      fStack_60 = fStack_88;
      fStack_98 = fStack_74;
      fStack_5c = fStack_84;
      fStack_94 = 0.0;
      fStack_58 = fStack_80;
      uStack_54 = 0;
      cVar4 = FUN_004cff70(&fStack_60,&fStack_a0,&fStack_70,400);
      if (cVar4 != '\0') {
        *(uint8_t *)((int)pClient + 0xa86) = 1;
        FUN_004c3a40(&fStack_70);
        *(uint8_t *)(piVar7 + 0xc1) = 1;
      }
    }
  }
  // ---------------------------------------------------------------------------
  // SECTION 8: Brake-edge / air-stab impulse (DAT_00d1bd5e held + DAT_00d1bd5f edge)
  // Distinct from continuous handbrake latch later (SECTION 13). Sets countdown DAT_00d1f0cc.
  // ---------------------------------------------------------------------------
  if ((((DAT_00d1bd5e == '\0') || (DAT_00d1bd5f == '\0')) ||
      (DAT_00d1bd5f = '\0', *(char *)(DAT_00d1b644 + 0xf5) == '\0')) ||
     (((char)DAT_00d1b6d8[0xc2] != '\0' || (DAT_00d1b6d8[2] == 0)))) {
    if (0 < DAT_00d1f0cc) goto LAB_0092301f;
  }
  else {
    fStack_60 = 0.0;
    fStack_5c = DAT_00aaacc0;
    fStack_58 = 0.0;
    uStack_54 = 0;
    FUN_00404cb0(&fStack_60);
    (**(code **)(*DAT_00d1b6d8 + 100))(0xd,0x3dcccccd,1,0xbf800000);
    *(uint8_t *)(DAT_00d1b6d8 + 0xc2) = 1;
    *(uint8_t *)((int)pClient + 0xa39) = 1;
    DAT_00d1f0cc = 3;
LAB_0092301f:
    DAT_00d1f0cc = DAT_00d1f0cc + -1;
  }
  // ---------------------------------------------------------------------------
  // SECTION 9: Terrain cast / airborne impulse helper (when DAT_00d1b644+0xf5)
  // CVOGMap_CastTerrainHeight @ 0x004cfe60; may ApplyImpulseVector.
  // ---------------------------------------------------------------------------
  if (*(char *)(DAT_00d1b644 + 0xf5) != '\0') {
    bVar2 = false;
    iVar5 = (**(code **)(*(int *)(*(int *)(DAT_00d1b6d8[1] + 4) + 4 + (int)DAT_00d1b6d8) + 0x1c8))()
    ;
    iVar5 = *(int *)(iVar5 + 8);
    if (iVar5 != 0) {
      iVar1 = *(int *)(iVar5 + 0x3c);
      fStack_70 = *(float *)(iVar1 + 0xb0);
      fStack_68 = *(float *)(iVar1 + 0xb8);
      (**(code **)(**(int **)(iVar5 + 0xc) + 0x18))(iVar1 + 0x80,0x38d1b717,&fStack_60);
      fVar10 = (float10)CVOGMap_CastTerrainHeight(fStack_70,fStack_68,fStack_5c + DAT_00a0f298,0);
      if (fVar10 + (float10)DAT_00a0f718 < (float10)fStack_5c) {
        bVar2 = true;
      }
    }
    if (*(char *)((int)pClient + 0xa39) == '\0') {
      if ((bVar2) && (iVar5 != 0)) {
        iVar5 = *(int *)(iVar5 + 0x3c);
        fStack_a0 = *(float *)(iVar5 + 0x40);
        fStack_9c = *(float *)(iVar5 + 0x44);
        fStack_98 = *(float *)(iVar5 + 0x48);
        fStack_94 = *(float *)(iVar5 + 0x4c);
        if (0.0 < fStack_9c) {
          fStack_9c = 0.0;
          CVOGPhysics_ApplyImpulseVector(&fStack_a0);
        }
      }
    }
    else if ((!bVar2) && (DAT_00d1f0cc < 1)) {
      *(uint8_t *)((int)pClient + 0xa39) = 0;
    }
  }
  // ---------------------------------------------------------------------------
  // SECTION 10: Airborne / special-mode early return (DAT_00d1b644+0xf5)
  // Skips combat/handbrake-digital tail when set.
  // ---------------------------------------------------------------------------
  if (*(char *)(DAT_00d1b644 + 0xf5) != '\0') {
    return 1;
  }
  // ---------------------------------------------------------------------------
  // SECTION 11: Combat / skill / secondary-fire modes (when not airborne early-return)
  // pClient[0x183]==1: vehicle combat mode; else optional QB skill slot 0.
  // ---------------------------------------------------------------------------
  if (pClient[0x183] != 1) {
    if (*(char *)((int)DAT_00d1b6d8 + 0x6b9) != '\0') {
      if ((DAT_00d1b61c == (code *)0x0) || (cVar4 = (*DAT_00d1b61c)(0), cVar4 == '\0')) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (((*(char *)((int)pClient + 0xa32) != '\0') || (DAT_00d1bd92 != '\0')) || (bVar2)) {
        Client_QuickBarActivateSkillSlot('\0');
      }
    }
    goto LAB_009234e7;
  }
  if ((DAT_00d1b61c == (code *)0x0) || (cVar4 = (*DAT_00d1b61c)(0), cVar4 == '\0')) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (*(char *)((int)pClient + 0xa32) == '\0') {
    if (DAT_00d1bd92 == '\0') {
      if (!bVar2) {
        iVar5 = 0;
        do {
          if ((iVar5 != 8) && (*(int *)(iVar5 + *(int *)(pVehicle + 0x260)) != 0)) {
            FUN_0056a260(0);
          }
          iVar5 = iVar5 + 4;
        } while (iVar5 < 0xc);
        goto LAB_009234e7;
      }
LAB_009231e7:
      if ((pClient[0x331] != 6) && (!bVar2)) {
        if ((*(char *)((int)pClient + 0xa87) == '\0') || (DAT_00d1b218 == '\0')) goto LAB_009234e7;
        *(uint8_t *)((int)pClient + 0xa87) = 0;
        aTStack_40[0].dwCoidLo = DAT_00a158b8;
        aTStack_40[0].bPad3 = (byte)DAT_00a158c4;
        aTStack_40[0].bPad4 = DAT_00a158c4._1_1_;
        aTStack_40[0].bPad5 = DAT_00a158c4._2_1_;
        aTStack_40[0].bPad6 = DAT_00a158c4._3_1_;
        aTStack_40[0].dwCoidHi = DAT_00a158bc;
        aTStack_40[0].bGlobal = (byte)DAT_00a158c0;
        aTStack_40[0].bPad0 = DAT_00a158c0._1_1_;
        aTStack_40[0].bPad1 = DAT_00a158c0._2_1_;
        aTStack_40[0].bPad2 = DAT_00a158c0._3_1_;
        fStack_a0 = 0.0;
        fStack_9c = 0.0;
        fStack_98 = 0.0;
        fStack_94 = 0.0;
        fStack_b4 = *(float *)(DAT_00d17948 + 0xc);
        uStack_b0 = *(uint32_t /* width from decompiler */ *)(DAT_00d17948 + 0x10);
        FUN_0075c340(&fStack_b4,&fStack_88,&fStack_7c);
        fStack_60 = fStack_7c;
        fStack_5c = fStack_78;
        fStack_70 = fStack_88;
        fStack_58 = fStack_74;
        fStack_6c = fStack_84;
        uStack_54 = 0;
        fStack_68 = fStack_80;
        uStack_64 = 0;
        FUN_004cff70(&fStack_70,&fStack_60,&fStack_a0,400);
        if (SQRT(fStack_a0 * fStack_a0 + fStack_9c * fStack_9c + fStack_98 * fStack_98) <= g_flZero)
        goto LAB_009234e7;
        piVar7 = *(int **)(*(int *)(DAT_00d1b6d8[1] + 4) + 0xa4 + (int)DAT_00d1b6d8);
        if ((piVar7 == (int *)0x0) || (iVar5 = (**(code **)(*piVar7 + 0x1c8))(), iVar5 == 0)) {
          if ((*(char *)((int)pClient + 0xa87) != '\0') && (DAT_00d1b218 != '\0')) {
            piVar7 = DAT_00d1b6d8;
            if (DAT_00d1b6d8 != (int *)0x0) {
              piVar7 = (int *)(*(int *)(DAT_00d1b6d8[1] + 4) + 4 + (int)DAT_00d1b6d8);
            }
            Skill_GatherTargetsInArea
                      (aTStack_40,0,DAT_00d1b644,piVar7,&fStack_a0,0x41c80000,1,2,0,0,1,0,1,0,
                       0xbf800000);
            if ((((aTStack_40[0].dwCoidLo & aTStack_40[0].dwCoidHi) != 0xffffffff) &&
                (pvVar8 = Object_ResolveFromTFID(aTStack_40), pvVar8 != (void *)0x0)) &&
               (pvVar8 != *(void **)((int)DAT_00d1b6d8 + *(int *)(DAT_00d1b6d8[1] + 4) + 0xa4))) {
              FUN_005172d0(pvVar8);
            }
          }
          goto LAB_009234e7;
        }
        (**(code **)(**(int **)(*(int *)(DAT_00d1b6d8[1] + 4) + 0xa4 + (int)DAT_00d1b6d8) + 0x1c8))
                  ();
        iVar5 = FUN_00404c90();
        fStack_b4 = *(float *)(iVar5 + 8) - fStack_98;
        pfVar6 = (float *)FUN_00404c90();
        if (DAT_00a111b0 <=
            SQRT(fStack_b4 * fStack_b4 + (*pfVar6 - fStack_a0) * (*pfVar6 - fStack_a0)))
        goto LAB_009234e7;
      }
    }
  }
  else if (DAT_00d1bd92 == '\0') goto LAB_009231e7;
  FUN_00922270();
LAB_009234e7:
  // ---------------------------------------------------------------------------
  // SECTION 12: Secondary weapons / QB slot-1 fire (DAT_00d1bdc6 edge or analog ch1)
  // ---------------------------------------------------------------------------
  if (((DAT_00d1bdc6 != '\0') && (DAT_00d1bdc7 != '\0')) ||
     ((DAT_00d1b61c != (code *)0x0 && (cVar4 = (*DAT_00d1b61c)(1), cVar4 != '\0')))) {
    DAT_00d1bdc7 = '\0';
    if ((*(char *)(DAT_00d1b6d8[0x94] + 0x101) == '\0') && (pClient[0x183] == 1)) {
      Input_TryFireSecondaryWeapons();
    }
    else if (*(char *)((int)DAT_00d1b6d8 + 0x6b9) != '\0') {
      Client_QuickBarActivateSkillSlot('\x01');
    }
  }
  // ---------------------------------------------------------------------------
  // SECTION 13: HANDBRAKE - continuous latch (digital Brake DAT_00d1bd5e + analog ch 8)
  //   Engaged: SetHandbrake(1) @ VehicleEntity_SetHandbrake 0x004f3620 → entity+0x61c
  //            Latch pClient+0xa31 = 1; clear auto-drive pClient[0x319].
  //   Released: if latch set and drive-enabled → clear latch + SetHandbrake(0).
  //   No 0xC7 gate on handbrake setter (unlike thr/steer).
  // ---------------------------------------------------------------------------
  if ((DAT_00d1bd5e == '\0') &&
     ((DAT_00d1b61c == (code *)0x0 || (cVar4 = (*DAT_00d1b61c)(8), cVar4 == '\0')))) {
    if ((*(char *)(pVehicle + 0x101) == '\0') && (*(char *)((int)pClient + 0xa31) != '\0')) {
      *(uint8_t *)((int)pClient + 0xa31) = 0;
      VehicleEntity_SetHandbrake(0);
    }
  }
  else {
    *(uint8_t *)(pClient + 0x319) = 0;
    if (*(char *)(pVehicle + 0x101) == '\0') {
      *(uint8_t *)((int)pClient + 0xa31) = 1;
      VehicleEntity_SetHandbrake(1);
      if ((DAT_00d1a860 == '\0') && (*(char *)(pClient[0x31c] + 0x21) == '\0')) {
        FUN_005081d0();
      }
      FUN_004f3700();
      if ((DAT_00d1a860 == '\0') && (DAT_00d1d866 == '\0')) {
        *(uint8_t *)((int)pClient + 0xa32) = 0;
      }
    }
  }
  if (((DAT_00d1be2e != '\0') && (DAT_00d1be2f != '\0')) &&
     ((DAT_00d1be2f = '\0', 0 < DAT_00d1b6d8[0x1ad] ||
      (DVar9 = GetTickCount(), 5000 < DVar9 - _DAT_00d1f0c8)))) {
    _DAT_00d1f0c8 = GetTickCount();
    FUN_0091d460();
  }
  if ((DAT_00d1cafa != '\0') && (DAT_00d1cafb != '\0')) {
    DAT_00d1cafb = '\0';
    FUN_0091f6b0();
  }
  // ---------------------------------------------------------------------------
  // SECTION 14: Push drive axes → controller (thr + handbrake; NOT steer)
  // Gate: vehicle+0x101 == 0. Cross-ref VehicleEntity_PushDriveAxesToController @ 0x004fbc10.
  // Steer remains on entity+0x618 for applyAction consumers.
  // ---------------------------------------------------------------------------
  if (*(char *)(pVehicle + 0x101) == '\0') {
    VehicleEntity_PushDriveAxesToController();
  }
  // ---------------------------------------------------------------------------
  // SECTION 15: Camera aim epilogue - project look vector into world camera slots
  // ---------------------------------------------------------------------------
  fStack_b4 = DAT_00d1d86c;
  uStack_b0 = DAT_00d1d870;
  FUN_0075c340(&fStack_b4,&fStack_88,&fStack_7c);
  fVar10 = (float10)FUN_004cd220(fStack_88,fStack_80);
  iVar5 = *(int *)(DAT_00d1b644 + 0xe894);
  fVar11 = (float)(((float10)fStack_84 - fVar10) / ABS((float10)fStack_78));
  *(float *)(iVar5 + 0x11c) = fStack_88 + fVar11 * fStack_7c;
  *(float *)(iVar5 + 0x120) = fStack_84 + fStack_78 * fVar11;
  *(float *)(iVar5 + 0x124) = fStack_80 + fVar11 * fStack_74;
  return 1;
}
