# Raw capture: FUN_004bfe10

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bfe10` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bfe10` |
| **Canonical name** | `FUN_004bfe10` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004bfe10(int param_1,float param_2)

{
  undefined4 *puVar1;
  char cVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  float local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a192d;
  pvStack_c = ExceptionList;
  local_10 = DAT_00d1f040;
  ExceptionList = &pvStack_c;
  FUN_0076cf00("CLoadQueue::update");
  uVar3 = 0;
  local_4 = 0;
  local_14 = param_2;
  piVar6 = (int *)(param_1 + 8);
  do {
    if ((piVar6[1] != 0) && (piVar4 = *(int **)*piVar6, piVar4 != (int *)*piVar6)) {
      do {
        puVar1 = (undefined4 *)piVar4[2];
        cVar2 = FUN_005c7df0(&local_14,0);
        piVar5 = piVar4;
        if (cVar2 == '\0') {
LAB_004bfeb7:
          if (local_14 <= g_flZero) goto LAB_004bfed7;
          piVar5 = (int *)*piVar5;
        }
        else {
          if (puVar1 != (undefined4 *)0x0) {
            (**(code **)*puVar1)(1);
          }
          piVar5 = (int *)*piVar4;
          if (piVar4 != (int *)*piVar6) {
            *(int **)piVar4[1] = piVar5;
            *(int *)(*piVar4 + 4) = piVar4[1];
                    /* WARNING: Subroutine does not return */
            operator_delete(piVar4);
          }
          if (local_14 <= g_flZero) goto LAB_004bfeb7;
        }
        piVar4 = piVar5;
      } while (piVar5 != (int *)*piVar6);
    }
    uVar3 = uVar3 + 1;
    piVar6 = piVar6 + 3;
  } while (uVar3 < 9);
LAB_004bfed7:
  local_4 = 0xffffffff;
  FUN_0076cef0();
  ExceptionList = pvStack_c;
  return;
}
```
