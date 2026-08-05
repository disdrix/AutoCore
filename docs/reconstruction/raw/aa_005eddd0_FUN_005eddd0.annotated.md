# Annotated low-level: FUN_005eddd0

| Field | Value |
|---|---|
| Stable ID | `aa_005eddd0` |
| VA | `0x005eddd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_005eddd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
undefined4 * __thiscall FUN_005eddd0(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  basic_ostream<char,struct_std::char_traits<char>_> *pbVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  char *pcVar8;
  _func_basic_ostream<char,struct_std::char_traits<char>_>_ptr_basic_ostream<char,struct_std::char_traits<char>_>_ptr
  *p_Var9;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a78b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004f32d0();
  local_4 = 0;
  p_Var9 = endl_exref;
  pbVar1 = std::operator<<<struct_std::char_traits<char>_>
                     ((basic_ostream<char,struct_std::char_traits<char>_> *)cout_exref,
                      "Dividing Actor, please wait.");
  std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<(pbVar1,p_Var9);
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0xc] = param_2[0xc];
  param_1[0xd] = param_2[0xd];
  puVar3 = param_2;
  puVar4 = param_1;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  param_1[9] = param_2[9];
  param_1[10] = param_2[10];
  param_1[0xb] = param_2[0xb];
  param_1[0xe] = param_2[0xe];
  *(undefined2 *)(param_1 + 0xf) = *(undefined2 *)(param_2 + 0xf);
  param_1[0x11] = param_2[0x11];
  param_1[0x10] = param_2[0x10];
  iVar2 = 0;
  param_2[0xc] = 0;
  param_2[0x11] = 0;
  param_2[0x10] = 0;
  if (0 < (int)(param_2[0x15] - param_2[0x14] & 0xfffffffc)) {
    do {
      FUN_005eced0(*(undefined4 *)(param_2[0x14] + iVar2 * 4),param_3);
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)(param_2[0x15] - param_2[0x14]) >> 2);
  }
  FUN_005ec6e0(param_2);
  uVar7 = param_1[0x19];
  uVar5 = param_1[0x1a];
  pcVar8 = " candidates considered.";
  pcVar6 = " divisions performed. ";
  p_Var9 = endl_exref;
  pbVar1 = std::operator<<<struct_std::char_traits<char>_>
                     ((basic_ostream<char,struct_std::char_traits<char>_> *)cout_exref,
                      "Division complete. ");
  pbVar1 = std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<(pbVar1,uVar5);
  pbVar1 = std::operator<<<struct_std::char_traits<char>_>(pbVar1,pcVar6);
  pbVar1 = std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<(pbVar1,uVar7);
  pbVar1 = std::operator<<<struct_std::char_traits<char>_>(pbVar1,pcVar8);
  std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<(pbVar1,p_Var9);
  ExceptionList = local_c;
  return param_1;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
