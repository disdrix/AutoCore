# Review B (skeptical / adversarial): `aa_0092a590` Tracker_SetActiveMissionObjective_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092a590` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY MEGA-010) |
| **Counterpart** | `reviews/A_aa_0092a590_Tracker_SetActiveMissionObjective_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the full mission-bind path (hash gate + UI) | **Falsified** — sole body is tracker write; gate `FUN_0059dc50` and UI `vtbl+0x3d8/+0x448` live in parent `0x0092fd00` |
| 2 | Pure ECX-thiscall with stack missionId | **Falsified** — no stack formals; `PUSH EAX` only for hash key; missionId stays in **EAX** at entry; bare `RET` not `RET 4` |
| 3 | EDI-only / unaff_EDI phantom this | **Falsified** — entry `MOV EDI,ECX`; parent seeds **ECX**=`[client+0x4d0]` then `MOV EAX,EBX` |
| 4 | Decompiler `void` / `undefined` return is correct | **Falsified** — three exits set **AL** (`B0 01` / `32 C0`); parent `MOV BL,AL` |
| 5 | `in_EAX` is garbage / undefined register | **Falsified** — parent preserves missionId in EBX and reloads `MOV EAX,EBX` immediately before CALL |
| 6 | Zero-id path returns failure | **Falsified** — id==0 clears then `MOV AL,1` |
| 7 | Hash miss leaves stale `+0x10` id | **Falsified** — fail path zeros `+0x10` and `+0xc` after clear helpers |
| 8 | Clears via standard thiscall only | **Falsified** — `FUN_0092a3d0` uses **EDI**; `FUN_00929c00` uses **EAX** (`MOV EAX,EDI` before call) |
| 9 | Multiple static callers | **Falsified** — single xref `0092fd4c` UNCONDITIONAL_CALL |
| 10 | Scaffold "CalleeOf MissionDialogHandleButton" is product role | **Falsified** — structural role is tracker bind/clear; dialog is one of many parent callers, not this unit's body |
| 11 | Writes character hash / mutates mission journal | **Falsified** — only **reads** `char+0x548` via lookup; mutations are tracker fields + clear helpers on tracker |
| 12 | Same as parent `Client_TryBindActiveMissionTracker` | **Falsified** — parent adds idle short-circuit, eligibility gate, UI refresh; this unit is the tracker write leaf |
| 13 | `param_1[1]` bind flag is dword | **Falsified** — `C6 47 04 01` is **byte** at `+0x4` (decompiler `param_1+1` is dword-index of byte store) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI ECX=tracker / EAX=id / AL=bool / bare RET | **High** | Wrong call convention → crash / bad id |
| Offsets +0x10 / +0xc / +0x6 / +0x4 | **High** | Wrong tracker state |
| Host `*tracker` → `+0xe98` → hash `+0x548` | **High** | Wrong lookup root |
| Objective stamp `**(node+0x14c)` | **High** | Wrong objective payload |
| Clear helpers EDI/EAX custom | **High** | Wrong clear ABI |
| Sole-caller binder role | **High** | Wrong lifecycle placement |
| Product tracker/objective English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

| Check | Result |
|---|---|
| Live decompile 2026-08-05 ≡ raw 2026-07-23 CF | **Match** |
| Body size 111 B to final RET | **Match** (`0x0092a590`–`0x0092a5fe`) |
| Hex vs disasm mnemonics | **Match** (`56 57 8BF9…5F32C05EC3`) |
| Parent seeds ECX/EAX | **Match** (`MOV ECX,[EDI+0x4d0]` / `MOV EAX,EBX` / `CALL`) |
| Sibling getter @ `0x0092fd90` uses same `+0x10` / hash / `+0x14c` | **Match** (objective-head interpretation) |
| Analyze: 1 caller, 3 callees, 3 returns, 0 loops | **Match** |

---

## 4. Surviving contract for AutoCore

```
// After eligibility (parent):
//   ECX = client->tracker_4d0;
//   EAX = missionId;           // 0 = clear
//   AL  = Tracker_SetActiveMissionObjective_Inferred();
// On success parent may refresh mission UI root client+0x107c.
// Do NOT treat as full bind path, stack thiscall, or multi-caller dialog leaf.
// Clear helpers: FUN_0092a3d0 (EDI), FUN_00929c00 (EAX) — keep custom ABI.
```

---

## 5. Verdict

Adversarial attacks on full-bind-merge / stack-thiscall / void-return / multi-caller / scaffold-product / stale-id-on-miss claims **fail**. Residual product English only → **accept-with-gaps**. Terminal **false**.
