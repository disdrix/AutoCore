# Dual A/B report — W18-C OWN `aa_005828b0` + `aa_0054b480`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W18-C  
**Scope:** OWN VAs only: `0x005828b0`, `0x0054b480`.  
**Excluded:** Parent ledgers (`WORK_QUEUE` / `RESUME` / `ACTIVE_WORK` / `CHANGE_LOG` / `COVERAGE_LEDGER`); Launcher.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Structural name | Verdict |
|------|-----------------|---------|
| `aa_0054b480` | `SkillDefMap_GetGlobal` | **accept** — 20 B leaf; lazy flag + `&DAT_00b04734` sealed; ≠ category CD map |
| `aa_005828b0` | `Object_LoadOrReplaceAnimSlot` | **accept-with-gaps** — thiscall `ret 0xC`, visual this, replace/0x78/load/add sealed; product English residual |

---

## `aa_0054b480` — sealed facts

1. **ABI:** leaf — no this, no stack args, pure **`ret`**. Body `0054b480`–`0054b493` (**20 B**).
2. **Algorithm:** if `DAT_00b04724 == 0` → `FUN_0054b2c0()`; always return **`&DAT_00b04734`**.
3. **Role:** global **SkillDefMap** header getter for `SkillDefMap_ExactFindByIntKey` (`0x00418890`) and skill-def walks.
4. **Distinct from** `Skill_GetCategoryCooldownMap` (entity `owner+0x6c`).
5. **Direct callers:** `Client_RecvSkillStatusEffect`, `FUN_005408f0`, `FUN_00541aa0`, `FUN_00542790`, site `0x0052a2ca`.
6. **Live decompile ≡ 2026-07-23 raw.**

---

## `aa_005828b0` — sealed facts

1. **ABI:** `__thiscall` — **ECX = visual host\***; stack `(slotIndex, path, flagByte)`; **`ret 0xC`**.
2. **Body:** `005828b0`–`005829c6` through `ret 0xC` (SEH frame).
3. **this seal:** call sites load ECX from **visual** fields (`event+0x10` / `+0x24`), not the special-event shell.
4. **Layout:** controller `this+0x24` (`vtbl+0x0C` add / `+0x10` remove); slots `this+0x2c + index*4`.
5. **CF:** replace existing → `new 0x78` + `FUN_0074ed90` → path resolve/`FUN_0074ee40` → duration `FUN_0079a110(DAT_00b04c74)` → `FUN_0074e910(0,dur)` → `slot+0x4c=flag` → Add → **return 1/0**.
6. **Callers (airlift trio):** `ClientSpecialEvent_TeleportIn_ctor`, `ClientSpecialEvent_TeleportOut_ctor`, `FUN_00979310` — slots 1/2/3, paths `obj_f_inc_mov_01_airlift_{at,aut,at2}.anm`, flag `0`.
7. **Live decompile ≡ 2026-07-23 raw CF.**

---

## Gaps

### `aa_0054b480`

1. Product/STL English type name.  
2. Dual of `FUN_0054b2c0` (not OWN).  
3. Runtime cold/warm golden.

### `aa_005828b0`

1. Product English: controller / 0x78 slot / flag `+0x4c`.  
2. Duration global (`DAT_00b04c74+0x238`) product meaning.  
3. Load-fail-after-store: raw leaves slot non-null — intentional?  
4. Duals of path/resource helpers (not OWN).  
5. Runtime / bit-exact.

---

## Files

### `aa_0054b480` `SkillDefMap_GetGlobal`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0054b480_SkillDefMap_GetGlobal.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0054b480_SkillDefMap_GetGlobal.md` |
| Function record | `docs/reconstruction/functions/aa_0054b480_SkillDefMap_GetGlobal.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0054b480_FUN_0054b480.md` (superseded) |
| Clean | `docs/reconstruction/reconstructed-exact/SkillDefMap_GetGlobal.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0054b480.cpp` |
| Raw | `docs/reconstruction/raw/aa_0054b480_FUN_0054b480.md` |
| Annotated | `docs/reconstruction/raw/aa_0054b480_FUN_0054b480.annotated.md` |

### `aa_005828b0` `Object_LoadOrReplaceAnimSlot`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005828b0_Object_LoadOrReplaceAnimSlot.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005828b0_Object_LoadOrReplaceAnimSlot.md` |
| Function record | `docs/reconstruction/functions/aa_005828b0_Object_LoadOrReplaceAnimSlot.md` |
| Scaffold record | `docs/reconstruction/functions/aa_005828b0_FUN_005828b0.md` (superseded) |
| Clean | `docs/reconstruction/reconstructed-exact/Object_LoadOrReplaceAnimSlot.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005828b0.cpp` |
| Raw | `docs/reconstruction/raw/aa_005828b0_FUN_005828b0.md` |
| Annotated | `docs/reconstruction/raw/aa_005828b0_FUN_005828b0.annotated.md` |

### This report

`docs/agents/task-dual-ab-w18c-005828b0-0054b480-report.md`

Absolute roots: `C:\Users\josh\Documents\GitHub\AutoCore\` + paths above.

---

## Tools used (both VAs)

- `ghidra-mcp__decompile_function`
- `ghidra-mcp__read_memory`
- `ghidra-mcp__get_function_by_address`
- `ghidra-mcp__get_function_callees` / `get_function_callers` / `get_xrefs_to`
- **Never** `disassemble_bytes`
- **Never** Launcher

---

## AutoCore impact

- **Skill def lookup:** always go through global header `DAT_00b04734` via this lazy getter before exact-find; do not confuse with entity category-cooldown maps.
- **Airlift / special-event FX:** anim slots attach to the **visual** (CBID `0xadc` path), slots 1–3, replace semantics, 0x78 objects — server does not need this client visual path for wire correctness.
