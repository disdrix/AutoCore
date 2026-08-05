# Function record: FUN_0076cef0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076cef0` |
| **Canonical name** | `Profiler_ScopeLeave` (prefer named record) |
| **Ghidra name** | `FUN_0076cef0` |
| **Address** | `0x0076cef0` |
| **Body range** | `0x0076cef0` only (1 byte `c3`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client instrumentation / profiler |
| **Completion status** | **partial** — dual A/B **accept** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `reviews/A_aa_0076cef0_Profiler_ScopeLeave.md`, `reviews/B_aa_0076cef0_Profiler_ScopeLeave.md` |
| **Last reviewed** | `2026-07-29` (W19-D) |

## Alias

- `Profiler_ScopeLeave` (canonical structural)
- Plausible: `Profiler_ScopeExit` (not sealed)

## Purpose

Empty profiler leave leaf. See named record.

## Signature

```c
void FUN_0076cef0(void);
```

## Artifacts

- Named record: `docs/reconstruction/functions/aa_0076cef0_Profiler_ScopeLeave.md`
- Raw / annotated / clean / reviews: see named record
