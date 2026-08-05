# Raw capture: thunk_FUN_0076c4d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076c5c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0076c5c0` |
| **Canonical name** | `thunk_FUN_0076c4d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall thunk_FUN_0076c4d0(int param_1)

{
  undefined8 uVar1;
  
  uVar1 = rdtsc();
  *(int *)(param_1 + 8) = (int)uVar1;
  *(int *)(param_1 + 0xc) = (int)((ulonglong)uVar1 >> 0x20);
  *(undefined1 *)(param_1 + 0x18) = 1;
  return;
}
```
