# Review A (reconstruction fidelity): `aa_00411180` StdVector_PushBack_Dword_EaxVec_EsiVal_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00411180` |
| **VA** | `0x00411180` (measured **74 B**) |
| **Canonical name** | `StdVector_PushBack_Dword_EaxVec_EsiVal_Inferred` |
| **Ghidra name** | `FUN_00411180` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ7R-D) |
| **Counterpart** | `reviews/B_aa_00411180_StdVector_PushBack_Dword_EaxVec_EsiVal_Inferred.md` |
| **System** | MSVC `vector::push_back`, dword elem |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full body) + `analyze_function_complete` + `get_assembly_context` + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Append one `uint32_t` to a three-pointer vector (`begin/end/cap_end` at +4/+8/+c) using **EAX=vec / ESI=value*** customcall. Spare capacity writes in place; full capacity calls `FUN_0040b6d0`.

Closes WQ-007 residual: undualed journal callee of `Client_UpdateMissionJournal`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ7R-D append) | `docs/reconstruction/raw/aa_00411180_FUN_00411180.md` |
| Annotated | `docs/reconstruction/raw/aa_00411180_FUN_00411180.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_PushBack_Dword_EaxVec_EsiVal_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00411180.cpp` |
| Function record | `docs/reconstruction/functions/aa_00411180_StdVector_PushBack_Dword_EaxVec_EsiVal_Inferred.md` |
| Sibling push | `Vector_PushDword` `aa_004149d0` (thiscall; different grow) |
| Live | decompile ≡ scaffold; body hex 74 B; 9 call sites |

---

## 3. Signature (sealed)

```c
// EAX=vec*, ESI=const uint32_t*; bare RET
void StdVector_PushBack_Dword_EaxVec_EsiVal_Inferred(
    StdVectorDword* vec,
    const uint32_t* value);
```

| Formal | Source | Conf |
|---|---|---|
| vec* | **EAX** → `MOV EDI,EAX` | **High** |
| value* | **ESI** → `MOV ECX,[ESI]` on fast path | **High** |
| cleanup | `C3` both paths (no `RET n`) | **High** |

Call-site confirm: journal `LEA EAX,[EBX+0x728/0x738]`; `LEA ESI,[ESP+…]` then `CALL`.

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| begin null → size 0 | bytes `TEST EDX` / `XOR ECX,ECX` | **High** |
| size/cap via `SAR 2` | image | **High** |
| fast: `*end=*ESI; end+=4` | `89 08` / `83 C0 04` / `89 47 08` | **High** |
| slow: `CALL 0x0040b6d0` | `E8` rel → `0x0040b6d0` | **High** |
| Live decompile ≡ raw scaffold | **Yes** (CF); ABI registers recovered from bytes | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (74 B) — raw WQ7R-D append.

Entry: `51 57 8B F8 8B 57 04 …`  
Fast store: `8B 0E 89 08 83 C0 04 89 47 08 5F 59 C3`  
Slow: `8B 47 08 53 56 50 8D 5C 24 10 E8 0A A5 FF FF 5B 5F 59 C3`  
Pad `CC` after body.

---

## 6. Gaps

- Product English for grow helper `FUN_0040b6d0` (WQ7R-E owned).
- Element product type per caller site (mission id vs other dword).
- Host vector field English for journal `+0x728/+0x738`.
- Runtime / bit-exact / differential.

---

## Verdict

**accept-with-gaps** — dword push_back ABI/CF sealed; multi-caller generic; distinct from thiscall `Vector_PushDword`.
