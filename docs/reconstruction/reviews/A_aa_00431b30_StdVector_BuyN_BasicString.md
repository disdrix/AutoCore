# Review A (reconstruction fidelity): `aa_00431b30` StdVector_BuyN_BasicString

| Field | Value |
|---|---|
| **Stable ID** | `aa_00431b30` |
| **VA** | `0x00431b30`–`0x00431b82` (**82 B**) |
| **Canonical name** | `StdVector_BuyN_BasicString` |
| **Ghidra name** | `FUN_00431b30` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-E) |
| **Counterpart** | `reviews/B_aa_00431b30_StdVector_BuyN_BasicString.md` |
| **System** | MSVC `vector<basic_string<char>>` blank capacity buy |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (full 82 B) + xrefs. Nested `FUN_004540b0` decompile for throw plate. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Zero dest vector triad without free; if `n≠0` allocate capacity for **n** 0x1c-byte elements with **size 0** (begin==end); return 0/1. Throws `"vector<T> too long"` when n exceeds `0x9249249`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W37-E append) | `docs/reconstruction/raw/aa_00431b30_FUN_00431b30.md` |
| Annotated | `docs/reconstruction/raw/aa_00431b30_FUN_00431b30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_BuyN_BasicString.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00431b30.cpp` |
| Function record | `docs/reconstruction/functions/aa_00431b30_StdVector_BuyN_BasicString.md` |
| Caller assign | W34-S `StdVector_AssignFrom_BasicString` (`0x00469d10`) |
| Throw plate | live decompile `FUN_004540b0` → `"vector<T> too long"` |
| Live | decompile ≡ CF; full 82 B hex; dual `C2 04 00` |

---

## 3. Signature (sealed)

```c
// ECX = dest*; stack n; RET 4; returns 0 (n==0) or 1 (bought)
uint8_t __thiscall StdVector_BuyN_BasicString(VectorBasicString* dest, uint32_t n);
```

| Formal | Source | Conf |
|---|---|---|
| dest | ECX (`8B F1`) | **High** |
| n | `[esp+4]` (`8B 44 24 04`) | **High** |
| triad zero | `89 4E 04/08/0C` with ECX=0 | **High** |
| no free | no `operator_delete` in body | **High** |
| return 0/1 | `32 C0` / `B0 01` | **High** |
| cleanup | `C2 04 00` (both paths) | **High** |
| stride | `n*0x1c` | **High** |
| max | `cmp 0x09249249` | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| Zero begin/end/capEnd | bytes + decomp | **High** |
| n==0 → return 0 | `75 06` / `32 C0` | **High** |
| n>max → throw noreturn | decomp of `FUN_004540b0` | **High** |
| new(n*0x1c); begin=end=buf; capEnd=buf+n | bytes | **High** |
| return 1 + RET 4 | epilogue | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (82 B) — see raw W37-E append.

Entry: `8B 44 24 04 56 8B F1 33 C9 …`  
Epilogues: `32 C0 5E C2 04 00` and `B0 01 5E C2 04 00`.

---

## 6. Gaps

- Product/MSVC demangle for exact `_Buy` helper name.
- Whether any other call site exists outside static xrefs (only 1 xref sealed).
- Runtime / bit-exact / differential.

## 7. Verdict

Fidelity pass seals ABI/CF/no-free buy/stride/max/throw against live decompile + full hex + nested throw plate. Residual product demangle → **accept-with-gaps**.
