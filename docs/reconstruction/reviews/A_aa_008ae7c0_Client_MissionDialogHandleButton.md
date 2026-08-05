# Review A (reconstruction fidelity): `aa_008ae7c0` Client_MissionDialogHandleButton

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ae7c0` |
| **VA** | `0x008ae7c0` |
| **Canonical name** | `Client_MissionDialogHandleButton` |
| **Review date** | `2026-07-29` (UF-017 lag close + 0x206E seal refresh; prior 2026-07-23) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008ae7c0_Client_MissionDialogHandleButton.md` |
| **System tag** | `missions-progression` |
| **Chain (abandon static e2e)** | `reviews/CHAIN_2026-07-29_abandon_failmission.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Ghidra decompile (live) | `Client_MissionDialogHandleButton` @ `0x008ae7c0` |
| Open-site image bytes | `read_memory` `0x008ae8a0` len 48 (2026-07-29) |
| ShowModalPrompt body | `FUN_007fdfb0` @ `0x007fdfb0` (EAX→`+0x498`, param_3→`+0x49c`) |
| Clean | `docs/reconstruction/reconstructed-exact/Client_MissionDialogHandleButton.cpp` |
| Function record | `docs/reconstruction/functions/aa_008ae7c0_Client_MissionDialogHandleButton.md` |
| Prepare | Ghidra `Client_NpcDialog_PrepareResponseOpcode` @ `0x008abd70` |
| Flush | Ghidra / clean `Client_MissionDialog_FlushPreparedResponse` @ `0x008ab8f0` |
| Show UI | Ghidra `Client_ShowNpcMissionDialogUI` @ `0x009438f0` |
| Hide | Ghidra `Client_HideMissionDialogIfOpen` @ (hide-only; no flush) |
| Packet | `src/AutoCore.Game/Packets/Sector/MissionDialogResponsePacket.cs` |
| Server handler | `TNLConnection.Sector.cs` → `HandleMissionDialogResponse` |
| System map | `docs/reconstruction/systems/missions-progression.md` |
| Abandon e2e chain | `reviews/CHAIN_2026-07-29_abandon_failmission.md` |
| Prior dual | A/B 2026-07-23 (open: 0x206E send site); mid-day 0x206E seal |

---

## 2. Evidence used — 0x206E seal refresh

### 2.1 What HandleButton does for the response buffer (state 1)

When state at `dialog+0x648 == 1` and `dialog+0x670 != 0`:

| Offset | Written value | Source |
|---|---|---|
| `+0x660..+0x66c` | NPC TFID16 (or −1s) | From `dialog+0x644` object / TFID fields |
| `+0x654` | missionId | `*(*(dialog+0x670))` |
| `+0x658` / `+0x65c` | **accept path:** `pDialogContext` + sign-extend; **turn-in path:** reward COIDs from `+0x578/+0x57c` | Branch on `dialog+0x64c` |

**No** `Client_SendSectorPacket` / vtbl+0x18 call with opcode **0x206E** appears in this function.

State 0 **does** send sector packet **0x206F** size `0x18` directly — different opcode, not the seal target.

### 2.2 Who stamps opcode / who sends

```
ShowNpcMissionDialogUI
  → NpcDialog_PrepareResponseOpcode   // +0x650 = 0x206E
MissionDialogHandleButton (state 1)
  → fills +0x654 / +0x658 / +0x660    // payload only
MissionDialog_FlushPreparedResponse   // vtable 0x00a4a95c
  → if (+0x650 != 0) send 0x20 bytes from +0x650
```

This closes the 2026-07-23 open item: **“Exact send site for response 0x206E relative to this handler.”**  
Answer: **not in this handler**; deferred to `Client_MissionDialog_FlushPreparedResponse` @ `0x008ab8f0` after payload prepare.

### 2.3 Local gameplay side effects still in this body

| State | Behavior | Confidence |
|---|---|---|
| 0 | C2S `0x206F` accept-request (NPC TFID from `+0x678`) | High |
| 1 + `+0x64c==0` + button==0 | `CVOGReaction_GiveMission`; hide; optional first-obj helper | High |
| 1 + turn-in | reward gates; inventory check; `CompleteObjective(..., force=0)`; hide/refresh | High |
| 2 | Abandon **confirm modal only** — stack secondary **`0x4e47`** (No) + open-site **EAX `0x4e46`** (Yes); FailMission **not** here | High |
| 3 | `ShowNpcMissionDialogUI(..., 0)` re-show | High |

---

## 3. State-2 abandon open site (UF-017 / UF-009)

### 3.1 Decompiler lag (why UF-017 existed)

Decompiler of HandleButton shows only:

```c
FUN_007fdfb0(&DAT_00d1a840, acStack_200, 0x4e47, 1, 0);
```

That third arg is the **stack secondary / No id**. It is **not** the only modal code programmed.

### 3.2 Image at call site (`read_memory` @ `0x008ae8a0`)

Relevant tail (decoded):

| Bytes | Asm | Meaning |
|---|---|---|
| `6A 00` | `PUSH 0` | flag B |
| `6A 01` | `PUSH 1` | flag A |
| `68 47 4E 00 00` | `PUSH 0x4e47` | No / Cancel secondary |
| `…` | push msg / `&DAT_00d1a840` | prompt text + UI root |
| `B8 46 4E 00 00` | **`MOV EAX, 0x4e46`** | **Yes / OK primary** |
| `E8 …` | `CALL Client_ShowModalPrompt` (`0x007fdfb0`) | |

### 3.3 How `FUN_007fdfb0` consumes both ids

Live decompile of `0x007fdfb0`:

- `modal+0x498 = in_EAX` → **Yes = `0x4e46`**
- `modal+0x49c = param_3` (when ≥ 0) → **No = `0x4e47`**

Dispatch (`aa_00911840`): case **`0x4e46`** → C2S `0x20B2`; case **`0x4e47`** → close only.

**Pairing confidence: High.** Do not describe state-2 as “modal code only `0x4e47`.”

### 3.4 Static e2e pointer (not residual)

Abandon end-to-end on the client is **sealed static** in:

`docs/reconstruction/reviews/CHAIN_2026-07-29_abandon_failmission.md`

```
state2 stash DAT_00d1b4b4
  → ShowModalPrompt Yes EAX 0x4e46 / No stack 0x4e47
  → UiModal case 0x4e46 → C2S 0x20B2 size 0x18
  → (server) S2C 0x20B2
  → RecvFailMission → CVOGReaction_FailMission
