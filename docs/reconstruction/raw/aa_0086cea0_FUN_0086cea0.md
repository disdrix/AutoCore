# Raw capture: FUN_0086cea0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0086cea0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0086cea0` |
| **Canonical name** | `FUN_0086cea0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0086cea0(int param_1)

{
  undefined4 uVar1;
  float fVar2;
  
  fVar2 = g_flOne;
  *(undefined4 *)(param_1 + 0x4b8) = 0;
  *(undefined4 *)(param_1 + 0x4bc) = 0;
  *(undefined4 *)(param_1 + 0x4b4) = 0;
  *(undefined4 *)(param_1 + 0x504) = 0;
  *(undefined4 *)(param_1 + 0x508) = 0;
  *(undefined4 *)(param_1 + 0x560) = 0;
  *(undefined4 *)(param_1 + 0x564) = 0;
  *(undefined4 *)(param_1 + 0x568) = 0;
  *(undefined4 *)(param_1 + 0x56c) = 0;
  *(undefined4 *)(param_1 + 0x570) = 0;
  *(undefined4 *)(param_1 + 0x574) = 0;
  *(undefined4 *)(param_1 + 0x578) = 0;
  *(undefined4 *)(param_1 + 0x57c) = 0;
  *(undefined4 *)(param_1 + 0x580) = 0;
  *(undefined4 *)(param_1 + 0x584) = 0;
  uVar1 = DAT_00a0f298;
  *(undefined4 *)(param_1 + 0x50c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x510) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x514) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x518) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x51c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x588) = 0;
  *(undefined4 *)(param_1 + 0x59c) = 0;
  *(undefined4 *)(param_1 + 0x58c) = 0;
  *(undefined4 *)(param_1 + 0x5a0) = 0;
  *(undefined4 *)(param_1 + 0x590) = 0;
  *(undefined4 *)(param_1 + 0x5a4) = 0;
  *(undefined4 *)(param_1 + 0x594) = 0;
  *(undefined4 *)(param_1 + 0x5a8) = 0;
  *(undefined4 *)(param_1 + 0x598) = 0;
  *(undefined4 *)(param_1 + 0x5ac) = 0;
  *(undefined4 *)(param_1 + 0x528) = 0xffffffff;
  *(float *)(param_1 + 0x540) = fVar2;
  *(float *)(param_1 + 0x544) = fVar2;
  *(float *)(param_1 + 0x548) = fVar2;
  *(float *)(param_1 + 0x54c) = fVar2;
  *(undefined4 *)(param_1 + 0x530) = uVar1;
  *(undefined4 *)(param_1 + 0x534) = uVar1;
  *(float *)(param_1 + 0x538) = fVar2;
  *(float *)(param_1 + 0x53c) = fVar2;
  *(undefined4 *)(param_1 + 0x550) = 0;
  *(undefined4 *)(param_1 + 0x554) = 0;
  *(float *)(param_1 + 0x558) = fVar2;
  *(float *)(param_1 + 0x55c) = fVar2;
  return;
}
```
