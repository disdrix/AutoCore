# Raw capture: FUN_0064cce0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064cce0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0064cce0` |
| **Canonical name** | `FUN_0064cce0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0064cce0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  
  iVar3 = param_2;
  iVar1 = *(int *)(param_2 + 4);
  if (iVar1 != *(int *)(param_1 + 4)) {
    if (iVar1 == 0) {
      return;
    }
    for (iVar2 = *(int *)(iVar1 + 0xc); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xc)) {
      iVar1 = iVar2;
    }
    if (*(int *)(iVar1 + 0x20) == 0) {
      return;
    }
    pcVar4 = (char *)FUN_0064b270(&param_2,0x1000);
    if (*pcVar4 == '\0') {
      return;
    }
  }
  *(undefined4 *)(iVar3 + 0xc) = 1;
  return;
}
```
