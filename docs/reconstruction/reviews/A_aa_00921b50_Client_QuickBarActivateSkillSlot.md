# Review A (reconstruction fidelity): `aa_00921b50` Client_QuickBarActivateSkillSlot

| Field | Value |
|---|---|
| **Stable ID** | `aa_00921b50` |
| **VA** | `0x00921b50` |
| **Canonical name** | `Client_QuickBarActivateSkillSlot` |
| **Review date** | `2026-07-29` (dual residual strengthen; supersedes thin 2026-07-23 wave3 A/B scaffold) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw) |
| **Counterpart** | `reviews/B_aa_00921b50_Client_QuickBarActivateSkillSlot.md` |
| **System tag** | `skills-abilities` / skills-combat |
| **Dual status** | **Present and strengthened** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Activate by **visible skill-list index** `nSlotIndex` (not the persisted 0–99 quick-bar skill-id table):

1. Resolve local character via `DAT_00d1b6d8` dual-base link `+0xa4` → vfunc `+0x1d8`.
2. Seed 16B resolve input from character interior `+0x164..+0x170`; override from selection object `+0xa4 → +0x160..+0x16c` when present.
3. Traverse skill list at entity `+0x74` under lock byte `list+0x1d`; count only entries with `(skill+0x615 & 1) == 0` until counter equals `nSlotIndex`.
4. If skill found and `Skill_LocalCastValidate(entity, 0, pSkill, 0) == 0`:
   - skillId = `skill+0x5fc`
   - optimistic cast-again HB when world `+0x7e == 0` and `skill+0x61c == 0` (Clear always runs when `+0x7e==0`)
   - charge FX via entity vfunc `+0x238` when `skill+0x14 != 0`
   - build C2S **0x2030** size **0x28**; send on sector connection vtbl `+0x18`
   - optional UI refresh `FUN_0089ff80` when `DAT_00d1b8f0` gate passes

**Does not** call `Client_RequestCastSkill` — parallel packer of the same opcode.

**Calling convention:** `char nSlotIndex` stack formal (MSVC default). Callers pass **literals** `0` / `1`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00921b50_Client_QuickBarActivateSkillSlot.md` |
| Annotated | `docs/reconstruction/raw/aa_00921b50_Client_QuickBarActivateSkillSlot.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_QuickBarActivateSkillSlot.cpp` |
| Function record | `docs/reconstruction/functions/aa_00921b50_Client_QuickBarActivateSkillSlot.md` |
| Prior dual (thin) | A/B wave3 2026-07-23 + `aa_00921b50_reconstruction_review.md` / `_skeptical_review.md` |
| Sibling packer | `aa_00941590` `Client_RequestCastSkill` (dual residual sealed 2026-07-29) |
| Validate | `aa_0051a790` `Skill_LocalCastValidate` |
| Resolve | `aa_0093b3a0` `Client_Skill_ResolveCastTarget` |
| Dispatcher | `aa_009436c0` `Client_QuickBar_ActivateSlot` |
| Topic / wire | `docs/topic-extractions/skill-cast.md`; `Documentation/PACKET STRUCTURES.md` `SMSG_Sector_RequestCastSkill` Size=0x28 |
| Live Ghidra this pass | `decompile_function 0x00921b50`; `get_function_callers`; `get_xrefs_to`; callees list |

**Not performed:** Launcher, runtime CE capture, bit-exact / binary diff, `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| C2S opcode `0x2030`, send size `0x28` | **High / Confirmed** | imm store + send arg; matches PACKET STRUCTURES Size=0x28 Id=5659 |
| Packet `+0x18` = `skill+0x5fc` | **High** | explicit `iStack_20 = pSkill` after load from `+0x5fc` |
| Packet `+0x08` TFID16 from `Client_Skill_ResolveCastTarget` | **High** | four dwords copied from resolve return |
| Packet `+0x1C` aim XYZ intentional fill | **Open / Medium plate** | zeros then overwrite from **never-written** `uStack_60/5c/58` — decomp stack hazard |
| Skill list head entity `+0x74`; lock `+0x1d` | **High** | raw lock assert strings |
| Skip count when `skill+0x615 & 1` | **High** | CF; product meaning of bit0 still Probable (“hidden”) |
| `nSlotIndex` = Nth **visible** skill in list | **High** | counter only advances on non-bit0 entries |
| `nSlotIndex` ≠ persisted QB skill-id slot 0–99 | **High** | no read of client `+0x3220` type table; contrast ActivateSlot type-1 |
| Callers: ActivateSlot on-foot 0/1; DriveControlTick 0/1 | **High** | xrefs `00943725`, `0094374a`, `009234e2`, `00923546` |
| `Skill_LocalCastValidate == 0` gate | **High** | silent return on fail (no FormatFailure toast here) |
| Validate 3rd arg is skill **pointer** (not `char`) | **High** | sealed by LocalCastValidate dual; decomp `(char)` is type artifact |
| HB: world interior `+0xa8→+0x7e==0` then Clear; Start only if `skill+0x61c==0` | **High** | comma-operator CF |
| Charge FX when `skill+0x14 != 0` via vfunc `+0x238(3, skillId, rankSum, charge, 0…)` | **High** | rankSum = `+0x5f6 + +0x174` |
| Sector send `conn→vtbl+0x18(-1, buf, 0x28, 0)` | **High** | not `Client_SendSectorPacket` |
| `g_pSectorNetConnection_INFERRED` product name | **INFERRED** | role sealed as sector net object |
| No invalid-TFID abort before send | **High** | contrast RequestCast which aborts on invalid |
| Clean CF ≡ raw re-decompile 2026-07-29 | **High** | live body matches 2026-07-23 capture |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Character resolve via `DAT_00d1b6d8` + `+0xa4` + vfunc `0x1d8` | **Yes** |
| Seed pos/TFID from self; override selection `+0xa4` | **Yes** |
| Traversal lock set / clear around walk | **Yes** |
| Visible-slot counter vs `nSlotIndex`; skip `+0x615&1` | **Yes** |
| Node walk: list `+0x14` next; payload at node `+0x8` | **Yes** |
| LocalCastValidate gate | **Yes** |
| ClearActiveCast + optional StartCastAgainHeartbeat | **Yes** |
| Charge FX vfunc `+0x238` | **Yes** |
| Pack `0x2030` + skillId + resolve TFID + aim region | **Yes** |
| Net send size `0x28` | **Yes** |
| Optional `FUN_0089ff80` | **Yes** |
| No invent `Client_RequestCastSkill` call | **Yes** |

