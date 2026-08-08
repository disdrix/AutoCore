# Review B (skeptical / adversarial): `aa_004d2e50` CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d2e50` |
| **VA** | `0x004d2e50` |
| **Canonical name** | `CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred` |
| **Review date** | `2026-08-05` (MEGA-068 dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_004d2e50_CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `read_memory` + analyze/xrefs + `disassemble_function` + assembly context |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function purpose is `VOG_DEBUG_STOP` / Named_VOG_DEBUG_STOP | **Falsified** — string only on TraversalLock error paths; body is mission interact eval |
| 2 | `__thiscall` with ECX=this primary | **Falsified** — entry reads stack `[ESP+0xc]` after `SUB ESP,8` as child; never loads this from ECX; parent ECX is dead |
| 3 | `RET 4` / cdecl caller-clean | **Falsified** — three **`RET 8`** (`C2 08 00`) exits |
| 4 | Returns bool / only 0/1 | **Falsified** — `MOV AL,0`, `MOV AL,3`, `SETNE AL; ADD AL,6` → {0,3,6,7} |
| 5 | Same as `CVOGObject_EvalOfferableMissionInteractState` `0x004d5aa0` | **Falsified** — different VA; parent calls both; this one is child-vector walk |
| 6 | Same as `CVOGMission_EvalActiveObjectiveInteractState` `0x004d3ef0` | **Falsified** — different return set {0,4,5,8} vs {0,3,6,7}; different object |
| 7 | Same as `FUN_004d3ba0` type-0x25 sibling | **Falsified** — sibling also called from parent; separate body `0x004d3ba0–0x004d3eca` |
| 8 | Many callers / global mission manager | **Falsified** — **1** caller, **2** xrefs only |
| 9 | Writes mission state / completes missions | **Falsified** — read-only eval + hash traversal locks; no complete/set-active stores beyond lock bytes |
| 10 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Decisive machine dataflow

```text
// entry
SUB  ESP, 8
MOV  EDX, [ESP+0xc]          // child = arg1
TEST [EDX+0x244], ...
MOV  EBP, [ESP+0x20]          // character = arg2 (after frame)

// return-3 path
CMP  byte [ESP+0x13], 0       // completed_flag
JZ   ret0
MOV  AL, 3
ADD  ESP, 8
RET  8

// return-6/7 path
PUSH 0
MOV  ECX, ESI                 // mission
CALL FUN_00547920
SETNE AL, [mission+0x169]
ADD  AL, 6
RET  8
```

Parent call sites (`0x004d7823` / `0x004d7830`):

```text
PUSH EBP                // character
PUSH ESI                // child (type 0x25 payload)
MOV  ECX, EDI           // unused by callee
CALL 0x004d2e50
CMP  AL, BL / MOV BL, AL
CMP  BL, 6
JGE  skip_offerable
```

A ≡ B on live decompile + body range + RET bytes + xrefs + call-site context.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| CF two-path mission eval | **High** | wrong interact icons |
| ABI stdcall RET 8; 2 stack args | **High** | stack smash |
| Return set {0,3,6,7} | **High** | UI state matrix |
| Sole parent type-0x25 | **High** | over-general port |
| Product English / code-3 label | Medium | naming only |
| Child field English | Medium | struct docs |

---

## 4. Surviving contract for AutoCore

```csharp
// Child active/complete mission interact eval (type 0x25 helper)
// stdcall; callee cleans 8 bytes.
byte EvalChildActiveCompleteMissionInteract(ChildReaction child, Character character)
{
    // Path A: foreach missionId in child.MissionIdVec (+0x244):
    //   if region-active (short+0xac == -1) && CheckRequirements(mission, character)==0
    //       -> return 6 + (mission.Flag169 ? 1 : 0);
    //   if character.HasCompleted(missionId) && completed-def ok -> flag = true;
    //   return flag ? 3 : 0;
    // Path B: if child.ByteFilterVec (+0x234) non-empty:
    //   traverse character mission hash (+0x540) with TraversalLock;
    //   match mission.Byte86 in filter; incomplete + reqs ok -> return 6/7;
    // return 0;
}
// Keep distinct from EvalOfferableMissionInteractState (004d5aa0) and
// CVOGMission_EvalActiveObjectiveInteractState (004d3ef0).
// Do not name after VOG_DEBUG_STOP.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/caller roles/return set. Residual product English for code **3** and child field names → **accept-with-gaps**.
