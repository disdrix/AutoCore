# Review B (skeptical / adversarial): `ObjectMotion_ApplyStageParams_Inferred` / `FUN_004b2b90` @ `0x004b2b90`

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b2b90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W27-E) |
| **Counterpart** | `reviews/A_aa_004b2b90_ObjectMotion_ApplyStageParams_Inferred.md` |
| **Verdict** | **accept-with-gaps** on CF/ABI/role; **needs-more-evidence** on product field English |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This **is** IntegrateStep | **Falsified** — SlotTick calls this **before** dualed `FUN_004b1100` IntegrateStep |
| 2 | Always re-samples stage every tick | **Falsified** — only when dirty≠0; else continuous lerp |
| 3 | plain `ret` / single stack arg | **Falsified** — **`C2 08 00`** (ret 8) for dirty+dt |
| 4 | Returns bool | **Falsified** — void; no AL contract |
| 5 | progress = remaining/total | **Falsified** — `g_flOne - rem/total` (elapsed fraction) |
| 6 | Product field names sealed | **Open** |
| 7 | Runtime / bit-exact | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ret 8 thiscall void | **Confirmed** | stack imbalance |
| dirty reinit vs continuous | **High** | wrong motion params after stage advance |
| progress formula polarity | **Confirmed** | inverted lerps |
| Always rate*dt on continuous | **Confirmed** | missing integration |
| Nested FUN_004b2910 semantics | **Probable** | byte-channel wrong |
| Product C++ name / field labels | **Open** | docs only |
| Runtime | **Open** | |

---

## 3. Cross-check against raw + bytes

```
if dirty != 0:
  memcpy end-block stage+0x36c → slot+0x3e (0x1D dwords)
  flag-gated loads / RNG / FUN_004b2910 from stage bitmasks
  optional mirror rates if !slot+0x242 and host mode in {0,2}
  memcpy baseline slot+4 → slot+0x21 (0x1D dwords)
  return
progress = 1 - slot[0x5c]/slot[0x5d]
// flag-gated lerps baseline→end by progress
slot[0xb] += slot[9] * dt
return  // ret 8
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Epilogue: `5D 59 C2 08 00`.

---

## 4. Surviving contract for AutoCore

```
// thiscall, ret 8, void
void ObjectMotion_ApplyStageParams(void* slot, char dirty, float dt):
  if dirty:
    reinit from current stage template + snapshot baseline
  else:
    lerp by elapsed fraction; always integrate rate*dt into slot[0xb]
// Called before IntegrateStep in SlotTick
```

Do **not** merge into IntegrateStep. Do **not** invert progress to remaining fraction. Do **not** skip continuous path when dirty==0.

---

## 5. Falsification notes

### 5.1 “Is IntegrateStep”

W24-C dualed `FUN_004b1100` as integrate; this VA prepares params. SlotTick order: `004b2b90` → `004b1100`.

### 5.2 “Always dirty path”

Entry compares dirty early; continuous path is the fall-through used every tick when no stage advance / radius rebind.

### 5.3 “progress = rem/total”

Decompile uses `g_flOne - rem/total`. Inverting would reverse all lerps.

---

## 6. Open questions

1. Retail name / product class of param blocks.
2. Exact English for each `+0x3e0..3e3` bit.
3. Full dual of `FUN_004b2910` and `FUN_005bc120` call site.
4. Bit-exact / runtime — open.

**Verdict:** **accept-with-gaps** on sealed dual-path CF and ABI. Reject “is IntegrateStep” and “always reinit” overclaims.
