# Review A (reconstruction fidelity): `aa_004306b0` StdVector_InsertN_BasicString

| Field | Value |
|---|---|
| **Stable ID** | `aa_004306b0` |
| **VA** | `0x004306b0`–`0x004309bf` (**783 B**) |
| **Canonical name** | `StdVector_InsertN_BasicString` |
| **Ghidra name** | `FUN_004306b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-B) |
| **Counterpart** | `reviews/B_aa_004306b0_StdVector_InsertN_BasicString.md` |
| **System** | MSVC `vector<basic_string<char>>` insert-n |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (entry/magic/epilogue + full hex) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Insert `count` copies of a `basic_string` (elem **0x1c**) at `where` into the vector, growing 1.5× when needed or shifting in-place when capacity allows.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W32-B append) | `docs/reconstruction/raw/aa_004306b0_FUN_004306b0.md` |
| Annotated | `docs/reconstruction/raw/aa_004306b0_FUN_004306b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertN_BasicString.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_004306b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004306b0_StdVector_InsertN_BasicString.md` |
| Caller insert-one | `FUN_00430310` (decompile: count=`1`, rebind out-it) |
| Indirection | `StringVec_PushFront_EnsureTrailingDirSep` (W31-E) → `FUN_00430310` → this |
| Live | decompile ≡ CF; RET `C2 0C 00` sealed |

---

## 3. Signature (sealed)

```c
// ECX = vector*; stack where*, count, value*; RET 0x0C; void
void __thiscall StdVector_InsertN_BasicString(
    VectorBasicString* vec,
    BasicString_0x1c* where,
    uint32_t count,
    BasicString_0x1c* value);
```

| Formal | Source | Conf |
|---|---|---|
| vec | ECX (`8B F1`) | **High** |
| where / count / value | stack; `RET 0x0C` | **High** |
| begin/end/cap @ +4/+8/+0xC | decompile + triad math | **High** |
| stride 0x1c | `/0x1c` magic + destroy loop | **High** |
| max 0x9249249 | `BA 49 92 24 09` | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| Local string copy of value | IAT ctor + EH state 0 | **High** |
| count==0 early cleanup | decompile | **High** |
| overflow → `FUN_004540b0` | size+count vs max | **High** |
| Grow 1.5× + new + relocate + fill + destroy old | decompile + helpers | **High** |
| In-place hole/mid arms | decompile | **High** |
| Local dtor + RET 0x0C | `C2 0C 00` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (783 B) — see raw W32-B append.

Entry: `55 8B EC 6A FF 68 F9 CC 9B 00`.  
Epilogue: `5B 8B E5 5D C2 0C 00`.  
Pad `CC`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_00430310` @ `0x00430363` only (direct) |
| Callees | string IAT; throw; new/delete; relocate/fill/destroy helpers |

---

## 7. Gaps

1. Product/MSVC demangle for exact `vector<basic_string<…>>::insert` plate.  
2. Nested helper duals (`FUN_0046a2c0`, `FUN_00430390`, `FUN_004314*`, `FUN_00431aa0`, `FUN_00430310`).  
3. Runtime / bit-exact / differential.

---

## 8. Verdict

**accept-with-gaps** — insert-n ABI/CF/stride/max sealed; product demangle + nested helpers residual.
