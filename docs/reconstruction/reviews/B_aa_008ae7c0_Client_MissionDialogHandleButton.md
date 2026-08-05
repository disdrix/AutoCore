# Review B (skeptical / adversarial): `Client_MissionDialogHandleButton` @ `0x008ae7c0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ae7c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (UF-017 lag close + 0x206E seal refresh; prior 2026-07-23) |
| **Counterpart** | `reviews/A_aa_008ae7c0_Client_MissionDialogHandleButton.md` |
| **Chain (abandon static e2e)** | `reviews/CHAIN_2026-07-29_abandon_failmission.md` |
| **Verdict** | **accept-with-gaps** on CF + payload prepare + abandon open dual-id; **partial** on end-to-end 0x206E delivery (flush invoker) |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Turn-in must also send S2C 0x2070 | Local `CompleteObjective` already runs with force=0 | **Falsified policy** (do not double-complete) |
| 2 | State 1 always GiveMission | `+0x64c` selects turn-in → CompleteObjective | **Falsified** |
| 3 | This function sends C2S 0x206E | No send of 0x206E in body; only field stores | **Correct — does not send** |
| 4 | 0x206E is therefore “sealed” for live Accept | Flush is virtual; HideMissionDialogIfOpen does not call Flush | **Partial** — static chain yes; live invoker not proven inside this unit (UF-010) |
| 5 | `+0x658` is always Accepted bool | Turn-in writes reward COID pair into `+0x658/+0x65c` | **Attack hits** — AutoCore bool Read may be a simplification |
| 6 | State 2 only programs modal code `0x4e47` | Decompiler shows only stack `0x4e47`; image has `MOV EAX,0x4e46` before call | **Attack hits decompiler lag** — dual-id: Yes EAX `0x4e46`, No stack `0x4e47` (**High**, UF-009/UF-017) |
| 7 | Abandon / FailMission happens in this function | Body only stashes `DAT_00d1b4b4` + opens modal; no `0x20B2`, no FailMission | **Correct if “modal only”**; **false if “fails mission here”** |
| 8 | Abandon e2e is still open in dual residual | Static chain sealed; only runtime open | **Lag closed** — pointer `CHAIN_2026-07-29_abandon_failmission.md` |
| 9 | pDialogContext is always button index | Used as accept gate (0), abandon branch flag, reward path index | **Tension** — overloaded |
| 10 | GiveMission when pDialogContext==0 means “accepted=true” | Stores `pDialogContext` into `+0x658` then only grants on 0 — **accepted field may be 0 on grant** | **Polarity hazard** for server Accepted semantics |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| State matrix 0–3 | High | Wrong accept/claim UX |
| Local turn-in CompleteObjective (force=0) | High | Double-complete if server also 0x2070 |
| Opcode 0x206F accept-request | High | Wrong C2S for accept-request |
| Payload field stores for 0x206E buffer | High | Server sees empty missionId/TFID |
| Deferred flush is always reached | **Medium** | Server never gets 0x206E |
| Inventory full gate | Medium | Reject claim incorrectly |
| State-2 dual-id open (EAX `0x4e46` / stack `0x4e47`) | **High** | Yes/No inverted; wrong dispatch case |
| Static abandon → FailMission e2e (outside this body) | **High** | See chain; residual runtime only |
| Abandon completes FailMission **here** | **False / N/A** | Would invent local fail path |
| Accepted bool interpretation | **Low–Medium** | Grant vs decline inverted; turn-in misread |
| Auto-complete first objective after accept | Low | Skipped or always-on wrong |

---

## 3. Attack on “only 0x4e47” (UF-017)

**Adversarial claim that failed:** “HandleButton residual is still open because state-2 only posts `0x4e47`.”

**Evidence that kills the claim:**

