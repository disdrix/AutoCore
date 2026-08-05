# Function record: Client_SendUseObject_IfInteractable

| Field | Value |
|---|---|
| **Stable ID** | `aa_00930d70` |
| **Canonical name** | `Client_SendUseObject_IfInteractable` |
| **Address** | `0x00930d70` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | interaction-activation |
| **Completion status** | **Human-refined clean** + dual residual **sealed** (gates, `client+0xe98` character, explicit `IDObjective` store) 2026-07-29; runtime wire open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

**Gated** C2S UseObject path: send `0x2072` size `0x20` only when (a) interact-block flag is clear, and (b) either `FUN_00524520` returns a non-zero **objective id**, or the target’s clone type is **4**. Returns **1** if the pack path is taken (even if net is null), else **0**.

Does **not** call `Client_FindObjectiveMatchingTarget`. Packet `+0x18` is an **explicit store of EAX** after `FUN_00524520` (`MOV [ESP+0x1c],EAX`) — match → real id; type-4 with no match → **0** (not −1). Does **not** stash `client+0xd28`.

Sibling unconditional sender: `Client_SendUseObject` (`aa_00916740`) — −1 fallback, `+0xd28` stash, different matcher / net expression.

## Signature (decompiler + bytes)

```c
// Custom register convention (no formal args in decompile):
//   EAX = target world object*
//   ESI = client/controller*
//   FUN_00524520 thiscall: ECX = *(client + 0xe98)  // character*  [CONFIRMED bytes]
// returns 0/1 in AL
undefined4 Client_SendUseObject_IfInteractable(void);
```

## Behavioral notes

1. **Block gate:** `*( *(client + 0xe04) + 0xf6 ) == 0` required; else return 0.
2. **Character:** `ECX = *(client + 0xe98)` then `objectiveId = FUN_00524520(character, target)` — walks active objectives (`char+0x548`), match via `FUN_0059d9c0` (evaluator `vtable+0x40`); returns objective id (`def+0x10`) or 0.
3. **Allow if** `objectiveId != 0` **OR** `*( *(target + 0xa8) + 0x38 ) == 4`.
4. Pack TFID from `target+0x160..+0x16c`; opcode `0x2072` at packet `+0x00`.
5. **Packet `+0x18`:** `MOV [packet+0x18], EAX` (FUN return). Type-4-only path transmits **0**. Pad at `+0x04` never written.
6. If `*(client + 0xc78) != 0`: `vtbl+0x18` send size `0x20`; if null, still return 1 after pack.
7. Fail paths: return 0 (`XOR AL,AL`).

## Asm anchors (from `read_memory`, 2026-07-29)

| Site | Effect |
|---|---|
| `MOV ECX,[ESI+0xe98]` + `PUSH EDI` + `CALL 0x00524520` | Character thiscall sealed |
| `TEST EAX` / `CMP [ECX+0x38],4` | Dual residual gate |
| `MOV DWORD PTR [ESP+4],0x2072` | Opcode |
| `MOV [ESP+0x1c],EAX` | IDObjective = FUN return |
| `CMP [ESI+0xc78],0` then optional vtbl`+0x18` | Conditional send |
| `MOV AL,1` / `XOR AL,AL` | Return bool |

## Callers / callees

| Direction | Address | Name |
|-----------|---------|------|
| Caller | `0x00925d60` | `Client_Input_PollBoundActions` |
| Caller | `0x009247b0` | `Client_InteractClickPickTarget` |
| Caller | `0x008be900` | `FUN_008be900` |
| Caller | `0x00925820` | `FUN_00925820` |
| Callee | `0x00524520` | `CVOGCharacter_FindActiveObjectiveIdForInteract` (`FUN_00524520`) |
| Nested | `0x0059d9c0` | Match helper (evaluator `vtable+0x40`) |

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00930d70_Client_SendUseObject_IfInteractable.md` |
| Annotated | `docs/reconstruction/raw/aa_00930d70_Client_SendUseObject_IfInteractable.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_SendUseObject_IfInteractable.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_00930d70_Client_SendUseObject_IfInteractable.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_00930d70_Client_SendUseObject_IfInteractable.md` |
| Scratch | `tmp/a_00930d70.md` |
| System map | `docs/reconstruction/systems/interaction-activation.md` |
| Sibling | `aa_00916740` Client_SendUseObject |
| Callee record | `aa_00524520` FindActiveObjectiveIdForInteract |

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Gates + type 4 | **High / Confirmed** | explicit CF + bytes |
| Opcode / size | **High** | literals |
| TFID pack | **High** | dword copies from `+0x160` |
| Character `*(client+0xe98)` | **High / Confirmed** | `MOV ECX,[ESI+0xe98]` |
| `@+0x18` = FUN EAX store | **High / Confirmed** | `MOV [ESP+0x1c],EAX` |
| Type-4 → objective 0 not −1 | **High / Confirmed** static | store path; no −1 write |
| ESI=client, EAX=target | **High** static | body + call convention |
| Return 1 with null net | **High** | JZ skip_send then AL=1 |
| Wire confirmation of 0 vs −1 | **Open** | need capture |
| Block-flag / type-4 English | **Open / Probable** | product names |
| Overall (static kernel) | **High / Sealed** | runtime open |

## Open questions

- Live wire dump of type-4 path objective dword.
- Product English for `*(client+0xe04)+0xf6` and clone type **4**.
- Identity of `client+0xc78` vs sibling net global.
- Thin callers `FUN_008be900` / `FUN_00925820` dual depth.
