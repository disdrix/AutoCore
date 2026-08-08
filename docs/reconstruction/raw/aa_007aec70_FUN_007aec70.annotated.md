# Annotated low-level: FUN_007aec70 → CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_007aec70` |
| VA | `0x007aec70`–`0x007aecc3` (**84 B**) |
| System | CNDUIWindow complete-dtor helper |
| Date | 2026-08-05 (WQ9L-G re-verify) |
| Named | `CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred` |

## Machine-level notes

- **ABI:** ECX=`CNDUIWindow* this`; bare `RET` (`C3`); void.
- **Role:** partial teardown leaf in `CNDUIWindow_CompleteDtor` after `FUN_007a8580`, before `FUN_007aff00`.
- **Owned shell @ +0x294:** if non-null and ownership flag `@+0xBB`:
  - `RefCountedPtr_Dtor_Inferred` (`FUN_0096efd0`) on shell (ECX=shell)
  - `operator_delete(shell)` (cdecl)
- **Always when shell non-null:** null `+0x294`, clear `+0xBB`, call `this->vtbl[+0x2B4]("")` with shared empty literal `DAT_00a1419b`.
- **Always:** zero `+0x29C` and `+0x2A0`.
- Ghidra false-noreturn on `operator_delete` ignored — epilogue present.
- Scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_007aec70` rejected (parent debug string, not this body).

## Pseudocode (byte-corrected)

```c
// ECX = this (CNDUIWindow*)
void __fastcall CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred(uint8_t* self)
{
  void* shell = *(void**)(self + 0x294);
  if (shell != NULL) {
    if (self[0xBB] != 0) {
      RefCountedPtr_Dtor_Inferred((void**)shell); // thiscall ECX=shell
      operator_delete(shell);
    }
    *(void**)(self + 0x294) = NULL;
    self[0xBB] = 0;
    // this->vtbl[+0x2B4](this, "")
    void** vtbl = *(void***)self;
    ((void (__thiscall*)(void*, const char*))vtbl[0x2B4 / 4])(self, (const char*)0x00a1419b);
  }
  *(uint32_t*)(self + 0x29C) = 0;
  *(uint32_t*)(self + 0x2A0) = 0;
}
```

## Open questions

- Product English for vtbl[+0x2B4] (clear-text/set-caption style; empty arg sealed).
- Exact class of heap shell beyond “hosts RefCountedPtr dtor at entry”.
- Semantic names for always-zeroed `+0x29C` / `+0x2A0`.
- Runtime / bit-exact / differential.
