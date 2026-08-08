# Function record: CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d2e50` |
| **Canonical name** | `CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred` |
| **Ghidra name** | `FUN_004d2e50` |
| **Address** | `0x004d2e50`–`0x004d319e` (**847 B** / `0x34F`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation |
| **Dual** | MEGA-068 OWN-ONLY 2026-08-05 — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (terminal **false**) |

## Purpose

Helper under `CVOGObject_EvalInteractStateFromChildren` for child type **0x25**: compute mission-related interact state from the child's mission-id vector (`+0x244`) and byte-filter vector (`+0x234`) using character `HasCompletedMission` / `CheckMissionRequirements` and region mission host `FUN_0053fff0`.

Returns:

| Code | Role |
|---|---|
| 0 | No qualifying state |
| 3 | Completed-mission residual (flag after path A/B) |
| 6/7 | Active/incomplete qualifying mission (`6 + (flag@+0x169!=0)`) |

## Signature (sealed)

```c
char __stdcall CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred(
    void *child_reaction,
    void *character);
```

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_004d2e50_FUN_004d2e50.md`
- Annotated: `docs/reconstruction/raw/aa_004d2e50_FUN_004d2e50.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004d2e50.cpp`
- FUN record: `docs/reconstruction/functions/aa_004d2e50_FUN_004d2e50.md`
- Review A/B: `docs/reconstruction/reviews/A_aa_004d2e50_CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred.md`, `B_aa_004d2e50_...`

## Call graph (OWN VA only)

```text
CVOGObject_EvalInteractStateFromChildren  [0x004d7640]  (parent; not OWN dual here)
  └─ FUN_004d2e50 / CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred  [OWN MEGA-068]
        ├─ FUN_0053fff0                    region mission host
        ├─ CVOGCharacter_HasCompletedMission
        ├─ CVOGCharacter_CheckMissionRequirements
        ├─ FUN_00547920                    pre-return side effect
        ├─ FUN_00402c40                    TraversalLock
        └─ FUN_007a4480                    HashError / VOG_DEBUG_STOP log
```

## Naming evidence

- Parent plate: type-0x25 deliver/use path calls this helper.
- Partition hint: “child active/complete mission interact eval”.
- Reject string-seed `VOG_DEBUG_STOP` names (lock diagnostics only).
- `_Inferred`: no PDB product English for exact symbol / code-3 label.

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / callers | **High** |
| Semantic name (family) | **Probable** |
| Product demangle | **Inferred** |
