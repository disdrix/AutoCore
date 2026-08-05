# Review B (skeptical / adversarial): `aa_00536080` CVOGCharacter_CompleteMissionObjectives

| Field | Value |
|---|---|
| **Stable ID** | `aa_00536080` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual strengthen; prior spot-check same day) |
| **Counterpart** | `reviews/A_aa_00536080_CVOGCharacter_CompleteMissionObjectives.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present and strengthened** (A + B modern pair; residual pass) |
| **Verdict** | **accept-with-gaps** on loop CF + convention; **needs-more-evidence** only on mission-authority English / multi-force values / runtime |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function completes the **mission** | **Overstated** — body only force-completes each objective via callee; completed-hash / wrap-up not in this unit |
| 2 | All objectives always succeed | **Unproven** — CompleteObjective return ignored (no `TEST AL` after CALL) |
| 3 | Reason / 4th arg is always `0xffffffff` | **Falsified** — args **2/3** are −1; **4th is stack formal** (prereqs: **1**); plate step 5 is wrong |
| 4 | Return 1 means work was done | **Falsified** — count 0 still returns 1 if def found (`JLE` skip → `MOV AL,1`) |
| 5 | This is `__cdecl` / no `this` / static free function | **Falsified** — `PUSH ECX`/`MOV [ESP],ECX` save; reload ECX for CompleteObjective; **`RET 8`**; callers set ECX |
| 6 | Call-site `MOV ECX,ESI` is dead | **Falsified** — ECX is the character required by CompleteObjective thiscall |
| 7 | EvaluatePending / other paths use force 0 | **Falsified (static)** — sole xrefs are Prerequisites; both `PUSH 1` |
| 8 | 4th formal is a rich “reason” enum | **Overstated** — callee treats it as **forceComplete** (char); only `0` vs non-zero gates req eval |
| 9 | Clean invents behavior | **Survives as typing + convention correction** — CF ≡ raw; thiscall was decompiler lie |
| 10 | Name “CompleteMissionObjectives” seals progression | **Name inflation** — bulk force loop only |

---

## 2. Decisive dataflow (raw + listing)

```
this (ECX), missionId, forceFlag   // __thiscall; RET 8
  save this
  root = FUN_0053fff0(DAT_00b041fc) // ECX overwritten for FUN, this stays on stack
  table = *root                     // null → 0
  def = Lookup(table, missionId)    // miss → 0
  count = u8(def+0x130)             // MOVZX
  array = *(def+0x13c)
  for i in 0..count-1:
    CompleteObjective(this, *(array[i]+0x10), -1, -1, forceFlag)  // return ignored
  return 1

Sole callers (Ghidra xrefs 2026-07-29):
  CheckMissionPrerequisites @ 0x005365ae  // live-active + autoComplete
  CheckMissionPrerequisites @ 0x00536722  // post-GiveMission + autoComplete
  both: PUSH 1; PUSH missionId; MOV ECX,ESI; CALL
```

### Listing anchors (function listing, not free-range disasm)

| VA | Insn | Residual use |
|---|---|---|
| `0x00536080` | `PUSH ECX; MOV [ESP],ECX` | this save |
| `0x00536084` | `MOV ECX,[0x00b041fc]` | table owner for FUN |
| `0x005360aa` / `0x005360ed` | `RET 8` | callee-cleaned 8-byte formals |
| `0x005360ae` | `MOVZX EBX,byte [EDI+0x130]` | count |
| `0x005360c1` | `MOV ECX,[EDI+0x13c]` | array base |
| `0x005360cd` | `MOV EAX,[EDX+0x10]` | objective id |
| `0x005360d0` | `MOV ECX,[ESP+0x10]` | restore this for callee |
| `0x005360d4..d9` | `PUSH EBP; PUSH -1; PUSH -1; PUSH EAX` | force, wildcards, id |
| `0x005360da` | `CALL CompleteObjective` | no status consume |

Name inflates “mission complete”; CF is **force all objectives on def with forceComplete flag**.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Def lookup + loop bounds | **High** | Wrong bulk complete set |
| Obj id at +0x10 | **High** | Completing wrong ids |
| thiscall + live this | **High** | Porting as free function → CompleteObjective on wrong/null this (crash / wrong char) |
| forceFlag forwarding | **High** | Wrong req-bypass / reward side effects in callee |
| Sole-caller force = 1 | **High** | Inventing other force values |
| “Reason enum” multi-value | **Low** | Over-modeling a force bit |
| Mission finished after this | **Low** | Server/client mission state desync if assumed |
| Empty-mission return 1 | **High** CF; intent **Probable** | Callers treating 1 as “objectives ran” |
| `FUN_0053fff0` / `DAT_00b041fc` product name | **Tentative** | Wrong English for table owner |
| Clean CF ≡ raw | **High** | — |

---

## 4. Cross-check against raw / live

```
tableRoot = FUN_0053fff0(global)
if *tableRoot && (def = lookup(*tableRoot, id)):
  for i in 0 .. byte(def+0x130)-1:
    CompleteObjective(this, *( *(def+0x13c)[i] + 0x10 ), -1, -1, forceFlag)
  return 1
return 0
```

Live decompile 2026-07-29 **identical** to 2026-07-23 raw body (still mislabels convention as cdecl and drops this). Clean matches CF and **corrects** convention from listing.

Offset collision note: GiveMission gates “awardable” on non-zero `def+0x130` (dword-index `+0x4c`) — same byte used here as **count**. Treat as objective-count field, not a separate flag.

FUN usage note (boundary only): this unit gates/lookups via `*FUN()`; sibling CompleteObjective missing-obj path uses `FUN()+4` for a related table. **Do not merge** table-slot English in this dual — only seal what this body reads (`*return`).

---

## 5. Surviving contract for AutoCore

```
CompleteMissionObjectives(thisCharacter, missionId, forceComplete) -> 0/1
  require mission def in global table (FUN_0053fff0 / DAT_00b041fc owner)
  for each objective def on mission:
    CompleteObjective(thisCharacter, objId, -1, -1, forceComplete)
  return 1 if def existed (even 0 objectives)
  does not itself write completed-mission hashes
  client sole static use: prereq auto-complete with forceComplete=1
  convention: __thiscall; RET 8
```

**Porting rules (adversarial):**

1. **Never** call without a real character `this` — force path is not free-standing.
2. **Never** treat return 1 as “all objectives succeeded” or “mission marked complete.”
3. **Never** invent a multi-value reason enum from this unit alone; only force 0/1 is evidenced.
4. **Never** assume EvaluatePending or dialog paths call this (they call CompleteObjective directly).

---

## 6. Open questions

1. What callers expect when count==0 returns 1 (only prereq auto-complete path observed).
2. Whether any CompleteObjective failure should abort (retail ignores).
3. Mission-level completion path after bulk force (inside CompleteObjective dual).
4. Live prereq path with force `1` capture; other force values if any dynamic caller appears.
5. Product name / owner class of `DAT_00b041fc` (+0xf18 lazy slot).
6. Why decompiler still emits `__cdecl` despite `RET 8` (tooling residual, not behavioral).

**Verdict:** Accept bulk-loop CF + thiscall/forceFlag residual seal; strip mission-authority language; seal wrap-up only via CompleteObjective duals + runtime. **accept-with-gaps.**
