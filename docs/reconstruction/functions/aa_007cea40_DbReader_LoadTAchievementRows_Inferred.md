# Function record: DbReader_LoadTAchievementRows_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007cea40` |
| **Canonical name** | `DbReader_LoadTAchievementRows_Inferred` |
| **Address** | `0x007cea40` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression / DB |
| **Completion status** | **Dual A/B present** (2026-07-29) — accept-with-gaps (structural) |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- Ghidra: `FUN_007cea40`
- Prior: `Named_tAchievement`

## Purpose

Load `//tAchievement/row` (or equivalent primary-path table) into 0x3d4-byte vector; out count. ECX = `*[DAT_00b0469c]` DbReader context. Dual backend on `DAT_00d1793c`.

## Signature

```c
HRESULT __thiscall DbReader_LoadTAchievementRows(
  DbReaderCtx *this, int *outCount, RowVector *outRows /* elem 0x3d4 */);
```

## Artifacts

- Dual A/B under `reviews/A_aa_007cea40_*` / `B_aa_007cea40_*`
- Raw / clean scaffold present (clean not bit-exact for SEH/COM)
