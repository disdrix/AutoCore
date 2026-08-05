# Raw capture: FUN_0084fdf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0084fdf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0084fdf0` |
| **Canonical name** | `FUN_0084fdf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_0084fdf0(int *param_1,int param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  if (40000 < param_3) {
    if ((param_2 != 5) && (param_2 != 6)) {
      if (param_2 != 8) goto LAB_0084fe23;
      FUN_0084f810();
    }
    return 1;
  }
LAB_0084fe23:
  cVar1 = (**(code **)(*param_1 + 0xd8))();
  if ((cVar1 != '\0') && (param_1[0xac] != 0)) {
    uVar2 = (**(code **)(*(int *)param_1[0xac] + 0x338))(param_2,param_3);
    return uVar2;
  }
  return 0;
}
```