```

**HandleButton’s share:** stash + open dual-id modal; **no** FailMission, **no** C2S `0x20B2` here.

**Residual for this unit:** **runtime** live capture only (CE/packet). Static pairing and static e2e are closed (UF-009 High; UF-017 dual lag closed).

---

## 4. Confirmed claims with confidence

| Claim | Confidence | Notes |
|---|---|---|
| Dialog state at `+0x648` routes 0/1/2/3 | **High** | Explicit compares |
| State 0 → C2S `0x206F` size `0x18` | **High** | Literal in stack packet |
| State 1 fills 0x206E **payload** at `+0x654/+0x658/+0x660` | **High** | Direct stores |
| State 1 does **not** send 0x206E itself | **High** | No send site in body |
| 0x206E opcode stamped earlier by Prepare | **High** | Chain |
| 0x206E sent by FlushPreparedResponse | **High** (static) | See `aa_008ab8f0` reviews |
| Accept → GiveMission when not turn-in | **High** | Named callee; gated `pDialogContext==0` |
| Turn-in → CompleteObjective force=0 | **High** | Named callee |
| Do not also emit server 0x2070 for same client turn-in | **High** (policy) | Local complete already runs |
| Reward selection masks `+0x558/55c` & `+0x578/57c` | **High** | Gate before turn-in |
| Inventory space `FUN_005714e0` | **Probable** | Semantics open |
| `in_EAX` dialog UI context | **High** | Active slot `+0x708+idx*4` |
| State 2 stashes `DAT_00d1b4b4` from `+0x670` | **High** | Direct stores |
| State 2 open: EAX Yes `0x4e46` + stack No `0x4e47` | **High** | Image + ShowModalPrompt body |
| Abandon completes FailMission here | **False** | Modal only |
| Static abandon e2e | **High** | Chain seal; residual = runtime only |
| `+0x658` is pure `bool accepted` on all paths | **Medium-Low** | Turn-in overloads with reward COID |

---

## 5. Control flow: clean ≡ decompiler

| Stage | Match |
|---|---|
| Global null / modal child abort | **Yes** |
| State 2 abandon prompt (with EAX correction) | **Yes** (clean plate documents EAX; body still shows decompiler third-arg form) |
| State 0 packet 0x206F | **Yes** |
| State 3 re-show | **Yes** |
| State 1 accept vs turn-in on `+0x64c` | **Yes** |
| Payload field stores before GiveMission / CompleteObjective | **Yes** |
| CompleteObjective args (obj id, reward COID lo/hi, force 0) | **Yes** |

---

## 6. Remaining uncertainty

1. **Virtual flush after hide:** `Client_HideMissionDialogIfOpen` only hides root chrome — invoker of Flush vtable slot still not fully walked (see Flush B review / UF-010).
2. **`pDialogContext` polarity** for accepted bool (0 = accept/GiveMission path).
3. ~~Abandon static e2e / Yes id only No `0x4e47`~~ **Sealed** — see §3 + `CHAIN_2026-07-29_abandon_failmission.md`. **Runtime** live abandon capture still open.
4. Auto-complete first objective gates (`DAT_00d1b216`, def+0xfa, `DAT_00d1ad10+0x10`).
5. Turn-in payload vs AutoCore `Accepted` bool — server tests often use `accepted=false` for turn-in.

---

## 7. Verdict

**accept-with-gaps.**

Dialog button matrix remains faithful. **0x206E seal:** payload prepare is **in** this unit; **send is not** — send is `Client_MissionDialog_FlushPreparedResponse`. **UF-017 lag closed:** state-2 opens dual-id modal (Yes EAX `0x4e46` / No stack `0x4e47`), not “code only `0x4e47`.” Abandon static e2e points at `CHAIN_2026-07-29_abandon_failmission.md`; residual is **runtime only**. Other gaps: flush invoker liveness, accepted-field overload on turn-in.
