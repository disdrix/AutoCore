# Review A (reconstruction fidelity): `aa_00416490` StdString_OperatorPlus_Cstr

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416490` |
| **VA** | `0x00416490`–`0x00416509` (**122 B**) |
| **Canonical name** | `StdString_OperatorPlus_Cstr` |
| **Ghidra name** | `FUN_00416490` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-F) |
| **Counterpart** | `reviews/B_aa_00416490_StdString_OperatorPlus_Cstr.md` |
| **System** | MSVC free `operator+(basic_string const&, char const*)` |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body + IAT slots) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Free MSVC binary `operator+` for `basic_string` + C string. Copies `lhs` into a temp, appends `rhs` via `operator+=(char const*)`, copy-constructs into the hidden return object, destroys temp, returns `out*`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W33-F append) | `docs/reconstruction/raw/aa_00416490_FUN_00416490.md` |
| Annotated | `docs/reconstruction/raw/aa_00416490_FUN_00416490.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdString_OperatorPlus_Cstr.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00416490.cpp` |
| Function record | `docs/reconstruction/functions/aa_00416490_StdString_OperatorPlus_Cstr.md` |
| Peer | `aa_00416410` StdString_OperatorPlus_String |
| Live | decompile ≡ scaffold; body hex 122 B; RET `C3`; IAT `+=` slot `0x009c62b0` |

---

## 3. Signature (sealed)

```c
// cdecl; stack out*, lhs*, const char* rhs; RET plain; returns out*
MsvcBasicString* StdString_OperatorPlus_Cstr(
    MsvcBasicString* out,
    const MsvcBasicString* lhs,
    const char* rhs);
```

| Formal | Source | Conf |
|---|---|---|
| out | Stack[0x4]; ESI preserved; EAX return | **High** |
| lhs | Stack[0x8]; first copy-ctor arg | **High** |
| rhs | Stack[0xc]; pushed to `+=cstr` | **High** |
| epilogue | `ADD ESP,0x2C; C3` | **High** |

---

## 4. Control flow (bytes authority)

```
SEH install LAB_009bc093
tmp = copy_ctor(lhs)          // IAT [0x009c62ec]
tmp += rhs_cstr               // IAT [0x009c62b0]
out = copy_ctor(tmp)          // IAT [0x009c62ec]
~tmp                          // IAT [0x009c62f4]
return out
```

| Stage | Match | Conf |
|---|---|---|
| SEH + EH state 1 around temp | Yes | **High** |
| copy / +=cstr / copy-out / dtor order | Yes | **High** |
| Body size 122 B | Yes | **High** |
| Twin differs only at += IAT | Yes | **High** |

---

## 5. Gaps

- Product/MSVC fully demangled free-function plate.
- CRT import symbol names for the three IAT slots (targets sealed).
- Runtime / bit-exact / differential.

---

## 6. Verdict

CF, ABI, SEH, IAT overload, and twin relationship sealed from decompile + full-body hex. Residual demangle/runtime only → **accept-with-gaps**.
