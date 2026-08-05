# Review A (reconstruction fidelity): `aa_004a7ad0` StdVector_InsertN_BasicStringW

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a7ad0` |
| **VA** | `0x004a7ad0`–`0x004a7df7` (**807 B**) |
| **Canonical name** | `StdVector_InsertN_BasicStringW` |
| **Ghidra name** | `FUN_004a7ad0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-R) |
| **Counterpart** | `reviews/B_aa_004a7ad0_StdVector_InsertN_BasicStringW.md` |
| **System** | MSVC `vector<basic_string<wchar_t>>` insert-n |
| **Evidence pass** | Live Ghidra `batch_decompile` + `get_function_by_address` + `get_function_xrefs` + `read_memory` (entry/magic/epilogue + full hex). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Insert `count` copies of a `basic_string<wchar_t>` (elem **0x1c**) at `where` into the vector, growing 1.5× when needed or shifting in-place when capacity allows. Wide twin of sealed `StdVector_InsertN_BasicString` (`0x004306b0`, W32-B).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W34-R append) | `docs/reconstruction/raw/aa_004a7ad0_FUN_004a7ad0.md` |
| Annotated | `docs/reconstruction/raw/aa_004a7ad0_FUN_004a7ad0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertN_BasicStringW.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_004a7ad0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004a7ad0_StdVector_InsertN_BasicStringW.md` |
| Caller insert-one | `FUN_004a7ff0` (decompile: count=`1`, rebind out-it) |
| Live | decompile ≡ CF; RET `C2 0C 00` sealed |

---

## 3. Signature (sealed)

```c
// ECX = vector*; stack where*, count, value*; RET 0x0C; void
void __thiscall StdVector_InsertN_BasicStringW(
    VectorBasicStringW* vec,
    BasicStringW_0x1c* where,
    uint32_t count,
    BasicStringW_0x1c* value);
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
| Local wstring copy of value | IAT ctor + EH state 0 | **High** |
| count==0 early cleanup | decompile | **High** |
| overflow → `FUN_004a6820` | size+count vs max | **High** |
| Grow 1.5× + new + relocate + fill + destroy old | decompile + helpers | **High** |
| In-place hole/mid arms | decompile | **High** |
| Local dtor + RET 0x0C | `C2 0C 00` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (807 B) — see raw W34-R append.

Entry: `55 8B EC 6A FF 68 E9 11 9A 00`.  
`8B F1` this. Magic `/0x1c`: `B8 93 24 49 92`. Max: `BA 49 92 24 09`.  
Epilogue: `5B 8B E5 5D C2 0C 00`.  
Pad `CC`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_004a7ff0` @ `0x004a8043` only (direct) |
| Callees | wstring IAT; throw; new/delete; relocate/fill/destroy helpers |
| Size helper | `StdVector_Elem28_Size` `0x00469c50` (W33-J) |

---

## 7. Gaps

1. Product/MSVC demangle for exact `vector<basic_string<wchar_t>>::insert` plate.  
2. Nested helper duals (`FUN_004a6b50`, `FUN_004a74f0`, `FUN_004a7aa0`, `FUN_004a7a70`, `FUN_004a68*`, `FUN_004a7ff0`).  
3. Runtime / bit-exact / differential.

---

## 8. Verdict

**accept-with-gaps** — insert-n ABI/CF/stride/max/wstring sealed; product demangle + nested helpers residual.
