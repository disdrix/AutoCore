# Raw capture: FUN_004bdd40

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bdd40` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bdd40` |
| **Canonical name** | `FUN_004bdd40` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
uint __thiscall FUN_004bdd40(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  uint in_EAX;
  int iVar2;
  byte bVar3;
  
  if (*(int *)(param_1 + 0x1c) == 0) {
    return in_EAX & 0xffffff00;
  }
  iVar2 = *(int *)(param_1 + 0x14);
  bVar3 = 0;
  do {
    *(int *)(param_1 + 0x18) = iVar2;
    if ((int *)**(int **)(iVar2 + 0xc) != (int *)0x0) {
      bVar1 = (**(code **)(*(int *)**(int **)(iVar2 + 0xc) + 0x78))(param_2,param_3);
      bVar3 = bVar3 | bVar1;
    }
  } while ((*(int *)(param_1 + 0x18) != 0) &&
          (iVar2 = *(int *)(*(int *)(param_1 + 0x18) + 4), iVar2 != 0));
  return (uint)bVar3;
}
```
