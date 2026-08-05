# Raw capture: FUN_0052ada0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052ada0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0052ada0` |
| **Canonical name** | `FUN_0052ada0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __fastcall FUN_0052ada0(int param_1)

{
  int local_4;
  
  local_4 = param_1;
  FUN_00418b80(&local_4,&stack0x00000004);
  if (local_4 == *(int *)(param_1 + 0x588)) {
    return 0xffffffff;
  }
  return *(undefined4 *)(local_4 + 0x10);
}
```

---

## Version note (2026-07-29 dual)

Live Ghidra re-decompile **CF-identical** to this raw body. Dual A/B seals assembly ABI (`__thiscall` + `RET 4`), map `+0x584/+0x588`, value `node+0x10`, missing → `-1`. See `reviews/A_aa_0052ada0_*` / `B_aa_0052ada0_*`. Do not rewrite raw body.
