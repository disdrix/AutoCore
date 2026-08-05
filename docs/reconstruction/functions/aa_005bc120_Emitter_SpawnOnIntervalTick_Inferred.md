# Function record: Emitter_SpawnOnIntervalTick_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bc120` |
| **Canonical name** | `Emitter_SpawnOnIntervalTick_Inferred` |
| **Ghidra name** | `FUN_005bc120` |
| **Address** | `0x005bc120`–`0x005bc3bc` (**669 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client::fx / emitter |
| **Completion status** | **Sealed** — dual A/B W26-I 2026-07-29; **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Dual verdict** | **accept** |

## Naming evidence

| Source | Value |
|---|---|
| Sole caller | `FUN_005bc3c0` — emitter update with string `"Emitter found at 0,0,0: %d %I64d"` |
| Role | countdown interval → spawn burst → random reschedule |
| Product mangled on this VA | **No** |

**Decision:** promote **`Emitter_SpawnOnIntervalTick_Inferred`** (role sealed; product English residual → `_Inferred`).

## Purpose / signature / artifacts

See twin record `aa_005bc120_FUN_005bc120.md`.
