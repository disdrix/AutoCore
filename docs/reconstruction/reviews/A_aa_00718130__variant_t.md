# Review A (reconstruction fidelity): `aa_00718130` `_variant_t::_variant_t(long, unsigned short)`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00718130` |
| **VA** | `0x00718130` |
| **Canonical name** | `_variant_t::_variant_t(long, unsigned short)` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00718130__variant_t.md` |
| **System** | `crt-com` / MSVC COM support (`comutil` / `_variant_t`) |
| **Live tools** | Ghidra `batch_decompile` / `decompile_function` + `read_memory` + `get_function_by_address` + xrefs |
| **Verdict** | **accept** (library ctor sealed; not game logic) |

---

## 1. Purpose

MSVC `_variant_t` constructor that builds a `VARIANT`/`_variant_t` from a `long` payload and a `VARTYPE` (`unsigned short`). Only three VTs are legal:

| VT | Value | Behavior |
|---|---|---|
| `VT_I4` | `3` | `vt=3`; `lVal` @ `this+8` = `param_1` |
| `VT_ERROR` | `10` | `vt=10`; `scode` @ `this+8` = `param_1` |
| `VT_BOOL` | `0xb` (11) | `vt=11`; `boolVal` @ `this+8` = `VARIANT_TRUE` (`0xFFFF`) if `param_1 != 0`, else `0` |

Any other VT → `_com_issue_error(E_INVALIDARG)` (`0x80070057` / `-0x7ff8ffa9`).

Ghidra library match: **Visual Studio 2003/2005 Debug** `public: __thiscall _variant_t::_variant_t(long, unsigned short)`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00718130_FUN_00718130.md` |
| Annotated | `docs/reconstruction/raw/aa_00718130_FUN_00718130.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00718130.cpp` |
| Function record | `docs/reconstruction/functions/aa_00718130_FUN_00718130.md` |
| Live decompile | Ghidra name `_variant_t`, single-match plate |
| Callee | `_com_issue_error` @ `0x00717f00` (OWN sibling dual) |

---

## 3. Seal: body bytes + CF (High)

`get_function_by_address`: body **`00718130`–`007181b4`** (inclusive end metadata; last insn `ret 8`).

`read_memory` @ `0x00718130` (key sites):

| Site | Bytes | Meaning |
|---|---|---|
| Prologue | `55 8B EC 51 89 4D FC` | `push ebp; mov ebp,esp; push ecx; mov [ebp-4], this` |
| Gate VT∈{3,10,11} | `0F B7 … 83 F8 03 / 83 F9 0A / 83 FA 0B` | zero-extend `ushort` arg @ `[ebp+0xC]` |
| Invalid | `68 57 00 07 80` + `E8 A4 FD FF FF` | `push 0x80070057`; `call 0x00717f00` (`_com_issue_error`) |
| VT_ERROR | `66 C7 01 0A 00` … `89 42 08` | `*(u16*)this=10`; `*(i32*)(this+8)=param_1` |
| VT_BOOL | `66 C7 02 0B 00` + `F7 D8 1B C0` + `66 89 41 08` | `vt=11`; `neg/sbb` → `0`/`-1`; store `ax` as `VARIANT_BOOL` |
| VT_I4 (else) | `66 C7 02 03 00` … `89 48 08` | `vt=3`; `lVal=param_1` |
| Epilogue | `8B E5 5D C2 08 00` | `mov esp,ebp; pop ebp; ret 8` (**thiscall**, 2 stack args = 8 bytes) |

Hex (body through `ret 8`, then `CC` pad):

```
558bec51894dfc0fb7450c83f803741e0fb74d0c83f90a74150fb7550c83fa0b740c6857000780e8a4fdffffeb4e
0fb7450c83f80a75138b4dfc66c7010a008b55fc8b4508894208eb320fb74d0c83f90b75188b55fc66c7020b00
8b4508f7d81bc08b4dfc66894108eb118b55fc66c70203008b45fc8b4d088948088b45fc8be55dc20800
```

| Claim | Evidence | Conf |
|---|---|---|
| Library single-match `_variant_t(long, ushort)` | Ghidra plate | **Confirmed** |
| Only VT 3 / 10 / 11 accepted | decompile + imm compares | **High** |
| `E_INVALIDARG` = `0x80070057` | `push 0x80070057` imm | **High** |
| Raise via `_com_issue_error` @ `0x00717f00` | rel32 decode | **High** |
| VT_BOOL uses full `VARIANT_BOOL` (`0`/`0xFFFF`) | `neg`/`sbb`/`mov [this+8],ax` | **High** |
| `vt` at `this+0` (`u16`); value union at `this+8` | stores | **High** |
| `__thiscall`; stack cleanup `ret 8` | epilogue | **High** |
| Clean ≡ raw ≡ live decompile | three-rep 2026-07-29 | **High** |
| Not AutoAssault game domain | CRT COM helper | **Confirmed** |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Name / signature | **Confirmed** | library single-match + bytes |
| VT filter set {3,10,11} | **High** | sealed |
| Layout (`vt`@0, payload@+8) | **High** | matches `VARIANT`/`_variant_t` |
| Invalid path is fatal raise (no return on success path after raise) | **High** | `_com_issue_error` semantics owned by sibling dual |
| Port needed for AutoCore server | **N/A** | client COM only |

---

## 5. Callers (sample)

`get_bulk_xrefs` → one static call site `0x009c2ecf` (UNCONDITIONAL_CALL). Not game mission/skill logic; COM/`_variant_t` construction path.

---

## 6. Gaps

1. Full English of every retail caller of this ctor (out of unit / low value).
2. Runtime / bit-exact deferred.
3. Sibling `_variant_t` overloads (other VAs) not dualed here.

**Verdict:** **accept** — sealed MSVC `_variant_t(long, unsigned short)` library ctor; dual complete for OWN unit.
