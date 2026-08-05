# Raw capture: FUN_004eb4a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004eb4a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004eb4a0` |
| **Canonical name** | `FUN_004eb4a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_004eb4a0(int *param_1,float param_2,float param_3,float param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    if (param_1[0x18] != 0) {
      FUN_004b5cb0(param_1[0x18],param_5,param_2);
      return;
    }
    if ((*(int *)(iVar1 + 0x54) - *(int *)(iVar1 + 0x50) & 0xfffffffcU) != 0) {
      iVar1 = **(int **)(iVar1 + 0x50);
      iVar2 = *(int *)(iVar1 + 4);
      if (iVar2 == 1) {
        *(float *)(iVar1 + 0x68) = param_2 * param_3;
        return;
      }
      if (iVar2 == 3) {
        *(float *)(iVar1 + 0x6c) = param_2 * param_4;
        *(float *)(iVar1 + 0x68) = param_2 * param_3;
        *(undefined4 *)(iVar1 + 0x30) = 0;
        return;
      }
      if (iVar2 == 2) {
        *(float *)(iVar1 + 0x6c) = param_2;
        *(float *)(iVar1 + 0x68) = param_2 * param_3;
        *(float *)(iVar1 + 0x70) = param_2 * param_4;
        return;
      }
      FUN_007a4480(0xffffffff,"Unsupported shape");
    }
  }
  return;
}
```
