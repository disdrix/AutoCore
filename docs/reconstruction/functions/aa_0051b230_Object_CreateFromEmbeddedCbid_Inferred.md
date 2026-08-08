# Function record: Object_CreateFromEmbeddedCbid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b230` |
| **Canonical name** | `Object_CreateFromEmbeddedCbid_Inferred` |
| **Ghidra name** | `FUN_0051b230` |
| **Address** | `0x0051b230`–`0x0051b298` exclusive |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object-spawn / CVOGClonedObjectBase virtual |
| **Completion status** | **Dual sealed** WQ9R-H 2026-08-04 — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (no Launcher) |

## Naming basis

- **Structural:** GiveItemByCbid factory + vtbl+8 init family shared with `AllocateNewObjectFromCbid`.
- **RTTI:** callers cast result to `CVOGCreature` / `CVOGWeapon` from `CVOGClonedObjectBase`.
- **No product plate** → `_Inferred` suffix mandatory.

## Purpose

See `aa_0051b230_FUN_0051b230.md`. Named clean source is authoritative for port shape.

## Signature

```c
void * __thiscall Object_CreateFromEmbeddedCbid_Inferred(void *self);
```

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/Object_CreateFromEmbeddedCbid_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0051b230.cpp`
- Dual A/B under `docs/reconstruction/reviews/`
- Report: `docs/agents/task-dual-ab-0051b230-0051b2a0-wq9rh-report.md`

## Confidence

| Claim | Level |
|---|---|
| Name as structural factory | **Probable** |
| Product demangle | **Open** |
| Body semantics | **High** |
