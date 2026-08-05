# Review B (skeptical / adversarial): `aa_00575c00` Object_009d33c4_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00575c00` |
| **VA** | `0x00575c00` |
| **Canonical name** | `Object_009d33c4_ScalarDeletingDtor` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Adversarial / gap-hunt (OWN-ONLY W29-H) |
| **Counterpart** | `reviews/A_aa_00575c00_Object_009d33c4_ScalarDeletingDtor.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Outcome |
|---|---|
| This IS the complete dtor? | **Rejected.** Body only calls `FUN_00575350` then optional free; complete work lives in callee (W28-M). |
| Vector deleting dtor? | **Rejected.** No `flags & 2` / no array loop; classic scalar pattern only. |
| `operator_delete` truly noreturn? | **Rejected.** Bytes fall through: `8B C6 5E C2 04 00` after call. Ghidra warning is false. |
| Wrong vtbl family? | **Rejected.** `read_memory(0x009d33c4)` LE dword = `0x00575c00`; same vtbl used by ctor/complete dtor. |
| Missing code callers means dead? | **Rejected.** Dispatched via virtual delete; data xref from vtbl is the install site. |
| `__stdcall` not thiscall? | **Rejected.** ECX = this (`8B F1`); stack only carries flags; hybrid thiscall+`RET 4` is standard MSVC scalar deleting. |

---

## Residual risks

1. Product type English / demangle.
2. No live virtual-delete trace in this dual (static seal only).
3. Interaction with custom allocators — `operator_delete` is CRT symbol as decompiled.

---

## Port cautions

```
// OK
Object_009d33c4_ScalarDeletingDtor(obj, 1);  // destroy + free
Object_009d33c4_ScalarDeletingDtor(obj, 0);  // destroy only

// BAD: call this instead of complete dtor when storage is not heap
// BAD: merge implementation into complete dtor body
// BAD: assume RET (no arg cleanup) — must RET 4
```

---

## Verdict

No CF/ABI falsifier stands. Gaps are product naming / runtime only → **accept-with-gaps**.
