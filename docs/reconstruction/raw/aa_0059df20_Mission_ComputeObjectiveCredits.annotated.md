# Annotated low-level: Mission_ComputeObjectiveCredits (`aa_0059df20`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059df20` |
| **VA** | `0x0059df20` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | missions-progression |
| **Source raw** | `aa_0059df20_Mission_ComputeObjectiveCredits.md` (capture 2026-07-23) |
| **Caller** | `CVOGReaction_CompleteObjective` final path only |

This file is the **annotated** layer: widths, signedness, branch order, side effects, and decompiler corrections. It does not replace the immutable raw capture.

---

## 1. Corrected signature

```c
// __fastcall: pObjective in ECX
int __fastcall Mission_ComputeObjectiveCredits(void* pObjective /* CVOGObjective* */);
```

| Name | Width | Signedness | Origin | Role |
|---|---|---|---|---|
| `pObjective` | 32-bit pointer | unsigned | ECX | Objective with mission link |
| return | 32-bit int | signed | EAX | Credit **delta** to ADD at char+0x720 |

---

## 2. Decompiler corrections

| Decompiler artifact | Correction | Confidence |
|---|---|---|
| `extraout_EAX` | Iterator* from lower_bound; `*EAX` → node* | **High** |
| `unaff_EDI` | Residual; not a real input | **Probable** |
| No null check on `obj+0x14c` | **Intentional vs XP** — XP checks null, credits does not | **High** (raw) |
| `missionDef+0x11c` short | TargetLevel → tQuestBaseCredits key | **High** |
| `obj+0x13e` short | CreditsIndex → tQuestCreditsLookup key | **High** |
| `obj+0x148` float | CreditScaler | **High** |
| Base row `+0x10` as `(float)*(int*)` | Integer base credits cast to float | **High** |
| Frac row `+0x10` as float | Level credits fraction | **High** |
| `ceil` then `ROUND` | Image: FISTP with RC=chop (`OR AH,0x0C`) after ceil; positive ≈ ceil | **High** |
| Ensure-load names | `EnsureQuestBaseCreditsLoaded` `0x00512870` / `EnsureQuestCreditsLookupLoaded` `0x00512830` | **High** (2026-07-29 residual) |
| Map node key/value | key `@+0x0C`, payload `@+0x10`, flag `@+0x15` (`Map_LowerBoundFindByIntKey`) | **High** |

---

## 3. Control flow

```text
key = mission.TargetLevel          // no null-check on missionDef
ensure tQuestBaseCredits
baseRow = lower_bound(tQuestBaseCredits, key)
if baseRow == end: return 0

base = (float)baseRow.nBaseCredits
key = obj.CreditsIndex
ensure tQuestCreditsLookup
fracRow = lower_bound(tQuestCreditsLookup, key)
if fracRow == end: return 0

return ROUND(ceil(obj.CreditScaler * fracRow.frac * base))
```

| Branch | Effect |
|---|---|
| Base map end | 0 |
| Credits lookup end | 0 |
| Success | ceiled product as int |

---

## 4. Side-effect order

1. Lazy-load base credits / credits lookup tables.
2. **No character mutation** — pure calculator.
3. Caller CompleteObjective performs 64-bit ADD into `this[0x1c8]` / `+0x720`.

---

## 5. Open questions / residual disposition (2026-07-29)

| Item | Disposition |
|------|-------------|
| Null mission def | Body unchecked; CompleteObjective early-outs on null; toast can call with null → theoretical fault. Sealed. |
| ROUND | FISTP RC=chop after ceil (not FRNDINT / nearest library). Sealed via image at `0x0059dfca`. |
| Negative scaler | Client can return negative int; AutoCore clamps 0. Documented. |
| Full WAD bit-exact rows | Schema sealed; exhaustive dump open. |

See `reviews/a_0059df20.md`.
