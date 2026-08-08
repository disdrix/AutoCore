# Review B (skeptical / adversarial): `aa_0052b080` CVOGCharacter_ComputeObjectDifficultyScore_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052b080` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R13-035 OWN-ONLY dual B; dual start 2686) |
| **Counterpart** | `reviews/A_aa_0052b080_CVOGCharacter_ComputeObjectDifficultyScore_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Identity is long `Named_CalleeOf_Client_RefreshOpen_*` scaffold | Prior alias | **Falsified as product name** — sole real caller is difficulty UI tier formatter; scaffold retired |
| 2 | Is `CVOGCharacter_GetResourceBalanceByType` | Same map/find | **Falsified** — that returns **int** balance (`RET 4`, no float math); this returns **float score** from gap formula |
| 3 | Is `UI_FormatObjectDifficultyTier` / labels colors | Consumer confusion | **Falsified** — this leaf has no strings, no palette, no sprintf; only score |
| 4 | Is DisciplineDef map try-copy (`0x0052b040`) | Partition parent adjacency | **Falsified** — different body; global map `0x00b045b0` vs per-char `+0x584`; bool copy vs float score |
| 5 | `__cdecl` / bare RET / two equal stack args | Decompiler `float param_2` noise | **Falsified** — `MOV EDI,ECX`; all exits `RET 4`; call site loads ECX from `DAT_00d1b6d8` then one `PUSH` |
| 6 | Stack arg is IEEE float scalar | Decompiler type | **Falsified** — loaded as pointer (`[EAX+0xa8]`); null test is pointer TEST |
| 7 | Higher player always harder (score rises with overlevel) | Naïve difficulty intuition | **Falsified** — overlevel **decreases** score by 6 per step (easier tier); equal → 100 (hardest non-Impossible) |
| 8 | Under-level returns negative / Impossible code | UI coupling guess | **Falsified** — under-level returns **0.0f** same as gap>15; Impossible is **caller** balance compare |
| 9 | Mutates character map / object | “compute” overclaim | **Falsified** — read-only find + arithmetic; no stores to map/object |
| 10 | Multiple independent callers | Importance inflation | **Falsified for direct xrefs** — exactly **1** UNCONDITIONAL_CALL (`0x008e4484`); mission UI chain calls the tier formatter, not this leaf |
| 11 | Runtime Confirmed | Wave seal claim | **Fails (open)** — no Launcher; dual CF seal only |
| 12 | Base/step/gap are ints 100/6/15 without float loads | Mental model | **Falsified form** — `MOVSS`/`MULSS`/`COMISS` from float immediates; values are 100.0/6.0/15.0 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + RET 4 + ST0 float | **High** | Wrong cleanup / wrong return channel in ports |
| Score formula + constants | **High** | Wrong tier thresholds upstream |
| Map `+0x584` / fields `+0x4ac`/`+0x4b0` | **High** | Lookup wrong resource / wrong required |
| Domain = difficulty score (not balance, not UI pack) | **High** | Merge with sibling helpers incorrectly |
| Product English name | **Low–Med** | Doc only (`_Inferred`) |
| Runtime | **Open** | Not claimed |

---

## 3. Cross-check against raw ≡ live

```text
// sealed CF (authority = disassemble_function + read_memory constants)
if (!target || !*(target+0xa8)) return 0.0f;          // FLD g_flZero
clone = *(*(target+0xa8)+0x3c)
required = *(clone+0x4b0)
typeId   = *(clone+0x4ac)
FUN_00418b80(character+0x584, &node, &typeId)
player = (node == *(character+0x588)) ? -1 : *(node+0x10)
if (player < required) return 0.0f
score = 100.0f
if (player == required) return score
gap = player - required
if (gap > 15.0f) return 0.0f
return score - gap * 6.0f
// __thiscall; RET 4; float ST0
```

Sibling contrast (evidence only; not OWN dual):

* `CVOGCharacter_GetResourceBalanceByType` (`0x0052ada0`): same map/find; returns int/`-1`; no score.
* `UI_FormatObjectDifficultyTier_Inferred` (`0x008e4430`): sole caller; Impossible via balance; tiers via this score.
* `DisciplineDefMap_TryCopyPayloadById_Inferred` (`0x0052b040`): partition parent VA only; global DisciplineDef POD copy.

Bytes / constant seal (`read_memory`):

```text
DAT_00aaa7ac → 0x42C80000 = 100.0f
DAT_00aaa8dc → 0x40C00000 =   6.0f
DAT_00aaa7a4 → 0x41700000 =  15.0f
g_flZero     → 0x00000000 =   0.0f
RET form     → C2 04 00 at each exit
```

---

## 4. Surviving contract for AutoCore

```
CVOGCharacter_ComputeObjectDifficultyScore_Inferred(character, target):
  if !target or !target.holder(+0xa8): return 0.0
  clone = target.holder.clone(+0x3c)
  player = CharacterResourceMap_FindValue(character+0x584, clone.typeId@+0x4ac)  // -1 miss
  required = clone.required@+0x4b0
  if player < required: return 0.0
  if player == required: return 100.0
  gap = player - required
  if gap > 15: return 0.0
  return 100.0 - gap * 6.0
```

**Port tests:**

* null target → 0.0  
* missing type on character map → 0.0 (player −1)  
* player == required → 100.0  
* player = required+1 → 94.0; +5 → 70.0; +10 → 40.0; +15 → 10.0; +16 → 0.0  
* player = required−1 → 0.0 (UI may still paint Impossible via separate balance API)  
* Do **not** implement tier strings here  
* Do **not** use cdecl / bare RET / float stack typing from Ghidra  
* Share map access with `GetResourceBalanceByType` (same offsets)

**Verdict:** **accept-with-gaps** — adversarial balance-merge / UI-merge / cdecl / float-arg / rising-with-overlevel / Runtime Confirmed claims **falsified**. Product English + runtime remain open (terminal **false**).
