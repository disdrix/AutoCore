# Function record: PerfStatRings_CommitAndTrim_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009668a0` |
| **Canonical name** | `PerfStatRings_CommitAndTrim_Inferred` |
| **Ghidra name** | `FUN_009668a0` |
| **Address** | `0x009668a0`–`0x00966c03` exclusive (**867 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | Palantir / frame perf stat rings |
| **Status** | Dual A/B sealed W30-E 2026-07-29 — **accept-with-gaps** |

## Purpose

Frame-path commit for a global perf-stat object (`DAT_00d1f614`): push period bins into GuardedVector rings, enforce dual window budgets (500 / 3000), publish snapshot, clear live state.

## Signature

```c
void __stdcall PerfStatRings_CommitAndTrim_Inferred(void* stats);
```

## Related

| VA / name | Relation |
|-----------|----------|
| `0x0043c830` GuardedVector_PushBack | Callee (×5) |
| `0x0076c3c0` | Timer sample callee |
| `0x007545c0` | Sole caller (Palantir frame) |
| `DAT_00d1f614` | Global stats object |

## Artifacts

See `aa_009668a0_FUN_009668a0.md`.
