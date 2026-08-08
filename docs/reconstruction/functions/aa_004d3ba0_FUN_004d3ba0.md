# Function record: FUN_004d3ba0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d3ba0` |
| **Canonical name** | `CVOGObject_EvalChildDeliverObjectiveInteract_Inferred` |
| **Ghidra name** | `FUN_004d3ba0` |
| **Address** | `0x004d3ba0`–`0x004d3ee2` (**835 B** / `0x343`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation |
| **Completion status** | **Dual sealed MEGA-069** — raw re-verify + annotated + clean named + A/B reviews |
| **Bit-for-bit / runtime / diff** | Open (no Launcher; terminal false) |
| **Dual verdict** | **accept-with-gaps** |

## Alias

- Canonical: `CVOGObject_EvalChildDeliverObjectiveInteract_Inferred`
- Ghidra: `FUN_004d3ba0`
- Retired: `Named_VOG_DEBUG_STOP_004d3ba0` (string diagnostic only)

## Purpose

Type-`0x25` child deliver/use objective interact-state helper: resolve child target pair, require NPC type 0x12, scan character world-object hash, score action requirements → AL ∈ {0,4,5,8}.

## Signature (assembly-sealed)

```c
// ECX=host; stack child, character; RET 8
char __thiscall CVOGObject_EvalChildDeliverObjectiveInteract_Inferred(
    void *this_host,
    void *child_reaction,
    void *character);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004d3ba0_FUN_004d3ba0.md`
- Annotated: `docs/reconstruction/raw/aa_004d3ba0_FUN_004d3ba0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/CVOGObject_EvalChildDeliverObjectiveInteract_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_004d3ba0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_004d3ba0_CVOGObject_EvalChildDeliverObjectiveInteract_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_004d3ba0_CVOGObject_EvalChildDeliverObjectiveInteract_Inferred.md`
- Named record: `docs/reconstruction/functions/aa_004d3ba0_CVOGObject_EvalChildDeliverObjectiveInteract_Inferred.md`

## Callers / callees

| Direction | Symbols |
|---|---|
| Callers | `CVOGObject_EvalInteractStateFromChildren` (`0x004d7640`) ×2 sites |
| Callees | `FUN_0040fb90`, `FUN_004e0eb0`, `CVOGReaction_ResolveObjectTarget`, `FUN_007a4480`, `CNDHash_LookupByKey`, `FUN_00403430`, `operator_delete` |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + assembly | **High** |
| ABI thiscall RET 8; AL {0,4,5,8} | **High** |
| Sole parent type-0x25 role | **High** |
| Parameter product English | **Inferred** / Tentative |
| Runtime Confirmed | Open |

## Report

`docs/agents/task-dual-ab-004d3ba0-mega-069-report.md`
