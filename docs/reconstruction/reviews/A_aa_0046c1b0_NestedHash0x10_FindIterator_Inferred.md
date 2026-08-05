# Review A (reconstruction fidelity): `aa_0046c1b0` NestedHash0x10_FindIterator_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0046c1b0` |
| **VA** | `0x0046c1b0`–`0x0046c223` (**116 B**) |
| **Canonical name** | `NestedHash0x10_FindIterator_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_0046c1b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-B) |
| **Counterpart** | `reviews/B_aa_0046c1b0_NestedHash0x10_FindIterator_Inferred.md` |
| **System** | NestedHash bag (sentinel node 0x10) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (120 B) + `analyze_function_complete`; leaf; 13 callers. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

**Hash-map find by u32 key → write iterator**:

1. `idx = (*key) & mask(+0x20)`; fold if `index >= bucket_count(+0x24)`.
2. Walk chain from `table[+0x14][idx]` to adjacent end slot; keys at **`node+8`**.
3. On equal key dword: `*out = node`. On miss / ordered greater: `*out = map[+0x08]` end.
4. Bare **`RET`**; no stack args.

Used by sto factory insert, NestedHash operator[], GfxMesh edge bag (W35-F), and ~10 other NestedHash0x10 sites.

**Not** insert, erase, rehash, or the string-hash twin `HashMap_FindIterator_Inferred` (`0x0044e8c0`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0046c1b0_FUN_0046c1b0.md` (+ W36-B append) |
| Annotated | `docs/reconstruction/raw/aa_0046c1b0_FUN_0046c1b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NestedHash0x10_FindIterator_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0046c1b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0046c1b0_FUN_0046c1b0.md` |
| Named record | `docs/reconstruction/functions/aa_0046c1b0_NestedHash0x10_FindIterator_Inferred.md` |
| Live | decompile ≡ raw CF; full 116 B hex; 3× bare `C3`; leaf |
| Context | NestedHash0x10 ctor W34-E `0x00457ac0`; sibling insert `0x0046bf90`; string-hash twin `0x0044e8c0` |

**Not performed:** Launcher, runtime, ledgers.

---

## 3. Signature (sealed)

```c
// ESI=map*; ECX=key*; EAX=out_it*; bare RET
void NestedHash0x10_FindIterator_Inferred(
    void* map /*ESI*/,
    uint32_t* key /*ECX*/,
    void** out_it /*EAX*/);
```

| Slot | Source | Conf |
|---|---|---|
| map | **ESI** (`MOV EDX,[ESI+0x20]`) | **High** |
| key* | **ECX** (`MOV EDI,[ECX]`) | **High** |
| out_it* | **EAX** (`MOV [EAX],…`) | **High** |
| cleanup | bare `RET` (`C3` ×3) | **High** |
| hash | identity `key & mask` (no call) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
mask = map+0x20
idx = *key & mask
if idx >= map+0x24: fold
bucket = table[idx] .. table[idx+1]
walk next; ordered cmp on node+8
hit → *out=node; miss → *out=map+8
```

| Stage | Match | Conf |
|---|---|---|
| Identity hash | **Yes** | **High** |
| Fold vs bucket_count | **Yes** | **High** |
| Adjacent-slot end | **Yes** | **High** |
| Ordered early-exit | **Yes** | **High** |
| End sentinel on miss | **Yes** | **High** |
| Leaf | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

```
8B 56 20 83 EC 08 57 8B 39 8B CF 23 CA 39 4E 24 77 0B …
… 5F 83 C4 08 C3   (×3 epilogues)
```

Body length **116 B**. Full hex: raw W36-B append.

---

## 6. Gaps

- Product/PDB type English.
- Key domain (FourCC vs numeric id) — equality is dword sealed.
- Runtime / bit-exact.

**Verdict:** **accept**
