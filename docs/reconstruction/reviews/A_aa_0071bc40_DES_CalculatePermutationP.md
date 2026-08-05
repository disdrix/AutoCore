# Review A (reconstruction fidelity): `aa_0071bc40` DES_CalculatePermutationP

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071bc40` |
| **VA** | `0x0071bc40` |
| **Canonical name** | `DES_CalculatePermutationP` |
| **System** | auth |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0071bc40_DES_CalculatePermutationP.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_0071bc40_DES_CalculatePermutationP.md` |
| Raw | `docs/reconstruction/raw/aa_0071bc40_DES_CalculatePermutationP.md` |
| Annotated | `docs/reconstruction/raw/aa_0071bc40_DES_CalculatePermutationP.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/DES_CalculatePermutationP.cpp` |
| Live decompile | Ghidra MCP `decompile_function` @ `0x0071bc40` (autoassault.exe) |
| Memory | Ghidra MCP `read_memory` @ `DAT_00d11658` / `d11a58` / `d11e58` / `d12258` |

Three-rep (raw + annotated + clean) **present and sealed this pass** (supersedes FUN scaffold naming).

---

## 2. Purpose (from unit)

DES **P-permutation**: take 4-byte (32-bit) S-box output at `param_1` and write 4-byte P-permuted result to buffer in **EAX** by OR-ing four precomputed per-byte contribution rows (no classic bit-loop; table-driven).

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Input 4 bytes (S-box half) via stack `param_1` | **High** | reads param_1[0..3] |
| Output 4 bytes via EAX | **High** | zero then OR into in_EAX[0..3] |
| Four LUT bases: d11658, d11a58, d11e58, d12258 (stride 0x400) | **High** | body + audit_globals |
| Index form: entry = bank[byte*4 .. +3], OR into out | **High** | body; bank0 uses undefined4* scale |
| Leaf; sole caller DES_RoundFunctionF @ 0x0071bff1 | **High** | xrefs |
| LUTs empty offline; filled at DES_InitializeCipher | **High** | read_memory all-zero; sibling init dual |
| Control flow preserved clean ≡ raw ≡ live Ghidra | **High** | byte-identical body |
| Bit-for-bit / runtime / differential / FIPS P vector | **Open** | Deferred (no Launcher; tables empty) |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| zero out[0..3] | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| bank0 DAT_00d11658 ← param_1[0] OR contrib | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| bank1 DAT_00d11a58 ← param_1[1] OR contrib | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| bank2 DAT_00d11e58 ← param_1[2] OR contrib | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| bank3 DAT_00d12258 ← param_1[3] OR contrib | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| return in_EAX + 3 | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |

---

## 5. Gaps

1. LUT contents not dumped post-init — cannot prove ≡ FIPS P bit table from static image alone
2. Builder which of `FUN_0071bdd0` / `FUN_0071b5a0` fills P banks not dualled in this OWN set
3. No known-answer vector (S32 → P(S32))
4. Return `in_EAX+3` is decompiler pointer artifact; Feistel consumer reads buffer not return value

**Verdict:** **accept-with-gaps**
