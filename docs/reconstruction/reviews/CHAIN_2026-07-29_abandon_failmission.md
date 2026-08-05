# Chain seal: Abandon confirm → FailMission (2026-07-29)

| Field | Value |
|---|---|
| System | missions-progression |
| Status | **Sealed (static)** — runtime open; modal Yes/No id pairing **High** (UF-009 sealed) |
| Primary residual closed | "Abandon confirm → FailMission end-to-end" (static client path) + FUN_007fdfb0 Yes/No pairing |
| Dual reviews | A/B for `aa_0052da30`, `aa_0080b100`, `aa_00911840`, `aa_007fdfb0` (this date); HandleButton `aa_008ae7c0` prior |

---

## End-to-end (client)

```
┌─ UI: abandon request ─────────────────────────────────────────────┐
│ Client_MissionDialogHandleButton (0x008ae7c0)                     │
│   dialog state +0x648 == 2, button context == 1                   │
│   DAT_00d1b4b4 = **(dialog+0x670)  or  0xFFFFFFFF                 │
│   sprintf: Are you sure you wish to abandon "%s"?                 │
│   Client_ShowModalPrompt FUN_007fdfb0:                            │
│     EAX=0x4e46 → modal+0x498 (Yes/OK)                             │
│     stack secondary=0x4e47 → modal+0x49c (No/Cancel)              │
│     (&DAT_00d1a840, msg, 0x4e47, 1, 0)  // decompiler omits EAX   │
│   return 0   // does NOT send; does NOT FailMission               │
└───────────────────────────────┬───────────────────────────────────┘
                                │ modal open (dual ids programmed)
┌───────────────────────────────▼───────────────────────────────────┐
│ Client_UiModalDispatch FUN_00911840 (0x00911840)                  │
│                                                                   │
│  case 0x4e47 + click(param_2==8):                                 │
│    FUN_007fc360()  // CANCEL / dismiss only                       │
│                                                                   │
│  case 0x4e46 + click(param_2==8):  // CONFIRM (Yes id — High)     │
│    if DAT_00d1b4b4 != -1 && DAT_00d1b6d8 (character) live:        │
│      table = FUN_0053fff0()  // mission def table                 │
│      node  = CNDHash_LookupByKey(*table, DAT_00d1b4b4)            │
│      if node:                                                     │
│        packet[0] = 0x20B2                                         │
│        packet coid = char entity +0x164/+0x168                    │
│        packet missionId = *node                                   │
│        Client_SendSectorPacket(&DAT_00d1a840, 0x18, packet)       │
│        optional: FUN_007fef20(0x13,1,0) if mission UI visible     │
│    FUN_007fc360()  // close modal                                 │
│    // NO local CVOGReaction_FailMission here                      │
└───────────────────────────────┬───────────────────────────────────┘
                                │ C2S 0x20B2
┌───────────────────────────────▼───────────────────────────────────┐
│ Server (out of client RE scope)                                   │
│   missionHandler: HandleFailMission → FailMission                 │
│   strip cargo; delete active; may S2C 0x20B2                      │
│   AutoCore product gap may still exist (see contradictions)       │
└───────────────────────────────┬───────────────────────────────────┘
                                │ S2C 0x20B2 (when server sends)
┌───────────────────────────────▼───────────────────────────────────┐
│ Client_PacketDispatch (0x00815710) case 0x20b2                    │
│   → Client_RecvFailMission FUN_0080b100 (0x0080b100)              │
│       EAX=packet ESI, ECX=client EBP (UF-012 framing sealed)      │
│       if game+0xe98 character:                                    │
│         CVOGReaction_FailMission(missionId = packet+0x10)         │
│         // return AL ignored                                      │
│         FUN_005307e0(char)  // end-quest drain always if char live│
│         optional objective-hash / UI tail-jmp refresh             │
└───────────────────────────────┬───────────────────────────────────┘
                                │
┌───────────────────────────────▼───────────────────────────────────┐
│ CVOGReaction_FailMission (0x0052da30)                             │
│   walk active hash char+0x540                                     │
│   require live node (+8)                                          │
│   log "Player %I64d failed mission %d"                            │
│   CVOGReaction_FailMissionNotify(&id)  // vector push             │
│   char+0x634 |= 0x10                                              │
│   return 1 / 0                                                    │
│   // does NOT erase hash node itself                              │
└───────────────────────────────────────────────────────────────────┘
```

