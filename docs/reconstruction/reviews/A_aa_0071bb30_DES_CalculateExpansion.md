# Review A (reconstruction fidelity): `aa_0071bb30` DES_CalculateExpansion

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071bb30` |
| **VA** | `0x0071bb30` |
| **Canonical name** | `DES_CalculateExpansion` |
| **System** | auth |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0071bb30_DES_CalculateExpansion.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_0071bb30_DES_CalculateExpansion.md` |
| Raw | `docs/reconstruction/raw/aa_0071bb30_DES_CalculateExpansion.md` |
| Annotated | `docs/reconstruction/raw/aa_0071bb30_DES_CalculateExpansion.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/DES_CalculateExpansion.cpp` |
| Live decompile | Ghidra MCP `batch_decompile` / `decompile_function` @ `0x0071bb30` (autoassault.exe) |

Three-rep (raw + annotated + clean) **already present** — dual only this pass.

---

## 2. Purpose (from unit)

DES expansion E: take 32-bit right half (4 bytes at `param_1` / fastcall) and write 48-bit expanded form (6 bytes) to buffer in EAX via bit-shuffle arithmetic (no table walk).

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Input 4 bytes (R half) via __fastcall param_1 | **High** | reads param_1[0..3] |
| Output 6 bytes via EAX | **High** | writes in_EAX[0..5] |
| Pure bit arithmetic expansion (no DAT table) | **High** | body |
| Sole caller: DES_RoundFunctionF @ 0x0071bf82 | **High** | xrefs |
| System tag missions-progression on record is heuristic mis-tag | **High** | auth DES chain only |
| Control flow preserved clean ≡ raw ≡ live Ghidra | **High** | Scaffold rewrite; no modernization of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred (no Launcher) |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| load R0..R3 | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| compute E[0..5] bit fields with shifts/masks/xors | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| store 6-byte expansion to EAX buffer | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| return | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |

---

## 5. Gaps

1. Bit formula not re-expanded into standard E-bit table listing in this dual
2. No known-answer vector (R → E(R))

**Verdict:** **accept-with-gaps**
