# Raw capture: FUN_0086efc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0086efc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0086efc0` |
| **Canonical name** | `FUN_0086efc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0086efc0(void)

{
  int iVar1;
  char cVar2;
  int in_EAX;
  undefined4 local_20 [2];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined1 local_8;
  
  FUN_0086ed60();
  local_20[0] = 0x9016;
  iVar1 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4);
  local_18 = *(undefined4 *)(iVar1 + 0x164 + DAT_00d1b6d8);
  local_14 = *(undefined4 *)(iVar1 + 0x168 + DAT_00d1b6d8);
  local_8 = *(undefined1 *)(in_EAX + 0x510);
  local_10 = 0xffffffff;
  local_c = 0xffffffff;
  if (DAT_00d1b4bc != (int *)0x0) {
    cVar2 = (**(code **)(*DAT_00d1b4bc + 8))();
    if (cVar2 != '\0') {
      (**(code **)(*DAT_00d1b4bc + 0x18))(0xffffffff,local_20,0x20,0);
    }
  }
  return;
}
```
