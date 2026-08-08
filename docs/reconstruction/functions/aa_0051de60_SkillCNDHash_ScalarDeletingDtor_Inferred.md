# Function record: SkillCNDHash_ScalarDeletingDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051de60` |
| **Canonical name** | `SkillCNDHash_ScalarDeletingDtor_Inferred` |
| **Ghidra name** | `FUN_0051de60` |
| **Address** | `0x0051de60`–`0x0051de7d` inclusive (**30 bytes** / exclusive end `0x0051de7e`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / skill-family CNDHash |
| **Completion status** | **accept-with-gaps** — dual A/B sealed 2026-08-04 (WQ9F-H OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

MSVC scalar-deleting destructor (vtbl[0] of `PTR_FUN_009ce1b8`): run complete dtor `FUN_0051de80`, optionally `operator_delete(this)` when `(flags & 1)`, return this. Same vtbl family as dualed `SkillCNDHash_Ctor_Inferred`.

## Signature (byte-sealed)

```c
void* __thiscall SkillCNDHash_ScalarDeletingDtor_Inferred(void* self, uint8_t flags);
// ECX=this; stack flags; RET 4; returns this*
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0051de60_FUN_0051de60.md`
- Annotated: `docs/reconstruction/raw/aa_0051de60_FUN_0051de60.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/SkillCNDHash_ScalarDeletingDtor_Inferred.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_0051de60.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0051de60_SkillCNDHash_ScalarDeletingDtor_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_0051de60_SkillCNDHash_ScalarDeletingDtor_Inferred.md`
- Alias record: `docs/reconstruction/functions/aa_0051de60_FUN_0051de60.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| DATA | `PTR_FUN_009ce1b8[0]` @ `0x009ce1b8` | vtbl slot 0 |
| Callee | `FUN_0051de80` | complete dtor (not OWN) |
| Callee | `operator_delete` | free host when flags bit0 |

## Confidence

| Claim | Level |
|---|---|
| Scalar deleting CF (complete + optional free + ret 4) | **Confirmed** (bytes) |
| vtbl[0] of skill CNDHash | **Confirmed** |
| Product English class name | Open |
| Complete dtor dual | Open (not OWN) |
| Runtime / image diff | Open |
