# Annotated low-level: operator_delete_array (`operator delete[]`)

| Field | Value |
|---|---|
| Stable ID | `aa_0048981c` |
| VA | `0x0048981c`–`0x00489821` inclusive (**6 B**) |
| Ghidra name | `operator_delete[]` |
| Canonical name | `operator_delete_array` |
| Alias (Ghidra decomp) | `operator_delete__` |
| System | inventory-transfer (partition seed); **CRT universal** |
| Wave | R10-010 OWN-ONLY dual (2026-08-05) |
| Classification | **IAT thunk** |

---

## Machine-level notes

- Source: raw capture `aa_0048981c` + R10-010 live re-verify append.
- Prefer assembly when decompiler conflicts — **this unit is assembly-only** (one instruction).
- **Not** a jumptable. Ghidra warning is a false positive on `FF 25` IAT JMP.
- Sibling **scalar** `operator_delete` @ `0x00489822` uses adjacent IAT `[0x009c6694]` — do **not** merge VAs.
- Callers use **cdecl**: `PUSH ptr; CALL 0x0048981c; ADD ESP,4` — proves the thunk **returns** (not noreturn).
- Parent dual `InventoryGrid_CompleteDtor` `0x005725a0` frees cell array `@+0x28` via this thunk (null-safe).
- CRT implementation body lives in the import target (`0x006ea814` at capture time) — **outside** this VA; dual seals the thunk only.

## Bytes (authoritative)

```
0048981c  FF 25 98 66 9C 00   JMP dword ptr [0x009c6698]
```

IAT `0x009c6698` → resolved CRT `operator delete[]`.

## Pseudocode (annotated — decompiler + corrections)

```c
/* Ghidra decomp shows recursive self-call + jumptable warning.
 * Live bytes: pure IAT tail-JMP. */

void __cdecl operator_delete_array(void *block)
{
  /* JMP [IAT operator_delete[]] — MSVC CRT array free.
   * Handles new[] cookie / array form; not dualed here. */
  ((void (__cdecl *)(void *)) *IAT_operator_delete_array)(block);
  /* no fall-through in image; JMP does not return to this VA */
}
```

## ABI

| Item | Value |
|---|---|
| Convention | `__cdecl` |
| Arg0 | `void *` — pointer returned by `operator new[]` / array alloc |
| Return | void (via CRT) |
| Stack cleanup | caller (`ADD ESP,4` after CALL) |
| ECX/this | unused |

## Open questions

- None on thunk CF/ABI.
- Product CRT version / exact MSVC `operator delete[]` variant is external (runtime open; terminal false).
- Whether any site passes non-array blocks is a **caller** contract issue, not this VA.

## Related

| VA | Name | Relation |
|---|---|---|
| `0x00489822` | `operator_delete` | scalar sibling IAT thunk |
| `0x00489892` | `operator_new` | alloc family (R10-002) |
| `0x005725a0` | `InventoryGrid_CompleteDtor` | parent dual seed caller |
| `0x00570720` | `InventoryGrid_AllocateCellArray_Inferred` | realloc path CALL sample |
