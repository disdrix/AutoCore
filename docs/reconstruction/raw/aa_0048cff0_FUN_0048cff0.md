# Raw capture: FUN_0048cff0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048cff0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0048cff0` |
| **Canonical name** | `FUN_0048cff0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
uint FUN_0048cff0(char *param_1,char *param_2,char param_3,int param_4)

{
  char *pcVar1;
  char cVar2;
  undefined4 in_EAX;
  uint3 uVar3;
  uint _C;
  uint _C_00;
  undefined3 uVar4;
  
  uVar3 = (uint3)((uint)in_EAX >> 8);
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    return (uint)uVar3 << 8;
  }
  _C_00 = CONCAT31(uVar3,param_3);
  if (param_3 == '\0') {
    do {
      cVar2 = *param_2;
      uVar4 = (undefined3)(_C_00 >> 8);
      _C_00 = CONCAT31(uVar4,cVar2);
      if (cVar2 == '\0') goto LAB_0048d06a;
      if (*param_1 != cVar2) break;
      pcVar1 = param_1 + 1;
      _C_00 = CONCAT31(uVar4,*pcVar1);
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    } while (*pcVar1 != '\0');
    _C_00 = CONCAT31((int3)(_C_00 >> 8),*param_2);
  }
  else {
    do {
      if (*param_2 == '\0') goto LAB_0048d06a;
      _C = (uint)*param_1;
      if ((param_4 != 1) || ((int)_C < 0x80)) {
        _C = tolower(_C);
      }
      _C_00 = (uint)*param_2;
      if ((param_4 != 1) || ((int)_C_00 < 0x80)) {
        _C_00 = tolower(_C_00);
      }
      if (_C != _C_00) break;
      pcVar1 = param_1 + 1;
      _C_00 = CONCAT31((int3)(_C_00 >> 8),*pcVar1);
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    } while (*pcVar1 != '\0');
    _C_00 = CONCAT31((int3)(_C_00 >> 8),*param_2);
  }
  if ((char)_C_00 != '\0') {
    return _C_00 & 0xffffff00;
  }
LAB_0048d06a:
  return CONCAT31((int3)(_C_00 >> 8),1);
}
```
