# Function record: Object_LazyFillMatColorVecFromMesh_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b2a0` |
| **Canonical name** | `Object_LazyFillMatColorVecFromMesh_Inferred` |
| **Ghidra name** | `FUN_0051b2a0` |
| **Address** | `0x0051b2a0`–`0x0051b302` exclusive |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object / mesh material color bank |
| **Completion status** | **Dual sealed** WQ9R-H 2026-08-04 — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (no Launcher) |

## Naming basis

- Lazy empty-check on vector bank + mesh probe + `FUN_00519280` MatDiffuse/Ambient/Emissive fill.
- No product plate → `_Inferred`.

## Signature

```c
void __thiscall Object_LazyFillMatColorVecFromMesh_Inferred(
    void *self, uint32_t c0, uint32_t c1, uint32_t c2, uint32_t c3);
```

## Artifacts

- Clean: `docs/reconstruction/reconstructed-exact/Object_LazyFillMatColorVecFromMesh_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_0051b2a0.cpp`
- Dual A/B under `docs/reconstruction/reviews/`
- Report: `docs/agents/task-dual-ab-0051b230-0051b2a0-wq9rh-report.md`

## Confidence

| Claim | Level |
|---|---|
| Structural name | **Probable** |
| Product demangle | **Open** |
| Body semantics | **High** |
