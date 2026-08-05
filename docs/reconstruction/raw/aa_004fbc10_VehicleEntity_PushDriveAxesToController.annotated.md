# Annotated low-level: VehicleEntity_PushDriveAxesToController

| Field | Value |
|---|---|
| Stable ID | `aa_004fbc10` |
| VA | `0x004fbc10` |
| System | input-drive-control |
| Date | 2026-07-23 (annotate); residual strengthen 2026-07-29 pass 2 (live Ghidra) |
| Dual residual | sealed in dual A/B 2026-07-29 pass 2 — see `tmp/a_004fbc10.md` |

---

## Machine-level notes

- Source: raw capture for `aa_004fbc10` (do not overwrite raw body).
- Prefer assembly when decompiler conflicts.
- Input controller `ctrl = *(entity+0x1a0)+8` is **layout-distinct** from Havok `VehicleAction`.
- Constants sealed via verified `read_memory` table in `physics/verified/fn_004fbc10_pushDriveAxes.md` (re-read 2026-07-29 pass 2).
- Live re-decompile confirmed body CF ≡ raw; callees `FUN_004c4e20` / `FUN_00404a20` / `FUN_004e8a40` decompiled this pass.

### Sealed residuals (2026-07-29)

| Topic | Seal |
|---|---|
| Reverse clamp | Positive ceiling **0.9** only when `ctrl+0x19`; not ±0.9 |
| Speed-cap operands | `local_3c < entity+0x10c` (derived max vs requested speed field) |
| Overspeed thr zero | Clears thr that **continues travel** polarity under Accel=−1 / Reverse=+1 |
| Early `SQRT\|v\|` | Computed then slot reused as basis storage — no later use as speed compare |
| Steer | **Not** written; consumer `VehicleAction_applyAction` |
| Hard-stop | thr0 + HB1 + return; **no** `+0x61c` copy |
| Bonus init `fStack_40` | Port assume **0**; no explicit zero in decompile |
| `FUN_004c4e20` baseMax | `*(entity+0x1f4)`; optional `+ *(driver+0xd48)` if `DAT_00b037d4` (image **0**) |
| Outer vs inner `+0xd48` | Outer bonus uses `DAT_00af1854` (image **1**); **not** the same gate as `b037d4` |
| Basis helpers | `FUN_00404a20` → quat at phys `+0x30` or entity `+0x94`; `FUN_004e8a40` forward × **2.0** |

---

## Pseudocode (annotated copy of raw)

