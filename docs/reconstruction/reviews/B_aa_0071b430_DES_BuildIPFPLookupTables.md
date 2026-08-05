# Review B (skeptical / adversarial): `aa_0071b430` DES_BuildIPFPLookupTables

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071b430` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W25-Q) |
| **Counterpart** | `reviews/A_aa_0071b430_DES_BuildIPFPLookupTables.md` |
| **Verdict** | **accept-with-gaps** on sealed CF/role; reject listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This unit **applies** IP/FP to a live 64-bit block | Body never reads ciphertext; only fills LUT from static perm | **Falsified as apply** — **builder** |
| 2 | Tables ready offline in EXE | Outputs are BSS (`d16ef0`/`d12690`); filled only at init | **Falsified** as static-ready |
| 3 | Clear size is 0x200 **bytes** | `ecx=0x200` dwords ×4 = **0x800** bytes | **Falsified** if claimed as bytes |
| 4 | Source is S-box data | `afca50`/`afca90` are 1..64 positions = FIPS IP/FP | **Falsified as S-box** |
| 5 | Builder re-runs every Feistel round | Sole caller `DES_InitializeCipher` (×2 sites IP/FP) | **Falsified** |
| 6 | Same as `DES_BuildPermutationP_Tables` (`0071b5a0`) | Different VA, bounds, outputs, source (P vs IP/FP) | **Falsified as same unit** |
| 7 | Same as `DES_BuildSBoxLookupTables` (`0071bdd0`) | S-box banks d12e90..; this is block-perm nibble LUT | **Falsified** |
| 8 | stdcall / `ret 8` | Epilogue bare `c3` after local `add esp,8` | **Falsified** as stdcall |
| 9 | Bit-exact filled LUT verified | Static dual only; no post-init dump | **Fail** if claimed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Role = IP/FP nibble LUT builder | **High** | Wrong DES init |
| FIPS IP/FP constant identity | **High** | Wrong permutation |
| Clear 0x800 bytes | **High** | Adjacent BSS clobber |
| Init-only dual call (IP then FP) | **High** | Missed re-init |
| Row packing bit-exact without dump | **Medium** | Port reimplementation diverge |
| Clean as production crypto library | **Low** | Do not ship as OpenSSL stand-in |

---

## 3. Cross-check

| Item | Result |
|---|---|
| Raw ≡ live decompile | **Yes** |
| Body hex via `read_memory` | **Yes** — starts `83ec08…`, ends `…83c408c3` |
| IP @ `0x00afca50` FIPS | **Yes** |
| FP @ `0x00afca90` FIPS | **Yes** |
| Masks afcd68/afcd88 | **Yes** |
| Sole caller InitializeCipher | **Yes** |
| Distinct from P-builder / S-box builder | **Yes** |

**Attack on "this is runtime permute":** **Fails** — pure table expand.

**Attack on "same as P-table builder":** **Fails** — different bounds/outputs/source.

---

## 4. Surviving contract for AutoCore

```
// cdecl: dst[0x800], perm[64] 1-based FIPS IP or FP
DES_BuildIPFPLookupTables(dst, perm):
  zero dst as 0x200 dwords
  for group in 0..15:           // local_4; rowBase = group*16
    for nibble in 0..15:        // uVar6
      for bitPos in 0..63:      // unrolled ×4
        src = perm[bitPos] - 1
        if (src >> 2) == group and (nibble_mask[src & 3] & nibble):
          dst[(rowBase+nibble)*8 + (bitPos >> 3)] |= out_mask[bitPos & 7]

// Called twice from DES_InitializeCipher only:
//   IP → DAT_00d16ef0 from DAT_00afca50
//   FP → DAT_00d12690 from DAT_00afca90
// Consumer: DES_PermuteBlock
```

**Falsified port mistakes:**

- Treating as per-block IP/FP apply (that is `DES_PermuteBlock`).
- Confusing with S-box (`0071bdd0`) or P (`0071b5a0`) builders.
- Assuming offline-filled tables.
- Using stdcall `ret 8`.

---

## 5. Open questions

1. Dump filled IP/FP banks after init; match independent FIPS expand.
2. Product/PDB symbol.
3. Whether any path re-clears banks without rebuild.

**Verdict:** **accept-with-gaps** — safe behavioral map for auth DES init; do not treat clean as bit-exact crypto until bank dumps + KAT pass.
