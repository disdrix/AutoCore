# Review A (reconstruction fidelity): `aa_0077d520` BitStream_HuffmanBuildTables

| Field | Value |
|---|---|
| **Stable ID** | `aa_0077d520` |
| **VA** | `0x0077d520`–`0x0077d952` |
| **Canonical name** | `BitStream_HuffmanBuildTables` |
| **Ghidra name** | `FUN_0077d520` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W25-T) |
| **Counterpart** | `reviews/B_aa_0077d520_BitStream_HuffmanBuildTables.md` |
| **System** | net / TNL BitStream Huffman |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; callers write/readString |
| **Verdict** | **accept** |

---

## 1. Purpose

One-shot **Huffman table builder** for BitStream string codec:

1. Set once-flag `DAT_00d17a28 = 1`.
2. Ensure alphabet capacity **0x100**.
3. Seed 256 alphabet leaves from `DAT_00a1ea68` (`weight = freq+1`, symbol at +5).
4. Classic merge of two lightest into internal tree nodes (`DAT_00d1eab0`, 8 B).
5. `FUN_0077d440` tree walk fills bitlen (+4) and code bits (+8) on alphabet.
6. Destroy scratch BitStream object.

Sole consumers (callers): `BitStream_writeString` / `BitStream_readString`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0077d520_FUN_0077d520.md` (+ 2026-07-29 W25-T append) |
| Annotated | `docs/reconstruction/raw/aa_0077d520_FUN_0077d520.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BitStream_HuffmanBuildTables.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0077d520.cpp` |
| Function record | `docs/reconstruction/functions/aa_0077d520_FUN_0077d520.md` |
| Named record | `docs/reconstruction/functions/aa_0077d520_BitStream_HuffmanBuildTables.md` |
| Related sealed | `BitStream_writeString` / `BitStream_readString` (W21-C) — residual builder closed here |
| Live | decompile ≡ raw; prologue `C6 05 28 7A D1 00 01`; epilogue `ADD ESP,0x154; RET` |

---

## 3. Signature (sealed)

```c
// no formals; void; plain RET after frame teardown
void BitStream_HuffmanBuildTables(void);
```

| Formal | Source | Conf |
|---|---|---|
| (none) | — | **High** |
| return | void | **High** |
| frame | `SUB/ADD ESP, 0x154` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
DAT_00d17a28 = 1
ensure alphabet 0x100
seed leaves from DAT_00a1ea68
worklist = 256 leaf slots
while count != 1:
  pick two lightest
  grow tree if needed (cap += 16 aligned)
  parent = merge; encode child shorts
  compact worklist
tree[0] = root
FUN_0077d440(scratch, 0, 0)  // assign codes
destroy scratch
```

| Stage | Match | Conf |
|---|---|---|
| Flag set first | **Yes** | **High** |
| Alphabet 0x100 / stride 0xC | **Yes** | **High** |
| weight = freq+1 | **Yes** | **High** |
| Two-lowest merge | **Yes** | **High** |
| Tree node 8 B + short children | **Yes** | **High** |
| Code fill via FUN_0077d440 | **Yes** | **High** |
| Exactly 2 callers (write/readString) | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Prologue + flag (sealed):
```
81 EC 54 01 00 00    sub esp, 0x154
...
C6 05 28 7A D1 00 01 mov byte ptr [DAT_00d17a28], 1
E8 ...              call FUN_00433c00
```

Epilogue:
```
5F 5E 5D 5B 81 C4 54 01 00 00 C3
```

Freq seed `@0x00a1ea68` sampled (first non-zero clusters + printable weights).

---

## 6. Gaps

- Product English inside TNL sources (name residual).
- Exact signed-div leaf-index corner cases under negative offsets — decompiler formula held; runtime table dump open.
- Nested `FUN_00433ba0` / `FUN_00433c00` container type — not OWN.
- Bit-exact post-build table vs retail process memory — open.

---

## 7. Verdict

CF, ABI, strides, once-init flag, callers, and Huffman role are sealed. Residuals are English + runtime dump only. → **accept**.
