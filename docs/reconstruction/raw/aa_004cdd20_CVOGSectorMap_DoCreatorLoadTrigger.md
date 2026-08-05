# Raw capture: CVOGSectorMap_DoCreatorLoadTrigger

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cdd20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cdd20` |
| **Canonical name** | `CVOGSectorMap_DoCreatorLoadTrigger` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* DoCreatorLoadTrigger: once per map instance (flag sector+0x74). Look up m_coidCreatorLoadTrigger
   (sector+0xE7E8) and fire vtable+0x114. Called from CVOGSectorMap_AddCharacter when character
   count condition met. */

void __fastcall CVOGSectorMap_DoCreatorLoadTrigger(int param_1)

{
  DWORD DVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x74) == '\0') {
    *(undefined1 *)(param_1 + 0x74) = 1;
    DVar1 = GetTickCount();
    *(DWORD *)(param_1 + 0x6c) = DVar1;
    iVar2 = FUN_004bb1c0(0,*(undefined4 *)(param_1 + 0xe7e8),*(undefined4 *)(param_1 + 0xe7ec));
    if (iVar2 != 0) {
                    /* WARNING: Could not recover jumptable at 0x004cdd86. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x114))();
      return;
    }
  }
  return;
}
```
