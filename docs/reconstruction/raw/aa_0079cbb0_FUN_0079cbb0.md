# Raw capture: FUN_0079cbb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0079cbb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0079cbb0` |
| **Canonical name** | `FUN_0079cbb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

int __thiscall FUN_0079cbb0(int *param_1,int *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  undefined1 local_2710 [9996];
  undefined4 uStack_4;
  
  uStack_4 = 0x79cbba;
  iVar1 = 0;
  for (; param_3 != 0; param_3 = param_3 - uVar2) {
    uVar2 = 10000;
    if (param_3 < 0x2711) {
      uVar2 = param_3;
    }
    (**(code **)(*param_2 + 4))(local_2710,uVar2);
    (**(code **)(*param_1 + 8))(&stack0xffffd8e8,uVar2);
    iVar1 = iVar1 + uVar2;
  }
  return iVar1;
}
```
