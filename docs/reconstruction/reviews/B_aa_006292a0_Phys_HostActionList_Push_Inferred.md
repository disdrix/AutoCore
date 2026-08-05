# Review B (skeptical / adversarial): `aa_006292a0` Phys_HostActionList_Push_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006292a0` |
| **Canonical name** | `Phys_HostActionList_Push_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_006292a0_Phys_HostActionList_Push_Inferred.md` |
| **System** | `physics` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | ECX is always the top-level world manager | Prior “world+0x4c” wording | **Partially falsified as wording** — RegisterAction uses **host** (`body+0x44`) in ECX; layout is still `ECX+0x4c` |
| 2 | Grows via `FUN_005b3300` | Pair-vector sibling | **Falsified** — **`FUN_005b3370(..., 4)`** only |
| 3 | Element stride 8 | Pair glue mix-up | **Falsified** — pointer list, size **4** |
| 4 | No ownership backlink | | **Falsified** — always `action+0x10 = host` |
| 5 | Inserts sorted / unique | | **Falsified** — pure append; no scan |
| 6 | Refcount action | | **Falsified** — RegisterAction bumps `action+6` **before** this call; this VA does not |
| 7 | This is applyAction itself | | **Falsified** — list bookkeeping only; apply is later `vtbl+0x14` |
| 8 | Product name sealed | | **Holds open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + ret 4 | **Confirmed** | ABI break |
| Header `+0x4c/+0x50/+0x54` | **Confirmed** | Wrong list |
| Double-grow on full via `005b3370` | **Confirmed** | (sealed grow dual) |
| Backlink `+0x10` | **Confirmed** | Orphan action / wrong host |
| ECX is host of first body in RegisterAction | **Confirmed** | Mis-port registration |
| “World” English for ECX | **Medium** | Doc confusion only if host≠world type |
| Product name | **Low** | Doc |

---

## 3. Cross-check against raw / live

```text
raw:  if count == (capRaw&0x7fffffff): 005b3370(this+0x4c, 4)
      data[count]=action; count++; action+0x10=this
live: ≡ raw; C2 04 00
site 0055feac: PUSH EDI(action); MOV ECX,ESI(host); CALL
```

### Sentinel / sibling traps

| Trap | B position |
|---|---|
| Merge with `PhysSim_PushBodyPair` | **Reject** |
| Merge with active-host push inside ActivateHost (`world+8`) | **Reject** — different offset family |
| Assume grows by +1 only | **Reject** — doubles via `005b3370` |
| Assume sorted insert | **Reject** — append |

---

## 4. Surviving contract for AutoCore

```
Phys_HostActionList_Push(host, action):
  hdr = host.actionList @ +0x4c   // {data, count, capRaw}
  if count == (capRaw & 0x7fffffff):
      GrowableArray_DoubleGrow(hdr, elemSize=4)
  data[count] = action
  count++
  action.owner @ +0x10 = host
```

**Port tests:**

* After RegisterAction first-host path, action appears once on that host’s list.
* `action+0x10` equals the host used for ActivateHost gate, not a random world pointer.
* Full list doubles capacity; count only +1.

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Corrects “world+0x4c” → host in ECX | **Agree** — step-rate note was imprecise |
| Role feeds applyAction | **Agree High** — list identity sealed; walk dual is island integrate |
| Always action type | **Open** — structural pointer only |

---

## 6. Open questions

1. Product name.
2. Host type identity vs world manager across all three callers.
3. Whether remove/pop twin exists as named dual (compact paths elsewhere).

**Verdict:** **accept-with-gaps**
