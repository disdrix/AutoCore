# Raw capture: FUN_0074ebe0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074ebe0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0074ebe0` |
| **Canonical name** | `FUN_0074ebe0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined2 FUN_0074ebe0(int param_1)

{
  float fVar1;
  float fVar2;
  undefined2 uVar3;
  byte bVar4;
  int in_EAX;
  float10 extraout_ST0;
  
  *(undefined4 *)(in_EAX + 100) = *(undefined4 *)(in_EAX + 0x6c);
  *(undefined4 *)(in_EAX + 0x60) = *(undefined4 *)(in_EAX + 0x68);
  uVar3 = FUN_0074e800(param_1);
  fVar2 = (float)extraout_ST0;
  *(float *)(in_EAX + 0x6c) = (float)extraout_ST0;
  *(int *)(in_EAX + 0x68) = *(int *)(in_EAX + 0x50);
  if (*(int *)(in_EAX + 0x60) != -1) {
    fVar1 = *(float *)(in_EAX + 100);
    bVar4 = (fVar1 == fVar2) << 6 | (NAN(fVar1) || NAN(fVar2)) << 2 | 2U | fVar1 < fVar2;
    uVar3 = CONCAT11(bVar4,(char)uVar3);
    if (fVar1 != fVar2) {
      param_1._1_3_ = (uint3)((uint)fVar2 >> 8);
      param_1 = CONCAT31(param_1._1_3_,1);
      if (*(float *)(in_EAX + 0x3c) < g_flZero) {
        param_1 = (uint)param_1._1_3_ << 8;
      }
      uVar3 = CONCAT11(bVar4,*(int *)(in_EAX + 0x60) != *(int *)(in_EAX + 0x50));
      if (*(int *)(in_EAX + 0x58) != 0) {
        uVar3 = FUN_009873a0(*(undefined4 *)(in_EAX + 100),fVar2,param_1);
      }
    }
  }
  return uVar3;
}
```
