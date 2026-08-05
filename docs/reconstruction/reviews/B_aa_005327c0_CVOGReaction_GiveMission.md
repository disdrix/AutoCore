# Review B (skeptical / adversarial): `aa_005327c0` CVOGReaction_GiveMission

| Field | Value |
|---|---|
| **Stable ID** | `aa_005327c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual; prior `2026-07-28` / `2026-07-23`) |
| **Counterpart** | `reviews/A_aa_005327c0_CVOGReaction_GiveMission.md` |
| **Residual scratch** | `reviews/a_005327c0.md` |
| **Verdict** | **accept-with-gaps** on client CF; helper **roles** High; server-mirror prose still external |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | This is server authority for mission grant | **Falsified** — client EXE only; plate “server mirror” / `OnMissionStateChanged` is external prose, not body |
| 2 | Always toasts “Received Mission” | **Falsified** — only when `word def+0xF8 == 0` after insert path |
| 3 | Directly writes hash at `+0x540` in this body | **Overstated** — insert via `FUN_0053c360` / `FUN_0053c660`, not raw store at +0x540 |
| 4 | Double `FUN_0053c360` is accidental same-hash insert | **Falsified (2026-07-29 residual)** — first ECX=`+0x540`, second ECX=`**+0x544**`; end-quest removes both |
| 5 | Opens map volume gates | **Falsified by plate+body** — UnlockContinentObject only; volume re-eval elsewhere |
| 6 | `WeaponAllowsKillXpBonus` is a weapon-XP feature here | **Name attacked** — mode gate; **this** is entity-chain `+0xa8` object, not character |
| 7 | Outer already-active (`+0x540` hit) returns **1** | **Falsified** — outer hit skips grant body → **return 0** |
| 8 | Outer already-active returns **0** | **Survives** — raw + asm `XOR AL,AL` |
| 9 | Inner re-check hit (“Already had mission”) returns 0 | **Falsified** — logs then fall-through **return 1** |
| 10 | Def `+0x130` is a distinct “awardable” flag | **Overstated** — asm uses **byte objective count**; grant needs count ≥ 1 |
| 11 | Clean deleted branches vs raw | **Falsified** — CF clean≡raw; residual only sealed `this`/roles |
| 12 | AddActiveObjective is 1-arg in GiveMission | **Falsified** — asm 2-arg thiscall; raw elides `this` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Obj-count gate + outer-active / completed grant CF | **High** | Client journal desync vs server |
| Outer already-active → **return 0** | **High** | Callers treating 0 as hard fail vs “already have” |
| Inner re-check hit → log + **return 1** | **High** | Mis-count new grants if collapsed with outer path |
| Completed-hash dual reject (+0x538 / +0x53c) | **High** | Repeatable missions blocked wrongly |
| UnlockContinentObject always after objective branch | **High** | Missing unlock visuals |
| Toast condition (`word def+0xF8==0` only) | **High** | Missing/extra toasts |
| `FUN_0053c360` → `+0x540` then optional `+0x544` | **High** | Wrong dual-active model if collapsed |
| `FUN_0053c660` → state blob on `+0x530` | **High** | Wrong runtime-state ownership |
| `FUN_00547920` XML ensure on def | **High** | Missing lazy load / false free-function model |
| Mode gate framing (entity `+0xa8` object) | **High** | Wrong `this` if assumed character |
| Mode product meaning (`+0xac==2`, `+0x100`) | **Probable** | Wrong instance vs permanent set |
| `+0x544` / `+0x530` product English names | **Tentative** | Layout docs incomplete |

---

## 3. Cross-check against raw (spot-check)

Raw grant spine (authoritative) with **2026-07-29 residual** byte/`this` seals:

```
if table && def && byte def[+0x130] >= 1:          // obj count, not awardable bit
  EnsureXmlLoaded(def, 1); maybe EnsureXmlLoaded(def, 0) if def[+0x168]==0
  if !active(+0x540):                              // OUTER — miss only
    if word def[+0xAC] != -1:
      reject completed (+0x538) if !mode → return 0
      reject instance-completed (+0x53c) if mode → return 0
    ensure objective (+0x548) / else log already-had-objective
    UnlockContinentObject(firstObj+0x120)
    if !active(+0x540):                            // INNER re-check
      CNDHash_Insert(+0x540, id, def, 0)
      if mode && (word def[+0xF8]==0 || dword def[+0x100]!=-1):
        CNDHash_Insert(+0x544, id, def, 0)         // sibling active hash
      strip completed (+0x538) if word def[+0xAC]==-1 via CNDHash_Remove
      new 0x30 blob; lower_bound tree +0x508; copy prior; Insert(+0x530, *def, blob)
      FUN_0052d8b0(char, 0, *def)
      if word def[+0xF8]==0: toast + gen_give_quest; return 1
    else:
      log "Already had mission..."
    return 1
  // OUTER hit: fall through
return 0
```

Clean preserves spine CF (no wholesale rewrite this residual). Cross-units: `SearchAutoMissions → GiveMission → AddActiveObjective`; Dispatch case `0x1e`.

**Prior dual error corrected (2026-07-28):** outer already-active → **0** (not 1).  
**Residual 2026-07-29:** double-insert is **`+0x540` then `+0x544`**, not same-hash; `FUN_00547920` is def XML load (ECX=def).

---

## 4. Surviving contract for AutoCore

```
GiveMission(character, missionId) -> 1/0
  require def table + def + byte objCount@+0x130 >= 1
  EnsureXmlLoaded(def)
  if already active (+0x540): return 0          // outer — no re-grant
  if non-repeatable (word@+0xAC != -1) conflict with mode-selected completed set: return 0
  ensure first objective active; UnlockContinentObject
  if still not active:
    CNDHash_Insert active +0x540
    optional CNDHash_Insert sibling +0x544 under mode + (type@+0xF8==0 || field@+0x100!=-1)
    maybe strip completed +0x538 if repeatable (word@+0xAC == -1)
    bind 0x30 state blob on +0x530; notify state tree
    maybe toast "Received Mission" + gen_give_quest when word@+0xF8==0
  else:
    log already-had-mission (inner race)
  return 1 on grant-body success path
Does not implement server OnMissionStateChanged; client-only apply.
Does not open volume gates.
```

---

## 5. Open questions

1. Product identity of entity object at `+0xa8` and mode values (`+0xac==2`, `+0x100`).
2. Product English for `char+0x544` (paired active) and `char+0x530` (state-blob hash).
3. Whether callers treat outer return-0 as hard error vs soft “have it” (recovered callers ignore).
4. ~~AddActiveObjective arity~~ **Sealed** 2-arg thiscall from this site.
5. Live grant + continent unlock + toast + outer-active capture.
6. ~~Double insert accidental?~~ **No** — `+0x544` sibling; product name open.

**Verdict:** Accept client grant CF (clean ≡ raw CF). Residual sealed hash insert/remove roles + `+0x544` pair + def byte map. Outer already-active = **0**; inner “already had mission” = **1**. Server-authority language stays stripped.
