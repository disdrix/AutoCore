# Review A (reconstruction fidelity): `aa_0071bdd0` DES_BuildSBoxLookupTables

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071bdd0` |
| **VA** | `0x0071bdd0` |
| **Canonical name** | `DES_BuildSBoxLookupTables` |
| **Prior names** | `FUN_0071bdd0` |
| **Review date** | `2026-07-29` (dual A/B — W19-P OWN) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_0071bdd0_DES_BuildSBoxLookupTables.md` |
| **System** | `auth` / DES |
| **Dual status** | **Present** (supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**One-shot DES S-box LUT expansion.** Reads FIPS-style S-box nibble tables and writes four precomputed **0x1000-byte** banks used by the round function's S substitution step.

```
DAT_00afcb48 / DAT_00afcb88  →  DAT_00d12e90, d13e90, d14e90, d15e90
```

**Calling convention:** no args; plain `ret`. Sole caller `DES_InitializeCipher` after `DES_KeySchedule`, before sibling `FUN_0071b5a0`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0071bdd0_FUN_0071bdd0.md` (+ 2026-07-29 live) |
| Annotated | `docs/reconstruction/raw/aa_0071bdd0_FUN_0071bdd0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/DES_BuildSBoxLookupTables.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0071bdd0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0071bdd0_DES_BuildSBoxLookupTables.md` |
| Live decompile | Ghidra `decompile_function` `0x0071bdd0` (2026-07-29) ≡ raw body |
| Live bytes | entry `0x0071bdd0` + epilog `0x0071bf50` |
| Source tables | `read_memory` `0x00afcb48` length 512; `0x00afcb88` |
| Output BSS | `read_memory` `0x00d12e90` (zeros in static image) |
| Xrefs | sole CALL from `DES_InitializeCipher` @ `0x0071c06b` |
| Consumer | dual unit `aa_0071ba90` DES_CalculateSBoxSubstitution |

**Not performed:** `disassemble_bytes`, Launcher, filled-table golden vectors, W19-Q body of `FUN_0071b5a0`.

---

## 3. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| `iVar3 = 0`; cursor = `&DAT_00d12e91` | **Yes** — `xor edx,edx`; `mov ebp, 0x00d12e91` |
| Outer: emit bank while cursor < `0x00d16e91` | **Yes** — end check at epilog region |
| Inner: `uVar5 = 2`; step 4 while `uVar5+2 < 0x1000` | **Yes** — decompile |
| 4 bytes per inner iter (indices u-2..u+1) | **Yes** |
| Pack: lo = `afcb88[…]&0xf`, hi = `afcb48[…]<<4` | **Yes** |
| `iVar3 += 8` per bank (0,8,16,24) | **Yes** |
| No callees | **Yes** |
| `ret` | **Yes** — `5f 5e 5d 5b c3` |

### 3.1 Bank geometry — **SEALED**

| Bank | Base | Size |
|------|------|------|
| 0 | `DAT_00d12e90` | `0x1000` |
| 1 | `DAT_00d13e90` | `0x1000` |
| 2 | `DAT_00d14e90` | `0x1000` |
| 3 | `DAT_00d15e90` | `0x1000` |

Total span `0x4000`; consumer `DES_CalculateSBoxSubstitution` indexes exactly these four bases.

### 3.2 Source table identity — **SEALED as FIPS DES S-boxes**

`DAT_00afcb48` first 64 bytes match classic **S1** (`0e 04 0d 01 02 0f 0b 08 …`).  
`DAT_00afcb88` (= `afcb48+0x40`) matches classic **S2** (`0f 01 08 0e …`).  
Full `read_memory` 512 bytes covers S1..S8.

### 3.3 Role vs P-permutation builder — **SEALED**

This unit only touches S-box constants → S-substitution LUT banks. P-related tables / `FUN_0071b5a0` are **out of OWN set** (W19-Q) and must not be attributed to this VA.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = build S-box LUTs for round S-step | **High / Sealed** | consumer + write targets |
| CF double-loop / index formulas | **High / Sealed** | clean ≡ raw ≡ live |
| Four 0x1000 banks d12e90..d15e90 | **High / Sealed** | end `0xd16e91` |
| Source = FIPS S1..S8 layout | **High** | byte prefixes + 512 span |
| Sole caller InitializeCipher | **High** | xrefs |
| Filled LUT golden-vector proof | **Open** | deferred |
| Canonical PDB name | **Probable** | role-based |

---

## 5. Gaps

1. Pedagogical map of bank/`iVar3` → exact S-box pair order (formula sealed).
2. Bit-exact verification of filled 0x4000 against independent DES SP-box generator.
3. Sibling `FUN_0071b5a0` body (W19-Q).
4. Runtime init once / re-entry behavior (static analysis only).

**Verdict:** **accept-with-gaps**
