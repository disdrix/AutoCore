# Raw capture: FUN_0099caa0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0099caa0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0099caa0` |
| **Canonical name** | `FUN_0099caa0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall
FUN_0099caa0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 in_EAX;
  int iVar1;
  undefined4 *unaff_ESI;
  undefined4 *puVar2;
  
  FUN_0071e6e0(param_3,param_4,param_6,param_7,param_2,param_1,in_EAX);
  *unaff_ESI = &PTR_FUN_00aa98fc;
  puVar2 = unaff_ESI + 0x94;
  for (iVar1 = 0x32; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return;
}
```
