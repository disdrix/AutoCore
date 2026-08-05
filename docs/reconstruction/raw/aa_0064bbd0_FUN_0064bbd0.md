# Raw capture: FUN_0064bbd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064bbd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0064bbd0` |
| **Canonical name** | `FUN_0064bbd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0064bbd0(int param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_20;
  undefined4 local_1c;
  
  puVar1 = (undefined4 *)(param_2 * 0xc0 + *(int *)(*(int *)(param_1 + 0xc) + 0x80));
  local_40 = *puVar1;
  local_3c = puVar1[1];
  local_38 = puVar1[2];
  local_34 = puVar1[3];
  local_30 = puVar1[4];
  local_2c = puVar1[5];
  local_28 = puVar1[6];
  local_24 = puVar1[7];
  local_1c = *(undefined4 *)(param_1 + 0x1f8);
  local_20 = 1;
  FUN_00580ed0(&local_40,param_3);
  return;
}
```
