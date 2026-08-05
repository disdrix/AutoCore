# Raw capture: FUN_004dbef0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004dbef0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004dbef0` |
| **Canonical name** | `FUN_004dbef0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_004dbef0(int *param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  piVar1 = param_1;
  iVar5 = param_1[0x58];
  iVar2 = FUN_004e23d0(iVar5,param_1[0x59],&param_1);
  iVar3 = 0;
  if (iVar2 != 0) {
    iVar3 = *(int *)(iVar2 + 0xc);
  }
  if (iVar3 != 0) {
    FUN_004e3170(iVar5,piVar1[0x59],&param_1);
  }
  piVar4 = operator_new(0x28);
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    *piVar4 = 0;
    piVar4[1] = 0;
    piVar4[2] = 0;
    piVar4[3] = 0;
    piVar4[4] = 0;
    piVar4[5] = 0;
    piVar4[6] = 0;
    piVar4[7] = 0;
    piVar4[8] = 0;
    piVar4[9] = 0;
  }
  *piVar4 = piVar1[0x58];
  piVar4[1] = piVar1[0x59];
  piVar4[2] = piVar1[0x5a];
  piVar4[3] = piVar1[0x5b];
  piVar4[4] = 0;
  piVar4[6] = param_3;
  piVar4[7] = param_4;
  piVar4[8] = param_5;
  iVar5 = FUN_004bb1c0(0,param_3,param_4);
  piVar4[5] = iVar5;
  piVar1[0x47] = (int)piVar4;
  if (piVar1[0x29] != 0) {
    iVar5 = (**(code **)(*piVar1 + 0x1cc))();
    if (iVar5 != 0) {
      iVar5 = (**(code **)(*piVar1 + 0x1cc))();
      FUN_00493e90(*(undefined4 *)(iVar5 + 8));
    }
  }
  iVar5 = FUN_004e7d30(*piVar4,piVar4[1],piVar4,0);
  if (iVar5 != 0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(piVar4);
  }
  return;
}
```
