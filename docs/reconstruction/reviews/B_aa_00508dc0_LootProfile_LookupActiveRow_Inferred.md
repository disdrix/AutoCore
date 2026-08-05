# Review B (skeptical / adversarial): `aa_00508dc0` LootProfile_LookupActiveRow_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508dc0` |
| **VA** | `0x00508dc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00508dc0_LootProfile_LookupActiveRow_Inferred.md` |
| **System** | missions-progression / combat death loot |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Function generates loot / awards credits | Body is pure map lookup; no random, no GiveItem | **Falsified** as generator — **lookup only** |
| 2 | Always returns non-null on valid table | Empty `+0xb8` or end-sentinel → 0 | **Falsified** |
| 3 | Key is always `param_1` (table ptr as key) | Decompiler stores `local_4 = param_1` then uses `stack0x00000004` / `unaff_ESI` | **Survives as residual** — key source **Open** |
| 4 | Double lower-bound call is product intent | Identical consecutive calls look like Ghidra re-walk | **Tentative** — do not port as two independent probes without asm |
| 5 | Credit-only helper | Also called from item drop generators | **Falsified** as credit-only — shared profile/row lookup |
| 6 | Clean renamed semantic ≠ raw | Scaffold still FUN_*; CF matches | **Survives** (leave-FUN OK) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Null / empty / miss → 0 | **High** | Infinite loot or crash on null row |
| Payload at node `+0x10` | **High** | Wrong row layout |
| Map at `table+0xb0`, end `+0xb4`, size/flag `+0xb8` | **High** | Bad table object wiring |
| Key identity | **Open** | Silent miss → always 0 drops/credits |
| Product name | **Probable** | Cosmetic |
| Double Map call | **Tentative** | Port noise |

---

## 3. Cross-check against raw (minimal)

Live `batch_decompile` 2026-07-29 ≡ raw `aa_00508dc0` body (empty gate, lower-bound, payload `+0x10`, miss → 0).

Callers (static): `0x004d4440`, `0x00508e70`, `0x0050ac80` — all treat return as optional row/profile; null aborts productive path.

---

## 4. Surviving contract for AutoCore

```
// Shared loot/credit profile row lookup
void* LootProfile_LookupActiveRow(Table* table /*, key */) {
  if (!table || table->mapCountOrFlag /*+0xb8*/ == 0) return nullptr;
  node = Map_LowerBoundFindByIntKey(&table->map /*+0xb0*/, key);
  if (node == table->mapEnd /*+0xb4*/) return nullptr;
  return *(void**)(node + 0x10);  // payload row
}
// Port: treat null as “no table row”; do not invent key without call-site seal.
```

---

## 5. What would overturn this dual

1. Asm proof that `+0xb8` is not emptiness / count gate.
2. Payload offset not `+0x10` on retail node type.
3. Evidence callers pass a different object class without `+0xb0` map.

**Verdict:** **accept-with-gaps** — lookup CF High; key provenance residual.
