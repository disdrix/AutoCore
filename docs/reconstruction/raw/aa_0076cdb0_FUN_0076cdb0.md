# Raw capture: FUN_0076cdb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076cdb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0076cdb0` |
| **Canonical name** | `FUN_0076cdb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined1 * __thiscall FUN_0076cdb0(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined1 *puVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009acdab;
  local_c = ExceptionList;
  piVar3 = *(int **)(param_1 + 0x40);
  while( true ) {
    if (piVar3 == *(int **)(param_1 + 0x44)) {
      ExceptionList = &local_c;
      puVar4 = operator_new(0x80);
      if (puVar4 == (undefined1 *)0x0) {
        puVar4 = (undefined1 *)0x0;
      }
      else {
        *puVar4 = 0;
        *(int *)(puVar4 + 4) = param_2;
        FUN_0076c500(1000000);
        *(int *)(puVar4 + 0x38) = param_1;
        *(undefined4 *)(puVar4 + 0x40) = 0;
        *(undefined4 *)(puVar4 + 0x44) = 0;
        *(undefined4 *)(puVar4 + 0x48) = 0;
        *(undefined4 *)(puVar4 + 0x4c) = 0;
        *(undefined4 *)(puVar4 + 0x50) = 0;
        *(undefined4 *)(puVar4 + 0x54) = 0;
        *(undefined4 *)(puVar4 + 0x58) = 0;
        *(undefined4 *)(puVar4 + 0x5c) = 0;
        *(undefined4 *)(puVar4 + 0x60) = 0;
        *(undefined4 *)(puVar4 + 100) = 0;
        *(undefined4 *)(puVar4 + 0x68) = 0;
        *(undefined4 *)(puVar4 + 0x6c) = 0;
        *(undefined4 *)(puVar4 + 0x70) = 0;
        *(undefined4 *)(puVar4 + 0x74) = 0;
        *(undefined4 *)(puVar4 + 0x78) = 0;
      }
      local_4 = 0xffffffff;
      iVar1 = *(int *)(param_1 + 0x40);
      if ((iVar1 == 0) ||
         ((uint)(*(int *)(param_1 + 0x48) - iVar1 >> 2) <=
          (uint)(*(int *)(param_1 + 0x44) - iVar1 >> 2))) {
        FUN_00456960(*(undefined4 *)(param_1 + 0x44));
      }
      else {
        puVar2 = *(undefined4 **)(param_1 + 0x44);
        *puVar2 = puVar4;
        *(undefined4 **)(param_1 + 0x44) = puVar2 + 1;
      }
      ExceptionList = local_c;
      return puVar4;
    }
    if (*(int *)(*piVar3 + 4) == param_2) break;
    piVar3 = piVar3 + 1;
  }
  return (undefined1 *)*piVar3;
}
```
