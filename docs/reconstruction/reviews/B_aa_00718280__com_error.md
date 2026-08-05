# Review B (skeptical / adversarial): `_com_error(const _com_error&)` @ `0x00718280`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00718280` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00718280__com_error.md` |
| **Verdict** | **accept** as CRT COM copy ctor; **reject** as game-owned clone helper |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Game-specific error copy | **Falsified** — MSVC library single-match |
| 2 | Deep-copies `m_pszMsg` string | **Falsified** — forces `this+0xC = 0`; other’s msg not shared |
| 3 | Same AddRef gate as primary ctor (`bool`) | **Falsified** — **no** bool; AddRef whenever errinfo ≠ null |
| 4 | Copies vftable pointer from source object | **Falsified** — installs **literal** `PTR_FUN_00a14034` (not `*other`) |
| 5 | Dead / unreachable (0 xrefs ⇒ unused) | **Survives as risk only** — EH/copy elision may omit static edges; body still present + library-named |
| 6 | `ret 0` / dtor-like ABI | **Falsified** — `ret 4` one stack arg |
| 7 | Clean invents AddRef | **Falsified** — three-rep + `FF 51 04` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Byte-level copy CF | **Confirmed** | Low |
| Library identity | **Confirmed** | Mis-port waste |
| Caller graph completeness | **Medium** | static xref empty; EH may still call |
| Msg buffer ownership post-copy | **High** | each instance rebuilds description on demand |

---

## 3. Surviving contract

```cpp
// MSVC COM support — not game domain
// thiscall; stack (const _com_error& other); ret 4
_com_error* _com_error::_com_error(const _com_error& other) {
  *(void**)this = &PTR_FUN_00a14034;
  *(HRESULT*)(this + 4) = *(HRESULT*)(other + 4);
  *(IErrorInfo**)(this + 8) = *(IErrorInfo**)(other + 8);
  *(void**)(this + 0xC) = nullptr; // do not share m_pszMsg
  if (*(IErrorInfo**)(this + 8) != nullptr)
    (*(IErrorInfo**)(this + 8))->AddRef();
  return this;
}
```

**Verdict:** **accept** sealed library copy ctor; exclude from game-logic port priority.
