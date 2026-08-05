# Raw capture: std_basic_string_char_dtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00690450` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00690450` |
| **Canonical name** | `std_basic_string_char_dtor` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

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
