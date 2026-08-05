# Raw capture: FUN_004ddcc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ddcc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004ddcc0` |
| **Canonical name** | `FUN_004ddcc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WARNING: Removing unreachable block (ram,0x004ddfdd) */

int * __fastcall FUN_004ddcc0(int param_1)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int *piStack_6f4;
  undefined4 uStack_6f0;
  undefined1 *puStack_6ec;
  undefined4 uStack_6e8;
  undefined4 *puStack_6e4;
  int iStack_6bc;
  undefined1 auStack_6a8 [244];
  undefined1 auStack_5b4 [4];
  undefined1 auStack_5b0 [4];
  int aiStack_5ac [2];
  undefined4 uStack_5a4;
  undefined1 auStack_5a0 [1420];
  undefined4 uStack_14;
  undefined1 *puStack_10;
  undefined4 *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009a2438;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_007b6a20();
  piVar1 = (int *)FUN_007b72b0();
  if (piVar1 != (int *)0x0) {
    *(undefined1 *)(param_1 + 0x81) = 1;
    iVar2 = FUN_004a94e0();
    *(int *)(param_1 + 0x8c) = iVar2;
    if (iVar2 != -1) {
      *(undefined4 *)(param_1 + 0x104) = *(undefined4 *)(*(int *)(param_1 + 0xe4f8) + 4);
      (**(code **)(*piVar1 + 0x14))();
      (**(code **)(*piVar1 + 0x14))();
      puStack_6e4 = local_c;
      uStack_6e8 = 0x4ddd75;
      (**(code **)(*piVar1 + 0x14))();
      uStack_6e8 = 4;
      puStack_6ec = puStack_10;
      uStack_6f0 = 0x4ddd87;
      (**(code **)(*piVar1 + 0x14))();
      uStack_6f0 = uStack_14;
      piStack_6f4 = piVar1;
      FUN_00513880();
      uStack_6f0 = 8;
      piStack_6f4 = (int *)(param_1 + 0xe7e0);
      (**(code **)(*piVar1 + 0x14))();
      (**(code **)(*piVar1 + 0x14))(param_1 + 0xe7e8,8);
      if (0x20 < *(int *)(param_1 + 0x8c)) {
        (**(code **)(*piVar1 + 0x14))(param_1 + 0xe7d8,8);
      }
      if (0x21 < *(int *)(param_1 + 0x8c)) {
        (**(code **)(*piVar1 + 0x14))(param_1 + 0xe7f0,8);
      }
      FUN_004dbc20(piVar1);
      FUN_004dbda0(piVar1,*(undefined4 *)(param_1 + 0x8c));
      FUN_005b06d0(piVar1,*(undefined4 *)(param_1 + 0x8c));
      (**(code **)(**(int **)(param_1 + 0xe520) + 4))();
      if ((0x24 < *(int *)(param_1 + 0x8c)) && (*(int *)(param_1 + 0x8c) < 0x2f)) {
        (**(code **)(*piVar1 + 0x14))();
        iVar2 = 0;
        if (0 < unaff_EBP) {
          do {
            uStack_5a4 = 0;
            auStack_5a0[0] = 0;
            auStack_6a8[0] = 0;
            (**(code **)(*piVar1 + 0x14))();
            puStack_6e4 = &uStack_5a4;
            uStack_6e8 = 0x4dde98;
            (**(code **)(*piVar1 + 0x14))();
            uStack_6e8 = 4;
            puStack_6ec = auStack_5a0;
            uStack_6f0 = 0x4ddeaa;
            (**(code **)(*piVar1 + 0x14))();
            uStack_6f0 = 4;
            piStack_6f4 = aiStack_5ac;
            (**(code **)(*piVar1 + 0x14))();
            (**(code **)(*piVar1 + 0x14))(aiStack_5ac,1);
            (**(code **)(*piVar1 + 0x14))(auStack_5b0,4);
            (**(code **)(*piVar1 + 0x14))(auStack_5b4,4);
            (**(code **)(*piVar1 + 0x14))(&piStack_6f4,4);
            if (iStack_6bc != 0) {
              (**(code **)(*piVar1 + 0x14))();
              auStack_6a8[iStack_6bc] = 0;
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 < unaff_EBP);
        }
        (**(code **)(*piVar1 + 0x14))();
        iVar2 = 0;
        if (0 < iStack_6bc) {
          do {
            (**(code **)(*piVar1 + 0x14))();
            iVar2 = iVar2 + 1;
          } while (iVar2 < iStack_6bc);
        }
      }
      if ((0x25 < *(int *)(param_1 + 0x8c)) && (*(int *)(param_1 + 0x8c) < 0x2f)) {
        (**(code **)(*piVar1 + 0x14))();
        if (iStack_6bc != 0) {
          pvVar3 = operator_new__(iStack_6bc + 1);
          (**(code **)(*piVar1 + 0x14))();
          *(undefined1 *)((int)pvVar3 + unaff_EBP) = 0;
          FUN_00553ff0();
                    /* WARNING: Subroutine does not return */
          operator_delete(pvVar3);
        }
        iVar2 = 4;
        do {
          (**(code **)(*piVar1 + 0x14))();
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      if (*(int *)(param_1 + 0x8c) < 0x2f) {
        if (*(int *)(param_1 + 0x8c) < 0x26) {
          ExceptionList = local_c;
          return piVar1;
        }
        FUN_004cd9a0();
        ExceptionList = local_c;
        return piVar1;
      }
      (**(code **)(*piVar1 + 0x14))();
      pvVar3 = operator_new__(unaff_EBX + 1);
      (**(code **)(*piVar1 + 0x14))();
      *(undefined1 *)((int)pvVar3 + unaff_ESI) = 0;
      puStack_6e4 = (undefined4 *)0x4de05e;
      FUN_00553ff0();
                    /* WARNING: Subroutine does not return */
      puStack_6e4 = (undefined4 *)&UNK_004de064;
      operator_delete(pvVar3);
    }
    FUN_007a4480();
  }
  ExceptionList = local_c;
  return (int *)0x0;
}
```
