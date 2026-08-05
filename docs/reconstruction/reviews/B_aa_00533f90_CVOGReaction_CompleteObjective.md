# Review B (skeptical / adversarial): `aa_00533f90` CVOGReaction_CompleteObjective

| Field | Value |
|---|---|
| **Stable ID** | `aa_00533f90` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual; prior `2026-07-23`) |
| **Counterpart** | `reviews/A_aa_00533f90_CVOGReaction_CompleteObjective.md` |
| **Residual scratch** | `reviews/a_00533f90.md` |
| **Verdict** | **accept-with-gaps** on client CF; residual helper/**this**/flag seals **High**; product English + runtime open |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Advance awards XP/credits | **Falsified** — advance path grants skill/attrib only; XP/credits final-only |
| 2 | Always awards even if mission already completed | **Falsified** — final rewards gated on completed-hash miss (`+0x538`) |
| 3 | `forceComplete` skips all logic | **Overstated** — only bypasses req eval failures; still walks action vtbl+0x2c |
| 4 | `char+0x152` is a byte offset | **Doc trap** — dword index → byte `+0x548` |
| 5 | GiveXP kill path used for mission XP | **Falsified** — `PacketOrNonKill` / isKillPath=0 |
| 6 | Dialog turn-in must also send 0x2070 | **Policy risk** — client already completes locally; 0x2070 is force S2C |
| 7 | FINAL "local player only" covers XP/credits/medals | **Overstated (2026-07-29 residual)** — inventory + SearchAuto are `+0x7e`-gated; XP/credits/medals are **not** |
| 8 | Flag `+0x7e` polarity inverted / unknown | **Falsified residual** — IsLocalPlayer: missing-obj reject when set; inventory/SearchAuto when set |
| 9 | Double `FUN_00538b20` is accidental same-hash remove | **Falsified residual** — ECX=`+0x540` then ECX=`+0x544` (GiveMission insert pair reverse) |
| 10 | Skill/attrib helper names may swap pools | **Falsified residual** — `AddSkillPoints`→`+0x6ce`, `AddAttributePoints`→`+0x6cc`; both **assign absolute** |
| 11 | `FUN_0059d880` free-function / unknown object | **Falsified residual** — `__fastcall` return `*(obj+0x164)`; ECX=objective |
| 12 | GiveMission / AddActiveObjective are 1-arg free calls | **Falsified residual** — 2-arg thiscall (ECX=character) |
| 13 | This body is server authority | **Falsified** — client EXE only; server must re-validate |
| 14 | Clean deleted branches vs raw | **Falsified** — CF clean≡raw; residual sealed roles only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Advance vs final sequence math | **High** | Wrong reward timing server-side |
| Non-kill AddExperience for mission XP | **High** | Spree/kill formula incorrectly applied |
| XP bias global `0x00AAA6D0` ≈ 0.5001f | **High** | Off-by-one grants if omitted |
| Flag `+0x7e` = IsLocalPlayer polarity map | **High** | Completing / rewarding wrong entity class |
| XP/credits **not** local-gated | **High** | Over-restricting server force-complete rewards |
| Inventory / SearchAuto local-only | **High** | Ghost inventory grants for non-local |
| Skill `+0x6ce` / attrib `+0x6cc` absolute set | **High** | Wrong pool or accidental double-add |
| Min-pass `obj+0x164` | **High** | Force/non-force gate desync |
| Hash this-map: insert `+0x538`, remove `+0x540`/`+0x544`, obj `+0x548`, destroy `+0x530`, manual `+0x53c` | **High** | Journal desync / stuck active |
| Medal / map / `+0x580` FUN **roles** | **High** CF | Cosmetic / counter miss if mis-port |
| Inventory reward COID filter args | **Medium→High** framing | Wrong reward item filter (layout mild open) |
| Product English for `+0x544` / `+0x530` / medal | **Tentative** | Layout docs incomplete |
| Toast / audio FUN identities | **High** strings / **Low** server impact | Cosmetic only for server |
| Req vtable bodies | **Probable** | Wrong req satisfaction semantics |

---

## 3. Cross-check against raw (spot-check)

Raw complete spine (authoritative) with **2026-07-29 residual** seals:

