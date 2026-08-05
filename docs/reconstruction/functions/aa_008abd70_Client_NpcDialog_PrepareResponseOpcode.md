# Function record: Client_NpcDialog_PrepareResponseOpcode

| Field | Value |
|---|---|
| **Stable ID** | `aa_008abd70` |
| **Canonical name** | `Client_NpcDialog_PrepareResponseOpcode` |
| **Address** | `0x008abd70` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **Human-refined (static seal: opcode stamp + reg framing + sole caller)** — UI chrome helpers still scaffold-level |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual residual** | Strengthened 2026-07-29 — accept-with-gaps; see A/B + `tmp/a_008abd70.md` |

## Purpose

Stamps the prepared MissionDialogResponse opcode at **`dialog+0x650 = 0x206E`** and stores the mission definition pointer at **`dialog+0x670`**. Does **not** send the packet. Sole static caller is `Client_ShowNpcMissionDialogUI` (CALL @ `0x00943a60`) when the NPC dialog is shown/reconfigured on the present spine. Later, `Client_MissionDialogHandleButton` fills payload fields and `Client_MissionDialog_FlushPreparedResponse` flushes size `0x20` on teardown.

## Signature (decompiler + asm-sealed)

```c
/* Client_NpcDialog_PrepareResponseOpcode
   ECX = mission def* (param_1)
   ESI = dialog UI object (not in prototype; dual-register framing)
   Sets dialog+0x650 = 0x206E; dialog+0x670 = def.
   Payload body filled later (HandleButton): missionId i32 + accepted + pad + npc TFID16. */
void __fastcall Client_NpcDialog_PrepareResponseOpcode(int param_1 /* mission def* */);
// dialog in ESI from caller (Show: MOV ESI,EBX; MOV ECX,EDI; CALL)
```

### Register contract (High)

| Reg | Meaning | Evidence |
|---|---|---|
| ECX | mission def* | Entry `MOV [ESI+0x670],ECX`; caller `MOV ECX,EDI` |
| ESI | dialog UI* | Entry stores `+0x650`/`+0x670`; caller `MOV ESI,EBX` |
| Imm @ `0x008abd8c` | `0x206E` | `C7 86 50 06 00 00 6E 20 00 00` |

Sole caller always passes **nonzero** def (Show gate). The `param_1 == 0` chrome path is retained in the image but not reached from that path.

## Flush relationship (sealed 2026-07-29)

| Stage | Unit | Address | Role |
|---|---|---|---|
| Show | `Client_ShowNpcMissionDialogUI` | `0x009438f0` | Sole caller; frames ESI/ECX |
| **Prepare (this)** | `Client_NpcDialog_PrepareResponseOpcode` | `0x008abd70` | `*(dialog+0x650) = 0x206E` only `.text` imm site |
| Fill | `Client_MissionDialogHandleButton` | `0x008ae7c0` | Body at `+0x654..` (state 1) |
| **Flush** | `Client_MissionDialog_FlushPreparedResponse` | `0x008ab8f0` | Send size `0x20` from `+0x650` if nonzero |

This function is **not** a direct caller of Flush; Flush is a **downstream teardown peer** that consumes the opcode field this unit writes. Chain: `reviews/CHAIN_2026-07-29_c2s_206e_seal.md`.

## Dialog fields touched

| Off | Write/use | Role | Confidence |
|---:|---|---|---|
| `+0x650` | write imm 0x206E | Prepared C2S opcode / packet head | **High** |
| `+0x670` | write ECX | Mission def* | **High** |
| `+0x6dc` | use | Title/chrome widget | High use |
| `+0x6e4` | use | Reward panel; `FUN_008ab9b0` | High use |
| `+0x68c` | use | Related hide path | Probable |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008abd70_Client_NpcDialog_PrepareResponseOpcode.md`
- Annotated: `docs/reconstruction/raw/aa_008abd70_Client_NpcDialog_PrepareResponseOpcode.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_NpcDialog_PrepareResponseOpcode.cpp`
- Dual A/B: `reviews/A_aa_008abd70_Client_NpcDialog_PrepareResponseOpcode.md`, `reviews/B_aa_008abd70_Client_NpcDialog_PrepareResponseOpcode.md`
- Scratch: `tmp/a_008abd70.md`
- Flush peer: `functions/aa_008ab8f0_Client_MissionDialog_FlushPreparedResponse.md`
- Chain: `reviews/CHAIN_2026-07-29_c2s_206e_seal.md`

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler ≡ raw ≡ live | **High** |
| `dialog+0x650 = 0x206E` stamp | **High** (imm + read_memory + only .text site) |
| ESI/ECX framing | **High** (call-site asm) |
| Sole static caller Show | **High** (xrefs) |
| Sole caller nonzero def | **High** (Show gate) |
| Does not send | **High** |
| Flush is consumer of this field | **High** (static chain) |
| UI chrome side branches / FUN_* names | Probable / Tentative |
| Title sprintf operands | Tentative |
