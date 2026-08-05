# Review B (skeptical / adversarial): `aa_0057c500` CVOGReaction_Dispatch

| Field | Value |
|---|---|
| **Stable ID** | `aa_0057c500` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_0057c500_CVOGReaction_Dispatch.md` |
| **Verdict** | **accept-with-gaps** on switch CF + mission arms; **needs-more-evidence** for full type taxonomy |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Clean is a fully understood port of every reaction type | **Falsified** — scaffold of a massive switch; most cases not semantically named |
| 2 | GiveMission / CompleteObjective only entry points | **Falsified** — also SearchAutoMissions, S2C 0x2070, dialog turn-in; this is *one* reaction-type path |
| 3 | Case 0x1f always completes *all* objectives | **Overstated** — walks targets; ORs CompleteObjective returns; nested only if any success |
| 4 | Case 0x20 is “UnlockContObj” with sealed GenericVar semantics | **Weak beyond call** — UnlockContinentObject named; GenericVar field use not fully documented in this unit |
| 5 | Server AutoCore enum matches client case numbers 1:1 for all types | **Needs evidence** — mission cases align; many AutoCore reactions still Unhandled |
| 6 | Dispatch runs only for local player | **Attacked** — early branch when `+0x7e==0` still proceeds into switch after prep; polarity not “skip all” |
| 7 | Missing cases 4/5 mean types unused | **Tentative** — may be intentional fallthrough/default elsewhere; do not invent |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Type byte at +0x1d1 drives switch | High | Wrong reaction apply entirely |
| 0x1e GiveMission / 0x1f CompleteObjective | High | Mission reactions no-op or double-apply |
| Nested FireNestedReactions contract | Probable | Child reactions never fire / double fire |
| Full 0x00–0x57 semantic map | Tentative | Server emits “supported” types client mishandles |
| Object list at [0x76]/[0x77] as TFID pairs | Probable | Wrong target set |
| param_1[0x97] universal GenericVar1 | Tentative | Field reuse per type |

---

## 3. Cross-check against raw

Raw case map (sampled):

- Early cases 0–3, 6–10: object resolve / spawn / remove / transfer / cast skill.
- **0x1e**: list walk → `CVOGReaction_GiveMission(param_1[0x97])` + nested on valid targets.
- **0x1f**: optional mode flag; list walk → `CompleteObjective(id, -1, -1, 1)`; nested if any true.
- **0x20**: list walk → `UnlockContinentObject`; always nested fire after.
- **0x2b / 0x2c**: SetPath / SetPatrolDistance (documented in `docs/NPC.md`).

Clean is a line-preserving scaffold of this decompile (including SEH and large stack). Cross-check against dual-reviewed GiveMission / CompleteObjective units confirms callee signatures used at these cases.

---

## 4. Surviving contract for AutoCore

```
CVOGReaction_Dispatch(reaction, activator) -> status
  optional prep if !localFlag(+0x7e path)
  switch reaction.type@+0x1d1:
    ... many object/map/skill cases ...
    0x1e: GiveMission(reaction.genericVar / [0x97]) on valid targets
    0x1f: CompleteObjective(..., force=1) on valid targets; nest if any ok
    0x20: UnlockContinentObject on targets
    0x2b/0x2c: path / patrol distance (NPC)
    default/unhandled: do not invent
  many arms call FireNestedReactions
Do NOT assume this body handles S2C packet framing (0x206C GroupReactionCall is upstream).
```

---

## 5. Open questions

1. Complete client case → AutoCore `ReactionType` enum table.
2. Semantics of missing cases 4/5 and sparse gaps.
3. Exact layout of reaction object (`[0x97]`, target vectors, nested flags).
4. Whether every successful arm should emit nested GroupReactionCall server-side (server design).
5. Runtime multi-object GiveMission / CompleteObjective from map trigger.

**Verdict:** Safe as the client reaction hub switch with sealed mission arms; do not claim full taxonomy or server parity without more case work.
