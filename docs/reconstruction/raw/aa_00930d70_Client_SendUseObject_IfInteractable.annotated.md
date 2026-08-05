# Annotated low-level: Client_SendUseObject_IfInteractable

| Field | Value |
|---|---|
| Stable ID | `aa_00930d70` |
| VA | `0x00930d70` |
| System | interaction-activation |
| Date | 2026-07-29 (dual residual strengthen) |

## Machine-level notes

- Source: raw capture for `aa_00930d70` + Ghidra decompile ≡ raw body + **`read_memory` 160 bytes** residual 2026-07-29.
- **Register convention:** `EAX` = target object; `ESI` = client (not formal args).
- **Character thiscall sealed:** before `FUN_00524520`, body does `MOV ECX,[ESI+0xe98]` then `PUSH EDI` (target). Residual “character ECX provenance” **closed**.
- **Critical objective fill (bytes, not decompiler alias):** after gates, pack path does `MOV [ESP+0x1c],EAX` where packet base is `ESP+4` → field **`+0x18`**. Therefore:
  - match path → wire objective = returned id
  - type-4 allow with `FUN_00524520 == 0` → wire objective = **0** (not −1)
  - Prior dual residual “objective field unset / garbage” is **incorrect**; residual is **semantic difference from SendUseObject (−1)**.
- `FUN_00524520` is **not** a boolean “isInteractable” helper: walks `char+0x548`, match `FUN_0059d9c0` (evaluator **vtable+0x40**), returns **objective id** (`def+0x10`) or 0. Non-zero is truthy gate **and** wire value.
- Block flag: `*( *(ESI+0xe04) + 0xf6 )` must be `'\0'`.
- Type allow: `*( *(target+0xa8) + 0x38 ) == 4` (clone class / type field).
- Net send uses `*(ESI+0xc78)` not sibling global; if null, still **return 1** after pack.
- **No** `client+0xd28` stash in this body.
- Pad dword at packet `+0x04` never written.

## Pseudocode (annotated)

```c
/* Alt UseObject path: C2S 0x2072 size 0x20; TFID from obj+0x160;
   gated by block flag + (FUN_00524520 objective id OR clone type==4).
   Packet+0x18 = explicit store of FUN return (EAX). */

undefined4 Client_SendUseObject_IfInteractable(void)
{
  int target;     /* EAX */
  int client;     /* ESI */
  uint32_t packet[8]; /* 0x20 bytes: [0]=opcode … [6]=IDObjective */
  int objectiveId;

  if (*(char *)(*(int *)(client + 0xe04) + 0xf6) != '\0') {
    return 0;                                    /* interact blocked */
  }

  /* thiscall: ECX = *(client+0xe98) character*  [CONFIRMED bytes] */
  objectiveId = FUN_00524520(*(int *)(client + 0xe98), target);
  if ((objectiveId == 0) &&
      (*(int *)(*(int *)(target + 0xa8) + 0x38) != 4)) {
    return 0;                                    /* no match and not type 4 */
  }

  packet[0] = 0x2072;
  /* packet[1] pad untouched */
  packet[2] = *(uint32_t *)(target + 0x160);
  packet[3] = *(uint32_t *)(target + 0x164);
  packet[4] = *(uint32_t *)(target + 0x168);
  packet[5] = *(uint32_t *)(target + 0x16c);
  packet[6] = (uint32_t)objectiveId;            /* +0x18; type-4-only → 0 */

  if (*(int *)(client + 0xc78) != 0) {
    (**(code **)(**(int **)(client + 0xc78) + 0x18))
      (0xffffffff, packet, 0x20, 0);
  }
  return 1;                                      /* even if net was null */
}
```

## Open questions

- Server treatment of objective **0** vs **−1** (static client path sealed).
- Semantic name for block flag at `*(client+0xe04)+0xf6`.
- Whether type **4** is “reaction / interact prop” class (Probable from pick switch case 4).
- `client+0xc78` vs sibling net global identity.
