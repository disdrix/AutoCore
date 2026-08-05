# Review A (reconstruction fidelity): `aa_0052aa20` CVOGCharacter_HasCompletedMission

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052aa20` |
| **VA** | `0x0052aa20` |
| **Canonical name** | `CVOGCharacter_HasCompletedMission` |
| **Review date** | `2026-07-23` |
| **Tighten date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0052aa20_CVOGCharacter_HasCompletedMission.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Client predicate: is `missionId` treated as completed for this character?

1. If continent/context object at entity chain `+0xa8` is **null** → sole lookup on completed hash `char+0x538`.
2. Else compound path: mission-def table (`FUN_0053fff0`), optional def lookup + field `+0xfc` compare, mode gate (`WeaponAllowsKillXpBonus`), then `+0x538` and/or instance-completed `+0x53c` under **non-OR** rules.

Returns **bool** only. No stores in body.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0052aa20_CVOGCharacter_HasCompletedMission.md` |
| Annotated | `docs/reconstruction/raw/aa_0052aa20_CVOGCharacter_HasCompletedMission.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCharacter_HasCompletedMission.cpp` |
| Function record | `docs/reconstruction/functions/aa_0052aa20_CVOGCharacter_HasCompletedMission.md` |
| Mode-gate dual | `A/B_aa_004ce340_CVOGCharacter_WeaponAllowsKillXpBonus` |
| Sibling grant | `CVOGReaction_GiveMission` `0x005327c0` (dual-hash policy) |
| Prior dual (legacy) | `aa_0052aa20_reconstruction_review.md` / `aa_0052aa20_skeptical_review.md` |
| System map | `docs/reconstruction/systems/missions-progression.md` |
| Layout | `docs/missionState.md` — permanent `+0x538`; debug string “Instanced Completed Missions” for `+0x53c` |

**Live re-decompile performed (2026-07-29)** via Ghidra MCP — body matches raw capture byte-for-byte at CF level.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `bool __thiscall(char*, missionId)` | **High** | Raw + callers + signature |
| Fast path: null `+0xa8` → only `+0x538` | **High** | Raw early return |
| Completed hash `+0x538` / instance `+0x53c` | **High** | body + debug string + GiveMission |
| Clean ≡ raw CF | **High** | Nesting preserved; re-decompile match |
| Body store-free (return bool only) | **High** | No writes in this function |
| Mode gate = `WeaponAllowsKillXpBonus` fields `+0x100==0 && +0xac!=2` | **High** | sealed dual `aa_004ce340` body |
| Full Path A/B truth table (static) | **High** | expanded from nested `\|\|`/`&&` (below) |
| Continent field compare at def/`obj+0xfc` | **Probable** | Present in CF; **name** “continent id” open |
| Object at entity `+0xa8` = continent attach | **Probable** | Structure high; product type open |
| `FUN_0053fff0` = mission-def table holder | **Probable** | Shared with GiveMission; lazy `owner+0xf18` |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Null continent → `CNDHash_LookupByKey(+0x538)` | **Yes** |
| `FUN_0053fff0` + compound `\|\|\|` / `&&` | **Yes** |
| Instance path gated by mode gate + `+0x53c` | **Yes** |
| Final `return false` | **Yes** |
| No invented clamps / stores | **Yes** |

---

## 5. Sealed static truth table (Path A / Path B)

Let:

| Sym | Meaning |
|---|---|
| `cont` | `*(*( *(this+4)+4 ) + this + 0xa8)` |
| `A` | mission-def table null (`*FUN_0053fff0() == 0`) |
| `B` | def lookup miss for `missionId` |
| `C` | `def+0xfc != cont+0xfc` |
| `D` | `!mode` (`WeaponAllowsKillXpBonus` returns 0) |
| `E` | `Lookup(+0x538, id) != null` |
| `F` | `mode && Lookup(+0x53c, id) != null` |

```
if cont == null:
  return E                          // never touches +0x53c

// attached (short-circuit order of (A||B||C||D) && E):
if (A || B || C || D) && E: return true   // Path A — permanent hash
if F: return true                         // Path B — instance hash only
return false
```

**Critical rows (tighten):**

| Scenario (cont ≠ null) | Path A | Path B | Result |
|---|---|---|---|
| mode **true**, table+def OK, **continent match**, only in `+0x538` | false (`A..D` all false) | false | **false** — permanent hit ignored |
| mode **true**, match, hit in `+0x53c` | false | true | **true** |
| mode **true**, continent **mismatch**, hit `+0x538` | true | maybe | **true** via A |
| mode **false**, hit `+0x538` | true (`D`) | never | **true** via A only |
| mode **false**, only in `+0x53c` | maybe E | false | **false** unless also in 538 |
| table/def missing, hit `+0x538` | true | maybe | **true** via A |

Do **not** implement as naïve `hash538 || hash53c`.

Mode-gate body (`aa_004ce340`): AL=1 iff `+0x100==0` and `+0xac!=2` (LEA `+0xa0` null-check is effectively dead). Same switch polarity as `GiveMission` dual-hash skip.

---

## 6. Callers (live Ghidra, 13 xrefs)

| Caller | Role |
|---|---|
| `CVOGCharacter_CheckMissionRequirements` | Prereq IDs at mission `+0x9c` |
| `CVOGObject_EvalOfferableMissionInteractState` | Skip already-completed offers |
| `CVOGObject_EvalInteractStateFromChildren` | Interact state walk |
| `Client_UpdateNpcInteractIcons` | NPC icon gating |
| `CVOGVariable_EvaluateComputed` | Logic var type **9** (HasCompletedMission) |
| `FUN_004d5c10` / `FUN_004d2e50` / `FUN_0052c9d0` | Additional offer/eval glue |

---

## 7. Gaps (still open)

1. Product type of object at entity `+0xa8` (continent vs world context).
2. Semantic English of `+0xfc` beyond “match field.”
3. Writers / meaning of mode fields `+0x100` / `+0xac==2` (mode-gate dual residual).
4. Runtime inject: completed vs instance-completed vs null continent (not observed).
5. Bit-exact / diff vs retail binary open.

**Tighten note (2026-07-29):** Live re-decompile matches raw; Path A/B truth table sealed statically; mode-gate body cross-linked to `aa_004ce340`; caller set enumerated. Semantics of `+0xa8` / `+0xfc` / mode fields remain Probable/Tentative — dual stays **accept-with-gaps**. Plate “OR + continent match” is **oversimplified** (see B).

**Verdict:** Predicate CF faithful. **accept-with-gaps.**
