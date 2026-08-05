# Review A (reconstruction fidelity): `aa_00433c00` BitStream_HuffmanAlphabetEnsureCapacity

| Field | Value |
|---|---|
| **Stable ID** | `aa_00433c00` |
| **VA** | `0x00433c00`–`0x00433c53` |
| **Canonical name** | `BitStream_HuffmanAlphabetEnsureCapacity` |
| **Ghidra name** | `FUN_00433c00` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W26-B) |
| **Counterpart** | `reviews/B_aa_00433c00_BitStream_HuffmanAlphabetEnsureCapacity.md` |
| **System** | net / TNL BitStream Huffman alphabet buffer |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; exclusive caller site bytes |
| **Verdict** | **accept** |

---

## 1. Purpose

Grow-if-needed helper for the **Huffman alphabet** dynarray (element stride **0xC**):

1. If `capacity >= need` → return.
2. Else `newCap = need + (0x10 − (need & 0xF))`.
3. `malloc(newCap * 0xC)`; install new buffer; `FUN_00433ca0` copies live elements; free old; commit capacity.

Sole consumer: `BitStream_HuffmanBuildTables` with `need = 0x100`, `ECX = &DAT_00d1eab4`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00433c00_FUN_00433c00.md` (+ 2026-07-29 W26-B append) |
| Annotated | `docs/reconstruction/raw/aa_00433c00_FUN_00433c00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BitStream_HuffmanAlphabetEnsureCapacity.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00433c00.cpp` |
| Function record | `docs/reconstruction/functions/aa_00433c00_FUN_00433c00.md` |
| Named record | `docs/reconstruction/functions/aa_00433c00_BitStream_HuffmanAlphabetEnsureCapacity.md` |
| Parent sealed | `BitStream_HuffmanBuildTables` (`aa_0077d520`, W25-T) — residual nested helper closed here |
| Live | decompile ≡ raw; body 83 B; call site `mov eax,0x100; mov ecx,0x00d1eab4; call` |

---

## 3. Signature (sealed)

```c
// Machine: ECX = container*, EAX = need; void
// container @ 0x00d1eab4: size@+0, capacity@+4, data@+8 (= DAT_00d1eabc)
void BitStream_HuffmanAlphabetEnsureCapacity(HuffmanAlphaContainer *c, uint32_t need);
```

| Formal | Source | Conf |
|---|---|---|
| container | ECX | **High** |
| need | EAX (`in_EAX`) | **High** |
| return | void | **High** |
| elem size | `* 0xC` in malloc | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if capacity < need:
  newCap = need + (0x10 - (need & 0xF))
  neu = malloc(newCap * 0xC)
  old = data; data = neu
  FUN_00433ca0()          // copy size elems old→neu
  data = old; free(old)
  data = neu; capacity = newCap
return
```

| Stage | Match | Conf |
|---|---|---|
| capacity < need gate | **Yes** | **High** |
| newCap slab formula | **Yes** | **High** |
| malloc ×0xC | **Yes** | **High** |
| copy via FUN_00433ca0 | **Yes** | **High** |
| free old + commit | **Yes** | **High** |
| Exactly 1 caller | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Body **83 B** `0x00433c00`–`0x00433c53`; pad `CC`.

```
53 57                push ebx; push edi
8B D8                mov ebx, eax        ; need
8B F9                mov edi, ecx        ; container
3B 5F 04             cmp ebx, [edi+4]    ; need ? capacity
76 45                jbe ret             ; capacity >= need
... and eax,0xF; lea newCap; malloc(newCap*0xC)
... call FUN_00433ca0; free; commit
5D 5F 5B C3          (grow path pops) ret
```

Caller `0x0077d520` prologue fragment:

```
BB 00 01 00 00       mov ebx, 0x100
8B C3                mov eax, ebx
B9 B4 EA D1 00       mov ecx, 0x00d1eab4
... call FUN_00433c00
```

---

## 6. Gaps

- Product / TNL template English for the dynarray helper — residual.
- Full formal recovery of `FUN_00433ca0` (OWN W26-C sibling territory for tree helper `00433ba0`; copy helper residual Medium).
- Runtime alloc failure paths — `malloc` null not checked (matches binary).

---

## 7. Verdict

CF, ABI (ECX/EAX), stride 0xC, growth formula, and exclusive HuffmanBuildTables caller sealed. → **accept**.
