# Raw capture: Vehicle_BuildAerodynamicsDescriptor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fc4f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fc4f0` |
| **Canonical name** | `Vehicle_BuildAerodynamicsDescriptor` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int Vehicle_BuildAerodynamicsDescriptor(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_14;
  
  *param_3 = *(undefined4 *)
              (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) +
              0x5a8);
  param_3[1] = *(undefined4 *)
                (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) +
                0x59c);
  param_3[2] = *(undefined4 *)
                (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) +
                0x5a0);
  param_3[3] = *(undefined4 *)
                (*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) +
                0x5a4);
  iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c);
  uVar1 = *(undefined4 *)(iVar3 + 0x5b0);
  uVar2 = *(undefined4 *)(iVar3 + 0x5b4);
  param_3[4] = *(undefined4 *)(iVar3 + 0x5ac);
  param_3[5] = uVar1;
  param_3[6] = uVar2;
  param_3[7] = local_14;
  return iVar3 + 0x5ac;
}
```
