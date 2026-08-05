# Review B (skeptical / adversarial): `aa_00519150` Skill_GetCategoryCooldownRemaining

| Field | Value |
|---|---|
| **Stable ID** | `aa_00519150` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual A/B strengthen; prior scaffold `2026-07-23`) |
| **Counterpart** | `reviews/A_aa_00519150_Skill_GetCategoryCooldownRemaining.md` |
| **Verdict** | **accept** (prior accept-with-gaps closed on clock + scale + return mode) |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Always returns 0 / no remaining math | **Falsified** — `deadline - now` on active path |
| 2 | Mutates skill cast flag / skill+0x628 | **Falsified** — only map find + optional **erase** |
| 3 | Seconds-only API | **Falsified** — dual mode on `bAsSeconds` |
| 4 | False branch returns remaining **milliseconds** | **Falsified (strengthen)** — `fidiv duration` → **fraction** |
| 5 | Clock identity open / non-`g_dwClientTickMs` | **Falsified** — direct load `[0x00b041cc]` |
| 6 | Float scale open / not 0.001 | **Falsified** — `fmul [0x00a0f72c]`; bytes `6f12833a` = 0.001f |
| 7 | ECX is skill runtime | **Falsified** — GetMap owner+0x6c; callers pass caster/char this-adjust |
| 8 | Decompiler signature (`float10*`, 3 stack slots) is ABI | **Falsified** — `RET 8`, two args, ST0 float |
| 9 | Query is pure (no side effects) | **Falsified** — expired hit **erases** node (`FUN_004188e0`) |
| 10 | Insert path refreshes start on re-arm without erase | Out of unit; Insert dual: equal key **does not** rewrite — erase-here enables re-insert |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x10 start / +0x14 duration | **Confirmed** | Wrong CD gauge / gate |
| Expired erase | **Confirmed** | Stuck deny forever **or** ghost CD if erase missed |
| Clock `g_dwClientTickMs` | **Confirmed** | Early/late ready |
| Seconds = ms × 0.001 | **Confirmed** | UI time scale wrong |
| Fraction = rem/duration when flag 0 | **Confirmed** | QB probe threshold misread |
| Map find/erase helper **product** names | Tentative | Naming only |
| duration==0 fraction | Residual | Rare div0 |
| Server owns true CD | Out of scope | Desync if client-only trust |

---

## 3. Cross-check against machine (not scaffold raw)

```
map = GetCategoryCooldownMap(owner)          // +0x6c lazy
it  = map_find(map, categoryId)           // FUN_00418b80; key @ node+0x0C
if it == end: return 0.f
deadline = start(+0x10) + duration(+0x14)
if now >= deadline: erase(it); return 0.f
rem = deadline - now
if bAsSeconds: return rem * 0.001f
else:          return rem / duration      // NOT raw ms
```

Scaffold clean/raw decompile shows **identical** dual returns and pointer fallthrough — **do not trust** for AutoCore; A sealed from `read_memory` + caller `push 0`/`push 1` pairs.

### Caller dual-call pattern (QB)

1. `GetRemaining(cat, 0)` → fraction; compare to `DAT_00aaa664` ≈ **1e-4**.
2. If above threshold: `GetRemaining(cat, 1)` → seconds for overlay/gauge.

LocalCast: single call `(cat, 1)` vs `g_flZero` → **eSkillResponses = 7** (recharge).

---

## 4. Surviving contract for AutoCore

```
// Client-side category CD query (owner entity holds map @ +0x6c)
float Skill_GetCategoryCooldownRemaining(owner, categoryId, asSecondsMode);
// asSecondsMode:
//   0 → remaining fraction of armed duration (UI progress)
//   1 → remaining seconds (gate / text)
// Side effect: drops expired entries (enables Insert to re-arm)

// AutoCore:
//  - LocalCastValidate-style deny when seconds remaining != 0 (code 7)
//  - QuickBar gauge: fraction probe + seconds fill
//  - Optional server mirror: own authoritative timers; do not trust client erase alone
```

Pair with:

- `Skill_GetCategoryCooldownMap` / `Skill_InsertCategoryCooldown` / `Skill_CategoryCooldownMap_Insert`
- `CVOGHBOKToCastAgain_ctor` (arms category unless category == -1)
- `skill+0x5e8` category key; casting UI path uses skill+0x628 / +0x178 **instead** of this map

---

## 5. Open questions (residual only)

1. Promote Ghidra names for `FUN_00418b80` / `FUN_004188e0` (map find / erase).
2. `duration == 0` fraction path — confirm no production arm writes 0 duration.
3. Server-authoritative CD packet vs client map (policy).
4. Rewrite scaffold clean/raw to match sealed CF (doc hygiene).

**Verdict:** **accept**. Prior gaps (clock, ms→sec constant, return-mode wording) **closed** by this strengthen. Remaining items are naming / edge / server policy — not CF blockers.
