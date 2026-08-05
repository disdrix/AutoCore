# Review A (reconstruction fidelity): `aa_0055be00` StdVector_InsertN_Elem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055be00` |
| **VA** | `0x0055be00`–`0x0055c11c` (**796 B**) |
| **Canonical name** | `StdVector_InsertN_Elem28` |
| **Ghidra name** | `FUN_0055be00` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-R) |
| **Counterpart** | `reviews/B_aa_0055be00_StdVector_InsertN_Elem28.md` |
| **System** | MSVC `vector<T>` insert-n for POD elem stride **0x1c** |
| **Evidence pass** | Live Ghidra `batch_decompile` + `get_function_by_address` + `get_function_xrefs` + `read_memory`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Insert `count` copies of a **trivially copyable 0x1c** value at `where`. Same insert-n skeleton as BasicString/BasicStringW twins (max `0x9249249`, 1.5× grow, hole/mid in-place), but POD value copy (7× movss) and **no destroy-range** on reallocation.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W34-R append) | `docs/reconstruction/raw/aa_0055be00_FUN_0055be00.md` |
| Annotated | `docs/reconstruction/raw/aa_0055be00_FUN_0055be00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertN_Elem28.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0055be00.cpp` |
| Function record | `docs/reconstruction/functions/aa_0055be00_StdVector_InsertN_Elem28.md` |
| Callers | `FUN_0055c250` (resize grow); `FUN_0055c310` (insert-one) |
| Live | decompile ≡ CF; RET `C2 0C 00` sealed |

---

## 3. Signature (sealed)

```c
// ECX = vector*; stack where*, count, value*; RET 0x0C; void
void __thiscall StdVector_InsertN_Elem28(
    VectorElem28* vec,
    Elem28* where,
    uint32_t count,
    const Elem28* value);
```

| Formal | Source | Conf |
|---|---|---|
| vec | ECX (`8B F1`) | **High** |
| where / count / value | stack; `RET 0x0C` | **High** |
| begin/end/cap @ +4/+8/+0xC | decompile + triad math | **High** |
| stride 0x1c | `/0x1c` magic | **High** |
| max 0x9249249 | `BA 49 92 24 09` | **High** |
| POD | movss ladder; delete without destroy | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| Local POD copy of value | 7× movss / dword | **High** |
| count==0 early return | decompile | **High** |
| overflow → `FUN_0055b3a0` | size+count vs max | **High** |
| Grow 1.5× + new + relocate + fill + delete old | decompile; **no** destroy | **High** |
| In-place hole/mid arms | decompile | **High** |
| RET 0x0C (no local dtor) | `C2 0C 00` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (796 B) — see raw W34-R append.

Entry: `55 8B EC 6A FF 68 60 48 9A 00`.  
Value copy: `F3 0F 10` / `F3 0F 11` ladder from `[ebp+0x10]`.  
`8B F1` this. Magic `/0x1c`: `B8 93 24 49 92`. Max: `BA 49 92 24 09`.  
Epilogue: `5B 8B E5 5D C2 0C 00`.  
Pad `CC`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_0055c250` @ `0x0055c2ae`; `FUN_0055c310` @ `0x0055c363` |
| Callees | throw; new/delete; POD relocate/fill helpers |
| Size helper | `StdVector_Elem28_Size` `0x00469c50` (W33-J) |

---

## 7. Gaps

1. Product English for `Elem28` (what domain struct is 0x1c here).  
2. Nested helper duals (`FUN_0055b6a0`, `FUN_0055b7a0`, `FUN_0055bd90`, `FUN_0055b5d0`, `FUN_0055b4d0`, callers).  
3. Runtime / bit-exact / differential.

---

## 8. Verdict

**accept-with-gaps** — insert-n ABI/CF/stride/max/POD sealed; product type of Elem28 + nested helpers residual.
