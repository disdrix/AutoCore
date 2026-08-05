# Raw capture: FUN_005ac1d0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ac1d0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ac1d0` |
| **Canonical name** | `FUN_005ac1d0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall
FUN_005ac1d0(int param_1,
            basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
            *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  bool bVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar5 = (undefined4 *)(*(undefined4 **)(param_1 + 4))[1];
  cVar1 = *(char *)((int)puVar5 + 0x2d);
  puVar2 = *(undefined4 **)(param_1 + 4);
  while (cVar1 == '\0') {
    bVar3 = std::operator<<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
                      ((basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>
                        *)(puVar5 + 3),param_2);
    if (bVar3) {
      puVar4 = (undefined4 *)puVar5[2];
      puVar5 = puVar2;
    }
    else {
      puVar4 = (undefined4 *)*puVar5;
    }
    puVar2 = puVar5;
    puVar5 = puVar4;
    cVar1 = *(char *)((int)puVar4 + 0x2d);
  }
  return puVar2;
}
```
