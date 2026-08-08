# Dual A/B report — MEGA-012 OWN-ONLY (`0x00513eb0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-012**  
**Scope:** VA `0x00513eb0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` + `get_function_xrefs` + `read_memory` + `get_assembly_context` + caller decompiles. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — partition row MEGA-012 / inventory-transfer residual under `Client_RecvInventoryDropResponse` (`0x00813730`).  
**Hint consumed:** `Item_TryConcatStackWithPeer` → **confirmed** as role name (concat string + CF).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00513eb0` Item_TryConcatStackWithPeer | **accept-with-gaps** — CF/ABI/RET4/CBID/concat role/callers sealed; field English `+0x180` / def`+0x4BC` open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): capacity-predicate / eligibility / `+0x4BA`-max / this=peer / always-SetQty / rem0→0 claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00513eb0` — sealed facts

1. **Body:** `0x00513eb0`–`0x00513f5e` inclusive (**175 B** / `0xAF`); pad `CC` before next @ `0x00513f60`.
2. **ABI:** **ECX** = destination item; stack peer item*; **AL** bool; **`RET 4`** ×3 exits.
3. **Semantics:** try-concat same-CBID peer into this:
   - Gate: peer non-null and `clonebase+0x34` CBID equal (`clonebase = item+0xA8`).
   - Optional: sum `u16` @ `item+0x180` under def limit @ `+0x4BC` (0 / 0xFFFF skip); fit → store+dirty+return; overflow → remainder (0→full limit) then continue.
   - Non-early: `SetQty(GetQty(peer)+GetQty(this))` via vtbl **`+0x25C` / `+0x260`**; dirty; return 1.
   - Fail → 0.
4. **Callees:** `FUN_00512670` (dirty `\| 0x20000` @ `+0x17C` + `+0xAC` chain); vtbl get/set qty.
5. **Callers (2):**  
   - `FUN_008134d0` TradeRemoveItem_Response @ `0x00813673`  
   - `Client_RecvInventoryDropResponse` @ `0x00813995` (concat branch; string *"Dropping failed trying to concatinate"*)
6. **Xrefs:** 2 UNCONDITIONAL_CALL.
7. **Name:** `Item_TryConcatStackWithPeer` (Ghidra `FUN_00513eb0`).  
   Retired: `Named_CalleeOf_Client_RecvInventoryDropResponse_00513eb0`.
8. **Decompile ≡ raw CF**; ABI/offsets sealed via `disassemble_function` + `read_memory` + call-site context.
9. **Distinct:** capacity max def **`+0x4BA`** (`Item_CanAcceptStackQty`); eligibility `Item_IsStackEligible`.

### Gaps

- Product English for `item+0x180` and def `+0x4BC`.  
- Product rationale for early fit path skipping SetQty (behavior sealed).  
- Runtime / bit-exact / differential / server parity.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00513eb0_Item_TryConcatStackWithPeer.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00513eb0_Item_TryConcatStackWithPeer.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00513eb0_FUN_00513eb0.md` |
| Annotated | `docs/reconstruction/raw/aa_00513eb0_FUN_00513eb0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Item_TryConcatStackWithPeer.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00513eb0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_RecvInventoryDropResponse_00513eb0.cpp` |
| Function | `docs/reconstruction/functions/aa_00513eb0_FUN_00513eb0.md` |
| Function named | `docs/reconstruction/functions/aa_00513eb0_Item_TryConcatStackWithPeer.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_RecvInventoryDropResponse  0x00813730  [parent plate; concat/split @ pkt+0x38]
  ├─ FUN_00571010  resolve existing by coid
  ├─ Item_TryConcatStackWithPeer  0x00513eb0  [OWN MEGA-012]  site 0x00813995
  │    └─ FUN_00512670  dirty flag 0x20000
  └─ fail string "Dropping failed trying to concatinate"

FUN_008134d0  TradeRemoveItem_Response
  ├─ FUN_005710c0  FindItemByCbid
  └─ Item_TryConcatStackWithPeer  site 0x00813673  [OWN MEGA-012]

Related (not OWN; dualed elsewhere):
  Item_CanAcceptStackQty   0x0040abf0  capacity predicate (def+0x4BA)
  Item_IsStackEligible     0x00513e70  eligibility flags
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00513eb0-mega-012-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00513eb0` | Port as **try-concat same-CBID peer into dest**. **thiscall RET 4**. Preserve early fit exit (no SetQty), remainder-wrap (0→limit), and limit @ def **`+0x4BC`** (not capacity `+0x4BA`). Dirty via flag `0x20000`. |
| Pair with | drop-response concat branch; trade-remove add-to-existing; capacity `0040abf0`; eligibility `00513e70`; dirty `00512670`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` inventory-transfer residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Not written by this agent.**

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00513eb0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + assembly context + parent decompiles. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name; FUN_* twin kept; Named_CalleeOf scaffold retired.  
- Odd behavior preserved: fit path skips SetQty; rem0 stores full limit; limit field ≠ capacity max.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
