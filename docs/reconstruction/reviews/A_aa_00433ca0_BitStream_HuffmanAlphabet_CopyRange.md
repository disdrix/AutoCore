# Review A (reconstruction fidelity): `aa_00433ca0` BitStream_HuffmanAlphabet_CopyRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_00433ca0` |
| **VA** | `0x00433ca0`–`0x00433cd3` |
| **Canonical name** | `BitStream_HuffmanAlphabet_CopyRange` |
| **Ghidra name** | `FUN_00433ca0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W28-A) |
| **Counterpart** | `reviews/B_aa_00433ca0_BitStream_HuffmanAlphabet_CopyRange.md` |
| **System** | net / TNL BitStream Huffman (alphabet container) |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; parent call site |
| **Verdict** | **accept** |

---

## 1. Purpose

Nested **range copy** of 12-byte Huffman alphabet elements after buffer grow:

1. Loop `i` from start (EDX) to end (EAX).
2. `dest = *(container+8) + i*0xC`.
3. If dest non-null: copy three `uint32_t` words from `src + i*0xC`.

Exclusive caller: `BitStream_HuffmanAlphabetEnsureCapacity` (`FUN_00433c00`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00433ca0_FUN_00433ca0.md` (+ 2026-07-29 W28-A append) |
| Annotated | `docs/reconstruction/raw/aa_00433ca0_FUN_00433ca0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BitStream_HuffmanAlphabet_CopyRange.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00433ca0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00433ca0_FUN_00433ca0.md` |
| Named record | `docs/reconstruction/functions/aa_00433ca0_BitStream_HuffmanAlphabet_CopyRange.md` |
| Live | decompile ≡ raw; body 52 B; parent sets EDI/ESI/EAX/EDX |

---

## 3. Signature (sealed)

```c
// custom registers; plain RET
void BitStream_HuffmanAlphabet_CopyRange(
    HuffmanAlphaContainer* self /*EDI*/,
    const uint8_t* src /*ESI*/,
    uint32_t endIdx /*EAX*/,
    uint32_t startIdx /*EDX*/);
```

| Formal | Source | Conf |
|---|---|---|
| self | EDI | **High** |
| src | ESI | **High** |
| endIdx | EAX | **High** |
| startIdx | EDX | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if start >= end: return
off = start * 0xC; n = end - start
push ebx; push ebp
loop:
  dest = *(edi+8) + off
  if dest != 0:
    copy 12 bytes from esi+off
  off += 0xC; n--
  if n != 0: goto loop
pop ebp; pop ebx
ret
```

| Stage | Match | Conf |
|---|---|---|
| Stride 0xC (`lea ecx,[edx+edx*2]; add ecx,ecx; add ecx,ecx`) | **Yes** | **High** |
| Dest from container+8 | **Yes** | **High** |
| Three dword stores | **Yes** | **High** |
| Exclusive parent | **Yes** | **High** |
| Not tree (8 / FUN_00433c60) | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

```
3B D0 73 31 8D 0C 52 03 C9 03 C9 2B C2 53 8B D0 55
8B 47 08 03 C1 74 13 8D 1C 31 8B 2B 89 28 8B 6B 04
89 68 04 8B 5B 08 89 58 08 83 C1 0C 83 EA 01 75 DE
5D 5B C3
```

Body exclusive end `0x00433cd3` (RET).

---

## 6. Gaps

- Product English / TNL original helper name.
- Null-dest branch practical reachability.
- Runtime realloc bit-exact — open.

---

## 7. Verdict

CF, custom-register ABI, 12-byte stride, exclusive EnsureCapacity role sealed. → **accept**.
