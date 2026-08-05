# Raw capture: FUN_004eaf30

| Field | Value |
|---|---|
| **Stable ID** | `aa_004eaf30` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004eaf30` |
| **Canonical name** | `FUN_004eaf30` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004eaf30(undefined4 *param_1)

{
  void *pvVar1;
  undefined4 *puVar2;
  float fVar3;
  
  pvVar1 = (void *)*param_1;
  if (pvVar1 != (void *)0x0) {
    FUN_004b55e0();
                    /* WARNING: Subroutine does not return */
    operator_delete(pvVar1);
  }
  *param_1 = 0;
  if ((void *)param_1[1] != (void *)0x0) {
    operator_delete__((void *)param_1[1]);
  }
  puVar2 = (undefined4 *)param_1[2];
  param_1[1] = 0;
  if (puVar2 != (undefined4 *)0x0) {
    *(short *)((int)puVar2 + 6) = *(short *)((int)puVar2 + 6) + -1;
    if (*(short *)((int)puVar2 + 6) == 0) {
      (**(code **)*puVar2)(1);
    }
    param_1[2] = 0;
  }
  fVar3 = g_flOne;
  param_1[5] = 0;
  param_1[3] = 0;
  param_1[0xb] = 0;
  param_1[10] = 0;
  param_1[9] = 0;
  param_1[8] = 0;
  param_1[0xf] = 0;
  param_1[0xe] = 0;
  param_1[0xd] = 0;
  param_1[0xc] = 0;
  param_1[0x13] = 0;
  param_1[0x12] = 0;
  param_1[0x11] = 0;
  param_1[0x10] = 0;
  param_1[8] = fVar3;
  param_1[0xd] = fVar3;
  param_1[0x12] = fVar3;
  param_1[0x17] = 0;
  param_1[0x16] = 0;
  param_1[0x15] = 0;
  param_1[0x14] = 0;
  if ((void *)param_1[0x18] != (void *)0x0) {
    operator_delete__((void *)param_1[0x18]);
  }
  param_1[0x18] = 0;
  return;
}
```
