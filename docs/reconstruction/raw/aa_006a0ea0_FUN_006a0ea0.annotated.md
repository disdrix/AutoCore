# Annotated low-level: FUN_006a0ea0

| Field | Value |
|---|---|
| Stable ID | `aa_006a0ea0` |
| VA | `0x006a0ea0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_006a0ea0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
int __thiscall
FUN_006a0ea0(int param_1,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_2)

{
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_2c [28];
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pbVar1 = param_2;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009ab0b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar3 = FUN_0069fcb0(param_2);
  if (iVar3 != *(int *)(param_1 + 4)) {
    bVar2 = std::operator<<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                      (pbVar1,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                               *)(iVar3 + 0xc));
    if (!bVar2) goto LAB_006a0f1b;
  }
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_2c,pbVar1);
  local_10 = 0;
  local_4 = 0;
  piVar4 = (int *)FUN_006a08a0(&param_2,iVar3,local_2c);
  iVar3 = *piVar4;
  local_4 = 0xffffffff;
  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_2c);
LAB_006a0f1b:
  ExceptionList = local_c;
  return iVar3 + 0x28;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
