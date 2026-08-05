# Raw capture: thunk_FUN_0065e6c0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0064fde0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0064fde0` |
| **Canonical name** | `thunk_FUN_0065e6c0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall thunk_FUN_0065e6c0(int param_1,undefined1 *param_2)

{
  float fVar1;
  float fVar2;
  
  *(undefined1 *)(param_1 + 8) = *param_2;
  fVar1 = DAT_00aaa668;
  fVar2 = g_flOne;
  switch(*param_2) {
  case 0:
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(float *)(param_1 + 0x28) = fVar2;
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(float *)(param_1 + 0x30) = fVar2;
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(undefined4 *)(param_1 + 0x38) = 0;
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(float *)(param_1 + 0x14) = fVar2;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 4);
    return;
  case 1:
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(float *)(param_1 + 0x24) = fVar2;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(float *)(param_1 + 0x38) = fVar2;
    goto LAB_0065ea2b;
  case 2:
    *(float *)(param_1 + 0x20) = g_flOne;
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(float *)(param_1 + 0x34) = fVar2;
    *(undefined4 *)(param_1 + 0x38) = 0;
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(float *)(param_1 + 0x18) = fVar2;
    break;
  case 3:
    *(float *)(param_1 + 0x20) = g_flOne;
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(float *)(param_1 + 0x38) = fVar1;
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(float *)(param_1 + 0x14) = fVar2;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 4);
    return;
  case 4:
    *(float *)(param_1 + 0x20) = g_flOne;
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(float *)(param_1 + 0x34) = fVar1;
    *(undefined4 *)(param_1 + 0x38) = 0;
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(float *)(param_1 + 0x18) = fVar1;
    break;
  case 5:
    *(float *)(param_1 + 0x20) = g_flOne;
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(float *)(param_1 + 0x38) = fVar2;
    fVar2 = DAT_00aaa668;
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(float *)(param_1 + 0x14) = fVar2;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 4);
    return;
  case 6:
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(float *)(param_1 + 0x24) = fVar2;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(float *)(param_1 + 0x30) = fVar1;
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(undefined4 *)(param_1 + 0x38) = 0;
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(float *)(param_1 + 0x18) = fVar2;
    break;
  case 7:
    *(float *)(param_1 + 0x24) = g_flOne;
    fVar2 = DAT_00aaa668;
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(float *)(param_1 + 0x38) = fVar2;
    goto LAB_0065ea2b;
  case 8:
    *(float *)(param_1 + 0x24) = g_flOne;
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(float *)(param_1 + 0x30) = fVar2;
    fVar2 = DAT_00aaa668;
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(undefined4 *)(param_1 + 0x38) = 0;
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(float *)(param_1 + 0x18) = fVar2;
    break;
  case 9:
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(float *)(param_1 + 0x28) = fVar2;
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(float *)(param_1 + 0x34) = fVar1;
    goto LAB_0065ea26;
  case 10:
    *(float *)(param_1 + 0x28) = g_flOne;
    fVar2 = DAT_00aaa668;
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(float *)(param_1 + 0x30) = fVar2;
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(undefined4 *)(param_1 + 0x38) = 0;
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(float *)(param_1 + 0x14) = fVar2;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 4);
    return;
  case 0xb:
    *(float *)(param_1 + 0x28) = g_flOne;
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(float *)(param_1 + 0x34) = fVar2;
    fVar2 = DAT_00aaa668;
LAB_0065ea26:
    *(undefined4 *)(param_1 + 0x38) = 0;
LAB_0065ea2b:
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(float *)(param_1 + 0x10) = fVar2;
    *(undefined4 *)(param_1 + 0x18) = 0;
    break;
  default:
    goto switchD_0065e6da_default;
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
switchD_0065e6da_default:
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 4);
  return;
}
```
