# Raw capture: FUN_008bb3e0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008bb3e0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008bb3e0` |
| **Canonical name** | `FUN_008bb3e0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_008bb3e0(int *param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*param_1 + 0x3d8))();
  if (cVar1 != '\0') {
    (**(code **)(*param_1 + 0x3b8))(param_1[0x15d]);
    (**(code **)(*param_1 + 0x3b8))(param_1[0x15c]);
    (**(code **)(*param_1 + 0x3b8))(param_1[0x15b]);
    (**(code **)(*param_1 + 0x3b8))(param_1[0x158]);
    (**(code **)(*param_1 + 0x3b8))(param_1[0x157]);
    (**(code **)(*param_1 + 0x3b8))(param_1[0x15a]);
  }
  (**(code **)(*param_1 + 0x3ac))();
  FUN_00792490();
  return;
}
```
