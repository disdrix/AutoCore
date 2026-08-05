# Review B (skeptical / adversarial): `aa_00433c60` BitStream_HuffmanTree_CopyRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_00433c60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W27-B) |
| **Counterpart** | `reviews/A_aa_00433c60_BitStream_HuffmanTree_CopyRange.md` |
| **Scratch** | `tmp/a_00433c60.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | True `__fastcall` (ECX/EDX formals only) | **Falsified** — EBX/ESI/EDI carry container/src/end; ECX unused as formal |
| 2 | Stack formals / RET N | **Falsified** — plain `C3`; parent passes registers |
| 3 | Element stride 0xC (alphabet) | **Falsified** — `*8` addressing; alphabet uses `FUN_00433ca0` |
| 4 | Copies capacity not count | **Falsified** — parent loads EDI from `this+0` (count) |
| 5 | Multiple independent callers | **Falsified** — single xref from `FUN_00433ba0` |
| 6 | Named alias is retail symbol | **Overstated** — inferred from exclusive parent + stride; Ghidra remains `FUN_00433c60` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Custom reg ABI EBX/ESI/EDI/EDX | **High** | Wrong grow path / memory corruption |
| Stride 8 | **High** | Partial/over copy of tree nodes |
| Exclusive parent | **High** | Missed alternate grow path |
| Product English | **Medium** | Naming only |
| Null-dest check meaning | **Medium** | Theoretical edge only |

---

## 3. Cross-check against raw + bytes

```
for i in [edx, edi):
  dest = *(ebx+8) + i*8
  if dest: copy 8B from esi+i*8
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Parent W26-C left this unit as residual; register contract now sealed.

---

## 4. Surviving contract for AutoCore

```
// During Huffman tree ensure-capacity grow:
//   after buf = neu; copy count elements of 8 bytes from old → neu
//   using custom regs, not memcpy of capacity.
// Do not reuse for alphabet (stride 0xC → FUN_00433ca0).
```

---

## 5. Verdict

Adversarial pass **confirms** A: ABI, stride, exclusive parent, leaf CF sealed. Residuals English + null-dest → **accept**.
