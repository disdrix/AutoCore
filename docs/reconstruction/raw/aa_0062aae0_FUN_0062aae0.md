# Raw capture: FUN_0062aae0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0062aae0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0062aae0` |
| **Canonical name** | `FUN_0062aae0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall
FUN_0062aae0(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  ushort uVar4;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  piVar1 = (int *)(param_1 + 0x14);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    iVar2 = *(int *)(param_3 + 0x20);
    iVar3 = *(int *)(param_2 + 0x20);
    uVar4 = *(ushort *)(iVar2 + 0x5c);
    if (*(ushort *)(iVar3 + 0x5c) < *(ushort *)(iVar2 + 0x5c)) {
      uVar4 = *(ushort *)(iVar3 + 0x5c);
    }
    *(uint *)(param_1 + 0x14) = uVar4 + 1;
    local_10 = param_2;
    local_c = param_3;
    local_8 = param_5;
    local_14 = param_1;
    FUN_0062a650(*(undefined4 *)(param_1 + 8),&local_14);
    if (*(int *)(iVar3 + 100) != 0) {
      FUN_00600100(iVar3,&local_14);
    }
    if (*(int *)(iVar2 + 100) != 0) {
      FUN_00600100(iVar2,&local_14);
    }
  }
  return;
}
```
