# Function record: Math_RoundFloatToInt_MissionXpBias_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040dab0` |
| **Canonical name** | `Math_RoundFloatToInt_MissionXpBias_Inferred` |
| **Ghidra name** | `FUN_0040dab0` |
| **Address** | `0x0040dab0`–`0x0040dad7` inclusive (**40 B** / `0x28`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Calling convention** | stack `float`; **EAX** `int`; plain **`RET`** |
| **Completion status** | **Dual sealed** MEGA-119 (2026-08-05) — verdict **accept** |
| **Bit-for-bit / runtime / diff** | Open (Terminal **false**) |

## Purpose

Shared **signed float→int round** leaf used by the mission reward toast path (and other consumers). Applies `g_flMissionXpRoundBias` (**0.5001f** @ `0x00aaa6d0`) then truncates toward zero via `CVTTSS2SI`:

- `value < 0` → `(int)(value - bias)`
- `value >= 0` → `(int)(value + bias)`

Equivalent to half-away-from-zero with a slightly-over-half bias (0.5001) matching the grant path’s inline ±bias constant.

## Signature

```c
int Math_RoundFloatToInt_MissionXpBias_Inferred(float value);
```

## Chain (presentation)

```text
Client_ShowMissionRewardChatToast  [dualed parent 0x008ac540]
  ├─ Mission_ComputeObjectiveXp (gate)
  ├─ Mission_ComputeObjectiveXpAsFloat  [0x0051f510]
  │     └─ Mission_ComputeObjectiveXp
  └─ Math_RoundFloatToInt_MissionXpBias_Inferred  [OWN MEGA-119 0x0040dab0]
        → sprintf "Awarded %d ..." + Client_EnqueueCombatFloater
```

Grant path (`CVOGReaction_CompleteObjective`) applies ±bias **inline** then `CVOGReaction_AddExperience` — does **not** call this helper for authority grant.

## Naming gate

| Evidence | Present? |
|---|---|
| Algorithm sealed from SSE body | **Yes** |
| Shared bias VA + image float | **Yes** |
| Toast parent uses for XP int display | **Yes** |
| Product demangle / plate English | **No** → `_Inferred` |
| Toast-only exclusivity | **No** (multi-caller utility) |

**Retired:** `Mission_Bulk_0040dab0`.

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0040dab0_FUN_0040dab0.md` |
| Annotated | `docs/reconstruction/raw/aa_0040dab0_FUN_0040dab0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Math_RoundFloatToInt_MissionXpBias_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040dab0.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0040dab0_FUN_0040dab0.md` |
| Review A | `docs/reconstruction/reviews/A_aa_0040dab0_Math_RoundFloatToInt_MissionXpBias_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0040dab0_Math_RoundFloatToInt_MissionXpBias_Inferred.md` |
| Report | `docs/agents/task-dual-ab-0040dab0-mega-119-report.md` |

## Confidence

| Dimension | Level |
|---|---|
| Function boundary | **Confirmed** |
| Control flow | **Confirmed** |
| ABI | **Confirmed** |
| Bias constant | **Confirmed** |
| Toast parent role | **High** |
| Product English name | Open (`_Inferred`) |
