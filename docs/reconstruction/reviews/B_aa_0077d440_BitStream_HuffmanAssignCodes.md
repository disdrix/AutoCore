# Review B (skeptical / adversarial): `aa_0077d440` BitStream_HuffmanAssignCodes

| Field | Value |
|---|---|
| **Stable ID** | `aa_0077d440` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W26-C) |
| **Counterpart** | `reviews/A_aa_0077d440_BitStream_HuffmanAssignCodes.md` |
| **Scratch** | `tmp/a_0077d440.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Optional polish after tree build | **Falsified** — only writer of alphabet bitlen/code used by write/readString |
| 2 | Iterative non-recursive walk | **Falsified** — two self-calls + external entry |
| 3 | Left writes bit 1 | **Falsified** — left clears bit (`AND ~mask`); right sets (`OR mask`) |
| 4 | Leaf when nodeOrLeaf > 0 | **Falsified** — `TEST EAX; JGE internal` → leaf is negative |
| 5 | Alphabet stride 8 | **Falsified** — leaf formula ≡ ×0xC; tree uses ×8 |
| 6 | Stores bitlen at +8 | **Falsified** — code dword at +8; bitlen byte at +4 |
| 7 | Multiple external callers | **Falsified** — only `FUN_0077d520` external xref |
| 8 | Named alias is retail | **Overstated** — inferred; Ghidra `FUN_0077d440` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Leaf vs internal CF | **High** | Broken string codec tables |
| bitlen@+4 / code@+8 | **High** | Wrong encode/decode |
| Left0 / right1 | **High** | Inverted codes |
| Leaf index formula | **High** | Wrong alphabet row |
| cdecl 3-arg | **High** | ABI mismatch |
| Expand-fail skip write | **Medium-High** | Rare; parent cap 0x20 |
| Product English | **Medium** | Naming only |
| Runtime dump | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
if node < 0:
  alphabet[leaf].code = current_bits
  alphabet[leaf].bitlen = depth
  return
write 0; recurse left; restore
write 1; recurse right; restore
```

Algebra: `base + (n*3+3)*-4` with `n = -1-k` → `base + 12k`. Live ≡ raw 2026-07-23. Parent W25-T required this walk.

---

## 4. Surviving contract for AutoCore

```
// After HuffmanBuildTables tree merge:
//   BitStream_HuffmanAssignCodes(scratch, 0, 0)
// fills DAT_00d1eabc[ch*0xC + 4] = bitlen, +8 = code.
// Port must preserve left=0 / right=1 path bits and negative leaf encoding.
// Do not substitute a different canonical Huffman code assignment.
```

---

## 5. Verdict

Adversarial pass **confirms** A: role required, CF/ABI/strides sealed. Residuals English + runtime dump → **accept**.
