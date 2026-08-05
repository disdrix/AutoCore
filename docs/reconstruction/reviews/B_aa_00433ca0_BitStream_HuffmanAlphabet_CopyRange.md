# Review B (skeptical / adversarial): `aa_00433ca0` BitStream_HuffmanAlphabet_CopyRange

| Field | Value |
|---|---|
| **Stable ID** | `aa_00433ca0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W28-A) |
| **Counterpart** | `reviews/A_aa_00433ca0_BitStream_HuffmanAlphabet_CopyRange.md` |
| **Scratch** | `tmp/a_00433ca0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | True `__fastcall` (ECX/EDX formals only) | **Falsified** — EDI/ESI/EAX carry container/src/end; ECX unused as formal |
| 2 | Stack formals / RET N | **Falsified** — plain `C3`; parent passes registers |
| 3 | Element stride 8 (tree) | **Falsified** — `*0xC` addressing; tree uses `FUN_00433c60` |
| 4 | Copies capacity not size | **Falsified** — parent loads EAX from `this+0` (size) |
| 5 | Multiple independent callers | **Falsified** — single xref from `FUN_00433c00` |
| 6 | Named alias is retail symbol | **Overstated** — inferred from exclusive parent + stride; Ghidra remains `FUN_00433ca0` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Custom reg ABI EDI/ESI/EAX/EDX | **High** | Wrong grow path / memory corruption |
| Stride 0xC | **High** | Partial/over copy of alphabet entries |
| Exclusive parent | **High** | Missed alternate grow path |
| Product English | **Medium** | Naming only |
| Null-dest check meaning | **Medium** | Theoretical edge only |

---

## 3. Cross-check against raw + bytes

```
for i in [edx, eax):
  dest = *(edi+8) + i*0xC
  if dest: copy 12B from esi+i*0xC
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Parent W26-B left this unit as residual; register contract now sealed.

---

## 4. Surviving contract for AutoCore

```
// During Huffman alphabet ensure-capacity grow:
//   after buf = neu; copy size elements of 0xC from old → neu
//   using custom regs, not memcpy of capacity.
// Do not reuse for tree (stride 8 → FUN_00433c60).
```

---

## 5. Verdict

Adversarial pass **confirms** A: ABI, stride, exclusive parent, leaf CF sealed. Residuals English + null-dest → **accept**.