Also: **reaction / HB** can call `CVOGReaction_FailMission` without the UI chain (patrol, kill precheck, reaction type 72, etc.).

---

## Key evidence

| Claim | Evidence | Confidence |
|---|---|---|
| State 2 stashes `DAT_00d1b4b4` | HandleButton decompile; clean `Client_MissionDialogHandleButton.cpp` | **High** |
| Modal open: secondary stack `0x4e47`, primary **EAX `0x4e46`** | asm `008ae8be` `MOV EAX,0x4e46` + `PUSH 0x4e47` | **High** |
| Dual-id store `+0x498`=EAX / `+0x49c`=param_3 | `FUN_007fdfb0` asm `007fe02c` / `007fe060` | **High** |
| Confirm send `0x20B2` / size `0x18` | `FUN_00911840` case `0x4e46` live decompile | **High** |
| Cancel closes only at `0x4e47` | Multi-case group → `FUN_007fc360` | **High** |
| Yes id is `0x4e46` for No/open secondary `0x4e47` | Open-site EAX + dual-id store + dispatch cases | **High** (UF-009 sealed) |
| No local FailMission on confirm | Absent from case `0x4e46` body | **High** |
| S2C `0x20B2` → `FUN_0080b100` | Sole xref call `0x00815d97` in `Client_PacketDispatch` case `0x20b2` | **High / Confirmed** (UF-012 sealed) |
| Recv framing EAX=packet / ECX=client | Image @ `0x00815d93`: `MOV EAX,ESI; MOV ECX,EBP; CALL` | **High / Confirmed** |
| FailMission thiscall on `*(client+0xe98)` | Body `MOV ECX,[EDI+0xe98]` then CALL `0x0052da30` | **High / Confirmed** |
| Recv calls FailMission then end-quest | Image: FailMission then `FUN_005307e0` thiscall on same char | **High** |
| FailMission dirty `\|0x10`, no hash erase | Live decompile `0052da30` | **High** |
| Packet size 0x18 layout | C2S builder + missionState wire notes | **High** |
| Runtime abandon observation | Not run | **Open** |

---

## Dual-review verdicts

| Unit | Stable ID | A | B |
|---|---|---|---|
| `CVOGReaction_FailMission` | `aa_0052da30` | accept (kernel + Notify contract) / accept-with-gaps (lifecycle) | accept-with-gaps (Notify this sealed; drain not always) |
| `Client_RecvFailMission` | `aa_0080b100` | accept-with-gaps (UF-012 framing dual residual sealed High) | accept-with-gaps (framing High; secondary helpers / runtime open) |
| `Client_UiModalDispatch` (abandon slice) | `aa_00911840` | accept-with-gaps | accept-with-gaps (Yes id residual closed via `aa_007fdfb0`) |
| `Client_ShowModalPrompt` | `aa_007fdfb0` | accept (pairing High) | accept (pairing High); gaps on flags/widget source |
| `Client_MissionDialogHandleButton` (upstream) | `aa_008ae7c0` | accept-with-gaps (UF-017 dual lag closed: Yes EAX `0x4e46` / No `0x4e47`; e2e→this chain) | accept-with-gaps (same; residual runtime only) |

---

## Contradictions / doc debt

| # | Conflict | Resolution for RE |
|---|---|---|
| 1 | `docs/missionState.md` (historical): FailMissionPacket “not wired”, “no abandon path” | **Client path is wired** (C2S send + S2C recv + FailMission kernel). Statement is **AutoCore server product debt**, not client absence. Update missionState when product catches up. |
| 2 | HandleButton decompile shows only stack **`0x4e47`** but confirm is case **`0x4e46`** | **Resolved (UF-009):** open sets **EAX=`0x4e46`** (Yes→`+0x498`) and stack **`0x4e47`** (No→`+0x49c`). Decompiler omitted EAX. Do not assume decompiler third arg alone is the Yes id. |
| 3 | Prior FailMission dual residual “abandon UI not observed” | **Closed as chain:** abandon UI never calls FailMission directly; S2C/`0080b100` does. |
| 4 | Prior HandleButton residual “handler for `0x4e47` open” | **Partially closed:** handler is `00911840`; but **`0x4e47` is cancel**, send is **`0x4e46`**. |
| 5 | Name `Client_UiModalDispatch_AbandonConfirm` vs full function | Full VA is multi-domain modal dispatch; abandon is a **slice**. Prefer `Client_UiModalDispatch` + plate comment. |
| 6 | FailMission “fails mission” vs hash still active until end-quest | Kernel only notify + dirty bit; **`FUN_005307e0`** performs remove/toast on recv path. |
| 7 | C2S and S2C share opcode `0x20B2` | Same wire id, **different directions**; client send site ≠ client recv handler. |
| 8 | Ghidra “no callers” for `00911840` | Indirect UI dispatch; not evidence of dead code. |

