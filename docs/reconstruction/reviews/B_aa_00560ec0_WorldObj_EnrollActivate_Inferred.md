# Review B (skeptical / adversarial): `aa_00560ec0` WorldObj_EnrollActivate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00560ec0` |
| **VA** | `0x00560ec0` |
| **Canonical name** | `WorldObj_EnrollActivate_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00560ec0_WorldObj_EnrollActivate_Inferred.md` |
| **System** | npc-ai / spawn / world object |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is deactivate / destroy | Refcount++, bind helpers, parent enable path | **Falsified** deactivate |
| 2 | Same as `FUN_00561450` | Sibling; that path decrefs / optional free / deferred queue | **Falsified** merge |
| 3 | Flag +0x12c is permanent 1 | Save → set 1 → restore previous | **Falsified** sticky |
| 4 | No refcount | `*(short*)(obj+6)++` | **Falsified** |
| 5 | Spawn-only | 13 xrefs incl. phys/net helpers | **Falsified** spawn-only |
| 6 | Counter always +0x130 | Branch on `obj+0x40` | **Falsified** |
| 7 | Returns void | Returns `param_2` (object) | **Falsified** void |
| 8 | Parent always enrolls | Parent only if `*(obj+8)==0` | **Agree** — gate is parent, not this VA |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Enroll CF + flag sandwich | **Confirmed** | Deferred-remove races |
| Refcount ++ at +6 | **Confirmed** | UAF / leak |
| Counter stamp at +0x20 | **High** | Wrong handle |
| Parent enable role | **High** | Wrong polarity docs |
| Counter pool English | **Tentative** | Port bugs |
| Manager product name | **Open** | Naming |

---

## 3. Cross-check against raw / live / bytes

```
read_memory @ 0x00560ec0:
  mov esi, ecx                 ; manager
  movsx ebx, byte [esi+0x12c]  ; save flag
  mov edi, [esp+…]             ; object
  mov byte [esi+0x12c], 1
  cmp byte [edi+0x40], 0
  … +0x130 vs +0x134 …
```

### Merge trap

| VA | Polarity |
|---|---|
| `00560ec0` | **enroll / activate** |
| `00561450` | **remove / deactivate** (or deferred queue when flag==1) |

Ports that call the wrong sibling on SetObjectActiveState will invert object lifetime.

### Flag trap

Leaving `+0x12c` stuck at 1 causes `00561450` to **queue** deletes instead of running full teardown — subtle lifetime bug.

---

## 4. Surviving contract for AutoCore

```
WorldObj_EnrollActivate(m, obj):
  prev = m.flag_12c; m.flag_12c = 1
  stamp = (obj.b40==0) ? m.cnt130++ : m.cnt134--
  obj.field20 = stamp
  BindA(obj); BindB(obj)
  m.flag_12c = prev
  obj.ref6++
  Notify(m, obj)
  return obj
```

**Verdict:** **accept-with-gaps** — adversarial review does not break enroll contract.
