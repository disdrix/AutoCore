# Function record: Client_QuickBarActivateSkillSlot

| Field | Value |
|---|---|
| **Stable ID** | `aa_00921b50` |
| **Canonical name** | `Client_QuickBarActivateSkillSlot` |
| **Address** | `0x00921b50` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **Human-refined + dual residual (2026-07-29)** — CF, callers 0/1, visible-list slot, 0x2030 pack/send sealed; aim residual + runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

---

## 1. Summary

Activate the **Nth non-hidden skill** in the character skill list (`entity+0x74`), not a persisted quick-bar skill-id slot. Validates with `Skill_LocalCastValidate`, optional cast-again HB, builds **C2S 0x2030** size `0x28` (`skill+0x5fc` at `+0x18`, TFID from `Client_Skill_ResolveCastTarget`), sends via sector connection `vtbl+0x18`.

Callers (only observed): on-foot quick-bar slots **0/1** via `Client_QuickBar_ActivateSlot`, and matching DriveControlTick secondary paths — always with literal indices `0` or `1`.

Parallel packer to `Client_RequestCastSkill` (does **not** call it).

---

## 2. Signature

```c
void Client_QuickBarActivateSkillSlot(char nSlotIndex);
// nSlotIndex = visible skill-list index (skip skill+0x615 bit0); callers use 0 or 1
```

---

## 3. Behavior outline

1. Resolve player/character from `DAT_00d1b6d8` link `+0xa4` → `vtbl+0x1d8`
2. Seed 16B from character interior `+0x164..+0x170`; override if selection `+0xa4` → `+0x160..`
3. Lock skill-list `+0x1d`, walk nodes via `FUN_00411900` / node `+0x14` / payload `+0x8`
4. Count only skills without `+0x615 & 1`; break when count == `nSlotIndex`
5. Unlock; if skill found and `LocalCastValidate == 0`:
   - `skillId = skill+0x5fc`
   - if world `+0xa8→+0x7e == 0`: `ClearActiveCast(skillId)`; if `skill+0x61c == 0` → `StartCastAgainHeartbeat`
   - if `skill+0x14 != 0`: charge FX entity `vtbl+0x238`
   - pack `0x2030` + resolve TFID + aim region → send `0x28` on `g_pSectorNetConnection_INFERRED`
   - optional `FUN_0089ff80` if `DAT_00d1b8f0` UI gate

---

## 4. Packet (same 0x2030 / WI-SKL-001)

| Off | Field | Source |
|---:|---|---|
| +0x00 | opcode `0x2030` | imm |
| +0x04 | pad | unset |
| +0x08 | target TFID 16B | `Client_Skill_ResolveCastTarget` |
| +0x18 | skill id | `skill+0x5fc` (**explicit**) |
| +0x1C | aim XYZ | stack residual — **not sealed** |

---

## 5. Related artifacts

| Kind | Path |
|---|---|
| Raw / annotated | `raw/aa_00921b50_Client_QuickBarActivateSkillSlot.*` |
| Clean | `reconstructed-exact/Client_QuickBarActivateSkillSlot.cpp` |
| Dual A/B | `reviews/A_aa_00921b50_*`, `B_aa_00921b50_*` |
| Prior dual | `reviews/aa_00921b50_reconstruction_review.md`, `_skeptical_review.md` |
| Scratch | `tmp/a_00921b50.md` |
| Topic | `docs/topic-extractions/skill-cast.md` |
| Callers | `aa_009436c0` ActivateSlot; `Client_Input_DriveControlTick` `0x009223b0` |
| Siblings | `aa_00941590` RequestCast; `aa_009418e0` CastFromQB; `aa_0093b3a0` Resolve |

---

## 6. Confidence

| Dimension | Level |
|---|---|
| Control flow | High |
| Slot walk / skip bit / callers 0/1 | High |
| 0x2030 layout (except aim source) | High |
| Net connection global name | INFERRED |
| Aim XYZ source | Open |
| Overall | **Human-refined + dual residual; runtime open** |

---

## 7. Open questions

1. Aim stack residual (`uStack_60/5c/58` never written after zero of aim trio).
2. Product name for `skill+0x615` bit0.
3. Exact type of skill-list at entity `+0x74`.
4. Seal `g_pSectorNetConnection_INFERRED` / `DAT_00d1b8f0` names.
