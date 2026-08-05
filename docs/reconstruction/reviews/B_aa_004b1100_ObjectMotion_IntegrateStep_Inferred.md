# Review B (skeptical / adversarial): `ObjectMotion_IntegrateStep_Inferred` / `FUN_004b1100` @ `0x004b1100`

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b1100` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004b1100_ObjectMotion_IntegrateStep_Inferred.md` |
| **Verdict** | **accept-with-gaps** on CF/ABI/role; **needs-more-evidence** on product symbol + nested force helpers |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is `Math_QuatInverseRotateDelta` | **Falsified** — that is a leaf callee at `0x004e8590` |
| 2 | plain `ret` / 0 stack args | **Falsified** — **`ret 0xC`** (3 stack args) |
| 3 | Always uses path sampling | **Falsified** — path branch only when `*host_path != 0` |
| 4 | Always runs force helpers | **Falsified** — each gated by `def+0x1e4` bits; attach path bypasses |
| 5 | Writes host transform in-place only | **Partial** — primarily mutates **slot** pos/orient; host fields mostly read |
| 6 | Scaffold name is domain English | **Falsified** — NestedNamedCallee chain is not role |
| 7 | Product name sealed | **Open** |
| 8 | Runtime / bit-exact | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ret 0xC thiscall | **Confirmed** | stack imbalance (`FUN_004b4620` chain) |
| motion integrate role | **High** | mis-port as pure math leaf |
| path vs free branch | **Confirmed** | wrong pose source |
| constants 1.0/2.0/0.5/6.0/-1.0/0.01 | **Confirmed** | formula drift |
| Product C++ name | **Open** | docs only |
| Nested force helper CF | **Open** | incomplete port if assumed trivial |

---

## 3. Surviving contract for AutoCore

```
// thiscall, ret 0xC
void ObjectMotion_IntegrateStep(slot, enable_hf_y, ctx, dt):
  pos = &slot.xyz            // +0x178
  snap = *pos
  host = slot.host
  def  = slot.def
  if host.path == null:
    if nested_gate: basis_prep; QuatInverseRotateDelta; QuatPeer
    if attach_gate:
      chase_attach(sample, host+0x880, def.max_speed, dt)
    else:
      if def.bits & FORCE_A: helper_A(...)
      if def.bits & FORCE_B: helper_B(...)
      if def.bits & FORCE_C: helper_C(...)
      if def.bits & FORCE_D: if helper_D_fail: slot.timer = -1; return
                            else rebuild local basis with factor 2.0
      if enable_hf_y and host.flag: clamp Y to heightfield+0.01; maybe bounce Y vel
  else:
    sample path[slot.path_index]; transform; optional look-ahead bias
  if host.mode == 2: slot.orient = normalize(pos - snap)
  elif host.mode == 4: slot.orient = host.facing
  if nested_vel_gate: pos += host.lin_vel * dt
```

---

## 4. Falsification notes

### 4.1 “Is the quat leaf”

`FUN_004e8590` is sealed math; this VA is the **sole consumer** orchestrating prep + integrate. Do not collapse them.

### 4.2 stdcall trap

Epilogue is `C2 0C 00`, not `C3`. Three stack formals required.

### 4.3 “Always attach chase”

Attach only when `(def+0x3e3 & 8) && host+0xc`. Force helpers are the complementary free path.

### 4.4 Early return on force-D fail

Writes `slot[0x5c] = -1.0` (`DAT_00aaa668`) and returns — ports must not fall through to post-modes.

---

## 5. Open questions

1. Retail symbol / product class name of motion slot.
2. Full taxonomy of `def+0x1e4` force bits.
3. Whether `param_3` is always the same flag type across both callers.
4. Bit-exact / runtime — open.

**Verdict:** **accept-with-gaps** on sealed CF skeleton, ABI, constants, and role. Reject “plain ret math leaf” overclaims.
