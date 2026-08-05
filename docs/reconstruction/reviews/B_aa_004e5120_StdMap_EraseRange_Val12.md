# Review B (adversarial): `aa_004e5120` StdMap_EraseRange_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e5120` |
| **VA** | `0x004e5120` |
| **Canonical name** | `StdMap_EraseRange_Val12` (**Inferred**) |
| **Review date** | `2026-07-29` (OWN-ONLY dual B — W28-P) |
| **Reviewer role** | Adversarial / disconfirm |
| **Counterpart** | `reviews/A_aa_004e5120_StdMap_EraseRange_Val12.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Not range erase (single erase / list unlink) | **Reject** — half-open `[first,last)` loop + full-range gate; single erase is callee `004e4130` |
| Wrong node layout (isnil@+0x15 / +0x29) | **Reject** — successor uses **`+0x19`**; callee is Val12 erase W27-Q |
| Wrong ABI (`ret 8` / `ret 0x10`) | **Reject** — both exits `c2 0c 00` |
| Multi-caller product API | **Reject** — single xref from `004e7350` only |
| Full path skips free | **Reject** — `call FUN_004e2940` on root before head reset |
| Name overclaim (exact MSVC demangle) | **Gap** — role High; product symbol open → name remains Inferred |

---

## Residual risks

- `FUN_004e2940` decompiler may under-state left recursion; free role still sealed by isnil gate + call site.
- Mapped value type beyond Val12 size family not recovered from this VA alone.
- No runtime trace of sole caller destroy path.

---

## Decision

Fidelity review A stands. No CF or ABI contradiction from adversarial pass.

**Verdict:** **accept-with-gaps**
