# Annotated low-level: Client_RecvFailMission (`aa_0080b100`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_0080b100` |
| **VA** | `0x0080b100` |
| **Canonical name** | `Client_RecvFailMission` |
| **Alias** | `Client_OnFailMissionPacket` |
| **System** | missions-progression |
| **Opcode** | **0x20B2** S2C FailMission (**UF-012 sealed High** 2026-07-29 residual) |
| **Source raw** | `aa_0080b100_Client_RecvFailMission.md` |

---

## 1. Corrected signature

```c
// PacketDispatch call site 0x00815d93 (image-sealed):
//   MOV EAX, ESI   ; packet
//   MOV ECX, EBP   ; client
//   CALL 0x0080b100
void Client_RecvFailMission(ClientGame* client /* ECX */, FailMissionPacket* packet /* EAX */);
```

| Name | Width | Origin | Role | Confidence |
|---|---|---|---|---|
| `client` / ECX | ptr | EBP at call site → ECX | Game client; `+0xe98` = local character | **High / Confirmed** |
| `packet` / EAX | ptr | ESI at call site → EAX | FailMission buffer; mission id at `+0x10` (valid only through FailMission call) | **High / Confirmed** |
| return | void | — | — | High |

---

## 2. Decompiler corrections

| Decompiler artifact | Correction | Confidence |
|---|---|---|
| `FUN_0080b100` | **`Client_RecvFailMission`** | High (dispatch + FailMission callee) |
| `in_EAX + 0x10` | **`packet->missionId`** | **High / Confirmed** (asm `MOV EDX,[EAX+0x10]`) |
| `CVOGReaction_FailMission(missionId)` single arg | **`__thiscall` on `*(client+0xe98)`** + missionId | **High / Confirmed** (body image) |
| FailMission return drives next steps | **Return ignored** — end-quest always runs if char was live | **High** |
| `FUN_005307e0()` no args | **`__thiscall` on same character** | **High / Confirmed** |
| `client+0xe98` | Local `CVOGCharacter*` | High |
| `char+0x548` | Active **objectives** hash (not active missions `+0x540`) | High (layout registry) |
| `DAT_00d1ad10 + 0x10` | Load **pointer** from global, then field `+0x10` as lookup key | **High (shape)** / Tentative product |
| `FUN_005307e0` product name | Post-fail / end-quest teardown drain | Probable role; dual open |
| `FUN_0092fd00` | Path when objective hash miss after fail | Tentative |
| UI `+0x107c` vtbl `+0x448` "call" | **`POP EDI; JMP [vtbl+0x448]`** (tail; jumptable warning is noise) | **High CF** |

---

## 3. Image evidence (2026-07-29 residual re-seal)

### Call site (`0x00815d93`)

```
8b c6          MOV EAX, ESI
8b cd          MOV ECX, EBP
e8 64 53 ff ff CALL 0x0080b100   ; next 0x00815d9c + rel(-0xac9c) → 0x0080b100
```

Sole xref: `get_function_xrefs` → `From 00815d97 in Client_PacketDispatch` only.

### Body (full, through RET)

```
0080b100  PUSH EDI
0080b101  MOV EDI, ECX                 ; client
0080b103  MOV ECX, [EDI+0xe98]         ; character
0080b109  TEST ECX, ECX
0080b10b  JZ  0x0080b173               ; POP EDI; RET
0080b10d  MOV EDX, [EAX+0x10]          ; missionId (EAX = packet)
0080b110  PUSH EDX
0080b111  CALL CVOGReaction_FailMission  ; → 0x0052da30; AL ignored
0080b116  MOV ECX, [EDI+0xe98]
0080b11c  CALL FUN_005307e0              ; → 0x005307e0
0080b121  MOV EAX, [EDI+0xe98]           ; EAX = character (packet dead)
0080b127  TEST EAX, EAX
0080b129  JZ  0x0080b149
0080b12b  MOV ECX, [DAT_00d1ad10]        ; pointer global
0080b131  MOV EDX, [ECX+0x10]            ; key
0080b134  MOV ECX, [EAX+0x548]           ; objectives hash
0080b13a  PUSH EDX
0080b13b  CALL CNDHash_LookupByKey       ; → 0x005b0920
0080b140  TEST EAX, EAX
0080b142  JNZ 0x0080b149
0080b144  CALL FUN_0092fd00              ; → 0x0092fd00
0080b149  CMP DWORD [EDI+0x107c], 0
0080b150  JZ  0x0080b173
0080b152  MOV ECX, [EDI+0x107c]
0080b158  MOV EAX, [ECX]
0080b15a  CALL [EAX+0x3d8]               ; live predicate
0080b160  TEST AL, AL
0080b162  JZ  0x0080b173
0080b164  MOV ECX, [EDI+0x107c]
0080b16a  MOV EDX, [ECX]
0080b16c  POP EDI
0080b16d  JMP [EDX+0x448]                ; tail refresh
0080b173  POP EDI
0080b174  RET
```

Prologue hex:  
`57 8b f9 8b 8f 98 0e 00 00 85 c9 74 66 8b 50 10 52 e8 1a 29 d2 ff 8b 8f 98 0e 00 00 e8 bf 56 d2 ff`

---

## 4. Control flow

```text
if client.localCharacter ( +0xe98 ) == null: return

CVOGReaction_FailMission(character, packet.missionId @ +0x10)  // thiscall; return ignored
FUN_005307e0(character)                                        // thiscall; always

if character still non-null:
  key = *(*DAT_00d1ad10 + 0x10)
  node = CNDHash_LookupByKey(character.activeObjectivesHash +0x548, key)
  if node == null:
    FUN_0092fd00()

if client.missionUi ( +0x107c ) non-null:
  if vtbl+0x3d8() live:
    tail jmp vtbl+0x448()
return
```

---

## 5. Chain position

```text
Abandon UI confirm (0x4e46)
  → C2S 0x20B2 Client_SendSectorPacket
  → server FailMission / abandon processing
  → S2C 0x20B2 Client_PacketDispatch case 0x20b2
  → Client_RecvFailMission (this)
  → CVOGReaction_FailMission (active hash fail + notify + dirty 0x10)
  → FUN_005307e0 (drain end-quest vector / toast / hash remove)
```

Also reachable whenever the server emits FailMission for other reasons (reaction type 72, patrol fail, etc.) — same S2C handler.

---

## 6. Side-effect order

1. Gate on local character present.
2. **Fail mission** on character (hash notify path inside callee; may no-op if no live node).
3. `FUN_005307e0` post-step (thiscall) — **unconditional** once char was live at entry.
4. Optional objective-hash probe + `FUN_0092fd00` on miss (no packet fields).
5. Optional mission UI vcall / **tail-jmp** refresh.

---

## 7. Open questions

- Exact meaning of `DAT_00d1ad10` key used after fail (current target objective id?).
- Product name / dual of `FUN_005307e0` (framing sealed).
- Body of `FUN_0092fd00`.
- Whether packet CharacterCoid is validated against local character (not in this body).
- Runtime abandon observation.

---

## 8. Related

| Unit | Address |
|---|---:|
| `Client_PacketDispatch` (call site) | `0x00815d97` |
| `CVOGReaction_FailMission` | `0x0052da30` |
| `FUN_005307e0` | `0x005307e0` |
| `CNDHash_LookupByKey` | `0x005b0920` |
| C2S abandon send (`Client_UiModalDispatch` case `0x4e46`) | `0x00911840` |
| Dual residual scratch | `tmp/a_0080b100.md` |
