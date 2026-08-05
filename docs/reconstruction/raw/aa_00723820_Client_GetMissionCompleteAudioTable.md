# Raw capture: Client_GetMissionCompleteAudioTable

| Field | Value |
|---|---|
| **Stable ID** | `aa_00723820` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00723820` |
| **Canonical name** | `Client_GetMissionCompleteAudioTable` |
| **System** | missions-progression |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* Client_GetMissionCompleteAudioTable
   
   One-time init of mission-complete audio/UI table at DAT_00d20210.
   Called with names mission_complete_3 / mission_complete_5 from CVOGReaction_CompleteObjective. */

undefined * Client_GetMissionCompleteAudioTable(void)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009ac7a0;
  local_c = ExceptionList;
  if ((DAT_00d20630 & 1) == 0) {
    DAT_00d20630 = DAT_00d20630 | 1;
    local_4 = 0;
    ExceptionList = &local_c;
    FUN_00723510(&DAT_00d20210);
    _atexit((_func_4879 *)&LAB_009c3700);
  }
  ExceptionList = local_c;
  return &DAT_00d20210;
}
```
