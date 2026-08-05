# Review B (skeptical / adversarial): `_com_issue_error` @ `0x00717f00`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00717f00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00717f00__com_issue_error.md` |
| **Verdict** | **accept** as CRT COM wrapper; **reject** treating as game-owned error policy |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Custom AutoAssault error reporter | **Falsified** — MSVC library single-match `_com_issue_error` |
| 2 | Attaches `IErrorInfo` | **Falsified** — always `push 0` second arg |
| 3 | `__cdecl` / thiscall | **Falsified** — `ret 4` stdcall |
| 4 | Returns HRESULT to caller | **Falsified** — void; raise path (no return value use) |
| 5 | Direct call to fixed absolute | **Falsified** — **indirect** via `[00af8b20]` (mutable function pointer slot) |
| 6 | Slot is always `007181c0` at runtime after patch | **Open** — static image yes; runtime hook possible |
| 7 | Safe to reimplement differently in AutoCore | **Survives as policy** — client-only COM; server need not port |
| 8 | Clean invents body | **Falsified** — 19-byte match |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Byte-level wrapper CF | **Confirmed** | Low |
| Library identity | **Confirmed** | Mis-port as game logic wastes effort |
| Raise semantics of callee | **Medium** | Exact exception type not sealed here |
| IAT-style mutability of PTR | **High** (exists) | Hooks could redirect |

---

## 3. Surviving contract

```
// MSVC COM support — not game domain
void __stdcall _com_issue_error(long hr) {
  (*PTR_FUN_00af8b20)(hr, /*IErrorInfo*/ nullptr);
}
// sibling: _com_issue_errorex @ 0x00717f20 may attach IErrorInfo
```

**Verdict:** **accept** sealed wrapper; exclude from game logic port priority.
