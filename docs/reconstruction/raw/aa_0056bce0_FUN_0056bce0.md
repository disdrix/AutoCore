# Raw capture: FUN_0056bce0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056bce0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0056bce0` |
| **Canonical name** | `FUN_0056bce0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0056bce0(int param_1,char param_2)

{
  void *pvVar1;
  int iVar2;
  undefined4 auStack_c [3];
  
  iVar2 = *(int *)(*(int *)(param_1 + -0x14c) + 4);
  if (param_2 == '\0') {
    (**(code **)(*(int *)(iVar2 + -0x14c + param_1) + 0xfc))();
    pvVar1 = *(void **)(param_1 + -0x94);
    if (pvVar1 != (void *)0x0) {
      FUN_004b99c0();
                    /* WARNING: Subroutine does not return */
      operator_delete(pvVar1);
    }
    *(undefined4 *)(param_1 + -0x94) = 0;
    *(undefined1 *)(param_1 + -0x9e) = 0;
    FUN_0056edf0();
  }
  else {
    iVar2 = *(int *)(iVar2 + -0xa8 + param_1);
    if ((iVar2 != 0) && (*(char *)(iVar2 + 0xf5) == '\0')) {
      FUN_0056a770();
      (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x14c) + 4) + -0x14c + param_1) + 0x100))()
      ;
      iVar2 = *(int *)(*(int *)(*(int *)(param_1 + -0x14c) + 4) + param_1 + -0xa4);
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(iVar2 + 0x3c);
      }
      if ((*(byte *)(iVar2 + 0x536) & 0x80) != 0) {
        iVar2 = FUN_004ec010(4);
        if (iVar2 != 0) {
          auStack_c[0] = 0;
          FUN_004b7550(auStack_c,1);
          auStack_c[0] = *(undefined4 *)(param_1 + -0x68);
          FUN_004b7550(auStack_c,2);
          auStack_c[0] = *(undefined4 *)(param_1 + -0x74);
          FUN_004b7550(auStack_c,3);
          auStack_c[0] = *(undefined4 *)(param_1 + -0x70);
          FUN_004b7550(auStack_c,4);
          FUN_004b8dc0(0,0);
          (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x14c) + 4) + -0x14c + param_1) + 0xf8)
          )(iVar2,1,0);
          return;
        }
      }
    }
  }
  return;
}
```
