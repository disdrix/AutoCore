# Review B (skeptical / adversarial): `aa_0082f510` UI_Window_OnCommand_Class8_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082f510` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ8R-F) |
| **Counterpart** | `reviews/A_aa_0082f510_UI_Window_OnCommand_Class8_Inferred.md` |
| **Verdict** | **accept-with-gaps** on ABI/case map/cast; **falsify** inventory-transfer and multi-skill claims |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Inventory transfer manager (WQ-008 queue alone) | Body has **no** grab/drop/equip packets; UI dialog + one skill cast | **Falsified** as inventory wire |
| 2 | Same as `Client_CastFirstHardpointSkillFlag200` | That unit walks HB list + flag 0x200; this hardcodes **0xED5** only | **Falsified** as same leaf |
| 3 | Multiple direct CALL callers | `get_function_callers` empty; only DATA vtable | **Falsified** as static multi-call |
| 4 | Casts skill from selected hardpoint | Case 1 is **literal 0xED5** | **Falsified** |
| 5 | `stdcall` / no this | `MOV EDI,ECX`; `RET 8` | **Falsified** |
| 6 | Always forwards to base | Class-8 handled arms return 1 without base; 70000 absorbs | **Falsified** as always-base |
| 7 | Dead gate applies to all cmdIds | Explicit `cmdId != 10` skip | **Falsified** |
| 8 | Decompiler omits ESI client → cast broken | `BE 40 A8 D1 00` before call | **Falsified** |
| 9 | Product name Confirmed | No RTTI/string on VA | **Open** — keep `_Inferred` |
| 10 | Case 2/3 are bugs / unreachable | Jump table entries exist; fallthrough return 1 | **Sealed** as intentional no-ops |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI ret 8 / thiscall | **High** | Wrong stack cleanup |
| Case 1 skill 0xED5 | **High** | Wrong skill on UI cmd |
| Class-8 case map | **High** | Wrong dialog toggles |
| DATA entry only | **High** | Missed static caller search |
| Window class product | **Open** | Mis-attributed UI surface |
| Dialog global identity | **Tentative** | Wrong menu port |
| Runtime | **Open** | |

---

## 3. Cross-check against raw + dual residual

`reviews/a_009418e0.md` already listed this unit as CastSkill caller:

| Caller | Setup | skill |
|---|---|---|
| `FUN_0082f510` @ `0x0082f6d1` | `MOV ESI,0x00d1a840`; `PUSH 0xed5` | **0xED5** |

Body re-decompile 2026-08-04 ≡ 2026-07-23 raw.  
Jump table dwords match case targets for 1..0xd.  
Base `FUN_0082c780` special-cases 70000 with classes {8,0xb,0xe} — consistent with this unit absorbing 70000 before forward when class-8 fallthrough would not apply the same way (this unit returns 1 for 70000 without calling base).

---

## 4. Naming attack

| Proposed | Status |
|---|---|
| `UI_Window_OnCommand_Class8_Inferred` | **Accept INFERRED** — thiscall OnCommand shape + class-8 switch |
| `Client_CastSkillFromQuickBarSlot` | **Reject** — callee only |
| `Client_SendInventory*` | **Reject** — no inventory wire |
| `Client_Input_PollBoundActions` | **Reject** — different entry; shares dialog patterns only |
| `FUN_0082f510` | Keep Ghidra residual synonym |

---

## 5. Surviving contract for AutoCore

```
// vtable OnCommand (class, id)
if deadVehicle && id!=10: hook+0x47c; return base(class,id)
if class==8:
  if id==1: CastSkill(globalClient, 0xED5); return 1
  // else dialog toggles / FUN_007fef20 indices — UI only
if id!=70000: return base(class,id)
return 1
// not an inventory transfer path
```

**Verdict:** **accept-with-gaps**.
