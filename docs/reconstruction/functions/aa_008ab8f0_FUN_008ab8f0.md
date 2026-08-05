# Function record: FUN_008ab8f0 (legacy path)

> **REDIRECT (2026-07-29):** Canonical name and record is
> **[`aa_008ab8f0_Client_MissionDialog_FlushPreparedResponse.md`](aa_008ab8f0_Client_MissionDialog_FlushPreparedResponse.md)**.
>
> Do not use this file as the primary unit record. Kept so older links to the FUN scaffold do not break.

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ab8f0` |
| **Canonical name** | `Client_MissionDialog_FlushPreparedResponse` (was `FUN_008ab8f0`) |
| **Address** | `0x008ab8f0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **Redirect** → promoted record |
| **Primary record** | `functions/aa_008ab8f0_Client_MissionDialog_FlushPreparedResponse.md` |
| **Primary raw** | `raw/aa_008ab8f0_Client_MissionDialog_FlushPreparedResponse.md` |
| **Primary clean** | `reconstructed-exact/Client_MissionDialog_FlushPreparedResponse.cpp` |

## One-line purpose

On mission-dialog teardown, if `dialog+0x650` (prepared opcode) is non-zero, send **0x20** bytes from that buffer via sector connection `DAT_00d1b4b8` vtbl `+0x18` — the **C2S 0x206E** flush site.
