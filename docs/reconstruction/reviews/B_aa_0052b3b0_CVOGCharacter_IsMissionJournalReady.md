# Review B (skeptical / adversarial): `aa_0052b3b0` CVOGCharacter_IsMissionJournalReady

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052b3b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0052b3b0_CVOGCharacter_IsMissionJournalReady.md` |
| **Sibling contrast** | `aa_0052b420` turn-in mode **1** |
| **Verdict** | **accept** on sealed gates; **needs-more-evidence** only on product names |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function is dead / unused | 3 static xrefs: `00829c5c`, `0082a25f`, `008a2032` | **Falsified** — journal UI consumers |
| 2 | Same as turn-in `0052b420` | Different arity (`ret 4` vs `ret 8`); flag 0 vs 1; no NPC loop | **Falsified** — strict sibling, not alias |
| 3 | Checks **first** objective | LEA `base + count*4 - 4` (same as turn-in) | **Falsified** — **last** objective |
| 4 | Uses active-**missions** hash `+0x540` | Image `mov eax,[ecx+0x548]` | **Falsified** — active **objectives** |
| 5 | Hash hit alone is enough | Requires `node+0x8 != 0` **and** `FUN_0052a020(...,0)` | **Falsified** as sole gate |
| 6 | Mode 1 / pending-aware eval | Image `6A 00` push 0; callee mode 0 → vtbl+0xc | **Falsified** — **mode 0** |
| 7 | Requires NPC match like turn-in | No third arg; body ends after mode-0 call | **Falsified** — no NPC filter |
| 8 | `FUN_0052a020(iVar1,0)` means this=objective | Call preserves ECX=char; callee uses `param_1+0x55c` | **Falsified** — this=character |
| 9 | `__cdecl` / 2 stack args | `ret 4` + ECX this | **Falsified** — thiscall, **1** stack arg |
| 10 | Wrapper `008a2020` can call with null character | Image: `mov ecx,[DAT_00d1b6d8]`; null → `xor al,al; ret` **before** call | **Falsified** — null-safe |
| 11 | “(Complete)” string proves turn-in claim | `FUN_0082a050` only sets label text from bool; claim chrome is ShowNpc/`0052b420` | **Survives refined** — journal chrome only |
| 12 | Clean deleted branches | Spot-check all return sites vs live decompile | **Falsified** — CF preserved |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Last-obj index formula | **High** | Wrong journal “complete” step |
| Active hash `+0x548` + key `obj+0x10` | **High** | Never-complete / always-complete UI |
| Payload `node+0x8` | **High** | Tombstone false positive |
| `FUN_0052a020` flag **0** | **High** | Port uses pending-aware eval in journal |
| No NPC filter | **High** | Invented claim-at-wrong-NPC failures |
| Body pure predicate | **High** | Accidental state mutation |
| Distinct from turn-in | **High** | Collapsed dual ports |
| Product names (self + callers) | **Tentative** | Docs only |
| Runtime multi-eval journal vs turn-in divergence | **Open** | mode 0 vs 1 product delta |

---

## 3. Cross-check against raw / image

### 3.1 Spine (authoritative)

```
lastObj = mission.objectives[mission.objCountByte - 1]
node = hash_find(char.activeObjectives(+0x548), lastObj.id(+0x10))
if !node || !node.value(+0x8): return 0
if !ObjectiveReadyEval(char, lastObj, mode=0): return 0   // FUN_0052a020
return 1
// no NPC loop
```

### 3.2 Image seals (`read_memory` @ `0x0052b3b0`)

| Fact | Bytes / pattern |
|---|---|
| Stack args = 1 dword | epilogue `C2 04 00` (`ret 4`) |
| this = character | `8B 81 48 05 00 00` (`mov eax,[ecx+0x548]`) |
| Last obj | `0F B6 90 30 01 00 00` count@+0x130; `8B 80 3C 01 00 00` arr@+0x13c; `8D 44 90 FC` |
| Mode-0 call | `6A 00 56 E8 …` push 0, push lastObj; ECX unclobbered for thiscall into `0052a020` |
| Body end before sibling | padding `CC…` then `FUN_0052b420` at `0x0052b420` |

### 3.3 Sibling image seals (`0x0052b420`) — contrast only

| Fact | Pattern |
|---|---|
| `ret 8` | two stack args |
| `6A 01` | mode **1** |
| Type-3 loop | `FF 52 50` / `83 F8 03` / target `+0x18` vs NPC `+0x34` |

### 3.4 Call-site seals

| Site | Framing |
|---|---|
| `FUN_008a2020` `0x008a2020` | `mov ecx,[DAT_00d1b6d8]`; null→0; `push mission; call 0052b3b0` |
| `FUN_0082a050` `0x0082a25f` | same global this; bool → `"(Complete)"` vs empty label |
| `FUN_00829b20` `0x00829c5c` | `mov ecx,[DAT_00d1b6d8]`; push mission; call; then `FUN_00829ac0` |

Clean preserves spine. **No deleted branches. No invented NPC gate.**

---

## 4. Surviving contract for AutoCore

```
// Client journal / detail "mission complete" probe (NOT claim/turn-in)
bool IsMissionJournalReady(Character ch, MissionDef mission):
  if mission.ObjectiveCount == 0: undefined (callers should gate)
  last = mission.Objectives[Count - 1]
  if !ch.ActiveObjectives.Contains(last.Id) with live payload: return false
  if !AllObjectiveEvaluatorsPass(ch, last, strict:false /* mode 0 */): return false
  return true

// Do NOT pass NPC.
// Do NOT use FUN_0052a020 mode 1 here.
// Do NOT use active-missions hash (+0x540).
// Do NOT drive claim chrome (+0x64c) from this — that is IsMissionTurnInReady (0x0052b420).
// UI: true → journal label "(Complete)" (FUN_0082a050).
```

---

## 5. Open questions

1. Retail symbol for `0x0052b3b0`.
2. Product English for mode-0 eval slot (`vtbl+0xc`) across Collect/Kill/Deliver/…
3. Runtime capture: mission that is journal-ready but fails turn-in mode-1 or wrong NPC.
4. Bit-diff vs retail EXE.

**Verdict:** Adversarial review **accepts** last-objective, active-hash, mode-0 readiness, and **distinct-from-turn-in** seals. Residual gaps are naming/runtime only — not CF.
