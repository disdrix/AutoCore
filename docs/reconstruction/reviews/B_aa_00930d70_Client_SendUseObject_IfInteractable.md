# Review B (skeptical / adversarial): `aa_00930d70` Client_SendUseObject_IfInteractable

| Field | Value |
|---|---|
| **Stable ID** | `aa_00930d70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual strengthen) |
| **Counterpart** | `reviews/A_aa_00930d70_Client_SendUseObject_IfInteractable.md` |
| **Scratch** | `tmp/a_00930d70.md` |
| **Verdict** | **accept** on CF + objective store; wire product still **needs-more-evidence** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Identical packet / behavior to `Client_SendUseObject` | **Falsified** — no `FindObjectiveMatchingTarget`; objective may be **0** not **−1**; no `+0xd28` stash; net is `client+0xc78` not the sibling global expression |
| 2 | Always sends once called | **Falsified** — multi-gate; returns 0; even on allow, send is null-checked |
| 3 | Type-4 is the only allow path | **Falsified** — OR with non-zero `FUN_00524520` |
| 4 | `FUN_00524520` is boolean “isInteractable” | **Falsified** — returns objective id from active hash (`def+0x10`) or 0; used as truthy **and** wire field |
| 5 | Objective field left uninitialized / garbage | **Falsified (bytes)** — explicit `MOV [ESP+0x1c],EAX` after FUN; type-4 with EAX=0 stores **0** |
| 6 | Character `this` for FUN is unknown residual | **Falsified (bytes)** — `MOV ECX,[ESI+0xe98]` immediately before call |
| 7 | Match uses evaluator `vtable+0x38` (SendUseObject family) | **Falsified for this path** — callee chain `FUN_0059d9c0` → evaluator **vtable+0x40** |
| 8 | Return 1 means bytes left the process | **Falsified** — if `*(client+0xc78)==0`, pack still completes and returns 1 without call |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Interact / type gates | **High / Confirmed** | Blocked or spurious use |
| Character `*(client+0xe98)` | **High / Confirmed** | Wrong thiscall → wrong objectives |
| Objective store = FUN EAX | **High / Confirmed** | Mis-port sentinel (0 vs −1) |
| Wire confirms 0 on type-4 | **Tentative** | Server hint reconcile wrong |
| Return 0/1 in AL | **High** | Caller branch wrong |
| ESI=client, EAX=target | **High** static | Wrong client/target if convention broken at call site |
| Net identity vs sibling global | **Open** | Double-connection theory |

---

## 3. Cross-check against raw + bytes

```
if blockFlag(*( *(ESI+0xe04)+0xf6 )) != 0: return 0
ECX = *(ESI+0xe98)                 // character — sealed
EAX = FUN_00524520(ECX, EDI=target)
if EAX == 0 and type(*( *(target+0xa8)+0x38 )) != 4: return 0
pack TFID; opcode 0x2072
[packet+0x18] = EAX                // sealed store; type-4-only → 0
if *(ESI+0xc78) != 0: send 0x20
return 1
```

No `Client_FindObjectiveMatchingTarget`. No `client+0xd28` write. No `or eax, 0xFFFFFFFF`.

Callee `FUN_00524520` (live decompile): null target → 0; lock hash `char+0x548`; walk; `FUN_0059d9c0` match; return `*(objDef+0x10)`.

---

## 4. Surviving contract for AutoCore

```
On gated UseObject (IfInteractable):
  require interact block flag clear on *(client+0xe04)+0xf6
  character = *(client+0xe98)
  objectiveId = FindActiveObjectiveIdForInteract(character, target)  // 0 if none
  allow only if objectiveId != 0 OR cloneType == 4
  send 0x2072 size 0x20 with TFID from target+0x160
  IDObjective = objectiveId   // 0 on type-4-only; NEVER invent −1 here
  return success bool for gate pass (not "bytes on wire")
  do NOT stash client+0xd28 in this unit
  do NOT call FindObjectiveMatchingTarget (vtable+0x38 path)
Before port: confirm server treats objective 0 vs −1; capture type-4 wire.
```

---

## 5. Open questions (after residual)

1. Wire dump type-4 vs mission-match `@+0x18`.
2. Product English for block flag and type **4** class.
3. `client+0xc78` vs `g_pSectorNetConnection_INFERRED` identity.
4. Optional: dual remaining thin callers `FUN_008be900` / `FUN_00925820`.

**Closed this residual:** character ECX provenance; objective uninit theory; static 0-vs-−1 store path.

---

## 6. Verdict

Static reconstruction of the **dual residual gates before SendUseObject** (block flag + objective-or-type-4) is **sealed**. Prior “objective garbage” residual is dead. Product/wire confirmation of zero objective remains the only material send-side gap for AutoCore.

**Verdict: accept** (CF + objective fill + character) / **needs-more-evidence** (live wire objective bytes; flag/type English).
