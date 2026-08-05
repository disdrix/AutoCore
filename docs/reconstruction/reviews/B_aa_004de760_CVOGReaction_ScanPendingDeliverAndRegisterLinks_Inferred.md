# Review B (skeptical / adversarial): `aa_004de760` CVOGReaction_ScanPendingDeliverAndRegisterLinks_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004de760` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W23-M) |
| **Counterpart** | `reviews/A_aa_004de760_CVOGReaction_ScanPendingDeliverAndRegisterLinks_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This VA **is** the RTTI Type Descriptor for CVOGObjectiveRequirement | **Falsified** — body is code with TraversalLock / loops / `ret 8`; RTTI only as cast targets |
| 2 | It evaluates Collect (type 4) requirements | **Falsified** — hard compare type **3** (Deliver) only |
| 3 | It completes missions / advances objective state machines | **Falsified** — only locks, matches, and calls `FUN_004dbef0` |
| 4 | Stack arity is 1 (`ret 4`) | **Falsified** — epilogue **`ret 8`** |
| 5 | Register mode 5/8 is inventable as “success/fail UI toast” without peer | **Partial** — constants sealed; semantic English residual in peer dual gaps |
| 6 | `param_2` is the host | **Falsified** — `param_2` holds `+0x55c` character hash; host is ECX |
| 7 | Optional object always required | **Falsified** — null arm scans host list |
| 8 | Coverage “full” status means dual sealed | **Falsified** — inventory said full scaffold; dual is this pass |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI `ret 8` / ECX host | **High** | Wrong this / stack smash on port |
| Pending hash + lock protocol | **High** | Hash reentrancy bugs |
| Deliver-only type 3 gate | **High** | Wrong requirement family |
| Modes 5/8 wiring to RegisterObjectHashEntry | **High** | Wrong link flavor on objects |
| Host `+0xfc` product meaning | Medium | Filter mis-port |
| Nested MI `+0xac/+0x34` product field | Medium | Object match miss |
| Predicate `+0xc` English | Low/Medium | Naming only |

---

## 3. Cross-check against raw + bytes

```
host (ECX), character (stack), optObject (stack)
lock character.pendingHash(+0x55c).traversal(+0x1d)
for each pending objective evaluator:
  if GetType()==3 and dynamic_cast<Deliver> and deliver[7]==host+0xfc:
    for each candidate object (list or opt):
      if object.mi+0x34 == deliver[6]:
        RegisterObjectHashEntry(obj, mode= pred?8:5, -1, -1, objId)
unlock; ret 8
```

Clean must **not**:
- claim Collect/Kill/Patrol requirement handling beyond using Patrol as a **caller**
- treat RTTI symbols as this function’s identity
- invent mission complete / inventory give side effects beyond the register call

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape (client mission link maintenance)
void ScanPendingDeliverAndRegisterLinks(Host* host, Character* ch, Object* optOrNull)
{
    var hash = ch->PendingObjectives; // +0x55c
    TraversalLock(hash);
    foreach (var entry in hash) {
        foreach (var req in entry.Objective.Evaluators) {
            if (req.Type() != 3) continue;
            var deliver = req as Deliver;
            if (deliver == null || deliver.Key1c != host.FilterFc) continue;
            foreach (var obj in Candidates(host, ch, optOrNull)) {
                if (obj.MatchKey34 != deliver.Key18) continue;
                var mode = deliver.Predicate(ch, entry) ? 8 : 5;
                RegisterObjectHashEntry(host, obj, mode, -1, -1, entry.ObjectiveId);
            }
        }
    }
    TraversalUnlock(hash);
}
```

Server ports that rebuild object links after inventory/give/patrol start should preserve **Deliver-only**, **lock discipline**, and **mode 5/8** split.

---

## 5. Open questions

1. Authoritative product name of modes 5/8 in the object-hash descriptor.
2. Whether all callers pass the same host subobject shape for ECX.
3. Runtime confirmation of list enumeration source `+0xe4e8`.

**Verdict:** **accept-with-gaps**
