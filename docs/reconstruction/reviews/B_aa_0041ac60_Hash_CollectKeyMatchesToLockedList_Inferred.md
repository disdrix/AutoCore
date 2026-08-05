# Review B (skeptical / adversarial): `aa_0041ac60` Hash_CollectKeyMatchesToLockedList_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041ac60` |
| **VA** | `0x0041ac60` |
| **Canonical name** | `Hash_CollectKeyMatchesToLockedList_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0041ac60_Hash_CollectKeyMatchesToLockedList_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Looks up single node only | Walks full chain; multiple inserts possible | **Falsified** single-hit claim |
| 2 | Returns null on no matches | Still returns allocated empty list if new succeeded | **Falsified** null-on-miss |
| 3 | Hash is open-addressed array only | Chained nodes via `+0x0C` | **Falsified** open-address-only |
| 4 | No synchronization | CS init + insert uses CS | **Falsified** lock-free claim |
| 5 | Payload type sealed as skill element | Parent copies 0x14-byte rows separately; list holds opaque ptrs | **Unproven** element struct identity |

---

## 2. Surviving contract

```
list = new LockedList(vtbl 00a86168, CS, empty)
for node in hash_bucket(table, key):
  if node.key==key and node.payload:
    list.Insert(node.payload)   // FUN_0041c7e0
return list
```

Skill loader: collect element payloads for current skill id before materializing rank/element array.

**Verdict:** **accept-with-gaps**
