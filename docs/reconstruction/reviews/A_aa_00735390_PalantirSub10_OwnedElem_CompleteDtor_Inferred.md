# Review A (reconstruction fidelity): `aa_00735390` PalantirSub10_OwnedElem_CompleteDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00735390` |
| **VA** | `0x00735390`–`0x00735403` exclusive (**115 B**) |
| **Canonical name** | `PalantirSub10_OwnedElem_CompleteDtor_Inferred` |
| **Ghidra name** | `FUN_00735390` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-N) |
| **Counterpart** | `reviews/B_aa_00735390_PalantirSub10_OwnedElem_CompleteDtor_Inferred.md` |
| **System** | client / Palantir nested owned-element teardown |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (full 115 B) + `get_assembly_context` @ `0x00964d37` + callee decompile `FUN_00465d70`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Complete destructor for heap elements of Palantir nested `+0x10` owned-pointer vector: Release COM@+0x48, tidy vector@+0x70C, destroy two `std::string`s. Caller frees the host.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W37-N append) | `docs/reconstruction/raw/aa_00735390_FUN_00735390.md` |
| Annotated | `docs/reconstruction/raw/aa_00735390_FUN_00735390.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PalantirSub10_OwnedElem_CompleteDtor_Inferred.cpp` |
| Parent consumer | W35-J `aa_00964d00` PalantirSub10_DestroyOwnedPtrVecAndComUninit |
| Live | decompile + 115 B hex + caller site + `FUN_00465d70` |

---

## 3. Signature (sealed)

```c
// stdcall; RET 4; void
void __stdcall PalantirSub10_OwnedElem_CompleteDtor_Inferred(void* elem);
```

| Formal | Source | Conf |
|---|---|---|
| elem | stack (`MOV ESI,[esp+0x18]`) | **High** |
| cleanup | `C2 04 00` | **High** |
| thiscall ECX | **not used** | **High** |

---

## 4. Control flow (bytes authority)

```
SEH LAB_009ab754; state=2
com = [elem+0x48]; if com: Release(com); [elem+0x48]=0
EBX = elem+0x70C; FUN_00465d70()   // EBX-this vec tidy stride 0x24
state=0; ~string(elem+0x1C)
state=-1; ~string(elem)
RET 4
```

| Stage | Match | Conf |
|---|---|---|
| stdcall RET 4 | `C2 04 00` | **High** |
| COM Release vtbl+8 | `FF 51 08` | **High** |
| EBX=elem+0x70C | `8D 9E 0C 07 00 00` | **High** |
| two string dtors | IAT `@0x009c62f4` ×2 | **High** |
| sole caller parent | PUSH elem; CALL; delete | **High** |

---

## 5. Machine bytes (`read_memory`)

Full 115 B hex — see raw W37-N append.

---

## 6. Gaps (fidelity)

- Product C++ class English for element / COM / 0x24 payload.
- Matching ctor path into Palantir+0x10 vector.
- Runtime / bit-exact / differential.

---

## 7. Verdict rationale

Structural complete-dtor plate is fully sealed by bytes + sole W35-J consumer. Product English open → **accept-with-gaps** (not full accept).
