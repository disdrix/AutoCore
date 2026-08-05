# Annotated low-level: FUN_004a7aa0 / StdVector_DestroyRange_BasicStringW

| Field | Value |
|---|---|
| Stable ID | `aa_004a7aa0` |
| VA | `0x004a7aa0`–`0x004a7ac4` exclusive (**36 B**) |
| System | MSVC `vector<basic_string<wchar_t>>` destroy-range |
| Date | 2026-07-23 scaffold; W36-S refine 2026-07-29 |

## Machine-level notes

- **ABI:** stack `first*`, `last*`; **`RET 0x08`** (`C2 08 00`); void. Not ECX-thiscall for the range (each elem uses thiscall dtor via ECX).
- **Loop:** `[first, last)` with stride **`0x1c`** (`ADD ESI,0x1C`).
- **Dtor:** IAT `[0x009c62ac]` → `0x006eb03a` — `~basic_string<wchar_t>` (thiscall ECX = elem).
- **Does not free** the buffer; parent insert-n grow path calls `operator_delete` after this.
- **Twin:** char destroy-range `StdVector_DestroyRange_BasicString` (`0x00431aa0`, W33-H) — same shape, different IAT (`0x009c62f4`).
- Prefer bytes when decompiler omits RET cleanup width.

## Pseudocode (annotated)

```c
// stack first*, last*; RET 0x08; void
void StdVector_DestroyRange_BasicStringW(
    BasicStringW_0x1c* first,
    BasicStringW_0x1c* last)
{
  for (; first != last; first = (BasicStringW_0x1c*)((uint8_t*)first + 0x1c)) {
    basic_string_wchar_dtor(first); // IAT [0x009c62ac]
  }
}
```

## Call graph

| Direction | Targets |
|---|---|
| Callers | `StdVector_InsertN_BasicStringW` (`0x004a7ad0`) grow + two catch sites |
| Callees | IAT `~basic_string<wchar_t>` |

## Open / residual

- Product/MSVC demangle (`_Destroy_range` English).
- Full IAT symbol plate for dtor.
- Runtime / bit-exact / differential.
