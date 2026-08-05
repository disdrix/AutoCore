# Review B (skeptical / adversarial): `NDSpecialFX_HostTick_Inferred` / `FUN_004b8ed0` @ `0x004b8ed0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b8ed0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004b8ed0_NDSpecialFX_HostTick_Inferred.md` |
| **Verdict** | **accept-with-gaps** on CF/ABI/role; **needs-more-evidence** on product symbol + full free residual |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is DeactivateClear itself | **Falsified** — calls `FUN_004b7150`; returns 1 after |
| 2 | plain `ret` / no stack cleanup | **Falsified** — epilogue **`C2 04 00`** |
| 3 | Always ticks every frame | **Falsified** — 5s rate gate + type switch can deactivate without tick |
| 4 | Frees all children itself always | **Falsified** — only destroy-pending (`+0x90e bit0`); DeactivateClear marks |
| 5 | Return value unused | **Falsified** — AL 0/1 is explicit; callers (e.g. `FUN_004fc400`) consume |
| 6 | Scaffold name (Input_PollBound…) is role | **Falsified** — ownership is SpecialFX host |
| 7 | Product name sealed | **Open** |
| 8 | Runtime / bit-exact | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ret 4 thiscall | **Confirmed** | stack imbalance in callers |
| host tick / deactivate role | **High** | mis-port as pure teardown |
| 5s stamp gate | **Confirmed** | over-tick or never-tick bugs |
| DeactivateClear linkage | **Confirmed** | double-free / skip-teardown |
| Product C++ name | **Open** | docs only |
| operator_delete edges | **Probable** | list corruption if mis-modeled |

---

## 3. Surviving contract for AutoCore

```
// thiscall, ret 4
int NDSpecialFX_HostTick(void* fx, void** ctx):
  counter++
  now = g_dwClientTickMs
  if now - fx.stamp_ms < 5001: active = true
  else switch fx.event_type:
    case 4: active = OptionalReenter()  // FUN_004b6a80
    case {2,3,5,6,0xC,0xD,0xE,0x13,0x14,0x15,0x17}: active = false
    default: active = true
  if not active:
    DeactivateClear(fx); return 1
  fx.stamp_ms = now
  if LivenessDone(fx):              // FUN_004b7330 != 0
    DeactivateClear(fx); return 1
  UpdateParamMapTransforms(fx)
  if cull_ok:
    for child in fx.owned(+0x204):
      if child.flags & DESTROY_PENDING:
        profile("Destroy"); unlink node; free child resources
      else:
        CVOGObject_Tick(child, *ctx, clock)
    // residual lists +0x1e0 / +0x210 / +0x21c
    HostNotify(fx)                  // FUN_004b6910
  return 0
```

---

## 4. Falsification notes

### 4.1 “Is DeactivateClear”

DeactivateClear is a callee (W23-H sealed, plain `ret`). This VA owns rate/type policy + child tick/free orchestration.

### 4.2 “stdcall void”

`ret 4` + non-void AL. Ports must clean 4 bytes and honor 0/1.

### 4.3 “Always free children”

Only when `+0x90e & 1`. Marking is DeactivateClear's job; free is this tick's job when already marked — matches W23-H B-review claim #4.

### 4.4 Rate constant off-by-one

Image compares to **`0x1388`** with **`jbe`** ⇒ effective `< 0x1389` as decompiler states. Do not hardcode 5000 without matching that relation.

---

## 5. Open questions

1. Retail symbol.
2. Product names for event types that force deactivate.
3. Whether all five callers share identical host layout (likely yes).
4. Bit-exact / runtime — open.

**Verdict:** **accept-with-gaps** on sealed CF, ABI, rate/type gates, deactivate linkage. Reject “plain void ret” and “is DeactivateClear” overclaims.
