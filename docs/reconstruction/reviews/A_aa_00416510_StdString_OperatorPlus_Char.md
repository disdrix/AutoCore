# Review A (reconstruction fidelity): `aa_00416510` StdString_OperatorPlus_Char

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416510` |
| **VA** | `0x00416510`–`0x00416589` (**122 B**) |
| **Canonical name** | `StdString_OperatorPlus_Char` |
| **Ghidra name** | `FUN_00416510` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-C) |
| **Counterpart** | `reviews/B_aa_00416510_StdString_OperatorPlus_Char.md` |
| **System** | MSVC free `operator+(basic_string const&, char)` |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body + IAT slots) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Free MSVC binary `operator+` for `basic_string` + single char. Copies `lhs` into a temp, appends `rhs` via `operator+=(char)`, copy-constructs into the hidden return object, destroys temp, returns `out*`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W34-C append) | `docs/reconstruction/raw/aa_00416510_FUN_00416510.md` |
| Annotated | `docs/reconstruction/raw/aa_00416510_FUN_00416510.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdString_OperatorPlus_Char.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00416510.cpp` |
| Function record | `docs/reconstruction/functions/aa_00416510_StdString_OperatorPlus_Char.md` |
| Peers | `aa_00416490` Cstr; `aa_00416410` String |
| Live | decompile ≡ scaffold; body hex 122 B; RET `C3`; IAT `+=` slot `0x009c6294`→`0x006eb20c` |

---

## 3. Signature (sealed)

```c
// cdecl; stack out*, lhs*, char rhs; RET plain; returns out*
MsvcBasicString* StdString_OperatorPlus_Char(
    MsvcBasicString* out,
    const MsvcBasicString* lhs,
    char rhs);
```

| Formal | Source | Conf |
|---|---|---|
| out | Stack[0x4]; ESI preserved; EAX return | **High** |
| lhs | Stack[0x8]; first copy-ctor arg | **High** |
| rhs | Stack[0xc]; pushed to `+=char` | **High** |
| epilogue | `ADD ESP,0x2C; C3` | **High** |

---

## 4. Control flow (bytes authority)

```
SEH install LAB_009bc093
tmp = copy_ctor(lhs)          // IAT [0x009c62ec]
tmp += rhs_char               // IAT [0x009c6294]
out = copy_ctor(tmp)          // IAT [0x009c62ec]
~tmp                          // IAT [0x009c62f4]
return out
```

| Stage | Match | Conf |
|---|---|---|
| SEH + EH state 1 around temp | Yes | **High** |
| copy / +=char / copy-out / dtor order | Yes | **High** |
| Body size 122 B | Yes | **High** |
| Twin differs only at += IAT vs 490/410 | Yes | **High** |

---

## 5. Gaps

- Product/MSVC fully demangled free-function plate.
- CRT import symbol names for the three IAT slots (targets sealed).
- Runtime / bit-exact / differential.

---

## 6. Verdict

CF, ABI, SEH, IAT overload, and peer-triple relationship sealed from decompile + full-body hex. Residual demangle/runtime only → **accept-with-gaps**.
