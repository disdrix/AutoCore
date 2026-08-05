# Raw capture: Input_TryFireSecondaryWeapons

| Field | Value |
|---|---|
| **Stable ID** | `aa_0091a550` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0091a550` |
| **Canonical name** | `Input_TryFireSecondaryWeapons` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void Input_TryFireSecondaryWeapons(void)

{
  char cVar1;
  
  if ((((DAT_00d1b6d8 != 0) &&
       ((*(byte *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xb8 + DAT_00d1b6d8) & 0xd2) == 0)) &&
      (g_pSectorNetConnection_INFERRED != (void *)0x0)) &&
     ((cVar1 = (**(code **)(*(int *)g_pSectorNetConnection_INFERRED + 8))(), cVar1 != '\0' &&
      (*(int *)(DAT_00d1b6d8 + 0x250) != 0)))) {
    cVar1 = FUN_004f52e0();
    if (cVar1 == '\0') {
      FUN_007a4480(0,"Failed to fire secondary weapons due to heat.\n");
      return;
    }
    FUN_004f5110();
    if (((*(char *)(DAT_00d1b6d8 + 0x6b8) != '\0') || (*(char *)(DAT_00d1b6d8 + 0x6b9) != '\0')) &&
       ((DAT_00d1b8f0 != (int *)0x0 &&
        (cVar1 = (**(code **)(*DAT_00d1b8f0 + 0x3d8))(), cVar1 != '\0')))) {
      FUN_0089ff80();
    }
  }
  return;
}
```
