# Raw capture: FUN_0048cea0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048cea0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0048cea0` |
| **Canonical name** | `FUN_0048cea0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
byte * FUN_0048cea0(byte *param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  
  if ((param_1 == (byte *)0x0) || (bVar2 = *param_1, bVar2 == 0)) {
    return (byte *)0x0;
  }
  if (param_2 == 1) {
    do {
      if (bVar2 == 0xef) {
        if ((param_1[1] == 0xbb) && (param_1[2] == 0xbf)) {
          param_1 = param_1 + 3;
        }
        else {
          if (param_1[1] != 0xbf) goto LAB_0048cef5;
          if (param_1[2] == 0xbe) {
            param_1 = param_1 + 3;
          }
          else {
            if (param_1[2] != 0xbf) goto LAB_0048cef5;
            param_1 = param_1 + 3;
          }
        }
      }
      else {
LAB_0048cef5:
        iVar1 = isspace((uint)bVar2);
        if ((((iVar1 == 0) && (bVar2 != 10)) && (bVar2 != 0xd)) &&
           ((*param_1 != 10 && (*param_1 != 0xd)))) {
          return param_1;
        }
        param_1 = param_1 + 1;
      }
      bVar2 = *param_1;
    } while (bVar2 != 0);
  }
  else {
    for (; ((bVar2 = *param_1, bVar2 != 0 &&
            (((iVar1 = isspace((uint)bVar2), iVar1 != 0 || (bVar2 == 10)) || (bVar2 == 0xd)))) ||
           ((*param_1 == 10 || (*param_1 == 0xd)))); param_1 = param_1 + 1) {
    }
  }
  return param_1;
}
```
