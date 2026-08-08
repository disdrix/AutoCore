# Dual A/B report — MEGA-032 OWN-ONLY (`0x008e5990`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-032**  
**Scope:** VA `0x008e5990` (`aa_008e5990`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-032**.  
**Work item:** MEGA residual dual seal — inventory-transfer craft host bind of resolved object (`UI_CraftHost_BindResolvedObject`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_008e5990` UI_CraftHost_BindResolvedObject_Inferred | **accept-with-gaps** — CF/ABI/RET4/offsets/`.geo`/callers/599dd0 early-out sealed; product English + residual helpers open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): cdecl / TFID-resolver / always-refresh / mission-only scaffold claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x008e5990` — sealed facts

1. **Body:** `0x008e5990`–`0x008e5cd0` inclusive (**833 B** / `0x341`); pad `CC`×15 then parent `FUN_008e5ce0` @ `0x008e5ce0`.
2. **ABI:** **thiscall** **ECX** = craft/UI host*; stack **object*** (nullable); void; **`RET 4`** (`C2 04 00`).
3. **Semantics:** bind resolved object into craft host UI:
   - `host+0x7cc = object` (before optional orphan chrome teardown).
   - If `host+0x7d0 && host+0x520==0`: delete chrome (`vtbl[0](1)`); zero `+0x7d0`.
   - `FUN_008e2d60(host)`; clear **5** material slots (`+0x568` widgets / `+0x590` TFID pairs = `0xFFFFFFFF`).
   - Zero status blob `+0x7da..+0x7e0`.
   - **Null:** hide `+0x530`/`+0x54c`; optional detach `+0x520` vtbl+`0x44`; preview `+0x754` vtbl+`0x448`(`-1,-1`).
   - **Non-null:** show widgets; preview with `obj+0x160/0x164`; `operator_new(0x14c)` + `FUN_00764030` → `host+0x7d0`; name from type-`0xc` vtbl+`0x1c0` **or** template string via `FUN_00403450`; append **`".geo"`** (`DAT_00a28904`); `FUN_00989e00` + chrome vtbl+`0x5c`; attach `+0x520` vtbl+`0x40`(chrome,1); `FUN_007afe80`; recipe path via `FUN_00599dd0` / `FUN_008e5120` / up to 5× `FUN_008e5220` on `+0x61c`; `FUN_008e4ea0`.
   - Common: `FUN_008e55e0` + `FUN_008e47d0` — **skipped** when `FUN_00599dd0` returns 0.
4. **Classification:** worker.
5. **Xrefs:** 5 UNCONDITIONAL_CALL — `008e5cf9`, `008e5de8`, `008e80e5`, `0093a3aa`, `0093a3c5`.
6. **Callers:** `FUN_008e5ce0` (dualed TFID parent), `FUN_008e6b50`, `FUN_0093a330`.
7. **Callees:** `008e2d60`, `operator_new`, `00764030`, `00403450`, free, `00989e00`, `007afe80`, `00599dd0`, `008e5120`, `004ce940`, `008e5220`, `008e4ea0`, `008e55e0`, `008e47d0`, vtbls.
8. **Name:** `UI_CraftHost_BindResolvedObject_Inferred` (Ghidra `FUN_008e5990`). Product host class open → `_Inferred`.
9. **Retired scaffold:** `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen_008e5990`.
10. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context. Decompiler understates `FUN_00599dd0` / `FUN_008e5120` / `FUN_008e5220` ABIs — assembly authority used in annotated/clean.

### Gaps

- Product demangle for craft host / chrome / widget classes.  
- Residual helper English (not OWN).  
- Type-tag `0xc` product meaning.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008e5990_UI_CraftHost_BindResolvedObject_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_008e5990_UI_CraftHost_BindResolvedObject_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_008e5990_FUN_008e5990.md` |
| Annotated | `docs/reconstruction/raw/aa_008e5990_FUN_008e5990.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_CraftHost_BindResolvedObject_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008e5990.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen_008e5990.cpp` |
| Function | `docs/reconstruction/functions/aa_008e5990_FUN_008e5990.md` |
| Function named | `docs/reconstruction/functions/aa_008e5990_UI_CraftHost_BindResolvedObject_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_UI_CraftHost_BindObjectByTfid_Inferred  FUN_008e5ce0  [dualed WQ8R-H]
  ├─ invalid TFID (lo&hi == -1): FUN_008e5990(host, null)   [OWN MEGA-032]
  └─ resolved obj:             FUN_008e5990(host, obj)     [OWN MEGA-032]
        ├─ InventoryGrid_FindItemByCoid / equip TFID resolve (parent only)
        └─ (this unit does not resolve TFID)

FUN_008e6b50  (residual host op)
  └─ FUN_008e5990  rebind

FUN_0093a330  (residual panel select)
  └─ FUN_008e5990  ×2
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-008e5990-mega-032-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `008e5990` | Port as **craft-host bind of resolved object\***. **thiscall RET 4**: ECX=host, stack=object\|null. Store `host+0x7cc`; clear 5 material slots; null hides selection; non-null rebuilds name chrome with **`.geo`** suffix and optional recipe fill. If recipe query fails, **skip** host refresh tail. Do **not** implement TFID resolution here (parent `008e5ce0`). Keep distinct from Named_CalleeOf mission-refresh scaffold (retired). |
| Pair with | dualed parent `Client_UI_CraftHost_BindObjectByTfid_Inferred` `008e5ce0`; residual `008e6b50`, `0093a330`; residual helpers `008e2d60` / `008e5120` / `008e5220` / `008e4ea0` / `008e55e0` / `008e47d0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` inventory-transfer residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x008e5990`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name; machine twin `FUN_008e5990.cpp`; Named_CalleeOf scaffold **retired**.  
- Odd behavior preserved: store-before-teardown; 599dd0 fail skips `55e0`/`47d0`; type-`0xc` direct name vs template string path.  
- `_Inferred` (product host class unproven). Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
