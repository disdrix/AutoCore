# Annotated low-level: FUN_0043cef0 / GuardedVector_RingFillRange

| Field | Value |
|---|---|
| Stable ID | `aa_0043cef0` |
| VA | `0x0043cef0`–`0x0043cf38` (**73 B**) |
| Canonical | `GuardedVector_RingFillRange` (**Inferred**) |
| Ghidra | `FUN_0043cef0` |
| System | STL / guarded ring-vector container |
| Date | 2026-07-29 (W28-D dual seal) |

## Machine-level notes

- **ABI:** 4 stack formals `(container_from, idx_from, container_to, idx_to)`; **EBX = &fill_dword**; plain `RET` (caller cleans `0x10`); saves EBP/ESI/EDI.
- **Leaf:** no callees.
- **Ring map addressing** (MSVC deque-like map of 4-slot pages):
  - `page = idx >> 2`
  - `sub  = idx & 3` (via `idx - page*4`)
  - if `page >= capacity_pages` (`[container+0x08]`) then `page -= capacity_pages`
  - `page_ptr = ([container+0x04])[page]`; store `*EBX` at `page_ptr[sub]`
- **Range:** half-open dual-iterator form; typically same container both ends (parent `FUN_0043cb00` always passes identical container twice).
- **Exclusive parent:** `FUN_0043cb00` grow/insert worker (3 call sites for fill-after-construct / fill residual).

## Pseudocode (annotated)

```c
// EBX = &fill_value (dword)
void GuardedVector_RingFillRange(
    GuardedVectorHeader* container_from, uint32_t idx_from,
    GuardedVectorHeader* container_to,   uint32_t idx_to)
{
  for (; container_from != container_to || idx_from != idx_to; ++idx_from) {
    uint32_t page = idx_from >> 2;
    uint32_t sub  = idx_from - page * 4;
    if (container_from->capacity /*pages*/ <= page)
      page -= container_from->capacity;
    uint32_t* page_ptr =
        reinterpret_cast<uint32_t**>(container_from->slots)[page];
    page_ptr[sub] = *reinterpret_cast<uint32_t*>(ebx_fill_ptr);
  }
}
```

## Open residual

- Product English for element type / container class name.
- Runtime golden vs insert parent paths (unowned `FUN_0043cb00`).
