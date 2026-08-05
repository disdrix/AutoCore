# Review A (reconstruction fidelity): `aa_004612d0` StdVector_InsertOne_RebindIt_RcElem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_004612d0` |
| **VA** | `0x004612d0`–`0x00461342` exclusive (**114 B**) |
| **Canonical name** | `StdVector_InsertOne_RebindIt_RcElem28` |
| **Ghidra name** | `FUN_004612d0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-Q) |
| **Counterpart** | `reviews/B_aa_004612d0_StdVector_InsertOne_RebindIt_RcElem28.md` |
| **System** | MSVC `vector` insert-one + rebind, refcounted elem **0x1c** |
| **Evidence pass** | Live Ghidra `batch_decompile` / `decompile_function` + `read_memory` + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Insert **exactly one** RC-elem28 at `where` via sealed insert-n (`count=1`), then write a **rebased** iterator to `*outIt` so callers survive realloc.

Primary known caller: **`FUN_00460f90`** capacity-full push_back slow path (fast path: `FUN_00461c90` fill-n one at end when spare cap).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W35-Q append) | `docs/reconstruction/raw/aa_004612d0_FUN_004612d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004612d0_FUN_004612d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertOne_RebindIt_RcElem28.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_004612d0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004612d0_StdVector_InsertOne_RebindIt_RcElem28.md` |
| Insert-n dual | W34-P `aa_004617a0` |
| Parent | `FUN_00460f90` decompile |

---

## 3. Signature (sealed)

```c
// EDI=vec*, stack (outIt*, where, value*); RET 0xC
RcElem28** StdVector_InsertOne_RebindIt_RcElem28(
    StdVectorRc28* vec,
    RcElem28** outIt,
    RcElem28* where,
    const RcElem28* value);
```

| Formal | Source | Conf |
|---|---|---|
| vec* | EDI | **High** |
| outIt* | stack0 → EBP; returned in EAX | **High** |
| where | stack1 → EBX | **High** |
| value* | stack2 → ECX into InsertN | **High** |
| RET 0xC | `C2 0C 00` | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| Empty → index 0 | decompile + bytes | **High** |
| Else index = (where−begin)/0x1c | magic divide | **High** |
| InsertN count=1 | `push 1` + call `004617a0` | **High** |
| Rebind `*outIt = begin' + index*0x1c` | lea/mov | **High** |
| return outIt; RET 0xC | bytes | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (114 B) — raw W35-Q append.

Entry: `53 8B 5C 24 0C 55 …`.  
Epilogue: `8B C5 5D 5B C2 0C 00`.  
Pad `CC` then next @ `0x00461350`.

---

## 6. Gaps

- Product T English.  
- Parent push_back `FUN_00460f90` not dual-owned.  
- Twin ABI variants (thiscall ECX=vec dword family) not unified here.  
- Runtime / bit-exact.

---

## Verdict

**accept-with-gaps** — insert-one rebind ABI/CF sealed; engine is W34-P insert-n.
