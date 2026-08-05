# Review A (reconstruction fidelity): `aa_00433ba0` BitStream_HuffmanTree_EnsureCapacity

| Field | Value |
|---|---|
| **Stable ID** | `aa_00433ba0` |
| **VA** | `0x00433ba0`–`0x00433bfe` |
| **Canonical name** | `BitStream_HuffmanTree_EnsureCapacity` |
| **Ghidra name** | `FUN_00433ba0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W26-C) |
| **Counterpart** | `reviews/B_aa_00433ba0_BitStream_HuffmanTree_EnsureCapacity.md` |
| **System** | net / TNL BitStream Huffman (tree container) |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; parent call sites |
| **Verdict** | **accept** |

---

## 1. Purpose

Nested **ensure-capacity** for the Huffman **tree** buffer:

1. Compare `needCount` to container capacity at `this+4`.
2. If short: compute `newCap = need + (0x10 - (need & 0xf))`, `malloc(newCap * 8)`.
3. Install new buffer, copy via `FUN_00433c60`, free old, commit capacity.

Exclusive caller: `BitStream_HuffmanBuildTables` (×2).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00433ba0_FUN_00433ba0.md` (+ 2026-07-29 W26-C append) |
| Annotated | `docs/reconstruction/raw/aa_00433ba0_FUN_00433ba0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BitStream_HuffmanTree_EnsureCapacity.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00433ba0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00433ba0_FUN_00433ba0.md` |
| Named record | `docs/reconstruction/functions/aa_00433ba0_BitStream_HuffmanTree_EnsureCapacity.md` |
| Live | decompile ≡ raw; body 94 B; epilogue `C2 04 00`; parent `mov eax,0x00d1eaa8` |

---

## 3. Signature (sealed)

```c
// this-in-EAX; stack needCount; RET 4
void BitStream_HuffmanTree_EnsureCapacity(
    HuffmanTreeContainer* self /*EAX*/, uint32_t needCount);
```

| Formal | Source | Conf |
|---|---|---|
| self | EAX (`mov ebx,eax` at entry) | **High** |
| needCount | Stack[0x4] after pushes (`[esp+0xC]` after 2 pushes) | **High** |
| return | void; RET 4 | **High** |

Container fields: +0 count, +4 capacity, +8 buf (8 B elems) at image `0x00d1eaa8`.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if capacity < need:
  newCap = need + (16 - (need & 15))
  neu = malloc(newCap * 8)
  old = buf; buf = neu
  FUN_00433c60()   // copy
  buf = old; free(old); buf = neu
  capacity = newCap
return
```

| Stage | Match | Conf |
|---|---|---|
| Capacity compare at +4 | **Yes** | **High** |
| Align formula + *8 alloc | **Yes** | **High** |
| Copy then free old | **Yes** | **High** |
| Exclusive parent ×2 | **Yes** | **High** |
| Not alphabet (0xC) — sister is FUN_00433c00 | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

```
53 55 8B 6C 24 0C 8B D8 3B 6B 04 76 ...
... C2 04 00 CC
```

Body exclusive end `0x00433bfe` (Ghidra function bounds).

---

## 6. Gaps

- Product English / TNL container type name.
- Full register contract of `FUN_00433c60` (not OWN).
- Runtime realloc bit-exact — open.

---

## 7. Verdict

CF, ABI (this-in-EAX + RET 4), 8-byte stride, exclusive HuffmanBuildTables role sealed. → **accept**.
