# Function record: Character_GetXpRemainingToMaxLevelSoftCap_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004111d0` |
| **Canonical name** | `Character_GetXpRemainingToMaxLevelSoftCap_Inferred` |
| **Ghidra name** | `FUN_004111d0` |
| **Address** | `0x004111d0`–`0x004111e9` (**26 B** measured) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Classification** | wrapper / leaf compute |
| **Dual** | MEGA-124 2026-08-05 — **accept-with-gaps** |
| **Name confidence** | Inferred (formula + toast caller; no product symbol) |

## Role

Return XP room remaining under the max-level soft-cap (`threshold(maxLevel) − totalXp − 1`). Sole consumer is the mission reward chat toast clamp path in `Client_ShowMissionRewardChatToast` when `char+0x6b4 < 1`.

## Offsets

| Offset | Role | Width |
|--------|------|-------|
| `+0xc50` | max level (table key) | ushort load |
| `+0x730` | total experience | int32 |

## See also

- Ghidra twin record: `aa_004111d0_FUN_004111d0.md`
- Threshold table: `Experience_GetCumulativeThreshold` (`aa_0052c860`)
- Soft-cap write twin: `CVOGReaction_AddExperience`
- Toast parent: `Client_ShowMissionRewardChatToast` (`aa_008ac540`)
