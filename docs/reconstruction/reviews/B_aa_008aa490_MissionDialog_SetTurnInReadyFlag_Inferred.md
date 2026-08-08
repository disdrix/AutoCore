# Review B (skeptical / adversarial): `aa_008aa490` MissionDialog_SetTurnInReadyFlag_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aa490` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-078) |
| **Counterpart** | `reviews/A_aa_008aa490_MissionDialog_SetTurnInReadyFlag_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This **presents** the NPC mission dialog | **Falsified** — no panel open / no `FUN_007fef20` / no `FUN_0092f090`; parent continues after return |
| 2 | This is `Client_NpcDialog_PrepareResponseOpcode` | **Falsified** — sibling call @ `00943a60` is `0x008abd70`; this unit only stores flag + optional vcall |
| 3 | ECX-thiscall host | **Falsified** — body uses **EAX** as host base; ECX only loads child from `+0x6e8`; caller `MOV EAX,EBX` |
| 4 | `in_EAX` is unused phantom garbage | **Falsified** — first load is `[EAX+0x6e8]`; store `[EAX+0x580]`; call site seeds EAX |
| 5 | Decompiler `__fastcall(param_1,param_2)` stack/ECX formals | **Falsified** — bare `C3`; no stack args; `param_1` empty storage |
| 6 | Always calls child vtbl | **Falsified** — `TEST ECX,ECX` / `JZ` skips when `+0x6e8` null; flag store still happens |
| 7 | Clears response slots / TFIDs | **Falsified** — no loop; no `+0x518` / `+0x708`; that is `FUN_008aa560` / `FUN_008aa510` family |
| 8 | Multi-mission panel fill | **Falsified** — `FUN_008ab550` is next residual; this unit is 23 B leaf |
| 9 | Scaffold "CalleeOf ShowNpc" is product role | **Falsified** — parent-seed only; sealed role is flag apply + optional notify |
| 10 | Multiple static callers | **Falsified** — single xref `00943a57` UNCONDITIONAL_CALL |
| 11 | Stack args / `RET 4` | **Falsified** — bare `C3`; flag in **DL** |
| 12 | Classification "leaf" means no side effects | **Falsified** — leaf = no static callees; writes `+0x580` and may vcall child |
| 13 | Flag is mode/`param_3` from ShowNpc | **Falsified** — call site loads DL from `[ESP+0x1c]` after `FUN_0052b420` AL gate, not from ShowNpc `param_3` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI EAX-host / DL-flag / bare RET | **High** | Wrong convention → crash / wrong object |
| Offsets +0x580 / +0x6e8 | **High** | Corrupt wrong fields |
| Optional vtbl[+4] notify | **High** | Miss UI sync |
| Sole caller pre-present order | **High** | Wrong lifecycle |
| Flag = turn-in readiness (role) | **High** | Miswire readiness source |
| Product English | **Low** | Naming only |
| EDX upper-byte contract | **Med** | Child may read full dword |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

| Check | Result |
|---|---|
| Live decompile 2026-08-05 ≡ raw 2026-07-23 CF | **Match** |
| Body size 23 B to RET | **Match** (`0x008aa490`–`0x008aa4a6`) |
| Hex vs disasm mnemonics | **Match** (`8B88E8060000…C3`) |
| Caller seeds EAX=EBX, DL=flag | **Match** (`00943a51`–`00943a57`) |
| Parent clean documents 52b420 as turn-in readiness | **Match** (`Client_ShowNpcMissionDialogUI.cpp`) |
| Sibling pad then `FUN_008aa4b0` @ `008aa4b0` | **Match** (`CC` pad in `read_memory`) |

---

## 4. Surviving contract for AutoCore

```
// After turn-in readiness probe, before response opcode / panel fill:
//   EAX = missionDialogHost;   // client+0x1058
//   DL  = turnInReady;         // 0/1 from FUN_0052b420 path
//   MissionDialog_SetTurnInReadyFlag_Inferred();
//     → dialog[+0x580] = DL
//     → if dialog[+0x6e8]: child.vtbl[+4](EDX)
// Do NOT treat as present, PrepareResponseOpcode, slot clear, or ECX-thiscall.
```

---

## 5. Verdict

Adversarial attacks on present/opcode/ECX/slot-clear/multi-caller/scaffold-product claims **fail**. Residual product English + EDX width only → **accept-with-gaps**. Terminal **false**.
