# Annotated low-level: FUN_005fdf20 → hkDefaultAnalogDriverInput_FilterSteer_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_005fdf20` |
| VA | `0x005fdf20`–`0x005fdf97` inclusive (**120 B** / `0x78`) |
| System | **input-drive-control** |
| Date | 2026-08-05 (MEGA-026 OWN dual refresh) |
| Promoted name | `hkDefaultAnalogDriverInput_FilterSteer_Inferred` |
| Ghidra name | `FUN_005fdf20` |
| Parent | `hkDefaultAnalogDriverInput_calcStatus` @ `0x005fe520` |

---

## Machine-level notes

- Source: raw capture for `aa_005fdf20` + MEGA-026 live re-verify.
- **Leaf** FPU helper: no callees; three plain `RET` exits; return float on ST0.
- **ABI sealed:** ECX = `this` (same object as calcStatus `ESI`); no stack args; caller `MOV ECX,ESI` then `FSTP [ESI+0x14]`.
- Decompiler shows `__fastcall` with `param_1` — machine is **thiscall** (ECX this only). Prefer assembly.
- `DAT_00aaa668` = **−1.0f** (shared with calcStatus pedal sign flip).
- `g_flZero` @ `0x00a0f518` = 0.0f; `g_flOne` @ `0x00a0f2a0` = 1.0f.
- Parent plate (WI-MOV-005): status `+0x14` = **steer via this function**.

### This layout (reads only)

| Offset | Role | Conf |
|---|---|---|
| `+0x1c` | raw signed steer input | **High** (loaded first; sign source) |
| `+0x28` | inner-zone upper threshold | **High** |
| `+0x2c` | inner-zone slope | **High** |
| `+0x30` | outer-zone slope | **High** |
| `+0x34` | outer-zone base / intercept | **High** |
| `+0x38` | deadzone threshold | **High** |

### Control flow

```text
abs = |raw(+0x1c)|
if abs < deadzone(+0x38): return 0.0
sign = (raw > 0) ? +1.0 : −1.0     // COMISS vs 0; JA keeps +1 else loads −1
if abs < inner(+0x28):
    return (abs − deadzone) * slope_inner(+0x2c) * sign
else:
    return ((abs − inner) * slope_outer(+0x30) + base(+0x34)) * sign
```

---

## Pseudocode (annotated)

```c
// ECX = hkDefaultAnalogDriverInput* this
// Returns float on FPU ST0; plain RET; leaf
float __thiscall hkDefaultAnalogDriverInput_FilterSteer_Inferred(
    hkDefaultAnalogDriverInput *this)
{
  float abs_steer;
  float sign;

  abs_steer = ABS(this->raw_steer_0x1c);           // |+0x1c|
  if (abs_steer < this->steer_deadzone_0x38) {
    return 0.0f;                                   // g_flZero
  }
  sign = 1.0f;                                     // g_flOne
  if (this->raw_steer_0x1c <= 0.0f) {
    sign = -1.0f;                                  // DAT_00aaa668
  }
  if (abs_steer < this->steer_inner_thresh_0x28) {
    // inner ramp above deadzone
    return (abs_steer - this->steer_deadzone_0x38)
         * this->steer_inner_slope_0x2c
         * sign;
  }
  // outer ramp + intercept
  return ((abs_steer - this->steer_inner_thresh_0x28)
         * this->steer_outer_slope_0x30
         + this->steer_outer_base_0x34)
         * sign;
}
```

---

## Call graph

| Role | Target |
|---|---|
| Sole caller | `hkDefaultAnalogDriverInput_calcStatus` `0x005fe520` site `0x005fe58d` → stores result at status `+0x14` |
| Callees | none |
| Sibling helpers | `hkDefaultAnalogDriverInput_calcReverse` `0x005fe0b0` (handbrake/reverse path of same calcStatus) |

---

## Open questions / gaps

- Product/Havok SDK English for this exact helper (may be inline in retail SDK `calcStatus`) → `_Inferred`.
- Field English for `+0x28..+0x38` tuning knobs beyond structural roles.
- Runtime / bit-exact / differential (Terminal **false**).
