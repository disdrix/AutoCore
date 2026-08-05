# Raw capture: FUN_004bf3f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bf3f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bf3f0` |
| **Canonical name** | `FUN_004bf3f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004bf3f0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  uVar1 = *(undefined4 *)(param_1 + 0x590);
  uVar2 = *(undefined4 *)(param_1 + 0x58c);
  if (*(void **)(param_1 + 0x57c) != *(void **)(param_1 + 0x580)) {
    pvVar3 = memmove(*(void **)(param_1 + 0x57c),*(void **)(param_1 + 0x580),0);
    *(void **)(param_1 + 0x580) = pvVar3;
  }
  FUN_004bf830(*(undefined4 *)(param_1 + 0x57c),uVar2,uVar1,param_1);
  return;
}
```
