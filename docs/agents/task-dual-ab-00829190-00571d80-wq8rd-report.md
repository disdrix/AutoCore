# Dual A/B report — WQ8R-D OWN-ONLY (`aa_00829190`, `aa_00571d80`)

**Date:** 2026-08-04  
**Agent:** WQ8R-D OWN-ONLY  
**Scope:** OWN ONLY VAs `0x00829190`, `0x00571d80`. Trio + clean + dual A/B.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `reviews/WAVE_2026-08-04_wq008_residual_partition_map.md` → WQ8R-D  
**Work item:** WQ-008 residual (inventory-transfer priority 94; high-mention undualed callees)

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00829190` UI_QuickBarSlotButton_CanCastBoundSkill_Inferred | **accept-with-gaps** — skill-slot readiness predicate; ABI/layout/validate{0,6}/resolve-vs-invalid sealed; product flag glosses open |
| `aa_00571d80` InventoryGrid_RemoveItemByCoid | **accept** — 39 B FindByCoid + RemoveItem(qty=1, forceFull) wrapper; thiscall `ret 0xC`; rel32 Confirmed |

---

## Sealed facts — `0x00829190`

1. **ABI:** `__thiscall` (Ghidra `__fastcall`) — **QuickBar slot-button in ECX**; **0** stack formals; plain **`RET`**; **bool AL**.

2. **Body:** `0x00829190`–`0x00829359` (**458 bytes** / `0x1CA`). Prologue: `push ebp; mov ebp,esp; and esp,0xFFFFFFF0; sub esp,0x3C`.

3. **Gates:**
   - `DAT_00d1b6d8 != 0`
   - `*(button+0x548) == 1` → **payloadKind = skill** (layout shared with dualed `UI_QuickBarSlotButton_AssignSkill_Inferred`)
   - `skill = *(button+0x558) != 0`

4. **Force-true:** if `DAT_00d1b644 != 0` and `*(char*)(DAT_00d1b644+0xf5) != 0` → **return true** (skip validate/resolve).

5. **Validate:** `Skill_LocalCastValidate(localChar, skipBusy=**1**, skill, 0)` — accepts return codes **0** or **6** only (6 = busy/active-use from LocalCastValidate residual). Bytes: `push 0; push esi; push 1; lea ecx,…; call 0x0051a790`.

6. **Target path:** if `(skill+0x614 & 0x800) == 0` → `Client_Skill_ResolveCastTarget` then `TFID_EqualsObjectId` vs **`DAT_00a1e810`**; return **true iff not equal**. Bit set → return true without resolve.

7. **Invalid sentinel:** `DAT_00a1e810` = `FF×8 00×8` — content-identical to `g_abTfidInvalid_A15870` @ `0x00a15870`, **different address**.

8. **Callees:** `Skill_LocalCastValidate` `0x0051a790`; `Client_Skill_ResolveCastTarget` `0x0093b3a0`; `TFID_EqualsObjectId` `0x00404aa0`; character vtbl `+0x19c` / `+0x1a0`.

9. **Caller:** sole xref **`0x00829883`** — `call 0x00829190` with `ECX=ESI` (button); near icon-state `+0x4fe`. Ghidra function boundary around site sparse.

10. **Name:** `UI_QuickBarSlotButton_CanCastBoundSkill_Inferred` — role-sealed **INFERRED**. Ghidra: `FUN_00829190`.

---

## Sealed facts — `0x00571d80`

1. **ABI:** **`__thiscall`** grid in **ECX**; stack `(coidLo, coidHi, forceFull)`; **`ret 0x0C`**; returns **`ItemObject*`** in EAX (decompiler `void` understates).

2. **Body:** `0x00571d80`–`0x00571da6` (**39 bytes**).

3. **Formula (exact):**
   ```
   item = InventoryGrid_FindItemByCoid(this, coidLo, coidHi);  // 0x00571010
   return InventoryGrid_RemoveItem(this, item, /*qty=*/1, forceFull); // 0x00571b80
   ```

4. **removeQty** is **hardcoded 1** (`push 1` @ `0x00571d90`) — not a formal.

5. **Rel32:** `00571010` and `00571b80` **Confirmed** via `read_memory`.

6. **Callers:** `Client_RecvInventoryUseItemResponse` (force 0); `FUN_00810170` (force 1×2); `FUN_00810670` (force from packet flag / 0); `FUN_004f8e00` (force 0).

7. **Name:** `InventoryGrid_RemoveItemByCoid` — composition of dualed FindByCoid + RemoveItem. Ghidra: `FUN_00571d80`.

---

## Gaps

### `00829190`
1. Product English for `skill+0x614` bit **0x800** and `DAT_00d1b644+0xf5`.  
2. Owning function label for call site `0x00829883` (code present; Ghidra FUN gap).  
3. Why UI skipBusy=1 vs many cast senders using 0.  
4. Runtime / bit-exact / differential — open.

### `00571d80`
1. PDB English name.  
2. Per-caller forceFull product table beyond bool-like sites.  
3. Double-call pattern residual in `FUN_00810170` (caller scope).  
4. Runtime / bit-exact / differential — open.

---

## Dual A/B

| VA | Review A | Review B | Verdict |
|---|---|---|---|
| `0x00829190` | `reviews/A_aa_00829190_UI_QuickBarSlotButton_CanCastBoundSkill_Inferred.md` | `reviews/B_aa_00829190_UI_QuickBarSlotButton_CanCastBoundSkill_Inferred.md` | **accept-with-gaps** |
| `0x00571d80` | `reviews/A_aa_00571d80_InventoryGrid_RemoveItemByCoid.md` | `reviews/B_aa_00571d80_InventoryGrid_RemoveItemByCoid.md` | **accept** |

---

## Files

### `aa_00829190`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00829190_UI_QuickBarSlotButton_CanCastBoundSkill_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00829190_UI_QuickBarSlotButton_CanCastBoundSkill_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00829190_UI_QuickBarSlotButton_CanCastBoundSkill_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00829190_FUN_00829190.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_QuickBarSlotButton_CanCastBoundSkill_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00829190.cpp` |
| Raw (authoritative body + WQ8R-D append) | `docs/reconstruction/raw/aa_00829190_FUN_00829190.md` |
| Annotated | `docs/reconstruction/raw/aa_00829190_FUN_00829190.annotated.md` |

