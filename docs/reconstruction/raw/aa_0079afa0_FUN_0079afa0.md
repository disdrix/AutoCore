# Raw capture: FUN_0079afa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0079afa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0079afa0` |
| **Canonical name** | `FUN_0079afa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __fastcall FUN_0079afa0(int *param_1)

{
  char cVar1;
  undefined4 unaff_ESI;
  undefined4 uVar2;
  
  cVar1 = (**(code **)(*param_1 + 0xd8))();
  if (cVar1 != '\0') {
    if (*(char *)((int)param_1 + 0xd3) != '\0') {
      uVar2 = 0;
      (**(code **)(*param_1 + 0x3d0))(0);
      (**(code **)(*param_1 + 0x3c8))(*(char *)((int)param_1 + 0x48e) == '\0',1);
      (**(code **)(*param_1 + 0x34c))();
      FUN_007a81e0(uVar2,unaff_ESI);
    }
    return 1;
  }
  return 0;
}
```
