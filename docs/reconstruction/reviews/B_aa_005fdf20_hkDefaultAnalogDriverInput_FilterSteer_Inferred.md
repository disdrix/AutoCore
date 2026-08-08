# Review B (skeptical / adversarial): `aa_005fdf20` hkDefaultAnalogDriverInput_FilterSteer_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fdf20` |
| **VA** | `0x005fdf20` |
| **Canonical name** | `hkDefaultAnalogDriverInput_FilterSteer_Inferred` |
| **Review date** | `2026-08-05` (MEGA-026 dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_005fdf20_hkDefaultAnalogDriverInput_FilterSteer_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `read_memory` + analyze/xrefs/callers + `disassemble_function` + assembly context |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is **accel** or **brake** filter | **Falsified** — reads `+0x1c` not `+0x20`; caller stores to **`+0x14` steer**, not `+0xc`/`+0x10` |
| 2 | This **is** `calcStatus` | **Falsified** — separate VA; leaf; calcStatus calls it once then writes handbrake/reverse |
| 3 | Stack args / `RET 4` thiscall with extra arg | **Falsified** — three plain **`RET`**; call site only `MOV ECX,ESI` + `CALL` |
| 4 | ECX is something other than the analog DI object | **Falsified** — same `ESI` as calcStatus this; body reads DI fields; result to `[ESI+0x14]` |
| 5 | Returns via EAX | **Falsified** — FLD/FMUL path leaves value on **ST0**; caller **`FSTP`** |
| 6 | Has callees / not a leaf | **Falsified** — analyze_function_complete callees=[]; no CALL in body |
| 7 | Sign is always +1 or uses raw without abs | **Falsified** — FABS then separate sign from COMISS vs 0 → ±1 / DAT_−1 |
| 8 | Deadzone is at +0x28 | **Falsified** — deadzone compare is **`[ECX+0x38]`**; `+0x28` is inner-zone split |
| 9 | `DAT_00aaa668` is not −1 | **Falsified** — bytes `00 00 80 bf` = −1.0f |
| 10 | Runtime Confirmed | **Fails** — open (Terminal false) |

---

## 2. Decisive machine dataflow

```text
// body
MOV  EAX, [ECX+0x1c]       // raw steer
FLD  abs(raw)
FLD  [ECX+0x38]            // deadzone
FCOMIP / JBE → continue else return 0
COMISS raw, 0 / JA → sign=+1 else sign=-1 (DAT_00aaa668)
COMISS [ECX+0x28], abs
  JA (abs < inner):  (abs - dz) * [+0x2c] * sign
  else:              (abs - inner) * [+0x30] + [+0x34]  then * sign
RET                    // plain, ×3

// call site 0x005fe58d in calcStatus
MOV  ECX, ESI
CALL 0x005fdf20
FSTP [ESI+0x14]            // status.steer
```

A ≡ B on live decompile + body hex + xrefs + assembly context.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Filtered-steer CF (deadzone/inner/outer) | **High** | wrong vehicle feel / control |
| ABI ECX=this, plain RET, ST0 return | **High** | stack/FPU corruption |
| Sole caller calcStatus → +0x14 | **High** | wrong status field |
| Field offset map +0x1c/28/2c/30/34/38 | **High** | bad tuning port |
| Product English for leaf symbol | Medium | naming only |
| Runtime Confirmed | **None** | open |

---

## 4. Surviving contract for AutoCore

```csharp
// Piecewise filtered steer for hkDefaultAnalogDriverInput (leaf)
// ECX=this; plain RET; float on ST0. Sole caller writes result to status.+0x14.
float FilterSteer(AnalogDriverInput self)
{
    float abs = Math.Abs(self.RawSteer);           // +0x1c
    if (abs < self.SteerDeadzone) return 0f;       // +0x38
    float sign = self.RawSteer > 0f ? 1f : -1f;
    if (abs < self.SteerInnerThresh)               // +0x28
        return (abs - self.SteerDeadzone) * self.SteerInnerSlope * sign; // +0x2c
    return ((abs - self.SteerInnerThresh) * self.SteerOuterSlope
            + self.SteerOuterBase) * sign;         // +0x30, +0x34
}
// Keep distinct from pedal→accel/brake path and calcReverse.
// Do not claim product/Havok symbol without PDB/SDK string.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/caller/offset roles. Residual product English → **accept-with-gaps**.
