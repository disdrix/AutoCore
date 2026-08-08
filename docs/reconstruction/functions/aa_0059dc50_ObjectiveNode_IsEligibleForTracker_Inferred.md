# Function record: ObjectiveNode_IsEligibleForTracker_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059dc50` |
| **Canonical name** | `ObjectiveNode_IsEligibleForTracker_Inferred` |
| **Ghidra name** | `FUN_0059dc50` |
| **Address** | `0x0059dc50`–`0x0059dcb9` inclusive (**106 B** / `0x6A`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` |
| **Parent dual / context** | `Client_TryBindActiveMissionTracker` `0x0092fd00`; tracker set `0x0092a590` |
| **Partition** | MEGA-025 (P93) — Objective-node eligibility gate for tracker |
| **Completion status** | **Dual sealed** (2026-08-05 MEGA-025) — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (terminal **false**) |

## Alias

| Name | Status |
|---|---|
| `ObjectiveNode_IsEligibleForTracker_Inferred` | **Canonical** |
| `FUN_0059dc50` | Ghidra twin |
| `Named_CalleeOf_Named_VOG_DEBUG_STOP_0059dc50` | **Retired** (parent-seed only) |

## Purpose

Gate whether an **objective node** may be selected or bound by the mission **tracker**:

1. Null character → false.
2. Template gate short@`+0xf8` non-zero requires node flag byte@`+0x14` non-zero.
3. Sibling `FUN_0059db80(character)` must not return `-1`.
4. Template id in inclusive band `[0xdfd, 0xe02]` (3581–3586) requires character virtual `+0x27c` ≥ 5.
5. Else true.

## Signature (image-sealed)

```c
// thiscall RET 4
uint8_t /*AL*/ __thiscall ObjectiveNode_IsEligibleForTracker_Inferred(
    ObjectiveNode* self,     // ECX
    Character* character);   // stack
```

## Layout notes (observed)

| Offset | Object | Use |
|---|---|---|
| `+0x14c` | node → template* | template base |
| `+0xf8` | template short | optional gate enable |
| `+0x14` | node byte | required when gate short ≠ 0 |
| `[0]` | template u32 | id; band-checked |
| `+4` chain | character | MSVC this-adjust before `vtbl+0x27c` |

## Artifacts

| Kind | Path |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0059dc50_FUN_0059dc50.md` |
| Annotated | `docs/reconstruction/raw/aa_0059dc50_FUN_0059dc50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ObjectiveNode_IsEligibleForTracker_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0059dc50.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0059dc50_FUN_0059dc50.md` |
| Dual A | `docs/reconstruction/reviews/A_aa_0059dc50_ObjectiveNode_IsEligibleForTracker_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_0059dc50_ObjectiveNode_IsEligibleForTracker_Inferred.md` |
| Report | `docs/agents/task-dual-ab-0059dc50-mega-025-report.md` |

## Call graph (OWN sealed edge)

```text
Client_TryBindActiveMissionTracker (0092fd00)  [dualed]
  └─ CNDHash_LookupByKey(char+0x548, missionId)
       └─ ObjectiveNode_IsEligibleForTracker_Inferred (0059dc50)  [MEGA-025 OWN]
            └─ FUN_0059db80 (0059db80)  [residual sibling]
            └─ character virtual +0x27c     [product open]

FUN_009344b0 / FUN_008a8660 / FUN_0092b020 / FUN_008a5240
  └─ hash walk active objectives
       └─ ObjectiveNode_IsEligibleForTracker_Inferred
```

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / RET4 / body hex | **High** |
| Tracker eligibility gate role | **High** (parent dual + call sites) |
| Band + virtual threshold mechanics | **High** |
| Product field / band / vtbl English | **Inferred** → `_Inferred` suffix |
| Runtime Confirmed | **Open** |

## Gaps

- Product English for short@template+0xf8, byte@node+0x14, id band, virtual+0x27c.
- Sibling `FUN_0059db80` dual not in OWN scope.
- Runtime / bit-exact / differential.
