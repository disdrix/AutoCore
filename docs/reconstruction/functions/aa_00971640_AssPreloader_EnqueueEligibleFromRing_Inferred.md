# Function record: AssPreloader_EnqueueEligibleFromRing_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00971640` |
| **Canonical name** | `AssPreloader_EnqueueEligibleFromRing_Inferred` |
| **Ghidra name** | `FUN_00971640` |
| **Address** | `0x00971640`–`0x009716f7` (**184 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | assPreloader / asset preload pipeline |
| **Completion status** | Dual A/B sealed W31-K 2026-07-29 — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Enqueue asset keys from a caller-supplied GuardedVector ring into the AssPreloader pending set when they are missing from the host membership tree and unloaded (or absent) in the resource cache. Signals the preloader event when work was added.

## Signature

```c
// ESI = source ring; stack host; RET 4; void
void AssPreloader_EnqueueEligibleFromRing_Inferred(
    void* host /*stack*/,
    GuardedVectorHeader* source /*ESI*/);
```

## Host offsets (sealed)

| Off | Role |
|-----|------|
| `+0x04` | `HANDLE` event (`SetEvent`) |
| `+0x10` | tree / map for membership lower_bound (`FUN_0043d5e0`) |
| `+0x14` | end iterator for that tree |
| `+0x1c` | pending GuardedVector (contains + push) |
| `+0x110` | resource cache pointer (`FUN_0044e8c0`) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00971640_FUN_00971640.md`
- Annotated: `docs/reconstruction/raw/aa_00971640_FUN_00971640.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/AssPreloader_EnqueueEligibleFromRing_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00971640.cpp`
- FUN record: `docs/reconstruction/functions/aa_00971640_FUN_00971640.md`
- Review A/B: `docs/reconstruction/reviews/A_aa_00971640_AssPreloader_EnqueueEligibleFromRing_Inferred.md`, `B_…`
- Agent report: `docs/agents/task-dual-ab-00971640-00971900-w31k-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF + ABI + offsets | **High** |
| AssPreloader product family (via sibling `assPreloader.cpp` string) | **High** (family) / **Inferred** (exact method English) |
| Runtime / bit-exact | **Open** |
