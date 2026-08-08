# Review A (reconstruction fidelity): `aa_0082f510` UI_Window_OnCommand_Class8_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082f510` |
| **VA** | `0x0082f510` |
| **Canonical name** | `UI_Window_OnCommand_Class8_Inferred` |
| **Review date** | `2026-08-04` (WQ8R-F dual seal) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0082f510_UI_Window_OnCommand_Class8_Inferred.md` |
| **System** | UI command dispatch / skills |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, xrefs/callers/callees (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

UI window **OnCommand** specialization for **cmdClass == 8**: jump-table dispatch of cmdId **1..0xd**, including hardcoded skill cast **0xED5** (case 1), dialog toggles via `FUN_007fef20` / dialog globals, dead-vehicle divert to base `FUN_0082c780`, and sentinel **70000** absorb.

WQ-008 residual: undualed caller of sealed `Client_CastSkillFromQuickBarSlot` (skill **0xED5**).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | Ghidra `decompile_function(0x0082f510)` 2026-08-04 ≡ raw |
| Body bytes | `read_memory` 640 B; `RET 8`; case1 `PUSH 0xED5; MOV ESI,0x00d1a840` |
| Jump table | `read_memory` `@0x0082f794` 13 dwords |
| Callers | **0** CALL; DATA `@0x00a72514` |
| Callees | CastSkill, FUN_0082c780, FUN_007fef20×, FUN_007fca10, dialog helpers |
| Raw / annotated / clean / records | WQ8R-F trio refresh |

**Not performed:** `disassemble_bytes`; Launcher; parent ledgers; full RTTI of vtable owner.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Live decompile ≡ frozen raw | **Confirmed** | 2026-08-04 |
| `__thiscall` + two stack args + `RET 8` | **Confirmed** | epilogue `C2 08 00` |
| Dead-vehicle gate cmdId≠10 + vtbl`+0x194` | **Confirmed** | decomp + imm `0x194` |
| this vtbl`+0x47c` before base forward | **Confirmed** | imm `0x47c` |
| cmdClass==8 switch cases 1..0xd | **Confirmed** | jump table + decomp |
| Case 1 skill **0xED5** + client ESI | **Confirmed** | `68 D5 0E 00 00` / `BE 40 A8 D1 00` |
| Dialog cases 4/5/0xb use globals + vtbl`+0x3d8` | **Confirmed** | decomp |
| `FUN_007fef20` indices 0,1,2,3,4,5,0x11,0x12,0x13,0x29 | **Confirmed** | push immediates |
| Fallback cmdId≠70000 → `FUN_0082c780` | **Confirmed** | `CMP ESI,0x11170` |
| DATA-only entry `0x00a72514` | **Confirmed** | xrefs |
| Product window class name | **Open** | no RTTI seal this pass |
| Skill 0xED5 product English | **Open** | |
| Runtime / bit-exact | **Open** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Dead-vehicle early divert | **Yes** |
| Class-8 jump table arms | **Yes** |
| Case 1 cast 0xED5 | **Yes** |
| Dialog toggle arms | **Yes** |
| Default / 70000 absorb | **Yes** |
| No invented inventory packets | **Yes** |

### Sealed CF sketch

```
UI_Window_OnCommand_Class8_Inferred(this, cmdClass, cmdId):
  if cmdId!=10 && player && vehicle && vehicle.IsDead(vtbl+0x194):
    this.vtbl+0x47c(); return Base_OnCommand(this, class, id)  // FUN_0082c780
  if cmdClass==8:
    switch cmdId:
      1: CastSkillFromQuickBarSlot(client, 0xED5); return 1
      2..3: return 1
      4/5/0xb: dialog show/hide families
      6..10,0xc,0xd: FUN_007fef20(index, …); return 1 (mostly)
  if cmdId!=70000: return Base_OnCommand(...)
  return 1
```

---

## 5. Gaps

1. Product / RTTI name of window class owning vtable slot `0x00a72514`.
2. Skill data name for id **0xED5** (3797).
3. Product names for `DAT_00d1b870/874/880` and each `FUN_007fef20` dialog index.
4. Why cmdId **10** is exempt from dead-vehicle divert.
5. Runtime command capture; bit-exact image.

**Verdict:** **accept-with-gaps** — ABI, case map, cast imm, DATA entry sealed; product labels residual.