```
resolve active obj @ char+0x548 by objectiveId
if missing:
  entity = *(*(char+4)+4) + char + 0xa8
  if entity[+0x7e] != 0: return 0          // local — must already hold objective
  else: def lookup → if parent not completed: GiveMission(parent); fall through
require mission def @ obj+0x14c; EnsureXmlLoaded; log "Finishing mission %d."
if pending @ +0x55c:
  for each req: eval vtbl+0x8 (unless force); action vtbl+0x2c on pass
  min = *(obj+0x164) via FUN_0059d880(ECX=obj)
  if min<=0: need allOk|force else return 0
  else: need (nActioned>=min) | allOk | force else return 0
  destroy pending helper FUN_00538e50(objId)
if seq < count-1:                            // ADVANCE
  AddActiveObjective(next); remove retiring @ +0x548
  UnlockContinentObject(next+0x120)
  set skill(+0x6ce) = skill + obj+0x130     // absolute assign
  set attrib(+0x6cc) = attrib + obj+0x134
  dirty|0x10; return 1                      // no XP/credits
if mission not in completed +0x538:          // FINAL rewards
  skill/attrib absolute (same pools)
  XP = nearest-int(ComputeObjectiveXp ± bias); AddExperience(non-kill)
  credits 64-bit add @ +0x720; dirty|1
  medal FUN_00530550; map FUN_00530610; short+0x580 FUN_00531960
  if entity[+0x7e] != 0:                    // local inventory only
    reward-table fill; for slot 0..3: filter COID → SendInventoryAddItem / delete
// shared post-final / post-advance tail:
toast if primary-entity (+0xe8a0 gate ≠ +0x7e)
insert completed +0x538 if miss; manual +0x53c insert
remove active +0x540 and paired +0x544; remove obj +0x548
destroy reward bind +0x530; EvaluatePending if final-was-new
if local(+0x7e): SearchAutoMissions
dirty|0x10; return 1
```

Cross-units: `RecvCompleteDynamicObjective(0x2070) force=1`; dialog turn-in local (no double 0x2070); bulk `CompleteMissionObjectives`; `EvaluatePendingObjectives`. Sibling GiveMission residual owns `+0x540`/`+0x544` insert pair.

**Live re-decompile 2026-07-29:** body CF ≡ frozen raw; helper bodies confirm skill/attrib assign, min-pass, hash remove/destroy strings, medal CF.

---

## 4. Surviving contract for AutoCore

```
CompleteObjective(character, objectiveId, rewardCoidLo, rewardCoidHi, force) -> 1/0
  resolve active objective @ +0x548
  if missing:
    if IsLocal(+0x7e): return 0
    else: def lookup → GiveMission(parent) if not completed @ +0x538
  evaluate pending reqs (force bypasses fail); minPass = obj+0x164
  if seq < count-1:  // ADVANCE
    AddActiveObjective(next); remove old @ +0x548; unlock next+0x120
    set skill(+0x6ce) and attrib(+0x6cc) absolute (current + obj grants)
    dirty|0x10; return 1   // no XP/credits
  if mission not in completed +0x538:  // FINAL
    skill/attrib absolute
    XP non-kill + nearest-int bias; credits 64-bit @ +0x720; medals/counters
    if IsLocal: inventory×4 (COID filter) + reward table fill
  toast if primary entity; insert completed +0x538 / +0x53c
  remove active mission +0x540 and paired +0x544; remove obj +0x548
  destroy reward bind +0x530; EvaluatePending if final-was-new
  if IsLocal: SearchAutoMissions
  dirty|0x10; return 1

S2C 0x2070 uses force=1. Local dialog turn-in should not double-send 0x2070.
Client-only apply — server must re-validate.
```

---

## 5. Open questions

1. Product English for `char+0x544` / `char+0x530` (paired with GiveMission).
2. Product names for `FUN_00530550` / `FUN_00530610` / `FUN_00531960` (`+0x580`).
3. Requirement vtable bodies (+0x8 / +0x2c).
4. Live complete/advance/0x2070 capture; bit-exact / image diff.
5. ~~Flag `+0x7e`~~ **Sealed** IsLocalPlayer.
6. ~~XP/credits local-only plate~~ **Overstatement** sealed.
7. ~~Double remove same-hash~~ **No** — `+0x544` sibling.
8. ~~Pool swap / delta vs absolute~~ **Sealed** absolute set.

**Verdict:** Accept client complete/advance CF (clean ≡ raw). Residual sealed IsLocal flag map, hash this-targets, skill/attrib pools, min-pass, arities, medal FUN roles. Server-authority language stays stripped. **accept-with-gaps.**
