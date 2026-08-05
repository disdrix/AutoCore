# Review A (reconstruction fidelity): `aa_00748960` MeshHost0xC4_BaseCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00748960` |
| **VA** | `0x00748960`–`0x00748aaf` (**336 B**) |
| **Canonical name** | `MeshHost0xC4_BaseCtor_Inferred` |
| **Ghidra name** | `FUN_00748960` |
| **Review date** | `2026-07-29` (W36-H dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-H) |
| **Counterpart** | `reviews/B_aa_00748960_MeshHost0xC4_BaseCtor_Inferred.md` |
| **System** | mesh / host graphics (0xC4 shell) |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 336 B) + `analyze_function_complete` + callers/xrefs + neighbor decompile |
| **Verdict** | **accept** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Placement-construct a preallocated **0xC4** multi-vtbl mesh host: install three vtbl pointers, vector-construct two 8-byte elements, zero mid-fields, seed **+FLT_MAX** / **−FLT_MAX** float triples, construct subobject at `+0x78`, OR flags `0x81` at `+0xBC`, return `self`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00748960_FUN_00748960.md` (+ W36-H full hex) |
| Annotated | `docs/reconstruction/raw/aa_00748960_FUN_00748960.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MeshHost0xC4_BaseCtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00748960.cpp` |
| Function records | `aa_00748960_FUN_00748960.md`, `aa_00748960_MeshHost0xC4_BaseCtor_Inferred.md` |
| Live | decompile ≡ raw CF; 336 B hex ends `83c410 c3`; `DAT_00aaa630`/`63c` = ±FLT_MAX |
| Context | W35-E HostPtrTable12 `new(0xC4)`×7; neighbor `FUN_00748ab0` uses `+0xBC` flags |

---

## 3. Signature (sealed)

```c
uint32_t * __fastcall MeshHost0xC4_BaseCtor_Inferred(uint32_t *self /* ECX */);
```

| Slot | Source | Conf |
|---|---|---|
| self | ECX (`MOV ESI,ECX`) | **High** |
| return | `MOV EAX,ESI` | **High** |
| size | 0xC4 (callers + last store +0xC0) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Multi-vtbl triple | **Yes** | **High** |
| eh_vector 2×8 @ +0x10 | **Yes** | **High** |
| +FLT_MAX / −FLT_MAX triples | **Yes** (`read_memory` DAT) | **High** |
| Subobject `FUN_00437680(+0x78)` | **Yes** | **High** |
| `+0xBC \|= 0x81` | **Yes** | **High** |
| return self | **Yes** | **High** |
| Product English | open | **Low** |

---

## 5. Gaps / open

1. Product/PDB English for 0xC4 class + three base vtbls.
2. Exact meaning of flag bits `0x81` @ +0xBC (neighbor clears bit0).
3. Unowned subobject contracts (`FUN_00437440`, `FUN_00437680`).
4. Runtime / bit-exact / differential.

**Verdict:** **accept** — ABI + layout + constants sealed; product plate residual only.
