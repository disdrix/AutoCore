# Raw capture: FUN_0079cec0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0079cec0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0079cec0` |
| **Canonical name** | `FUN_0079cec0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int FUN_0079cec0(char *param_1)

{
  char *pcVar1;
  int iVar2;
  char unaff_BP;
  int *unaff_ESI;
  int iVar3;
  int unaff_retaddr;
  
  pcVar1 = param_1;
  param_1 = (char *)((uint)param_1 & 0xffffff00);
  (**(code **)(*unaff_ESI + 4))(&param_1,1);
  iVar3 = 0;
  if ((((unaff_BP != '\0') && (iVar3 = 0, unaff_BP != '\r')) && (unaff_BP != '\n')) &&
     (0 < unaff_retaddr + -2)) {
    *pcVar1 = unaff_BP;
    iVar3 = 1;
    (**(code **)(*unaff_ESI + 4))(&stack0xfffffffc,1);
    unaff_BP = '\0';
  }
  pcVar1[iVar3] = '\0';
  if (unaff_BP == '\r') {
    iVar2 = (**(code **)(*unaff_ESI + 0x1c))();
    (**(code **)(*unaff_ESI + 0x24))(iVar2 + 1);
  }
  return iVar3;
}
```
