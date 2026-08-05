# Review B (skeptical / adversarial): `CVOGObject_Tick` / `FUN_00595230` @ `0x00595230`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00595230` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00595230_CVOGObject_Tick.md` |
| **Verdict** | **accept-with-gaps** on phase CF/ABI; reject overclaims that this is Just-created-only or physics-step |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This **is** JustCreatedInit | **Falsified** — calls it as callee mode 0; own body is timers + pose |
| 2 | cdecl / plain ret | **Falsified** — epilogue **`C2 08 00`** |
| 3 | No stack args | **Falsified** — ret 8 ⇒ two dwords |
| 4 | Always updates pose | **Falsified** — gated on `+0x911==0` or `+0x90e&8`; lifetime path can early-out |
| 5 | Server authoritative physics step | **Falsified** — client gfx/parent sync; no island step |
| 6 | Multi-hit flush is primary role | **Falsified** — only on phase-timer expire with node flag |
| 7 | Product name sealed | **Open** |
| 8 | Runtime / bit-exact | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ret 8 thiscall | **Confirmed** | stack imbalance |
| Phase string map | **Confirmed** | wrong port structure |
| JustCreated mode 0 abort | **Confirmed** | infinite defer / drop init |
| dt first float formal | **High** | wrong timer rates |
| Second formal product type | **Low** | wrong ctx to `FUN_005942d0` |
| Nested quat formulas | **Medium** | visual pose drift |
| Product C++ name | **Open** | docs only |

---

## 3. Surviving contract for AutoCore

```
// thiscall; ret 8
void CVOGObject_Tick(void* self, float dt, uint32_t ctx):
  bump_counters(self)
  maybe_multi_tick_components(self)
  profile "Time etc.."
  countdown phase_timer; on_expire: pulse=1; maybe FlushMultiHits; advance reaction
  if lifetime_flag: countdown; maybe mark destroy; return
  if not_created or just_created_pending:
    profile "Update Parent Pos"
    sync pose from gfx or parent
    maybe warn zero geo
    cache velocity
    if just_created_pending:
      if delay>0: maybe copy peer pos; return
      if JustCreatedInit(self, 0)==0: return
      pulse=1
    if gfx:
      FUN_005942d0(pulse, ctx)
      velocity_or_integrate(...)
      clear just_created bit
  return

// NOT the full physics island step.
// NOT batch JustCreated (mode 1) — that is FUN_00594290.
```

---

## 4. Falsification notes

### 4.1 Collapse into JustCreatedInit

W22-H sealed JustCreated as separate unit. Tick **defers** to it and may abort when it returns 0. Ports that inline mode-1 batch semantics here break FX-owned objects.

### 4.2 Ignoring ret 8

Two stack args must be cleaned. Treating as plain ret corrupts SpecialFX caller `FUN_004b8ed0`.

### 4.3 Pose always runs

Created objects without just-created bit skip the big pose block (fall through to early `FUN_0076cef0` return at `LAB_0059544d` after lifetime handling).

---

## 5. Open questions

1. Retail symbol.
2. Exact product type of `ctx` / `*param_2` at sole call site.
3. Full bit dictionary for soft flags.
4. Bit-exact nested pose — open.

**Verdict:** **accept-with-gaps** — sealed tick phase CF + ABI + JustCreated linkage. Reject JustCreated-only / server-physics-step overclaims.
