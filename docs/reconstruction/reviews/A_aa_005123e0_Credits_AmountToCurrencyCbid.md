# Review A (reconstruction fidelity): `aa_005123e0` Credits_AmountToCurrencyCbid

| Field | Value |
|---|---|
| **Stable ID** | `aa_005123e0` |
| **VA** | `0x005123e0` |
| **Canonical name** | `Credits_AmountToCurrencyCbid` |
| **Ghidra name** | `FUN_005123e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_005123e0_Credits_AmountToCurrencyCbid.md` |
| **System** | `inventory-transfer` / kill credits |
| **Verdict** | **accept-with-gaps** — tier ladder sealed; global CBID table values runtime-filled |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

Map a **64-bit credits amount** `(lo, hi)` to a **currency-item CBID** (or `-1` if amount is zero / negative hi).

Sole caller: `FUN_004d2750` (credits object spawn on kill path), which feeds the result into `CVOGReaction_GiveItemByCbid`.

### Tier ladder (amount as unsigned 64-bit, hi signed check)

| Condition | Return |
|---|---|
| `hi < 0` | `0xffffffff` (−1) |
| `hi > 0` **or** `lo > 999_999_999` | `DAT_00af1b5c` |
| `hi > 0` **or** `lo > 999_999` | `DAT_00af1b58` |
| `hi > 0` **or** `lo > 999` | `DAT_00af1b54` |
| `hi > 0` **or** `lo != 0` | `DAT_00af1b50` |
| else (`lo==0 && hi==0`) | `0xffffffff` |

Nested `if (-1 < hi)` repeats are decompiler noise; effective policy is magnitude buckets at **1e0 / 1e3 / 1e6 / 1e9**.

---

## 2. ABI

```c
// __cdecl (no this)
uint32_t Credits_AmountToCurrencyCbid(uint32_t amountLo, int32_t amountHi);
```

---

## 3. Globals

| Symbol | Role |
|---|---|
| `DAT_00af1b50` | CBID for amounts 1…999 |
| `DAT_00af1b54` | CBID for amounts 1_000…999_999 |
| `DAT_00af1b58` | CBID for amounts 1e6…999_999_999 |
| `DAT_00af1b5c` | CBID for amounts ≥1e9 or hi≠0 large |

Image read of `0x00af1b50..5c` at static analysis time is `0xffffffff`×4 — **table filled at runtime** (writers at `0x0051273f` / `0x00512760` / `0x00512781` / `0x005127a2`).

---

## 4. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | Ghidra `0x005123e0` |
| Raw / clean | `raw/aa_005123e0_*`, `FUN_005123e0.cpp` |
| Xrefs | only from `0x004d2760` inside `004d2750` |
| DAT writers | `0x005127xx` block |

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Magnitude → tier CBID | **Confirmed** |
| Zero → −1 | **Confirmed** |
| Negative hi → −1 | **Confirmed** |
| Concrete CBID values | **Open** (runtime init) |
| Product name “currency pile tiers” | **High** via sole credits-spawn caller |

---

## 6. Gaps

1. Runtime values of `DAT_00af1b50..5c` need capture.
2. Init function at `0x005127xx` not dualed here.

**Verdict:** **accept-with-gaps**.
