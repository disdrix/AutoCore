# Raw capture: Std_LengthError_CtorFromString

| Field | Value |
|---|---|
| **Stable ID** | `aa_00401a40` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00401a40`–`0x00401a90` |
| **Canonical name** | `Std_LengthError_CtorFromString` |
| **Prior scaffold** | `FUN_00401a40` / misname `Named_CalleeOf_Named_CalleeOf_Auth_AuthServer_00401a40` |
| **System** | MSVC STL / `std::length_error` |
| **Capture timestamp** | `2026-07-29` (W20-L dual seal; body ≡ 2026-07-23 raw) |
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` + RTTI strings |
| **Integrity** | Named raw; authoritative CF matches scaffold raw |

---

## Raw pseudocode (authoritative decompile)

```c
/* std::length_error::length_error(std::string const&)
   RTTI: .?AVlength_error@std@@
   Base: FUN_00401aa0 = logic_error(string) → vtbl 009c7628
   This: install vtbl PTR_FUN_009c7634; ret 4
*/

undefined4 * __thiscall
Std_LengthError_CtorFromString(undefined4 *this,
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *msg)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009bc828;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00401aa0(msg);                 /* std::logic_error(msg) */
  *this = &PTR_FUN_009c7634;         /* length_error vtbl */
  ExceptionList = local_c;
  return this;
}
```
