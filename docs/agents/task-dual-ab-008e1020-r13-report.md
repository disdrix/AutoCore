# Dual A/B report — R13-014 OWN-ONLY (`0x008e1020`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-014**  
**Scope:** VA `0x008e1020` (`aa_008e1020`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including parent dual `0x00756c90` re-dual, craft twin `0x008e6b50`, residual helpers).  
**Ghidra:** `decompile_function` (FAILED) + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-014**.  
**System:** inventory-transfer (UI chrome CreateChildWidgets; no inventory wire).  
**Parent dual:** `0x00756c90` UI_Widget_MoveToFrontInParentGroup_Inferred (R12-003; residual caller of that dual).  
**Dual start:** 2686.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_008e1020` UI_DtHost_CreateChildWidgets_Inferred | **accept-with-gaps** — thiscall RET0 / vtbl DATA / `i_d_dt_2d_*` tree / slots / tab pair + dualed helpers sealed; product demangle + residual helpers + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): inventory-wire / craft-or-trade merge / stack-arg RET4 / direct CALL callers / empty-body-from-decompile-fail claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x008e1020` — sealed facts

1. **Body:** `0x008e1020`–`0x008e17be` inclusive (**1951 B** / `0x79F`); exit `POP EDI/ESI/EBP/EBX; MOV FS:[0],ECX; ADD ESP,0x18; RET` (`… 83 C4 18 C3`).
2. **ABI:** **thiscall** **ECX = host*** (`MOV EBP,ECX`); no stack args; void; **`RET`** (`C3`).
3. **Dispatch:** sole xref **DATA** vtbl slot `0x00a3c3a0` — virtual CreateChildWidgets*; no UNCONDITIONAL_CALL callers.
4. **Decompile:** **FAILED** (`Low-level Error: Overlapping input varnodes`). Scaffold raw error preserved; **assembly is sole CF authority**.
5. **Semantics:** dt 2d host child construction:
   - `FUN_00792600(host)` prep.
   - Mass `operator_new` + ctor + `host.vtbl+0xa8` attach + `child.vtbl+0x28` load `i_d_dt_2d_*` XML + optional alpha `vtbl+0xfc(1, 0.5f)`.
   - Slot map: `+0x520` bg_fill, `+0x524` fx (0x4BC/`00864f20`), `+0x540/+0x544` frame instructions, `+0x548` frame_image, `+0x52c` bg_image, `+0x528` bg_texture, `+0x530` title **then overwritten by** icon, icon_cover via `host.vtbl+0x404`, `+0x538/+0x53c` instructions, `+0x504` close id `0x9c40`.
   - Tabs: `+0x54c` crafting id `0x9c41` (BL=0 + dualed `00822cb0` + dualed `00756c90` MoveToFront); `+0x550` disciplines id `0x9c42` (BL=1 + `vtbl+0x94`).
   - Optional `DAT_00d1b8a8` path → `host.vtbl+0x114` + `FUN_007fca10`.
   - Tail: `host.vtbl+0x448()`; `host.vtbl+0x34c()`.
6. **Classification:** worker (virtual).
7. **Callees:** `00792600`, `operator_new` (`00489892`), `007b5dd0`, `00864f20`, `0079c860`, `008230b0`, dualed `00822cb0`, dualed `00756c90`, `007fca10`, vtbls.
8. **Name:** `UI_DtHost_CreateChildWidgets_Inferred` (Ghidra `FUN_008e1020`). Product host class open → `_Inferred`.
9. **Scaffold:** raw decompile-error body preserved; R13-014 section **appended only**.

### Gaps

- Product demangle for dt host class (vtbl COL/RTTI).  
- Residual helper English (`00792600`, `008230b0`, `0079c860`, `00864f20`, `007fca10`).  
- Product policy for `+0x530` title→icon overwrite and icon_cover `vtbl+0x404`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008e1020_UI_DtHost_CreateChildWidgets_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_008e1020_UI_DtHost_CreateChildWidgets_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_008e1020_FUN_008e1020.md` |
| Annotated | `docs/reconstruction/raw/aa_008e1020_FUN_008e1020.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_DtHost_CreateChildWidgets_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008e1020.cpp` |
| Function | `docs/reconstruction/functions/aa_008e1020_FUN_008e1020.md` |
| Function named | `docs/reconstruction/functions/aa_008e1020_UI_DtHost_CreateChildWidgets_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
vtbl[slot @ 0x00a3c3a0]
  └─ FUN_008e1020  UI_DtHost_CreateChildWidgets_Inferred  [OWN R13-014]
        ├─ FUN_00792600  host prep  [residual]
        ├─ CNDUIWindow / fx / button children (i_d_dt_2d_*)
        ├─ FUN_008230b0  tab ctor  [residual]
        ├─ FUN_00822cb0  UI_TabChrome_SetSelected_Inferred  [dualed R12-002]
        └─ FUN_00756c90  UI_Widget_MoveToFrontInParentGroup_Inferred  [dualed R12-003 / parent]

Sibling CreateChildWidgets families (not dualled here):
  FUN_008e6b50  UI_CraftHost_CreateChildWidgets_Inferred  [dualed R11-036] — i_d_craft_2d_*
  FUN_008847f0  CDlgTrade2d_CreateChildWidgets            [dualed] — trade grids
```

Partition parent `0x00756c90` is the dualed MoveToFront helper this unit **calls** for the collapsed crafting tab (residual discovery edge), not a structural outer caller.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-008e1020-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `008e1020` | Port as **virtual CreateChildWidgets** for **dt 2d host** (`i_d_dt_2d_*`). **`__thiscall`** ECX=host; **RET 0**. Vtbl DATA `0x00a3c3a0`. |
| Do **not** | Treat as inventory C2S; merge with craft `008e6b50` or trade `008847f0`; invent product demangle; claim Runtime Confirmed; trust failed decompiler as empty body. |
| Pair with | dualed tab set-selected `00822cb0`; dualed MoveToFront `00756c90`; dualed craft CreateChildWidgets `008e6b50` (family peer); residual prep `00792600` / tab ctor `008230b0`. |
| Naming caution | **Not** craft host. **Not** trade dialog. **Not** pure MoveToFront. Product class English open → `_Inferred` only. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/inventory-transfer.md` residual tables (UI chrome CreateChildWidgets — not inventory wire)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x008e1020`); no Launcher; no parent ledger edits.  
- Seal tools: decompile (failed — documented) + analyze_function_complete + disassemble_function + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful `_Inferred` name; machine ABI corrections (thiscall RET 0; assembly authority past decompile fail).  
- Odd behavior preserved: decompiler hard-fail; `+0x530` title→icon overwrite; asymmetric tab select/MoveToFront.  
- `_Inferred` where English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
