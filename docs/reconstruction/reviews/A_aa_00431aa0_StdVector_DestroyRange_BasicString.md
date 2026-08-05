# Review A (reconstruction fidelity): `aa_00431aa0` StdVector_DestroyRange_BasicString

| Field | Value |
|---|---|
| **Stable ID** | `aa_00431aa0` |
| **VA** | `0x00431aa0`–`0x00431ac2` (**34 B**) |
| **Canonical name** | `StdVector_DestroyRange_BasicString` |
| **Ghidra name** | `FUN_00431aa0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-H) |
| **Counterpart** | `reviews/B_aa_00431aa0_StdVector_DestroyRange_BasicString.md` |
| **System** | MSVC `vector<basic_string<char>>` destroy-range |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Destroy each `basic_string` in `[first, last)` at stride **0x1c**. Buffer deallocation is separate (caller `operator_delete` after grow).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W33-H append) | `docs/reconstruction/raw/aa_00431aa0_FUN_00431aa0.md` |
| Annotated | `docs/reconstruction/raw/aa_00431aa0_FUN_00431aa0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_DestroyRange_BasicString.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00431aa0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00431aa0_StdVector_DestroyRange_BasicString.md` |
| Parent context | `StdVector_InsertN_BasicString` (W32-B) destroy-old after relocate |
| Live | decompile ≡ CF; `RET C2 08 00` + `ADD ESI,0x1C` sealed |

---

## 3. Signature (sealed)

```c
// stack first*, last*; RET 0x08; void
void StdVector_DestroyRange_BasicString(
    BasicString_0x1c* first,
    BasicString_0x1c* last);
```

| Formal | Source | Conf |
|---|---|---|
| first / last | stack; ESI/EDI loop | **High** |
| stride 0x1c | `83 C6 1C` | **High** |
| dtor | `FF 15 F4 62 9C 00` | **High** |
| cleanup | `C2 08 00` | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| Early-out first==last | `CMP ESI,EDI; JE` | **High** |
| Loop dtor + stride | decompile ≡ bytes | **High** |
| RET 8 | epilogue bytes | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (34 B) — see raw W33-H append.

```
568b742408578b7c24103bf774118bff8bceff15f4629c0083c61c3bf775f15f5ec20800
```

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (destroy helper; analyze also labels wrapper) |
| Callers | insert-n main @ `0x0043084d`; two catch sites |
| Callees | IAT `~basic_string` |

---

## 7. Gaps

1. Product/MSVC demangle (`_Destroy_range` English).  
2. IAT dtor full symbol plate.  
3. Runtime / bit-exact / differential.

---

## 8. Verdict

**accept-with-gaps** — destroy-range ABI/CF/stride/dtor sealed; product demangle residual.
