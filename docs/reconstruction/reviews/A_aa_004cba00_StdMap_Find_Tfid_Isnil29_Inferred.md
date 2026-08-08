# Review A (reconstruction fidelity): `aa_004cba00` StdMap_Find_Tfid_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cba00` |
| **VA** | `0x004cba00`–`0x004cba51` (**82 B** / `0x52`) |
| **Canonical name** | `StdMap_Find_Tfid_Isnil29_Inferred` |
| **Ghidra name** | `FUN_004cba00` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9G-G) |
| **Counterpart** | `reviews/B_aa_004cba00_StdMap_Find_Tfid_Isnil29_Inferred.md` |
| **System** | MSVC map find / TFID-shaped key / isnil@+0x29 |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Exact-match **find** shell over dualed `StdMap_LowerBound_Tfid_Isnil29`: lower_bound then equality gate; write hit node or head(end) to `*outIt`. Leaf of skill/object TFID map consumer neighborhood (not a hash table helper).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9G-G append) | `docs/reconstruction/raw/aa_004cba00_FUN_004cba00.md` |
| Annotated | `docs/reconstruction/raw/aa_004cba00_FUN_004cba00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_Find_Tfid_Isnil29_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_004cba00.cpp` |
| Lower_bound dual | `aa_004cb4b0` StdMap_LowerBound_Tfid_Isnil29 (W31-N) |
| Live | decompile ≡ equality CF; RET 8 + body hex sealed |

---

## 3. Signature (sealed)

```c
// ECX = map (head@+4); stack outIt*, pKey*; RET 8; *outIt written
void __fastcall StdMap_Find_Tfid_Isnil29_Inferred(
    MapHost_Head4* self, Node_Isnil29** outIt, const KeyU32I32* pKey);
```

| Formal | Source | Conf |
|---|---|---|
| map | ECX (`MOV ESI,ECX`) | **High** |
| outIt | stack after 3 pushes `@[ESP+0x10]` | **High** |
| pKey | stack `@[ESP+0x14]` into EDI | **High** |
| cleanup | `C2 08 00` both exits | **High** |
| effect | `*outIt = node or head` | **High** |

---

## 4. Control flow

```
lb = LowerBound_Tfid(self, pKey)
head = self->head
if lb != head && node.key <= *pKey:  // hi signed, lo unsigned
  *outIt = lb
else:
  *outIt = head
```

| Stage | Match | Conf |
|---|---|---|
| lower_bound call | `CALL 004cb4b0` | **High** |
| end test | `CMP EAX, [map+4]` | **High** |
| key gate hi@+0x14 / lo@+0x10 | decompile ≡ bytes | **High** |
| no mutate | no stores to tree | **High** |
| RET 8 | both epilogues | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (82 B) — see raw WQ9G-G append. Pad `CC`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (find shell) |
| Xrefs | 5 UNCONDITIONAL_CALL |
| Callers | `FUN_004ea350` (×3), `FUN_00807550`, site `0x005dd84d` |
| Callee | `StdMap_LowerBound_Tfid_Isnil29` only |
| Closes | W31-N residual “find shell FUN_004cba00”; WQ-009 depth-4 skill-hash neighborhood residual |

---

## 7. Gaps

- Product map / value_type at node `+0x20`.
- Whether all hosts share one class vs layout clones.
- Parent `FUN_004ea350` / `0x005dd84d` product English.
- Runtime / bit-exact / differential.

---

## 8. Verdict

Fidelity pass seals CF/ABI/key/layout/role. Product English residual → **accept-with-gaps**.
