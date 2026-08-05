# Raw capture: FUN_008bb2c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_008bb2c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x008bb2c0` |
| **Canonical name** | `FUN_008bb2c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_008bb2c0(void)

{
  int in_EAX;
  int iVar1;
  void *local_8;
  undefined4 local_4;
  
  local_4 = 0;
  FUN_004294f0();
  iVar1 = FUN_004113b0(in_EAX + 0x530,&local_8);
  while (iVar1 == 0) {
    if (local_8 != (void *)0x0) {
      operator_delete__(local_8);
    }
    local_8 = (void *)0x0;
    iVar1 = FUN_004113b0(in_EAX + 0x530,&local_8);
  }
  if (*(char *)(in_EAX + 0x558) != '\0') {
    *(undefined1 *)(in_EAX + 0x558) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)(in_EAX + 0x534));
  }
  FUN_00410d60();
  return;
}
```
