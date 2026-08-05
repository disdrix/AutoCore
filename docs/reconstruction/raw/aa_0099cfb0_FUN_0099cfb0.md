# Raw capture: FUN_0099cfb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0099cfb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0099cfb0` |
| **Canonical name** | `FUN_0099cfb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0099cfb0(int param_1,int param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (*(int *)(param_1 + 0x14) != 0) {
    FUN_0043f4b0();
  }
  if (*(int *)(*(int *)(param_1 + 0x14) + 0x34) == 0) {
    FUN_00967150(*(int *)(param_1 + 0x14) + 0x24);
  }
  FUN_00734550();
  iVar1 = *(int *)(param_2 + 0x10);
  if ((*(byte *)(iVar1 + 0xbc) & 1) != 0) {
    iVar1 = FUN_00972e50();
  }
  if ((*(uint *)(*(int *)(param_2 + 0x10) + 0xbc) >> 2 & 1) == 0) {
    uVar2 = CONCAT44(iVar1,*(int *)(param_2 + 0x10) + 0xa8);
  }
  else {
    uVar2 = FUN_00972b20();
  }
  FUN_00752df0(*(undefined4 *)(param_2 + 4),(int)((ulonglong)uVar2 >> 0x20),1,(int)uVar2,0,0);
  return;
}
```
