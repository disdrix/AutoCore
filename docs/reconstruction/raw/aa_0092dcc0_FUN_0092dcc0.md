# Raw capture: FUN_0092dcc0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092dcc0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0092dcc0` |
| **Canonical name** | `FUN_0092dcc0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0092dcc0(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char unaff_BL;
  int iVar4;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar2 = param_1;
  *(char *)(param_1 + 0xa0e) = unaff_BL;
  iVar4 = 0;
  do {
    if (iVar4 == 0) {
      piVar1 = *(int **)(iVar2 + 0xc78);
      if (piVar1 != (int *)0x0) {
        iVar3 = (**(code **)(*piVar1 + 0x48))();
LAB_0092dcfa:
        if ((iVar3 != 0) && ((*(byte *)(iVar3 + 0xb4) & 0xc) == 0)) {
          FUN_0059e290(&uStack_4,&uStack_8,&param_1,&uStack_c);
          if (unaff_BL == '\x01') {
            param_1 = 10000;
            uStack_c = 10000;
          }
          else if (unaff_BL == '\x02') {
            param_1 = 5000;
            uStack_c = 5000;
          }
          else {
            param_1 = 20000;
            uStack_c = 20000;
          }
          FUN_00426120(uStack_4,uStack_8,param_1,uStack_c);
        }
      }
    }
    else {
      piVar1 = *(int **)(iVar2 + 0xc7c);
      if (piVar1 != (int *)0x0) {
        iVar3 = (**(code **)(*piVar1 + 0x48))();
        goto LAB_0092dcfa;
      }
    }
    iVar4 = iVar4 + 1;
    if (1 < iVar4) {
      return;
    }
  } while( true );
}
```
