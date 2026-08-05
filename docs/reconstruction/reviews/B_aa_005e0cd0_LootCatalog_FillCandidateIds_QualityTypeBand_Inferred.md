# Review B (skeptical / adversarial): `aa_005e0cd0` LootCatalog_FillCandidateIds_QualityTypeBand_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e0cd0` |
| **VA** | `0x005e0cd0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005e0cd0_LootCatalog_FillCandidateIds_QualityTypeBand_Inferred.md` |
| **Evidence** | Live decompile + epilogue + helpers + sole caller `005e1150` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same function as `005e07d0` | Different offsets, helpers, caller | **Falsified** |
| 2 | Performs exclusion-list filter | That is `005e1150` after return | **Falsified** |
| 3 | Randomly returns one ID | Returns 0/1 emptiness; vector holds many IDs | **Falsified** |
| 4 | Skips band copy when typed slice runs | Body **always** copies `+0x10e13c` row after optional typed path | **Falsified skip** |
| 5 | Type code used raw as row | `005e0480` remaps | **Falsified** |
| 6 | No random | `005e0590` band bias is RNG | **Falsified no-RNG** |
| 7 | `__cdecl` | `ret 0x18` + thiscall ECX | **Falsified** |
| 8 | Unreachable-block warnings mean wrong CF | Dead SEH/switch tails; main path live | **Falsified as CF break** |
| 9 | Product name sealed | No string | **Not sealed** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Fill for filtered roll path | **Confirmed** | Wrong loot table family |
| Dual copy (typed optional + band always) | **High** | Missing candidates |
| Return emptiness bool | **Confirmed** | Caller fail path |
| `005e0590` bias correctness | **Med** | ESI residual |
| Extra stack formal / sentinel | **Med** | ABI port |
| Runtime | **Open** | — |

---

## 3. Surviving contract for AutoCore

```
// this = catalog; out vector of candidate IDs
typeRow = TypeCodeToRow(typeCode)
qBand = clamp quality → 0..3
tIdx  = clamp typeParam → 0..4
idx = RandomBandBias() + typeRow * 50
if quality/type in narrow window:
  optional clear cell; copy typed cell → out
copy band row (catalog+0x10e13c+idx*0x140) → out
return out.nonempty
// NOT pick; NOT exclude-list; NOT 005e07d0 tables
```

---

## 4. Cross-check vs `005e1150`

Caller: fill with this → strip excludes/invalids → random pick. Treat this unit as **pure fill**. Do not move filter logic downward.

---

## 5. Open questions

1. Sentinel `0xffffffff` stack formal meaning (dual notes vs decompiler `param_6`).
2. `005e0590` level input (ESI).
3. Runtime distribution of bias indices.

**Verdict:** **accept-with-gaps** — adversarial pass keeps alternate-fill CF; ESI/ABI residual.
