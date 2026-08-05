# Review A (reconstruction fidelity): `aa_004d3ef0` CVOGMission_EvalActiveObjectiveInteractState

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d3ef0` |
| **VA** | `0x004d3ef0` |
| **Canonical name** | `CVOGMission_EvalActiveObjectiveInteractState` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004d3ef0_CVOGMission_EvalActiveObjectiveInteractState.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Compute **interact-icon / target state** for an active mission against a world object:

**Returns (plate):**

| Code | Meaning (inferred) |
|---|---|
| **4** | Active mission, no matching pending objective on this pass |
| **5** | Active objective on target, requirements not all met |
| **8** | Active objective on target, all reqs satisfied (turn-in ready) |
| **0** | Related objective found but target filter failed (`bVar3`) |

**Algorithm:**

1. Walk mission def objectives (`count=byte(+0x130)`, array `+0x13c`).
2. Lookup objective id in character **pending** hash `param_3+0x55c`.
3. If pending state node present: for each evaluator `[+0x158,+0x15c)`:
   - vtable **+0x50** type probe; if type **3** and evaluator `+0x18` ≠ target continent id (`param_2+0xa8`→`+0x34`), clear match flag `bVar3`
   - vtable **+0xc**(character, pendingState) must all succeed for complete (8) else pending (5)
4. If no pending hit for any objective → **4**.

Parameters (roles from use): `param_1` mission def, `param_2` interact target object, `param_3` character.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004d3ef0_CVOGMission_EvalActiveObjectiveInteractState.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGMission_EvalActiveObjectiveInteractState.cpp` |
| Function record | `docs/reconstruction/functions/aa_004d3ef0_CVOGMission_EvalActiveObjectiveInteractState.md` |
| System / interact | `docs/missionState.md`, missions-progression |
| Related | Offer interact evaluators / object interact tree |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Return set {0,4,5,8} | **High** | Literals only |
| Pending hash `char+0x55c` lookup by obj id | **High** | Manual bucket walk |
| Mission obj array +0x130 / +0x13c | **High** | Same as bulk complete |
| All-req → 8 else 5 | **High** | `bVar2` |
| Type-3 continent filter → 0 | **Probable** | Present; type enum open |
| Default 4 when no pending match | **High** | Fallthrough |
| Clean ≡ raw | **High** | Scaffold |
| Param roles named | **Probable** | From plate + CF |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Objective loop + pending lookup | **Yes** |
| Empty evaluator → LAB complete (8) | **Yes** |
| Type-3 continent mismatch clears bVar3 | **Yes** |
| Return 0 / 5 / 8 / 4 | **Yes** |

---

## 5. Gaps

1. Evaluator type enum (3 = continent/map target?).
2. Field `evaluator+0x18` vs `targetContinent+0x34`.
3. Call graph for who consumes return codes (icon set).
4. Runtime icon states 4/5/8/0 capture.
5. Clean still scaffold-named params.

**Verdict:** Interact-state CF faithful. **accept-with-gaps.**
