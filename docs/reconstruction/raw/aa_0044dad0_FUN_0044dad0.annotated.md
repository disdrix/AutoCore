# Annotated low-level: FUN_0044dad0

| Field | Value |
|---|---|
| Stable ID | `aa_0044dad0` |
| VA | `0x0044dad0` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_0044dad0`.
- Prefer assembly when decompiler conflicts.
- Recover types for still-generic parameters via callers/xrefs.
- Map DAT_* globals and FUN_* callees in follow-up waves.

## Pseudocode (annotated copy of raw)

```c
void FUN_0044dad0(void)

{
  bool bVar1;
  int iVar2;
  int *unaff_EBX;
  int unaff_ESI;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *unaff_EDI;
  
  iVar2 = FUN_0044dfc0(unaff_EDI);
  if (iVar2 != *(int *)(unaff_ESI + 4)) {
    bVar1 = std::operator><char,struct_std::char_traits<char>,class_std::allocator<char>_>
                      (unaff_EDI,
                       (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)(iVar2 + 0xc));
    if (!bVar1) {
      *unaff_EBX = iVar2;
      return;
    }
  }
  *unaff_EBX = *(int *)(unaff_ESI + 4);
  return;
}
```

## Open questions

- Confirm calling convention and full signature against callers.
- Recover meaningful types for still-generic parameters.
