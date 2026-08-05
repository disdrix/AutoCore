# Annotated low-level: FUN_005ccff0 → CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_005ccff0` |
| VA | `0x005ccff0`–`0x005cd220` |
| System | CVOGHB AI engage target select |
| Date | 2026-07-29 (W29-L OWN dual) |

## Machine-level notes

- Prologue: `83 EC 18` / push ebx,ebp,esi,edi / `8B F9` (EDI = this HBAI).
- Owner: `[this+0x64]`; TFID copy from `owner+0x228` (16 B stack local).
- Resolve manager rebuild matches sealed `004c3c80` pattern (`+0xA8` / `+0xE4E8`) before `Object_ResolveFromTFID` @ `0x004bb950`.
- All exits: `ADD ESP,0x18; RET` (plain ret — **0** stack formals).
- `Object_SetSelectedTarget` sealed arity **1** stack formal (W prior dual); decompiler `unaff_EDI` residual discarded.
- Engage caller: `CVOGHBAICreatureBase_OnHeartBeat` when no target (`state+0xa0==0`) **or** owner mode `+0x278==1`.

## Control-flow summary

1. Resolve owner TFID.
2. Miss → `Object_SetMode278_SelectFromTFID228_Inferred(owner, 0)`.
3. Hit with candidate `resolved+0xA0` + owner `vtbl+0x298` + candidate `vtbl+0x1c8` → SetSelectedTarget.
4. Else optional `FUN_004c8970` early-out via owner `+0xA4`/`vtbl+0x214`.
5. Else locked-list walk on resolved `vtbl+0x19c`→`+0xB4`; type 2 → `CVOGHBLinkedDeath`; partner promote.

## Open questions

- Product English for mode `+0x278`, vtbl `+0x298` / `+0x1c8` / `+0x214` / `+0x19c`.
- Product name / role of `FUN_004c8970`.
- Runtime / differential.
