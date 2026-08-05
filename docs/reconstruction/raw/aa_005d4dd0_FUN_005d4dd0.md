# Raw capture: FUN_005d4dd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d4dd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005d4dd0` |
| **Canonical name** | `FUN_005d4dd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005d4dd0(int param_1)

{
  int iVar1;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  FUN_0053dd40();
  if (*(int *)(param_1 + -0xd8) != 0) {
    (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0xdc + param_1) + 0xfc))();
    FUN_004e88e0(&uStack_1c,*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0x5c + param_1);
    FUN_004e87d0(&uStack_10,*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0x4c + param_1);
    (*(code *)**(undefined4 **)(param_1 + -0xa0))
              (1,uStack_1c,uStack_18,uStack_14,uStack_10,uStack_c,uStack_8,uStack_4,
               *(undefined1 *)(param_1 + -0x93));
    iVar1 = *(int *)(*(int *)(param_1 + -0xdc) + 4) + param_1;
    (**(code **)(*(int *)(iVar1 + -0xdc) + 0xb8))(*(undefined4 *)(iVar1 + -0x24));
    (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0xdc) + 4) + -0xdc + param_1) + 0x100))();
  }
  return;
}
```
