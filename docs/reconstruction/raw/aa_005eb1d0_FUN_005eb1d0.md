# Raw capture: FUN_005eb1d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005eb1d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005eb1d0` |
| **Canonical name** | `FUN_005eb1d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005eb1d0(int param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = param_2;
  FUN_005f5690(param_2);
  pcVar2 = (char *)FUN_005eaf50(&param_2,param_1 + 0x80,0x38d1b717);
  if (*pcVar2 == '\0') {
    FUN_005eb0e0(iVar1 + 0x20);
  }
  return;
}
```
