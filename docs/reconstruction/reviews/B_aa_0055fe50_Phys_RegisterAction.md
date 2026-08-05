# Review B (skeptical / adversarial): `aa_0055fe50` Phys_RegisterAction

| Field | Value |
|---|---|
| **Stable ID** | `aa_0055fe50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0055fe50_Phys_RegisterAction.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | ECX is action, stack is world | Swap ABI | **Falsified** — `mov ebp,ecx` world; action in EDI from stack; `action+0xc = ebp` |
| 2 | Collect is vtbl `+0x14` (applyAction) | Slot mix-up | **Falsified** — collect is **`+0x18`**; applyAction is **`+0x14`** on VehicleAction |
| 3 | Always ActivateHost every host | Over-activate | **Falsified** — only first valid path when `+0x29==0` |
| 4 | Always cross-link every pair | | **Falsified** — only when subsequent host's `+0x44` differs from first |
| 5 | Skips free-list hosts | | **Sealed** — `+0x24 == -1` continue |
| 6 | `unaff_EBX` means undefined behavior | Decompiler panic | **Falsified as mystery** — collect output pointer from stack object filled by vcall |
| 7 | Null action is safe | Defensive port | **Falsified** — no null gate; createVehicleAction can call with null action |
| 8 | Only vehicle uses this | | **Falsified** — flipper constraint + other callers |
| 9 | Name PDB-proven | | **Not sealed** — Probable |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Refcount `+6` | **High** | Leaks / premature free |
| Collect `+0x18` vs apply `+0x14` | **High** | Wrong vcall → crash |
| World back-link `action+0xc` | **High** | Island lookup fails |
| `FUN_006292a0` island list insert | **High** | Action never stepped |
| ActivateHost gate on `+0x29` | **High** | Double-activate / stuck inactive |
| Null action | **High** (unsafe) | Port “safe return” diverges |
| English name | **Medium** | Doc |

---

## 3. Cross-check against raw

```text
// raw ≡ live (ECX=world, arg0=action)
action.ref16(+6)++
action.vtbl[+0x18](&collect)     // NOT +0x14
action.world(+0xc) = world
first = null
for h in collect:
  if h.index(+0x24) == -1: continue
  if first == null:
    FUN_006292a0(action)
    first = h
    if h.ready(+0x29) == 0: PhysSim_ActivateHost(h)
  else if first.islandKey(+0x44) != h.islandKey:
    FUN_0055efd0(first, h)
FUN_0062a3d0(world, action)
maybe free collect
return action
```

---

## 4. Surviving contract for AutoCore

```
Phys_RegisterAction(world, action):
  action.refCount16 += 1
  bodies = action.CollectRelated()           // vtbl +0x18
  action.world = world                       // +0x0c
  first = null
  for host in bodies:
    if host.freeIndex == -1: continue        // +0x24
    if first is null:
      IslandActionList_Add(action)           // FUN_006292a0
      first = host
      if not host.ready: ActivateHost(host)  // +0x29
    else if first.group != host.group:       // +0x44
      LinkCrossIsland(first, host)           // FUN_0055efd0
  PostRegister(world, action)                // FUN_0062a3d0
  return action
```

**Port tests:**

* Must not call applyAction (`+0x14`) here.
* Must bump `+6` before collect.
* Null action may fault — matching retail if caller is wrong.

---

## 5. Open questions

1. Duals for `006292a0` / `0055efd0` / `0062a3d0`.
2. Meaning of host `+0x44` group key (island id?).
3. Whether flipper constraint implements collect `+0x18` like VehicleAction.

**Verdict:** **accept-with-gaps**
