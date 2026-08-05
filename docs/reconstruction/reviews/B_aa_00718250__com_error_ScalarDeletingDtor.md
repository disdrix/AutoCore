# Review B (skeptical / adversarial): `_com_error_ScalarDeletingDtor` @ `0x00718250`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00718250` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Agent** | W25-P OWN-ONLY |
| **Counterpart** | `reviews/A_aa_00718250__com_error_ScalarDeletingDtor.md` |
| **Verdict** | **accept** as CRT COM deleting dtor; **reject** as game-owned teardown |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Game custom COM free policy (own heap API) | **Falsified** — standard MSVC deleting-dtor shape + CRT `operator_delete` |
| 2 | This VA implements Release / LocalFree | **Falsified** — only calls body dtor `007182e0`; resources handled there |
| 3 | Always deletes object storage | **Falsified** — gated on `(flags & 1)` |
| 4 | `operator_delete` never returns (decomp WARNING) | **Falsified as control-flow claim** — bytes after call set EAX and `ret 4` |
| 5 | `__cdecl` / plain `ret` | **Falsified** — `C2 04 00` thiscall + stack flags |
| 6 | Vector deleting (array count) present | **Falsified** — no `flags & 2` / no array loop |
| 7 | Vftable points elsewhere | **Falsified** — `[00a14034] == 00718250` |
| 8 | Must port for AutoCore server | **Survives as policy reject** — client CRT COM only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Byte-level CF (dtor → optional delete → return this) | **Confirmed** | Low |
| Library identity | **Confirmed** | Mis-port waste |
| Flags bit0 semantics | **Confirmed** | Double-free / leak if inverted |
| Body dtor resource policy | **High** (sibling dual) | Not this VA |

---

## 3. Surviving contract

```cpp
// MSVC COM support — not game domain
// thiscall; 1 stack arg; ret 4; returns this
_com_error *_com_error_ScalarDeletingDtor(_com_error *self, unsigned flags) {
  self->~_com_error();           // 0x007182e0
  if (flags & 1)
    operator_delete(self);
  return self;
}
```

**Port rules:**

1. **Do not** re-implement COM error policy in server ports.
2. **Do not** merge this with body dtor `007182e0` (different ownership of delete).
3. Keep bit0 gate when matching client `delete` of `_com_error` objects.

---

## 4. Open questions

1. Exact CRT plate on this leaf (siblings: VS2003 Debug for body dtor).
2. Live hook of `operator_delete` — out of static seal.

**Verdict:** **accept** sealed library deleting dtor; exclude from game-logic port priority.
