# Raw capture: FUN_008db6d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008db6d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008db6d0` |
| **Canonical name** | `FUN_008db6d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_008db6d0(void)

{
  int iVar1;
  float *pfVar2;
  int *piVar3;
  int unaff_ESI;
  undefined1 *puVar4;
  float fVar5;
  float fStack_40;
  int iStack_3c;
  undefined1 local_28 [4];
  undefined1 auStack_24 [12];
  undefined1 local_18 [4];
  undefined1 auStack_14 [4];
  undefined1 auStack_10 [16];
  
  if (*(char *)(unaff_ESI + 0x518) == '\0') {
    if (*(int *)(unaff_ESI + 0x52c) == 6) {
      if (*(int *)(unaff_ESI + 0x584) != 0) {
        (**(code **)(**(int **)(unaff_ESI + 0x584) + 4))(1);
      }
      if ((*(int *)(unaff_ESI + 0x580) != 0) && (*(int *)(unaff_ESI + 0x584) != 0)) {
        iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x580) + 0x134))(local_18);
        fStack_40 = (float)DAT_00d1e81c * *(float *)(iVar1 + 4) * DAT_00aaa678;
        pfVar2 = (float *)(**(code **)(**(int **)(unaff_ESI + 0x580) + 0x134))(auStack_14);
        fVar5 = 1.4013e-45;
        puVar4 = auStack_10;
        piVar3 = (int *)(**(code **)(**(int **)(unaff_ESI + 0x584) + 0x140))
                                  (puVar4,1,(float)DAT_00d1e818 * *pfVar2 * DAT_00aaa67c);
        fStack_40 = (float)((int)(float)puVar4 - *piVar3);
        iStack_3c = (int)fVar5;
        (**(code **)(**(int **)(unaff_ESI + 0x580) + 300))(&fStack_40);
      }
    }
    else {
      if (*(int *)(unaff_ESI + 0x584) != 0) {
        (**(code **)(**(int **)(unaff_ESI + 0x584) + 4))(0);
      }
      if (*(int *)(unaff_ESI + 0x580) != 0) {
        iVar1 = (**(code **)(**(int **)(unaff_ESI + 0x580) + 0x134))(local_28);
        puVar4 = auStack_24;
        pfVar2 = (float *)(**(code **)(**(int **)(unaff_ESI + 0x580) + 0x134))
                                    (puVar4,(float)DAT_00d1e81c * *(float *)(iVar1 + 4) *
                                            DAT_00aaa678);
        iStack_3c = (int)(float)puVar4;
        fStack_40 = (float)(int)((float)DAT_00d1e818 * *pfVar2 * DAT_00aaa67c);
        (**(code **)(**(int **)(unaff_ESI + 0x580) + 300))(&fStack_40);
        return;
      }
    }
  }
  else if (*(int *)(unaff_ESI + 0x584) != 0) {
    (**(code **)(**(int **)(unaff_ESI + 0x584) + 4))(0);
    return;
  }
  return;
}
```
