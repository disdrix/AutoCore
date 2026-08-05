# Raw capture: FUN_004dbda0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004dbda0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004dbda0` |
| **Canonical name** | `FUN_004dbda0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004dbda0(int param_1,int *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int local_6a8;
  undefined **local_6a4;
  undefined1 local_69f;
  undefined1 local_69e;
  int *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a2336;
  local_c = ExceptionList;
  iVar3 = 0;
  ExceptionList = &local_c;
  if (*(int *)(*(int *)(param_1 + 0xe5c4) + 0xc) != 0) {
    ExceptionList = &local_c;
    FUN_004e49f0(5);
  }
  local_6a8 = 0;
  if (param_2 != (int *)0x0) {
    FUN_0079ce60();
    local_6a4 = &PTR_FUN_009cc008;
    local_10 = param_2;
    local_69f = 1;
    local_69e = 0;
    local_4 = 0;
    (*(code *)PTR_FUN_009cc00c)(&local_6a8,4);
    if (0 < local_6a8) {
      do {
        piVar1 = operator_new(0x40);
        if (piVar1 == (int *)0x0) {
          piVar1 = (int *)0x0;
        }
        else {
          piVar1[6] = 0;
          piVar1[5] = 0;
          piVar1[4] = 0;
        }
        piVar1[10] = 0;
        if (param_3 < 0x19) {
          if (param_3 < 0x17) {
            if (0xc < param_3) {
              (**(code **)(*param_2 + 0x14))(piVar1,0x28);
              goto LAB_004dbe9c;
            }
            uVar4 = 0x20;
          }
          else {
            uVar4 = 0x40;
          }
          (**(code **)(*param_2 + 0x14))(piVar1,uVar4);
        }
        else {
          FUN_00522500(&local_6a4,param_3);
        }
LAB_004dbe9c:
        iVar2 = *piVar1 + 1;
        if (*piVar1 + 1 < *(int *)(param_1 + 0xe8f0)) {
          iVar2 = *(int *)(param_1 + 0xe8f0);
        }
        *(int *)(param_1 + 0xe8f0) = iVar2;
        FUN_004e7a30(*piVar1,piVar1,0);
        iVar3 = iVar3 + 1;
      } while (iVar3 < local_6a8);
    }
  }
  ExceptionList = local_c;
  return;
}
```
