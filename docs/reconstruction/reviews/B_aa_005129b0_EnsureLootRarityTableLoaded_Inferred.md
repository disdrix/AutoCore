# Review B (skeptical / adversarial): `aa_005129b0` EnsureLootRarityTableLoaded_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005129b0` |
| **VA** | `0x005129b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005129b0_EnsureLootRarityTableLoaded_Inferred.md` |
| **System** | inventory-transfer / loot tables |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Body is XP table ensure | Loader is `Inv_tLootRarity`, not quest/level XP | **Falsified** as XP |
| 2 | Early-outs if already loaded | No flag test; always `operator_new` | **Falsified** early-out claim |
| 3 | Load status checked / debug-stopped | No status test vs quest-credit ensures | **Falsified** — thin wrapper |
| 4 | `007ce130` is unrelated | Dual seals `//tLootRarity/row` | **Survives** as rarity loader |
| 5 | Scaffold name implies only InitInstance | Callers include kill-loot + UI paths | **Falsified** exclusivity |
| 6 | Alloc size is 0x280 / other | Imm **0x288** | **Survives** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Linear alloc → enter → load → leave | **High** | Wrong init order |
| Global `DAT_00b04214` | **High** | Consumer miss |
| Product = loot rarity table | **High** | via loader dual |
| Re-entrancy safety | **Open** | Leak / double-load |
| Name | **Probable** | Cosmetic |

---

## 3. Cross-check against raw (minimal)

Live ≡ raw. Sibling ensures (`005127f0`…`005128f0`) share enter/leave but pass map roots without `operator_new` in the thin wrapper — this unit is the **allocating** rarity twin.

---

## 4. Surviving contract for AutoCore

```
// Client table bring-up (rarity tiers)
void EnsureLootRarityTableLoaded() {
  g_pLootRarity = new (0x288);   // DAT_00b04214
  DbEnter();                     // FUN_007e1d80
  Inv_tLootRarity(g_pLootRarity);// FUN_007ce130
  DbLeave();                     // FUN_007b7df0
}
// Port: gate on null global if re-entry is possible; do not treat as XP ensure.
```

---

## 5. What would overturn this dual

1. Evidence `007ce130` at this call is not the rarity loader (wrong overload).
2. Asm showing conditional skip around `operator_new`.
3. Different global than `DAT_00b04214` written.

**Verdict:** **accept-with-gaps** — ensure CF High; re-entry policy open.
