# Review B (skeptical / adversarial): `aa_005e07d0` LootCatalog_FillCandidateIds_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e07d0` |
| **VA** | `0x005e07d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005e07d0_LootCatalog_FillCandidateIds_Inferred.md` |
| **Evidence** | Live decompile + constants + `005e0480` + sole caller `005e1030` dual |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This function randomly picks the loot ID | Only fills vector; pick is `005e1030` + `007a41f0` | **Falsified** |
| 2 | Same as filtered fill `005e0cd0` | Different tables/offsets (`0x65408` path vs `0x10e00c`); different callers | **Falsified** |
| 3 | Type index is raw def type | `005e0480` remaps sparse codes → compact row; default −1 | **Falsified raw** |
| 4 | Affinity always runs | Only if `param_9 != 0` | **Falsified** |
| 5 | Keep probability ignores floor | Floor at ~0.2 sealed | **Falsified** |
| 6 | Secondary merge always on | Gated by `param_7 == 0` | **Falsified always** |
| 7 | Empty vector always fails immediately | Outer rank descent continues; early success only when non-empty **and** rank&lt;0 | **Survives nuanced** |
| 8 | Product name string on VA | None | **Not sealed** |
| 9 | Clean rewrote loops | Scaffold ≡ live | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Fill-not-pick role | **Confirmed** | Double-roll bugs |
| Type remap via `005e0480` | **Confirmed** | Wrong table row |
| Affinity optional + 2↔3 bridge | **High** | Faction loot leaks |
| Keep-prob formula | **Confirmed** | Level bias wrong |
| Table stride English | **Low–Med** | Port layout |
| Runtime | **Open** | — |

---

## 3. Surviving contract for AutoCore

```
// catalog this; out = vector of candidate dword IDs
map quality → band0..3
typeRow = TypeCodeToRow(type)   // 005e0480; -1 = all 12 subtypes
optional: roll keep flag by level keepProb
clamp levelLo/Hi; convert to 0-based
for rank = startRank .. 0:
  if out non-empty && rank < 0: return success
  for level in [lo, hi]:
    copy matching table cells → out (grow push)
    if !skipSecondary: merge secondary cells
  if keepFlag: compact out by affinity match
return fail/0
// NOT the final random pick
```

Port rule: never call this alone as “roll loot” — pair with pick path like retail `005e1030`.

---

## 4. Cross-check vs siblings

| VA | Role |
|---|---|
| `005e0580` | Global catalog pointer |
| `005e07d0` | **This** — unfiltered band fill |
| `005e0cd0` | Filtered/quality-type band fill (other tables) |
| `005e1030` | Fill via **this** + pick |
| `005e1150` | Fill via `005e0cd0` + exclude/invalid strip + pick |

---

## 5. Open questions

1. Stride/geometry product documentation.
2. Whether early-return 1 vs final 0 is observed by `005e1030` (caller mainly checks vector emptiness).
3. Runtime.

**Verdict:** **accept-with-gaps** — adversarial pass keeps fill CF; geometry residual.
