# Review B (skeptical / adversarial): `aa_00433c00` BitStream_HuffmanAlphabetEnsureCapacity

| Field | Value |
|---|---|
| **Stable ID** | `aa_00433c00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W26-B) |
| **Counterpart** | `reviews/A_aa_00433c00_BitStream_HuffmanAlphabetEnsureCapacity.md` |
| **Scratch** | `tmp/a_00433c00.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This builds Huffman codes | **Falsified** — only capacity grow; codes filled later by `FUN_0077d440` |
| 2 | Element stride 8 (tree nodes) | **Falsified** — `malloc(newCap * 0xC)`; alphabet stride from W25-T |
| 3 | Stack-arg cdecl need | **Falsified** — `mov ebx, eax` at entry; caller loads EAX=0x100 |
| 4 | Multiple independent callers | **Falsified** — exactly 1 xref: `FUN_0077d520` |
| 5 | newCap = need exactly | **Falsified** — `need + (0x10 − (need & 0xF))` (0x100 → 0x110) |
| 6 | Grows tree buffer `DAT_00d1eab0` | **Falsified** — ECX fixed to `0x00d1eab4` alphabet triple |
| 7 | Named form is retail | **Overstated** — role from exclusive caller + stride; English open |
| 8 | Copies without helper | **Falsified** — always `FUN_00433ca0` on grow |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| capacity < need gate | **High** | Wrong realloc |
| stride 0xC / newCap formula | **High** | Corrupt alphabet |
| ECX/EAX ABI | **High** | Broken call from BuildTables |
| Exclusive caller | **High** | Missed init path |
| FUN_00433ca0 copy detail | **Medium** | Truncated migrate on grow-from-nonempty |
| Product English | **Medium** | Naming only |

---

## 3. Cross-check against raw + bytes

```
need = EAX; c = ECX
if c->capacity < need:
  newCap = need + (16 - (need & 15))
  neu = malloc(newCap * 12)
  copy size elems via FUN_00433ca0
  free old; c->data = neu; c->capacity = newCap
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Closes W25-T residual “nested `FUN_00433c00` not OWN”.

---

## 4. Surviving contract for AutoCore

```
// Before seeding 256 alphabet leaves, ensure:
//   container @ DAT_00d1eab4 has capacity >= 0x100
//   data @ DAT_00d1eabc points to capacity*12-byte buffer
// Growth: capacity becomes need + (16 - (need&15)); never shrink here.
// Port may pre-size alphabet to >= 0x110 and skip this helper if tables are static.
```

---

## 5. Verdict

Adversarial pass **confirms** A: ensure-capacity role, ABI, stride, growth math, exclusive caller sealed. Residuals English + copy-helper formals → **accept**.
