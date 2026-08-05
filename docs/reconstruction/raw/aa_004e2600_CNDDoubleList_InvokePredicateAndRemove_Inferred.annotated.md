# Annotated low-level: CNDDoubleList_InvokePredicateAndRemove_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_004e2600` |
| VA | `0x004e2600` |
| Canonical name | `CNDDoubleList_InvokePredicateAndRemove_Inferred` |
| Prior | `FUN_004e2600` |
| System | skills-abilities (generic utility; ValidateTarget consumer) |
| Date | 2026-07-29 |

## Machine-level notes

- Generic CS-protected intrusive double-list walk/remove — **not skill-specific**.
- Layout: `CS@+4`, head `@+0x1c`, tail `@+0x20`, count `@+0x24`, busy byte `@+0x28`.
- Callback `(node[1] payload, ctx, &stopFlag)`; non-zero → unlink node, optional null payload, `node->vtbl[0](1)` destroy.
- Continues while `stopFlag == 0` after a match; exits on empty list.
- **ValidateTarget path:** `Skill_ValidateTargetForSkill` thiscall on `target+0xB0` with predicate `Skill_ValidateTarget_HBSkillListener`.
- **RTTI family:** `CNDDoubleList<CVOGHBBase*>` / `CNDDoubleListNode` / `CNDDoubleListPtr` strings present; method mangling not recovered → `_Inferred`.

## Open questions

- Exact mangled method name (RemoveIf / ForEachRemove / InvokeAndDelete).
- Whether all `this` sites are CNDDoubleList vs CVOGHBList wrapper (CVOGHBList_ctor also init CS at +4).
