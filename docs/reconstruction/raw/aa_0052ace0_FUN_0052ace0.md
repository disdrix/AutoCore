# Raw capture: FUN_0052ace0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052ace0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0052ace0` |
| **Canonical name** | `FUN_0052ace0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_0052ace0(int param_1)

{
  int iVar1;
  undefined4 *_Src;
  undefined4 *_Dst;
  
  _Dst = *(undefined4 **)(param_1 + 0xd80);
  if (_Dst != *(undefined4 **)(param_1 + 0xd84)) {
    _Src = _Dst + 1;
    do {
      iVar1 = (**(code **)(*(int *)*_Dst + 0x25c))();
      if (iVar1 < 1) {
        FUN_004d4790(*_Dst);
        memmove(_Dst,_Src,(*(int *)(param_1 + 0xd84) - (int)_Src >> 2) * 4);
        *(int *)(param_1 + 0xd84) = *(int *)(param_1 + 0xd84) + -4;
      }
      else {
        _Dst = _Dst + 1;
        _Src = _Src + 1;
      }
    } while (_Dst != *(undefined4 **)(param_1 + 0xd84));
  }
  return;
}
```
