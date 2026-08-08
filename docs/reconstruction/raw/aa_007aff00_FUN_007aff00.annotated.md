# Annotated low-level: FUN_007aff00 → CNDUIWindow_ReleaseTextLayoutAndNested_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_007aff00` |
| VA | `0x007aff00`–`0x007aff51` (**82 B**) |
| System | CNDUIWindow complete-dtor helper |
| Date | 2026-08-05 (WQ9L-G re-verify) |
| Named | `CNDUIWindow_ReleaseTextLayoutAndNested_Inferred` |

## Machine-level notes

- **ABI:** ECX=`CNDUIWindow* this`; bare `RET` (`C3`); void.
- **Role:** partial teardown leaf in `CNDUIWindow_CompleteDtor` after `FUN_007aec70`; early free of text layout + nested list clear.
- **Gate `+0x20C`:** if non-zero, free owned layout at `+0x28C`:
  - `UiTextLayout_CompleteDtor_Inferred` (`FUN_00797d70`, stdcall/`RET 4`)
  - `operator_delete(layout)`
  - always null `+0x28C` when gate taken
- **Always:** `FUN_00424060(this+0x1E8)` — nested CS-guarded list clear (decompiler dropped LEA).
- **Always:** zero `+0x128` and `+0x12C`.
- Parent may free `+0x28C` again after return (no-op if already nulled) and later restamp nested vtbl + re-call `FUN_00424060` + `DeleteCriticalSection`.
- Scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_007aff00` rejected.

## Pseudocode (byte-corrected)

```c
// ECX = this (CNDUIWindow*)
void __fastcall CNDUIWindow_ReleaseTextLayoutAndNested_Inferred(uint8_t* self)
{
  if (*(int32_t*)(self + 0x20C) != 0) {
    void* layout = *(void**)(self + 0x28C);
    if (layout != NULL) {
      UiTextLayout_CompleteDtor_Inferred(layout); // stdcall RET 4
      operator_delete(layout);
    }
    *(void**)(self + 0x28C) = NULL;
  }
  FUN_00424060(self + 0x1E8); // thiscall nested object
  *(uint32_t*)(self + 0x128) = 0;
  *(uint32_t*)(self + 0x12C) = 0;
}
```

## Open questions

- Product English for gate field `+0x20C` and always-zeroed `+0x128`/`+0x12C`.
- Product class of nested object at `+0x1E8` (CS + list; vtbls `00a964b8`/`00a964ac` in parent).
- Why layout free is gated here vs unconditional parent free of same slot.
- Runtime / bit-exact / differential.
