# Function record: Client_RecvFailMission

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080b100` |
| **Canonical name** | `Client_RecvFailMission` |
| **Aliases** | `Client_OnFailMissionPacket`, prior `FUN_0080b100` |
| **Address** | `0x0080b100` |
| **Size** | ~0x75 bytes (`0x0080b100`–`0x0080b174` RET) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Opcode** | **0x20B2** FailMission (S2C) — **UF-012 sealed High** |
| **Calling convention** | Call site: **EAX** = packet (from ESI), **ECX** = client (from EBP). Body: EDI=client; FailMission / `FUN_005307e0` thiscall on `*(client+0xe98)` |
| **Completion status** | **Promoted / human-refined** — opcode + full register/body framing sealed 2026-07-29 dual residual; secondary helpers open |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

S2C FailMission packet handler. When local character (`game+0xe98`) is present:

1. `CVOGReaction_FailMission(character, missionId @ packet+0x10)` — thiscall ECX=character; **return ignored**
2. `FUN_005307e0(character)` — thiscall post-fail / end-quest drain (**always** after step 1 when char was live)
3. Probe active-objectives hash `char+0x548` with key from `*(*DAT_00d1ad10 + 0x10)`; on miss `FUN_0092fd00()`
4. Optional mission UI refresh via controller at `client+0x107c` (`vtbl+0x3d8` call; `+0x448` **tail jmp** after `POP EDI`)

**Link to abandon:** C2S `0x20B2` is sent from `Client_UiModalDispatch` case `0x4e46` after journal abandon confirm; server processing replies with S2C `0x20B2` into this handler. Also used for non-abandon server fail (reaction / patrol / etc.).

## Signature

```c
// Dispatch call site (0x00815d93):
//   MOV EAX, ESI   ; packet
//   MOV ECX, EBP   ; client
//   CALL 0x0080b100
void Client_RecvFailMission(int client /* ECX */, int packet /* EAX */);
```

## Packet map

| Offset | Field | Used here |
|---:|---|---|
| `+0x10` | MissionId (u32) | **Yes** → FailMission (asm `MOV EDX,[EAX+0x10]`) |
| `+0x08/+0x0C` | CharacterCoid | **No** (local char at `client+0xe98`) |
| other | pad / opcode | No (dispatch already matched) |

## Callers / callees

| Direction | Symbol | Address |
|---|---|---:|
| Caller (sole) | `Client_PacketDispatch` case `0x20b2` | call `0x00815d97` / fn `0x00815710` |
| Callee | `CVOGReaction_FailMission` | `0x0052da30` |
| Callee | `FUN_005307e0` (end-quest drain) | `0x005307e0` |
| Callee | `CNDHash_LookupByKey` | `0x005b0920` |
| Callee | `FUN_0092fd00` | `0x0092fd00` |

## Image seals (dual residual)

| Seal | Evidence | Confidence |
|---|---|---|
| UF-012 opcode → this VA | sole xref `0x00815d97`; `case 0x20b2` | **High / Confirmed** |
| Call framing | `8b c6 8b cd e8 64 53 ff ff` @ `0x00815d93` | **High / Confirmed** |
| FailMission thiscall + missionId | body `MOV ECX,[EDI+0xe98]`; `MOV EDX,[EAX+0x10]`; CALL `0x0052da30` | **High / Confirmed** |
| FailMission return ignored | next insn reloads ECX; no `TEST AL` | **High** |
| End-quest thiscall | `MOV ECX,[EDI+0xe98]`; CALL `0x005307e0` | **High** |
| Packet EAX dead after FailMission | `MOV EAX,[EDI+0xe98]` @ `0x0080b121` for probe | **High** |
| DAT load shape | `MOV ECX,[DAT_00d1ad10]`; `MOV EDX,[ECX+0x10]` | **High (shape)** |
| UI tail | `POP EDI; JMP [EDX+0x448]` @ `0x0080b16c` | **High CF** |

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Opcode / dispatch wiring | **High / Confirmed** | Sole xref + case + enum (UF-012) |
| Call framing EAX/ECX | **High / Confirmed** | Image bytes at call site |
| FailMission thiscall on char | **High / Confirmed** | Body image |
| MissionId packet+0x10 | **High / Confirmed** | Body image |
| Side-effect order (Fail → drain → probe → UI) | **High** | Linear body |
| Post-fail helper product names | Probable / Tentative | `FUN_005307e0` role High framing; dual open |
| Overall | **High (static framing)** | Runtime / bit-exact open |

## Open questions

- Product name / dual for `FUN_005307e0` (proposed role: client end-quest / fail teardown drain).
- `DAT_00d1ad10` object identity; `FUN_0092fd00` body.
- Whether non-local character COID on wire is ever relevant (multi-entity fail).
- Runtime abandon observation.

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_0080b100_Client_RecvFailMission.md` |
| Annotated | `raw/aa_0080b100_Client_RecvFailMission.annotated.md` |
| Clean | `reconstructed-exact/Client_RecvFailMission.cpp` |
| Prior scaffold | `raw/aa_0080b100_FUN_0080b100.md`, `reconstructed-exact/FUN_0080b100.cpp` |
| Dual A/B | `reviews/A_aa_0080b100_Client_RecvFailMission.md`, `reviews/B_aa_0080b100_Client_RecvFailMission.md` |
| Scratch | `tmp/a_0080b100.md` |
| Callee | `functions/aa_0052da30_CVOGReaction_FailMission.md` |
| C2S abandon send | `functions/aa_00911840_Client_UiModalDispatch.md` |
| Dispatch | `reconstructed-exact/Client_PacketDispatch.cpp` |
| Chain | `reviews/CHAIN_2026-07-29_abandon_failmission.md` |
| UF | `UNRESOLVED_FINDINGS.md` UF-012 (sealed) |
