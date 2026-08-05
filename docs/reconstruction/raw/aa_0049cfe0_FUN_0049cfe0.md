# Raw capture: FUN_0049cfe0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0049cfe0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0049cfe0` |
| **Canonical name** | `FUN_0049cfe0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 FUN_0049cfe0(int param_1,int *param_2)

{
  float fVar1;
  char cVar2;
  int iVar3;
  int *local_4;
  
  if (param_2 != (int *)0x0) {
    iVar3 = (**(code **)(*param_2 + 0x44))(param_2,&local_4);
    fVar1 = g_flOne;
    if ((iVar3 == 0) && (local_4 != (int *)0x0)) {
      *(byte *)(param_1 + 0x3e3) = *(byte *)(param_1 + 0x3e3) | 8;
      *(float *)(param_1 + 0x3c) = fVar1;
      cVar2 = FUN_00799200(local_4,L"speed",(float *)(param_1 + 0x3c),param_1 + 0x40,&param_2);
      if (cVar2 != '\0') {
        *(byte *)(param_1 + 0x1e4) = *(byte *)(param_1 + 0x1e4) & 0x7f | (char)param_2 << 7;
      }
      (**(code **)(*local_4 + 8))(local_4);
      return 1;
    }
  }
  FUN_007a4480(0,"VOG_DEBUG_STOP");
  return 0;
}
```
