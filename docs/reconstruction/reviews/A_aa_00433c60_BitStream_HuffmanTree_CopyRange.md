# Review A (reconstruction fidelity): `aa_00433c60` BitStream_HuffmanTree_CopyRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_00433c60` |
| **VA** | `0x00433c60`–`0x00433c92` |
| **Canonical name** | `BitStream_HuffmanTree_CopyRange` |
| **Ghidra name** | `FUN_00433c60` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W27-B) |
| **Counterpart** | `reviews/B_aa_00433c60_BitStream_HuffmanTree_CopyRange.md` |
| **System** | net / TNL BitStream Huffman (tree container) |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; parent call site |
| **Verdict** | **accept** |

---

## 1. Purpose

Nested **range copy** of 8-byte Huffman tree elements after buffer grow:

1. Loop `i` from start (EDX) to end (EDI).
2. `dest = *(container+8) + i*8`.
3. If dest non-null: copy two `uint32_t` words from `src + i*8`.

Exclusive caller: `BitStream_HuffmanTree_EnsureCapacity` (`FUN_00433ba0`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00433c60_FUN_00433c60.md` (+ 2026-07-29 W27-B append) |
| Annotated | `docs/reconstruction/raw/aa_00433c60_FUN_00433c60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BitStream_HuffmanTree_CopyRange.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00433c60.cpp` |
| Function record | `docs/reconstruction/functions/aa_00433c60_FUN_00433c60.md` |
| Named record | `docs/reconstruction/functions/aa_00433c60_BitStream_HuffmanTree_CopyRange.md` |
| Live | decompile ≡ raw; body 51 B; parent sets ESI/EDI/EDX/EBX |

---

## 3. Signature (sealed)

```c
// custom registers; plain RET
void BitStream_HuffmanTree_CopyRange(
    HuffmanTreeContainer* self /*EBX*/,
    const uint8_t* src /*ESI*/,
    uint32_t endIdx /*EDI*/,
    uint32_t startIdx /*EDX*/);
```

| Formal | Source | Conf |
|---|---|---|
| self | EBX | **High** |
| src | ESI | **High** |
| endIdx | EDI | **High** |
| startIdx | EDX | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if start >= end: return
push ebp
loop:
  dest = *(ebx+8) + edx*8
  if dest != 0:
    copy 8 bytes from esi+edx*8
  edx++
  if edx < edi: goto loop
pop ebp
ret
```

| Stage | Match | Conf |
|---|---|---|
| Stride 8 (`lea ecx,[edx*8]`) | **Yes** | **High** |
| Dest from container+8 | **Yes** | **High** |
| Two dword stores | **Yes** | **High** |
| Exclusive parent | **Yes** | **High** |
| Not alphabet (0xC / FUN_00433ca0) | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

```
3B D7 73 2E 55 EB 09 8D A4 24 00 00 00 00 8B FF
8B 43 08 8D 0C D5 00 00 00 00 03 C1 74 0C 8B 2C
31 89 28 8B 4C 31 04 89 48 04 83 C2 01 3B D7 72
DF 5D C3
```

Body exclusive end `0x00433c92` (Ghidra function bounds).

---

## 6. Gaps

- Product English / TNL original helper name.
- Null-dest branch practical reachability.
- Runtime realloc bit-exact — open.

---

## 7. Verdict

CF, custom-register ABI, 8-byte stride, exclusive EnsureCapacity role sealed. → **accept**.
