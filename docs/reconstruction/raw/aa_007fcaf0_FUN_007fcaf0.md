# Raw capture: FUN_007fcaf0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007fcaf0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007fcaf0` |
| **Canonical name** | `FUN_007fcaf0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_007fcaf0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  int unaff_EDI;
  
  piVar4 = (int *)(param_1 + 0x1030);
  param_1 = 0x3a;
  do {
    piVar1 = (int *)*piVar4;
    if ((piVar1 == (int *)0x0) || (cVar3 = (**(code **)(*piVar1 + 0x3d8))(), cVar3 == '\0'))
    goto LAB_007fcb64;
    iVar2 = piVar1[0x13f];
    if (((iVar2 == unaff_EDI) || ((unaff_EDI == 0 || (iVar2 == 0x10)))) &&
       ((piVar1[0x140] == param_2 || (param_2 == 0)))) {
LAB_007fcb5d:
      FUN_007fca10();
    }
    else if (unaff_EDI == 0xf) {
      if ((iVar2 == 0xc) || (iVar2 == 0xd)) goto LAB_007fcb5d;
    }
    else if (((unaff_EDI == 0xc) || (unaff_EDI == 0xd)) && (iVar2 == 0xf)) goto LAB_007fcb5d;
LAB_007fcb64:
    piVar4 = piVar4 + 1;
    param_1 = param_1 + -1;
    if (param_1 == 0) {
      return;
    }
  } while( true );
}
```
