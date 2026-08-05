# Review A (reconstruction fidelity): `aa_0071c000` DES_InitializeCipher

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071c000` |
| **VA** | `0x0071c000` |
| **Canonical name** | `DES_InitializeCipher` |
| **System** | auth |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0071c000_DES_InitializeCipher.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_0071c000_DES_InitializeCipher.md` |
| Raw | `docs/reconstruction/raw/aa_0071c000_DES_InitializeCipher.md` |
| Annotated | `docs/reconstruction/raw/aa_0071c000_DES_InitializeCipher.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/DES_InitializeCipher.cpp` |
| Live decompile | Ghidra MCP `batch_decompile` / `decompile_function` @ `0x0071c000` (autoassault.exe) |

Three-rep (raw + annotated + clean) **already present** — dual only this pass.

---

## 2. Purpose (from unit)

One-shot DES table/key setup: fold null-terminated key string (EAX) into 8-byte XOR-rotated buffer (max 0x28 chars), build IP/FP precompute tables (`FUN_0071b430`), run `DES_KeySchedule`, then build S/P LUTs (`FUN_0071bdd0`, `FUN_0071b5a0`).

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Key pointer in EAX at entry | **High** | in_EAX walk |
| Caller FUN_007293f0 (auth client ctor) sets EAX=0x00aa7640 before call | **High** | asm MOV EAX,0xaa7640 @ 0x0072943e; CALL @ 0x00729448 |
| Key string at 0x00aa7640 is 'TEST' (54 45 53 54 00...) | **High** | read_memory — overrides prior NETD plate claim |
| Key fold: for i<0x28 while *s: buf[i%8] ^= *s++ | **High** | body (signed mod &7 form) |
| FUN_0071b430(&DAT_00d16ef0,&DAT_00afca50) then (&DAT_00d12690,&DAT_00afca90) | **High** | IP then FP builders |
| Then DES_KeySchedule; FUN_0071bdd0; FUN_0071b5a0 | **High** | call order |
| Sole static caller: FUN_007293f0 | **High** | xrefs |
| Control flow preserved clean ≡ raw ≡ live Ghidra | **High** | Scaffold rewrite; no modernization of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred (no Launcher) |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| zero 8-byte local key accum | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| XOR-fold C-string key into 8 bytes (cap 40) | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| build IP table DAT_00d16ef0 from DAT_00afca50 | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| build FP table DAT_00d12690 from DAT_00afca90 | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| DES_KeySchedule(key) | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| FUN_0071bdd0(); FUN_0071b5a0()  // S/P related LUT build | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |
| return | **Yes** (clean ≡ raw ≡ live Ghidra 2026-07-29) |

---

## 5. Gaps

1. FUN_0071b430 / FUN_0071bdd0 / FUN_0071b5a0 bodies not dualled here
2. Whether key is always 'TEST' in all builds (only this image verified)
3. Prior Client_EncryptAndPrepare plate said NETD — **falsified by live string at call site**

**Verdict:** **accept-with-gaps**
