# Review B (skeptical / adversarial): `aa_00941fb0` Client_SendChatOrMacro_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00941fb0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual A/B — seal opcode **0x2021**) |
| **Counterpart** | `reviews/A_aa_00941fb0_Client_SendChatOrMacro_Inferred.md` |
| **Verdict** | **accept-with-gaps** on CF (0x2021 + dual paths sealed; sender/prefilter/runtime open) |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Function only sends sector `0x2021` | Global template `0x8000` + `FUN_008073b0` for types 1/2/4/13–15 | **Falsified as sector-only** — dual transport |
| 2 | Opcode might be `Broadcast` S2C only | Imm `0x2021` written into **C2S** buffer; `Client_SendSectorPacket` | **Falsified** — client **sends** 0x2021 |
| 3 | Default type 5 means always SectorMessage | Seed `local_804=5` then **`local_804 = param_4`** before send | **Falsified** — seed only |
| 4 | All ChatTypes send | Jump group 3: types 6,7,11,12 → no send, `return 1` | **Falsified** |
| 5 | “Sector French/German” (14/15) use sector wire | Group 0 → **global `0x8000`** | **Falsified** product-name trap |
| 6 | Convoy (3) always sector | Flag `clone/meta+0xf6`: 0 → global; else sector | **Falsified as always-sector** |
| 7 | Sector packet fills Sender name | Only message + coid + type written; `+0x14` Sender untouched | **Held** — gap stands |
| 8 | ABI is 3 stack-only args (parent decompiles) | `mov esi,ecx` / `mov edi,edx` / `ret 0x0C` | **Falsified** — ECX/EDX + 3 stack |
| 9 | QuickBar type-5 is power and this is power activate | Sibling residual: type-5 → macro phrases → this unit builds chat | **Falsified** (prior false friend) |
| 10 | `0x2021` size is fixed | `size = (short)msgLen + 0x29` | **Falsified as fixed** — length-dependent |
| 11 | Channel always enabled | `DAT_00af9218` bit test; image value all-ones but code path real | **Partial** — mask real; default open in this binary |
| 12 | Coid always local character | Null char → `FFFFFFFF`/`FFFFFFFF` | **Falsified as always-valid** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `0x2021` imm in C2S buffer | **High** | Wrong sector chat opcode |
| Size `msgLen+0x29` | **High** | Truncation / overread |
| Layout ChatType/Coid/IsGM/Len/Msg | **High** | Misaligned `BroadcastPacket` |
| Sender 17 on C2S | **Open** | Server trust of client Sender |
| Global `0x8000` + `msgLen+0x31` | **High** | Wrong global chat path |
| Type→path map | **High** | Misrouted channel |
| ABI 5-slot | **High** | Broken callers / harness |
| Prefilter callees | **Tentative** | Slash-command parity |
| Runtime | **Open** | Live desync unknown |

---

## 3. Cross-check (bytes + decompile)

```
; entry
ESI = ECX          ; recipient name*
EDI = EDX          ; message*
[ebp+8]  = client*
[ebp+0xc]= chatType
[ebp+0x10]= doFilters

; empty message → eax=0x80070057; ret 0x0C

; mask
eax = 1 << chatType
test [0x00AF9218], eax ; jz → return 0

; dual templates
pkt2021+0x00 = 0x2021
pkt2021+0x04 = 5          ; seed
pkt8000+0x00 = 0x8000
pkt8000+0x04 = chatType
strncpy(msg, 1000); strlen → MessageLength
copy recipient → +17 field; copy char name → sender field (global pkt)

if filters: FUN_0093bd10; maybe early out; FUN_00865970

switch(chatType) groups:
  global:  if FUN_00807370: FUN_008073b0(len+0x31, &pkt8000)
  convoy:  flag+0xf6 ? sector_pack_send : global_send
  sector:  coid from char+0x164/168; len; copy msg;
           client+0x30e8=GetTickCount; +0x30ec=len;
           if FUN_00807440: Client_SendSectorPacket(client, len+0x29, &pkt2021)
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 body; opcode/size confirmed by `read_memory`.

---

## 4. Surviving contract for AutoCore

```
Client_SendChatOrMacro_Inferred(recipientName, message, client, chatType, doFilters):

  Reject empty message (HRESULT 0x80070057).
  If !(g_chatTypeMask & (1<<chatType)): return 0.

  // Sector C2S when type ∈ {5,8,9,10} or (type==3 && convoyFlag):
  Broadcast / opcode 0x2021, size = strlen(message) + 0x29:
    +0x00 u32 opcode = 0x2021
    +0x04 u32 ChatType = chatType
    +0x08 u64 SenderCoid = character coid or -1
    +0x10 u8  IsGM = 0
    +0x11 u8  pad (unwritten)
    +0x12 i16 MessageLength = strlen
    +0x14 char[17] Sender  (client does NOT fill)
    +0x25 char[]   Message + NUL
  Send via client+0xc78 (Client_SendSectorPacket).

  // Global C2S when type ∈ {1,2,4,13,14,15} or (type==3 && !convoyFlag):
  Chat / opcode 0x8000, size = strlen + 0x31:
    +0x00 u32 0x8000
    +0x04 u32 ChatType
    +0x08 u8  IsGM=0
    +0x09 char[17] PrivateRecipient = recipientName
    +0x1A char[17] Sender = character name or "DEBUG"
    +0x2C i16 MessageLength
    +0x2E message + NUL
  Send via client+0xc7c (FUN_008073b0).

  Types 6,7,11,12: no network send from this unit.
```

Server must not trust C2S Sender on `0x2021`; fill from connection/character.  
`BroadcastPacket` / `ChatPacket` field order already matches; **size slack** and **Sender residual** are the main parity hazards.

---

## 5. Gaps surviving adversarial pass

1. **Sender** unfilled on sector path.  
2. Prefilter / command rewrite callees not owned.  
3. Parent call-sites still show incomplete decompiler arg lists — harness writers must use §ABI, not parent scaffolds.  
4. No live packet capture this pass.

**Verdict:** **accept-with-gaps** — attacks on “sector-only / fixed-size / always-send / ABI-3arg / power-activate” **fail**; **0x2021 sealed** with documented dual path.
