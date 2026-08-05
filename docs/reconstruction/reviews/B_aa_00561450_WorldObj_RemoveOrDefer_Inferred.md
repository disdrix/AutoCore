# Review B (skeptical / adversarial): `aa_00561450` WorldObj_RemoveOrDefer_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00561450` |
| **VA** | `0x00561450` |
| **Canonical name** | `WorldObj_RemoveOrDefer_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00561450_WorldObj_RemoveOrDefer_Inferred.md` |
| **System** | npc-ai / spawn / world object |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always immediate destroy | Flag==1 queues and returns with out=0 | **Falsified** always-destroy |
| 2 | Same as enroll `00560ec0` | Opposite polarity; unbind vs bind | **Falsified** merge |
| 3 | Defer path drops ref | Defer **increments** ref | **Falsified** drop-on-defer |
| 4 | Always calls vtbl destroy | Only when post-dec ref == 0 | **Falsified** always-dtor |
| 5 | outFlag always 1 | Defer → 0; immediate → 1 | **Falsified** |
| 6 | Queue growth never needed | Fullness check + `005b3370` | **Falsified** no-grow |
| 7 | Spawn-only | 14 xrefs | **Falsified** |
| 8 | Can ignore `+0x24` / `00561320` | Conditional call when &gt;0 | **Agree** residual Open but present |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Defer vs immediate split | **Confirmed** | Nested UAF / double-free |
| Refcount policy (++ defer / -- immediate) | **Confirmed** | Lifetime bugs |
| Destroy only at ref 0 | **Confirmed** | Premature free |
| Parent disable polarity | **High** | Invert activate |
| Queue drain ownership | **Open** | Stuck deferred objects |
| Unbind helper English | **Tentative** | Incomplete ports |

---

## 3. Cross-check against raw / live / bytes

```
batch_decompile ≡ clean:
  if (*(char*)(this+300) == 1) {
    // grow queue if full; push obj; ref++; *out=0; return
  }
  // unbind chain; ref--; if 0 vtbl[0](1); *out=1
```

### Merge trap

| VA | Role |
|---|---|
| `00560ec0` | enroll; sets flag 1 temporarily |
| `00561450` | remove; **reads** flag for defer |

Calling enroll on disable (or remove on enable) inverts spawn lifetime.

### Nested trap

If enroll forgets to restore `+0x12c`, **all** subsequent removes only queue — objects never fully tear down until a drain path (Open) runs.

---

## 4. Surviving contract for AutoCore

```
WorldObj_RemoveOrDefer(m, outDone, obj):
  if m.flag_12c == 1:
    queue.push(obj); obj.ref++; *outDone = 0; return
  optional FUN_00561320
  Unbind…; NotifyRemove…
  if --obj.ref == 0: obj.Destroy(1)
  *outDone = 1
```

**Verdict:** **accept-with-gaps** — adversarial review does not break remove/defer contract; queue drain remains Open.
