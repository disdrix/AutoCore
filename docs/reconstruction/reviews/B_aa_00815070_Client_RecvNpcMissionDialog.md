# Review B (skeptical / adversarial): `Client_RecvNpcMissionDialog` @ `0x00815070`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00815070` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` (residual strengthen `2026-07-29` pass 2) |
| **Counterpart** | `reviews/A_aa_00815070_Client_RecvNpcMissionDialog.md` |
| **Verdict** | **accept-with-gaps** — count/framing/`+0xe04` deadness/Show EAX **sealed**; FUN product names still open |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Client re-filters offered missions by prereqs | **Falsified** — only def lookup; no CheckMissionRequirements |
| 2 | Item COIDs are TFIDs (16B) | **Falsified** — 8× i32 COIDs; −1 empty |
| 3 | Count is int32 at +0x18 (client loop) | **Falsified** — asm is **byte** load (`CMP BYTE` / `MOVZX BYTE` at `[EBX+0x18]`) |
| 4 | AutoCore i32 count write is wrong | **Falsified for 0–255** — LE low byte = client bound; packet comment already “low byte used” |
| 5 | Dialog always shows even with zero offers | **Confirmed** — JBE past loop still `Show(...,1)` |
| 6 | Must auto-send accept after deliver | **Policy risk** — staging only; button path owns accept (`0x206E` chain) |
| 7 | Packet arrives in EAX like SkillStatusEffect | **Falsified** — call site `MOV EBX,ESI`; packet in **EBX** |
| 8 | Opcode 0x206D is plate folklore only | **Falsified** — sole PacketDispatch xref + `case 0x206d` |
| 9 | `pClientCtx+0xe04→+0xe4e8` is required live input | **Falsified 2026-07-29 p2** — loads ECX; `FUN_004bb070` is stack-only stdcall (prolog `MOV EAX,[ESP+4]`, no ECX use); ECX overwritten next for `FUN_0052d8b0` |
| 10 | Show is pure 3-stack-arg API only | **Weakened** — handler forces `OR EAX,-1` before call; Show decomp uses `in_EAX` when `mode≠0` |
| 11 | Mission id lives at entry+8 | **Falsified** — `ESI=[EBP-8]` with `EBP=EBX+0x28` → id at `+0x20`; COIDs at `+0x28` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Layout NPC TFID + count + stride 40 | **High** | Broken NpcMissionDialogPacket |
| No client filter | **High** | Server over-filters or client double-filters |
| Count width **u8 client bound** | **High / Confirmed** | Was Medium; sealed via image bytes |
| Wire i32 count LE-compatible ≤255 | **High** | Truncation only if server ever sends count>255 |
| Show mode=1 semantics | **Medium→High on call site** | mode sealed; full UI state matrix still downstream |
| Show **EAX=−1** pre-seed | **High / Confirmed** | Wrong dialog multi/first-stage branch if EAX garbage |
| Opcode **0x206D** | **High / Confirmed** | Mis-dispatch would open wrong UI |
| EBX packet + stack ctx framing | **High / Confirmed** | Wrong port signature |
| `+0xe04` load live dependency | **High dead** | Over-coupling port to world object for this packet |

---

## 3. Surviving contract for AutoCore

```
S2C 0x206D (PacketDispatch sole case → this handler):
  call: PUSH clientCtx; EBX = packet; CALL 0x00815070  (stdcall ret 4)

  // prologue also loads ECX = *(*(clientCtx+0xe04)+0xe4e8) — DEAD; ignore for ports
  resolve NPC TFID@+8 via FUN_004bb070 (stack TFID*; stdcall)
  clear prior staging (FUN_0052d8b0 thiscall character DAT_00d1b6d8, flag=0, key=-1)
  count = *(u8*)(packet+0x18)     // NOT full i32 loop bound
  for i in 0..count-1:
    entry = packet + 0x20 + i*40  // missionId@0, 8× i32 COID@+8
    this = *(clientCtx+0xd30); table = FUN_0053fff0()  // fastcall
    if mission def found: stage offer (FUN_0052c700 this=character, key=*def, 12 dwords from scratch)
  EAX = -1                        // required pre-seed for Show
  ShowNpcMissionDialogUI(ctx, npc, mode=1)

Server is authority for which missions appear.
Wire may write i32 at +0x18; client uses low byte only.
Do not auto-send MissionDialogResponse after deliver.
```

---

## 4. Open questions

1. Product names for staging/TFID/table FUN_* (roles only this pass).
2. Product type for `pClientCtx+0xe04` (dead here; sibling docs say world/sim).
3. Full Show branch matrix for `mode=1` + `EAX=-1` (downstream unit).
4. Interaction with concurrent journal state 3 (out of body).
5. Runtime capture still open.

**Verdict:** Safe for dialog deliver wire; **count u8 + EBX framing + dead +0xe04 + Show EAX pre-seed sealed**. AutoCore i32 count LE OK ≤255.
