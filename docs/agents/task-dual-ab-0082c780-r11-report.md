# Dual A/B report — R11-027 OWN-ONLY (`0x0082c780`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R11-027**  
**Scope:** VA `0x0082c780` (`aa_0082c780`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r11_residual_partition_map.md` → **R11-027**.  
**Work item:** Residual dual seal — inventory-transfer partition host; UI OnCommand **base** (child of dualed Class8 `0x0082f510`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0082c780` UI_Window_OnCommand_Base_Inferred | **accept-with-gaps** — thiscall/`RET 8`, 70000×{8,0xb,0xe} dismiss, child `@+0x2b0` forward `vtbl+0x338`, DATA `@0x00a732a4` sealed; product English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): inventory-packet / Class8-merge / parent-bubble / always-dismiss / product-English claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0082c780` — sealed facts

1. **Body:** `0x0082c780`–`0x0082c7eb` inclusive last (**108 B** / `0x6C`); terminal **`C2 08 00`** ×3; pad `CC×4`.
2. **ABI:** `__thiscall` — **ECX=this**, stack **(cmdClass, cmdId)**; **RET 8**. EBX=cmdId, EDI=cmdClass, ESI=this.
3. **Semantics:**
   - If **cmdId == 70000** (`0x11170`) and **cmdClass ∈ {8, 0xb, 0xe}**: `EDI = this[+0x2b0]`; `FUN_0090d400()` (ESI=self, EDI=child); return **1**.
   - Else if `this.vtbl+0xd8()` and `this[+0x2b0] ≠ 0`: return **`child.vtbl+0x338(cmdClass, cmdId)`**.
   - Else return **0**.
4. **Callees:** direct `FUN_0090d400` only; indirect `vtbl+0xd8` / `vtbl+0x338`.
5. **Callers:** dualed `FUN_0082f510` (`UI_Window_OnCommand_Class8_Inferred`) @ `0082f558`/`0082f786`; residual `FUN_00830aa0` @ `00830b36`; plus CALL xrefs `0082de0c`/`00831272`/`00831821`/`00832b41` (unnamed enclosures).
6. **DATA:** vtable slot **`0x00a732a4`** = `0x0082c780`.
7. **Family:** base for dualed Class8 OnCommand; sibling residual `FUN_00830aa0` handles 0x11171..0x11173 then falls through. Shared UI OnCommand slot `vtbl+0x338` (modal/keybind duals).
8. **Name:** `UI_Window_OnCommand_Base_Inferred` (Ghidra `FUN_0082c780`). Product demangle open → `_Inferred`.
9. **Decompile ≡ raw CF**; EDI setup for dismiss sealed via disasm (decompiler omits).
10. **Partition parent** `0x0082f510` is live structural specialization caller (also wave score parent).

### Gaps

- Product / RTTI class for vtable `0x00a732a4`.  
- English for `vtbl+0xd8` predicate and `+0x2b0` child field.  
- Dual of `FUN_0090d400` / `FUN_00830aa0` (not OWN).  
- Unnamed CALL-site enclosure recovery.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0082c780_UI_Window_OnCommand_Base_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0082c780_UI_Window_OnCommand_Base_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0082c780_FUN_0082c780.md` |
| Annotated | `docs/reconstruction/raw/aa_0082c780_FUN_0082c780.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_Window_OnCommand_Base_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0082c780.cpp` |
| Function | `docs/reconstruction/functions/aa_0082c780_FUN_0082c780.md` |
| Function named | `docs/reconstruction/functions/aa_0082c780_UI_Window_OnCommand_Base_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
UI_Window_OnCommand_Class8_Inferred (0x0082f510)  [dualed WQ8R-F]
  ├─ dead-vehicle divert → FUN_0082c780
  ├─ class-8 cases 1..0xd (skill 0xED5, dialogs, …)
  └─ fallback cmdId≠70000 → FUN_0082c780

FUN_00830aa0  [residual sibling]
  ├─ (8, 0x11171/0x11172/0x11173) specials + FUN_0090d400
  └─ else → FUN_0082c780

FUN_0082c780  UI_Window_OnCommand_Base_Inferred  [OWN R11-027]
  ├─ (class∈{8,0xb,0xe}, id=70000) → FUN_0090d400 (ESI/EDI)
  └─ else → child(+0x2b0).vtbl+0x338(class,id) if vtbl+0xd8

DATA vtable 0x00a732a4 → 0x0082c780
```

Partition host "inventory-transfer" names the **host chain**, not this leaf's product role (UI OnCommand base).

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0082c780-r11-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0082c780` | Port as **base UI OnCommand**: thiscall + **RET 8**; **70000** dismiss for classes **{8,0xb,0xe}** via dismiss helper; else forward **child@+0x2b0** **vtbl+0x338**. |
| Distinct from | Class8 specialization `0082f510` (jump table / skill 0xED5); residual `00830aa0` (0x11171..73). |
| Pair with | dualed Class8 `0082f510`; residual dismiss `0090d400`; residual sibling `00830aa0`. |
| Not | Inventory grid transfer / packet move. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `UI_Window_OnCommand_Base_Inferred` @ `0x0082c780` / `aa_0082c780`.
- Verdict: **accept-with-gaps**; Terminal **false**.

---

## Process

- OWN VA only (`0x0082c780`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + callee decompile. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses meaningful name; machine ABI corrections (RET 8; EDI for dismiss; +0x2b0).
- Odd behavior preserved: 70000 with non-{8,0xb,0xe} class falls into forward path (not auto-dismiss); AL-only false return.
- `_Inferred` where English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
