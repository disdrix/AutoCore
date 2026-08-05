# Review B (skeptical / adversarial): `aa_0052b420` CVOGCharacter_IsMissionTurnInReady

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052b420` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0052b420_CVOGCharacter_IsMissionTurnInReady.md` |
| **Verdict** | **accept** on sealed gates; **needs-more-evidence** only on `FUN_0052a020` product name + full type enum |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function is decorative / unused | 4 xrefs; ShowNpc branches chrome + `+0x64c` on result | **Falsified** — drives turn-in UI |
| 2 | Checks **first** objective | LEA `base + count*4 - 4` | **Falsified** — **last** objective only |
| 3 | Uses active-**missions** hash `+0x540` | Image `mov eax,[ecx+0x548]` | **Falsified** — active **objectives** `+0x548` |
| 4 | Hash hit alone is enough | Requires `node+0x8 != 0` **and** `FUN_0052a020` | **Falsified** as sole gate |
| 5 | Always requires NPC match | `param_3==0` skips filter; journal path passes 0 | **Falsified** — NPC optional |
| 6 | Type-3 mismatch still ready | Image `jne` → `xor bl,bl` → return 0 | **Falsified** — mismatch fails |
| 7 | Empty evaluators fail | begin==end skips loop → return 1 after complete | **Falsified** — empty OK |
| 8 | `FUN_0052a020(iVar1,1)` means this=objective | Call preserves ECX=char; callee uses `param_1+0x55c` | **Falsified** — this=character, obj on stack, flag=1 |
| 9 | `__cdecl` / 3 stack args | `ret 8` + ECX this | **Falsified** — thiscall, 2 stack args |
| 10 | Clean deleted branches | Spot-check all return sites | **Falsified** — CF preserved |
| 11 | All evaluators must match NPC | Non-type-3 ignored; only type-3 target checked | **Survives refined** — type-3 only |
| 12 | Compares continent id like `EvalActiveObjectiveInteractState` | Entity chain via `npc+4`→`+0xac`→`+0x34` (clonebase) | **Survives as NPC CBID**, not continent |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Last-obj index formula | **High** | Turn-in on wrong sequence step |
| Active hash `+0x548` + key `obj+0x10` | **High** | Never-ready / always-ready |
| Payload `node+0x8` | **High** | Tombstone / free node false positive |
| Complete via `FUN_0052a020` flag 1 | **High** | Claim before objective done |
| NPC type-3 filter | **High** | Claim at wrong giver NPC |
| NPC null skip | **High** | Journal / non-dialog callers break |
| Body pure predicate | **High** | Accidental state mutation in port |
| `FUN_0052a020` product name | **Tentative** | Docs only |
| Evaluator type catalog | **Open** | Other types may matter for sibling UX |

---

## 3. Cross-check against raw / image

### 3.1 Spine (authoritative)

```
lastObj = mission.objectives[mission.objCountByte - 1]
node = hash_find(char.activeObjectives(+0x548), lastObj.id(+0x10))
if !node || !node.value(+0x8): return 0
if !ObjectiveCompleteEval(char, lastObj, strict=1): return 0   // FUN_0052a020
ready = 1
if npc && evaluators non-empty:
  for eval in evaluators:
    if type(eval)==3 and eval.target(+0x18) != npc.clonebase(+0x34 chain):
      ready = 0; break
return ready
```

### 3.2 Image seals (`read_memory` @ `0x0052b420`)

| Fact | Bytes / pattern |
|---|---|
| Stack args = 2 dwords | epilogue `C2 08 00` (`ret 8`) |
| this = character | `8B 81 48 05 00 00` (`mov eax,[ecx+0x548]`) |
| Last obj | `0F B6 90 30 01 00 00` count@+0x130; `8B 80 3C 01 00 00` arr@+0x13c; `8D 44 90 FC` |
| Complete call | `6A 01 57 E8 …` push 1, push lastObj; ECX unclobbered |
| Type-3 filter | `FF 52 50` / `83 F8 03` / target `+0x18` vs NPC `+0x34` |

### 3.3 Call-site seals

| Site | Framing |
|---|---|
| ShowNpc `0x00943a43` | push mission; `mov ecx,[ebp+0xe98]`; push NPC; call |
| `FUN_008a8770` | `mov ecx,[DAT_00d1b6d8]`; push 0; push mission; call — **G4 off** |
| `FUN_004d5c10` | ECX=char; push mission-ish; push NPC/object — invert result into state `+0x2c` |

Clean preserves spine. **No deleted branches.**

---

## 4. Surviving contract for AutoCore

```
// Client dialog turn-in ready (mirror before offering claim chrome / CompleteObjective)
bool IsMissionTurnInReady(Character ch, MissionDef mission, NpcObject? npc):
  if mission.ObjectiveCount == 0: undefined on client (ShowNpc already gates count≠0)
  last = mission.Objectives[Count - 1]
  if !ch.ActiveObjectives.Contains(last.Id) with live payload: return false
  if !AllObjectiveEvaluatorsPass(ch, last, strict:true): return false
  if npc != null:
    for e in last.Evaluators:
      if e.Type == Interact/UseObject (client type 3)
         and e.TargetId != npc.ClonebaseId: return false
  return true

// Do NOT use active-missions hash (+0x540) here.
// Do NOT require NPC when probing journal-only paths (npc=null).
// Dialog: ready → claim mode (+0x64c=1); not-ready → offer vs active via +0x540 lookup in ShowNpc.
```

---

## 5. Open questions

1. Product name / full dual for `FUN_0052a020` (owned separately).
2. Complete evaluator type enum mapping (3/6/0xc appear in sibling UI).
3. Runtime capture of multi-type-3 last objective at wrong vs right NPC.
4. Bit-diff vs retail EXE.

**Verdict:** Adversarial review **accepts** last-objective, active-hash, and readiness-gate seals. Residual gaps are naming/enum/runtime only — not CF.
