# Function record: Client_PacketDispatch

| Field | Value |
|---|---|
| **Stable ID** | `aa_00815710` |
| **Canonical name** | `Client_PacketDispatch` |
| **Address** | `0x00815710` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression (multi-system S2C demux) |
| **Completion status** | **Partial scaffold + human-refined case comments** — dual review present |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Fresh decompile** | 2026-07-23 Ghidra `batch_decompile` CF-matches raw |

## Purpose

Central sector/global **S2C game-opcode switch**. Routes mission/XP/credits, inventory grab/drop/equip, skill status, object create/destroy, store/trade/refinery, and intentional no-ops. Returns 1 if handled, 0 if unknown.

## Signature (decompiler-derived)

```c
uint32_t /* undefined4 */ __fastcall
Client_PacketDispatch(void *param_1, Packet_CharacterLevel *param_2, void *param_3);
/* param_2 typed as CharacterLevel only by Ghidra — treat as generic packet header + body */
```

## Priority cases (see clean comments)

| Opcode | Name | Handler |
|---|---|---|
| `0x2017` | CharacterLevel | `Client_RecvCharacterLevel` (`0x00810f00`) |
| `0x2031` | SkillStatusEffect | `Client_RecvSkillStatusEffect` |
| `0x2035`/`0x2039` | Grab / GrabMM response | `Client_RecvInventoryGrabResponse` |
| `0x2037`/`0x203B` | Drop / DropMM response | `Client_RecvInventoryDropResponse` |
| `0x203C` | InventoryEquip | `Client_RecvInventoryEquip` |
| `0x205E` | GiveCredits | `Client_RecvGiveCredits` (`0x0080cac0`) |
| `0x205F` | GiveXP | `Client_AwardKillExperience` |
| `0x206C` | GroupReactionCall | `Client_RecvGroupReactionCall` |
| `0x206D` | MissionDialog | `Client_RecvNpcMissionDialog` |
| `0x2070` | CompleteDynamicObjective | `Client_RecvCompleteDynamicObjective` (`0x0080ff00`) |
| `0x2071` | ObjectiveState | `Client_RecvObjectiveState` |

**Absent:** `0x2030` RequestCastSkill (C2S only).

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00815710_Client_PacketDispatch.md`
- Annotated: `docs/reconstruction/raw/aa_00815710_Client_PacketDispatch.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_PacketDispatch.cpp`
- Reviews: `docs/reconstruction/reviews/aa_00815710_reconstruction_review.md`, `…_skeptical_review.md`
- Batch: `docs/reconstruction/coverage/tmp_batch_packetdispatch.json`

## Callers / callees

Callees include named recv units above plus many `FUN_008*` leaves. Callers: client game-packet queue drain (tick path; not fully xrefs-documented here).

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| Priority named case routes | High |
| Parameter semantic names / ABI | Tentative |
| Types (`Packet_CharacterLevel *`) | Tentative (shared header only) |
| Register args for credits/XP/grab | Contested across units |
