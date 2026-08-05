# Raw capture: FUN_006fa6f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_006fa6f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x006fa6f0` |
| **Canonical name** | `FUN_006fa6f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_006fa6f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  char cVar1;
  char cVar2;
  ushort uVar3;
  ushort local_8;
  ushort local_6 [3];
  
  local_6[1] = 0;
  FUN_006f8340(&local_8,local_6);
  FUN_006fa670(param_1,&local_8,param_8);
  if (param_4 == 0) {
    cVar1 = '\x03';
  }
  else {
    cVar1 = (param_4 == 1) + '\x01';
  }
  if (param_5 == 0) {
    cVar2 = '\x03';
  }
  else {
    cVar2 = (param_5 == 1) + '\x01';
  }
  uVar3 = (ushort)(1 << cVar1 + 4);
  local_8 = local_8 ^ uVar3;
  FUN_006fa670(param_1,&local_8,param_8);
  local_6[0] = local_6[0] ^ (ushort)(1 << cVar2 + 4);
  FUN_006fa670(param_1,&local_8,param_8);
  local_8 = local_8 ^ uVar3;
  FUN_006fa670(param_1,&local_8,param_8);
  return;
}
```
