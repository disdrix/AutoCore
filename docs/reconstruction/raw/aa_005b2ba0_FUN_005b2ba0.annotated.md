# Annotated low-level: GuardedVector_Dtor_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_005b2ba0` |
| VA | `0x005b2ba0`–`0x005b2c05` (**102 B** / `0x66`) |
| System | STL / guarded ring-deque container |
| Date | 2026-08-04 (W37-D) |
| Ghidra | `FUN_005b2ba0` |

## Machine-level notes

- Source: live `batch_decompile` + `read_memory` (W37-D). Scaffold raw body 2026-07-23 unchanged.
- **ABI:** ECX = `GuardedVectorHeader*`; plain `RET`; void. (`MOV ESI, ECX`)
- **Layout (family, sealed elsewhere):** `+0x04` pages**, `+0x08` capacity (page count), `+0x0c` begin, `+0x10` size.
- **CF:**
  1. Drain `size` (`+0x10`) to 0; on the decrement that hits 0, also `begin=0`.
  2. For `i = capacity; i > 0; --i`: `p = pages[i-1]`; if non-null → `operator_delete(p)`.
  3. If `pages != null` → `operator_delete(pages)`.
  4. **Always** `capacity = 0`, `pages = 0` (bytes; decompiler misses post-delete stores).
- **Callee:** `operator_delete` @ `0x00489822` (both sites).
- **Not** a header-freeing scalar dtor of the `GuardedVectorHeader` object itself — storage teardown only (stack locals + member rings).
- Decompiler false warnings: both `operator_delete` marked "does not return".

## Pseudocode (annotated)

```c
// ECX = GuardedVectorHeader* this
void __fastcall GuardedVector_Dtor_Inferred(GuardedVectorHeader* this /*ECX*/)
{
  // 1) empty element count; clear begin when size was non-zero
  while (this->size != 0) {
    this->size -= 1;
    if (this->size == 0) {
      this->begin = 0;
    }
  }

  // 2) free each page block (capacity is page count, not element size)
  for (int i = this->capacity; i > 0; ) {
    void* page = this->pages[i - 1];
    i -= 1;
    if (page != nullptr) {
      operator_delete(page);
    }
  }

  // 3) free page-map array + zero map/capacity (always)
  if (this->pages != nullptr) {
    operator_delete(this->pages);
  }
  this->capacity = 0;
  this->pages = 0;
}
```

## Open questions

- Product/PDB class English (`GuardedVector_*` structural family only).
- Whether any caller stores non-POD owning pointers inside pages (this body never runs per-element dtors).
- Runtime / bit-exact / differential.
