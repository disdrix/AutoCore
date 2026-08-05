# Review A (reconstruction fidelity): `aa_0055c310` StdVector_InsertOne_RebindIt_Elem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055c310` |
| **VA** | `0x0055c310`–`0x0055c383` exclusive (**115 B** / `0x73`) |
| **Canonical name** | `StdVector_InsertOne_RebindIt_Elem28` |
| **Ghidra name** | `FUN_0055c310` |
| **Prior scaffold** | `FUN_0055c310` / long `Named_CalleeOf_*VOG_DEBUG*` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-AF) |
| **Counterpart** | `reviews/B_aa_0055c310_StdVector_InsertOne_RebindIt_Elem28.md` |
| **System** | MSVC `vector` insert-one + rebind, POD elem **0x1c** |
| **Evidence pass** | Live Ghidra `decompile_function` / `batch_decompile` + `read_memory` + xrefs/callees/callers. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Insert **exactly one** POD Elem28 at `where` via sealed insert-n (`count=1`), then write a **rebased** iterator to `*outIt` so callers survive realloc.

Primary known caller: **`FUN_0055c710`** capacity-full push_back slow path (fast path: `FUN_0055b7a0` fill-n one at end when spare cap).

**Not** multi-insert public API, erase, resize (`0x0055c250`), or domain/mission logic.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W37-AF append) | `docs/reconstruction/raw/aa_0055c310_FUN_0055c310.md` |
| Annotated | `docs/reconstruction/raw/aa_0055c310_FUN_0055c310.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertOne_RebindIt_Elem28.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0055c310.cpp` |
| Function record | `docs/reconstruction/functions/aa_0055c310_StdVector_InsertOne_RebindIt_Elem28.md` |
| Insert-n dual | W34-R `aa_0055be00` `StdVector_InsertN_Elem28` |
| Parent | `decompile_function` `FUN_0055c710` @ `0x0055c710` |
| Bytes | `read_memory` 128 B from `0x0055c310` — body + `CC` pad |

---

## 3. Signature (sealed)

```c
// ECX=vec*, stack (outIt*, where, value*); void; RET 0x0C
void __thiscall StdVector_InsertOne_RebindIt_Elem28(
    VectorElem28* vec,
    Elem28** outIt,
    Elem28* where,
    const Elem28* value);
```

| Formal | Source | Conf |
|---|---|---|
| vec* | ECX | **High** |
| outIt* | stack0 | **High** |
| where | stack1 → EBX | **High** |
| value* | stack2 | **High** |
| RET 0x0C | `C2 0C 00` | **High** |
| return | void (`*outIt` only) | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| Empty → index 0 | decompile + bytes | **High** |
| Else index = (where−begin)/0x1c | magic `0x92492493` | **High** |
| InsertN count=1 | `push 1` + call `0055be00` @ `0x0055c363` | **High** |
| Rebind `*outIt = begin' + index*0x1c` | `lea`/`sub`/`lea` ×28 | **High** |
| void + RET 0x0C | `89 08` then `C2 0C 00` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (115 B) — raw W37-AF append.

Entry: `53 8B 5C 24 0C 56 57 8B F9 …`.  
Epilogue: `89 08 5B C2 0C 00`.  
Pad `CC` from `0x0055c383`.

Call relative: `E8 98 FA FF FF` → target **`0x0055be00`**.

---

## 6. Gaps

1. Product T English for POD Elem28 (shared residual with W34-R insert-n).  
2. Parent push_back `FUN_0055c710` not dual-owned.  
3. Twin ABI variants (EDI/ValueEdx / RC) not unified in one plate — document only.  
4. Runtime / bit-exact / differential — open.

---

## Verdict

**accept-with-gaps** — insert-one rebind ABI/CF sealed; engine is W34-R insert-n; sole callee already dualed.
