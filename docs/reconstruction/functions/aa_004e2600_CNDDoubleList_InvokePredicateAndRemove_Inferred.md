# Function record: CNDDoubleList_InvokePredicateAndRemove_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e2600` |
| **Canonical name** | `CNDDoubleList_InvokePredicateAndRemove_Inferred` |
| **Prior** | `FUN_004e2600` |
| **Address** | `0x004e2600` |
| **System** | skills-abilities (generic list; ValidateTarget consumer) |
| **Name confidence** | **Probable** — CS list shape + RTTI family `CNDDoubleList@PAVCVOGHBBase`; method name Inferred |
| **Status** | Human-refined + dual A/B (2026-07-29 dual quality pass) |

## Purpose

Thread-safe walk of a double-linked list under critical section. For each node, invoke `callback(payload, ctx, &stopFlag)`. When callback returns non-zero, unlink node and destroy via vtbl; continue until list end or stopFlag set.

## Evidence

| Fact | Source |
|------|--------|
| Enter/LeaveCriticalSection on `this+4` | decompile |
| Used by ValidateTarget accept path | `Skill_ValidateTargetForSkill` on `target+0xB0` |
| List shape matches CNDDoubleList | RTTI strings + layout |
| Many non-skill callers | reactions, spawn, creature paths |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004e2600_FUN_004e2600.md` (+ rename append)
- Annotated: `docs/reconstruction/raw/aa_004e2600_CNDDoubleList_InvokePredicateAndRemove_Inferred.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CNDDoubleList_InvokePredicateAndRemove_Inferred.cpp`
- Dual: `reviews/A|B_aa_004e2600_CNDDoubleList_InvokePredicateAndRemove_Inferred.md`
