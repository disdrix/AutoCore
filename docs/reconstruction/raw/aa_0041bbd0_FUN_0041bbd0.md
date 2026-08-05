# Raw capture: FUN_0041bbd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041bbd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0041bbd0` |
| **Canonical name** | `FUN_0041bbd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0041bbd0(int *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int unaff_EBX;
  undefined4 *unaff_ESI;
  int *unaff_EDI;
  undefined1 local_8 [8];
  
  piVar1 = *(int **)(unaff_EBX + 4);
  if (*(int *)(unaff_EBX + 8) == 0) {
    FUN_0040f100(unaff_ESI,1,piVar1,unaff_EDI);
    return;
  }
  if (param_1 == (int *)*piVar1) {
    if (*unaff_EDI < param_1[3]) {
      FUN_0040f100(unaff_ESI,1,param_1,unaff_EDI);
      return;
    }
  }
  else if (param_1 == piVar1) {
    if (*(int *)(piVar1[2] + 0xc) < *unaff_EDI) {
      FUN_0040f100(unaff_ESI,0,piVar1[2],unaff_EDI);
      return;
    }
  }
  else {
    if (*unaff_EDI < param_1[3]) {
      FUN_005a2850();
      if (param_1[3] < *unaff_EDI) {
        if (*(char *)(param_1[2] + 0x15) != '\0') {
          FUN_0040f100(unaff_ESI,0,param_1,unaff_EDI);
          return;
        }
        FUN_0040f100(unaff_ESI,1,param_1,unaff_EDI);
        return;
      }
    }
    if (param_1[3] < *unaff_EDI) {
      FUN_00673070();
      if ((param_1 == *(int **)(unaff_EBX + 4)) || (*unaff_EDI < param_1[3])) {
        if (*(char *)(param_1[2] + 0x15) != '\0') {
          FUN_0040f100(unaff_ESI,0,param_1,unaff_EDI);
          return;
        }
        FUN_0040f100(unaff_ESI,1,param_1,unaff_EDI);
        return;
      }
    }
  }
  puVar2 = (undefined4 *)FUN_0040ed60(local_8,unaff_EDI);
  *unaff_ESI = *puVar2;
  return;
}
```
