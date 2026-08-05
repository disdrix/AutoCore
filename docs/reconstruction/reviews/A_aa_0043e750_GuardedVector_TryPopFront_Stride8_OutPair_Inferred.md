# Review A (reconstruction fidelity): `aa_0043e750` GuardedVector_TryPopFront_Stride8_OutPair_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043e750` |
| **VA** | `0x0043e750`–`0x0043e7e2` (**146 B**) |
| **Canonical name** | `GuardedVector_TryPopFront_Stride8_OutPair_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_0043e750` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W38-A) |
| **Counterpart** | `reviews/B_aa_0043e750_GuardedVector_TryPopFront_Stride8_OutPair_Inferred.md` |
| **System** | GuardedVector ring-deque try pop_front (stride 8) |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 146 B) + `analyze_function_complete` + callers/xrefs; **no** `disassemble_bytes` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + analyze/callers/xrefs only. No Launcher.

---

## 1. Purpose

Optional-CS **try pop_front** of an **8-byte** ring element into a caller out-pair:

1. If lockEnable@`+0x2c` → Enter CS@`+0x14`.
2. Empty → Leave + AL=0.
3. Else resolve front slot (page=`begin>>1`, slot=`begin&1`, stride 8), copy pair, advance begin (wrap **cap×2**), size--, AL=1.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W38-A append) | `docs/reconstruction/raw/aa_0043e750_FUN_0043e750.md` |
| Annotated | `docs/reconstruction/raw/aa_0043e750_FUN_0043e750.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_TryPopFront_Stride8_OutPair_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043e750.cpp` |
| Function records | `functions/aa_0043e750_FUN_0043e750.md`, `…_GuardedVector_TryPopFront_Stride8_OutPair_Inferred.md` |
| Live | decompile ≡ raw CF; full 146 B hex; `B0 01` / `32 C0` + `C3`; CS IAT |
| Context | Sole caller AssPreloader drain `host+0x4c`; peer PopFront `0040d980` |

---

## 3. Signature (sealed)

```c
// ESI=container; EDI=out pair{u32,u32}; AL=popped; RET
uint8_t GuardedVector_TryPopFront_Stride8_OutPair_Inferred(
    GuardedVectorHeader *container, uint32_t out[2]);
```

| Slot | Source | Conf |
|---|---|---|
| container | **ESI** (`[ESI+…]` throughout) | **High** |
| out pair | **EDI** (`MOV [EDI],…` / `[EDI+4]`) | **High** |
| return | **AL** 1/0 | **High** |
| cleanup | plain **`RET`** (`C3`) | **High** |
| stack formals | none | **High** |

Decompiler `unaff_ESI` / `unaff_EDI` — **bytes win**.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if lockEnable: EnterCS(+0x14)
if size==0: Leave?; return 0
slotp = pages[begin>>1 (wrap)] + (begin&1)*8
if out != slotp: out[0]=slotp[0]
out[1]=slotp[1]          // always
begin++; wrap at cap*2; size--; empty→begin=0
Leave?; return 1
```

| Stage | Match | Conf |
|---|---|---|
| Body 146 B | **Yes** | **High** |
| CS gate +0x2c / +0x14 | **Yes** | **High** |
| Stride 8 / wrap cap×2 | **Yes** | **High** |
| Odd first-dword alias skip | **Yes** | **High** |
| AL boolean + plain RET | **Yes** | **High** |
| Product pair English | inferred only | **Inferred** |

---

## 5. Machine bytes (`read_memory`)

Full body (146 B):

```
807e2c00558d6e14740755ff15bc619c00837e1000746a8b4e0c8bc1d1e88d14002bca8b56083bd077022bc28b56048b04828d04c83bf874048b08890f8b50048957048b461085c0742683460c018b56088b4e0c03d23bd17707c7460c0000000083c0ff8946107507c7460c00000000807d1800740755ff15b8619c00b0015dc3807d1800740755ff15b8619c0032c05dc3
```

| Site | Bytes | Meaning |
|---|---|---|
| Gate | `80 7E 2C 00` | lockEnable |
| CS | `8D 6E 14` | `LEA EBP,[ESI+0x14]` |
| Size | `83 7E 10 00` | empty test |
| Stride | `8D 04 C8` | `+ slot*8` |
| Alias | `3B F8 74 04` | skip first dword if EDI==slot |
| Wrap | `03 D2` / `3B D1` | cap×2 vs begin |
| Success | `B0 01 5D C3` | AL=1 |
| Empty | `32 C0 5D C3` | AL=0 |

---

## 6. Gaps

- Product element type of the out-pair (AssPreloader success payload).
- Intent of first-dword self-assign skip (preserved oddness).
- Runtime / bit-exact (no Launcher).

---

## 7. Verdict

Reconstruction fidelity sealed for ABI, body bounds, stride-8 addressing, CS gate, and try-pop semantics. Product pair English residual → **accept-with-gaps**.
