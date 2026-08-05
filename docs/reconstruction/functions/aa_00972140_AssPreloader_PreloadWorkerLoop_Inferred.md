# Function record: AssPreloader_PreloadWorkerLoop_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00972140` |
| **Canonical name** | `AssPreloader_PreloadWorkerLoop_Inferred` |
| **Ghidra name** | `FUN_00972140` |
| **Address** | `0x00972140`–`0x00972421` (**738 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | assPreloader / asset preload pipeline |
| **Completion status** | Dual A/B sealed W32-K 2026-07-29 — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

AssPreloader worker-thread body: while the pending GuardedVector at `host+0x1c` is non-empty, drain work, optionally load a geo/xml asset from a snapshot of the resource-cache factory list, record success under CS or log PRELOAD failure, then yield.

## Signature

```c
// stack host; RET 4; void
void AssPreloader_PreloadWorkerLoop_Inferred(void* host /*stack*/);
```

## Host offsets (sealed)

| Off | Role |
|-----|------|
| `+0x1c` | pending GuardedVector (empty-check) |
| `+0x4c` | success stride-2 result vector |
| `+0x60` / `+0x78` | CS + gate for success push |
| `+0x7c` | tracked vector (fail-path push) |
| `+0x90` / `+0xa8` | CS + gate for fail-path (+0x7c embed) |
| `+0xdc` / `+0xe0` | ticket pair |
| `+0x110` | resource cache* (`+0x28` factory list) |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00972140_FUN_00972140.md`
- Annotated: `docs/reconstruction/raw/aa_00972140_FUN_00972140.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/AssPreloader_PreloadWorkerLoop_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00972140.cpp`
- FUN record: `docs/reconstruction/functions/aa_00972140_FUN_00972140.md`
- Review A/B: `docs/reconstruction/reviews/A_aa_00972140_AssPreloader_PreloadWorkerLoop_Inferred.md`, `B_…`
- Agent report: `docs/agents/task-dual-ab-00971820-00972140-w32k-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF + ABI + RET 4 + pending loop | **High** |
| geo/xml type map + PRELOAD log path | **High** |
| Product family (`assPreloader.cpp`) | **High** |
| Method English | **Inferred** |
| Nested `FUN_00971280` / `FUN_00971b80` product plates | **Open** (W32-J / residual) |
| Runtime / bit-exact | **Open** |
