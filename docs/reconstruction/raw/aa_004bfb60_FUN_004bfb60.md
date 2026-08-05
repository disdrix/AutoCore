# Raw capture: FUN_004bfb60

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bfb60` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bfb60` |
| **Canonical name** | `FUN_004bfb60` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
int __thiscall FUN_004bfb60(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + param_2 + 0xac);
  switch(*(undefined4 *)(iVar2 + 0x38)) {
  case 1:
    return param_1 + 4 +
           (((byte)~(*(byte *)(*(int *)(iVar2 + 0x3c) + 0x3f2) >> 7) & 1) * 2 | 5) * 0xc;
  default:
    return param_1 + 100;
  case 3:
    return param_1 + 0x4c;
  case 4:
  case 6:
  case 8:
  case 10:
  case 0x1a:
  case 0x1c:
  case 0x32:
  case 0x34:
  case 0x42:
    return param_1 + 0x40;
  case 0xc:
    cVar1 = FUN_005130e0(1);
    return param_1 + 4 + ((-(uint)(cVar1 != '\0') & 3) + 2) * 0xc;
  case 0xe:
    break;
  case 0x10:
    return param_1 + 4;
  case 0x12:
    return param_1 + 0x34;
  case 0x14:
  case 0x28:
  case 0x2a:
  case 0x2c:
  case 0x2e:
    return param_1 + 0x28;
  }
  iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x1d4))();
  if ((iVar2 == 0) || (iVar3 = 5, *(char *)(iVar2 + 0x2ac) == '\0')) {
    iVar3 = 1;
  }
  return param_1 + 4 + iVar3 * 0xc;
}
```
