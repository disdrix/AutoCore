# Annotated low-level: Client_InteractClickPickTarget

| Field | Value |
|---|---|
| Stable ID | `aa_009247b0` |
| VA | `0x009247b0` |
| System | `interaction-activation` |
| Date | `2026-07-29` (human stage labels; body ≡ raw 2026-07-23 / live decompile) |
| Clean | `reconstructed-exact/Client_InteractClickPickTarget.cpp` |
| Dual | `reviews/A\|B_aa_009247b0_Client_InteractClickPickTarget.md` |
| Chain | `reviews/CHAIN_2026-07-29_interaction_useobject.md` |

## Machine-level notes

- Sole caller: `FUN_009251d0` @ `0x009251d0` (two sites: soft `param_3=0` / commit `param_3=1`).
- `unaff_EBX` = client/input controller residual (select slots `[0x349]`=`+0xd24`, `[0x1d6]`=`+0x758`).
- `param_2` packed screen coords: lo16 = X, hi16 = Y.
- `param_4` low char: `0` enables self/vehicle filter out.
- Distance constants (read_memory 2026-07-29):
  - `DAT_00aaa6fc` = **25.0f** — UseObject click gate + gather cap A
  - `DAT_00a110d8` = **10.0f** — gather scale soft path A
  - `DAT_00aaa688` = **5.0f** — gather scale soft path A2
  - `DAT_00a1109c` = **40.0f** — gather cap path B
  - `_DAT_00aaacbc` ≈ **0.015f** — post-`FUN_0040d020` scale
- UseObject producers in this body only:
  1. `Client_SendUseObject_IfInteractable` after objective matchers
  2. `Client_SendUseObject` after `obj+0x11c` && dist ≤ 25f
- Case type **4** secondary send is **QuestItemPickup `0x205D`** size `0x10` (not UseObject).

## Stage map

| Stage | Label | Lines (raw) | Summary |
|------:|-------|-------------|---------|
| 0 | Early-out | clear `[0x349]`; `DAT_00d1b6d8+0x4f1` or vtbl`+0x3d8` fail → 0 | UI/modal block |
| 1 | Special `DAT_00d1a8da` | camera helper → `FUN_0093e120` select only | No UseObject |
| 2 | Primary pick | `FUN_00490070` + empty TFID seed | May return object* |
| 3a | Soft ray+gather | only if `param_3==0` and pick null | ray 400; gather masks 1,3 then 1,5 |
| 3b | Path B gather | still null | gather mask 1,2; radius×25 cap 40 |
| 4 | Self/vehicle filter | if `(char)param_4==0` | return 1 without select |
| 5 | Store + IfInteractable | slots; `005245d0` \| `00524520` | **Gated UseObject** |
| 6 | Alt mode `DAT_00d1bdfa` | vtbl`+0x380` | Early return |
| 7 | UseObject gate | `+0x11c` && dist≤25f | **Unconditional UseObject** |
| 8 | Clone type switch | types 3/4/0xe/0x12/0x14/0x16 | type4 = `0x205D` |
| 9 | Vehicle flag / commit | `FUN_004f3640`; `+0xa32` | Always return 1 |

## UseObject chain (this unit → wire)

```
Client_InteractClickPickTarget
  ├─ [5] if FUN_005245d0(obj) || FUN_00524520(obj):
  │       Client_SendUseObject_IfInteractable()   // 0x00930d70 → C2S 0x2072
  │         (gates: block flag; id!=0 OR clone type 4; objective id or 0)
  └─ [7] if obj+0x11c != 0 && ||obj.pos - player.pos|| <= 25.0f:
          Client_SendUseObject()                  // 0x00916740 → C2S 0x2072
            (objective match def+0x10 or −1; stash client+0xd28)
```

Both send paths are **callers-owned gates** for range/interact; the send bodies do not re-check 25f.

## Pseudocode (annotated copy of raw)