```c
/* WI-MOV-002: Push entity drive axes into input controller (not Havok VA).

   Requires entity+0x101==0 and entity+0x1a0!=0.
   ctrl = *(entity+0x1a0)+8

   Writes:
     ctrl+0x25 = 0
     if entity+0x109: ctrl+0x20=0, ctrl+0x24=1, return
     ctrl+0x20 = entity+0x614 (longitudinal; Accel=-1, Reverse=+1 at producers)
     if ctrl+0x19: if thr >= DAT_00a0f734 (0.9) thr = 0.9  // positive ceiling only
     ... derive local_3c max; if local_3c < entity+0x10c, may zero thr by travel polarity ...
     ctrl+0x24 = entity+0x61c (handbrake)

   entity+0x618 is NOT written — applyAction steer ramp target.
   entity+0x61c ALSO read in VehicleAction_calcWheelTorque (rear torque *0.5).

   Callers: DriveControlTick, PollBoundActions, Vehicle_setDrivingInputs, SetDriveAxes, MoveToTarget3DPoint, etc. */

void __fastcall VehicleEntity_PushDriveAxesToController(int param_1)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  float *pfVar5;
  int iVar6;
  bool bVar7;
  float10 fVar8;
  float fVar9;
  float fStack_40;
  float local_3c;
  float local_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  
  if ((*(char *)(param_1 + 0x101) == '\0') && (*(int *)(param_1 + 0x1a0) != 0)) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x1a0) + 8);
    *(undefined1 *)(iVar2 + 0x25) = 0;
    if (*(char *)(param_1 + 0x109) != '\0') {
      *(undefined4 *)(iVar2 + 0x20) = 0;
      *(undefined1 *)(iVar2 + 0x24) = 1;
      return;
    }
    fVar9 = *(float *)(param_1 + 0x614);
    *(float *)(iVar2 + 0x20) = fVar9;
    if (*(char *)(*(int *)(*(int *)(param_1 + 0x1a0) + 8) + 0x19) != '\0') {
      if (DAT_00a0f734 <= fVar9) {
        fVar9 = DAT_00a0f734;
      }
      *(float *)(iVar2 + 0x20) = fVar9;
    }
    if (*(int *)(param_1 + 8) == 0) {
      pfVar5 = (float *)&DAT_00b041b0;
    }
    else {
      pfVar5 = (float *)(*(int *)(*(int *)(param_1 + 8) + 0x3c) + 0x40);
    }
    fVar9 = *(float *)(param_1 + 0x10c);               /* requested/target speed field */
    piVar3 = *(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1);
    local_34 = SQRT(pfVar5[2] * pfVar5[2] + pfVar5[1] * pfVar5[1] + *pfVar5 * *pfVar5);
    /* local_34 |v| is SSA-dead; slot reused below as basis storage */
    if ((piVar3 == (int *)0x0) || (iVar6 = (**(code **)(*piVar3 + 0x1d8))(), iVar6 == 0)) {
      local_3c = 0.0;
    }
    else {
      (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) + 0x1d8))();
      fVar8 = (float10)FUN_004c4e20();
      local_3c = (float)fVar8;
    }
    iVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x210))(0);
    if ((iVar6 != 0) && (DAT_00af1854 != '\0')) {
      iVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x210))(0);
      fStack_40 = *(float *)(iVar6 + 0xd48) + fStack_40;  /* bonus; init treat as 0 for port */
    }
    iVar6 = *(int *)(*(int *)(param_1 + 4) + 4);
    uVar4 = *(uint *)(iVar6 + 0xb8 + param_1);
    iVar6 = iVar6 + param_1;
    if (((uVar4 & 0x1000) != 0) ||
       ((*(int *)(iVar6 + 0xb0) != 0 && ((*(byte *)(*(int *)(iVar6 + 0xb0) + 0xb5) & 0x10) != 0))))
    {
      fStack_40 = fStack_40 - g_flOverheatCoolFrac;     /* 0.3 */
    }
    if (((uVar4 & 0x4000) != 0) ||
       ((*(int *)(iVar6 + 0xb0) != 0 && ((*(byte *)(*(int *)(iVar6 + 0xb0) + 0xb5) & 0x40) != 0))))
    {
      fStack_40 = fStack_40 + DAT_009cd0d8;             /* 0.5 */
    }
    fVar1 = *(float *)(*(int *)(*(int *)(iVar6 + 0xac) + 0x3c) + 0x634);  /* AbsoluteTopSpeed */
    local_3c = (fStack_40 + g_flOne) * local_3c;
    if ((fVar1 != DAT_00aaa668) && (fVar1 < local_3c)) {  /* sentinel -1.0 */
      local_3c = fVar1;
    }
    if (local_3c < fVar9) {
      pfVar5 = (float *)FUN_00404a20();
      local_34 = *pfVar5;
      fStack_30 = pfVar5[1];
      fStack_2c = pfVar5[2];
      fStack_28 = pfVar5[3];
      FUN_004e8a40(&local_34,&fStack_24);
      if (*(int *)(param_1 + 8) == 0) {
        pfVar5 = (float *)&DAT_00b041b0;
      }
      else {
        pfVar5 = (float *)(*(int *)(*(int *)(param_1 + 8) + 0x3c) + 0x40);
      }
      /* forwardSpeed = dot(vel, forward) */
      if (pfVar5[2] * fStack_1c + pfVar5[1] * fStack_20 + *pfVar5 * fStack_24 <= 0.0) {
        fVar9 = *(float *)(iVar2 + 0x20);
        bVar7 = fVar9 < 0.0;          /* thr Accel polarity "toward travel" when not going forward */
      }
      else {
        fVar9 = *(float *)(iVar2 + 0x20);
        bVar7 = 0.0 < *(float *)(iVar2 + 0x20);  /* thr Reverse polarity when going forward */
      }
      if (!bVar7 && fVar9 != 0.0) {
        *(undefined4 *)(iVar2 + 0x20) = 0;  /* zero thr that continues travel */
      }
    }
    *(undefined1 *)(iVar2 + 0x24) = *(undefined1 *)(param_1 + 0x61c);
  }
  return;
}
```

---

## Open questions

- Seal `FUN_004c4e20` field map under its own unit.
- Live-stack proof for `fStack_40` initial value.
- Runtime thr-cap capture; bit-exact / differential.
