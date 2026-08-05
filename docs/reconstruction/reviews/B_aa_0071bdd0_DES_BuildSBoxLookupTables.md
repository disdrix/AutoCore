# Review B (skeptical / adversarial): `aa_0071bdd0` DES_BuildSBoxLookupTables

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071bdd0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0071bdd0_DES_BuildSBoxLookupTables.md` |
| **Verdict** | **accept-with-gaps** on CF (S-box LUT builder sealed; golden vectors + sibling open) |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This builds **P-permutation** tables | Writes only `d12e90` region; consumer is S-sub unit | **Falsified as P-builder** |
| 2 | Builds all DES tables (IP/FP/key/S/P) | No calls; only S constants → S LUTs | **Falsified** — S LUT only |
| 3 | Tables live in static image ready | BSS `d12e90` reads zero pre-init | **Falsified as prefilled** |
| 4 | Multiple callers | Single xref: `DES_InitializeCipher` | **Falsified** |
| 5 | `DAT_00afcb88` is a separate unrelated table | Address = `afcb48+0x40`; S2 prefix match | **Falsified as independent blob** — alias into same S1..S8 array |
| 6 | Outer loop is more than 4 banks | End `0xd16e91 - 0xd12e91 = 0x4000` | **Falsified** — exactly four 0x1000 banks |
| 7 | Output packing is one S-box per byte | `lo|hi<<4` from two index paths | **Falsified as single-nibble** — packed pair |
| 8 | Name is original PDB symbol | No PDB | **Gap** — role name only |
| 9 | Filled LUTs proven vs FIPS vectors this pass | No runtime fill / no offline recompute run | **Gap** — structure sealed, content open |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| CF / loop bounds / pack formula | **High** | Wrong auth crypto port |
| Output bases match S-sub consumer | **High** | Broken DES round |
| Source tables = DES S-boxes | **High** | Wrong cipher |
| Attribution of P tables to this VA | **Rejected** | Would mis-own W19-Q work |
| Bit-exact filled content | **Open** | Subtle index bugs undetected |
| Runtime re-init safety | **Open** | Unobserved |

---

## 3. Cross-check raw + live

Live decompile body **byte-identical in structure** to 2026-07-23 raw. Entry bytes:

```
0071bdd0  push ebx / ebp / esi / edi
0071bdd4  xor  edx, edx           ; bank base iVar3
0071bdd6  mov  ebp, 0x00d12e91    ; write cursor
...
0071bf68  ret
```

Outer bound material near epilog: compare against `0x00d16e91`.  
Source S1 prefix at `0x00afcb48`: `0e 04 0d 01 02 0f 0b 08 03 0a 06 0c 05 09 00 07` — classic DES S1 row0.

Consumer seal (`aa_0071ba90`): reads `d12e90` / `d13e90` / `d14e90` / `d15e90` — same bases this function fills.

---

## 4. Surviving contract for AutoCore

```
// During DES_InitializeCipher, after key schedule:
DES_BuildSBoxLookupTables();   // fill 4×0x1000 S LUT banks
// then FUN_0071b5a0()          // sibling — not this VA
// DES_CalculateSBoxSubstitution later indexes those banks
```

Client auth DES path requires these banks non-zero after init. Server/auth ports that reimplement DES must either call equivalent expand or ship precomputed tables.

---

## 5. Gaps surviving attack

1. Golden-vector fill verification.
2. Exact S1..S8 pair order pedagogy for each bank.
3. Sibling `FUN_0071b5a0` (W19-Q).
4. Original studio symbol.

**Verdict:** **accept-with-gaps**
