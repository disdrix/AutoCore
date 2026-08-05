# Review A (reconstruction fidelity): `aa_0043d770` StdMap_EraseEq_UintKey_Isnil15_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043d770` |
| **VA** | `0x0043d770`–`0x0043d7c7` exclusive (**87 B** / `0x57`) |
| **Canonical name** | `StdMap_EraseEq_UintKey_Isnil15_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_0043d770` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W38-O) |
| **Counterpart** | `reviews/B_aa_0043d770_StdMap_EraseEq_UintKey_Isnil15_Inferred.md` |
| **System** | STL / MSVC `_Tree` uint-key map (isnil@+0x15) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full 87 B) + `analyze_function_complete` + `get_function_by_address` + callers + callee decompiles. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

Ordered-map **erase-by-key returning count**:

1. `FUN_0043dc20` equal_range for unsigned key (isnil@+0x15).
2. Count nodes in `[begin, end)` via `FUN_0046f100` successor.
3. `FUN_00439050` erase that range (map in EDI).
4. Return count.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W38-O append) | `docs/reconstruction/raw/aa_0043d770_FUN_0043d770.md` |
| Annotated | `docs/reconstruction/raw/aa_0043d770_FUN_0043d770.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_EraseEq_UintKey_Isnil15_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043d770.cpp` |
| Function records | `functions/aa_0043d770_FUN_0043d770.md`, `…_StdMap_EraseEq_UintKey_Isnil15_Inferred.md` |
| Live | decompile ≡ raw CF; full 87 B hex; epilogue `ADD ESP,0xC; C3`; entry `MOV EDI,EAX` / `MOV EBX,ECX` |
| Context | Sole caller W37-AD drain fail path; peer find-or-insert `0043d700` (EDI map) |

---

## 3. Signature (sealed)

```c
// EAX=map; ECX=const uint32_t* key; RET; returns erase count
int StdMap_EraseEq_UintKey_Isnil15_Inferred(void /*EAX*/, void /*ECX*/);
```

| Slot | Source | Conf |
|---|---|---|
| map | **EAX** (`MOV EDI,EAX`) | **High** |
| key* | **ECX** (`MOV EBX,ECX` into equal_range) | **High** |
| cleanup | plain **`RET`** (`C3`) | **High** |
| return | **ESI count → EAX** | **High** |

Decompiler `void`/no formals — **bytes win**.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
pair = equal_range(map, *key)     // FUN_0043dc20
count = 0; it = pair.begin
while it != pair.end:
  count++; ++it                   // FUN_0046f100
erase [begin, end)                // FUN_00439050, EDI=map
return count
```

| Stage | Match | Conf |
|---|---|---|
| Worker CF / 3 callees | **Yes** | **High** |
| isnil@+0x15 (callees) | **Yes** | **High** |
| key-u32@+0x0C unsigned | **Yes** | **High** |
| Count then erase | **Yes** | **High** |
| RET plain | **Yes** | **High** |

---

## 5. Verdict

Reconstruction fidelity sealed for ABI, body bounds, isnil15 layout family, erase-by-key+count semantics. Product map English residual only → **accept**.
