# Raw capture: hkDefaultAnalogDriverInput_calcStatus

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fe520` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005fe520` |
| **Canonical name** | `hkDefaultAnalogDriverInput_calcStatus` |
| **System** | input-drive-control |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* WI-MOV-005: maps ctrl+0x20 raw pedal into status. Accel(-1)→+0xc |pedal|; positive→+0x10
   brake; +0x14 steer via FUN_005fdf20; +0x18=ctrl+0x24 handbrake; +0x19 reverse via FUN_005fe0b0.
   Same object as handle[8]/fw+0x14. Does NOT scale calcWheelTorque (AA has no engine consumer of
   +0xc). Live: brake_update reads +0x10/+0x18. */

void __fastcall hkDefaultAnalogDriverInput_calcStatus(int param_1)

{
  undefined1 *puVar1;
  float10 fVar2;
  float fVar3;
  undefined4 uStack_4;
  
  if ((*(char *)(*(int *)(*(int *)(param_1 + 8) + 0x20) + 0x14) == '\0') ||
     (*(char *)(param_1 + 0x3c) == '\0')) {
    fVar3 = *(float *)(param_1 + 0x20);
  }
  else {
    fVar3 = 0.0 - *(float *)(param_1 + 0x20);
  }
  if (fVar3 <= 0.0) {
    fVar3 = fVar3 * DAT_00aaa668;
  }
  else {
    fVar3 = 0.0;
  }
  *(float *)(param_1 + 0xc) = fVar3;
  if ((*(char *)(*(int *)(*(int *)(param_1 + 8) + 0x20) + 0x14) == '\0') ||
     (*(char *)(param_1 + 0x3c) == '\0')) {
    fVar3 = *(float *)(param_1 + 0x20);
  }
  else {
    fVar3 = 0.0 - *(float *)(param_1 + 0x20);
  }
  if (fVar3 < 0.0) {
    fVar3 = 0.0;
  }
  *(float *)(param_1 + 0x10) = fVar3;
  uStack_4 = param_1;
  fVar2 = (float10)FUN_005fdf20();
  *(float *)(param_1 + 0x14) = (float)fVar2;
  *(undefined1 *)(param_1 + 0x18) = *(undefined1 *)(param_1 + 0x24);
  puVar1 = (undefined1 *)hkDefaultAnalogDriverInput_calcReverse((int)&uStack_4 + 3);
  *(undefined1 *)(param_1 + 0x19) = *puVar1;
  return;
}
```
