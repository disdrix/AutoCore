# Review B (skeptical / adversarial): `_variant_t::_variant_t(long, ushort)` @ `0x00718130`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00718130` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00718130__variant_t.md` |
| **Verdict** | **accept** as CRT COM ctor; **reject** treating as game-owned variant policy |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Custom AutoAssault VARIANT builder | **Falsified** — MSVC library single-match `_variant_t` |
| 2 | Accepts arbitrary `VARTYPE` | **Falsified** — only `3` / `10` / `0xb`; else raise |
| 3 | VT_BOOL stores `1` for true | **Falsified** — `neg`/`sbb` yields `0` or `0xFFFFFFFF`, stores **AX** → `0xFFFF` (`VARIANT_TRUE`) |
| 4 | HRESULT is `DISP_E_TYPEMISMATCH` (`0x80020005`) | **Falsified** — imm is **`0x80070057`** (`E_INVALIDARG`) |
| 5 | `__stdcall` / `__cdecl` | **Falsified** — `this` in ECX; `ret 8` thiscall |
| 6 | Value field at `this+4` | **Falsified** — payload stores at **`this+8`** (standard VARIANT layout after `vt` + reserved) |
| 7 | Clean invents branches | **Falsified** — three-rep raw/clean/live match |
| 8 | Must reimplement for server port | **Survives as policy** — client COM only; exclude from game port priority |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Byte-level CF / VT set | **Confirmed** | Low |
| Library identity | **Confirmed** | Mis-port as game logic wastes effort |
| Exact VARIANT reserved-word zeroing | **Medium** | ctor only writes `vt` + payload@+8; does not zero wReserved* (matches typical MSVC debug `_variant_t` for these overloads) |
| Raise never returns | **High** (policy of `_com_issue_error`) | Exception/longjmp path owned by raise dual |

---

## 3. Surviving contract

```cpp
// MSVC COM support — not game domain
// thiscall; stack: (long value, unsigned short vt); ret 8
_variant_t* _variant_t::_variant_t(long value, unsigned short vt) {
  if (vt != VT_I4 && vt != VT_ERROR && vt != VT_BOOL) {
    _com_issue_error(E_INVALIDARG); // 0x80070057 → 0x00717f00
  }
  if (vt == VT_ERROR) { this->vt = 10; this->scode = value; }
  else if (vt == VT_BOOL) {
    this->vt = 11;
    this->boolVal = (value != 0) ? VARIANT_TRUE /*0xFFFF*/ : VARIANT_FALSE;
  } else { // VT_I4
    this->vt = 3; this->lVal = value;
  }
  return this;
}
```

**Verdict:** **accept** sealed library ctor; exclude from game-logic port priority.
