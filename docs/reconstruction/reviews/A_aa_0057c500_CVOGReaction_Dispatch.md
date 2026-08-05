# Review A (reconstruction fidelity): `aa_0057c500` CVOGReaction_Dispatch

| Field | Value |
|---|---|
| **Stable ID** | `aa_0057c500` |
| **VA** | `0x0057c500` |
| **Canonical name** | `CVOGReaction_Dispatch` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0057c500_CVOGReaction_Dispatch.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Central **client reaction-type switch** for mission/map reaction objects. Signature `__thiscall(reaction*, activator*)`. Reads reaction type byte at `reaction+0x1d1` and dispatches to type-specific apply logic, often iterating object-target lists (`param_1[0x76]`…`[0x77]`) via `CVOGReaction_ResolveObjectTarget`, then optionally chaining with `CVOGReaction_FireNestedReactions`.

Important named type arms (non-exhaustive; full switch ~0..0x57):

| Type | Role (from body / docs) |
|-----:|---|
| 0 / 1 | Object vtbl apply (`+0x114` / `+0x118`) |
| 2 | SpawnObject + nested |
| 3 / 8 | RemoveObject variants + nested |
| 0x0a (10) | TransferMap / CastSkill path materialize |
| **0x1e (30)** | **`CVOGReaction_GiveMission`** |
| **0x1f (31)** | **`CVOGReaction_CompleteObjective(..., force=1)`** |
| **0x20 (32)** | **`CVOGReaction_UnlockContinentObject`** |
| 0x2b / 0x2c | SetPath / SetPatrolDistance (NPC.md) |
| Others | Dialog, inventory, XP, teleport, random, boost, etc. |

Early path: if activator flag `param_1[0x29]+0x7e == 0`, call `FUN_004d3ae0` (prep / non-local path).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0057c500_CVOGReaction_Dispatch.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGReaction_Dispatch.cpp` |
| Function record | `docs/reconstruction/functions/aa_0057c500_CVOGReaction_Dispatch.md` |
| System maps | missions-progression; NPC.md reaction types |
| Sibling managers | GiveMission, CompleteObjective (dual-reviewed) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Large `switch(*(char*)(reaction+0x1d1))` | **High** | Raw + clean |
| Cases 0–3, 6–10 present with object loops | **High** | Spot-checked |
| Case **0x1e** → GiveMission(`param_1[0x97]`) | **High** | Named callee |
| Case **0x1f** → CompleteObjective force=1, OR success, nested if any | **High** | Matches mission force-complete pattern |
| Case **0x20** → UnlockContinentObject | **High** | Named |
| Nested fire via `CVOGReaction_FireNestedReactions` common | **High** | Many cases |
| Target resolve `CVOGReaction_ResolveObjectTarget` | **High** | Shared helper |
| Cast skill materialization via ResolveSkillTargets / CastSkillOnTarget | **High** | Case 10 region |
| Local-player prep when `+0x7e==0` | **Probable** | Polarity family; prep FUN unnamed |
| Full AutoCore enum name for every case | **Tentative** | Many cases still opaque FUN/vtable |
| Bit-exact completeness of every case body | **Tentative** | Huge function; scaffold fidelity not case-by-case sealed in this review |
| `param_1[0x97]` always missionId | **Probable** | Used as such in mission cases; field role not globally typed |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| SEH / ExceptionList frame | **Yes** (scaffold) |
| Early `+0x7e` prep call | **Yes** |
| Type byte switch entry | **Yes** |
| Mission cases 0x1e / 0x1f / 0x20 | **Yes** |
| Object-list iteration pattern | **Yes** |
| Nested reaction fire sites | **Yes** |
| No invented pruned case set | **Yes** (clean is full scaffold of raw) |

---

## 5. Gaps

1. Majority of case bodies still `FUN_*` / raw vtbl offsets — not human-refined.
2. Reaction object layout beyond type byte and a few indices open.
3. Interaction with S2C GroupReactionCall `0x206C` is caller-side, not this body.
4. Full case→enum naming table incomplete in reconstruction corpus.
5. Runtime differential of multi-target reactions open.
6. Function record system still `unknown` — should be missions-progression / reactions.

**Verdict:** Dispatch switch surface + sealed mission arms faithful. **accept-with-gaps** (manager scaffold, not full case taxonomy seal).
