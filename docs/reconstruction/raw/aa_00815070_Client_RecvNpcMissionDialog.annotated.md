# Annotated low-level: Client_RecvNpcMissionDialog (`aa_00815070`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00815070` |
| **VA** | `0x00815070` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | missions-progression |
| **Source raw** | `aa_00815070_Client_RecvNpcMissionDialog.md` (capture 2026-07-23) |
| **Opcode** | **S2C `0x206D`** open NPC mission dialog |

This file is the **annotated** layer: widths, signedness, branch order, side effects, and decompiler corrections. It does not replace the immutable raw capture.

---

## 1. Corrected signature

```c
void __stdcall Client_RecvNpcMissionDialog(void *pClientCtx /* → ShowNpcMissionDialogUI */);
// Packet base in EBX — sealed 2026-07-29: call site PUSH EBP; MOV EBX,ESI; CALL; epilogue RET 4
// Before Show: EAX forced to -1 (OR EAX, -1)
```

| Name | Width | Signedness | Origin | Role |
|---|---|---|---|---|
| `pClientCtx` | pointer | opaque | stack (`EBP` at call → EDI in body) | Nested tables + Show UI formal |
| packet (`unaff_EBX`) | pointer | unsigned | `EBX` ← `ESI` | S2C `0x206D` body |

### Packet layout (plate + loop stride + asm 2026-07-29)

| Offset | Width | Role |
|---|---|---|
| `+0` | u32 | Opcode (`0x206D`; dispatch-external) |
| `+0x08` | 16B | NPC TFID (`LEA EDX,[EBX+8]` → `FUN_004bb070`) |
| `+0x18` | **u8** client bound | Entry **count** — `CMP BYTE [EBX+0x18],0` / `MOVZX ECX, BYTE [EBX+0x18]` |
| `+0x18` wire | often **i32** LE | AutoCore writes i32; low byte = client bound (≤255) |
| `+0x20` | i32 | First mission id (`[EBP-8]` with `EBP=EBX+0x28`) |
| `+0x28` | 8× i32 | First entry item COIDs (−1 empty) |
| Per entry | **40 bytes** (`ADD EBP, 0x28`) | One mission offer row |

**Stride:** **40 bytes** per mission entry. Count client bound is **u8** (sealed).

Plate summary:

```text
+0x08 NPC TFID, +0x18 count (u8 client), per entry stride 40: mission id + 8 item coid slots
```

Decompiler indexing uses `undefined4*`; convert carefully when cleaning.

### Opcode / framing seal (2026-07-29)

| Claim | Evidence | Conf |
|---|---|---|
| S2C **0x206D** | sole xref `0x00815af4` in `Client_PacketDispatch`; `case 0x206d` | **Confirmed** |
| Packet in **EBX** | `8b de` at call site | **Confirmed** |
| Stack ctx stdcall | `55` push EBP; `c2 04 00` ret 4 | **Confirmed** |
| Show **EAX=−1** | `83 c8 ff` before `CALL Show` | **Confirmed** |
| `+0xe04→+0xe4e8` | loads ECX; `FUN_004bb070` stack-only | **Confirmed dead** |

---

## 2. Decompiler corrections

| Decompiler artifact | Correction | Confidence |
|---|---|---|
| `unaff_EBX` | Packet pointer from PacketDispatch (`MOV EBX,ESI`) | **Confirmed** |
| `FUN_004bb070(EBX+2)` | dword index: TFID at `packet+8`; stdcall stack-only | **High** |
| Prolog ECX from `ctx+0xe04` | Dead load; not consumed by resolve | **Confirmed** |
| `FUN_0052d8b0(0, -1)` | thiscall `DAT_00d1b6d8`; clear dialog staging map `+0x50c` / count `+0x510` | **High** CF |
| `FUN_0053fff0` | fastcall this=`*(ctx+0xd30)`; returns mission-def table @ `+0xf18` | **High** CF |
| Manual hash walk on def table | Bucket walk by mission id; node+8 → def* | **High** |
| `FUN_0052c700(*def, local_30)` | thiscall character; key=`*def`; copies **12** dwords from scratch | **High** CF |
| `Client_ShowNpcMissionDialogUI(param_1, npc, 1)` | mode **1**; **EAX must be −1** at call | **Confirmed** |

---

## 3. Control flow

```text
// dead: ECX = *(*(pClientCtx+0xe04)+0xe4e8)
npc = FUN_004bb070(packet+8)
FUN_0052d8b0(this=character, 0, -1)
for i in 0 .. count-1:          // count = *(u8*)(packet+0x18)
  missionId = entry[i].id       // packet+0x20 + i*40
  def = hash_lookup(FUN_0053fff0(*(ctx+0xd30)), missionId)
  if def:
    local_slots[0..10] = 0xFFFFFFFF; copy 8 item ids from packet
    FUN_0052c700(this=character, *def, local_slots)
  advance entry by 40 bytes
EAX = -1
Client_ShowNpcMissionDialogUI(param_1, npc, 1)
```

| Branch | Effect |
|---|---|
| count == 0 | Skip loop; still show UI (mode 1, EAX=-1) |
| Unknown mission id | Skip `FUN_0052c700` for that row |
| Always | End with ShowNpcMissionDialogUI |

---

## 4. Side-effect order

1. Dead world-ptr load (no effect).
2. Resolve NPC.
3. Clear character dialog staging (`FUN_0052d8b0`).
4. Per known mission: stage offer slots (`FUN_0052c700`).
5. Show dialog UI with mode=1 and EAX=−1.

**AutoCore note (plate):** do not auto-send dialog response immediately after deliver turn-in.

---

## 5. Open questions

- ~~Exact byte offsets for NPC TFID and count~~ — **sealed** (TFID `+0x08`, count u8 `+0x18`, first entry `+0x20`).
- ~~Nested `pClientCtx+0xe04` purpose in this hub~~ — **sealed dead** (not live input).
- ~~Show EAX pre-seed~~ — **sealed** `OR EAX,-1`.
- Item COID slot semantics (required items vs rewards) — staging only here.
- Full interaction with dialog state machine (`MissionDialogHandleButton` states 0–3) / Show branch matrix.
- Product names for `FUN_004bb070` / `FUN_0052c700` / `FUN_0052d8b0` / `FUN_0053fff0`.

## 6. Residual dual strengthen (2026-07-29)

- Pass 1: count u8 + opcode/framing.
- Pass 2: dead `+0xe04`, Show EAX=−1, entry id asm, this-ptrs.
- Dual A/B + function record + chain + scratch `tmp/a_00815070.md`.
- **No WORK_QUEUE/RESUME/CHANGE_LOG.**
