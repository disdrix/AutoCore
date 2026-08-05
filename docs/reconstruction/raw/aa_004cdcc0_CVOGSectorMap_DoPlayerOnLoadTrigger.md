# Raw capture: CVOGSectorMap_DoPlayerOnLoadTrigger

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cdcc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cdcc0` |
| **Canonical name** | `CVOGSectorMap_DoPlayerOnLoadTrigger` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* CVOGSectorMap_DoPlayerOnLoadTrigger: fire m_coidPerPlayerLoadTrigger after character add.
   Server: SectorMap.FireOnLoadPlayerMissions after Stage3 creates. */

void __fastcall CVOGSectorMap_DoPlayerOnLoadTrigger(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004bb1c0(0,*(undefined4 *)(param_1 + 0xe7e0),*(undefined4 *)(param_1 + 0xe7e4));
  if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x004cdd0d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x114))();
    return;
  }
  return;
}
```
