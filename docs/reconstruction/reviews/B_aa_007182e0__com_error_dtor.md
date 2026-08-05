# Review B (skeptical / adversarial): `_com_error::~_com_error` @ `0x007182e0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_007182e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007182e0__com_error_dtor.md` |
| **Verdict** | **accept** as CRT COM dtor; **reject** as game-owned cleanup policy |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Game custom COM error teardown | **Falsified** — MSVC library single-match `~_com_error` |
| 2 | Calls AddRef in dtor | **Falsified** — `vtbl+8` is **Release** (not +4) |
| 3 | Uses `SysFreeString` / `CoTaskMemFree` for `+0xC` | **Falsified** — **`LocalFree`** via IAT `[009c6180]` |
| 4 | Always frees both fields (no null checks) | **Falsified** — dual null gates before Release / LocalFree |
| 5 | This function also `delete this` | **Falsified** — plain `ret`; deleting path is separate (`0071825a` caller) |
| 6 | `__stdcall ret 4` | **Falsified** — `C3` thiscall dtor |
| 7 | Clean invents LocalFree | **Falsified** — three-rep + IAT bytes |
| 8 | Must port for server | **Survives as policy** — client COM only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Byte-level Release + LocalFree CF | **Confirmed** | Low |
| Library identity | **Confirmed** | Mis-port waste |
| IAT target is kernel32 `LocalFree` | **High** | static image IAT; runtime hook possible |
| Pairing of msg allocator | **Medium** | assumed `LocalAlloc`/FormatMessage family; not this VA |

---

## 3. Surviving contract

```cpp
// MSVC COM support — not game domain
// thiscall; no stack args; ret
void _com_error::~_com_error() {
  *(void**)this = &PTR_FUN_00a14034;
  if (*(IErrorInfo**)(this + 8) != nullptr)
    (*(IErrorInfo**)(this + 8))->Release(); // vtbl+8
  if (*(void**)(this + 0xC) != nullptr)
    LocalFree(*(HLOCAL*)(this + 0xC));
}
```

**Verdict:** **accept** sealed library dtor; exclude from game-logic port priority.
