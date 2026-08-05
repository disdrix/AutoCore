# Raw capture: FUN_0083dcb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0083dcb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0083dcb0` |
| **Canonical name** | `FUN_0083dcb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0083dcb0(int param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  char local_10 [16];
  
  sprintf(local_10,"%i%i",*(undefined4 *)(param_1 + 0x4fc));
  iVar2 = atoi(local_10);
  iVar3 = (**(code **)(**(int **)(param_1 + 0x500) + 0x25c))();
  if (iVar3 < iVar2) {
    uVar4 = (**(code **)(**(int **)(param_1 + 0x500) + 0x25c))();
    *(undefined4 *)(param_1 + 0x4fc) = uVar4;
    FUN_0083dae0();
    return;
  }
  iVar3 = (**(code **)(**(int **)(param_1 + 0x500) + 0x25c))();
  if (iVar2 <= iVar3) {
    *(int *)(param_1 + 0x4fc) = iVar2;
    FUN_0083dae0();
    return;
  }
  iVar3 = *(int *)(*(int *)(param_1 + 0x500) + 0xa8);
  if (*(int *)(iVar3 + 0x38) == 4) {
    uVar5 = 999999;
  }
  else {
    uVar1 = *(ushort *)(*(int *)(iVar3 + 0x3c) + 0x4ba);
    uVar5 = (uint)uVar1;
    if (uVar1 == 0) {
      uVar5 = 200;
    }
  }
  if ((int)(uVar5 & 0xffff) < iVar2) {
    uVar5 = FUN_0040ac40();
    *(uint *)(param_1 + 0x4fc) = uVar5 & 0xffff;
  }
  FUN_0083dae0();
  return;
}
```
