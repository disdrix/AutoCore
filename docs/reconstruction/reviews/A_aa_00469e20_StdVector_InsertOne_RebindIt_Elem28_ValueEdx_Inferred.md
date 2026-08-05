# Review A (reconstruction fidelity): `aa_00469e20` StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00469e20` |
| **VA** | `0x00469e20`–`0x00469e92` exclusive (**114 B**) |
| **Canonical name** | `StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred` |
| **Ghidra name** | `FUN_00469e20` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-Q) |
| **Counterpart** | `reviews/B_aa_00469e20_StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred.md` |
| **System** | MSVC `vector` insert-one + rebind, POD elem **0x1c** |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Insert **exactly one** POD-elem28 at `where` via sealed insert-n (`count=1`), then write a **rebased** iterator to `*outIt` so callers survive realloc.

Primary known caller: **`FUN_00469c80`** push_back — spare capacity uses `FUN_0046a260` fill-n one at end; full capacity routes here with `where=end`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W36-Q append) | `docs/reconstruction/raw/aa_00469e20_FUN_00469e20.md` |
| Annotated | `docs/reconstruction/raw/aa_00469e20_FUN_00469e20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00469e20.cpp` |
| Function record | `docs/reconstruction/functions/aa_00469e20_StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred.md` |
| Insert-n dual | W34-Q `aa_00469f50` |
| Parent | `FUN_00469c80` decompile + xrefs |

---

## 3. Signature (sealed)

```c
// EDI=vec*, stack (outIt*, where, value*); RET 0xC
Elem28** StdVector_InsertOne_RebindIt_Elem28_ValueEdx_Inferred(
    StdVectorElem28* vec,
    Elem28** outIt,
    Elem28* where,
    const Elem28* value);
```

| Formal | Source | Conf |
|---|---|---|
| vec* | EDI | **High** |
| outIt* | stack0 → EBP; returned in EAX | **High** |
| where | stack1 → EBX | **High** |
| value* | stack2 → EDX into InsertN | **High** |
| RET 0xC | `C2 0C 00` | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| Empty → index 0 | decompile + bytes | **High** |
| Else index = (where−begin)/0x1c | magic `0x92492493` | **High** |
| InsertN count=1 | `push 1` + call `00469f50` | **High** |
| Rebind `*outIt = begin' + index*0x1c` | lea/mov | **High** |
| return outIt; RET 0xC | bytes | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (114 B) — raw W36-Q append.

Entry: `53 8B 5C 24 0C 55 8B 6C 24 0C 56 8B 77 04 …`.  
Call: `8B 54 24 18 6A 01 53 57 E8 D8 00 00 00` → `FUN_00469f50`.  
Epilogue: `5E 8B C5 5D 5B C2 0C 00`.  
Pad `CC` @ `0x00469e92`.

---

## 6. Gaps

- Product T English.  
- Parent push_back `FUN_00469c80` not dual-owned.  
- Runtime / bit-exact.

---

## Verdict

**accept-with-gaps** — insert-one rebind ABI/CF sealed; engine is W34-Q insert-n.
