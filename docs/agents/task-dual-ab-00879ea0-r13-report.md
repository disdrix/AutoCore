# Dual A/B report — R13-011 OWN-ONLY (`0x00879ea0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-011**  
**Scope:** VA `0x00879ea0` (`aa_00879ea0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-011**.  
**Work item:** Residual dual seal — inventory-transfer arena advanced host **CreateChildWidgets** (virtual).  
**Parent (score only):** `0x00756c90` `UI_Widget_MoveToFrontInParentGroup_Inferred` (dualed; **called** from this unit ×2 — not OWN).  
**Dual start:** 2686.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00879ea0` UI_ArenaAdvHost_CreateChildWidgets_Inferred | **accept-with-gaps** — thiscall RET0 / vtbl DATA / 56× `i_d_arena_adv_*` tree / tab pairing / tail sealed; product demangle + residual helpers + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): cdecl/stdcall-RET4 / direct CALL callers / inventory-wire / plate combo-only name / prefs-VA merge / Runtime Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00879ea0` — sealed facts

1. **Body:** `0x00879ea0`–`0x0087b38a` inclusive (**5355 B** / `0x14EB`); exit `ADD ESP,0x10; RET` (`83 C4 10 C3`).
2. **ABI:** **thiscall** **ECX = host*** (`MOV EBP,ECX`); no stack args; void; **`RET`** (`C3`).
3. **Dispatch:** sole xref **DATA** vtbl slot `0x00a59500` — virtual CreateChildWidgets*; no UNCONDITIONAL_CALL callers.
4. **Semantics:** arena advanced host child construction:
   - Clear **`host+0x524`** byte to 0.
   - `FUN_00792600(host)` prep.
   - Mass `operator_new` + ctor + `host.vtbl+0xa8` attach + `child.vtbl+0x28` load **`i_d_arena/i_d_arena_adv_*`** XML (**56** paths).
   - Buttons ids **0x9c41–0x9c45**, **0x9C40** close; combos **0x9c46/0x9c47**; tabs **0x9c48–0x9c4a**.
   - Tabs **`+0x630`/`+0x634`/`+0x638`**: console/tournament use dualed `FUN_00822cb0` + `FUN_00756c90`; advanced uses `FUN_00822cb0` + child `vtbl+0x94`.
   - Tail: residual **`FUN_00879240`**; host **`vtbl+0x448`**; host **`vtbl+0x34c`**.
5. **Classification:** worker (virtual).
6. **Callees:** `00792600`, `operator_new`, `007b5dd0`, `00864f20`, `0079c860`, `00795f20`, `008230b0`, `00822cb0`, `00756c90`, `0078e2f0`, `00879240`, vtbls.
7. **Name:** `UI_ArenaAdvHost_CreateChildWidgets_Inferred` (Ghidra `FUN_00879ea0`). Product host class open → `_Inferred`. Reject plate `UI_arena_adv_bg_combo_boxes` as function name.
8. **Decompile ≡ raw CF** for child tree; entry/exit/vtbl sealed via `read_memory` + body range.

### Gaps

- Product demangle for arena-adv host class (vtbl COL/RTTI).  
- Residual helper English (`00792600`, `00879240`, ctors, charset DAT_*).  
- Exact BL at each `00822cb0` site (force stack sealed; dualed helper uses ESI+BL).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00879ea0_UI_ArenaAdvHost_CreateChildWidgets_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00879ea0_UI_ArenaAdvHost_CreateChildWidgets_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00879ea0_FUN_00879ea0.md` |
| Annotated | `docs/reconstruction/raw/aa_00879ea0_FUN_00879ea0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_ArenaAdvHost_CreateChildWidgets_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00879ea0.cpp` |
| Function | `docs/reconstruction/functions/aa_00879ea0_FUN_00879ea0.md` |
| Function named | `docs/reconstruction/functions/aa_00879ea0_UI_ArenaAdvHost_CreateChildWidgets_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
vtbl[slot @ 0x00a59500]
  └─ FUN_00879ea0  UI_ArenaAdvHost_CreateChildWidgets_Inferred  [OWN R13-011]
        ├─ FUN_00792600  host prep (residual)
        ├─ many CNDUIWindow / button / edit / tab / combo children (i_d_arena_adv_*)
        ├─ FUN_00822cb0  UI_TabChrome_SetSelected_Inferred  [dualed R12-002]
        ├─ FUN_00756c90  UI_Widget_MoveToFrontInParentGroup_Inferred  [dualed R12-003; partition parent]
        └─ FUN_00879240  residual post-build

Related (not dualled here):
  FUN_008747e0  CDlgArenaPrefs_CreateChildWidgets  [dualed] — prefs XML family
  FUN_008e6b50  UI_CraftHost_CreateChildWidgets_Inferred  [dualed] — same role family
  Sibling residual hosts under parent 00756c90: 0086b9b0, 00878300, 00887780, 008b84a0, 008e1020
```

Partition parent `0x00756c90` is a dualed helper this unit **calls**, not a structural outer caller.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00879ea0-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00879ea0` | Port as **arena advanced host CreateChildWidgets\*** (virtual). **thiscall RET 0**: ECX=host. Build full `i_d_arena_adv_*` child tree; clear **`+0x524`**; tabs at **`+0x630/+0x634/+0x638`**; default advanced selected; console/tournament collapsed + move-to-front. Do **not** invent inventory C2S. |
| Pair with | dualed `00822cb0` / `00756c90`; dualed prefs `008747e0` (sibling role); residual prep `00792600` / post `00879240`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md` + rename-history
- `systems/inventory-transfer.md` residual tables
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER

**Name to register:** `UI_ArenaAdvHost_CreateChildWidgets_Inferred` @ `0x00879ea0` / `aa_00879ea0`.  
**Verdict:** **accept-with-gaps**; Terminal **false**.

---

## Process

- OWN VA only (`0x00879ea0`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses meaningful name; machine twin `FUN_00879ea0.cpp`.
- Odd behavior preserved: tab asymmetry; close at `+0x504`; null-tolerant new; radio group order.
- `_Inferred` (product host class unproven). Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
