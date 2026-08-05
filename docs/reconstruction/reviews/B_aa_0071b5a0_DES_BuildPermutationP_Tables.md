# Review B (skeptical / adversarial): `DES_BuildPermutationP_Tables` @ `0x0071b5a0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071b5a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0071b5a0_DES_BuildPermutationP_Tables.md` |
| **Tools** | Ghidra `decompile_function`, `read_memory`; no `disassemble_bytes` |
| **Verdict** | **accept-with-gaps** on CF / role; **needs-more-evidence** on post-init bank dumps |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This unit **applies** P to a 32-bit half-block | Body never reads a ciphertext buffer; only fills LUTs | **Falsified as apply** — it is a **builder** |
| 2 | Tables live ready in the offline EXE | `read_memory` @ d11658 all-zero | **Falsified** — runtime fill only |
| 3 | Clear size is 0x1000 **bytes** of stosb | `mov ecx,0x400` + `rep stosd` = 0x400 **dwords** = 0x1000 bytes | **Nuanced** — size correct if counted as dwords |
| 4 | `DAT_00afcd48` is S-box data | Bytes are 1..32 permutation positions matching FIPS **P**, not 0..15 S-box | **Falsified as S-box** |
| 5 | Builder is also called from Feistel each round | Single xref: `DES_InitializeCipher` only | **Falsified** |
| 6 | Clean is a portable OpenSSL-style API | Still mirrors decompiler address arithmetic | **Scaffold** — map only |
| 7 | Bank packing proven ≡ FIPS for all rows | No post-init dump / known-answer | **Open** |
| 8 | `uVar5+0xafcd47` is a second table | Same P blob, index `uVar5-1` | **Overstated as second table** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Role = P bank builder for CalculatePermutationP | **High** | Wrong DES F path |
| FIPS P constant identity | **High** | Wrong permutation |
| Clear extent 0x1000 bytes @ d11658 | **High** | Adjacent BSS clobber |
| Init-only call | **High** | Missed re-init path |
| Row packing bit-exact without dump | **Medium** | Port reimplementation diverge |
| Clean as production crypto | **Low** | Do not ship as library |

---

## 3. Surviving contract for AutoCore

```
DES_BuildPermutationP_Tables():
  zero P_bank[0..3][0..255][0..3] @ DAT_00d11658   // 0x1000 bytes
  for bank in 0..3:
    for inByte in 0..255:
      for outBit in 0..31:
        srcBit = P_fips[outBit] - 1
        if (srcBit >> 3) == bank and (inByte & mask[srcBit & 7]):
          P_bank[bank][inByte][outBit >> 3] |= mask[outBit & 7]

// Called once from DES_InitializeCipher after S-box bank builder (FUN_0071bdd0).
// Consumer: DES_CalculatePermutationP ORs four bank rows by S-box out bytes.
```

---

## 4. Open questions

1. Dump banks after init; match against independent FIPS P expansion.
2. Confirm `FUN_0071bdd0` ownership of S-box banks only (not dualled here).
3. Whether any path re-clears banks without rebuild.

**Verdict:** **accept-with-gaps** on CF — safe behavioral map for auth DES init; do not treat clean as bit-exact crypto until bank dumps + KAT pass.