```c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Click/interact target pick. When selected object has flag at +0x11c and distance <= DAT_00aaa6fc
   (25.0f), calls Client_SendUseObject (C2S 0x2072). Server should range-gate UseObject (~25-30f). */

undefined4
Client_InteractClickPickTarget
          (undefined4 param_1,undefined4 param_2,char param_3,undefined4 param_4)

{
  /* locals omitted — same as raw */

  /* Stage 0 */
  unaff_EBX[0x349] = 0;
  if ((*(char *)(DAT_00d1b6d8 + 0x4f1) != '\0') ||
     (cVar3 = (**(code **)(*unaff_EBX + 0x3d8))(), cVar3 == '\0')) {
    return 0;
  }
  iStack_d4 = (int)(short)((uint)param_2 >> 0x10); /* screen Y */
  unaff_EBX[0x156] = 0;
  uStack_12 = 0xff; uStack_13 = 0xff; uStack_14 = 0xff; uStack_11 = 0xff;

  /* Stage 1 — special mode: select only */
  if (DAT_00d1a8da != '\0') {
    /* camera pick path → FUN_0093e120(object); return 1 — no UseObject */
    ...
  }

  /* Stage 2 — FUN_00490070 primary */
  piVar4 = (int *)FUN_00490070(&fStack_10c,auStack_68,param_4);
  /* seed TFID from DAT_00a158b8.. invalid sentinel */

  /* Stage 3 — ray / gather soft resolution when piVar4 still null */
  if ((piVar4 == (int *)0x0) && (*(char *)(DAT_00d1b644 + 0xf5) == '\0')) {
    if (param_3 == '\0') {
      /* screen→world FUN_0075c340; ray FUN_004cff70(...,400) */
      /* dist scale * ~0.015; radius = scale*10 capped 25; GatherTargets mask 1,3 */
      /* empty → radius scale*5 cap 25; FUN_0058cd60 mask 1,5; ResolveFromTFID */
      /* hit type 0x12 may become pick only if FUN_0040b1b0 */
    }
    if (piVar4 == (int *)0x0) {
      /* path B: radius = scale*25 cap 40; GatherTargets mask 1,2; ResolveFromTFID */
    }
  }

LAB_00924d29:
  /* Stage 4 — filter self / vehicle when (char)param_4 == 0 */
  if ((char)param_4 == '\0') {
    if (piVar4 == playerBody) return 1;
    if (piVar4 == vehicleBody) return 1;
  }

  /* Stage 5 — store selection; gated UseObject */
  unaff_EBX[0x349] = (int)piVar4;
  unaff_EBX[0x1d6] = (int)piVar4;
  unaff_EBX[0x15a] = 0;
  if (piVar4 != (int *)0x0) {
    if (FUN_005245d0(piVar4) || FUN_00524520(unaff_EBX[0x1d6])) {
      Client_SendUseObject_IfInteractable(); /* C2S 0x2072 gated */
    }
    FUN_0093e120(unaff_EBX[0x1d6]);
  }

  /* Stage 6 — alternate handler */
  if (DAT_00d1bdfa != '\0') {
    DAT_00d1d867 = 1;
    return (**(code **)(*unaff_EBX + 0x380))(param_1,param_2);
  }

  if (unaff_EBX[0x1d6] == 0) goto default_flag;
  if (DAT_00d1d900 != -1) { FUN_00941ac0(&DAT_00d1a640); goto after_switch; }

  /* Stage 7 — unconditional UseObject gate */
  if (*(int *)(selected + 0x11c) != 0) {
    /* Euclidean(obj.pos - player.pos) via vtbl+0x1a0 */
    if (dist <= DAT_00aaa6fc /* 25.0f */) {
      Client_SendUseObject(); /* C2S 0x2072 */
    }
  }

  /* Stage 8 — clone type @ *(obj+0xa8)+0x38 */
  switch (cloneType) {
  case 3: break;
  case 4:
    /* packet opcode bits 0x205d (QuestItemPickup), size 0x10 */
    Client_SendSectorPacket(&DAT_00d1a840,0x10,&packet);
    break;
  case 0xe: case 0x12: case 0x14:
    /* optional clear select via FUN_0093e120(0) */
    ...
  case 0x16:
    FUN_00938670(...);
  default:
default_flag:
    if (param_3) unaff_EBX[+0xa32] = 1;
  }

after_switch:
  /* Stage 9 */
  if (vehicle present && flags) FUN_004f3640(0,1);
  if (param_3) unaff_EBX[+0xa32] = 1;
  return 1;
}
```

## Callers / callees

| Dir | Address | Name | Role |
|-----|---------|------|------|
| Caller | `0x009251d0` | `FUN_009251d0` | Sole xref; soft/commit |
| Callee | `0x00930d70` | `Client_SendUseObject_IfInteractable` | Gated 0x2072 |
| Callee | `0x00916740` | `Client_SendUseObject` | Uncond 0x2072 |
| Callee | `0x00524520` | `CVOGCharacter_FindActiveObjectiveIdForInteract` | id / gate |
| Callee | `0x005245d0` | sibling matcher (`vtable+0x44`) | id / gate |
| Callee | `0x0058d330` | `Skill_GatherTargetsInArea` | soft pick |
| Callee | `0x004bb950` | `Object_ResolveFromTFID` | TFID → object* |
| Callee | `0x00807460` | `Client_SendSectorPacket` | type-4 `0x205D` |

## Confidence (annotated claims)

| Claim | Level |
|---|---|
| Stage structure / UseObject dual paths | **High** |
| 25.0f gate constant | **High** (memory) |
| Type-4 packet = `0x205D` | **High** (bits match QuestItemPickup enum) |
| Soft vs commit `param_3` | **Probable** (caller 0/1) |
| Full product meaning of gather mask args | **Tentative** |
| Every FUN_* pick helper product name | **Open** |
