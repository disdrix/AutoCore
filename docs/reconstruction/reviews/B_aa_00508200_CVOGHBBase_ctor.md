# Review B (skeptical / adversarial): `aa_00508200` CVOGHBBase_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508200` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (residual seal; prior accept 2026-07-23) |
| **Counterpart** | `reviews/A_aa_00508200_CVOGHBBase_ctor.md` |
| **Live tools** | Ghidra `force_decompile` + `read_memory` + `get_struct_layout` + sibling ctor decompiles |
| **Verdict** | **accept** (simple ctor; dual-field + type-tag model sealed) |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Starts active (not dormant) | **Falsified** — machine `mov byte [eax+0x21], 1` |
| 2 | Zero lastFire | **Falsified** — stamps `g_dwClientTickMs` @ `0x00b041cc` into +0x14 |
| 3 | Single “period” field | **Falsified** — ctor zeros **both** +0x08 and +0x0C (dual model) |
| 4 | Full 0x28 zero-init | **Falsified** — **+0x22..+0x27 untouched** |
| 5 | +0x1C unused forever | **Falsified** — sibling type tags (1 / 4 / 8) |
| 6 | Plate `g_ActionSchedulerTickMs` ≠ client tick | **Falsified as distinct** — same VA load as StampLastFireTime |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dormant default | **High** | Fires before Start |
| lastFire seed | **High** | Immediate fire or long wait |
| Base vtbl | **High** | Wrong virtuals |
| Dual period (+0x08 vs +0x0C) | **High** | Combat-pool / Remaining wrong |
| Type tag +0x1C role | **High** (role); enum incomplete | Listener gates miss |
| +0x22..+0x27 garbage until subclass | **High** | Debounce/skill* noise if read early |

---

## 3. Cross-check against raw / machine

```
*this = PTR_FUN_009cdab0;
+0x1C = 0;  +0x21 = 1;  +0x08/+0x0C/+0x10 = 0;
+0x14 = g_dwClientTickMs;  +0x20 = 0;  +0x18 = 0;  +0x04 = 0;
// no stores to +0x22..+0x27
```

Clean ≡ raw decompile ≡ 45-byte machine. No callees.

### Type tag (+0x1C) — sibling seal (not written non-zero here)

| Value | Writer | Consumer note |
|------:|---|---|
| **0** | **this ctor** | base / unset |
| **1** | `CVOGHBSkillBase_ctor` (`param_1[7]=1`) | `HBSkillListener` requires `+0x1c==1` before RTTI |
| **4** | `Vehicle_CreateWeaponTrackAction` (`param_1[7]=4`) | weapon-track HB class |
| **8** | `CVOGHBOKToCastAgain_ctor` | cast-again HB class |

Ghidra field name `nUnusedOrFlags` is **misleading** — treat as **`nTypeTag`** for ports.

### Dual period (survives attack)

| Offset | Ctor | Later writers | Later readers |
|---|---|---|---|
| **+0x08** `nPeriodMs` | 0 | Regen 3000/5000; OKToCastAgain duration; WeaponTrack 30 | **TryFire** elapsed / −1000 gate; **GetRemainingSeconds** |
| **+0x0C** `nPeriodSentinel` | 0 | **SetPeriodAndCounter** | **RescheduleAfterFire** (−1000 → delay 0) |
| **+0x10** `nPeriodCounter` | 0 | SetPeriod (optional mirror); Reschedule `--` | GetRemaining multi-period; Reschedule |

Combat pool: `SetPeriodAndCounter(-1000,true)` then **pulse at +0x08** — never alias the two dwords.

---

## 4. Surviving contract for AutoCore

```
void CVOGHBBase_ctor(HB* this /* ECX */):
  this->pVTable          = &PTR_FUN_009cdab0;   // 0x009cdab0
  this->nRefOrFlags      = 0;                   // +0x04
  this->nPeriodMs        = 0;                   // +0x08  real pulse
  this->nPeriodSentinel  = 0;                   // +0x0C  SetPeriod/Reschedule
  this->nPeriodCounter   = 0;                   // +0x10
  this->dwLastFireTickMs = g_dwClientTickMs;    // +0x14  @ 0x00b041cc
  this->pOwnerObject     = nullptr;             // +0x18
  this->nTypeTag         = 0;                   // +0x1C  (Ghidra: nUnusedOrFlags)
  this->cStopped         = 0;                   // +0x20
  this->fDormant         = true;                // +0x21
  // +0x22..+0x27 NOT initialized

Post-ctor subclass pattern:
  *vtbl = derived;
  SetPeriodAndCounter(periodOrSentinel, bCounter);
  optionally this->nPeriodMs = realPulseMs;     // +0x08
  optionally this->nTypeTag = kClass;           // +0x1C
  AttachOwnerObject(owner);                     // +0x18
  // Start() later clears fDormant + vtbl OnStart (base: StampLastFireTime)
```

Port notes:
- **Do not** assume full `memset(this,0,0x28)` — debounce/skill extension bytes may be garbage until subclass.
- **Do not** merge +0x08 with +0x0C.
- Pair with `SetPeriodAndCounter` / `AttachOwnerObject` / `Start` before list tick expects work.

---

## 5. Open questions

1. Full product enum for `nTypeTag` beyond {0,1,4,8}.
2. `nRefOrFlags` readers (if any) outside this residual.
3. Allocator pre-zero policy for +0x22..+0x27 (out of scope for this unit).

**Verdict:** **accept** (residual dual sealed)
