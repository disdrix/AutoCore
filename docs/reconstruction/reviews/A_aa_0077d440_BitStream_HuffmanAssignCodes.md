# Review A (reconstruction fidelity): `aa_0077d440` BitStream_HuffmanAssignCodes

| Field | Value |
|---|---|
| **Stable ID** | `aa_0077d440` |
| **VA** | `0x0077d440`–`0x0077d514` |
| **Canonical name** | `BitStream_HuffmanAssignCodes` |
| **Ghidra name** | `FUN_0077d440` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W26-C) |
| **Counterpart** | `reviews/B_aa_0077d440_BitStream_HuffmanAssignCodes.md` |
| **System** | net / TNL BitStream Huffman (code assign) |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; parent + leaf formula |
| **Verdict** | **accept** |

---

## 1. Purpose

Recursive **code assignment** after Huffman tree merge:

1. If `nodeOrLeaf < 0` (leaf): map to alphabet row; store **code** at +8 and **bitlen** at +4; return.
2. Else (internal): node at `tree + index*8`.
3. Write path bit **0**, recurse left short@+4 at depth+1; restore bitPos.
4. Write path bit **1**, recurse right short@+6 at depth+1; restore bitPos.

Sole external caller: `BitStream_HuffmanBuildTables` with `(scratch, 0, 0)`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0077d440_FUN_0077d440.md` (+ 2026-07-29 W26-C append) |
| Annotated | `docs/reconstruction/raw/aa_0077d440_FUN_0077d440.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BitStream_HuffmanAssignCodes.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0077d440.cpp` |
| Function record | `docs/reconstruction/functions/aa_0077d440_FUN_0077d440.md` |
| Named record | `docs/reconstruction/functions/aa_0077d440_BitStream_HuffmanAssignCodes.md` |
| Related | W25-T `BitStream_HuffmanBuildTables`; W21-C write/readString |
| Live | decompile ≡ raw; body 212 B; plain RET; leaf/internal CF sealed |

---

## 3. Signature (sealed)

```c
// cdecl; void; plain RET
void BitStream_HuffmanAssignCodes(void* ctx, int nodeOrLeaf, int depth);
```

| Formal | Source | Conf |
|---|---|---|
| ctx | Stack[0x4] | **High** |
| nodeOrLeaf | Stack[0x8] | **High** |
| depth | Stack[0xC] | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if nodeOrLeaf < 0:
  row = alphabet + (nodeOrLeaf*3+3)*-4   // leafIdx = -1-nodeOrLeaf
  row[+8] = **(ctx+0xC)   // code dword
  row[+4] = (u8)depth     // bitlen
  return
saved = ctx.bitPos (+0x18)
node = tree + nodeOrLeaf*8
maybe expand; write bit 0; recurse left(+4); restore bitPos
maybe expand; write bit 1; recurse right(+6); restore bitPos
```

| Stage | Match | Conf |
|---|---|---|
| Leaf early-out + alphabet write | **Yes** | **High** |
| Leaf index algebra ≡ 0xC stride | **Yes** | **High** |
| Left bit0 / right bit1 | **Yes** | **High** |
| bitPos snapshot/restore | **Yes** | **High** |
| FUN_0042b450 expand gate | **Yes** | **High** |
| Single external parent | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Leaf branch starts:
```
8B 44 24 08  85 C0  7D 25 ... A1 BC EA D1 00 ... 89 50 08  88 48 04  C3
```
Internal ends:
```
5F 5E 5D 5B C3  CC… (pad to 0x0077d520)
```

---

## 6. Gaps

- Product English inside TNL.
- Runtime post-walk alphabet dump bit-exact vs process — open.
- Expand-fail (FUN_0042b450 AL=0) skips bit write; parent seeds 0x20-bit scratch so rare.

---

## 7. Verdict

CF, ABI, leaf/internal encoding, alphabet writes, and exclusive parent sealed. Residuals English + runtime dump. → **accept**.
