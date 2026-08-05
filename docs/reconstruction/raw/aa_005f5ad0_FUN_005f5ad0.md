# Raw capture: FUN_005f5ad0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005f5ad0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005f5ad0` |
| **Canonical name** | `FUN_005f5ad0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005f5ad0(int param_1,char param_2,char param_3)

{
  float fVar1;
  void *pvVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  if (param_2 == '\0') {
    if (*(void **)(param_1 + 0x5c) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
      operator_delete(*(void **)(param_1 + 0x5c));
    }
    *(undefined4 *)(param_1 + 0x5c) = 0;
    pvVar2 = operator_new(0xd78);
    if (pvVar2 == (void *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3 = (undefined4 *)FUN_00506ee0();
    }
    *(undefined4 **)(param_1 + 0x5c) = puVar3;
    for (iVar4 = 0x35e; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    iVar4 = *(int *)(param_1 + 0x5c);
    *(undefined4 *)(iVar4 + 0x28) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x2c) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x30) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x34) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x38) = 0xffffffff;
    **(undefined4 **)(param_1 + 0x5c) = 0x201d;
    iVar4 = *(int *)(param_1 + 0x5c);
    *(undefined4 *)(iVar4 + 0x5d8) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x5dc) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x5e0) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x5e4) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x5e8) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x180) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x184) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x188) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x18c) = 0xffffffff;
    *(undefined4 *)(iVar4 + 400) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x330) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x334) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x338) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x33c) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x340) = 0xffffffff;
    *(undefined4 *)(iVar4 + 600) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x25c) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x260) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x264) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x268) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x730) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x734) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x738) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x73c) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x740) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x708) = 0x201c;
    *(undefined4 *)(iVar4 + 0x70c) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x480) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x484) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x488) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x48c) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x490) = 0xffffffff;
    puVar3 = (undefined4 *)(iVar4 + 0x890);
    iVar5 = 3;
    do {
      puVar3[10] = 0xffffffff;
      puVar3[0xb] = 0xffffffff;
      puVar3[0xc] = 0xffffffff;
      puVar3[0xd] = 0xffffffff;
      puVar3[0xe] = 0xffffffff;
      *puVar3 = 0x201c;
      puVar3[1] = 0xffffffff;
      fVar1 = g_flOne;
      puVar3 = puVar3 + 0x62;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    *(undefined1 *)(iVar4 + 0xa2) = 0;
    *(undefined4 *)(iVar4 + 0x30c) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x15c) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x158) = 0x2012;
    *(undefined4 *)(iVar4 + 0x234) = 0xffffffff;
    *(float *)(iVar4 + 0x4d8) = fVar1;
    *(undefined1 *)(iVar4 + 0x4f8) = 1;
    *(undefined4 *)(iVar4 + 0x458) = 0x201b;
    *(undefined4 *)(iVar4 + 0x5b0) = 0x2060;
    *(undefined4 *)(iVar4 + 0x5b4) = 0xffffffff;
    *(undefined4 *)(iVar4 + 8) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0xc) = 0xffffffff;
    *(float *)(iVar4 + 0x80) = fVar1;
    *(undefined4 *)(iVar4 + 0xd0) = 0xffffffff;
    return;
  }
  if (*(void **)(param_1 + 0x60) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(*(void **)(param_1 + 0x60));
  }
  *(undefined4 *)(param_1 + 0x60) = 0;
  if (param_3 != '\0') {
    puVar3 = operator_new(0x930);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3[0x1b] = 0;
      puVar3[0x1a] = 0;
      puVar3[0x19] = 0;
      puVar3[0x1e] = 0;
      puVar3[0x1d] = 0;
      puVar3[0x1c] = 0;
      puVar3[0x1f] = g_flMsToSeconds_Inferred;
    }
    fVar1 = g_flOne;
    *(undefined4 **)(param_1 + 0x60) = puVar3;
    for (iVar4 = 0x24c; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    **(undefined4 **)(param_1 + 0x60) = 0x2013;
    iVar4 = *(int *)(param_1 + 0x60);
    *(undefined4 *)(iVar4 + 8) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0xc) = 0xffffffff;
    *(float *)(*(int *)(param_1 + 0x60) + 0x80) = fVar1;
    *(undefined4 *)(*(int *)(param_1 + 0x60) + 0xd0) = 0xffffffff;
    iVar4 = *(int *)(param_1 + 0x60);
    *(undefined1 *)(iVar4 + 0x10c) = 0;
    *(undefined4 *)(iVar4 + 0x100) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x104) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x118) = 0xffffffff;
    return;
  }
  puVar3 = operator_new(0x1a8);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3[0x1b] = 0;
    puVar3[0x1a] = 0;
    puVar3[0x19] = 0;
    puVar3[0x1e] = 0;
    puVar3[0x1d] = 0;
    puVar3[0x1c] = 0;
    puVar3[0x1f] = g_flMsToSeconds_Inferred;
  }
  fVar1 = g_flOne;
  *(undefined4 **)(param_1 + 0x60) = puVar3;
  for (iVar4 = 0x6a; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  **(undefined4 **)(param_1 + 0x60) = 0x2015;
  iVar4 = *(int *)(param_1 + 0x60);
  *(undefined4 *)(iVar4 + 8) = 0xffffffff;
  *(undefined4 *)(iVar4 + 0xc) = 0xffffffff;
  *(float *)(*(int *)(param_1 + 0x60) + 0x80) = fVar1;
  *(undefined4 *)(*(int *)(param_1 + 0x60) + 0xd0) = 0xffffffff;
  iVar4 = *(int *)(param_1 + 0x60);
  *(byte *)(iVar4 + 0x129) = *(byte *)(iVar4 + 0x129) | 1;
  *(undefined4 *)(iVar4 + 0xe0) = 0xffffffff;
  *(undefined4 *)(iVar4 + 0xe4) = 0xffffffff;
  return;
}
```
