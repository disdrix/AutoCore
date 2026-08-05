# Raw capture: FUN_0083dae0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0083dae0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0083dae0` |
| **Canonical name** | `FUN_0083dae0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0083dae0(void)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int unaff_ESI;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  char acStack_10 [16];
  
  if ((*(int **)(unaff_ESI + 0x500) == (int *)0x0) ||
     (iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x500) + 0x25c))(),
     *(int *)(unaff_ESI + 0x4fc) <= iVar2)) {
    if (*(int *)(unaff_ESI + 0x4fc) < 0) {
      *(undefined4 *)(unaff_ESI + 0x4fc) = 0;
    }
    else if (*(int *)(unaff_ESI + 0x500) != 0) {
      iVar2 = *(int *)(*(int *)(unaff_ESI + 0x500) + 0xa8);
      if (*(int *)(iVar2 + 0x38) == 4) {
        uVar4 = 999999;
      }
      else {
        uVar1 = *(ushort *)(*(int *)(iVar2 + 0x3c) + 0x4ba);
        uVar4 = (uint)uVar1;
        if (uVar1 == 0) {
          uVar4 = 200;
        }
      }
      if ((int)(uVar4 & 0xffff) < *(int *)(unaff_ESI + 0x4fc)) {
        uVar4 = FUN_0040ac40();
        *(uint *)(unaff_ESI + 0x4fc) = uVar4 & 0xffff;
      }
    }
  }
  else {
    uVar3 = (**(code **)(**(int **)(unaff_ESI + 0x500) + 0x25c))();
    *(undefined4 *)(unaff_ESI + 0x4fc) = uVar3;
  }
  sprintf(acStack_10,"%i",*(undefined4 *)(unaff_ESI + 0x4fc));
  fStack_20 = g_flOne;
  if ((*(int **)(unaff_ESI + 0x500) != (int *)0x0) &&
     (iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x500) + 0x25c))(), fStack_20 = g_flOne,
     *(int *)(unaff_ESI + 0x4fc) == iVar2)) {
    fStack_20 = 0.0;
  }
  fStack_1c = g_flOne;
  fStack_18 = fStack_20;
  fStack_14 = g_flOne;
  (**(code **)(**(int **)(unaff_ESI + 0x510) + 0x158))(1,&fStack_20);
  (**(code **)(**(int **)(unaff_ESI + 0x510) + 0x3ac))(&fStack_18);
  (**(code **)(**(int **)(unaff_ESI + 0x510) + 0x34c))();
  return;
}
```
