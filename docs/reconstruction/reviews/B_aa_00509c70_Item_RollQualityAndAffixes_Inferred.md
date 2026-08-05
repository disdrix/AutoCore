# Review B (skeptical / adversarial): `aa_00509c70` Item_RollQualityAndAffixes_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00509c70` |
| **VA** | `0x00509c70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00509c70_Item_RollQualityAndAffixes_Inferred.md` |
| **System** | inventory-transfer / combat death loot |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Always applies broken flag | Broken only if `param_4`, rand%100 < 11, `00513cf0`, zone gate | **Falsified** as always |
| 2 | Function is GiveItem itself | Callers GiveItem first; this mutates existing item | **Falsified** |
| 3 | Quality scales ignore Broken | Bit 19 selects alternate DAT constants | **Falsified** claim — broken **does** change scales |
| 4 | All item types get affix floats | Switch only handles 6 cases; others fall through | **Survives** |
| 5 | Finish block always runs | Entire tail gated on `param_4 != 0` | **Survives** — callers pass 0 or 1 deliberately |
| 6 | `operator_delete` on skill targets is normal return | Decompiler “does not return” warnings | **Ghidra artifact** — treat as free after use |
| 7 | Name Confirmed retail | Inferred from loot call graph + behavior | **Probable / leave-FUN** |
| 8 | Random scale is 1/65535 | `DAT_00aaa638` = **1/65536** | **Falsified** if 65535 claimed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Type switch membership | **High** | Wrong gear stat tables |
| Unit random + tier thresholds | **High** | Economy skew |
| Broken bit interaction | **High** | Broken items roll wrong scales |
| Finish / broken / mod-pack tail | **High** CF; **Probable** product labels | Missing durability |
| Per-case float offsets | **High** offsets; **Tentative** names | Port field map wrong |
| Formal meanings | **Probable** | Seed mismatch |

---

## 3. Cross-check against raw (minimal)

Live large decompile ≡ raw annotated body (quality preamble, switch, finish with `00509b10` / skill tints / `00513cf0` / `00513de0`).

`KillLoot_RollTableItems` dual already flagged this unit as “quality roll?” — **upgraded** here to High CF with sealed constants; product field names remain Tentative.

---

## 4. Surviving contract for AutoCore

```
// After item spawn / give:
void Item_RollQualityAndAffixes(
    Item* item,
    int qualityHint,      // param_2
    int streamOrSeed,     // param_3
    bool doFinish,        // param_4
    float seedScale);     // param_5

// Port rules:
// - null item → no-op
// - use 1/65536 unit random, not 1/65535
// - if !doFinish, skip durability/broken/skill-tint tail
// - type allow-list must match Item_IsAffixableType (00513d10)
// - Broken bit (item+0x17c bit19) selects alternate quality scales
```

---

## 5. What would overturn this dual

1. Asm proof switch uses different type codes than `def+0x38`.
2. Evidence `param_4` is not a finish gate (e.g. always nonzero in all retail paths — still a gate).
3. Different float constants in another image build.

**Verdict:** **accept-with-gaps** — roller CF High; type-case field lexicon open.
