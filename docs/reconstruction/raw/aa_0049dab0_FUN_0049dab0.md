# Raw capture: FUN_0049dab0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0049dab0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0049dab0` |
| **Canonical name** | `FUN_0049dab0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
bool FUN_0049dab0(wchar_t *param_1,int param_2,int *param_3)

{
  wchar_t *pwVar1;
  undefined4 uVar2;
  
  *param_3 = 0;
  pwVar1 = wcstok(param_1,L", ");
  while ((pwVar1 != (wchar_t *)0x0 && (*param_3 < 8))) {
    uVar2 = FUN_0049cb20(pwVar1);
    *(undefined4 *)(param_2 + *param_3 * 4) = uVar2;
    pwVar1 = wcstok((wchar_t *)0x0,L", ");
    *param_3 = *param_3 + 1;
  }
  return 0 < *param_3;
}
```
