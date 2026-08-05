# Review B (skeptical / adversarial): `aa_004a04f0` MissionTree_InorderCollectMediaPreloads_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a04f0` |
| **VA** | `0x004a04f0` |
| **Canonical name** | `MissionTree_InorderCollectMediaPreloads_Inferred` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Adversarial (OWN-ONLY W37-C) |
| **Counterpart** | `reviews/A_aa_004a04f0_MissionTree_InorderCollectMediaPreloads_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## Attacks considered

| Attack | Result |
|---|---|
| Body owns media string logic? | **No** — sole callee `004b88e0`; this is walk-only |
| ECX is mission host (same as `004b88e0`)? | **No** — ECX is tree holder; host loaded from **node+0x10** into ECX at call |
| Decompiler 4 stack formals wrong (parents show 3)? | **No** — parents push **4** stack slots (ctx + 3 flags); RET 0x10; W32-H matches |
| Preorder / postorder not inorder? | **No** — successor is textbook inorder (right-min or parent climb) |
| Infinite loop if nil-gate inverted? | Visited nodes are non-nil; head is sentinel; empty short-circuit present |
| VOG_DEBUG scaffold name? | **Reject** — no plate on this VA; name is structural from walk+callee |
| Same as list walk / vector for-each? | **No** — pointer tree with parent links + nil byte |

---

## Residual risks

1. Product type demangle for holder/node.
2. Holder `*ecx` indirection field identity (allocator/proxy vs map base).
3. No runtime of flag triples vs collected asset sets.

---

## Minimal sealed model

```
MissionTree_InorderCollectMediaPreloads(holder@ECX, unused, f3, f4, f5):
  head = *(*holder + 4)
  node = *head            // leftmost
  if node == head: ret 0x10
  do:
    MissionHost_CollectMediaPreloads(node->payload@+0x10, unused, f3, f4, f5)
    node = inorder_successor(node)  // nil @ +0x15
  while node != head
  ret 0x10
```

---

## Verdict

Do not fold into `004b88e0` or invent plate English. **accept-with-gaps**.
