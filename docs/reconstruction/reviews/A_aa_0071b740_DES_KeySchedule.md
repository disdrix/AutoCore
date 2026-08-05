# Review A (reconstruction fidelity): `aa_0071b740` DES_KeySchedule

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071b740` |
| **VA** | `0x0071b740` |
| **Canonical name** | `DES_KeySchedule` |
| **System** | auth |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0071b740_DES_KeySchedule.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_0071b740_DES_KeySchedule.md` |
| Raw | `docs/reconstruction/raw/aa_0071b740_DES_KeySchedule.md` |
| Annotated | `docs/reconstruction/raw/aa_0071b740_DES_KeySchedule.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/DES_KeySchedule.cpp` |
| Live decompile | Ghidra MCP `batch_decompile` / `decompile_function` @ `0x0071b740` (autoassault.exe) |

Three-rep (raw + annotated + clean) **already present** — dual only this pass.

---

## 2. Purpose (from unit)

Build 16 DES round subkeys (6 bytes each, 0x60 total) at `DAT_00d16e90` from an 8-byte key buffer (`param_2`), using PC-1 table `DAT_00afcad0`, rotation schedule `DAT_00afcb08`, PC-2 at `DAT_00afcb18..`, and bit masks `DAT_00afcd68` (0x80..0x01).

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| PC-1 table at 0x00afcad0 is standard DES PC-1 (56 entries) | **High** | read_memory: 57,49,41,...4 matches FIPS PC-1 |
| Rotation schedule 1,2,4,6,8,10,12,14,15,17,19,21,23,25,27,28 | **High** | read_memory 0x00afcb08 |
| Bit masks DAT_00afcd68 = 0x80,0x40,...,0x01 | **High** | read_memory |
| Round-key store DAT_00d16e90 zeroed then filled 16×6 bytes (local_10 < 0x60) | **High** | body loop |
| Caller: DES_InitializeCipher @ 0x0071c066 only | **High** | bulk xrefs |
| __fastcall param_2 = key byte pointer | **High** | used as key base; param_1 unused in body |
| Control flow preserved clean ≡ raw ≡ live Ghidra | **High** | Scaffold rewrite; no modernization of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred (no Launcher) |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| PC-1 expand 56 key bits into DAT_00d176f0 bit array | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| zero 0x60 bytes of DAT_00d16e90 (0x18 dwords) | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| 16 rounds: rotate C/D halves via DAT_00afcb08 schedule | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| PC-2 pack into 6-byte subkey at DAT_00d16e90 + local_10 | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| return | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |

---

## 5. Gaps

1. Full PC-2 table not fully dumped in this review (partial 0x00afcb18+)
2. Intermediate C/D rotate wrap thresholds are decompiler-dense (0x1a/0x1b/0x18 constants) — high CF match but hard to restate as readable rotate-n
3. No known-answer vector vs standard DES key schedule

**Verdict:** **accept-with-gaps**
