# Raw capture: FUN_005df1a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005df1a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005df1a0` |
| **Canonical name** | `FUN_005df1a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int FUN_005df1a0(LPCSTR param_1,int param_2)

{
  uint uVar1;
  LPCSTR lpOutputString;
  LPCSTR pCVar2;
  int iVar3;
  
  if (param_2 == 0) {
    return 0;
  }
  if (param_1[param_2 + -1] == '\0') {
    OutputDebugStringA(param_1);
    printf("%s",param_1);
    return param_2;
  }
  uVar1 = param_2 + 1;
  lpOutputString = (LPCSTR)(**(code **)(*DAT_00b05060 + 0x10))(uVar1,0x12);
  if (0 < param_2) {
    pCVar2 = lpOutputString;
    iVar3 = param_2;
    do {
      *pCVar2 = pCVar2[(int)param_1 - (int)lpOutputString];
      pCVar2 = pCVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  lpOutputString[param_2] = '\0';
  OutputDebugStringA(lpOutputString);
  printf("%s",lpOutputString);
  if (-1 < (int)uVar1) {
    (**(code **)(*DAT_00b05060 + 0x14))(lpOutputString,uVar1 & 0x7fffffff,0x12);
  }
  return param_2;
}
```
