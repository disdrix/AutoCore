# Review A (reconstruction fidelity): `aa_00461ac0` RcElem28_CopyCtor_EsiEdi

| Field | Value |
|---|---|
| **Stable ID** | `aa_00461ac0` |
| **VA** | `0x00461ac0`–`0x00461b11` exclusive (**81 B**) |
| **Canonical name** | `RcElem28_CopyCtor_EsiEdi` |
| **Ghidra name** | `FUN_00461ac0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-N) |
| **Counterpart** | `reviews/B_aa_00461ac0_RcElem28_CopyCtor_EsiEdi.md` |
| **System** | MSVC-style copy-ctor, refcounted elem **0x1c** |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full body) + `get_function_by_address` + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Copy-construct one **RcElem28** from **ESI** source into **EDI** dest: four dwords, shared resource `@+0x10` with AddRef, three bytes, trailing dword.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W35-N append) | `docs/reconstruction/raw/aa_00461ac0_FUN_00461ac0.md` |
| Annotated | `docs/reconstruction/raw/aa_00461ac0_FUN_00461ac0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/RcElem28_CopyCtor_EsiEdi.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00461ac0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00461ac0_RcElem28_CopyCtor_EsiEdi.md` |
| Parent (context) | `StdVector_InsertN_RcElem28` W34-P |
| Sole caller | `FUN_004617a0` @ `0x004617c9` |

---

## 3. Signature (sealed)

```c
// ESI=src*, EDI=dst*; EAX=dst; plain RET
RcElem28* RcElem28_CopyCtor_EsiEdi(void);
```

| Formal | Source | Conf |
|---|---|---|
| src* | ESI (`8B C6` / loads from ESI) | **High** |
| dst* | EDI (`8B CF` / stores to EDI) | **High** |
| return dst | `8B C7; C3` | **High** |
| resource @+0x10 AddRef | `8B 4E 10` + `83 41 04 01` + vtbl+4 | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| Copy dwords 0..3 | decompile ≡ bytes | **High** |
| Null resource skip AddRef | decompile | **High** |
| ++refcount; if ==1 call vtbl+4 | decompile + hex | **High** |
| Store resource + bytes + dword | decompile ≡ bytes | **High** |
| RET plain | `C3` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (81 B) — raw W35-N append.

Entry: `8B C6 8B 10 8B CF 89 11 …`  
Epilogue: `8B C7 C3`  
Pad `CC` from `0x00461b11`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker / leaf helper |
| Callers | 1 — insert-n parent only |
| Callees | conditional vtbl+4 only |

---

## 7. Gaps

1. Product/PDB class English for RcElem28 (gfx residual only from parent scaffold).  
2. Exact product meaning of AddRef-when-becomes-1 (unusual vs classic COM).  
3. Runtime / bit-exact.

---

## 8. Verdict rationale

Register ABI, full 0x1c field map, and AddRef gate sealed from decompile+bytes. Product plate open → **accept-with-gaps**.
