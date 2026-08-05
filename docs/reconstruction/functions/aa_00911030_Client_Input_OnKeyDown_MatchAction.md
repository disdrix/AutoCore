# Function record: Client_Input_OnKeyDown_MatchAction

| Field | Value |
|---|---|
| **Stable ID** | `aa_00911030` |
| **Canonical name** | `Client_Input_OnKeyDown_MatchAction` |
| **Address** | `0x00911030` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | input-drive-control |
| **Completion status** | **Human-refined partial** — ESC / scan / held+edge section banners; dual review open |
| **Bit-for-bit / runtime / diff** | Open |
| **Last refined** | 2026-07-23 |

## Purpose

WM key-down path: match DIK (+ optional LSHIFT) against ActionMap table, set held/edge flags, notify input pump. ESC UI cancel special-case.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00911030_Client_Input_OnKeyDown_MatchAction.md`
- Annotated: `docs/reconstruction/raw/aa_00911030_Client_Input_OnKeyDown_MatchAction.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_Input_OnKeyDown_MatchAction.cpp`

## Confidence

| Claim | Level |
|---|---|
| Table scan CF / held+edge stores | High |
| ESC UI cancel path | High |
| `pClient` rename | Probable |
