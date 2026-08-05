# Review A (reconstruction fidelity): `aa_0042ad50` BitStream_readFlag

| Field | Value |
|---|---|
| **Stable ID** | `aa_0042ad50` |
| **VA** | `0x0042ad50` |
| **Canonical name** | `BitStream_readFlag` |
| **System** | network-bitstream |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0042ad50_BitStream_readFlag.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_0042ad50_BitStream_readFlag.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_0042ad50_BitStream_readFlag.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BitStream_readFlag.cpp` |


---

## 2. Purpose (from unit)

Read one bit flag from BitStream; set overflow error at +0x1c if past end; store 0/1 into out param.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Bit cursor this+0x18 | **High** |  |
| End bound this+0x2c | **High** |  |
| Error sticky this+0x1c | **High** |  |
| Buffer base this+0xc | **High** |  |
| Return true means no error | **High** |  |
| Control flow preserved clean ≡ raw | **High** | Scaffold rewrite; no modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| bitPos=this+0x18; if bitPos>end(+0x2c): error=1 *out=0 | **Yes** (clean ≡ raw scaffold) |
| else sample bit from buf+0xc; ++bitPos; return error==0 | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. Full BitStream class layout incomplete
2. thiscall confirmed by decompile only

**Verdict:** **accept-with-gaps**
