# Raw capture: FUN_005ffe10

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ffe10` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ffe10` |
| **Canonical name** | `FUN_005ffe10` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005ffe10(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uStack_4;
  
  *param_1 = &PTR_FUN_009dde58;
  uStack_4 = param_1;
  uVar1 = FUN_00650190();
  FUN_0065ad10((int)&uStack_4 + 3,uVar1);
  while (uStack_4._3_1_ != '\0') {
    uVar2 = FUN_0065acb0(uVar1);
    (**(code **)(*DAT_00b05060 + 4))(uVar2);
    uVar1 = FUN_006501e0(uVar1);
    FUN_0065ad10((int)&uStack_4 + 3,uVar1);
  }
  FUN_00650420();
  *param_1 = &PTR_LAB_009cc290;
  return;
}
```
