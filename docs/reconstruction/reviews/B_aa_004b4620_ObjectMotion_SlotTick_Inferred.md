# Review B (skeptical / adversarial): `ObjectMotion_SlotTick_Inferred` / `FUN_004b4620` @ `0x004b4620`

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b4620` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W26-H) |
| **Counterpart** | `reviews/A_aa_004b4620_ObjectMotion_SlotTick_Inferred.md` |
| **Verdict** | **accept-with-gaps** on CF/ABI/role; **needs-more-evidence** on nested helper English + product name |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This **is** IntegrateStep | **Falsified** — calls dualed `FUN_004b1100`; owns radius/timers |
| 2 | plain `ret` / cdecl | **Falsified** — epilogue **`C2 08 00`** (ret 8) |
| 3 | Void / no return used | **Falsified** — AL 0\|1; caller unlinks on 0 |
| 4 | Both stack args are pure floats | **Falsified** — `param_2` immediately `(int)` cast as flag |
| 5 | Always pulls position | **Falsified** — only when radius≠0 and outside sphere |
| 6 | Constants are 0.5 / 1.0 | **Falsified** — `0.4`, `−0.5`, `≈0.99` via `read_memory` |
| 7 | Product name sealed | **Open** |
| 8 | Runtime / bit-exact | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ret 8 thiscall + AL bool | **Confirmed** | stack imbalance / never-remove slots |
| Outer tick role (not pure integrate) | **High** | miss radius/timer policy |
| Radius constants | **Confirmed** | wrong pull distance |
| Nested integrate linkage | **Confirmed** | wrong pose step |
| Nested helper semantics | **Probable** | side effects if mis-ported |
| Product C++ name | **Open** | docs only |
| Runtime | **Open** | |

---

## 3. Cross-check against raw + bytes

```
counter(DAT_00d17958+0x13c)++
if host gate: AL=0; ret 8
dirty=0
if radius && dist2 > r^2:
  if bit2: AL=0; ret 8
  // pull with 0.4 / -0.5 / normalize / r*0.99; optional heightfield
  FUN_004b0f80(0); dirty=1
if (t_primary -= dt) <= 0:
  dirty=1; if !FUN_004b0f80(1): AL=0; ret 8
if host+0x7fb:
  if (t_secondary -= dt) <= 0: AL=0; ret 8
FUN_004b2b90(dirty, dt)
FUN_004b1100(flag, dirty, dt)   // IntegrateStep
if slot[2]: FUN_004b18f0(flag)
slot_byte(+0x240)=0; AL=1; ret 8
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Epilogue: `B0 01 5E 83 C4 28 C2 08 00`.

---

## 4. Surviving contract for AutoCore

```
// thiscall, ret 8
int ObjectMotion_SlotTick(void* slot, int flag, float dt):
  // return 0 → parent list removes slot; 1 → keep
  // honor radius pull constants 0.4 / -0.5 / ~0.99
  // always call IntegrateStep path after timers (when not early-out)
```

Do **not** replace with bare IntegrateStep. Do **not** treat `param_2` as a float distance.

---

## 5. Falsification notes

### 5.1 “Is IntegrateStep”

W24-C dualed `FUN_004b1100` as integrate; this VA is the **caller** that supplies `(flag, dirty, dt)` after radius/timer policy.

### 5.2 “cdecl void”

`ret 8` + non-void AL. Ports must clean 8 bytes and honor 0/1 for list removal.

### 5.3 “float,float formals”

Decompiler types both as float, but first formal is only used as `(int)` flag and forwarded to integrate/helpers. Second is true dt.

---

## 6. Open questions

1. Retail name / product class of slot.
2. Exact roles of `FUN_004b0f80` modes 0/1 and `FUN_004b2b90`.
3. Whether all `FUN_005bb5e0` hosts share identical slot layout (likely yes).
4. Bit-exact / runtime — open.

**Verdict:** **accept-with-gaps** on sealed CF, ABI, constants, integrate linkage. Reject “is IntegrateStep” and “plain void ret” overclaims.
