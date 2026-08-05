# Raw capture: FUN_0074dba0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074dba0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0074dba0` |
| **Canonical name** | `FUN_0074dba0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_0074dba0(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int *local_4;
  
  local_4 = param_1;
  FUN_0046c1b0();
  piVar1 = local_4;
  if (local_4 == (int *)param_1[5]) {
    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\animation\\anmPriorityBlendController.cpp",
                   0xfa,1,"RemoveAnimation() called with animation that is not added to controller!"
                  );
    return 0;
  }
  (**(code **)(*param_1 + 0x3c))(param_2,local_4 + 3);
  FUN_00449ff0(&local_4,piVar1);
  return param_2;
}
```
