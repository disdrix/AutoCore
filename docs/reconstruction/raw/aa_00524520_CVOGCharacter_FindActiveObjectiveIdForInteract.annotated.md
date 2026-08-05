# Annotated: FindActiveObjectiveIdForInteract (`aa_00524520`)

## Signature (byte-sealed)

```c
// this = CVOGCharacter*  (ECX; saved to EBX)
// worldObject on stack; ret 4
// returns objective id at instance+0x10, or 0
uint32_t __thiscall CVOGCharacter_FindActiveObjectiveIdForInteract(
    Character* this, Object* worldObject);
```

## Behavior

1. Null object → 0 (`ret 4`)
2. Lock active-objectives hash `char+0x548` traversal bit `+0x1d`
3. Walk chain: first `hash+0x14`, next `node+0x14`, payload `node+8`
4. Per payload: `push world; push character; ECX=objective; call FUN_0059d9c0`
5. Helper: any evaluator `vtbl+0x40(character, world)` over `[obj+0x158, obj+0x15c)`
6. On match return `*(objectiveInstance+0x10)` (first hit)
7. Unlock `hash+0x1d`; return

## Primary caller (IfInteractable `0x00930d70`)

```
ECX = *(client + 0xE98);   // character
push target;
call FindActiveObjectiveIdForInteract;
// allow if EAX != 0 OR cloneType == 4
// packet: opcode 0x2072 @ +0; IDObjective @ +0x18 = EAX  (0 on type-4 miss)
```

## Callers (xrefs)

- `Client_SendUseObject_IfInteractable` — gate + packet objective field (**High**)
- `Client_InteractClickPickTarget` — truthy OR with ForPick
- `Client_Input_PollBoundActions` (×2) — truthy → IfInteractable
- `FUN_00490070`, `FUN_00925820`, `FUN_008a81a0`, tooltip / UI

## Confidence

| Claim | Level |
|---|---|
| Returns objective id not bool | **High** |
| Hash at +0x548 active objectives | **High** |
| Match via 0059d9c0 → vtbl+0x40(char, world) | **High** (bytes) |
| IfInteractable ECX `client+0xE98` + `@+0x18` | **High** (bytes) |
| Name | **Probable–High** reconstructed |
| Other xref ECX | **Open** |
