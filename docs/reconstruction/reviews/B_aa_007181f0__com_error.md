# Review B (skeptical / adversarial): `_com_error(long, IErrorInfo*, bool)` @ `0x007181f0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_007181f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007181f0__com_error.md` |
| **Verdict** | **accept** as CRT COM ctor; **reject** treating as game exception policy |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | AutoAssault custom error object | **Falsified** — MSVC library single-match `_com_error` |
| 2 | Always AddRefs `IErrorInfo` | **Falsified** — gated on **non-null and** `bool param_3` |
| 3 | Always AddRefs when non-null (ignores bool) | **Falsified** — `0F B6 4D 10` / `test ecx,ecx` skip |
| 4 | Calls `Release` in ctor | **Falsified** — only `vtbl+4` (AddRef); Release is dtor `vtbl+8` |
| 5 | Copies description string into `+0xC` | **Falsified** — forces **`this+0xC = 0`** |
| 6 | `__cdecl` / no stack cleanup | **Falsified** — `ret 0xC` thiscall |
| 7 | Vftable is game RTTI | **Falsified** — fixed imm `PTR_FUN_00a14034` in COM support image |
| 8 | Must port for AutoCore sector/auth | **Survives as policy** — client COM only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Byte-level field stores + AddRef gate | **Confirmed** | Low |
| Library identity | **Confirmed** | Mis-port waste |
| Exact MSVC `_com_error` size / packing | **High** | 16-byte object matches stores through +0xC |
| Whether `bool` is 1-byte or 4-byte on stack | **High** (reads as byte) | stack slot still 4-byte aligned; `ret 0xC` includes it |

---

## 3. Surviving contract

```cpp
// MSVC COM support — not game domain
// thiscall; stack (hr, IErrorInfo*, bool fAddRef); ret 0xC
_com_error* _com_error::_com_error(HRESULT hr, IErrorInfo* info, bool fAddRef) {
  *(void**)this = &PTR_FUN_00a14034; // _com_error vftable
  *(HRESULT*)(this + 4) = hr;
  *(IErrorInfo**)(this + 8) = info;
  *(void**)(this + 0xC) = nullptr;   // m_pszMsg
  if (info != nullptr && fAddRef)
    info->AddRef();                  // vtbl+4
  return this;
}
```

**Verdict:** **accept** sealed library ctor; exclude from game-logic port priority.