### `aa_00571d80`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00571d80_InventoryGrid_RemoveItemByCoid.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00571d80_InventoryGrid_RemoveItemByCoid.md` |
| Function record | `docs/reconstruction/functions/aa_00571d80_InventoryGrid_RemoveItemByCoid.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00571d80_FUN_00571d80.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_RemoveItemByCoid.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00571d80.cpp` |
| Raw (authoritative body + WQ8R-D append) | `docs/reconstruction/raw/aa_00571d80_FUN_00571d80.md` |
| Annotated | `docs/reconstruction/raw/aa_00571d80_FUN_00571d80.annotated.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00829190-00571d80-wq8rd-report.md` |

---

## AutoCore impact

### `00829190`
- QuickBar skill **UI readiness** is **not** the same as `Client_QuickBarActivateSkillSlot` / `Client_RequestCastSkill` (those pack 0x2030).
- Port must treat **busy (code 6)** as still UI-ready when skipBusy=1 at this site.
- Target-less skills (`+0x614 & 0x800`) skip resolve; others require resolved TFID ≠ invalid.
- Do not conflate invalid sentinel **pointer** `DAT_00a1e810` with `g_abTfidInvalid_A15870` (content-equal only).

### `00571d80`
- Prefer this helper when packet COID → grid remove with **qty=1**; peel vs full is owned by `InventoryGrid_RemoveItem` + forceFull.
- Preserve **thiscall + ret 0xC** and **Find then Remove** order; null Find is safe (Remove null-gates).
- Inventory use/sell/loot paths share this composition — do not reimplement COID walk ad hoc.

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x00571010` | `InventoryGrid_FindItemByCoid` (dualed) |
| `0x00571b80` | `InventoryGrid_RemoveItem` (dualed) |
| `0x00571db0` | sibling grid helper (WQ8R-G owned) |
| `0x00826860` | `UI_QuickBarSlotButton_AssignSkill_Inferred` (layout source) |
| `0x0051a790` | `Skill_LocalCastValidate` |
| `0x0093b3a0` | `Client_Skill_ResolveCastTarget` |
| `0x00404aa0` | `TFID_EqualsObjectId` |
| `0x00921b50` | `Client_QuickBarActivateSkillSlot` (send path; not this) |
| `0x00810280` | `Client_RecvInventoryUseItemResponse` (caller of RemoveByCoid) |

---

## Parent merge notes (not performed)

Per partition rules, parent must later lockstep: VERIFICATION_MATRIX rows, NAMING_REGISTRY, systems notes, WORK_QUEUE/RESUME/CHANGE_LOG/progress.json. **This agent did not edit parent ledgers.**
