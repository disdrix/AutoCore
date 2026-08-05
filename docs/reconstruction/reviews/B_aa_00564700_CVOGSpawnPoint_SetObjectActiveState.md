# Review B (skeptical / adversarial): `aa_00564700` CVOGSpawnPoint_SetObjectActiveState

| Field | Value |
|---|---|
| **Stable ID** | `aa_00564700` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_00564700_CVOGSpawnPoint_SetObjectActiveState.md` |
| **Verdict** | **accept-with-gaps** on CF outline; **needs-more-evidence** on NPC helper semantics |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | NPC and non-NPC identical | **Falsified — split paths** |
| 2 | No child recursion | **Falsified — kind 0xe child call** |
| 3 | Finished exact AI wake | **Overstated** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| IsNPC branch | High | Wrong enable path |
| Active char polarity | High | Stuck invisible NPCs |
| Child spawn chain | Tentative | Orphan children |

---

## 3. Cross-check against raw

```
log entry; cActive=*param_2;
if !IsNPC: non-NPC enable/disable (+ child kind 0xe recurse);
else: NPC AI wake / flags / map list / optional wander;
Clean preserves split; helpers open.
```

---

## 4. Surviving contract for AutoCore

```
SetObjectActiveState(spawn, &active):
  non-NPC: graphics/sim enable helpers; recurse vehicle-kind children
  NPC: AI wake, enrollment, deactivate pose tweaks
  active char polarity must match retail (*param_2)
Server NPC enable should coordinate HBAI start with this client path.
```

---

## 5. Open questions

1. Name IsNPC vfunc at +0x1d8.
2. Map list FUN_004e2600 callback LAB_00512ac0.
3. Which pieces are client-only chrome.

**Verdict:** **accept-with-gaps** on CF outline; **needs-more-evidence** on NPC helper semantics