### 4.1 Caller map (sealed this pass)

| Caller | Site | Arg |
|---|---|---|
| `Client_QuickBar_ActivateSlot` `0x009436c0` | `0x00943725` | `'\0'` when on-foot flag `entity+0x6b9` and slot0 |
| same | `0x0094374a` | `'\x01'` when on-foot and slot1 |
| `Client_Input_DriveControlTick` `0x009223b0` | `0x009234e2` | `'\0'` under drive/host gates |
| same | `0x00923546` | `'\x01'` when `DAT_00d1b6d8+0x6b9` |

Standard QB **type-1** path uses `Client_CastSkillFromQuickBarSlot(skillId)` → `Client_RequestCastSkill` instead — **not** this unit.

### 4.2 Packet layout (logical @ send)

| Off | Field | Source here |
|---:|---|---|
| +0x00 | `0x2030` | imm |
| +0x04 | pad | unset |
| +0x08 | target TFID 16B | resolve out |
| +0x18 | `lSkillID` | `skill+0x5fc` |
| +0x1C | aim `Vector3` | stack `uStack_60/5c/58` after zero of `uStack_1c/18/14` — **not sealed** |

Matches `SMSG_Sector_RequestCastSkill` / WI-SKL-001 field map (client→server same layout).

### 4.3 vs `Client_RequestCastSkill` (same opcode, different path)

| Dimension | This unit | RequestCast |
|---|---|---|
| Skill select | Nth visible list entry | lookup by skillId `vtbl+0x234` |
| Fail UX | silent | FormatFailure + toast |
| Invalid TFID | still sends | aborts send |
| Send API | conn vtbl `+0x18` | `Client_SendSectorPacket` |
| Aim | stack residual | formal `pAimPos` |
| Post-send tip `0x23` | no | yes |

---

## 5. Gaps (honest)

1. Aim XYZ true source / whether `uStack_60` aliases resolve out (decomp hazard).
2. Product name for `skill+0x615` bit0 (hidden/passive filter — CF sealed).
3. Exact skill-list container type at entity `+0x74` (hash/list with lock `+0x1d`).
4. `g_pSectorNetConnection_INFERRED` / `DAT_00d1b8f0` product symbols.
5. `unaff_EDI` 4th HB arg — decomp phantom (sibling RequestCast sealed as thiscall + charge at `+0x14`).
6. Runtime / CE hotbar / drive-control capture; bit-exact.

**Verdict:** **accept-with-gaps** — dual quality sealed for CF, callers, slot semantics, 0x2030 pack/send contrast; package not complete.
