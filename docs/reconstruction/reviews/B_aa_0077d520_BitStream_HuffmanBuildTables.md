# Review B (skeptical / adversarial): `aa_0077d520` BitStream_HuffmanBuildTables

| Field | Value |
|---|---|
| **Stable ID** | `aa_0077d520` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W25-T) |
| **Counterpart** | `reviews/A_aa_0077d520_BitStream_HuffmanBuildTables.md` |
| **Scratch** | `tmp/a_0077d520.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This encodes/decodes strings itself | **Falsified** — only builds tables; encode/decode in writeString/readString |
| 2 | Thread-safe re-entrant init | **Overstated** — flag set at entry without lock; callers check then call (single-threaded game main) |
| 3 | Alphabet stride 0x10 | **Falsified** — seed loop `+0xc`; writeString cost uses `ch*0xc` |
| 4 | Tree node is 4 B | **Falsified** — malloc `cap*8`; shorts at +4/+6 |
| 5 | weight uses raw freq without +1 | **Falsified** — `*piVar4 = freq + 1` |
| 6 | Multiple non-string callers | **Falsified** — exactly 2 xrefs: 0077d960, 0077daf0 |
| 7 | FUN_0077d440 is optional polish | **Falsified** — required to fill bitlen/code used by write/read |
| 8 | Named `BitStream_HuffmanBuildTables` is retail | **Overstated** — inferred from TNL BitStream + prior W21-C docs |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Once-init + Huffman merge CF | **High** | Broken string wire codec |
| Alphabet 0xC / tree 8 | **High** | Corrupt tables |
| Callers only write/readString | **High** | Missed init path |
| weight = freq+1 | **High** | Different code lengths |
| Leaf short encoding | **High** / signed-div Medium-High | Wrong leaf ids on edge |
| Product English | **Medium** | Naming only |
| Runtime table dump | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
DAT_00d17a28 = 1
ensure alphabet 256
for i in 0..255: alphabet[i] = {freq[i]+1, bitlen0, char i, code0}
worklist = leaves
while >1: merge two lightest into tree[]
root → tree[0]
FUN_0077d440(scratch,0,0)
cleanup
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Prior write/read dual reviews assumed this builder — now sealed.

---

## 4. Surviving contract for AutoCore

```
// Client BitStream string codec depends on these globals after first write/read:
//   DAT_00d17a28 == 1
//   DAT_00d1eabc[ch*0xC + 4] = bit length; +8 = code payload
//   DAT_00d1eab0 tree used by readString bit walk (left@+4 / right@+6 shorts)
// Server/port parity: either ship same static freq table DAT_00a1ea68 and build,
// or hardcode identical alphabet codes. Do not invent different Huffman trees.
```

---

## 5. Verdict

Adversarial pass **confirms** A: builder role, CF, strides, and exclusive callers sealed. Residuals are English + runtime dump → **accept**.
