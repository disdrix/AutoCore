# Review B (skeptical / adversarial): `aa_00508280` CVOGHBBase_GetRemainingSeconds

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508280` |
| **VA** | `0x00508280` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (residual seal; prior 2026-07-23) |
| **Counterpart** | `reviews/A_aa_00508280_CVOGHBBase_GetRemainingSeconds.md` |
| **Live tools** | Ghidra `decompile_function` + `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept** (body High; dual-field period model sealed) |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Returns **milliseconds** | **Falsified** — `fmul [0x00a0f72c]` = **0.001f** → seconds |
| 2 | Ignores **nPeriodCounter** | **Falsified** — `(counter-1)*period` after base clamp |
| 3 | Clamps only at end | **Falsified** — early `jns` clamp on **base** only; final rem uses signed fild bias, not clamp-to-zero |
| 4 | Drives list Tick / schedule | **Falsified** — pure float return; no list stores; UI/readiness consumers |
| 5 | Period field is **+0x0C** (SetPeriodAndCounter target) | **Falsified** — machine loads **`[ecx+0x08]`** only for period; never reads +0x0C |
| 6 | Uses combat-pool sentinel at +0x0C as period | **Falsified** — this body never loads +0x0C; sentinel is sibling Reschedule/SetPeriod domain |
| 7 | Stack formals / non-float return | **Falsified** — ECX this; result in x87 ST0; bare `ret` |
| 8 | `_DAT_00aaa5dc` unknown / non-2^32 | **Falsified** — LE `00 00 80 4f` = **4294967296.0f** |
| 9 | Scale is not 0.001 | **Falsified** — LE `6f 12 83 3a` @ `0x00a0f72c` = **0.001f** |
| 10 | No callers | **Falsified** — 15 code xrefs (tooltips, readiness, debug dump) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Formula structure (clamp base + multi-period + scale) | **High** | Wrong CD UI / readiness windows |
| Period offset **+0x08** | **High** | Wire period from wrong field; combat dual-field bug |
| Does not use **+0x0C** sentinel | **High** | Treating SetPeriod value as remaining period |
| ms→s scale 0.001 | **High** | 1000× display error |
| UI-only / non-authority | **High** | Porting remaining as server schedule |
| Counter==0 / negative rem display | **Tentative** | Rare bad tooltip if counter invalid |
| Full caller semantic map | **Probable** | Missed consumer class |

---

## 3. Cross-check against raw / machine

```
base = max(0, *(this+0x14) - g_dwClientTickMs + *(this+0x08))
rem  = (*(this+0x10) - 1) * *(this+0x08) + base
return (float)rem_with_u32_bias_if_neg * 0.001f
```

Clean ≡ raw CF ≡ decompile ≡ 54-byte body.  
No invented clamps-to-zero on final rem; no callees.

### Dual-field period model (survives attack)

| Offset | Writers (siblings) | Readers in this family |
|---|---|---|
| **+0x08** `nPeriodMs` | Regeneration_ctor pulse (3000/5000); other HB setup | **GetRemainingSeconds**, **TryFire** elapsed gate |
| **+0x0C** `nPeriodSentinel` | **SetPeriodAndCounter** | **RescheduleAfterFire** (−1000 → delay 0) |
| **+0x10** `nPeriodCounter` | SetPeriodAndCounter (optional); Reschedule decrements | **GetRemainingSeconds** multi-period; Reschedule |
| **+0x14** `dwLastFireTickMs` | StampLastFireTime; TryFire on fire | **GetRemainingSeconds**; TryFire |

Combat pool: `SetPeriodAndCounter(-1000, true)` seeds **+0x0C/+0x10**; real pulse lives at **+0x08**. GetRemainingSeconds therefore reports against **pulse period**, not the −1000 sentinel — if counter is still −1000, multi-period math is nonsense; `FUN_00578550` **skips** Remaining when `nPeriodCounter == -1000`.

---

## 4. Surviving contract for AutoCore

```
float CVOGHBBase_GetRemainingSeconds(HB* this /* ECX */):
  // reads only: +0x08 period, +0x10 counter, +0x14 lastFire, g_dwClientTickMs
  // does NOT read +0x0C sentinel; no writes; no callees
  base = max(0, lastFire - g_dwClientTickMs + period_ms)
  remMs = (counter - 1) * period_ms + base
  return to_float_signed_bias(remMs) * 0.001f   // globals 0x00aaa5dc, 0x00a0f72c

Use:
  - Client UI "Remaining" tooltips / CD overlays
  - Client readiness gates comparing rem seconds to skill windows
  - Debug combat dumps
  - NOT as server schedule authority (TryFire / Reschedule own that)
  - NOT as substitute for list delay ms

Port note:
  - Keep dual period fields; never alias +0x08 with SetPeriodAndCounter's +0x0C
```

---

## 5. Open questions

1. Name remaining `FUN_*` callers for consumer taxonomy.
2. Runtime capture: tooltip text vs HB fields under live tick.
3. Whether any path intentionally calls with counter ≤ 0.
4. Bit-exact / differential still deferred.

**Verdict:** **accept** (body High; prior +0x8 vs +0xc gap closed; UI contract sealed)
