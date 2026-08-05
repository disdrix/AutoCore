# Raw capture: FUN_008f5dd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008f5dd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008f5dd0` |
| **Canonical name** | `FUN_008f5dd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_008f5dd0(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  char unaff_BL;
  int *piVar3;
  int iVar4;
  
  piVar3 = (int *)(in_EAX + 0x540);
  iVar4 = 2;
  do {
    if (*piVar3 != 0) {
      iVar2 = 0xe88;
      do {
        iVar1 = *(int *)(iVar2 + *piVar3);
        if ((iVar1 != 0) && (*(undefined1 *)(iVar1 + 0x51c) = 1, unaff_BL != '\0')) {
          *(undefined1 *)(iVar1 + 0x51d) = 1;
        }
        iVar2 = iVar2 + 4;
      } while (iVar2 < 0x10e0);
    }
    piVar3 = piVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}
```
