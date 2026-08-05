# Raw capture: FUN_0043bdb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043bdb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0043bdb0` |
| **Canonical name** | `FUN_0043bdb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_0043bdb0(void)

{
  uint in_EAX;
  undefined4 uVar1;
  void *pvVar2;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 4) = 0;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *(undefined4 *)(unaff_ESI + 0xc) = 0;
  if (in_EAX == 0) {
    return 0;
  }
  if (0x3fffffff < in_EAX) {
    uVar1 = FUN_004540b0();
    return uVar1;
  }
  pvVar2 = operator_new(in_EAX * 4);
  *(void **)(unaff_ESI + 4) = pvVar2;
  *(void **)(unaff_ESI + 8) = pvVar2;
  *(void **)(unaff_ESI + 0xc) = (void *)(in_EAX * 4 + (int)pvVar2);
  return 1;
}
```
