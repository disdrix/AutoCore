# Review A (reconstruction fidelity): `aa_0071bf70` DES_RoundFunctionF

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071bf70` |
| **VA** | `0x0071bf70` |
| **Canonical name** | `DES_RoundFunctionF` |
| **System** | auth |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0071bf70_DES_RoundFunctionF.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_0071bf70_DES_RoundFunctionF.md` |
| Raw | `docs/reconstruction/raw/aa_0071bf70_DES_RoundFunctionF.md` |
| Annotated | `docs/reconstruction/raw/aa_0071bf70_DES_RoundFunctionF.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/DES_RoundFunctionF.cpp` |
| Live decompile | Ghidra MCP `batch_decompile` / `decompile_function` @ `0x0071bf70` (autoassault.exe) |

Three-rep (raw + annotated + clean) **already present** — dual only this pass.

---

## 2. Purpose (from unit)

DES Feistel f(R,K_i): expand R, XOR with 6-byte subkey at `DAT_00d16e90 + 6*round` (`EAX=round`), S-box substitute, then P-permute (`DES_CalculatePermutationP`).

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Round index in EAX; subkey offset = EAX*6 | **High** | iVar1 = in_EAX * 6 |
| Order: Expansion → XOR K → SBox → P | **High** | body call order |
| Subkeys at DAT_00d16e90 | **High** | XOR source |
| Callees: CalculateExpansion, CalculateSBoxSubstitution, CalculatePermutationP (0x0071bc40) | **High** | body + sibling decompile |
| Sole caller: DES_FeistelRound @ 0x0071c090 | **High** | xrefs |
| Control flow preserved clean ≡ raw ≡ live Ghidra | **High** | Scaffold rewrite; no modernization of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred (no Launcher) |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| offset = round*6 | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| DES_CalculateExpansion() | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| XOR 6 expanded bytes with DAT_00d16e90[offset..+5] | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| DES_CalculateSBoxSubstitution(&local_10) | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| DES_CalculatePermutationP(&local_10) | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| return (32-bit f result via registers/stack to FeistelRound) | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |

---

## 5. Gaps

1. Decompiler erases full register contract for R-in / f-out (stack locals confusing)
2. DES_CalculatePermutationP not dualled in this OWN set (sibling 0x0071bc40)
3. No known-answer f(R,K) vector

**Verdict:** **accept-with-gaps**
