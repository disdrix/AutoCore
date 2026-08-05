# Review A (reconstruction fidelity): `aa_0042b8b0` BitStream_readInt

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042b8b0` |
| **VA** | `0x0042b8b0` |
| **Canonical name** | `BitStream_readInt` |
| **System** | network-bitstream |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0042b8b0_BitStream_readInt.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_0042b8b0_BitStream_readInt.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_0042b8b0_BitStream_readInt.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BitStream_readInt.cpp` |


---

## 2. Purpose (from unit)

Read bitCount bits as integer via readBits; mask unless bitCount==0x20.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Thin wrapper on readBits | **High** |  |
| Mask omitted for 32-bit | **High** |  |
| Implicit this | **Medium** |  |
| Control flow preserved clean ≡ raw | **High** | Scaffold rewrite; no modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| local=0; readBits(bitCount,&local) | **Yes** (clean ≡ raw scaffold) |
| if bitCount!=0x20 mask (1<<n)-1 | **Yes** (clean ≡ raw scaffold) |
| return local | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. Free-func form vs thiscall
2. readBits error not checked

**Verdict:** **accept-with-gaps**
