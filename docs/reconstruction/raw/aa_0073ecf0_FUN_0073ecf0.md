# Raw capture: FUN_0073ecf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0073ecf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0073ecf0` |
| **Canonical name** | `FUN_0073ecf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __thiscall FUN_0073ecf0(int param_1,undefined4 param_2,int param_3)

{
  void *pvVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int unaff_EDI;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009ac0a2;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0073ebf0();
  pvVar1 = operator_new__(unaff_EDI * 4);
  *(void **)(param_1 + 0xc) = pvVar1;
  pvVar1 = operator_new__(unaff_EDI * 4);
  *(void **)(param_1 + 0x10) = pvVar1;
  piVar2 = operator_new__(unaff_EDI * 0x10 + 4);
  local_4 = 0;
  if (piVar2 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = piVar2 + 1;
    *piVar2 = unaff_EDI;
    _eh_vector_constructor_iterator_
              (piVar3,0x10,unaff_EDI,(_func_void_void_ptr *)&LAB_00456430,FUN_00449d40);
  }
  iVar4 = 0;
  if (0 < unaff_EDI) {
    piVar5 = (int *)(param_3 + 0xc);
    piVar2 = piVar3 + 2;
    do {
      piVar2[-1] = *(int *)(param_1 + 0xc) + iVar4 * 4;
      *piVar2 = *(int *)(param_1 + 0x10) + iVar4 * 4;
      if (param_3 != 0) {
        piVar2[1] = *piVar5;
      }
      iVar4 = iVar4 + 1;
      piVar5 = piVar5 + 4;
      piVar2 = piVar2 + 4;
    } while (iVar4 < unaff_EDI);
  }
  *(int **)(param_1 + 8) = piVar3;
  *(int *)(param_1 + 0x14) = unaff_EDI;
  *(undefined4 *)(param_1 + 0x18) = param_2;
  ExceptionList = local_c;
  return 0;
}
```
