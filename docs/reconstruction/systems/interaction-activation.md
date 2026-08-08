# System map: Interaction / activation (client)

| Field | Value |
|---|---|
| System | World-object **interact / UseObject** activation (C2S `0x2072`) + NPC interact chrome |
| Priority | **High** (#3 interaction) |
| Program | `autoassault.exe` (image base `0x400000`) |
| Primary units | `Client_SendUseObject` @ `0x00916740`; `Client_SendUseObject_IfInteractable` @ `0x00930d70` |
| Status | **active / partial** â€” entry map from fresh Ghidra decompile (2026-07-29) + dual A/B on primary send paths |
| Bit-for-bit | Deferred |
| Scope of this file | Client entry â†’ pack/send UseObject; pick/keybind producers; objective-id fill; interact icon state. Server `ObjectUseManager` is product-side (indexed only). |

---

## Scope

**In scope**

* Client paths that **select a world object** and **send C2S UseObject `0x2072`** (size `0x20`).
* Two send variants:
  * **Unconditional send** once called: `Client_SendUseObject` â€” fills `IDObjective` via `Client_FindObjectiveMatchingTarget` or **âˆ’1**.
  * **Gated send**: `Client_SendUseObject_IfInteractable` â€” block flag + objective-id match **or** clone type `4`; returns bool.
* Click/pick interact hub that distance-gates then calls those senders (`Client_InteractClickPickTarget`).
* Bound-action / key interact poll that also chooses which sender to call (`Client_Input_PollBoundActions` interact slice).
* NPC interact **icon / FX state** pass (`Client_UpdateNpcInteractIcons`) as chrome producer (not the send path).
* Client-side stash of last-use target at `client+0xd28`.
* Client distance gate `DAT_00aaa6fc` = **25.0f** before unconditional UseObject from click path.

**Out of scope (indexed only)**

* Server UseObject dispatch order (`ObjectUseManager` / mission deliver / store / facility) â€” see `docs/missionHandler.md`, `docs/topic-extractions/vendor-store-useobject.md`.
* Full mission dialog accept/claim packing (`0x206D` / `0x206E` / `0x206F`) â€” **missions-progression**.
* Skill cast / quick-bar activation â€” **skills-abilities** (adjacent bound-action poll).
* Inventory grab/drop â€” **inventory-transfer**.

---

## Known entry points

| Address | Symbol (conservative) | Role |
|--------:|------------------------|------|
| `0x00916740` | `Client_SendUseObject` | **Primary.** C2S `0x2072` size `0x20`; TFID + objective (âˆ’1 if none); stash target `client+0xd28`. |
| `0x00930d70` | `Client_SendUseObject_IfInteractable` | **Primary gated.** Same opcode/size; gates then send; returns `1`/`0`. |
| `0x009247b0` | `Client_InteractClickPickTarget` | Click/pick hub â†’ select object; may call IfInteractable and/or distance-gated SendUseObject. |
| `0x00925d60` | `Client_Input_PollBoundActions` | Bound-action poll; interact edge â†’ IfInteractable **or** SendUseObject (flag `obj+0x11c`). |
| `0x00525bd0` | `Client_FindObjectiveMatchingTarget` | Active-obj MatchTarget (`vtable+0x38`); returns **def\*** for SendUseObject `IDObjective`. |
| `0x00524520` | `FUN_00524520` â†’ proposed `CVOGCharacter_FindActiveObjectiveIdForInteract` | Walk active obj hash `char+0x548`; match via `FUN_0059d9c0` (`vtable+0x40`); returns **objective id** or `0`. Gate + id fill for IfInteractable. |
| `0x005245d0` | `FUN_005245d0` â†’ proposed `CVOGCharacter_FindActiveObjectiveIdForPick` | Sibling walker of `+0x548` using `CVOGObjective_MatchTargetEvaluators_Slot44` (`0x0059da10`, `vtable+0x44`); returns **objective id** or `0`. Pick/hover (3 xrefs). |
| `0x0091b8d0` | `Client_UpdateNpcInteractIcons` | Periodic interact-state + SpecialFX for NPCs/objects (chrome only). |
| `0x0080ff00` | `Client_RecvCompleteDynamicObjective` | S2C `0x2070`; **may** call `Client_SendUseObject` after force-complete when world target matches (missions cross-link). |

**Server (product, not client RE units):**

| Opcode | Direction | Role |
|--------|-----------|------|
| `0x2072` | C2S | UseObject â€” TFID + optional objective hint |
| `0x206D` | S2C | NPC mission dialog open (common UseObject outcome) |
| `0x206E` | C2S | Mission dialog response |
| Server range | â€” | AutoCore `NpcInteractHandler` ~**30f**; client click gate **25.0f** |

---

## Behavioral flow

### A. Unconditional send (`Client_SendUseObject`)

```
1. Caller places target object in EAX; client/controller in ECX (fastcall param_1)
2. client+0xd28 = target
3. Packet stack (0x20):
     +0x00 opcode = 0x2072
     +0x04 pad (unset / residual stack)
     +0x08..+0x17 TFID_16 from target+0x160..+0x16c
     +0x18 IDObjective =
           Client_FindObjectiveMatchingTarget( *( *(target+0xa8) + 0x34 ) )
             â†’ if def* != 0: *(def+0x10)
             â†’ else: 0xFFFFFFFF (âˆ’1)
4. if g_pSectorNetConnection_INFERRED != 0:
     vtbl+0x18 send(0xFFFFFFFF, packet, 0x20, 0)
```

### B. Gated send (`Client_SendUseObject_IfInteractable`)

```
1. Registers: EAX = target object; ESI = client (decompiler unaff_ESI)
2. Block gate: if *( *(client+0xe04) + 0xf6 ) != 0 â†’ return 0
3. character = *(client+0xe98)           // CONFIRMED bytes MOV ECX,[ESI+0xe98]
   objectiveId = FUN_00524520(character, target)  // id or 0
4. Allow if objectiveId != 0  OR  *( *(target+0xa8) + 0x38 ) == 4  (clone type 4)
   else return 0
5. Pack TFID from target+0x160..; opcode 0x2072
   // packet+0x18 = explicit MOV of EAX (FUN return):
   //   match â†’ real objective id
   //   type-4 bypass with no match â†’ 0  (NOT âˆ’1)
6. if *(client+0xc78) != 0:
     (**(**(client+0xc78))+0x18)(0xFFFFFFFF, packet, 0x20, 0)
   // else still fall through
7. return 1   // gate-pass / pack success â€” not "bytes on wire"
```

### C. Click pick hub (`Client_InteractClickPickTarget` â€” summary)

```
UI block / modal early-outs
â†’ ray / Skill_GatherTargetsInArea / Object_ResolveFromTFID pick
â†’ store selected: client slots [0x349], [0x1d6]
â†’ if FUN_005245d0(obj) or FUN_00524520(selected): Client_SendUseObject_IfInteractable()
â†’ if selected+0x11c != 0 AND distance(player, obj) <= DAT_00aaa6fc (25.0f):
      Client_SendUseObject()
â†’ type switch (3/4/0xe/0x12/0x14/0x16) for secondary selects / packets
```

### D. Bound-action interact (PollBoundActions **Activate** edge)

**Edge:** `DAT_00d1be62` (held) + `DAT_00d1be63` (edge), or `(*DAT_00d1b624)(3)`. Display name **"Activate"** (ActionMap `+0x4b9`). Modal block `param_1[0x31e]`. Dual residual sealed 2026-07-29 (`reviews/A|B_aa_00925d60_*`).

```
// 1) Exclusive early special gather (NOT UseObject)
//    FUN_0058cd60-family @ imm 20.0f (0x41a00000)
//    if TFID hit: FUN_00925580 â†’ C2S 0x2055 size 0x30; STOP

// 2) Resolve target within ~15f (key path â€” NOT click 25f)
//    prefer DAT_00d1d888 if not self and distÂ² â‰¤ DAT_00aaaca4 (225.0f = 15Â²)
//    else Skill_GatherTargetsInArea r=15.0f (0x41700000), masks (1,3)
//         town flag *(g+0xf5): second gather masks (1,7,0x14)
//    else Client_FindFirstObjectInRadius / FUN_009197a0(15.0f) â€” first-in-radius (not min-dist);
//         if null: gather mask (1,8)

// 3) Send (mutually exclusive)
if target+0x11c != 0:          // also pi[0x47] on resolved *
  Client_SendUseObject()
else if FUN_00524520(target):
  Client_SendUseObject_IfInteractable()
```

| Constant | Value | Path |
|----------|-------|------|
| Activate UseObject gather / select | **15.0f** (imm + âˆš225) | key edge |
| Activate early `0x2055` gather | **20.0f** | key edge exclusive |
| Click UseObject gate | **25.0f** (`DAT_00aaa6fc`) | pick hub only |

### E. Icon chrome (`Client_UpdateNpcInteractIcons`)

```
Throttle counter DAT_00d1f0b4 (mod 0x1e)
Walk in-scope interactive TFID list
Eval offerable / active mission interact state â†’ entry+0x10 enum
Attach/clear NDSpecialFX when state changes and object+0x4c FX slot empty
// Does NOT send 0x2072
```

---

## Call graph summary

```
Client_InteractClickPickTarget          0x009247b0
  â”œâ”€ FUN_005245d0 / FUN_00524520        (match helpers)
  â”œâ”€ Client_SendUseObject_IfInteractable 0x00930d70
  â”‚     â””â”€ FUN_00524520                 0x00524520
  â”‚           â””â”€ FUN_0059d9c0           0x0059d9c0  (eval vtable+0x40)
  â””â”€ Client_SendUseObject               0x00916740   (if +0x11c && distâ‰¤25f)
        â””â”€ Client_FindObjectiveMatchingTarget 0x00525bd0  (eval vtable+0x38)

Client_Input_PollBoundActions            0x00925d60
  â”œâ”€ Client_SendUseObject               0x00916740
  â””â”€ Client_SendUseObject_IfInteractable 0x00930d70

Client_RecvCompleteDynamicObjective     0x0080ff00
  â””â”€ (optional) Client_SendUseObject    0x00916740

Client_UpdateNpcInteractIcons           0x0091b8d0
  â””â”€ CVOGObject_EvalOfferableMissionInteractState / active-obj evaluators
     (chrome only)

â”€â”€â”€ Server (indexed) â”€â”€â”€
C2S 0x2072 â†’ ObjectUseManager.Handle
  â†’ UseItem / mission dialog / deliver / store / facility / reactions
  â†’ often S2C 0x206D dialog
```

---

## Data flow summary

| Source | Transform | Destination |
|--------|-----------|-------------|
| Target object `+0x160..+0x16c` | copy 16 B | UseObject packet TFID `@+0x08` |
| `*( *(target+0xa8)+0x34 )` | MatchTarget walk (`+0x38`) | SendUseObject `IDObjective` `@+0x18` or **âˆ’1** |
| Active objectives hash `char+0x548` via `FUN_00524520` | match `vtable+0x40` | IfInteractable gate + `@+0x18` id **or 0** |
| Clone type `*( *(target+0xa8)+0x38 )` | `== 4` | IfInteractable allow without objective match |
| `*( *(client+0xe04)+0xf6 )` | non-zero | IfInteractable hard block |
| Interact flag `obj+0x11c` | non-zero | Prefer unconditional SendUseObject (pick/poll) |
| Distance vs `DAT_00aaa6fc` | â‰¤ **25.0f** | Click path may call SendUseObject |
| Activate select distÂ² vs `DAT_00aaaca4` | â‰¤ **225.0f** (15Â²) | Poll Activate selection `DAT_00d1d888` |
| Activate gather radius imm | **15.0f** (`0x41700000`) | Poll Activate UseObject path |
| Activate early gather imm | **20.0f** (`0x41a00000`) | Poll Activate â†’ C2S **0x2055** only |
| Sector net `vtbl+0x18` | send size `0x20` | Wire C2S `0x2072` |
| Last target | store | `client+0xd28` (SendUseObject only) |

### Packet layout â€” C2S UseObject `0x2072` (size `0x20`)

| Offset | Field | SendUseObject | IfInteractable |
|-------:|-------|---------------|----------------|
| `+0x00` | opcode | `0x2072` | `0x2072` |
| `+0x04` | pad | residual | residual |
| `+0x08` | TFID_16 | `obj+0x160..` | `obj+0x160..` |
| `+0x18` | IDObjective | match id or **âˆ’1** | match id or **0** (type-4 no match) |

Server strip after opcode: pad4 + TFID + ObjectiveId (see plate / `UseObjectPacket`).

---

## State owners

| Owner | Location | Notes |
|-------|----------|-------|
| Last UseObject target | `client+0xd28` | Written by SendUseObject |
| Selected interact object | client slots used by pick (`[0x349]`, `[0x1d6]` decompiler indices) | Click hub |
| Interact block flag | `*(client+0xe04)+0xf6` | IfInteractable early-out |
| Sector connection | `client+0xc78` **or** `g_pSectorNetConnection_INFERRED` | Two send sites differ |
| Active objectives hash | `char+0x548` | Both objective matchers |
| Interact chrome enum | interact-list entry `+0x10` | UpdateNpcInteractIcons |
| Range constant | `DAT_00aaa6fc` = **25.0f** (`0x41c80000`) | Client click gate |
| Activate selectÂ² | `DAT_00aaaca4` = **225.0f** | Poll Activate max select dist (15f) |
| Activate gather | imm `0x41700000` = **15.0f** | Poll Activate UseObject gathers / `Client_FindFirstObjectInRadius` (`aa_009197a0`) |

---

## State transitions

| Event | Effect |
|-------|--------|
| Successful SendUseObject | C2S `0x2072` on wire; `client+0xd28` updated |
| Successful IfInteractable | C2S `0x2072`; returns 1; **no** `+0xd28` stash in body |
| Failed IfInteractable gates | return 0; no send |
| Icon state change | SpecialFX attach/clear; no network |
| Server accept (external) | Dialog `0x206D`, store open, use-item progress, etc. |

---

## External effects

* Sector network send (`vtbl+0x18`).
* Downstream server mission/dialog/store (not client).
* Interact SpecialFX / mission chrome (icons only).

## Dependencies

| System | Why |
|--------|-----|
| **missions-progression** | `FindObjectiveMatchingTarget`; dialog `0x206D`/`0x206E`; complete-objective optional re-UseObject |
| **skills-abilities** | `Skill_GatherTargetsInArea` in pick path; shared bound-action poll |
| **input-drive-control** | Same `PollBoundActions` / ActionMap edge machinery |
| Server ObjectUse | Authority for range (~30f), deliver, UseItem, facilities |

## Important functions

See entry table; dual-reviewed primaries:

| Unit | Stable ID | Dual A/B |
|------|-----------|----------|
| `Client_SendUseObject` | `aa_00916740` | `reviews/A|B_aa_00916740_*` |
| `Client_SendUseObject_IfInteractable` | `aa_00930d70` | `reviews/A|B_aa_00930d70_*` |
| `Client_FindObjectiveMatchingTarget` | `aa_00525bd0` | missions dual (prior) |
| `Client_InteractClickPickTarget` | `aa_009247b0` | dual A/B **2026-07-29** human refine; UseObject gate High; pick-helper residual |
| `Client_UpdateNpcInteractIcons` | `aa_0091b8d0` | dual present; chrome-only |
| `Client_FindFirstObjectInRadius` | `aa_009197a0` | dual A/B **2026-07-29**; 15f callers; first-in-radius not min-dist |

## Evidence

* Fresh Ghidra `batch_decompile` 2026-07-29: `0x00916740`, `0x00930d70`, `0x00524520`, `0x0059d9c0`, `0x009247b0`, `0x0091b8d0`
* Fresh Ghidra 2026-07-29 Activate residual: `decompile 0x00925d60` slice + `0x009197a0` + `0x00925580`; `read_memory 0x00aaaca4` â†’ `00 00 61 43` = **225.0f**
* Dual A/B `aa_009197a0` 2026-07-29: `decompile 0x009197a0`; call-site `PUSH 0x41700000` @ `00927b2a` / `00810029` / `00921338`; epilogue `RET 4`; first-in-radius CF sealed
* Ghidra `read_memory` `0x00aaa6fc` â†’ `00 00 c8 41` = **25.0f**
* Callers: SendUseObject â† PollBoundActions, InteractClickPickTarget, RecvCompleteDynamicObjective
* Callers: IfInteractable â† PollBoundActions, InteractClickPickTarget, `FUN_008be900`, `FUN_00925820`
* Prior: `docs/missionHandler.md`, `docs/agents/task-dual-ab-client-cvog-report.md`, pick dual `A_aa_009247b0`

## Confidence

| Area | Level |
|------|-------|
| Opcode `0x2072` / size `0x20` | **High** |
| TFID pack from `obj+0x160` | **High** |
| SendUseObject objective âˆ’1 fallback | **High** |
| IfInteractable gates (block / match / type 4) | **High** |
| IfInteractable `@+0x18` = `FUN_00524520` result (stack overlay) | **High** (static); wire dump still open |
| Type-4 no-match â†’ objective **0** not âˆ’1 | **High** static; **Probable** product impact |
| Distance 25.0f client click gate | **High** (constant read) |
| Server 30f range | **Probable** (product docs / plate) |
| `FUN_00524520` character ECX provenance | **Probable** (thiscall residual) |
| Full pick hub body | **Partial** (large) â€” UseObject stages High; gather taxonomy Tentative |
| Pick type-4 secondary `0x205D` | **High** (imm bits; not UseObject) |
| Poll Activate 15f / send exclusive | **High** (fresh decompile + `aaaca4` read) |
| Poll Activate early `0x2055` | **High** opcode/size; **Tentative** product role |
| Runtime capture | **Open** |

## Open questions

1. Exact identity of `g_pSectorNetConnection_INFERRED` vs `client+0xc78` â€” same connection object?
2. Why SendUseObject uses global and IfInteractable uses `client+0xc78` â€” historical dual paths or decompiler artifact?
3. Semantic difference MatchTarget `vtable+0x38` vs interact match `vtable+0x40` (`FUN_0059d9c0`) â€” when each fires.
4. Wire capture: IfInteractable type-4 path objective dword (0 vs âˆ’1 vs garbage) â€” static says **0**.
5. Full meaning of interact flag `obj+0x11c` and block flag `+0xf6`.
6. ~~`FUN_005245d0` / `CVOGObjective_MatchTargetEvaluators_Slot44` (`0x0059da10`) pairing vs `00524520` / `0059d9c0`~~ â€” **static sealed** as ForPick (+0x44) vs ForInteract (+0x40); residual = `+0x44` implementers / runtime.
7. Whether server treats objective `0` and `âˆ’1` identically on UseObject.

## Verification gaps

* Runtime UseObject round-trip (NPC deliver, type-4, use-item).
* Diff against AutoCore `ObjectUseManager` / `UseObjectPacket` reader.
* Promote `FUN_00524520` full unit + dual (name proposed; body raw exists).
* Pick-hub gather-mask taxonomy + dual-send wire residual (UseObject gate sealed).

## Dual reviews (primary senders + pick hub â€” 2026-07-29 refresh)

| Unit | Reviews | Verdict |
|------|---------|---------|
| `Client_SendUseObject` | A/B `aa_00916740` | **accept-with-gaps** |
| `Client_SendUseObject_IfInteractable` | A/B `aa_00930d70` | **accept-with-gaps** (objective residual **closed** as stack overlay; wire still open) |
| `Client_InteractClickPickTarget` | A/B `aa_009247b0` | **accept-with-gaps** (UseObject gate High; pick taxonomy residual) |
| `Client_Input_PollBoundActions` Activate residual | A/B `aa_00925d60` | **accept-with-gaps** (15f / +0x11c / exclusive 0x2055 High; masks Tentative) |

## Next recommended work

1. Full unit + dual for `FUN_00524520` / `FUN_0059d9c0` (interact match chain).
2. Wire-dump IfInteractable type-4 vs mission-match packets.
3. ~~Human-refine `Client_InteractClickPickTarget`~~ â€” done 2026-07-29 (three-rep + dual); residual gather masks / dual-send wire.
4. Cross-check AutoCore server objective-hint reconcile (`TryReconcileClientObjectiveHint`) vs client âˆ’1 / 0 / id.
5. Map `FUN_008be900` / UI callers of IfInteractable.
6. Wire-dump whether one click can emit both IfInteractable and SendUseObject.

## Mega residual duals (2026-08-05)

Nested undualed callees of dualed interact/pick/poll managers (pick-list residual, soft-cast, area-query, PollBoundActions nested).

23 dualed units from mega residual partition (MEGA-001..140). Parent merge: dual unique 2428→2567. Runtime Confirmed: none. Terminal: false.

| Address | Symbol | Notes |
|--------:|--------|-------|
| `0x004bae00` | `Host_DualCNDHash_TraverseNextObject_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00938670` | `Client_Interact_OpenCVOGStore_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x0040afb0` | `Host_LookupObjectByKey_PairTable30_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x004bc530` | `CNDHash_TraverseToNext_ListNext20` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x0091a350` | `Client_InteractWorldClick_SoftCastAlt_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00581220` | `TtPhantom_CtorFromAabbDesc_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x006c6c50` | `CVOGPhysicsUtils_AreaQueryFilterBitTest_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00409bd0` | `StdSort_RanItStride16_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00409e20` | `StdVector_ConstructN_Elem0x10_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x006ca890` | `SoftCastHitList_CoreFillAndRegister_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x004d2e50` | `CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x004d3ba0` | `CVOGObject_EvalChildDeliverObjectiveInteract_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x005ebec0` | `VOGPhysics_SphereQueryCollect_Ctor_Inferred` | mega residual dual 2026-08-05 (accept) |
| `0x006c7fa0` | `PhysicsShape_Sphere_CtorFromRadius_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00402ae0` | `StdMap_Find_Tfid_Isnil29_EaxMap_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00402c40` | `CNDHash_TraversalLock_Set_Inferred` | mega residual dual 2026-08-05 (accept) |
| `0x0040c410` | `SoftCastHitList_CtorInitBuffer_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x0040c6b0` | `CNDHash_TraverseToNext_TFID_Node0x28_RegEdiEsi_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00411e10` | `CNDHash_TraversalLock` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00411e40` | `CNDHash_TraverseToNext_RegEdiEsi` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x00489f20` | `SoftCastHitList_QuickSortRange_KeyFloat14_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x0048a060` | `SoftCastHitList_SortIfCountGt1_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |
| `0x0040d020` | `Math_Vec3Length_Inferred` | mega residual dual 2026-08-05 (accept-with-gaps) |


