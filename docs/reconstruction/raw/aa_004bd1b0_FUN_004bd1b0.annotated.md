# Annotated low-level: FUN_004bd1b0 → COList_ScalarDeletingDestructor

| Field | Value |
|---|---|
| Stable ID | `aa_004bd1b0` |
| VA | `0x004bd1b0`–`0x004bd1cd` (**30 B**) |
| System | client / COList |
| Date | 2026-07-29 (W27-L seal; scaffold 2026-07-23) |
| Canonical name | `COList_ScalarDeletingDestructor` |
| Ghidra name | `FUN_004bd1b0` |

## Machine-level notes

- **Role:** MSVC scalar-deleting destructor wrapper for **COList**.
- **Vtbl:** slot 0 of `PTR_FUN_009cb448` (`0x009cb448` → `0x004bd1b0`). Product class sealed via adjacent rdata **`COList::Insert`** (W26-J twin on body `FUN_004bbc70`).
- **Body dtor:** always calls `FUN_004bbc70` / `COList_Destructor` on `this` (ECX→ESI).
- **Heap free:** if `(flags & 1) != 0`, `operator_delete(this)` then return `this`; else skip free and return `this`.
- **ABI:** `__thiscall`; one stack formal (flags); **`ret 4`** (`C2 04 00`).
- **Callees:** `COList_Destructor` (`0x004bbc70`), `operator_delete`.
- **Callers / xrefs:** vtbl DATA only (no direct CALL sites in code — virtual dispatch).
- **Ctor twin:** `FUN_004bbfb0` / `COList_Constructor` (same vtbl; `Client_InitInstance` → `DAT_00b04830`).
- Prefer raw + `read_memory` when decompiler conflicts. Decompiler `/* does not return */` on `operator_delete` is a Ghidra artifact (delete returns after free in normal MSVC CRT; wrapper still returns `this` on the non-delete path).

## Pseudocode (annotated)

```c
// __thiscall; ECX = this (COList*); stack: byte flags; ret 4; returns this*
void* __thiscall COList_ScalarDeletingDestructor(void* this_ptr, uint8_t flags)
{
  // ESI = this
  COList_Destructor(/*this*/);           // FUN_004bbc70 — full body dtor
  if ((flags & 1) != 0) {
    operator_delete(this_ptr);           // heap free when scalar-delete flag set
  }
  return this_ptr;                       // EAX = this (standard MSVC scalar dtor)
}
```

## Sealed layout linkage (from ctor / dtor twins)

| Item | Evidence |
|---|---|
| Class | COList (`PTR_FUN_009cb448`, rdata `COList::Insert`) |
| sizeof | `0x58` (`operator_new(0x58)` at InitInstance call site) |
| Body dtor | `aa_004bbc70` dual **accept** (W26-J) |
| Ctor | `aa_004bbfb0` (this wave) |

## Open questions

- Product English for every COList field (shared with ctor/body dtor).
- Runtime / bit-exact verification open.
