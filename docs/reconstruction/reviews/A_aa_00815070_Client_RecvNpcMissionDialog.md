# Review A (reconstruction fidelity): `aa_00815070` Client_RecvNpcMissionDialog

| Field | Value |
|---|---|
| **Stable ID** | `aa_00815070` |
| **VA** | `0x00815070` |
| **Canonical name** | `Client_RecvNpcMissionDialog` |
| **Review date** | `2026-07-23` (residual strengthen `2026-07-29` pass 2) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00815070_Client_RecvNpcMissionDialog.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

S2C **0x206D** NpcMissionDialog handler. Resolve NPC TFID, clear prior dialog staging, stage each resolvable mission offer (mission id + 8 item COID slots, stride **40**), then `Client_ShowNpcMissionDialogUI(ctx, npc, mode=1)` with **EAX = −1** pre-seed. Client does **not** re-check mission eligibility.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00815070_Client_RecvNpcMissionDialog.md` |
| Annotated | `docs/reconstruction/raw/aa_00815070_Client_RecvNpcMissionDialog.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvNpcMissionDialog.cpp` |
| Function record | `docs/reconstruction/functions/aa_00815070_Client_RecvNpcMissionDialog.md` |
| Packet | `src/AutoCore.Game/Packets/Sector/NpcMissionDialogPacket.cs` |
| Tests | `src/AutoCore.Game.Tests/Packets/NpcMissionDialogPacketTests.cs` |
| Downstream | `Client_ShowNpcMissionDialogUI` @ `0x009438f0` |
| Chain | `reviews/CHAIN_2026-07-29_s2c_206d_npcmissiondialog.md` |
| Scratch | `tmp/a_00815070.md` |

Ghidra this pass: `decompile_function` @ `0x00815070` / callees `0x004bb070` `0x0052d8b0` `0x0052c700` `0x0053fff0` `0x009438f0`; `read_memory` body + call site + `FUN_004bb070` prolog.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Opcode **0x206D** NpcMissionDialog | **High / Confirmed** | Sole PacketDispatch xref `0x00815af4` + `case 0x206d` (body never compares) |
| Packet base in **EBX** | **High / Confirmed** | Call site `MOV EBX,ESI`; decomp `unaff_EBX` |
| Stack formal `param_1` = client/game ctx | **High / Confirmed** | `PUSH EBP`; epilogue `RET 4` stdcall |
| NPC TFID at `+0x08` via `FUN_004bb070(packet+8)` | **High / Confirmed** | `LEA EDX,[EBX+8]; PUSH; CALL` — callee stack-only stdcall |
| Count at `+0x18` is **u8** (client bound) | **High / Confirmed** | `CMP BYTE` @`0x008150a0`; `MOVZX` @`0x00815169` |
| Server may write i32 count; low byte used | **High** | AutoCore `Write(int)`; LE compatible for 0–255 |
| Entry stride **40** / 10 dwords | **High / Confirmed** | `ADD EBP, 0x28` @ loop tail |
| Mission id @ entry `+0` (`packet+0x20` first) | **High / Confirmed** | Loop: `LEA EBP,[EBX+0x28]`; `MOV ESI,[EBP-8]` → `EBX+0x20` |
| 8× item COID @ entry `+8` (`packet+0x28` first) | **High / Confirmed** | `REP MOVSD` ECX=8 from EBP (`EBX+0x28`) into scratch |
| Scratch: 11×i32 init −1 then overwrite 8 | **High / Confirmed** | image init block + `F3 A5` count 8 |
| No client eligibility filter | **High** | stages all resolvable defs only |
| Missing def → silent skip stage | **High** | CF; still advances index |
| Count 0 still shows UI mode 1 | **High** | JBE past loop → Show |
| Ends with `ShowNpcMissionDialogUI(ctx, npc, 1)` | **High / Confirmed** | `PUSH 1; PUSH uNpc; PUSH EDI` |
| **EAX = −1** immediately before Show | **High / Confirmed** | `OR EAX,0xFFFFFFFF` @`0x0081518c`; Show reads `in_EAX` when mode≠0 |
| `pClientCtx+0xe04` → `+0xe4e8` load | **High / Confirmed dead** | loads ECX; `FUN_004bb070` prolog uses **only** stack arg (`MOV EAX,[ESP+4]… RET 4`) — ECX never consumed in this hub |
| `FUN_0053fff0` this = `*(pClientCtx+0xd30)` | **High / Confirmed** | `MOV ECX,[EDI+0xd30]` before fastcall |
| `FUN_0052d8b0` / `FUN_0052c700` this = `DAT_00d1b6d8` | **High / Confirmed** | `MOV ECX,[00d1b6d8]` at both call sites |
| `FUN_0052d8b0(0,-1)` clears staging | **High** CF | thiscall character; map root `+0x50c` / count `+0x510`; product name open |
| `FUN_0052c700` offer staging | **High** CF | thiscall character; key=`*missionDef`; copies **12** dwords from scratch; product name open |
| `FUN_0053fff0` mission-def table root | **High** CF | returns `obj+0xf18`; product name open |
| `FUN_004bb070` TFID resolve | **High** CF | `CVOGReaction_ResolveObjectTarget` + vtbl `+0x1d8`; product name open |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| (dead) world ptr load `+0xe04/+0xe4e8` | **Yes** (documented dead) |
| Resolve NPC + clear staging | **Yes** |
| Per-entry mission def hash walk | **Yes** |
| Init slots −1; copy 8 COIDs; stage | **Yes** |
| Show UI mode 1 + EAX=−1 | **Yes** (plate/annotate must carry EAX) |
| No invented eligibility filter | **Yes** |

---

## 5. Gaps / open questions

1. Product names for `FUN_004bb070` / `FUN_0052c700` / `FUN_0052d8b0` / `FUN_0053fff0` (roles sealed; no string/RTTI this pass).
2. Product type name for `pClientCtx+0xe04` (world/sim from sibling units) — **unused live** in this hub; only dead load remains.
3. Full semantics of Show when `mode=1` and `EAX=−1` (uses first staged mission key from character map) — **downstream body** of `Client_ShowNpcMissionDialogUI`, not this hub’s responsibility beyond pre-seeding EAX.
4. Item COID slot semantics (required vs reward) live in staging consumers, not this hub.
5. Runtime capture / binary diff / bit-exact still open.

**Verdict:** Dialog open S2C hub faithful; count width, framing, dead `+0xe04` load, and Show EAX pre-seed **sealed**. **accept-with-gaps.**
