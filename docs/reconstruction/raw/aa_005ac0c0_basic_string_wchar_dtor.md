# Raw capture: basic_string_wchar_dtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ac0c0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ac0c0` |
| **Canonical name** | `basic_string_wchar_dtor` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall

std::basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>::

~basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

          (basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>

           *this)



{

                    /* WARNING: Could not recover jumptable at 0x005ac0c0. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  ~basic_string<wchar_t,struct_std::char_traits<wchar_t>,class_std::allocator<wchar_t>_>(this);

  return;

}
```
