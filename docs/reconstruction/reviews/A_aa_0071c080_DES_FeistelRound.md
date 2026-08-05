# Review A (reconstruction fidelity): `aa_0071c080` DES_FeistelRound

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071c080` |
| **VA** | `0x0071c080` |
| **Canonical name** | `DES_FeistelRound` |
| **System** | auth |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0071c080_DES_FeistelRound.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_0071c080_DES_FeistelRound.md` |
| Raw | `docs/reconstruction/raw/aa_0071c080_DES_FeistelRound.md` |
| Annotated | `docs/reconstruction/raw/aa_0071c080_DES_FeistelRound.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/DES_FeistelRound.cpp` |
| Live decompile | Ghidra MCP `batch_decompile` / `decompile_function` @ `0x0071c080` (autoassault.exe) |

Three-rep (raw + annotated + clean) **already present** — dual only this pass.

---

## 2. Purpose (from unit)

One DES Feistel round: compute f via `DES_RoundFunctionF`, then write next 8-byte state as L'=R, R'=L XOR f (bytewise).

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Calls DES_RoundFunctionF once | **High** | body |
| L' = old R (EDI[4..7] → EBX[0..3]) | **High** | body |
| R' = old L XOR f (EDI[0..3] XOR local_4 → EBX[4..7]) | **High** | body |
| Sole caller: DES_EncryptBlock8 loop @ 0x0071c1d4 | **High** | xrefs |
| Round index passed (decompiler shows DES_FeistelRound(iVar1) from EncryptBlock8) | **High** | EncryptBlock8 body |
| Control flow preserved clean ≡ raw ≡ live Ghidra | **High** | Scaffold rewrite; no modernization of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred (no Launcher) |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| DES_RoundFunctionF → f32 in local_4 | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| out[0..3] = in[4..7]  // R→L | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| out[4..7] = in[0..3] XOR f bytes LE | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| return | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |

---

## 5. Gaps

1. EBX/EDI register contract not in C signature
2. Whether out and in alias (ping-pong buffers) sealed only at EncryptBlock8 asm level

**Verdict:** **accept-with-gaps**
