# Raw capture: hkDefaultAnalogDriverInput_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fe020` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fe020` |
| **Canonical name** | `hkDefaultAnalogDriverInput_ctor` |
| **System** | input-drive-control |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall hkDefaultAnalogDriverInput_ctor(undefined4 *param_1,undefined4 *param_2)

{
  float fVar1;
  float fVar2;
  
  fVar1 = g_flOne;
  *(undefined1 *)(param_1 + 6) = 0;
  *(undefined1 *)((int)param_1 + 0x19) = 0;
  *(undefined1 *)(param_1 + 9) = 0;
  *(undefined1 *)((int)param_1 + 0x25) = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  *(undefined2 *)((int)param_1 + 6) = 1;
  *param_1 = &PTR_FUN_009dd368;
  param_1[10] = *param_2;
  param_1[0xe] = param_2[2];
  param_1[0xb] = param_2[1];
  fVar2 = (float)param_1[0xb] * ((float)param_1[10] - (float)param_1[0xe]);
  *(undefined1 *)(param_1 + 0xf) = *(undefined1 *)(param_2 + 3);
  param_1[0xd] = fVar2;
  param_1[0xc] = (fVar1 - fVar2) /
                 ((fVar1 - (float)param_1[0xe]) - ((float)param_1[10] - (float)param_1[0xe]));
  return;
}
```
