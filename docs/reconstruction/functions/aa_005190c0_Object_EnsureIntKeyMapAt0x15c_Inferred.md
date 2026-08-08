# Function record: Object_EnsureIntKeyMapAt0x15c_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005190c0` |
| **Canonical name** | `Object_EnsureIntKeyMapAt0x15c_Inferred` |
| **Ghidra name** | `FUN_005190c0` |
| **Address** | `0x005190c0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities (req map ensure) |
| **Completion status** | **Dual sealed** (WQ9R-E 2026-08-04) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Lazy-create empty int-key tree/map at object `+0x15C` for requirement aggregation and related probes.

## Signature

```c
IntKeyMapHeader* __fastcall Object_EnsureIntKeyMapAt0x15c_Inferred(void *host /* ECX */);
```

## Dual A/B

| Review | Verdict |
|---|---|
| A | accept-with-gaps |
| B | accept-with-gaps |

## Artifacts

- Raw / annotated / clean / twin as listed on `aa_005190c0_FUN_005190c0.md`
- Agent report: `docs/agents/task-dual-ab-005190c0-00519280-wq9re-report.md`
