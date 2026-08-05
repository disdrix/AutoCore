# Review A (reconstruction fidelity): `aa_0071bd40` DES_PermuteBlock

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071bd40` |
| **VA** | `0x0071bd40` |
| **Canonical name** | `DES_PermuteBlock` |
| **System** | auth |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0071bd40_DES_PermuteBlock.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_0071bd40_DES_PermuteBlock.md` |
| Raw | `docs/reconstruction/raw/aa_0071bd40_DES_PermuteBlock.md` |
| Annotated | `docs/reconstruction/raw/aa_0071bd40_DES_PermuteBlock.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/DES_PermuteBlock.cpp` |
| Live decompile | Ghidra MCP `batch_decompile` / `decompile_function` @ `0x0071bd40` (autoassault.exe) |

Three-rep (raw + annotated + clean) **already present** — dual only this pass.

---

## 2. Purpose (from unit)

Table-driven 64-bit block permutation (IP or FP): zero 8-byte out (EAX), then for each of 8 input bytes (`param_1`) OR precomputed 8-byte contribs from table base EBX (hi nibble) and EBX+0x80 (lo nibble), stepping table groups by 0x20 until 0x100.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| 8-byte in (param_1) / 8-byte out (EAX) | **High** | body |
| Table base via EBX; +0x80 lo-nibble plane | **High** | unaff_EBX |
| Called twice from DES_EncryptBlock8 (IP then FP) | **High** | xrefs 0x0071c1c3, 0x0071c245 |
| IP table prep DAT_00d16ef0 from DAT_00afca50; FP DAT_00d12690 from DAT_00afca90 (via init FUN_0071b430) | **High** | DES_InitializeCipher callees |
| Plate: FP uses table at 0x00d12690 | **High** | EncryptBlock8 plate comment |
| Control flow preserved clean ≡ raw ≡ live Ghidra | **High** | Scaffold rewrite; no modernization of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred (no Launcher) |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| zero out[0..7] | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| i=0; do { hi=in>>4; lo=in&0xf; OR table[EBX+(hi+i)*8] and [EBX+0x80+(lo+i)*8] into out; i+=0x20; in++ } while i<0x100 | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| return | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |

---

## 5. Gaps

1. Caller must set EBX to IP vs FP table base — register contract not in C signature
2. Full IP/FP table contents not dumped here
3. Decompiler shows param on second call only; first call uses registers

**Verdict:** **accept-with-gaps**
