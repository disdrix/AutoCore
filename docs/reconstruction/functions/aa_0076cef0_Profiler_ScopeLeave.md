# Function record: Profiler_ScopeLeave

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076cef0` |
| **Canonical name** | `Profiler_ScopeLeave` |
| **Ghidra name** | `FUN_0076cef0` |
| **Address** | `0x0076cef0` |
| **Body range** | `0x0076cef0` only (1 byte `c3`; exclusive end `0x0076cef1`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client instrumentation / profiler |
| **Completion status** | **partial** — dual A/B **accept**; CF + bytes sealed; product spelling residual |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0076cef0_Profiler_ScopeLeave.md`, `reviews/B_aa_0076cef0_Profiler_ScopeLeave.md` |
| **Last reviewed** | `2026-07-29` (W19-D) |

## Alias

- `FUN_0076cef0` (Ghidra)
- `Profiler_ScopeExit` / `Profiler_EndZone` (plausible product variants — **not sealed**)
- Residual scaffold-era unknown system label

## Purpose

**Profiler named-scope leave stub** — single-byte `RET`. Compiled-out counterpart to `Profiler_ScopeEnter` (`0x0076cf00`). High fan-in across client systems; **no side effects**.

## Signature

```c
void Profiler_ScopeLeave(void);  // bare ret; ignores any args
```

## Algorithm

1. `return;`

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0076cef0_FUN_0076cef0.md`
- Annotated: `docs/reconstruction/raw/aa_0076cef0_FUN_0076cef0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Profiler_ScopeLeave.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0076cef0.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00419ad0-0076cef0-w19d-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | none |
| **Callers** | ≥100 UNCONDITIONAL_CALL — AI/drive/physics/terrain/spawn/etc. paired with ScopeEnter |

## Confidence

| Claim | Level |
|---|---|
| Body is pure `ret` (`c3`) | **High** |
| No side effects | **High** |
| Leave twin of ScopeEnter `0x0076cf00` | **High** |
| Not `ret 4` (unlike enter) | **High** |
| Product/PDB symbol spelling | Open |
| Runtime / bit-exact | Open |

## Related

- `aa_0076cf00` Profiler_ScopeEnter
- Physics notes: `fn_004fc650_driveController`, `fn_004d6c80_stepTo`, `fn_00598650_applyAction` — ignore pair for port
