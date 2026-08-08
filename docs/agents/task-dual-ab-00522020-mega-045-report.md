# Dual A/B report — MEGA-045 OWN-ONLY (`0x00522020`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-045**  
**Scope:** VA `0x00522020` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_function_by_address`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — inventory-transfer nested under equip/customize confirm `0x00941b20`.  
**Partition hint:** `Character_SelectInventoryGridByMode`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00522020` Character_SelectInventoryGridByMode_Inferred | **accept-with-gaps** — CF/ABI/RET4/mode{1,3,5}/offsets sealed; product English + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): mutator / cdecl / sequential modes 0-2 / mid-as-grid / multi-caller / Named_CalleeOf-as-product claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00522020` — sealed facts

1. **Body:** `0x00522020`–`0x0052205c` inclusive (**61 B** / `0x3D`); pad `CC` before sibling `FUN_00522060` @ `0x00522060`.
2. **ABI:** **ECX** = `Character*`; stack `int mode`; **EAX** = `InventoryGrid*` or 0; **`RET 4`** ×4 exits.
3. **Semantics:** pure **mode → grid** selector (leaf):
   - mode **1**: mid = `*(this+0x250)`; if non-null return `*(mid+0x2B0)` else **0** (cargo).
   - mode **3**: return `*(this+0xCBC)` (locker; cross-dual invType 3).
   - mode **5**: return `*(this+0xCE0)` (trade; cross-dual invType 5).
   - else: **0**.
   - Mode decode is subtract-chain (`SUB 1` / `SUB 2` / `SUB 2`), not a cmp table.
4. **Callers (1):** `FUN_00941b20` @ `0x00941bc7` (UNCONDITIONAL_CALL).
5. **Xrefs:** 1 UNCONDITIONAL_CALL.
6. **Callees:** none.
7. **Name:** `Character_SelectInventoryGridByMode_Inferred` (Ghidra `FUN_00522020`). Partition hint kept; `_Inferred` — no demangle. Scaffold `Named_CalleeOf_Client_ConfirmEquipOrCustomizeItem_00522020` **retired**.
8. **Decompile ≡ raw CF**; ABI/offsets sealed via `disassemble_function` + `read_memory`.

### Gaps

- Product method English / PDB.  
- Locker/trade labels depend on cross-dual invType map (offsets sealed locally).  
- Runtime / bit-exact / differential.  
- Parent equip confirm `FUN_00941b20` residual (not owned).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00522020_Character_SelectInventoryGridByMode_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00522020_Character_SelectInventoryGridByMode_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00522020_FUN_00522020.md` |
| Annotated | `docs/reconstruction/raw/aa_00522020_FUN_00522020.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_SelectInventoryGridByMode_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00522020.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_ConfirmEquipOrCustomizeItem_00522020.cpp` |
| Function | `docs/reconstruction/functions/aa_00522020_FUN_00522020.md` |
| Function named | `docs/reconstruction/functions/aa_00522020_Character_SelectInventoryGridByMode_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00941b20  Client_ConfirmEquipOrCustomizeItem  [residual parent]
  ├─ type==0xE town-only gate / strings
  ├─ type!=4 equipment path:
  │     FUN_00522020  Character_SelectInventoryGridByMode_Inferred  [OWN MEGA-045]
  │     FUN_004fabc0  resolve unequip/target item
  │     if item && grid==0 → FUN_007fc270(2)
  │     else footprint/place FUN_005715d0 / FUN_005714e0
  │          fail → "There is not enough space in your inventory for this equipment."
  ├─ bind/customize warning path FUN_00513fc0
  └─ FUN_00931440 commit

Cross-dual invType map (evidence):
  1 → *(*(char+0x250)+0x2B0)  cargo
  3 → *(char+0xCBC)           locker
  5 → *(char+0xCE0)           trade
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00522020-mega-045-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00522020` | Port as **mode→InventoryGrid* selector** on Character. **thiscall RET 4**. Modes **1/3/5** only; default null. Mode 1 null-checks mid before cargo load; 3/5 return raw field (may be null). Do **not** invent modes 2/4 here. |
| Pair with | residual equip confirm `00941b20`; dualed cargo consumers (`+0x250/+0x2B0`); DropResponse/Grab invType map. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent may lockstep later for this VA only:

- `VERIFICATION_MATRIX.md` / coverage ledgers — **not edited** here.  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/inventory-transfer` residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00522020`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name; machine twin `FUN_00522020.cpp` kept; Named_CalleeOf scaffold **retired**.  
- Odd behavior preserved: only mode 1 null-gates mid; 3/5 return possibly-null field loads; non-{1,3,5} → 0.  
- `_Inferred` — product demangle open. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
