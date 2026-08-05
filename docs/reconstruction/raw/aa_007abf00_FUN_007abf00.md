# Raw capture: FUN_007abf00

| Field | Value |
|---|---|
| **Stable ID** | `aa_007abf00` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007abf00` |
| **Canonical name** | `FUN_007abf00` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
uint __fastcall FUN_007abf00(int *param_1)

{
  uint uVar1;
  
  *(undefined1 *)((int)param_1 + 0xd3) = 0;
  *(undefined1 *)(param_1 + 0x35) = 0;
  *(undefined1 *)((int)param_1 + 0xd5) = 0;
  (**(code **)(*param_1 + 0x330))(5);
  uVar1 = (**(code **)(*param_1 + 0xd8))();
  if (((char)uVar1 != '\0') && ((int *)param_1[0xac] != (int *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x007abf4f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*(int *)param_1[0xac] + 0x338))();
    return uVar1;
  }
  return uVar1 & 0xffffff00;
}
```
