# Raw capture: FUN_005ee4e0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ee4e0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ee4e0` |
| **Canonical name** | `FUN_005ee4e0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_005ee4e0(int *param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = *param_3;
  FUN_005ee030(iVar1 + *param_1 * 0xc,iVar1 + param_1[1] * 0xc,iVar1 + param_1[2] * 0xc);
  *param_2 = local_10;
  param_2[1] = local_c;
  param_2[2] = local_8;
  param_2[3] = local_4;
  return;
}
```
