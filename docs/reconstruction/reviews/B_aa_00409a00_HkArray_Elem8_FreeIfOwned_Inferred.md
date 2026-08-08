# Review B (skeptical / adversarial): `aa_00409a00` HkArray_Elem8_FreeIfOwned_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409a00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (WQ9J-J) |
| **Counterpart** | `reviews/A_aa_00409a00_HkArray_Elem8_FreeIfOwned_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory + analyze + disassemble_function (no disassemble_bytes).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Full worklist release (arena slab + free) like `0055f4c0` | **Falsified** — no `param_1[3]/[4]` slab math; free-only leaf |
| 2 | Element size 4 / 16 (`*4` / `<<4`) | **Falsified** — three `ADD EAX,EAX` → **`*8`** |
| 3 | Free uses raw capacity without mask | **Falsified** — machine `AND 0x7FFFFFFF` (decomp lies) |
| 4 | stdcall / stack args for array | **Falsified** — **thiscall ECX**, plain `RET` |
| 5 | Always frees (ignores high-bit sentinel) | **Falsified** — `JS` skip when capacity signed `< 0` |
| 6 | Tag other than `0x12` | **Falsified** — `PUSH 0x12` |
| 7 | Direct application call graph (not SEH) | **Falsified** — only unwind JMPs |
| 8 | Allocates (`vtbl+0x10`) | **Falsified** — only free `+0x14` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Free gate + mask + *8 | **High** | heap corruption |
| plain RET thiscall | **High** | stack smash if ret-n assumed |
| SEH dtor role | **High** | wrong placement in cleanup |
| Product type English | Medium | naming only |

---

## 3. Cross-check

```
LocalWorklist_Release 0055f4c0:
  arena return / vtbl+0x28
  + if cap>=0: free(*data, (cap&0x7fffffff)*8, tag 0x12)

HkArray_Elem8_FreeIfOwned 00409a00:
  free half only (same mask/*8/tag)
```

Do **not** merge with stride-16 release `0055f590` (`<<4`) or alloc paths.

---

## 4. Surviving contract for AutoCore

```csharp
void FreeIfOwned_Elem8(ArrayTriple* a)
{
    if ((int)a->capacity >= 0)
        Allocator.TaggedFree(a->data, (a->capacity & 0x7fffffff) * 8, tag: 0x12);
}
```

---

## 5. Open questions

1. Product allocator name for `DAT_00b05060`.  
2. Which stack types use this SEH dtor (elem size 8 evidence only).  
3. Runtime golden (optional).
