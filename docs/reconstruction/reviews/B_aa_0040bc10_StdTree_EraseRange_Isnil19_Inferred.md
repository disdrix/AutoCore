# Review B (skeptical / adversarial): `aa_0040bc10` StdTree_EraseRange_Isnil19_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040bc10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R13-020) |
| **Counterpart** | `reviews/A_aa_0040bc10_StdTree_EraseRange_Isnil19_Inferred.md` |
| **Dual start** | 2686 |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is free-subtree only | **Falsified as sole role** — free path is full-range gate; partial walks single-erase `0040b440` |
| 2 | This is single-node erase | **Falsified** — range loop + full-clear branch; body 178 B |
| 3 | Standard ECX `__thiscall` | **Falsified** — **EDI = map**; free still takes ECX=map for recursion thread |
| 4 | Same identity as dualed Val12 `0040d700` | **Falsified as merge** — different free (`0040c100` vs `0040d630`), erase (`0040b440` vs `004188e0`), ABI (EDI vs ECX) |
| 5 | isnil@+0x11 / +0x21 / +0x29 / +0x2d / +0x31 family | **Falsified** — successor + free + erase seal **isnil@+0x19** / color@+0x18 |
| 6 | RET 4 / RET 8 | **Falsified** — **`RET 0x0C`** both exits (`C2 0C 00`) |
| 7 | Inventory UI / grab-drop product method | **Reject** — generic STL helper; multi-caller tidy + parent shell clear |
| 8 | Free decompile (right-only + noreturn) is full free | **Falsified as plate** — `read_memory` of `0040c100` shows right-recurse + left-walk + delete; decompiler damaged by `operator_delete` noreturn |
| 9 | Runtime Confirmed | **Reject** — no Launcher; Terminal **false** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Range-erase CF shape | **High** | Wrong clear vs partial |
| ABI EDI-this + RET 0x0C | **High** | Stack/register corruption |
| isnil@+0x19 / color@+0x18 | **High** | Wrong node family port |
| Free = `0040c100` isnil19 | **High** | Wrong port wiring / leak |
| Partial erase = `0040b440` | **High** | Incomplete port |
| Product type English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against free / erase / peer

```
// Free 0040c100 (bytes):
//   if (!isnil(node@+0x19)) { free(right); delete node; walk left }
//   ECX threaded; RET 4. Not FreeSubtree_Val12 @ 0040d630.
//
// Erase 0040b440 (decomp evidence only — residual R13-018):
//   isnil@+0x19 throw "invalid map/set<T> iterator";
//   succ FUN_00457cc0 (Isnil19); unlink; color@+0x18 rebalance; operator_delete.
//
// Peer dualed 0040d700 StdTree_EraseRange_Val12:
//   same CF skeleton / ~180 B / RET 0xC / isnil19 successor;
//   ECX thiscall; free 0040d630; erase 004188e0 — DO NOT MERGE identity.
//
// Callers after full clear: operator_delete(head) via 00489822 (tidy pattern).
```

---

## 4. Surviving contract for AutoCore

```
// Port as isnil19 / Val12-family range erase:
//  - full [begin,end) → FreeSubtree_Isnil19(root=head->parent) + head reset + size 0
//  - partial → inline successor isnil@+0x19 + erase 0040b440(map, &outIt, node)
//  - ABI: EDI = map*, 3 stack args (outIt, first, last), ret 0x0c, EAX=outIt
// Do not merge with ECX Val12 peer 0040d700 or isnil11/29/2d/131 erase-range clones.
// Not inventory-product-specific despite R13 inventory-transfer partition.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/family/call-graph. Product residual + undualed free/erase → **accept-with-gaps**. Never Runtime Confirmed.
