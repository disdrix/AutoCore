# Raw capture: FUN_005fff20

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fff20` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fff20` |
| **Canonical name** | `FUN_005fff20` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_005fff20(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *in_EAX;
  int iVar4;
  
  iVar3 = in_EAX[1];
  while (iVar3 = iVar3 + -1, -1 < iVar3) {
    if ((*(int *)(*in_EAX + iVar3 * 4) == 0) &&
       (in_EAX[1] = in_EAX[1] + -1, iVar4 = iVar3, iVar3 < in_EAX[1])) {
      do {
        iVar2 = iVar4 * 4;
        iVar1 = iVar4 * 4;
        iVar4 = iVar4 + 1;
        *(undefined4 *)(*in_EAX + iVar1) = *(undefined4 *)(*in_EAX + 4 + iVar2);
      } while (iVar4 < in_EAX[1]);
    }
  }
  return;
}
```
