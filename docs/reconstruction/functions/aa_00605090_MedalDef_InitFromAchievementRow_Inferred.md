# Function record: MedalDef_InitFromAchievementRow_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00605090` |
| **Canonical name** | `MedalDef_InitFromAchievementRow_Inferred` |
| **Address** | `0x00605090` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **Dual A/B present** (2026-07-29) — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Alias

- Ghidra: `FUN_00605090`

## Purpose

Fill MedalDef 0x1c from one tAchievement row (0x3d4): id, four W→ACP strings, two trailing dwords. `ret 0x20`.

## Signature

```c
bool __thiscall MedalDef_InitFromAchievementRow(
  MedalDef *this, uint32_t id,
  const wchar_t *w0, const wchar_t *w1, void *unused,
  const wchar_t *w3, const wchar_t *w2, uint32_t a, uint32_t b);
```

## Artifacts

- Dual A/B under `reviews/A_aa_00605090_*` / `B_aa_00605090_*`
- Raw / clean scaffold present
