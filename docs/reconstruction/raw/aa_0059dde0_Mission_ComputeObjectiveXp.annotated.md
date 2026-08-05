# Annotated low-level: Mission_ComputeObjectiveXp (`aa_0059dde0`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059dde0` |
| **VA** | `0x0059dde0` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | missions-progression |
| **Source raw** | `aa_0059dde0_Mission_ComputeObjectiveXp.md` (capture 2026-07-23) |
| **Last annotated** | 2026-07-29 dual residual strengthen |
| **Callers** | Grant: `CVOGReaction_CompleteObjective` final; Presentation: toast×2 + `FUN_0051f510` |
| **Dual residual** | **accept-with-gaps** |

This file is the **annotated** layer: widths, signedness, branch order, side effects, and decompiler corrections. It does not replace the immutable raw capture.

---

## 1. Corrected signature

```c
// __fastcall: pObjective in ECX
int __fastcall Mission_ComputeObjectiveXp(void* pObjective /* CVOGObjective* */);
```

| Name | Width | Signedness | Origin | Role |
|---|---|---|---|---|
| `pObjective` | 32-bit pointer | unsigned | ECX | Objective def / runtime with mission link |
| return | 32-bit int | signed | EAX | XP amount; 0 on fail |

**Does not** apply `g_flMissionXpRoundBias` — that is caller-side in CompleteObjective (`0x00aaa6d0` = **0.5001f**).

Grant-side bias contract:

```
n = Mission_ComputeObjectiveXp(obj)
f = (float)n
f = (f >= 0) ? f + 0.5001f : f - 0.5001f
AddExperience(char, (int)f, PacketOrNonKill)
```

---

## 2. Decompiler corrections

| Decompiler artifact | Correction | Confidence |
|---|---|---|
| `extraout_EAX` / `_00` / `_01` | After map call, EAX holds **out-iterator address** (the `node**` arg); `*EAX` → **node*** | **High** (body `8B 38` + map `ret 8`) |
| `unaff_EDI` / 4th map arg | Pure noise — callees are `__thiscall(this, out, key)` only | **High** |
| `Map_LowerBoundFindByIntKey` param rename swap | Decompiler sometimes labels out/key swapped; image writes `*out = node`, reads `*key` | **High** |
| Quest vs level helper | Two layouts: nil **+0x15** (quest) vs **+0x1d** (level); same exact-match policy | **High** |
| L-1 path single deref | Correct — same node* as L path; payload `+0x10` | **High** |
| `obj+0x13c` short as int key | `wXPIndex` → tQuestXPLookup | **High** |
| `obj+0x140` / `+0x144` floats | `fXPScaler` / `fXPBalanceScaler` | **High** |
| `missionDef+0x11c` short | `wTargetLevel` | **High** |
| `node+0x10` float on quest map | `rlLevelXP` fraction | **High** |
| `node+0x10` int on level map | `intExperience` cumulative | **High** |
| Final `(int)((float)nLevelSpan * flSpanMult)` | Trunc toward zero | **High** |
| Miss / end | Exact key required; miss → 0 (unlike GetCumulativeThreshold miss → `0x7FFFFFFF`) | **High** |

---

## 3. Control flow

```text
if obj.missionDef == null: return 0

key = obj.wXPIndex
ensure tQuestXPLookup
row = exact_find(tQuestXPLookup, key)   // lower_bound + equality gate
if row == end: return 0

spanMult = obj.XPBalanceScaler * row.frac * obj.XPScaler
key = mission.TargetLevel
ensure tExperienceLevel
rowL = exact_find(tExperienceLevel, key)
if rowL == end: return 0

levelSpan = rowL.intExperience
if TargetLevel > 1:
  rowPrev = exact_find(tExperienceLevel, TargetLevel-1)
  if rowPrev != end:
    levelSpan -= rowPrev.intExperience

return (int)(levelSpan * spanMult)   // via float multiply; trunc
```

| Branch | Effect |
|---|---|
| Null mission def | 0 |
| Quest XP map miss / end | 0 |
| Experience level map miss / end | 0 |
| TargetLevel ≤ 1 | use cumulative as span (no subtract) |
| Success | truncated product |

---

## 4. Side-effect order

1. Lazy-load checks (quest XP table, then experience level table) — may mutate global ready flags via ensure-load.
2. **No character mutation** — pure calculator (plus possible table load).
3. Return integer XP.

---

## 5. Map node layout (sealed)

| Offset | Role |
|---|---|
| `+0x00` | left child* |
| `+0x04` | parent* (MSVC tree) |
| `+0x08` | right child* |
| `+0x0c` | int key |
| `+0x10` | mapped value (float or int) |
| `+0x15` | nil/color (quest map helper) |
| `+0x1d` | nil/color (level map helper; larger value type) |

End sentinel = `*(map+4)`.

### Global VAs

| Label | VA |
|---|---|
| level map / end / ready | `0x00b04240` / `44` / `48` |
| quest map / end / ready | `0x00b0424c` / `50` / `54` |
| round bias (caller) | `0x00aaa6d0` |

---

## 6. Open questions

- WAD field names / row payloads for `rlLevelXP` and level thresholds (semantic + economy).
- Negative/zero scaler edges.
- Runtime complete XP vs calculator + bias.
