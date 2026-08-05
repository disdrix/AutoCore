# Review B (skeptical / adversarial): `aa_00433ba0` BitStream_HuffmanTree_EnsureCapacity

| Field | Value |
|---|---|
| **Stable ID** | `aa_00433ba0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W26-C) |
| **Counterpart** | `reviews/A_aa_00433ba0_BitStream_HuffmanTree_EnsureCapacity.md` |
| **Scratch** | `tmp/a_00433ba0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Standard ECX thiscall | **Falsified** — entry `mov ebx,eax`; parent `mov eax,0x00d1eaa8` |
| 2 | cdecl RET (caller cleans) | **Falsified** — epilogue `C2 04 00` (RET 4) |
| 3 | Alphabet container (0xC elems) | **Falsified** — `malloc(newCap * 8)`; alphabet grow is `FUN_00433c00` |
| 4 | Always reallocates | **Falsified** — gated on `capacity < need` |
| 5 | newCap = need rounded down | **Falsified** — `need + (0x10 - (need & 0xf))` always next 16-block |
| 6 | Multiple callers outside Huffman | **Falsified** — only `FUN_0077d520` (2 xrefs) |
| 7 | Named alias is retail symbol | **Overstated** — inferred from parent + strides; Ghidra remains `FUN_00433ba0` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| this-in-EAX + RET 4 | **High** | Wrong ABI in port |
| 8 B elem / tree container | **High** | Corrupt tree / wrong free size |
| Grow formula | **High** | Under-alloc / OOB |
| Exclusive caller | **High** | Missed init path |
| Product English | **Medium** | Naming only |
| FUN_00433c60 copy detail | **Medium-High** residual | Partial copy if mis-modeled |

---

## 3. Cross-check against raw + bytes

```
if (self->cap < need):
  newCap = (need & ~0xf) + 0x10
  neu = malloc(newCap*8)
  copy old→neu via FUN_00433c60
  free old; self->buf=neu; self->cap=newCap
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Parent W25-T already documented tree stride 8 and these two ensure calls.

---

## 4. Surviving contract for AutoCore

```
// Tree container at 0x00d1eaa8 { count, capacity, buf* }
// Before Huffman merge, ensure capacity >= 0x100 and >= count+1
// using same align formula and 8-byte element size.
// Do not reuse for alphabet (stride 0xC → FUN_00433c00).
```

---

## 5. Verdict

Adversarial pass **confirms** A: ABI, stride, grow formula, exclusive parent sealed. Residuals English + copy-helper detail → **accept**.
