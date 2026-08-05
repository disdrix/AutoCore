# Review B (skeptical / adversarial): `aa_005081a0` CVOGHBBase_SetPeriodAndCounter

| Field | Value |
|---|---|
| **Stable ID** | `aa_005081a0` |
| **VA** | `0x005081a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (residual seal; prior accept 2026-07-23) |
| **Counterpart** | `reviews/A_aa_005081a0_CVOGHBBase_SetPeriodAndCounter.md` |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + callers (no `disassemble_bytes`) |
| **Verdict** | **accept** (trivial CF; layout naming residual; sealed High) |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Also writes `+0x08` pulse period | **Falsified** — stores only `+0x0C` / optional `+0x10` |
| 2 | Always sets counter | **Falsified** — gated on `cmp byte [esp+8],0` |
| 3 | No combat `-1000` use | **Falsified** — Regeneration_ctor, WeaponTrack, several FUN_* |
| 4 | `__cdecl` / caller stack cleanup | **Falsified** — `ret 8` (thiscall stack args) |
| 5 | Bool is 32-bit stack dword test | **Falsified** — **byte** cmp at `[esp+8]` |
| 6 | Touches last-fire `+0x14` | **Falsified** — StampLastFireTime / TryFire own that |
| 7 | Body has callees | **Falsified** — pure stores + ret |
| 8 | GetRemaining period field is this write target | **Falsified as identity** — GetRemaining machine reads **`+0x08`** for period; this helper seeds **`+0x0C`** (and maybe `+0x10`) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `+0x0C` write | **High** | Wrong TryFire/Reschedule gate / sentinel |
| Optional `+0x10` | **High** | Counter multi-fire / remaining inflate wrong |
| No `+0x08` write here | **High** | Port would clobber pulse period path |
| `-1000` combat-pool contract | **High** | Pool never arms / always remove |
| Call inventory (24 CALLs) | **High** | Missed ctor arm path |
| Field names across family | **Probable** | Port confusion TryFire vs GetRemaining |
| Existence of `bAlsoSetCounter=false` callers | **Open** | Dead branch vs rare path |

---

## 3. Cross-check against raw / machine

```
cmp  byte [esp+8], 0      ; 80 7C 24 08 00
mov  eax, [esp+4]         ; 8B 44 24 04
mov  [ecx+0x0C], eax      ; 89 41 0C
jz   +3
mov  [ecx+0x10], eax      ; 89 41 10
ret  8                    ; C2 08 00
```

Clean ≡ raw ≡ decompile ≡ 19-byte body. No invented clamps, loops, or globals.

Sibling evidence (not re-owned):

- **Regeneration_ctor** (`0x005fbdb0`): `SetPeriodAndCounter(this,-1000,true)` then `*(this+8)=nPeriodOverrideMs` / race 3000|5000.
- **GetRemainingSeconds** (`0x00508280`): remaining math uses `[ecx+0x08]` period + `[ecx+0x10]` counter + `[ecx+0x14]` last fire — confirms dual layout.
- **StampLastFireTime** (`0x00508270`): only `+0x14` — orthogonal helper.

---

## 4. Surviving contract for AutoCore

```
CVOGHBBase_SetPeriodAndCounter(HB* this /* ECX */,
                               int nPeriodSentinel /* [esp+4] */,
                               bool bAlsoSetCounter /* byte [esp+8] */):
  this[+0x0C] = nPeriodSentinel
  if (bAlsoSetCounter) this[+0x10] = nPeriodSentinel
  // void; ret 8; no +0x08 / +0x14 / owner / dormant

Use:
  - Combat pool / weapon track / many mission HB: (-1000, true) always-ready gate seed
  - Cast-again / token / short HB: (1, true)
  - Skill / variable-period ctors: (periodMsOrComputed, true)
  - Regeneration: (-1000, true) THEN write real pulse ms at +0x08 outside this helper

Pair with:
  StampLastFireTime / Start / Enqueue for schedule
  TryFire for -1000 vs elapsed gate on +0x0C family fields
  GetRemainingSeconds for UI (reads +0x08 period, not this write alone)
```

Do **not** treat status code **16** (Remove) as period ms.

---

## 5. Open questions

1. Unify `+0x08` pulse vs `+0x0C` sentinel names across TryFire / Reschedule / GetRemaining / Regeneration plates.
2. Prove or disprove any `bAlsoSetCounter == false` live callers (body path exists).
3. Map each FUN_* caller to product HB type name where still unnamed.
4. Runtime / bit-exact still deferred.

**Verdict:** **accept** (trivial CF; layout naming residual; sealed High)
