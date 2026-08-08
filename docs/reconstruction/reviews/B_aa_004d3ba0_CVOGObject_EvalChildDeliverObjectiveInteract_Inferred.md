# Review B (skeptical / adversarial): `aa_004d3ba0` CVOGObject_EvalChildDeliverObjectiveInteract_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d3ba0` |
| **VA** | `0x004d3ba0` |
| **Canonical name** | `CVOGObject_EvalChildDeliverObjectiveInteract_Inferred` |
| **Review date** | `2026-08-05` (MEGA-069 dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_004d3ba0_CVOGObject_EvalChildDeliverObjectiveInteract_Inferred.md` |
| **Live tools** | Independent `decompile_function` + `read_memory` + analyze/xrefs + `disassemble_function` + assembly context |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Function purpose is `VOG_DEBUG_STOP` / Named_VOG_DEBUG_STOP | **Falsified** — string only on TraversalLock error paths; body is deliver-target interact eval |
| 2 | `__stdcall` with dead ECX like sibling `004d2e50` | **Falsified** — `MOV ESI,ECX` then `MOV ECX,[ESI+0xe4e8]` before ResolveObjectTarget; ECX is live |
| 3 | `RET 4` / cdecl caller-clean | **Falsified** — two **`RET 8`** (`C2 08 00`) exits @ `0x004d3c71`, `0x004d3ee0` |
| 4 | Returns bool / only 0/1 | **Falsified** — `XOR AL,AL`; stores best `4`/`5`/`8`; `MOV AL,[ESP+0x0f]` |
| 5 | Same as `CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred` `0x004d2e50` | **Falsified** — different VA/body; return set {0,4,5,8} vs {0,3,6,7}; this uses ECX |
| 6 | Same as `CVOGObject_EvalOfferableMissionInteractState` `0x004d5aa0` | **Falsified** — different VA; parent calls both; offerable walks global mission table |
| 7 | Same as `CVOGMission_EvalActiveObjectiveInteractState` `0x004d3ef0` | **Falsified** — different VA (next function after pad); separate dual residual |
| 8 | Many callers / global mission manager entry | **Falsified** — **1** caller, **2** xrefs only |
| 9 | Writes mission state / completes deliver | **Falsified** — read-only eval + hash traversal lock bytes only |
| 10 | Decompiler `return uVar7 & 0xffffff00` is authoritative | **Falsified** — epilog is `MOV AL,best; RET 8` |
| 11 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Decisive machine dataflow

```text
// entry
PUSH -1 / SEH
SUB  ESP, 0x18
PUSH ESI
MOV  ESI, ECX                 // this = host
...
MOV  ECX, [ESP+0x30]          // child = arg1
MOV  EAX, [ECX+0x1d8]         // pair-vec begin
...
MOV  ECX, [ESI+0xe4e8]        // reaction mgr from this
CALL CVOGReaction_ResolveObjectTarget

// early fail
XOR  AL, AL
RET  8

// score paths (best @ [ESP+0x13] after frame)
MOV  byte [best], 4           // action+0x138 == 0
MOV  byte [best], 5           // req fail
MOV  byte [best], 8           // req pass

// success epilog
MOV  AL, [ESP+0x0f]           // best
RET  8
```

Parent call sites (`0x004d7806` / `0x004d7813`):

```text
CMP  AL, 0x25                 // child type
JNZ  not_25
PUSH EBP                      // character
PUSH ESI                      // child
MOV  ECX, EDI                 // host this — LIVE in callee
CALL 0x004d3ba0
CMP  AL, BL
JLE  skip_refresh
... CALL again ...
MOV  BL, AL                   // max-aggregate
CMP  BL, 6
JGE  skip_sibling_helpers
```

A ≡ B on live decompile CF + body range + RET bytes + xrefs + call-site context + ECX liveness.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| CF resolve → type-0x12 → hash score 4/5/8 | **High** | wrong interact icons |
| ABI thiscall + RET 8; 2 stack args | **High** | stack smash / wrong this |
| Return set {0,4,5,8} | **High** | UI state matrix |
| Sole parent type-0x25 | **High** | over-general port |
| ECX live (unlike sibling 004d2e50) | **High** | wrong calling convention port |
| Product English / state labels | Medium | naming only |
| `this_host` class English | Medium | struct docs |

---

## 4. Surviving contract for AutoCore

```csharp
// Child deliver/use objective interact eval (type 0x25 helper)
// thiscall; ECX = host with +0xe4e8 reaction mgr; callee cleans 8 bytes.
byte EvalChildDeliverObjectiveInteract(Host host, ChildReaction child, Character character)
{
    // if child.PairVec(+0x1d8) empty -> return 0
    // target = ResolveObjectTarget(host.ReactionMgr, pair[0], pair[1])
    // fill list via vcall+0x124; require NPC type 0x12
    // TraversalLock character.ObjectHash(+0x540)
    // for each world object matching continent/region to NPC:
    //   action = last slot of object.ActionVec
    //   if action.Field138 == 0: best = max(best, 4)
    //   else for each req in action.Reqs:
    //     if req.GetType()==3 && req.Key18 != npc.MI+0x34: continent_fail
    //     if !Lookup(char+0x55c, action.Key) or !req.Pred(char, entry): pred_fail
    //   best = continent_fail||pred_fail ? max(best,5) : max(best,8)
    // return best;
}
// Keep distinct from EvalChildActiveCompleteMissionInteract (004d2e50),
// EvalOfferableMissionInteractState (004d5aa0), and 004d3ef0.
// Do not name after VOG_DEBUG_STOP.
// Do not port as stdcall with dead ECX (unlike sibling 004d2e50).
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/caller roles/return set/ECX liveness. Residual product English for codes **4/5/8** and host/child field names → **accept-with-gaps**.
