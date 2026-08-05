# Review A (reconstruction fidelity): `aa_00718280` `_com_error::_com_error(const _com_error&)`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00718280` |
| **VA** | `0x00718280` |
| **Canonical name** | `_com_error::_com_error(const _com_error&)` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00718280__com_error.md` |
| **System** | `crt-com` / MSVC COM support (`comdef` / `_com_error`) |
| **Live tools** | Ghidra `batch_decompile` + `read_memory` + `get_function_by_address` + xrefs |
| **Verdict** | **accept** (library copy ctor sealed; not game logic) |

---

## 1. Purpose

MSVC `_com_error` **copy constructor**:

1. Install same vftable `PTR_FUN_00a14034` at `this+0`
2. Copy HRESULT from `other+4` → `this+4`
3. Copy `IErrorInfo*` from `other+8` → `this+8`
4. Zero **own** description buffer at `this+0xC` (**does not** share/copy `m_pszMsg`)
5. If copied `IErrorInfo* != NULL` → **unconditional** `AddRef` (`vtbl+4`)

Contrast with primary ctor `0x007181f0`: copy path has **no** `fAddRef` flag — AddRef is mandatory when errinfo present.

Ghidra library match: **Visual Studio 2003 Debug**  
`public: __thiscall _com_error::_com_error(class _com_error const &)`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00718280_FUN_00718280.md` |
| Annotated | `docs/reconstruction/raw/aa_00718280_FUN_00718280.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00718280.cpp` |
| Function record | `docs/reconstruction/functions/aa_00718280_FUN_00718280.md` |
| Live decompile | Ghidra name `_com_error` (copy ctor) |
| Sibling | primary ctor `aa_007181f0`; dtor `aa_007182e0` |

---

## 3. Seal: body bytes + CF (High)

Body range: **`00718280`–`007182d5`**.

`read_memory` @ `0x00718280`:

```
55 8B EC 51 89 4D FC                ; prologue; this → [ebp-4]
8B 45 FC C7 00 34 40 A1 00          ; *this = &PTR_FUN_00a14034
8B 4D FC 8B 55 08 8B 42 04 89 41 04 ; this+4 = other+4 (hr)
8B 4D FC 8B 55 08 8B 42 08 89 41 08 ; this+8 = other+8 (IErrorInfo*)
8B 4D FC C7 41 0C 00 00 00 00       ; this+0xC = 0  (fresh msg ptr)
8B 55 FC 83 7A 08 00 74 12          ; if (this+8 == 0) skip
… 50 FF 51 04                       ; AddRef via vtbl+4
8B 45 FC 8B E5 5D C2 04 00          ; return this; ret 4 (one ref arg)
; CC pad
```

Hex (body through `ret 4`):

```
558bec51894dfc8b45fcc7003440a1008b4dfc8b55088b42048941048b4dfc8b55088b42088941088b4dfc
c7410c000000008b55fc837a080074128b45fc8b48088b55fc8b42088b0950ff51048b45fc8be55dc20400
```

| Claim | Evidence | Conf |
|---|---|---|
| Library single-match copy ctor | Ghidra plate | **Confirmed** |
| Same vftable imm as primary ctor | `C7 00 34 40 A1 00` | **High** |
| hr + IErrorInfo copied; msg ptr **not** copied | stores + zero `+0xC` | **High** |
| AddRef always when errinfo non-null (no bool) | single null check only | **High** |
| `__thiscall`; `ret 4` | epilogue | **High** |
| Clean ≡ raw ≡ live | three-rep | **High** |
| Not game domain | CRT COM | **Confirmed** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Name / signature | **Confirmed** | library + bytes |
| Copy semantics (share IErrorInfo, clone msg later) | **High** | `+0xC` reset; AddRef on interface |
| Distinct from primary ctor AddRef policy | **High** | no `fAddRef` gate |
| Port for server | **N/A** | client COM |

---

## 5. Callers (sample)

`get_bulk_xrefs` → **no direct data-space call xrefs** at snapshot. Expected: C++ exception copy / inlined sites / compiler-generated EH. Absence of static CALL edges does not weaken body seal.

---

## 6. Gaps

1. EH/personality paths that invoke copy ctor (compiler metadata; out of unit).
2. Runtime / bit-exact deferred.

**Verdict:** **accept** — sealed MSVC `_com_error` copy ctor; dual complete for OWN unit.
