# Raw capture: FUN_0090dfa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090dfa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0090dfa0` |
| **Canonical name** | `FUN_0090dfa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall
FUN_0090dfa0(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((char)param_3 != '\0') {
    *(undefined1 *)(param_1 + 0x508) = 1;
    iVar1 = (**(code **)(*param_2 + 0x10))();
    *(undefined4 *)(iVar1 + 0xbc) = 0xffffffff;
    *(int *)(iVar1 + 0xb4) = *(int *)(iVar1 + 0xb4) + 1;
    *(undefined4 *)(iVar1 + 0x90) = param_3;
    *(undefined4 *)(iVar1 + 0x94) = param_4;
    *(undefined4 *)(iVar1 + 0x98) = param_5;
    return;
  }
  *(undefined1 *)(param_1 + 0x508) = 0;
  uVar2 = (**(code **)(*(int *)param_2[0x23] + 0x40))("Color");
  (**(code **)(*(int *)param_2[0x23] + 0x4c))(uVar2,&stack0xffffffec);
  return;
}
```
