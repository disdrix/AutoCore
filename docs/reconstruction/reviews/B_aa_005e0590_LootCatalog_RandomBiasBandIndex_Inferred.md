# Review B (skeptical / adversarial): `aa_005e0590` LootCatalog_RandomBiasBandIndex_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e0590` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005e0590_LootCatalog_RandomBiasBandIndex_Inferred.md` |
| **Evidence** | Live decompile + `read_memory` body/constants + sole caller + RNG dual |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `CVOGReaction_RandomUnitScalar` returns float in [0,1] | Returns `&DAT_00d20c1c`; this FN reads table | **Falsified float-return** |
| 2 | No input (true void) | ESI is live max band; asm `cmp esi,2` | **Falsified void** — register param |
| 3 | Can upgrade quality/band | Only returns n, n−1, n−2 | **Falsified upgrade** |
| 4 | Thresholds 0.25 / 0.75 | Memory: 0.5 / ~0.333 / ~0.666 | **Falsified wrong thresholds** |
| 5 | Scale is `/65535` exactly | Bytes `80 00 80 37` ≈ 1/65536 (+ulp) | **Survives as ~1/65536** |
| 6 | Many callers | Only `005e0cd0` | **Falsified multi-caller** |
| 7 | Wrap at 0xfffff inclusive differently | Asm: `cmp [+0xc],0x100000` / jl keep | **Survives** as ≥ 0x100000 reset |
| 8 | Product name sealed | No string | **Not sealed** |
| 9 | ESI is definitely “player level” | No proof at this VA; residual | **Survives as gap** — do not invent |

---

## 2. Live ≡ raw

Live decompile matches raw control flow. Memory confirms:

- `call CVOGReaction_RandomUnitScalar`
- wrap / u16 load / index++
- `mulss` with `DAT_00aaa638`
- branch structure on ESI vs 2, then 0.5 / ~1/3 / ~2/3

Decompiler `unaff_ESI` is **not** a decompiler bug — intentional register-passed argument.

---

## 3. Surviving contract

```
// ESI = maxBand (required live input)
// f = U16(rng) * ~1/65536
// if maxBand <= 1: return maxBand
// if maxBand == 2: return (f < 0.5) ? 2 : 1
// if maxBand > 2:
//   if f < ~1/3: return maxBand
//   if f < ~2/3: return maxBand - 1
//   else:        return maxBand - 2
// never increases maxBand
```

**Gaps kept:** ESI English label at call site; runtime histogram; product name.

---

## 4. Cross-check vs `005e0cd0`

Caller uses return as `short` then `+ typeRow*0x32` into `catalog+0x10e13c` band row. Treat this unit as **pure bias RNG helper** — do not merge fill/copy logic into it.

---

## 5. Open questions

1. Who sets ESI before `call 005e0590` (likely outer filtered-roll path)?
2. Is maxBand a quality tier, level band, or rank cursor?
3. Runtime distribution under real table contents (not ideal uniform).

**Verdict:** **accept-with-gaps** — adversarial pass keeps bias CF + constants; ESI semantic residual acknowledged.
