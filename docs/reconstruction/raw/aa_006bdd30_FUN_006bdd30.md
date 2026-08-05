# Raw capture: FUN_006bdd30

| Field | Value |
|---|---|
| **Stable ID** | `aa_006bdd30` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006bdd30` |
| **Canonical name** | `FUN_006bdd30` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined1 *
FUN_006bdd30(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined1 local_11;
  undefined1 local_10 [4];
  undefined4 local_c;
  undefined4 local_8;
  int local_4;
  
  local_c = 0;
  local_8 = 0;
  local_4 = -0x80000000;
  FUN_006bd1c0(&local_11,param_2,param_3,param_4,param_5,&local_c,local_10);
  *param_1 = local_10[0];
  if (-1 < local_4) {
    (**(code **)(*DAT_00b05060 + 0x14))(local_c,local_4 << 5,0x12);
  }
  return param_1;
}
```
