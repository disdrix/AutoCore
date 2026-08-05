# Function record: Client_RecvNpcMissionDialog

| Field | Value |
|---|---|
| **Stable ID** | `aa_00815070` |
| **Canonical name** | `Client_RecvNpcMissionDialog` |
| **Address** | `0x00815070` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Opcode** | **0x206D** NpcMissionDialog (S2C) |
| **Completion status** | **Human-refined clean** — layout, EBX framing, count u8, dead `+0xe04` load, Show EAX=−1 sealed 2026-07-29 p2 |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual verdict** | **accept-with-gaps** (A+B) |

## Purpose

Open NPC mission dialog from S2C `0x206D`. Resolve NPC TFID, clear prior character dialog staging, stage each offered mission’s 8 item COID slots via `FUN_0052c700`, then `Client_ShowNpcMissionDialogUI(ctx, npc, 1)` with **EAX pre-seeded to −1**. Client does not re-filter eligibility.

## Signature

```c
void __stdcall Client_RecvNpcMissionDialog(void *pClientCtx);
// packet base in EBX (call site: MOV EBX, ESI; PUSH EBP)
// epilogue RET 4
// before Show: EAX = 0xFFFFFFFF (OR EAX,-1)
```

## Packet map

| Offset | Field | Width | Notes |
|---|---|---|---|
| `+0x00` | opcode | u32 | `0x206D` (dispatch-external) |
| `+0x08` | NPC TFID | 16B | `FUN_004bb070(packet+8)` |
| `+0x18` | count | **u8** client | wire may be i32 LE; low byte bound |
| `+0x20` | entry0 missionId | i32 | `[EBP-8]` with `EBP=packet+0x28` |
| `+0x28` | entry0 item COIDs | 8× i32 | −1 empty; `REP MOVSD` ×8 |
| +40×n | further entries | stride **40** | `ADD EBP,0x28` |

## Body control flow (sealed)

```
sub esp,0x38; EDI = pClientCtx
ECX = *(*(EDI+0xe04)+0xe4e8)          // DEAD load — not consumed
uNpc = FUN_004bb070(EBX+8)            // stdcall stack TFID*
FUN_0052d8b0(this=DAT_00d1b6d8, 0, -1) // clear staging map +0x50c/+0x510
if (*(u8*)(EBX+0x18) != 0):
  EBP = EBX+0x28
  for index = 0 .. count-1:
    missionId = [EBP-8]               // packet+0x20 + index*40
    ECX = *(EDI+0xd30); table = FUN_0053fff0()
    hash-walk mission def by missionId
    if def:
      scratch[0..10] = -1; copy 8 COIDs from EBP → scratch[0..7]
      FUN_0052c700(this=char, key=*def, scratch)  // copies 12 dwords
    index++; EBP += 0x28
EAX = -1
Client_ShowNpcMissionDialogUI(EDI, uNpc, 1)
add esp,0x38; ret 4
```

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| Opcode / dispatch | **High / Confirmed** | sole PacketDispatch xref `0x00815af4` + case `0x206d` |
| EBX packet framing | **High / Confirmed** | call-site image `55 8B DE E8…` |
| Count u8 at +0x18 | **High / Confirmed** | `CMP BYTE` / `MOVZX BYTE` |
| Mission id / COID / stride 40 | **High / Confirmed** | EBP setup + REP MOVSD + ADD 0x28 |
| `+0xe04→+0xe4e8` | **High dead** | image load; callee `0x004bb070` stack-only |
| Show mode=1 + EAX=−1 | **High / Confirmed** | `6A 01` + `83 C8 FF` before call |
| No client-side filter | **High** | loop stages all valid defs |
| FUN residual roles | **High** CF | product names open |
| Overall | **High (static)** | residual FUN names + runtime + Show branch matrix open |

## Image anchors (read_memory)

| VA | Bytes / asm | Seal |
|---|---|---|
| `0x00815af1` | `55 8B DE E8 77 F5 FF FF` | PUSH ctx; MOV EBX,ESI; CALL handler |
| `0x00815070` | `83 EC 38 57 8B 7C 24 40` | frame; EDI=ctx |
| `0x00815078` | `8B 87 04 0E 00 00` / `8B 88 E8 E4 00 00` | dead `+0xe04` / `+0xe4e8` |
| `0x00815082` | `8D 53 08 52 E8 …` | TFID push + resolve |
| `0x008150a0` | `80 7B 18 00` | CMP BYTE count |
| `0x008150b2` | `8D 6B 28` | EBP = packet+0x28 (COID base / id-8) |
| `0x008150c0` | `8B 8F 30 0D 00 00` | ECX = ctx+0xd30 → FUN_0053fff0 |
| `0x00815169` | `0F B6 4B 18` | MOVZX count |
| `0x00815170` | `83 C5 28` | stride 40 |
| `0x00815185` | `6A 01 52 57 83 C8 FF E8 …` | Show(mode=1), EAX=−1 |
| `0x00815196` | `C2 04 00` | RET 4 |
| `0x004bb070` | `8B 44 24 04 … C2 04 00` | stack TFID*; no ECX |

## Open questions

- Product names for `FUN_004bb070` / `FUN_0052c700` / `FUN_0052d8b0` / `FUN_0053fff0`.
- Product type for `pClientCtx+0xe04` (dead in this hub; world/sim in siblings).
- Show UI branch matrix when `mode=1` && `EAX=-1` (downstream @ `0x009438f0`).
- Item COID required-vs-reward semantics (downstream of staging).
- Runtime / diff / bit-exact.

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_00815070_Client_RecvNpcMissionDialog.md` |
| Annotated | `raw/aa_00815070_Client_RecvNpcMissionDialog.annotated.md` |
| Clean | `reconstructed-exact/Client_RecvNpcMissionDialog.cpp` |
| Dual A | `reviews/A_aa_00815070_Client_RecvNpcMissionDialog.md` |
| Dual B | `reviews/B_aa_00815070_Client_RecvNpcMissionDialog.md` |
| Chain | `reviews/CHAIN_2026-07-29_s2c_206d_npcmissiondialog.md` |
| Scratch | `tmp/a_00815070.md` |
