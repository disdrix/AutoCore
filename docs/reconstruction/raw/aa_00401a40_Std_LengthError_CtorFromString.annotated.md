# Annotated low-level: Std_LengthError_CtorFromString

| Field | Value |
|---|---|
| Stable ID | `aa_00401a40` |
| VA | `0x00401a40`–`0x00401a90` |
| Canonical name | `Std_LengthError_CtorFromString` |
| Prior scaffold | `FUN_00401a40` |
| System | MSVC STL / `std::length_error` |
| Date | 2026-07-29 (W20-L) |

## Machine-level notes

- **`__thiscall`**: ECX = `this`, stack arg0 = `const std::string*`; epilogue **`RET 4`** (`C2 04 00`).
- SEH frame: `PUSH -1` / `PUSH LAB_009bc828` / FS:[0] chain — standard MSVC EH prolog for ctors that can throw.
- Sole static callee: **`FUN_00401aa0`** = `std::logic_error::logic_error(string const&)`:
  - `exception::exception(this)`
  - vtbl `PTR_FUN_009c7628` (logic_error)
  - `basic_string` copy-ctor into `this+0x0c`
- After base returns: **overwrite vtbl** with `PTR_FUN_009c7634` (length_error).
- Throw sites: `_CxxThrowException(&obj, &DAT_00acc388)` — object size **0x28** in CatchableType; messages include `"vector<T> too long"`, `"map/set<T> too long"`.
- RTTI TypeDescriptor string **Confirmed**: `.?AVlength_error@std@@` @ `0x00af8bf0`.
- Related (not OWN): dtor/unwind `FUN_00401880`; copy-ctor-like `FUN_00401970` (same vtbl install after different base).

## Pseudocode (annotated)

```c
// std::length_error::length_error(const std::string& what_arg)
std::length_error* __thiscall
Std_LengthError_CtorFromString(std::length_error* this, const std::string* msg)
{
  // SEH: state=-1, filter LAB_009bc828
  Std_LogicError_CtorFromString(this, msg);  // FUN_00401aa0
  this->vtbl = &PTR_FUN_009c7634;            // length_error
  return this;
}
```

## Open residual

- Full vtable slot product names at `009c7634` (what()/dtor/…).
- Exact MSVC CRT version of layout (string SSO vs heap) — not required for throw port.
- Runtime throw golden (optional).
