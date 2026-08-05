# Review B (skeptical / adversarial): `aa_00538780` MissionStagingTree_EraseNode

| Field | Value |
|---|---|
| **Stable ID** | `aa_00538780` |
| **VA** | `0x00538780` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00538780_MissionStagingTree_EraseNode.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Soft no-op if bad iterator | **Falsified** — throws `"invalid map/set<T> iterator"` |
| 2 | Only unlinks without free | **Falsified** — ends in `operator_delete(node)` |
| 3 | Hash remove (`CNDHash_Remove`) | **Falsified** — RB tree erase, not hash |
| 4 | Unreachable-block warnings mean dead function | **Falsified** — live call from `FUN_0052d8b0` / `FUN_00539150` |
| 5 | Erases active mission hash `+0x540` | **Falsified** — ECX is staging map `+0x508` |
| 6 | Bit-exact / runtime proven | **Fail** — static only |

---

## 2. Decisive evidence

- Call site GiveMission notify path: `LEA ECX,[char+0x508]` then CALL erase.
- Exception path proves standard library map erase contract.
- Sibling destroy `FUN_00537ef0` handles bulk free; this unit is **single-node** erase with rebalance.

---

## 3. Port risk

| Risk | If wrong |
|---|---|
| Skip rebalance | Map corruption after selective clear |
| Wrong map header | Erase wrong structure / crash |
| Treat as hash remove | Wrong container API |

**Verdict:** Accept as staging-map erase. Do not collapse into `CNDHash_Remove`.
