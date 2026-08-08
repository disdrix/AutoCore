# Function record: CVOGObject_EvalChildDeliverObjectiveInteract_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d3ba0` |
| **Canonical name** | `CVOGObject_EvalChildDeliverObjectiveInteract_Inferred` |
| **Ghidra name** | `FUN_004d3ba0` |
| **Address** | `0x004d3ba0`–`0x004d3ee2` inclusive (**835 B** / `0x343`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation |
| **Dual** | MEGA-069 OWN-ONLY 2026-08-05 |
| **Verdict** | **accept-with-gaps** |
| **Terminal** | **false** |

## Signature

```c
/* CVOGObject_EvalChildDeliverObjectiveInteract_Inferred
   Type-0x25 child deliver/use objective interact eval.
   thiscall; ECX=host (+0xe4e8 reaction mgr); RET 8; AL in {0,4,5,8}. */
char __thiscall CVOGObject_EvalChildDeliverObjectiveInteract_Inferred(
    void *this_host,
    void *child_reaction,
    void *character);
```

## Role in chain

```text
CVOGObject_EvalInteractStateFromChildren  0x004d7640
  └─ type 0x25:
        ├─ THIS  CVOGObject_EvalChildDeliverObjectiveInteract_Inferred  0x004d3ba0
        ├─ CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred  0x004d2e50
        └─ CVOGObject_EvalOfferableMissionInteractState                 0x004d5aa0
```

## Returns

| AL | CF meaning |
|---|---|
| 0 | no match / gate fail |
| 4 | action present, `+0x138==0` |
| 5 | requirements fail (type-3 continent or predicate) |
| 8 | requirements pass / empty |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004d3ba0_FUN_004d3ba0.md`
- Annotated: `docs/reconstruction/raw/aa_004d3ba0_FUN_004d3ba0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGObject_EvalChildDeliverObjectiveInteract_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_004d3ba0.cpp`
- A: `docs/reconstruction/reviews/A_aa_004d3ba0_CVOGObject_EvalChildDeliverObjectiveInteract_Inferred.md`
- B: `docs/reconstruction/reviews/B_aa_004d3ba0_CVOGObject_EvalChildDeliverObjectiveInteract_Inferred.md`
- FUN record: `docs/reconstruction/functions/aa_004d3ba0_FUN_004d3ba0.md`
- Report: `docs/agents/task-dual-ab-004d3ba0-mega-069-report.md`

## Gaps

- Product English for states 4/5/8 and field names.
- Exact class of `this_host`.
- Runtime / bit-exact / differential.
