# Review A (reconstruction fidelity): `aa_0042b670` BitStream_readBits

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b670` |
| **VA** | `0x0042b670` |
| **Canonical name** | `BitStream_readBits` |
| **System** | network-bitstream |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0042b670_BitStream_readBits.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_0042b670_BitStream_readBits.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_0042b670_BitStream_readBits.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BitStream_readBits.cpp` |


---

## 2. Purpose (from unit)

Read N bits into destination; set error +0x1c return 0 if past end; aligned/unaligned.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| End bound this+0x2c | **High** |  |
| Error sticky on OOB | **High** |  |
| Return 1/0 | **High** |  |
| Unaligned extract preserved | **High** |  |
| Control flow preserved clean ≡ raw | **High** | Scaffold rewrite; no modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| if count!=0 and bitPos+count>end: error return 0 | **Yes** (clean ≡ raw scaffold) |
| aligned byte loop | **Yes** (clean ≡ raw scaffold) |
| unaligned shift/merge + residual | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. Zero-count edge fallthrough
2. Dest buffer size not validated

**Verdict:** **accept-with-gaps**
