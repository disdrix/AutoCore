# Review A (reconstruction fidelity): `aa_004c8970` Object_TFIDMapLookupOrRelatedMatch_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c8970` |
| **VA** | `0x004c8970`–`0x004c8a58` |
| **Canonical name** | `Object_TFIDMapLookupOrRelatedMatch_Inferred` |
| **Ghidra name** | `FUN_004c8970` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W30-T) |
| **Counterpart** | `reviews/B_aa_004c8970_Object_TFIDMapLookupOrRelatedMatch_Inferred.md` |
| **System** | creature / TFID map / engage gate |
| **Evidence pass** | Live `decompile_function` + `read_memory` + callers/callees/xrefs; sealed `TFID_EqualsObjectId`; parent engage W29-L |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Query creature TFID map (`self+0x154`): return map payload on key hit; else return whether MI+`0xA4` related object matches the queried TFID (direct or via `vtbl+0x214` + `TFID_EqualsObjectId`). Engage path uses non-zero as early-out gate.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004c8970_FUN_004c8970.md` (+ W30-T append) |
| Annotated | `docs/reconstruction/raw/aa_004c8970_FUN_004c8970.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Object_TFIDMapLookupOrRelatedMatch_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c8970.cpp` |
| Function | `docs/reconstruction/functions/aa_004c8970_Object_TFIDMapLookupOrRelatedMatch_Inferred.md` |
| Sealed leaf | `TFID_EqualsObjectId` (`aa_00404aa0`) |
| Sole caller | `CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred` (`0x005ccff0`) |
| Bytes | `read_memory` @ `0x004c8970` / epilogue `C2 10 00` |

---

## 3. Signature

```c
// Ghidra residual: 3 stack formals + char; bytes: RET 0x10 (4 dwords TFID)
uint32_t __thiscall Object_TFIDMapLookupOrRelatedMatch_Inferred(
    void *self,
    uint32_t tfidLo, uint32_t tfidHi, uint32_t tfidW2, uint32_t tfidW3);
```

| Item | Evidence | Conf |
|---|---|---|
| thiscall ECX=self | `8B F1` | **High** |
| RET 0x10 | `C2 10 00` | **High** |
| Map this = self+0x154 | `8D BE 54 01 00 00` + ECX=EDI | **High** |
| Head compare self+0x158 | `3B 86 58 01 00 00` | **High** |
| Hit load node+0x20 | `8B 40 20` | **High** |

---

## 4. Control flow (sealed)

1. `FUN_004cb4b0(self+0x154, &tfidLo)` lower_bound
2. If end or key < node key → `sel = end`; else `sel = node`
3. **Miss (`sel == end`):** related @ MI+`0xA4` → direct TFID match → 1; else `vtbl+0x214` path + `TFID_EqualsObjectId` → 1; else 0
4. **Hit:** return `*(sel+0x20)`

| Stage | Match | Conf |
|---|---|---|
| Map lower_bound + equality gate | **Yes** | **High** |
| Miss related dual path | **Yes** | **High** |
| Hit payload +0x20 | **Yes** | **High** |
| Sole engage caller | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

| Addr role | Bytes / note |
|---|---|
| prolog | `83 EC 08 53 56 8B F1 57` |
| map base | `8D BE 54 01 00 00` → `+0x154` |
| lower_bound call | `8B CF E8 …` → `FUN_004cb4b0` |
| miss epilogue 0 | `33 C0 … C2 10 00` |
| miss epilogue 1 | `B8 01 00 00 00 … C2 10 00` |
| hit | `8B 40 20` then epilogue |

---

## 6. Gaps / open

1. Product English for map value type @ node `+0x20`.
2. Product name for MI field `+0xA4` and `vtbl+0x214`.
3. Nested map helper `FUN_004cb4b0` not OWN.
4. Runtime / bit-exact — open.

---

## 7. Verdict

CF/ABI/map offsets/caller gate sealed; product field English residual → **accept-with-gaps**.
