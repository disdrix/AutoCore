# Review B (skeptical / adversarial): `Client_NpcDialog_PrepareResponseOpcode` @ `0x008abd70`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008abd70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual strengthen; prior refresh same day; original 2026-07-23) |
| **Counterpart** | `reviews/A_aa_008abd70_Client_NpcDialog_PrepareResponseOpcode.md` |
| **Verdict** | **accept-with-gaps** |
| **Scratch** | `tmp/a_008abd70.md` |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Opcode is 0x2070 / CompleteDynamicObjective | Immediate is **0x206e** at `0x008abd8c` (`read_memory`) | **Falsified** — 0x206E stands |
| 2 | This function assembles full MissionDialogResponse | Only sets opcode + `+0x670`; body elsewhere | **Attack succeeds against over-read of name** — stamp + UI, not full pack |
| 3 | Only site for 0x206E in the image | Data hits exist outside `.text` | **Data ≠ code.** Accept “only code-site store,” not “only dword in PE” |
| 4 | Always paired 1:1 with a send | Prepare on **show**; send is deferred Flush; cancel policy open | **Gap remains** (cross-function) |
| 5 | Plate payload layout is *this* function’s stores | missionId/accepted/TFID are HandleButton | **Documentation overclaim risk** — layout is buffer contract |
| 6 | Show always prepares 0x206E even for abandon-only chrome | Abandon is HandleButton state 2 modal; Show still stamps on NPC dialog present | **Survives for present spine** |
| 7 | `param_1` / `unaff_ESI` are decompiler fiction | Call-site `MOV ESI,EBX; MOV ECX,EDI; CALL` | **Falsified** — dual-register framing **High** |
| 8 | `param_1 == 0` is a live Show path | Show gates `def != 0` before CALL; only static caller | **Falsified for sole caller** — branch exists, not reached from Show |
| 9 | Multiple callers write the opcode | xrefs: only Show @ `0x00943a60` | **Falsified** — single static caller |
| 10 | Opcode store skipped when param==0 | Stores run **before** `JE` on ZF from `TEST ECX` | **Falsified** — stamp always in body |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| C2S response opcode literal 0x206E at +0x650 | **High** | Wrong AutoCore GameOpcode |
| Prepare is not the send | **High** | Look for send in wrong function |
| ESI=dialog, ECX=mission def | **High** | Wrong object ownership in rebuilds |
| Sole static caller Show | **High** | Miss alternate prepare path |
| Sole caller always nonzero def | **High** | Over-weight param==0 chrome as live dialog open |
| Function name implies pure preparer | Medium | Miss UI side effects in rebuilds |
| Full payload laid out here | **Low — false if claimed** | Broken field map |
| Unique 0x206E code-site | High (data exclusion) | Miss alternate writer |
| When Flush fires after prepare | Open (peer unit) | Stale 0x206E on cancel |

---

## 3. Cross-check against decompiler + asm (minimal contract)

```
// Sole caller @ 0x00943a60 (Show present spine):
//   ESI = dialog (EBX); ECX = missionDef (EDI); CALL Prepare

NpcDialog_PrepareResponseOpcode(ECX=param_missionDef, ESI=dialog):
  dialog+0x670 = param_missionDef;
  dialog+0x650 = 0x206E;     // THE wire-critical side effect (unconditional in body)
  if param_missionDef == 0:  // not reached from sole static caller
    layout chrome on +0x6dc
  else:
    maybe FUN_00547920 if def+0x168 == 0
    title/layout on +0x6dc; optional +0x6e4 panel (FUN_008ab9b0 rewards)
  // NO sector send
```

Anything claiming “builds missionId/accepted/TFID here” is **wrong**.  
Anything claiming “Show calls with no args” is **decompiler presentation only**.

---

## 4. Surviving contract for AutoCore

```
On NPC mission dialog UI show/reconfigure (present spine):
  Client stamps dialog response opcode field (+0x650) with 0x206E
  and stores mission def* at +0x670.

Server opcode MissionDialogResponse = 0x206E is correct.

Packet body fields are NOT authored by Prepare; they are authored by
MissionDialogHandleButton (state 1) and flushed by
MissionDialog_FlushPreparedResponse (0x008ab8f0).
```

---

## 5. Open questions

1. Product names for chrome/title helpers and widget vtbls.
2. Title `[%d] %s` source operands (level vs name tables).
3. Should AutoCore clear or ignore 0x206E if Accepted/missionId zero on receive? (server policy)
4. Indirect calls with null param — none found statically.

---

## 6. Verdict

**accept-with-gaps.**

Adversarial residual: prior gaps on **register framing** and **param typing** are **closed High** via call-site asm + entry `read_memory`. Remaining gaps are UI chrome depth and peer flush policy — not opcode identity or “who prepares 0x206E.”
