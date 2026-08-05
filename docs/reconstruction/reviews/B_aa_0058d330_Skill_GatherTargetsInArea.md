# Review B (skeptical / adversarial): `aa_0058d330` Skill_GatherTargetsInArea

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058d330` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (mode-table CF strengthen; prior residual same day; base 2026-07-23) |
| **Counterpart** | `reviews/A_aa_0058d330_Skill_GatherTargetsInArea.md` |
| **Verdict** | **accept-with-gaps**; mode table **CF sealed** |

---

## 1. Claims under attack

| # | Claim | Attack / outcome |
|---|---|---|
| 1 | Single-target only | **Falsified** — area/chain multi TFID |
| 2 | Writes damage / casts | **Falsified** — list only |
| 3 | Mode enum finished with retail names | **Overstated** if claimed — **English names still INFERRED** |
| 4 | Mode table unknowable without PDB | **Falsified for CF** — body + `FUN_0058a810` + literal callers seal **behavior** |
| 5 | Mode 10 is “alive only” | **Falsified** — only mode that **allows** `vtbl+0x198 != 0` (dead-like); attack AI requires `+0x198==0` |
| 6 | Mode 3 is arbitrary | **Falsified** — hard filter to clonebase types Vehicle/Creature/Character (`0xe`/`0x12`/`0x14`) |
| 7 | Mode 2 == mode 1 | **Falsified** — opposite `+0x298` polarity |
| 8 | Mode 7 + filterA=0x14 ⇒ Character-only | **Overstated** — helper **bypasses** filterA exactness for Veh/Cre/Char; 0x14 only rejects non-living mismatched types. Prefer-pass-1 `+0x1dc` + query flags `10` are the real mode-7 CF. Intent may still be Character pick (**INFERRED**). |
| 9 | Pass-1 mode 7/10 “keep when vtbl returns 0” | **Falsified** (annotated bug) — when result **nonzero**, take entity **immediately**; when **0**, fall into `+0xd4`/`+0xdc` link path |
| 10 | Helper “already in outList” is full-list scan | **Overstated** — `TFID_EqualsObjectId(entity+0x58, outListBase)` is **first-slot / primary** dedupe only |
| 11 | allowSelfMode1 applies to all modes | **Falsified** — gather self-allow is only modes **0**, **0xb**, or (**1** && flag) |
| 12 | Missing modes 5/12 crash or reject-all | **Falsified** — unlisted modes use default query `1`, default pass-1, helper **`return 1`** after commons |
| 13 | Only ResolveTargetList feeds skill mode | **Incomplete** — also `NPC_TryCastSkillFromSet` `0x005d1280` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stride 0x10 TFID entries | **High** | Corrupt target list |
| maxTargets + cap 99 | **High** | Too many/few hits |
| Mode **branch CF** (query/pass-1/accept/self) | **High** | Wrong AoE / pick class |
| Mode **English names** | **INFERRED** | Doc mislabel only; CF still holds |
| skill `+0x60c` is mode | **High** | Wrong skill data field |
| filterA living-type bypass | **High** | Wrong type-filter assumptions in AutoCore port |
| Literal caller mode set {1,2,3,7,8} | **High** | Missing UI pick class |

---

## 3. Cross-check against raw

```
gatherMode → query flags → pass-1 keep → FUN_0058a810(mode) → TFID stride 0x10
  until max/99; optional sort; invalid terminator.
Clean ≡ raw CF; mode residual sealed on behavior (not PDB names).
Pass-1 7/10: prefer-nonzero primary, not keep-on-zero.
```

Re-decompile 2026-07-29 strengthen: matches frozen raw (no CF drift). Caller asm (`ADD ESP,0x3c`; literal PUSH modes) revalidated.

---

## 4. Surviving contract for AutoCore

```
GatherTargetsInArea(outList, start, queryCtx, source, origin, range,
                    maxTargets, gatherMode, typeFilter, chain, allowSelf1,
                    filterB, filterC, sortDist, scoreArg):
  multi-target / interact pick fill
  pair ResolveTargetList (skill+0x60c mode, +0x610 type) + CastSkillOnTarget
  NPC_TryCastSkillFromSet also gathers with skill fields
  AutoCore multi-target skills depend on mode CF, not English labels
  Do not assume filterA alone restricts Veh/Cre/Char special paths
```

---

## 5. Open questions (post-residual)

1. Retail / PDB names for mode integers (behavior sealed in `reviews/a_0058d330.md`).
2. Name spatial helpers (`FUN_004ea350`, `FUN_004e9aa0`, `FUN_0058a810`) — **out of this unit’s ownership**.
3. Confirm gather never implies ValidateTarget (still **no** direct call — legality separate).
4. Mode-7 + filterA=0x14 product intent vs CF (Character-only claim remains INFERRED).

**Tighten note (2026-07-29 strengthen):** Adversarial re-check — name “GatherTargetsInArea” remains **INFERRED**; mode **table CF sealed High** from body+helper+literal callers+Resolve ABI; pass-1 polarity and filterA living bypass corrected; do **not** claim PDB-bit-exact enum names or runtime proof.

**Verdict:** **accept-with-gaps**; mode table residual **sealed** (CF); runtime/diff/names open
