# Raw capture: FUN_0053fff0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053fff0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0053fff0` |
| **Canonical name** | `FUN_0053fff0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __fastcall FUN_0053fff0(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a3f90;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 0xf18) == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x10);
    local_4 = 0;
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_0060b870();
    }
    *(undefined4 *)(param_1 + 0xf18) = uVar2;
  }
  ExceptionList = local_c;
  return *(undefined4 *)(param_1 + 0xf18);
}
```

---

## Re-verify note (append-only) — 2026-07-29 wave3

- Tool: Ghidra MCP `decompile_function` `0x0053fff0` + `read_memory` 96 bytes @ entry.
- Result: body **=** frozen raw above (lazy `+0xf18`, `new(0x10)`, `FUN_0060b870`, return slot).
- Seal: dual A/B `Mission_EnsureRegionMissions`; wrapper layout via ctor `0x0060b870` (`VOGRegionMissions.cpp`).
- Do not rewrite the authoritative raw block; this section is metadata only.
