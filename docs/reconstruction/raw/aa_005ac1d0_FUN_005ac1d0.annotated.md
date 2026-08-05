# Annotated low-level: FUN_005ac1d0

| Field | Value |
|---|---|
| Stable ID | `aa_005ac1d0` |
| VA | `0x005ac1d0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005ac1d0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

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

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
