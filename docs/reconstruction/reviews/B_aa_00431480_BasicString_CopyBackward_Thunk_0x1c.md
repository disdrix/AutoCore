# Review B (skeptical / adversarial): `aa_00431480` BasicString_CopyBackward_Thunk_0x1c

| Field | Value |
|---|---|
| **Stable ID** | `aa_00431480` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00431480_BasicString_CopyBackward_Thunk_0x1c.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Full copy_backward algorithm lives here | **Falsified** — 29 B trampoline only; work in `00431790` |
| 2 | Public ABI is 4-arg thiscall | **Weakened** — sole call site pushes 3; ECX unset; treat as cdecl 3-arg |
| 3 | Forward `std::copy` | **Falsified** — callee walks `last`/`dest` **backward** by `0x1c` |
| 4 | POD `memmove` | **Falsified** — string `operator=` per element |
| 5 | Multi-purpose export | **Weak** — single parent xref (insert mid) |
| 6 | Return value of `00431790` used | **Falsified** — discarded; void at call site |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Thunk identity | High | Invent logic in wrong VA |
| Overlap-safe reverse assign role | High | Mid-insert corruption |
| Call-site 3-arg cdecl | High | Wrong stack cleanup |
| Nested free helper details | Medium | Missed edge of empty range (callee handles) |
| Product plate | Low | Name drift |

---

## 3. Cross-check

```
Parent mid path:
  00431430 move tail count beyond end
  00431480(where, end-count, old_end)  // this thunk
  00431450(where, where+count, value)  // fill hole
Sibling 00431430 is same "member-shaped trampoline" pattern.
Callee empty: first==last → return dest_end; no assigns.
```

---

## 4. Surviving contract for AutoCore

```
BasicString_CopyBackward_Thunk_0x1c(first, last, dest_end):
  copy_backward [first, last) into ending at dest_end
  // implement via FUN_00431790 or equivalent reverse assign loop, stride 0x1c
```

Porting insert mid-shift **must** use reverse assign (not forward) for the overlapping middle.

---

## 5. Open questions

1. Dual ownership of `FUN_00431790`.
2. Product demangle.

**Verdict:** **accept-with-gaps**
