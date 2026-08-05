# Function record: AssPackManager_CompactPackFile_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00985010` |
| **Canonical name** | `AssPackManager_CompactPackFile_Inferred` |
| **Ghidra name** | `FUN_00985010` |
| **Address** | `0x00985010`–`0x0098538d` exclusive (**893 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | assets / assPackManager packer |
| **Completion status** | **Dual A/B sealed (W32-E)** — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

In-place `.glm` pack compact via `_pack_tmp.glm` and `_pk_` staging. Sibling of `AssPackManager_OpenPackFile_Inferred` (`0x00984ee0`).

## Signature

```c
uint32_t AssPackManager_CompactPackFile_Inferred(const char* packPath /*ecx*/, int mode, char quiet);
```

## Artifacts

- See `aa_00985010_FUN_00985010.md` for full artifact table.
- Report: `docs/agents/task-dual-ab-00469db0-00985010-w32e-report.md`
