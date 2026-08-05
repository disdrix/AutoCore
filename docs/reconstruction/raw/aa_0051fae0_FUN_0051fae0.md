# Raw capture: FUN_0051fae0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051fae0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0051fae0` |
| **Canonical name** | `FUN_0051fae0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0051fae0(int param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  char *_Dest;
  
  if (*(void **)(param_1 + 0x64c) != (void *)0x0) {
    operator_delete__(*(void **)(param_1 + 0x64c));
  }
  *(undefined4 *)(param_1 + 0x64c) = 0;
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar2 = pcVar2 + (1 - (int)(param_2 + 1));
  if (pcVar2 != (char *)0x0) {
    _Dest = operator_new__((uint)pcVar2);
    *(char **)(param_1 + 0x64c) = _Dest;
    strncpy(_Dest,param_2,(size_t)pcVar2);
  }
  return;
}
```
