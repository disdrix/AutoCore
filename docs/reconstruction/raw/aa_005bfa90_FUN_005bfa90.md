# Raw capture: FUN_005bfa90

| Field | Value |
|---|---|
| **Stable ID** | `aa_005bfa90` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005bfa90` |
| **Canonical name** | `FUN_005bfa90` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_005bfa90(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  (**(code **)(*param_1 + 0x20))(*(undefined4 *)(*param_2 + 0x390));
  param_1[0x2f] = param_1[0x2f] & 0xfffffffe;
  fStack_10 = (float)param_1[0x33] * (float)param_2[0x10];
  fStack_c = (float)*(ushort *)((int)param_1 + 0xea) * (float)param_2[0x11];
  fStack_8 = (float)param_1[0x34] * (float)param_2[0x10];
  if ((*(byte *)(param_1 + 0x2f) & 1) != 0) {
    (**(code **)(*param_1 + 0x5c))();
  }
  FUN_0074b8f0(&fStack_10,&stack0xffffffe4);
  iVar1 = (**(code **)(**(int **)(*param_2 + 0x390) + 0xc))();
  param_1[0x19] = iVar1;
  iVar1 = *param_1;
  uVar2 = (**(code **)(**(int **)(*param_2 + 0x390) + 100))();
  (**(code **)(iVar1 + 0x34))(uVar2);
  return 1;
}
```
