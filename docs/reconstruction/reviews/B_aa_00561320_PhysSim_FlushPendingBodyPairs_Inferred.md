# Review B (skeptical / adversarial): `aa_00561320` PhysSim_FlushPendingBodyPairs_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00561320` |
| **Canonical name** | `PhysSim_FlushPendingBodyPairs_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W19-M) |
| **Counterpart** | `reviews/A_aa_00561320_PhysSim_FlushPendingBodyPairs_Inferred.md` |
| **System** | physics / island pair glue |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Compares integer island **IDs** at +0x44 | “group key” wording from producer dual | **Refined** — values are passed as **object pointers** into `00560a30` which treats them as hosts (fields, activate, destroy). Equality is pointer identity. |
| 2 | `00560a30(hostA, hostB)` free-standing 2-arg | Decomp of this unit | **Falsified** — `mov ecx, esi` (world) before call; callee signature thiscall 3-arg |
| 3 | Frees pair buffer | clear count looks like free | **Falsified** — only `count=0`; no free/grow call |
| 4 | Enqueues pairs (same as PushBodyPair) | name confusion | **Falsified** — drain only; producer is `0055efd0` |
| 5 | Always merges every pair | | **Falsified** — skip when hostA == hostB |
| 6 | Stack args / ret n | | **Falsified** — bare `c3` |
| 7 | Parent-seed SetObjectActiveState is sole role | auto name | **Falsified** — multi-caller island/remove family |
| 8 | Product name sealed | | **Holds open** — `_Inferred` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX world + bare ret | **Confirmed** | Wrong object |
| Pair vec `+0x20/+0x24`, stride 8 | **Confirmed** | Missed pairs / OOB |
| body+0x44 host pointers | **High** | Wrong merge operands |
| Conditional `00560a30(world, ha, hb)` | **Confirmed** | Stack/this smash |
| Count cleared always | **Confirmed** | Stuck glue queue |
| Merge implementation details | **Open** (other unit) | Incomplete island port |
| Product symbol | **Low** | Doc only |

---

## 3. Cross-check against raw / live

```text
raw:  for i in 0..count: hosts = bodyA/B +0x44; if !=: 00560a30(...); count=0
live: ≡ raw; ESI=ECX; call site sets ECX=world for merge
producer: PushBodyPair writes same +0x20/+0x24 stride-8
island step: multiple conditional calls when +0x24 > 0
```

### Sentinel / sibling traps

| Trap | B position |
|---|---|
| Confuse with `PhysSim_PushBodyPair` | **Reject** — inverse roles |
| Confuse with action-list push `006292a0` | **Reject** |
| Treat +0x44 as plain int id not pointer | **Reject as object identity** — merge consumes pointers |
| Assume buffer free on flush | **Reject** |
| Trust decomp’s missing world this on merge call | **Reject** — bytes fix it |

---

## 4. Surviving contract for AutoCore

```
PhysSim_FlushPendingBodyPairs(world):
  for i in 0 .. world.pairCount-1:
      (bodyA, bodyB) = world.pairData[i]   // 8-byte elements at +0x20
      hostA = bodyA.host   // +0x44
      hostB = bodyB.host
      if hostA != hostB:
          HostMerge(world, hostA, hostB)   // FUN_00560a30
  world.pairCount = 0                      // +0x24; buffer kept
```

**Port tests:**

* Equal-host pairs must not call merge.
* Count zero after flush even when count was zero at entry.
* Must pass **world** as this into merge (not host as this).
* Do not free pair storage here.

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Producer is PushBodyPair | **Agree** |
| Island step multi-flush | **Agree** (verified doc + xrefs) |
| Host English “island” | **Probable only** — pointer compare sealed |
| Name `_Inferred` | **Agree** |

---

## 6. Open questions

1. PDB/product symbol.
2. Dual of `FUN_00560a30` merge.
3. Whether count can change during merge mid-loop (retail re-reads `+0x24` each iteration — if merge pushes more pairs, loop extends; if not, stable).
4. Runtime island glue capture.

**Note on loop bound:** body reloads `*(world+0x24)` each `while` check — if merge re-enters and pushes pairs, behavior follows live count (not a frozen snapshot). No evidence merge pushes to this vector in this dual.

**Verdict:** **accept-with-gaps.**
