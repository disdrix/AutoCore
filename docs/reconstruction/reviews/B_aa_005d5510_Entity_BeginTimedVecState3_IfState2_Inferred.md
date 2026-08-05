# Review B (skeptical / adversarial): `aa_005d5510` Entity_BeginTimedVecState3_IfState2_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d5510` |
| **VA** | `0x005d5510` |
| **Canonical name** | `Entity_BeginTimedVecState3_IfState2_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005d5510_Entity_BeginTimedVecState3_IfState2_Inferred.md` |
| **System** | npc-ai / spawn |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always writes state/payload | Gate `state==2` else return | **Falsified** always-write |
| 2 | Sets state to 2 or 0 | Writes **3** | **Falsified** |
| 3 | Deadline is absolute `delayMs` only | Uses `g_dwClientTickMs + delay` when delay≠0 | **Falsified** absolute-only |
| 4 | delay 0 keeps old deadline | Stores **0** when delay==0 | **Falsified** keep-old |
| 5 | Multi-caller util | Sole xref from SetObjectActiveState | **Attack fails** sole |
| 6 | Same as enroll/remove world-obj helpers | Leaf state machine; different object layout | **Falsified** merge |
| 7 | Handles +0x40 kept | Forced to -1 on transition | **Falsified** keep-handles |
| 8 | Parent 5000 is seconds | ms added to tick counter | **Falsified** seconds |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| State2→3 gate + payload | **Confirmed** | Wrong AI phase |
| Deadline formula | **Confirmed** | Early/late wander |
| Sole spawn parent role | **Confirmed** | Wrong ownership |
| Payload = position-like float4 | **Probable** | Wrong units if TFID |
| Phase English / consumer | **Open** | Incomplete AI port |

---

## 3. Cross-check against raw / live / bytes

```
read_memory @ 0x005d5510:
  80 79 50 02     cmp byte [ecx+0x50], 2
  75 5A           jne skip
  0F 57 C0        xorps xmm0, xmm0
  83 C8 FF        or eax, -1
  89 41 40 …      store -1 to +0x40/44/48
  C6 41 50 03     mov byte [ecx+0x50], 3
  … zero +0x20.. ; if delay: add [g_dwClientTickMs] …
  copy 4 dwords from [esp+4] param
```

### Merge trap

Not `WorldObj_EnrollActivate` / `RemoveOrDefer` — those manage manager queues/refcounts. This is a **per-entity timed phase** used only on one NPC wander path of SetObjectActiveState.

### Gate trap

Calling without ensuring state==2 is a silent no-op — ports that “always start wander” will appear broken if phase is not 2.

---

## 4. Surviving contract for AutoCore

```
Entity_BeginTimedVecState3_IfState2(e, vec4, delayMs):
  if e.state != 2: return
  e.handles[3] = -1
  e.state = 3; e.sub = 0
  e.deadline = delayMs ? g_dwClientTickMs + delayMs : 0
  e.blob20 = vec4   // 16 bytes
```

**Verdict:** **accept-with-gaps** — adversarial review does not break state2→3 timed-vec contract; consumer Open.
