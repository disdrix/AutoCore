# Raw capture: FUN_007a4ee0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a4ee0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007a4ee0` |
| **Canonical name** | `FUN_007a4ee0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int FUN_007a4ee0(int param_1,int param_2)

{
  int iVar1;
  int in_EAX;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  
  if (*(int *)(in_EAX + 8) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(int *)(in_EAX + 0xc) - *(int *)(in_EAX + 8) >> 2;
  }
  uVar3 = 0;
  if (uVar2 != 0) {
    piVar4 = *(int **)(in_EAX + 8);
    do {
      iVar1 = *piVar4;
      if (((iVar1 != 0) && (*(int *)(iVar1 + 0x200) == param_1)) &&
         (*(int *)(iVar1 + 0x204) == param_2)) {
        return (*(int **)(in_EAX + 8))[uVar3];
      }
      uVar3 = uVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (uVar3 < uVar2);
  }
  return 0;
}
```
