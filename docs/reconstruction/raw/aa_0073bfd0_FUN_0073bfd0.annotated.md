# Annotated low-level: FUN_0073bfd0

| Field | Value |
|---|---|
| Stable ID | `aa_0073bfd0` |
| VA | `0x0073bfd0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0073bfd0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0073bfd0(void)

{
  int iVar1;
  undefined4 *unaff_ESI;
  undefined4 *puVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009ab51a;
  local_c = ExceptionList;
  local_4 = 0;
  DAT_00d1f62c = unaff_ESI;
  ExceptionList = &local_c;
  *unaff_ESI = 0;
  _eh_vector_constructor_iterator_
            (unaff_ESI + 1,0x2c,4,FUN_00462230,
             std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
             ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>);
  puVar2 = unaff_ESI + 1;
  for (iVar1 = 0x2c; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  unaff_ESI[0x2d] = 0;
  unaff_ESI[0x2e] = 0;
  unaff_ESI[0x2f] = 0;
  unaff_ESI[0x30] = 0;
  ExceptionList = local_c;
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
