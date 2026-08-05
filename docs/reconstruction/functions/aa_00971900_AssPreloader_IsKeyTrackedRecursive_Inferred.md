# Function record: AssPreloader_IsKeyTrackedRecursive_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00971900` |
| **Canonical name** | `AssPreloader_IsKeyTrackedRecursive_Inferred` |
| **Ghidra name** | `FUN_00971900` |
| **Address** | `0x00971900`–`0x00971a19` (**282 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | assPreloader / asset preload pipeline |
| **Completion status** | Dual A/B sealed W31-K 2026-07-29 — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Membership test for an asset key against AssPreloader tracked set (`this+0x7c`), after always running the preloader drain (`FUN_00971480`). With recurse≠0, also treats dependency keys (collected by `FUN_00744360`) as tracked if any recursive call returns true.

## Signature

```c
// ECX=this; stack (key*, recurse); RET 8; AL=bool
uint8_t AssPreloader_IsKeyTrackedRecursive_Inferred(
    void* self /*ECX*/,
    const int* key /*stack*/,
    uint8_t recurse /*stack*/);
```

## Host offsets (sealed)

| Off | Role |
|-----|------|
| `+0x7c` | tracked GuardedVector (`GuardedVector_ContainsFirstEqual`) |
| (via drain) | `FUN_00971480` may touch broader preloader state |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00971900_FUN_00971900.md`
- Annotated: `docs/reconstruction/raw/aa_00971900_FUN_00971900.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/AssPreloader_IsKeyTrackedRecursive_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00971900.cpp`
- FUN record: `docs/reconstruction/functions/aa_00971900_FUN_00971900.md`
- Review A/B: `docs/reconstruction/reviews/A_aa_00971900_AssPreloader_IsKeyTrackedRecursive_Inferred.md`, `B_…`
- Agent report: `docs/agents/task-dual-ab-00971640-00971900-w31k-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF + ABI + +0x7c contains | **High** |
| AssPreloader product family | **High** (family) / **Inferred** (method English) |
| Nested `FUN_00744360` / `FUN_00971480` product plates | **Open** |
| Runtime / bit-exact | **Open** |
