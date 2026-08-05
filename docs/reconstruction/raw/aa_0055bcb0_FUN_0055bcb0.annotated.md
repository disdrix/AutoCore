# Annotated low-level: FUN_0055bcb0

| Field | Value |
|---|---|
| Stable ID | `aa_0055bcb0` |
| VA | `0x0055bcb0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0055bcb0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void __thiscall
FUN_0055bcb0(int param_1,undefined4 *param_2,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_3)

{
  char cVar1;
  undefined4 *puVar2;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar3;
  bool bVar4;
  bool bVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  pbVar3 = param_3;
  puVar6 = (undefined4 *)(*(undefined4 **)(param_1 + 4))[1];
  bVar4 = true;
  cVar1 = *(char *)((int)puVar6 + 0x2d);
  puVar2 = *(undefined4 **)(param_1 + 4);
  while (cVar1 == '\0') {
    bVar4 = std::operator<<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                      (pbVar3,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                               *)(puVar6 + 3));
    if (bVar4) {
      puVar7 = (undefined4 *)*puVar6;
    }
    else {
      puVar7 = (undefined4 *)puVar6[2];
    }
    puVar2 = puVar6;
    puVar6 = puVar7;
    cVar1 = *(char *)((int)puVar7 + 0x2d);
  }
  param_3 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)puVar2;
  if (bVar4 != false) {
    if (puVar2 == (undefined4 *)**(int **)(param_1 + 4)) {
      puVar6 = (undefined4 *)FUN_0055b7f0(&param_3,1,puVar2,pbVar3);
      *param_2 = *puVar6;
      *(undefined1 *)(param_2 + 1) = 1;
      return;
    }
    FUN_00493380();
  }
  puVar6 = (undefined4 *)param_3;
  bVar5 = std::operator<<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                    ((basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )((int)param_3 + 0xc),pbVar3);
  if (bVar5) {
    puVar6 = (undefined4 *)FUN_0055b7f0(&param_3,bVar4,puVar2,pbVar3);
    *param_2 = *puVar6;
    *(undefined1 *)(param_2 + 1) = 1;
    return;
  }
  *param_2 = puVar6;
  *(undefined1 *)(param_2 + 1) = 0;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
