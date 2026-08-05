# Raw capture: FUN_006eb5e0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006eb5e0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006eb5e0` |
| **Canonical name** | `FUN_006eb5e0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall
FUN_006eb5e0(int param_1,undefined4 param_2,int *param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  undefined1 local_110 [268];
  
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = "LtBvTree";
    uVar3 = rdtsc();
    DAT_00bc5644[1] = (int)uVar3;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  FUN_006ea6f0(param_2,param_3,param_4,&LAB_006ea160);
  puVar4 = *(undefined4 **)(param_1 + 0xc);
  puVar1 = puVar4 + *(int *)(param_1 + 0x10) * 3;
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = "StNarrowPhase";
    uVar3 = rdtsc();
    DAT_00bc5644[1] = (int)uVar3;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  piVar2 = *(int **)(*param_3 + 0xc);
  for (; puVar4 != puVar1; puVar4 = puVar4 + 3) {
    (**(code **)(*piVar2 + 0x34))(*puVar4,local_110);
    (**(code **)(*(int *)puVar4[2] + 0x10))(param_2,&stack0xfffffed8,param_4,param_5);
  }
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = &DAT_009d282c;
    uVar3 = rdtsc();
    DAT_00bc5644[1] = (int)uVar3;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  return;
}
```