---

## Residual (still open)

1. ~~Full `FUN_007fdfb0` Yes/No id assignment for abandon~~ **Sealed High (UF-009, 2026-07-29):** EAX Yes `0x4e46` / stack No `0x4e47` → `+0x498`/`+0x49c`. Optional residual: widget class source that binds OK vs Cancel children.
2. ~~Asm-level register contract for `FUN_0080b100`~~ **Sealed High (UF-012, 2026-07-29):** call site EAX=packet/ECX=client; FailMission + `FUN_005307e0` thiscall on `*(client+0xe98)`; missionId `[EAX+0x10]`. Scratch `tmp/a_0080b100.md`.
3. Dual review of `FUN_005307e0` end-quest teardown as its own unit (thiscall framing sealed; product name open).
4. Live abandon runtime observation (CE/packet).
5. Server AutoCore `HandleFailMission` completeness (product, not client RE).
6. `DAT_00d1ad10+0x10` / `FUN_0092fd00` secondary semantics (Tentative).
7. ~~FailMission Notify `this` / body / always-drain~~ **Sealed (2026-07-29 residual `aa_0052da30`):** `char+0x560` u32 vector push; drain is caller-owned (S2C/`006508d0` yes; Patrol/Kill/`0060e800` no). Scratch `tmp/a_0052da30.md`.

---

## Artifacts

### Dual reviews (this chain)
- `reviews/A_aa_0052da30_CVOGReaction_FailMission.md`
- `reviews/B_aa_0052da30_CVOGReaction_FailMission.md`
- `reviews/A_aa_0080b100_Client_RecvFailMission.md`
- `reviews/B_aa_0080b100_Client_RecvFailMission.md`
- `reviews/A_aa_00911840_Client_UiModalDispatch_AbandonConfirm.md`
- `reviews/B_aa_00911840_Client_UiModalDispatch_AbandonConfirm.md`
- `reviews/A_aa_007fdfb0_Client_ShowModalPrompt.md`
- `reviews/B_aa_007fdfb0_Client_ShowModalPrompt.md`

### Upstream duals
- `reviews/A_aa_008ae7c0_Client_MissionDialogHandleButton.md`
- `reviews/B_aa_008ae7c0_Client_MissionDialogHandleButton.md`
- `reviews/A_aa_004149d0_CVOGReaction_FailMissionNotify.md`

### Reconstruct / records
- `reconstructed-exact/CVOGReaction_FailMission.cpp`
- `reconstructed-exact/FUN_0080b100.cpp`
- `reconstructed-exact/Client_UiModalDispatch_AbandonConfirm.cpp`
- `reconstructed-exact/Client_ShowModalPrompt.cpp` (`aa_007fdfb0`)
- `reconstructed-exact/Client_MissionDialogHandleButton.cpp`
- `reconstructed-exact/Client_PacketDispatch.cpp` (`case 0x20b2`)
- `functions/aa_0052da30_*`, `aa_0080b100_*`, `aa_00911840_*`, `aa_008ae7c0_*`, `aa_007fdfb0_Client_ShowModalPrompt.md`

### System / product docs
- `systems/missions-progression.md`
- `docs/missionHandler.md` (`0x20B2` FailMission)
- `docs/missionState.md` (layout; abandon product notes may lag)

---

## AutoCore implementation contract (from chain)

```
// Client abandon
UI state2 → stash missionId → modal confirm
  Yes → C2S FailMissionPacket 0x20B2 (24 bytes: opcode, pad, coid64, missionId, pad)
  No  → close modal only
// Do not locally FailMission until S2C (or reaction)

// Server
on C2S 0x20B2: validate active quest → fail (not complete) → strip cargo →
  delete active DB row → S2C 0x20B2 to client (and any needed journal)

// Client S2C
on 0x20B2: FailMission(char, missionId); HandleEndQuest teardown
```
