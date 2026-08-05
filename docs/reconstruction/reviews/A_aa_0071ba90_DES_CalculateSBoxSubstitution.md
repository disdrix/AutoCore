# Review A (reconstruction fidelity): `aa_0071ba90` DES_CalculateSBoxSubstitution

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071ba90` |
| **VA** | `0x0071ba90` |
| **Canonical name** | `DES_CalculateSBoxSubstitution` |
| **System** | auth |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0071ba90_DES_CalculateSBoxSubstitution.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_0071ba90_DES_CalculateSBoxSubstitution.md` |
| Raw | `docs/reconstruction/raw/aa_0071ba90_DES_CalculateSBoxSubstitution.md` |
| Annotated | `docs/reconstruction/raw/aa_0071ba90_DES_CalculateSBoxSubstitution.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/DES_CalculateSBoxSubstitution.cpp` |
| Live decompile | Ghidra MCP `batch_decompile` / `decompile_function` @ `0x0071ba90` (autoassault.exe) |

Three-rep (raw + annotated + clean) **already present** — dual only this pass.

---

## 2. Purpose (from unit)

Map 48-bit expanded+XOR'd block (6 bytes in EAX) through four precomputed S-box LUT banks (`DAT_00d12e90` / `d13e90` / `d14e90` / `d15e90`) into a 4-byte (32-bit) substitution result at `param_1`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Input is 6 bytes via EAX (48-bit E⊕K half) | **High** | reads in_EAX[0..5] |
| Output 4 bytes via param_1 (32-bit pre-P) | **High** | writes *param_1..[3] |
| Four LUT bases spaced 0x1000: d12e90,d13e90,d14e90,d15e90 | **High** | body indices |
| Index forms: (b0<<4)|(b1>>4)&0xf and CONCAT11 pairs & 0xfff | **High** | body |
| Sole caller: DES_RoundFunctionF @ 0x0071bfe3 | **High** | xrefs |
| Control flow preserved clean ≡ raw ≡ live Ghidra | **High** | Scaffold rewrite; no modernization of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred (no Launcher) |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| load 6 input bytes from EAX | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| LUT0: DAT_00d12e90[(EAX0<<4)|((EAX1>>4)&0xf)] -> out0 | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| LUT1: DAT_00d13e90[CONCAT11(EAX1,EAX2)&0xfff] -> out1 | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| LUT2: DAT_00d14e90[(EAX3<<4)|((EAX4>>4)&0xf)] -> out2 | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| LUT3: DAT_00d15e90[CONCAT11(EAX4,EAX5)&0xfff] -> out3 | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| return | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |

---

## 5. Gaps

1. LUTs are precomputed (built by FUN_0071bdd0/FUN_0071b5a0 path) — not classic 8×64 S-box matrices in this unit
2. Exact packing of S1..S8 into four 0x1000 banks not re-derived here
3. No vector proof vs FIPS S-boxes

**Verdict:** **accept-with-gaps**
