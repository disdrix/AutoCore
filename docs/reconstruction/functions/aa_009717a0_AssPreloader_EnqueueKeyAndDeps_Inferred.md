# Function record: AssPreloader_EnqueueKeyAndDeps_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009717a0` |
| **Canonical name** | `AssPreloader_EnqueueKeyAndDeps_Inferred` |
| **Ghidra name** | `FUN_009717a0` |
| **Address** | `0x009717a0`–`0x0097181c` (**124 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | assPreloader / asset preload pipeline |
| **Completion status** | Dual A/B sealed W32-J 2026-07-29 — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Classification** | worker |

## Purpose

Enqueue one asset key and its collected dependencies into AssPreloader pending (via W31-K `AssPreloader_EnqueueEligibleFromRing_Inferred`). Thin wrapper: local ring seed → dep expand → eligible enqueue → clear.

## Signature

```c
// ECX = AssPreloader* this; stack const int* key; RET 4; returns 0
uint32_t AssPreloader_EnqueueKeyAndDeps_Inferred(
    void* self /*ECX*/,
    const int* key /*stack*/);
```

## Stage order (sealed)

1. Zero local GuardedVector.
2. `GuardedVector_PushBack_Thiscall(local, key)` (`FUN_0043d670`).
3. `FUN_00744360(key, &local)` with `ECX = *(*(self+0x110)+0x64)`.
4. `AssPreloader_EnqueueEligibleFromRing_Inferred(self, local)` (`FUN_00971640`; ESI=local).
5. `FUN_005b2ba0(local)` clear/free.
6. `return 0`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_009717a0_FUN_009717a0.md`
- Annotated: `docs/reconstruction/raw/aa_009717a0_FUN_009717a0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/AssPreloader_EnqueueKeyAndDeps_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_009717a0.cpp`
- FUN record: `docs/reconstruction/functions/aa_009717a0_FUN_009717a0.md`
- Review A/B: `docs/reconstruction/reviews/A_aa_009717a0_AssPreloader_EnqueueKeyAndDeps_Inferred.md`, `B_…`
- Agent report: `docs/agents/task-dual-ab-00971280-009717a0-w32j-report.md`

## Confidence

| Claim | Level |
|---|---|
| ECX this + stack key + RET 4 + return 0 | **High** |
| Stage order + `+0x110→+0x64` dep host | **High** |
| AssPreloader family (via W31-K enqueue + callers) | **High** (family) / **Inferred** (method English) |
| Nested `FUN_00744360` product plate | **Open** (W32-L) |
| Runtime / bit-exact | **Open** |
