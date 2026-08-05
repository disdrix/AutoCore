# Review A (reconstruction fidelity): `aa_007181f0` `_com_error::_com_error(long, IErrorInfo*, bool)`

| Field | Value |
|---|---|
| **Stable ID** | `aa_007181f0` |
| **VA** | `0x007181f0` |
| **Canonical name** | `_com_error::_com_error(long, IErrorInfo*, bool)` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007181f0__com_error.md` |
| **System** | `crt-com` / MSVC COM support (`comdef` / `_com_error`) |
| **Live tools** | Ghidra `batch_decompile` + `read_memory` + `get_function_by_address` + xrefs |
| **Verdict** | **accept** (library ctor sealed; not game logic) |

---

## 1. Purpose

MSVC `_com_error` primary constructor:

1. Install vftable `PTR_FUN_00a14034` at `this+0`
2. Store HRESULT at `this+4`
3. Store `IErrorInfo*` at `this+8`
4. Zero description buffer pointer at `this+0xC`
5. If `IErrorInfo* != NULL` **and** `bool fAddRef` → call `IErrorInfo::AddRef` via `vtbl+4`

Ghidra library match: **Visual Studio 2003 Debug**  
`public: __thiscall _com_error::_com_error(long, struct IErrorInfo *, bool)`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007181f0_FUN_007181f0.md` |
| Annotated | `docs/reconstruction/raw/aa_007181f0_FUN_007181f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_007181f0.cpp` |
| Function record | `docs/reconstruction/functions/aa_007181f0_FUN_007181f0.md` |
| Live decompile | Ghidra name `_com_error` (3-arg ctor) |
| Vftable | `PTR_FUN_00a14034` → first slot `0x00718250` (scalar/deleting path; OWN sibling) |

---

## 3. Seal: body bytes + CF (High)

Body range: **`007181f0`–`00718247`**.

`read_memory` @ `0x007181f0`:

```
55 8B EC 51 89 4D FC          ; prologue; this → [ebp-4]
8B 45 FC C7 00 34 40 A1 00    ; *this = &PTR_FUN_00a14034  (imm 00a14034)
8B 4D FC 8B 55 08 89 51 04    ; this+4 = hr ([ebp+8])
8B 45 FC 8B 4D 0C 89 48 08    ; this+8 = IErrorInfo* ([ebp+0xC])
8B 55 FC C7 42 0C 00 00 00 00 ; this+0xC = 0
8B 45 FC 83 78 08 00 74 1A    ; if (this+8 == 0) skip AddRef
0F B6 4D 10 85 C9 74 12       ; if (!bool [ebp+0x10]) skip
… 52 FF 50 04                 ; push this_errinfo; call [vtbl+4] = AddRef
8B 45 FC 8B E5 5D C2 0C 00    ; return this; ret 0xC (3 stack args)
; pad CC… → next function
```

Hex (body through `ret 0xC`):

```
558bec51894dfc8b45fcc7003440a1008b4dfc8b55088951048b45fc8b4d0c8948088b55fcc7420c00000000
8b45fc83780800741a0fb64d1085c974128b55fc8b42088b4dfc8b51088b0052ff50048b45fc8be55dc20c00
```

| Claim | Evidence | Conf |
|---|---|---|
| Library single-match 3-arg `_com_error` ctor | Ghidra plate | **Confirmed** |
| Layout: vtbl@0, hr@+4, IErrorInfo*@+8, pszMsg@+0xC | stores | **High** |
| vftable imm `00a14034` | `C7 00 34 40 A1 00` | **High** |
| AddRef only if **both** non-null errinfo **and** `bool` true | dual branches | **High** |
| AddRef = COM `vtbl+4` (after QueryInterface @+0) | `FF 50 04` | **High** |
| `__thiscall`; `ret 0xC` (long + ptr + bool stack) | epilogue | **High** |
| `bool` zero-extended from `[ebp+0x10]` | `0F B6 4D 10` | **High** |
| Clean ≡ raw ≡ live | three-rep | **High** |
| Not game domain | CRT COM | **Confirmed** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Name / signature | **Confirmed** | library + bytes |
| Object layout 16 bytes (4 fields) | **High** | sealed stores |
| `fAddRef` polarity (true → AddRef) | **High** | sealed |
| Full English of all vftable slots | **Probable** | slot0 @ `00718250`; dtor @ `007182e0` dualed separately |
| Port for server | **N/A** | client COM |

---

## 5. Callers (sample)

`get_bulk_xrefs` → call from **`0x007181d3`** (inside raise helper cluster near `FUN_007181c0`). Typical `_com_raise_error` / throw path — not mission/skill game CF.

---

## 6. Gaps

1. Full dual of raise body `FUN_007181c0` (out of unit).
2. Runtime / bit-exact deferred.
3. Product string of description buffer format (owned by `ErrorMessage` path, not this ctor).

**Verdict:** **accept** — sealed MSVC `_com_error(hr, IErrorInfo*, bool)` ctor; dual complete for OWN unit.
