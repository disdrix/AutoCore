# Annotated low-level: std_basic_string_char_dtor

| Field | Value |
|---|---|
| Stable ID | `aa_00690450` |
| VA | `0x00690450` |
| System | unknown |
| Date | 2026-07-23 |

## Machine-level notes

- Source: raw capture for `aa_00690450`.
- CRT/import thunk or standard library surface for this address.

## Pseudocode (annotated copy of raw)

```c
void __thiscall
std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::
~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
          (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this)

{
                    /* WARNING: Could not recover jumptable at 0x00690450. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(this);
  return;
}
```