1. Image at open site (`0x008ae8a0` region): `PUSH 0x4e47` **and** `MOV EAX, 0x4e46` immediately before `CALL 0x007fdfb0`.
2. `FUN_007fdfb0` stores `in_EAX` → `+0x498` (Yes), `param_3` → `+0x49c` (No when ≥ 0).
3. `Client_UiModalDispatch` case `0x4e46` sends C2S `0x20B2`; case `0x4e47` closes only.

**Skeptical remaining:** runtime click observation not performed. That is **not** a static dual lag; do not re-open UF-017 as “pairing Probable.”

---

## 4. Surviving contract for AutoCore

```
Dialog button (state at dialog+0x648):
  0 → send 0x206F (accept-request) with NPC TFID from dialog+0x678
  1 + not turn-in (+0x64c==0):
        fill 0x206E payload (missionId, button→+0x658, NPC TFID);
        if button==0: GiveMission(missionId); hide; optional first-obj auto
        // 0x206E wire send is NOT here — FlushPreparedResponse later
  1 + turn-in:
        reward selection + inventory checks;
        fill payload (missionId; +0x658/+0x65c = reward COIDs; TFID);
        CompleteObjective(lastObj, reward, force=0);
        refresh/hide UI;
        do NOT also emit 0x2070 from server for same turn-in
  2 → stash DAT_00d1b4b4; open dual-id modal
        Yes id EAX 0x4e46  |  No id stack 0x4e47
        // FailMission / C2S 0x20B2 NOT here — see CHAIN abandon_failmission
  3 → ShowNpcMissionDialogUI(npc, mode=0)

0x206E opcode stamp: Prepare on dialog show (dialog+0x650).
0x206E send: FlushPreparedResponse (vtable 0x00a4a95c), size 0x20.

Abandon static e2e: reviews/CHAIN_2026-07-29_abandon_failmission.md
  residual = runtime live capture only
```

---

## 5. Open questions

1. Prove virtual call into `0x008ab8f0` after state-1 accept/turn-in (not only Hide chrome) — UF-010.
2. ~~Abandon confirm handler path to FailMission~~ **Sealed static** — `CHAIN_2026-07-29_abandon_failmission.md` (UiModal `0x4e46` → C2S `0x20B2` → Recv → FailMission). Runtime still open.
3. Whether reward COID −1/−1 is valid “no choice” for all mission defs.
4. Reconcile client `+0x658` polarity with server `MissionDialogResponsePacket.Accepted` and live logs that use `accepted=false` on turn-in.
5. Does state-1 decline (nonzero button) still leave 0x206E prepared for flush with “rejected” semantics?

---

## 6. What changed since 2026-07-23 / mid-day lag

| Prior open / lag | Now |
|---|---|
| “Who sends C2S 0x206E after turn-in / accept?” | **Answered:** `Client_MissionDialog_FlushPreparedResponse` @ `0x008ab8f0` |
| Seal relative to HandleButton | **Payload in HandleButton; send outside** — do not force a send into this CF |
| Registry “0x206E packing partial” | Packing partial remains for accepted/reward overload; opcode+size sealed |
| Dual residual “abandon e2e open” / “modal only 0x4e47” | **Closed static (UF-017)** — Yes EAX `0x4e46` + chain seal; residual **runtime only** |
| Dual B confidence “Abandon modal → FailMission Medium” | **Reclassified:** FailMission is **not** in this unit; static e2e **High** via chain |

---

## 7. Verdict

**accept-with-gaps.**

Skeptical stance: HandleButton is a **UI router + local reaction driver + 0x206E payload filler + abandon modal opener**, not the wire sender for 0x206E and not the FailMission kernel. Claiming “0x206E sealed inside HandleButton” is false; claiming “0x206E seal chain includes HandleButton as preparer” is true. Claiming “state-2 only posts `0x4e47`” is **false** after open-site image. Keep Accepted polarity and flush invoker open. Do **not** keep abandon static e2e open in this dual — point to `CHAIN_2026-07-29_abandon_failmission.md`; residual is runtime.
