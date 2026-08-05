# Review A (reconstruction fidelity): `aa_0043d5e0` StdMap_FindEq_UintKey_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043d5e0` |
| **VA** | `0x0043d5e0`–`0x0043d63a` (**90 B**) |
| **Canonical name** | `StdMap_FindEq_UintKey_Val12` (**Inferred**) |
| **Ghidra name** | `FUN_0043d5e0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-M) |
| **Counterpart** | `reviews/B_aa_0043d5e0_StdMap_FindEq_UintKey_Val12.md` |
| **System** | STL / MSVC `_Tree` Val12 uint-key map |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full 90 B) + `analyze_function_complete` + callers; **no** `disassemble_bytes` |
| **Verdict** | **accept** |

---

## 1. Purpose

Leaf ordered-map **exact find** for unsigned 32-bit keys:

1. Lower-bound walk from root (`head->parent`) using isnil@`+0x19`.
2. Equality gate: `cand != end && cand->key <= *key`.
3. Write hit or end into `*out_it` (EAX).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W37-M append) | `docs/reconstruction/raw/aa_0043d5e0_FUN_0043d5e0.md` |
| Annotated | `docs/reconstruction/raw/aa_0043d5e0_FUN_0043d5e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_FindEq_UintKey_Val12.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043d5e0.cpp` |
| Function records | `functions/aa_0043d5e0_FUN_0043d5e0.md`, `…_StdMap_FindEq_UintKey_Val12.md` |
| Live | decompile ≡ raw CF; full 90 B hex; epilogue `C3`; isnil `80 79 19 00`; key `39 79 0c` / `3B 72 0C` |
| Context | Val12 family (W28–W33 tree peers); contrast pure lower_bound TFID isnil29 |

---

## 3. Signature (sealed)

```c
// ECX=map; EBX=const uint32_t* key; EAX=node** out; RET
void StdMap_FindEq_UintKey_Val12(void *map, void **out_it, const uint32_t *key);
```

| Slot | Source | Conf |
|---|---|---|
| map | **ECX** (`MOV ESI,ECX`) | **High** |
| key* | **EBX** (`MOV EDI,[EBX]` / `MOV ESI,[EBX]`) | **High** |
| out_it | **EAX** (`MOV [EAX],ECX`) | **High** |
| cleanup | plain **`RET`** (`C3`) | **High** |

Decompiler omits formal ABI — **bytes win**.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
cand = head; node = root
while !isnil(node):
  if node.key < *key: node = right
  else: cand = node; node = left
if cand != head && cand.key <= *key: *out = cand
else: *out = head
```

| Stage | Match | Conf |
|---|---|---|
| Leaf CF / no callees | **Yes** | **High** |
| isnil@+0x19 | **Yes** | **High** |
| key-u32@+0x0C unsigned | **Yes** | **High** |
| Equality gate | **Yes** | **High** |
| RET plain | **Yes** | **High** |

---

## 5. Verdict

Reconstruction fidelity sealed for ABI, body bounds, Val12 layout, unsigned exact-find semantics. Product map English residual only → **accept**.
