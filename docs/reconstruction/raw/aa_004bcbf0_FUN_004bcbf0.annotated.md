# Annotated low-level: ThreadSafeObjectList_Dtor (`FUN_004bcbf0`)

| Field | Value |
|---|---|
| Stable ID | `aa_004bcbf0` |
| VA | `0x004bcbf0`–`0x004bcc31` |
| Ghidra name | `FUN_004bcbf0` |
| Structural name | `ThreadSafeObjectList_Dtor` (**Inferred**) |
| System | client::util / lock-protected object list |
| Date | 2026-07-29 (W25-C OWN dual; prior scaffold 2026-07-23) |
| Evidence | `decompile_function` + `read_memory` + `analyze_function_complete` (no `disassemble_bytes`) |

---

## Machine-level notes

- `mov esi, ecx` → **this** = list*; **no stack formals**; epilogue **`ret`** (`C3`).
- First store: `*this = PTR_FUN_009cb368` (list vtbl; slot0 = `FUN_004bcc40` scalar-deleting wrapper).
- Drain loop uses sealed `ThreadSafeObjectList_PopFront` (`aa_0040b020`): each iteration returns **payload\*** (node already deleted inside PopFront).
- On each payload: `(*payload->vtbl)(payload, 1)` — MSVC deleting dtor for the **owned object**, not the list node.
- After empty: force `count = 0` at `+0x0C`; `DeleteCriticalSection(+0x10)` then `DeleteCriticalSection(+0x28)` (inner then outer; outer via `add esi, 0x28` after first delete).
- Layout sealed with PopFront twin: head+4 / tail+8 / count+0xC / CS+0x10 / CS+0x28.
- Callers: direct dtor use from skill multi-target list (`FUN_0058c850`), list helpers, and scalar-deleting `FUN_004bcc40`.

---

## Pseudocode (annotated)

```c
// __thiscall / __fastcall  ECX = ThreadSafeObjectList*
// returns void
void ThreadSafeObjectList_Dtor(ThreadSafeObjectList *list)
{
  list->vtbl = &PTR_FUN_009cb368;

  void *payload = ThreadSafeObjectList_PopFront(list);  // FUN_0040b020
  while (payload != NULL) {
    // (*payload->vtbl)(payload, 1) — delete owned object
    (*(void (__thiscall **)(void *, int))*(void **)payload)(payload, 1);
    payload = ThreadSafeObjectList_PopFront(list);
  }

  list->count = 0;                          // +0x0C
  DeleteCriticalSection(&list->csInner);    // +0x10
  DeleteCriticalSection(&list->csOuter);    // +0x28
}
```

---

## Control-flow diagram

```
vtbl = PTR_FUN_009cb368
payload = PopFront(list)
while payload:
  payload.dtor_delete(1)
  payload = PopFront(list)
count = 0
DeleteCS(inner +0x10)
DeleteCS(outer +0x28)
ret
```

---

## List layout (shared with PopFront)

| Off | Field |
|----:|-------|
| `+0x00` | vtbl |
| `+0x04` | head |
| `+0x08` | tail |
| `+0x0C` | `LONG` count |
| `+0x10` | `CRITICAL_SECTION` inner |
| `+0x28` | `CRITICAL_SECTION` outer |

---

## Open gaps

1. Product/PDB English class name beyond structural `ThreadSafeObjectList_*`.
2. Payload type varies by list instance (skill targets, mission notify, …) — caller-owned.
3. Runtime / bit-exact image diff deferred.
