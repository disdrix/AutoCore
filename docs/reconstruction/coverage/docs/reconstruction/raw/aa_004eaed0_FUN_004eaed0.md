# Raw capture: FUN_004eaed0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004eaed0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004eaed0` |
| **Canonical name** | `FUN_004eaed0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004eaed0(int param_1,wchar_t *param_2)

{
  size_t sVar1;
  wchar_t *_Dest;
  
  if (*(void **)(param_1 + 0x84) != (void *)0x0) {
    operator_delete__(*(void **)(param_1 + 0x84));
  }
  *(undefined4 *)(param_1 + 0x84) = 0;
  if (param_2 != (wchar_t *)0x0) {
    sVar1 = wcslen(param_2);
    _Dest = operator_new__(sVar1 * 2 + 2);
    *(wchar_t **)(param_1 + 0x84) = _Dest;
    wcscpy(_Dest,param_2);
    *(undefined2 *)(*(int *)(param_1 + 0x84) + sVar1 * 2) = 0;
  }
  return;
}
```
