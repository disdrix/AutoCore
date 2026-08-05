# Review A (reconstruction fidelity): `aa_0042b4a0` BitStream_writeBits

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b4a0` |
| **VA** | `0x0042b4a0` |
| **Canonical name** | `BitStream_writeBits` |
| **System** | network-bitstream |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0042b4a0_BitStream_writeBits.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_0042b4a0_BitStream_writeBits.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_0042b4a0_BitStream_writeBits.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BitStream_writeBits.cpp` |


---

## 2. Purpose (from unit)

Write N bits from source into BitStream; capacity grow via FUN_0042b450; aligned and unaligned paths.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Zero count success no-op | **High** |  |
| Capacity this+0x30 bits | **High** |  |
| Grow FUN_0042b450 | **High** |  |
| Partial-byte merge preserved | **High** |  |
| param_2 is bit count | **Medium** | typed byte* but used as int |
| Control flow preserved clean ≡ raw | **High** | Scaffold rewrite; no modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| bitCount==0 return 1 | **Yes** (clean ≡ raw scaffold) |
| if bitPos+count>capacity(+0x30): grow; fail clamp return 0 | **Yes** (clean ≡ raw scaffold) |
| Aligned byte copy + residual | **Yes** (clean ≡ raw scaffold) |
| Unaligned shift/merge | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. FUN_0042b450 grow not dual-reviewed here
2. Decomp types bit-count as byte*

**Verdict:** **accept-with-gaps**
