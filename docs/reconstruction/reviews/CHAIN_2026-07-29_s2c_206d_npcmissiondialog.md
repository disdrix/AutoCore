# Chain note: S2C `0x206D` NpcMissionDialog dispatch + count seal

| Field | Value |
|---|---|
| **Date** | `2026-07-29` |
| **Topic** | Static seal of S2C NpcMissionDialog opcode → handler + EBX framing + count width |
| **Opcode** | `0x206D` (`GameOpcode.MissionDialog`) |
| **Handler** | `Client_RecvNpcMissionDialog` @ `0x00815070` (`aa_00815070`) |
| **System** | `missions-progression` |
| **Audience** | Dual-review residual strengthen; cold resume |

---

## Seal chain (static)

```
1. Client_PacketDispatch                    @ 0x00815710
     └─ switch(param_2->dwOpcode)
     └─ case 0x206d:
           PUSH EBP                ; client/game context (param_3 family)
           MOV EBX, ESI            ; packet buffer
           CALL 0x00815070         ; @ 0x00815af4
           return 1

2. Client_RecvNpcMissionDialog             @ 0x00815070
     └─ formal stack pClientCtx (stdcall RET 4)
     └─ packet in EBX
     └─ FUN_004bb070(packet+8) → NPC object / iface
     └─ FUN_0052d8b0(this=char, 0, -1) clear staging
     └─ count = *(u8*)(packet+0x18)
     └─ for i < count: hash mission def; stage 8 COIDs via FUN_0052c700
     └─ Client_ShowNpcMissionDialogUI(ctx, npc, 1)
```

Related C2S accept path (already sealed elsewhere):

```
ShowNpcMissionDialogUI → PrepareResponseOpcode(+0x650=0x206E)
MissionDialogHandleButton (state 1) fills payload
MissionDialog_FlushPreparedResponse sends size 0x20
```

See `CHAIN_2026-07-29_c2s_206e_seal.md`.

---

## Opcode evidence

| Source | Detail | Confidence |
|---|---|---|
| Sole function xref | `From 00815af4 in Client_PacketDispatch [UNCONDITIONAL_CALL]` | **High** |
| PacketDispatch raw | `raw/aa_00815710_Client_PacketDispatch.md` `case 0x206d` | **High** |
| Clean dispatch | `reconstructed-exact/Client_PacketDispatch.cpp` | **High** |
| AutoCore | `GameOpcode.MissionDialog = 0x206D` | corroborating |
| Handler body | never compares opcode | N/A (body-external seal) |

---

## Register / stack framing evidence

Call site image @ `0x00815af1` (Ghidra `read_memory` + `get_assembly_context`):

| Bytes | Asm | Role |
|---|---|---|
| `55` | `PUSH EBP` | client/game context → stack formal |
| `8b de` | `MOV EBX, ESI` | packet buffer → EBX |
| `e8 77 f5 ff ff` | `CALL 0x00815070` | handler |

Epilogue @ end of handler: `C2 04 00` (`RET 4`).

**Signature (sealed):**

```c
void __stdcall Client_RecvNpcMissionDialog(void *pClientCtx);
/* packet buffer in EBX */
```

---

## Count width seal (primary residual)

| Address | Bytes | Asm |
|---|---|---|
| `0x008150a0` | `80 7b 18 00` | `CMP BYTE PTR [EBX+0x18], 0` |
| `0x008150ac` | `0f 86 …` | `JBE` skip loop if count==0 |
| `0x00815169` | `0f b6 4b 18` | `MOVZX ECX, BYTE PTR [EBX+0x18]` |
| loop tail | `83 c5 28` / `3b c1` / `jl` | entry `+= 0x28`; `index < count` |

**Client bound = u8 at +0x18.** Not `MOV` dword.

**AutoCore wire:** `NpcMissionDialogPacket.Write` stores **i32** at `+0x18`. Little-endian low byte is the bound → correct for counts **0–255**. First mission entry remains at `+0x20`. Packet header comment already notes low-byte use.

---

## Packet layout (opcode at +0)

| Offset | Field | Notes |
|---|---|---|
| `+0x00` | u32 opcode | `0x206D` |
| `+0x08` | TFID16 NPC | `FUN_004bb070` |
| `+0x18` | count | **u8** client; wire often i32 LE |
| `+0x20` | entry0 missionId | i32 |
| `+0x28` | entry0 item COIDs | 8× i32 (−1 empty) |
| +40×n | further entries | stride 40 |

Confirmed by: body asm + `NpcMissionDialogPacketTests` + packet class constants.

---

## FUN residual surface (roles — product names open)

| Address | Role (evidence-only) | Conf |
|---|---|---|
| `0x004bb070` | TFID resolve → `CVOGReaction_ResolveObjectTarget` + vtbl+0x1d8 | High CF |
| `0x0052d8b0` | Clear character dialog staging map (`+0x50c`/`+0x510`) | High CF |
| `0x0053fff0` | Mission-def table root at object `+0xf18` | High CF |
| `0x0052c700` | Stage offer slots into character mission map | High CF |
| `0x009438f0` | `Client_ShowNpcMissionDialogUI` (named) | High |

---

## Dual-review unit

| Stable ID | Name | Reviews | Verdict |
|---|---|---|---|
| `aa_00815070` | `Client_RecvNpcMissionDialog` | A/B residual strengthen 2026-07-29 | **accept-with-gaps** |

Paths:

- `reviews/A_aa_00815070_Client_RecvNpcMissionDialog.md`
- `reviews/B_aa_00815070_Client_RecvNpcMissionDialog.md`
- Scratch: `tmp/a_00815070.md`

---

## Sealed vs still open

### Sealed (static, high confidence)

- Opcode **0x206D** → sole handler `0x00815070` via PacketDispatch
- Call framing **EBX=packet, stack=clientCtx** (stdcall)
- Count **u8** client bound at `+0x18`; AutoCore i32 LE OK ≤255
- Stride 40; 8 item COIDs; Show mode 1; no client prereq filter
- FUN residual **roles** (not product names)
- **`pClientCtx+0xe04→+0xe4e8` ECX load is dead** in this hub (`FUN_004bb070` stack-only stdcall; sealed 2026-07-29 p2)
- **Show pre-seed `EAX=-1`** (`OR EAX,-1` immediately before call; Show reads `in_EAX` when mode≠0)
- Mission id asm: `LEA EBP,[EBX+0x28]` / `[EBP-8]` → `+0x20`
- Body this-ptrs: `FUN_0053fff0` ← `*(ctx+0xd30)`; staging/clear ← `DAT_00d1b6d8`

### Still open

- Product names for residual FUN_*
- Product type name for `pClientCtx+0xe04` (dead here; world/sim in siblings)
- Full `Client_ShowNpcMissionDialogUI` branch matrix for mode=1 && EAX=-1
- Runtime capture; binary diff
