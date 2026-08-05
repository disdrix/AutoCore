# Raw capture: FUN_0088ede0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0088ede0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0088ede0` |
| **Canonical name** | `FUN_0088ede0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
uint __fastcall FUN_0088ede0(int *param_1)

{
  char cVar1;
  uint uVar2;
  
  if (param_1[0x16c] != 0) {
    cVar1 = (**(code **)(*(int *)param_1[0x16c] + 0x3d8))();
    if (cVar1 != '\0') {
                    /* WARNING: Could not recover jumptable at 0x0088ee07. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(*(int *)param_1[0x16c] + 0x39c))();
      return uVar2;
    }
  }
  uVar2 = (**(code **)(*param_1 + 0x3d8))();
  if (((char)uVar2 != '\0') && (param_1[0x12e] != 0)) {
                    /* WARNING: Could not recover jumptable at 0x0088ee2d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(*(int *)param_1[0x12e] + 0x39c))();
    return uVar2;
  }
  return uVar2 & 0xffffff00;
}
```
