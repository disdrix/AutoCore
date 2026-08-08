# Dual A/B report — WQ8R-I OWN `aa_0092adf0` + `aa_00941f50`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual WQ8R-I  
**Scope:** VAs `0x0092adf0`, `0x00941f50` only. Dual A/B + trio artifacts.  
**Role hint:** WQ-008 residual — UI/skill-adjacent inventory consumers.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` + `decompile_function` + `read_memory` + callers/callees/xrefs/assembly_context. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Name | Verdict |
|------|------|---------|
| `aa_0092adf0` | `TargetFilter_FindNearestWorldObjByCbidList_Inferred` | **accept-with-gaps** — nearest CBID scan + locker FindItemByCoid absence gate sealed; filter-class English residual |
| `aa_00941f50` | `Client_UseInventoryItemByCoid` | **accept-with-gaps** — cargo COID→Use path + ABI sealed; decompiler invalid-COID arm corrected; orphan UI owner residual |

**Terminal coverage:** false (no Launcher / runtime / bit-exact Confirmed).

---

## Shared context (not owned)

Both units call sealed **`InventoryGrid_FindItemByCoid`** (`aa_00571010`) but on **different grids**:

| Unit | Grid path | Role of Find |
|------|-----------|--------------|
| `0092adf0` | `*(character + 0xCBC)` **locker** (type-3) | **Gate:** continue only if COID **absent** |
| `00941f50` | `*( *(character+0x250) + 0x2B0 )` **cargo** (type-1) | **Lookup:** item pointer for Use |

Downstream of `00941f50`: sealed **`Client_UseInventoryItem_Inferred`** (`aa_00941d50`) — equip arm or skill-use **C2S 0x2045** size `0x28`.

Character access plate: **`client + 0xE98`** → local character (both units).

---

## VA `0x0092adf0` — sealed facts

1. **Body:** `0x0092adf0`–`0x0092af7a`.
2. **ABI:** **EDI = TargetFilterCtx\*** (`*ctx` = **Client\***); stack `float* origin`, `void** bestOut`, `float* bestDistSq`; **`ret 0x0C`**; returns **1**.
3. **Role:** Walk world-object list (TraversalLock `0x004294f0` + IterateNext `0x004022a0`). Keep candidates that:
   - are **not** the local player (`this-adjust(*(char+0x250))` ≠ `object+0xAC`);
   - have **no** locker hit: `InventoryGrid_FindItemByCoid(*(char+0xCBC), coidLo, coidHi) == NULL`;
   - match any CBID in **`ctx+0x2C[0 .. count)`** with **`count = ctx+0x28`**, against **`*(clonebase+0x34)`** (`clonebase = object+0xA8`).
4. **Nearest:** after object vtbl **`+0x144`**, squared distance on pos `+0x80/+0x84/+0x88` vs origin; if `< *bestDistSq` update dist + `*bestOut`.
5. **Unlock:** CS at `*(*(client+0xD34)+0x20)`; clear flag `+0x28`, `LeaveCriticalSection(+4)`.
6. **Caller (1):** `FUN_0092af80` when **`ctx+0x28 > 0`** (sibling arms: direct COID resolve, `0092abc0`, `0092a980`, `0092a760`). Grandcaller **`FUN_0092bf60`** feeds character position via vtbl `+0x1A0`.
7. **Name:** `TargetFilter_FindNearestWorldObjByCbidList_Inferred` (Ghidra `FUN_0092adf0`).
8. **Decompile ≡ image** for CF; **bytes win** on Find **ECX = *(char+0xCBC)**.

### Gaps

- Product/PDB name of filter context class (skill vs reaction vs interact).  
- Why **locker** grid for absence (vs cargo).  
- vtbl `+0x144` product English.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0092adf0_TargetFilter_FindNearestWorldObjByCbidList_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0092adf0_TargetFilter_FindNearestWorldObjByCbidList_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0092adf0_FUN_0092adf0.md` |
| Annotated | `docs/reconstruction/raw/aa_0092adf0_FUN_0092adf0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/TargetFilter_FindNearestWorldObjByCbidList_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0092adf0.cpp` |
| Function named | `docs/reconstruction/functions/aa_0092adf0_TargetFilter_FindNearestWorldObjByCbidList_Inferred.md` |
| Function FUN | `docs/reconstruction/functions/aa_0092adf0_FUN_0092adf0.md` |
| Scratch | `docs/reconstruction/tmp/a_0092adf0.md` |

---

## VA `0x00941f50` — sealed facts

1. **Body:** `0x00941f50`–`0x00941fa0` (pad `CC` after).
2. **ABI:** **EAX = Client\***; stack **`coidLo`**, **`coidHi`**, **`mode`**; **`ret 0x0C`**; **AL** bool.
3. **Role:** Cargo **FindItemByCoid** then **`Client_UseInventoryItem_Inferred(mode)`** (ESI=client, EDI=item).
4. **Guards → 0:** `*(client+0xE98)==0`, `*(char+0x250)==0`, or **`(coidLo & coidHi) == 0xFFFFFFFF`**.
5. **Grid:** `ECX = *(*(char+0x250) + 0x2B0)` — cargo **InventoryGrid\*** (type-1 plate).
6. **Decompiler correction:** invalid-COID arm is **`xor al,al` → return 0**, **not** `host & 0xffffff00`.
7. **No null check** on Find result before Use (gap).
8. **Sole static CALL:** `0x0086152C` in **orphan** code after `FUN_00861280` (Ghidra has no containing function). Call site: skill-bit gate on `cloneMeta+0x3F2`, COID from item, mode from `*(*(ui+0x56c)+4)`, **EAX = `DAT_00D1A840`**. On success: `FUN_007fbb70` UI closeout + vtbl `+0x33C`.
9. **Name:** `Client_UseInventoryItemByCoid` (Ghidra `FUN_00941f50`).
10. **Decompile ≡ image** for happy path; **bytes supersede** invalid-COID return.

### Gaps

- Full orphan UI function at ~`0x008612A8` (site sealed only).  
- Find-null safety.  
- PDB symbol.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00941f50_Client_UseInventoryItemByCoid.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00941f50_Client_UseInventoryItemByCoid.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00941f50_FUN_00941f50.md` |
| Annotated | `docs/reconstruction/raw/aa_00941f50_FUN_00941f50.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Client_UseInventoryItemByCoid.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00941f50.cpp` |
| Function named | `docs/reconstruction/functions/aa_00941f50_Client_UseInventoryItemByCoid.md` |
| Function FUN | `docs/reconstruction/functions/aa_00941f50_FUN_00941f50.md` |
| Scratch | `docs/reconstruction/tmp/a_00941f50.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0092adf0` target filter | Client nearest-object helper for multi-list filters: CBID whitelist + **locker absence** of object COID. Server authority for targeting should not assume this client filter; if parity needed, mirror locker check and CBID list, not cargo. |
| `00941f50` Use-by-COID | Client UI path: resolve **cargo** item by COID then same use pipeline as quickbar (`0x2045` / equip). Server must still authorize use; do not trust COID alone. Mode is pass-through to Use. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory (+ callers/callees/xrefs/assembly_context).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Trio updated: raw (append WQ8R-I), annotated, clean named + FUN twin, function records.  
- Names evidence-backed: Use-by-COID structural; TargetFilter **_Inferred** (no RTTI/string on leaf).
