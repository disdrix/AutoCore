# Review A (reconstruction fidelity): `aa_005081a0` CVOGHBBase_SetPeriodAndCounter

| Field | Value |
|---|---|
| **Stable ID** | `aa_005081a0` |
| **VA** | `0x005081a0` |
| **Canonical name** | `CVOGHBBase_SetPeriodAndCounter` |
| **Review date** | `2026-07-29` (residual seal; prior accept 2026-07-23) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005081a0_CVOGHBBase_SetPeriodAndCounter.md` |
| **System** | `heartbeat` / timed-actions |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + callers/xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept** (sealed High) |

---

## 1. Purpose

Seed HB schedule fields used by TryFire / Reschedule: write **period/sentinel at `this+0x0C`**, and optionally mirror the same int to **counter at `this+0x10`** when `bAlsoSetCounter != 0`.

Does **not** write pulse period at **`+0x08`**. Combat-pool / regeneration patterns pass `(-1000, true)` here, then set real pulse ms at `+0x08` separately (e.g. Regeneration_ctor 3000/5000).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005081a0_CVOGHBBase_SetPeriodAndCounter.md` |
| Annotated | `docs/reconstruction/raw/aa_005081a0_CVOGHBBase_SetPeriodAndCounter.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBBase_SetPeriodAndCounter.cpp` |
| Function record | `docs/reconstruction/functions/aa_005081a0_CVOGHBBase_SetPeriodAndCounter.md` |

---

## 3. Seal: body bytes (High)

`read_memory` @ `0x005081a0` (body `005081a0`–`005081b3`):

```
005081a0  80 7C 24 08 00    cmp  byte ptr [esp+0x8], 0   ; bAlsoSetCounter
005081a5  8B 44 24 04       mov  eax, [esp+0x4]          ; nPeriodSentinel
005081a9  89 41 0C          mov  [ecx+0x0C], eax         ; always write +0x0C
005081ac  74 03             jz   skip_counter
005081ae  89 41 10          mov  [ecx+0x10], eax         ; optional +0x10
005081b1  C2 08 00          ret  8                       ; pop 2 stack args
; 005081b4..  CC padding
```

Hex: `80 7c 24 08 00 8b 44 24 04 89 41 0c 74 03 89 41 10 c2 08 00`

| Claim | Evidence | Conf |
|---|---|---|
| Body size **19 bytes**; one cond store | `read_memory` + range `005081a0`–`005081b3` | **High** |
| `__thiscall`: **ECX = this**; stack formals period + bool; **void**; `ret 8` | `[esp+4]`/`[esp+8]` + `C2 08 00` | **High** |
| Bool is **byte** test (`cmp byte [esp+8],0`) | opcode `80 7C 24 08 00` | **High** |
| Always store arg → **`this+0x0C`** | `89 41 0C` | **High** |
| If bool ≠ 0, store same → **`this+0x10`** | `74 03` + `89 41 10` | **High** |
| **No** write to `+0x08` / `+0x14` / owner | only two store ops | **High** |
| **No callees** | no CALL | **High** |
| Decompiler ≡ machine | clean/raw match | **High** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Store arg1 → this+0x0C` | **High** | Body sealed |
| `If bAlsoSetCounter: store same → this+0x10` | **High** | Branch sealed |
| `No other side effects` | **High** | Void short |
| `Does not write +0x08` | **High** | Offsets explicit; Regeneration writes `+0x08` after call |
| Combat pool `(-1000, true)` pattern | **High** | Regeneration_ctor, WeaponTrack, several FUN ctors |
| Real pulse ms often set at `+0x08` outside this helper | **High** | Regeneration_ctor after call |
| Field name `nPeriodMs` vs `nPeriodSentinel` at `+0x0C` | **Probable** | TryFire plate uses both; GetRemaining machine uses `+0x08` as period for UI math |

---

## 5. Control flow: clean ≡ raw ≡ machine

| Stage | Match |
|---|---|
| Always +0x0C | **Yes** |
| Cond +0x10 | **Yes** |
| `ret 8` / two stack args | **Yes** |
| No invented clamps | **Yes** |

---

## 6. Callers (Ghidra 2026-07-29)

24 UNCONDITIONAL_CALL sites (function callers list). Named high-signal:

| Caller | Typical args |
|---|---|
| `CVOGHBRegeneration_ctor` `0x005fbdb0` | `(-1000, true)` then sets `+0x08` |
| `CVOGHBOKToCastAgain_ctor` `0x0051e240` | `(1, 1)` |
| `CVOGHBSkillBase_ctor` `0x005788d0` | `(period, true)` |
| `Vehicle_CreateWeaponTrackAction` `0x005a4f60` | `(-1000, true)` |
| `TimedAction_CreateTokenFlagAction` `0x005ffbd0` | `(1, true)` |
| + 19 FUN_* HB ctors / spawn helpers | mostly `(1,true)` or `(-1000,true)` or variable period |

Almost all observed call sites pass **true** for the counter flag (mirror to `+0x10`). Sites with **false** not enumerated as a dedicated xref class — gap if any exist via indirect calls.

---

## 7. Gaps / open

1. Unify authoritative field name at `+0x0C` across TryFire / Reschedule / this plate (`nPeriodMs` vs `nPeriodSentinel`).
2. Confirm whether any live path calls with `bAlsoSetCounter == false` (body supports it; call inventory looks mostly true).
3. GetRemainingSeconds uses **`+0x08`** as period for remaining math — dual layout residual vs TryFire gate on `+0x0C`/`-1000`.
4. Runtime / bit-exact / differential still deferred.

**Verdict:** **accept** (sealed High)
