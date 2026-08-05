# Function record: Client_DebugCmd_AddDisciplinePoints

| Field | Value |
|---|---|
| **Stable ID** | `aa_0094e530` |
| **Canonical name** | `Client_DebugCmd_AddDisciplinePoints` |
| **Ghidra name** | `FUN_0094e530` |
| **Address** | `0x0094e530`–`0x0094e617` (**231 B / `0xE7`**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression / client debug slash |
| **Completion status** | **Sealed (W31-T)** — dual A/B accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- Scaffold: `FUN_0094e530`
- Slash plate: `adddisciplinepoints`

## Purpose

Client debug slash-command body for **set discipline points**:

1. `strtok`/`atoi` key and amount (required).
2. Optional third token `1` → also set mapped max (`+0x10`) via `FUN_0052ade0`.
3. Absolute set via sealed `CVOGCharacter_SetMissionCounter` on `*(client+0xe98)`.
4. Refresh UI at `client+0x1074` when active (`vtbl+0x3d8` → `vtbl+0x448`).

## Signature (byte-sealed)

```c
// thiscall; ret 8
uint32_t Client_DebugCmd_AddDisciplinePoints(void *client, void *unused, char *delim);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0094e530_FUN_0094e530.md`
- Annotated: `docs/reconstruction/raw/aa_0094e530_FUN_0094e530.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_DebugCmd_AddDisciplinePoints.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0094e530.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0094e530_Client_DebugCmd_AddDisciplinePoints.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0094e530_Client_DebugCmd_AddDisciplinePoints.md`
- Report: `docs/agents/task-dual-ab-0094e530-005825d0-w31t-report.md`

## Callers / callees

**Registration:** `Client_RegisterDebugSlashCommands` @ `0x00959294` (handler imm + name `"adddisciplinepoints"` + help `"Set discipline [x] to [y], [1] to set max as well"`).

**Callees:** `strtok`, `atoi`, `CVOGCharacter_SetMissionCounter` (`0x005305b0`), `FUN_0052ade0`.

## Confidence

| Claim | Level |
|---|---|
| Body bounds + ret 8 | **Confirmed** |
| Tokens → SetMissionCounter | **Confirmed** |
| Flag 1 → max field +0x10 | **Confirmed** |
| Product discipline-key catalog | **Inferred** |
| Runtime golden | Open |
