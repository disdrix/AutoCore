# Raw capture: FUN_005be6a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005be6a0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005be6a0` |
| **Canonical name** | `FUN_005be6a0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005be6a0(int param_1)

{
  if (*(char *)(param_1 + 0xc4) != '\0') {
    *(undefined1 *)(param_1 + 0xc4) = 0;
    if (*(int *)(param_1 + 200) == 0) {
      DAT_00b45510 = *(undefined4 *)(param_1 + 0xcc);
    }
    else {
      *(undefined4 *)(*(int *)(param_1 + 200) + 0xcc) = *(undefined4 *)(param_1 + 0xcc);
    }
    if (*(int *)(param_1 + 0xcc) == 0) {
      DAT_00b45514 = *(undefined4 *)(param_1 + 200);
    }
    else {
      *(undefined4 *)(*(int *)(param_1 + 0xcc) + 200) = *(undefined4 *)(param_1 + 200);
    }
    DAT_00b45518 = DAT_00b45518 + -1;
    if (DAT_00b45518 == 0) {
      DAT_00b45510 = 0;
      DAT_00b45514 = 0;
    }
  }
  return;
}
```
