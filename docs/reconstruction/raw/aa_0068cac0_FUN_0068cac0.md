# Raw capture: FUN_0068cac0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0068cac0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0068cac0` |
| **Canonical name** | `FUN_0068cac0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_0068cac0(int param_1,float param_2,byte param_3)

{
  int iVar1;
  float *pfVar2;
  char *pcVar3;
  char cVar4;
  
  param_2 = g_flOne - param_2;
  cVar4 = (char)((uint)param_3 % *(uint *)(*(int *)(param_1 + 4) + 0x2c)) +
          *(char *)(*(int *)(param_1 + 4) + 0x28);
  iVar1 = *(int *)(param_1 + 0xf4);
  param_3 = cVar4;
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(param_1 + 0xfc) - iVar1 >> 2) <= (uint)(*(int *)(param_1 + 0xf8) - iVar1 >> 2)
     )) {
    FUN_004490a0(*(undefined4 *)(param_1 + 0xf8),1,&param_2);
  }
  else {
    pfVar2 = *(float **)(param_1 + 0xf8);
    *pfVar2 = param_2;
    *(float **)(param_1 + 0xf8) = pfVar2 + 1;
  }
  iVar1 = *(int *)(param_1 + 0x104);
  if ((iVar1 != 0) &&
     ((uint)(*(int *)(param_1 + 0x108) - iVar1) < (uint)(*(int *)(param_1 + 0x10c) - iVar1))) {
    pcVar3 = *(char **)(param_1 + 0x108);
    *pcVar3 = cVar4;
    *(char **)(param_1 + 0x108) = pcVar3 + 1;
    return;
  }
  FUN_00446860(*(undefined4 *)(param_1 + 0x108),1,&param_3);
  return;
}
```
