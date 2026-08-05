# Raw capture: FUN_006ba9d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006ba9d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006ba9d0` |
| **Canonical name** | `FUN_006ba9d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006ba9d0(undefined1 *param_1,int param_2,short *param_3,short *param_4,short *param_5,
                 short *param_6)

{
  short *psVar1;
  short sVar2;
  bool bVar3;
  bool bVar4;
  
  if (((param_3 == param_4) || (*param_3 != *param_4)) ||
     (bVar3 = true,
     *(short *)(param_2 + (uint)(ushort)param_3[1] * 8) ==
     *(short *)(param_2 + (uint)(ushort)param_4[1] * 8))) {
    bVar3 = false;
  }
  if (((param_5 == param_6) || (*param_5 != *param_6)) ||
     (bVar4 = true,
     *(short *)(param_2 + (uint)(ushort)param_5[1] * 8) ==
     *(short *)(param_2 + (uint)(ushort)param_6[1] * 8))) {
    bVar4 = false;
  }
  if ((bVar3) && (bVar4)) {
    bVar3 = true;
  }
  else {
    bVar3 = false;
  }
  if (!bVar3) {
    *param_1 = 0;
    return;
  }
  if ((((param_3 == param_6) || (*param_3 != *param_6)) ||
      (*(short *)(param_2 + (uint)(ushort)param_3[1] * 8) !=
       *(short *)(param_2 + (uint)(ushort)param_6[1] * 8))) &&
     ((param_5 != param_6 && (sVar2 = *param_6, *param_5 == sVar2)))) {
    if (*(short *)(param_2 + (uint)(ushort)param_5[1] * 8) !=
        *(short *)(param_2 + (uint)(ushort)param_6[1] * 8)) goto LAB_006baaad;
LAB_006baae5:
    if ((*(short *)(param_2 + (uint)(ushort)param_5[1] * 8) != sVar2) ||
       (*(short *)(param_2 + (uint)(ushort)param_6[1] * 8) != *param_5)) goto LAB_006bab14;
    bVar3 = (short *)(param_2 + (uint)(ushort)param_5[1] * 8) == param_6;
  }
  else {
LAB_006baaad:
    sVar2 = *param_6;
    if (((*(short *)(param_2 + (uint)(ushort)param_3[1] * 8) != sVar2) ||
        (*(short *)(param_2 + (uint)(ushort)param_6[1] * 8) != *param_3)) ||
       ((short *)(param_2 + (uint)(ushort)param_3[1] * 8) == param_6)) goto LAB_006baae5;
LAB_006bab14:
    bVar3 = true;
  }
  if ((((param_3 == param_4) || (*param_3 != *param_4)) ||
      (*(short *)(param_2 + (uint)(ushort)param_3[1] * 8) !=
       *(short *)(param_2 + (uint)(ushort)param_4[1] * 8))) &&
     (((param_5 != param_4 && (sVar2 = *param_4, *param_5 == sVar2)) &&
      (*(short *)(param_2 + (uint)(ushort)param_5[1] * 8) ==
       *(short *)(param_2 + (uint)(ushort)param_4[1] * 8))))) {
LAB_006bab94:
    if ((*(short *)(param_2 + (uint)(ushort)param_5[1] * 8) == sVar2) &&
       (*(short *)(param_2 + (uint)(ushort)param_4[1] * 8) == *param_5)) {
      bVar4 = (short *)(param_2 + (uint)(ushort)param_5[1] * 8) == param_4;
      goto LAB_006babbc;
    }
  }
  else {
    psVar1 = (short *)(param_2 + (uint)(ushort)param_3[1] * 8);
    sVar2 = *param_4;
    if (((*psVar1 != sVar2) || (*(short *)(param_2 + (uint)(ushort)param_4[1] * 8) != *param_3)) ||
       (psVar1 == param_4)) goto LAB_006bab94;
  }
  bVar4 = true;
LAB_006babbc:
  if ((bVar3) && (bVar4)) {
    *param_1 = 1;
    return;
  }
  *param_1 = 0;
  return;
}
```
