# Review B (skeptical / adversarial): `aa_005ccff0` CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ccff0` |
| **VA** | `0x005ccff0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005ccff0_CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred.md` |
| **Evidence** | Live decompile + `read_memory` + relative CALL targets + sole xref |
| **Agent** | W29-L OWN-ONLY |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | stdcall with stack formals | All exits `ADD ESP,18; RET` (`C3`) | **Falsified** — 0 stack formals |
| 2 | Mode-0 on fail is full select | `004c3c80(0)` only writes mode when mode≠1 (sealed dual) | **Accepted** — intentional mode clear, not target promote |
| 3 | Candidate is resolved object itself | Body uses `resolved[0x28]` / `+0xA0` | **Falsified conflation** |
| 4 | SetSelectedTarget arity 3 (`unaff_EDI`) | Prior dual seals **1** stack formal | **Falsified decompiler residual** |
| 5 | General FindTarget scan | Sole caller engage arm; TFID-driven | **Falsified** — not `FindTargetToAttack` |
| 6 | Always LinkedDeath walk | Direct promote returns early when gates pass | **Falsified always-walk** |
| 7 | Product name sealed without evidence | Name is role-inferred (`_Inferred`) from caller + CF | **Accepted gap** |
| 8 | Multiple call sites | Single xref `005d0704` | **Confirmed sole caller** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI thiscall / plain ret | **Confirmed** | Stack smash |
| Resolve fail → mode 0 | **Confirmed** | Wrong engage fail handling |
| Direct vs LinkedDeath paths | **Confirmed** | Wrong retarget priority |
| Product vtbl English | Open | Doc-only |
| Runtime | Open | — |

---

## 3. Cross-check vs sealed callees

| Callee | Dual / note |
|---|---|
| `0x004c3c80` | W28-L Object_SetMode278… — mode 0 no select |
| `0x005172d0` | Object_SetSelectedTarget |
| `0x004bb950` | Object_ResolveFromTFID |
| `0x004022a0` | LockedList_TryAdvanceIterator_Inferred |

Do not merge this unit into `CVOGHBAIBase_FindTargetToAttack` or `004c3c80` ownership.

---

## 4. Byte / CALL anchors

```text
0x005ccff0: 83 EC 18 53 55 56 57 8B F9   ; frame + this
            … Object_ResolveFromTFID @ 0x004bb950
            … Object_SetSelectedTarget @ 0x005172d0
            … Object_SetMode278… @ 0x004c3c80 (mode 0)
            … FUN_004c8970 / FUN_004294f0 / 0x004022a0
            … ADD ESP,18 / RET (multiple exits)
```

---

## 5. What would reverse the seal?

- Second caller with different `this` layout (would reclassify owner offset).
- Proof `+0xA0` is not the selected-target candidate (would reclassify promote path).

None observed.

**Verdict:** **accept-with-gaps**
