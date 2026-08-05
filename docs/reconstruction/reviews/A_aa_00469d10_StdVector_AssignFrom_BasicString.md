# Review A (reconstruction fidelity): `aa_00469d10` StdVector_AssignFrom_BasicString

| Field | Value |
|---|---|
| **Stable ID** | `aa_00469d10` |
| **VA** | `0x00469d10`–`0x00469d96` (**134 B**) |
| **Canonical name** | `StdVector_AssignFrom_BasicString` |
| **Ghidra name** | `FUN_00469d10` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-S) |
| **Counterpart** | `reviews/B_aa_00469d10_StdVector_AssignFrom_BasicString.md` |
| **System** | MSVC `vector<basic_string<char>>` assign-from-src |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (full 134 B) + xrefs. Nested `FUN_00431b30` decompile for buy contract. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Assign **src** string-vector contents into **dest**: measure src size, blank-buy dest capacity, uninit_copy strings, set dest.end, return dest. ECX is **source** (atypical vs classic dest-this operator=).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W34-S append) | `docs/reconstruction/raw/aa_00469d10_FUN_00469d10.md` |
| Annotated | `docs/reconstruction/raw/aa_00469d10_FUN_00469d10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_AssignFrom_BasicString.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00469d10.cpp` |
| Function record | `docs/reconstruction/functions/aa_00469d10_StdVector_AssignFrom_BasicString.md` |
| Callee uninit_copy | W33-G `StdUninitCopy_BasicString` (`0x0046a2c0`) |
| Callee buy | live decompile `FUN_00431b30` |
| Callers | `FUN_009841d0`, `FUN_00984340` (Fs expand, W33-E) |
| Live | decompile ≡ CF; full hex; `C2 04 00` |

---

## 3. Signature (sealed)

```c
// ECX = src*; stack dest*; RET 4; returns dest*
VectorBasicString* __thiscall StdVector_AssignFrom_BasicString(
    VectorBasicString* src,
    VectorBasicString* dest);
```

| Formal | Source | Conf |
|---|---|---|
| src | ECX (`8B F1`) | **High** |
| dest | `[ebp+8]` (`8B 7D 08`) | **High** |
| buy this = dest | `8B CF` before call | **High** |
| return dest | `8B C7` | **High** |
| cleanup | `C2 04 00` | **High** |
| stride 0x1c | magic `0x92492493` | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| src size null-safe `/0x1c` | decompile + bytes | **High** |
| `FUN_00431b30(dest, n)` blank-buy | nested decompile | **High** |
| size==0 → buy returns 0, skip copy | nested + branch | **High** |
| uninit_copy + set dest.end | `FUN_0046a2c0` + `89 47 08` | **High** |
| return dest + RET 4 | epilogue | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (134 B) — see raw W34-S append.

Entry: `55 8B EC 6A FF 68 60 DC 9B 00`.  
Epilogue: `8B C7 … C2 04 00`.

---

## 6. Gaps

- Product/MSVC demangle for exact helper name.
- Whether callers always pass empty dest (buy has no free).
- Nested `FUN_00431b30` not dual-owned.
- Runtime / bit-exact / differential.

## 7. Verdict

Fidelity pass seals ABI/CF/string-uninit path against live decompile + full hex + nested buy. Residual product plate + dest lifetime contract → **accept-with-gaps**.
