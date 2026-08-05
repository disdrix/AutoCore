# Raw capture: FUN_0068eba0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0068eba0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0068eba0` |
| **Canonical name** | `FUN_0068eba0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0068eba0(undefined4 *param_1,float param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 local_24 [36];
  
  fcos((float10)param_2 * (float10)DAT_009d9908);
  fsin((float10)(float)((float10)param_2 * (float10)DAT_009d9908));
  puVar1 = (undefined4 *)FUN_0068ea90(local_24,param_1);
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *puVar1;
    puVar1 = puVar1 + 1;
    param_1 = param_1 + 1;
  }
  return;
}
```
