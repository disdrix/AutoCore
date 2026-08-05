# Function record: Client_ProcessSectorUpdate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00811e00` |
| **Canonical name** | `Client_ProcessSectorUpdate_Inferred` |
| **Ghidra name** | `FUN_00811e00` |
| **Address** | `0x00811e00`–`0x008120c8` (**713 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client net / sector object update |
| **Completion status** | **Dual-reviewed 2026-07-29 W26-M** — accept-with-gaps |

Primary record with full tables: `docs/reconstruction/functions/aa_00811e00_FUN_00811e00.md`.

## Signature

```c
// ECX=packet*, EAX=object*, Stack[0x4]=game*, RET 4
void Client_ProcessSectorUpdate_Inferred(void* packet, void* game);
```

## Artifacts

- Raw / annotated / clean / dual A+B — see primary `FUN_00811e00` record.
