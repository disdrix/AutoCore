# Review A (reconstruction fidelity): `aa_0071c1b0` DES_EncryptBlock8

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071c1b0` |
| **VA** | `0x0071c1b0` |
| **Canonical name** | `DES_EncryptBlock8` |
| **System** | auth |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0071c1b0_DES_EncryptBlock8.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_0071c1b0_DES_EncryptBlock8.md` |
| Raw | `docs/reconstruction/raw/aa_0071c1b0_DES_EncryptBlock8.md` |
| Annotated | `docs/reconstruction/raw/aa_0071c1b0_DES_EncryptBlock8.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/DES_EncryptBlock8.cpp` |
| Live decompile | Ghidra MCP `batch_decompile` / `decompile_function` @ `0x0071c1b0` (autoassault.exe) |

Three-rep (raw + annotated + clean) **already present** — dual only this pass.

---

## 2. Purpose (from unit)

Standard DES 64-bit block encrypt (ECB one block): IP (`DES_PermuteBlock`), 16 Feistel rounds, final half-swap into stack buffer, FP (`DES_PermuteBlock`). Used by auth login to encrypt 3×8-byte credential blocks.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| IP then 16× FeistelRound then FP | **High** | body + plate comment |
| Round loop i=0..0x0f | **High** | while iVar1 < 0x10 |
| Post-round half swap into local_90..local_89 then FP | **High** | body |
| Caller Client_EncryptAndPrepareAuthRequest @ 0x00729013 only (static) | **High** | xrefs + asm loop EBX=3, ESI+=8 |
| Auth uses ECB ×3 on first 24 bytes of 30-byte cred buffer | **High** | caller asm + clean plate |
| Block pointer: PUSH ESI; MOV EAX,ESI before CALL | **High** | asm context |
| Control flow preserved clean ≡ raw ≡ live Ghidra | **High** | Scaffold rewrite; no modernization of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred (no Launcher) |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| DES_PermuteBlock()  // IP; EBX=IP table | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| for i in 0..15: DES_FeistelRound(i) | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| assemble swapped halves into local_90[8] | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| DES_PermuteBlock(&local_90)  // FP; EBX=FP table | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| return (ciphertext in caller block buffer via register contract) | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |

---

## 5. Gaps

1. Full stack/register map for in-place vs out buffer still decompiler-blurry (local_90 / local_8 / local_4)
2. Bit-exact vs OpenSSL DES_ecb_encrypt with key TEST not run
3. No decrypt twin dualled

**Verdict:** **accept-with-gaps**
