# Function record: AssResolverCore_HeadBag_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00469db0` |
| **Canonical name** | `AssResolverCore_HeadBag_Ctor_Inferred` |
| **Ghidra name** | `FUN_00469db0` |
| **Address** | `0x00469db0`–`0x00469e12` exclusive (**98 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | assets / AssResolverCore |
| **Completion status** | **Dual A/B sealed (W32-E)** — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Head-bag placement ctor for AssResolverCore (list sentinel + 9-slot pointer vector + flags). Sole caller `AssResolverCore_Ctor_Inferred`.

## Signature

```c
AssResolverCore_HeadBag* AssResolverCore_HeadBag_Ctor_Inferred(AssResolverCore_HeadBag* self /*stack*/);
```

## Artifacts

- See `aa_00469db0_FUN_00469db0.md` for full artifact table.
- Report: `docs/agents/task-dual-ab-00469db0-00985010-w32e-report.md`
