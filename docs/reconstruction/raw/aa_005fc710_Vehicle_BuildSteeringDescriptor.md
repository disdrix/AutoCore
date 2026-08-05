# Raw capture: Vehicle_BuildSteeringDescriptor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fc710` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fc710` |
| **Canonical name** | `Vehicle_BuildSteeringDescriptor` |
| **System** | input-drive-control |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void Vehicle_BuildSteeringDescriptor(int param_1,undefined4 param_2,undefined1 *param_3)

{
  int *piVar1;
  char cVar2;
  undefined1 uVar3;
  char cVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  
  cVar2 = FUN_004f5560();
  iVar7 = (int)cVar2;
  piVar1 = (int *)(param_3 + 0xc);
  if ((int)(*(uint *)(param_3 + 0x14) & 0x7fffffff) < iVar7) {
    iVar5 = (*(uint *)(param_3 + 0x14) & 0x7fffffff) * 2;
    if (iVar5 <= iVar7) {
      iVar5 = iVar7;
    }
    FUN_005b3300(piVar1,iVar5,1);
  }
  *(int *)(param_3 + 0x10) = iVar7;
  uVar3 = FUN_004f5560();
  *param_3 = uVar3;
  *(float *)(param_3 + 4) =
       *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) +
                 0x594) * *(float *)(param_1 + 0x208);
  *(float *)(param_3 + 8) =
       *(float *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c) +
                 0x598) * *(float *)(param_1 + 0x20c);
  cVar2 = *(char *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 600) + 4) + 4) + 0xac +
                                     *(int *)(param_1 + 600)) + 0x3c) + 0x4cc);
  cVar6 = '\0';
  cVar4 = FUN_004f5560();
  if ('\0' < cVar4) {
    do {
      if (cVar6 < cVar2) {
        *(byte *)((int)cVar6 + *piVar1) =
             *(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) +
                               0x3c) + 0x5f0) >> 2 & 1;
      }
      else {
        *(byte *)((int)cVar6 + *piVar1) =
             *(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) +
                               0x3c) + 0x5f0) >> 3 & 1;
      }
      cVar6 = cVar6 + '\x01';
      cVar4 = FUN_004f5560();
    } while (cVar6 < cVar4);
  }
  return;
}
```
