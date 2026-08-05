# Function record: CVOGCharacter_FindActiveObjectiveIdForInteract

| Field | Value |
|---|---|
| **Stable ID** | `aa_00524520` |
| **Canonical name** | `CVOGCharacter_FindActiveObjectiveIdForInteract` |
| **Prior** | `FUN_00524520`; false alias `Named_VOG_DEBUG_STOP` |
| **Address** | `0x00524520` |
| **System** | interaction-activation |
| **Signature** | `uint32_t __thiscall (Character* this /*ECX*/, Object* world /*stack*/)`; **`ret 4`** |
| **Status** | **Human-refined** — dual A/B residual refresh 2026-07-29 (byte-level +0x40 walker) |
| **Runtime** | Open |
| **Verdict** | accept-with-gaps |

## Purpose

Walk active objectives on the character (`this+0x548`) and return the **first** matching objective’s id (`instance+0x10`), or **0**. Match = any evaluator on the objective with **`vtable+0x40(character, world)`** via helper `FUN_0059d9c0`.

Primary product use: gate + fill C2S UseObject `0x2072` **`IDObjective @+0x18`** in `Client_SendUseObject_IfInteractable` (not a pure bool; type-4 miss wires **0**, not −1).

## Sealed contract (bytes 2026-07-29)

```
// walker
if (!world) return 0;
lock(ch->activeObjHash + 0x1d);
for (node = first(hash+0x14); node; node = node+0x14) {
  obj = *(node + 8);
  if (!obj) break;
  // push world; push ch; ECX = obj
  if (MatchTargetEvaluators_Slot40(obj, ch, world)) {
    id = *(obj + 0x10);
    unlock; return id;
  }
}
unlock; return 0;

// helper 0x0059d9c0 (sole caller = this)
// ECX=objective; stack=(character, world); ret 8
// for eval in [obj+0x158, obj+0x15c):
//   if eval->vtbl[+0x40](character, world) return 1
// return 0

// IfInteractable primary:
//   ECX = *(client + 0xE98);  push target;  call this
//   packet+0x18 = EAX  (mov [esp+0x1c], eax with opcode at [esp+4])
```

## Related

| Kind | Path |
|------|------|
| Raw / annotated | `raw/aa_00524520_*` |
| Clean | `reconstructed-exact/CVOGCharacter_FindActiveObjectiveIdForInteract.cpp` |
| Dual A | `reviews/A_aa_00524520_CVOGCharacter_FindActiveObjectiveIdForInteract.md` |
| Dual B | `reviews/B_aa_00524520_CVOGCharacter_FindActiveObjectiveIdForInteract.md` |
| Helper | `aa_0059d9c0` / `0x0059d9c0` MatchTargetEvaluators (**+0x40**) |
| Sibling | `aa_005245d0` ForPick → helper **+0x44** |
| Contrast | `aa_00525bd0` FindObjectiveMatchingTarget (**+0x38**, returns def\*) |
| Caller | `Client_SendUseObject_IfInteractable` `0x00930d70` |
| System | `systems/interaction-activation.md` |

## Confidence (summary)

| Area | Level |
|------|-------|
| Body walk / lock / first id | **High** |
| Helper +0x40 (char, world) | **High** |
| IfInteractable ECX `client+0xE98` + packet `@+0x18` | **High** |
| Name | **Probable–High** |
| Other xref ECX / eval implementers / runtime | **Open** |

## Gaps

1. Character ECX provenance at non-primary xrefs (9 remaining).
2. Which objective requirement types implement `vtable+0x40`.
3. Runtime multi-active first-wins order stability.
4. Product type name for `client+0xE98`.
