# Raw capture: FUN_007fe1d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fe1d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fe1d0` |
| **Canonical name** | `FUN_007fe1d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fe1d0(char param_1)

{
  int *piVar1;
  char cVar2;
  int in_EAX;
  int iVar3;
  int unaff_ESI;
  
  if (*(char *)(DAT_00d1b6d8 + 0x4f1) == '\0') {
    piVar1 = *(int **)(unaff_ESI + 0x1030 + in_EAX * 4);
    if (piVar1 == (int *)0x0) {
      FUN_007a4480(1,"Attempting to toggle visibility of null dialog %i.");
    }
    else {
      cVar2 = (**(code **)(*piVar1 + 0x3d8))();
      if (cVar2 != '\0') {
        if (((param_1 == '\0') &&
            ((cVar2 = (**(code **)(*piVar1 + 0xd0))(), cVar2 != '\0' ||
             (cVar2 = (**(code **)(*piVar1 + 0xf8))(), cVar2 != '\0')))) &&
           ((cVar2 = (**(code **)(*piVar1 + 0xd0))(), cVar2 != '\x01' ||
            (iVar3 = (**(code **)(*piVar1 + 0xe8))(), iVar3 != -1)))) {
          FUN_007fc9b0();
          return;
        }
        if ((((piVar1[0x140] != 1) || (*(int *)(unaff_ESI + 0xe98) == 0)) ||
            (iVar3 = *(int *)(*(int *)(unaff_ESI + 0xe98) + 0x250), iVar3 == 0)) ||
           (cVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3) + 0x194))()
           , cVar2 == '\0')) {
          (**(code **)(*piVar1 + 0xfc))(1,0x3f000000);
          FUN_0092f000();
          return;
        }
      }
    }
  }
  return;
}
```
