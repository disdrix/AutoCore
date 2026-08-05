# Annotated low-level: ThreadSafeObjectList_ScalarDeletingDtor

| Field | Value |
|---|---|
| Stable ID | `aa_004bcc40` |
| VA | `0x004bcc40`–`0x004bcc5d` (**30 B**) |
| Canonical | `ThreadSafeObjectList_ScalarDeletingDtor` |
| Ghidra | `FUN_004bcc40` |
| System | client::util / lock-protected object list |
| Date | 2026-07-29 (W26-I OWN dual) |

## Machine-level notes

- MSVC **scalar deleting destructor** pattern: complete body dtor + optional heap free.
- Body dtor sibling: `ThreadSafeObjectList_Dtor` (`FUN_004bcbf0` @ `0x004bcbf0`, dual W25-C **accept**).
- Vtbl: `PTR_FUN_009cb368` slot 0 = this VA (`read_memory` @ `0x009cb368` → `0x004bcc40`).
- ABI: `__thiscall`, ECX=list*, stack `flags`, **`ret 4`**, EAX=this.
- Only **bit 0** of flags tested → free. No array-delete (`flags&2`) path.
- No direct call-site callers; invoked virtually as `(*vtbl)(list, 1)` / placement without free uses flags=0.

## Pseudocode (annotated)

```c
// __thiscall  RET 4  → EAX = this
void *ThreadSafeObjectList_ScalarDeletingDtor(ThreadSafeObjectList *this /*ECX*/, uint8_t flags)
{
  ThreadSafeObjectList_Dtor(this);       // FUN_004bcbf0 — drain + dual DeleteCS
  if ((flags & 1) != 0) {
    operator_delete(this);               // heap free only when bit0 set
  }
  return this;
}
```

## Related family

| VA | Role |
|---|---|
| `0x004bcbf0` | complete dtor body (no free) |
| `0x0040b020` | PopFront |
| `0x004bcc40` | **this** — scalar deleting wrapper |

## Open questions

- Product / PDB mangled name on this VA.
- Runtime / bit-exact free path.
