# Dual A/B report — W28-N OWN-ONLY (`0x005b3b20`, `0x005ae0b0`)

**Date:** 2026-07-29  
**Agent:** W28-N OWN-ONLY  
**Scope:** OWN ONLY VAs `0x005b3b20`, `0x005ae0b0`. Dual A/B + artifacts.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave28_partition_map.md`  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / xrefs / complete analysis). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_005b3b20` Obj_BodyDtor_SetVtbl_DestroyStdListAt10 | **accept-with-gaps** — vtbl + `this+0x10` list destroy tail sealed; product class open |
| `aa_005ae0b0` StdTree_Inc_Val12 | **accept** — Val12 iterator++ / `_Tree::_Inc`; leaf; 9 erase consumers |

---

## `aa_005b3b20` — Obj_BodyDtor_SetVtbl_DestroyStdListAt10

### Sealed facts

1. **Body:** `0x005b3b20`–`0x005b3b2e` exclusive (**14** B / `0x0E`). Final rel32 **JMP**; pad `CC`.

2. **ABI:** ECX=`this`; void; **no local RET** (tail into list destroy).

3. **Algorithm (bytes authority):**
   ```
   *this = PTR_FUN_009d95b4
   ECX = this + 0x10
   jmp StdList_Destroy_FreeHead   // 0x00497360
   ```

4. **Decompile gap:** Ghidra shows CALL `FUN_00497360` without `ADD ECX,0x10` and without tail — **bytes win**.

5. **Vtbl:** `0x009d95b4[0]` = `0x005b44d0` (scalar-deleting dtor). Adjacent rdata is shader text, not class name.

6. **Callers (1):** `FUN_005b44d0` only. Ctors `FUN_005b3f60` / `FUN_005b4260` install same vtbl and list at `+0x10`.

7. **Name:** structural `Obj_BodyDtor_SetVtbl_DestroyStdListAt10`. No product plate.

### Gaps

1. Product English class name.  
2. Host fields outside list member (ctor-owned).  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_005b3b20_Obj_BodyDtor_SetVtbl_DestroyStdListAt10.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_005b3b20_Obj_BodyDtor_SetVtbl_DestroyStdListAt10.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005b3b20_Obj_BodyDtor_SetVtbl_DestroyStdListAt10.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005b3b20_Obj_BodyDtor_SetVtbl_DestroyStdListAt10.md` |
| Function record | `docs/reconstruction/functions/aa_005b3b20_Obj_BodyDtor_SetVtbl_DestroyStdListAt10.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_005b3b20_FUN_005b3b20.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Obj_BodyDtor_SetVtbl_DestroyStdListAt10.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005b3b20.cpp` |
| Raw | `docs/reconstruction/raw/aa_005b3b20_FUN_005b3b20.md` |
| Annotated | `docs/reconstruction/raw/aa_005b3b20_FUN_005b3b20.annotated.md` |

---

## `aa_005ae0b0` — StdTree_Inc_Val12

### Sealed facts

1. **Body:** `0x005ae0b0`–`0x005ae0fb` exclusive (**75** B / `0x4B`). Final **`C3`**; pad `CC`.

2. **ABI:** ECX = `node**` (iterator); bare **`RET`**; void. Leaf (no callees).

3. **Algorithm:**
   ```
   if (*it)->isnil: return
   if right not nil: *it = leftmost(right)
   else: walk parents while coming from right; *it = parent
   ```

4. **Layout:** Val12 — left@0, parent@+4, right@+8, isnil@+0x19 (family with Buynode/Erase/Insert Val12).

5. **Callers (9):** `FUN_004188e0`, `FUN_0040d5b0`, `FUN_004e4130`, `FUN_005399f0`, `FUN_0053a8e0`, `FUN_00572ab0`, `FUN_00573250`, `FUN_005ae990`, `FUN_005e15a0`.

6. **Name:** structural `StdTree_Inc_Val12`. Legacy skill-status seed is **narrow**.

### Gaps

1. Product/MSVC demangle per map instantiation.  
2. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_005ae0b0_StdTree_Inc_Val12.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_005ae0b0_StdTree_Inc_Val12.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005ae0b0_StdTree_Inc_Val12.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005ae0b0_StdTree_Inc_Val12.md` |
| Function record | `docs/reconstruction/functions/aa_005ae0b0_StdTree_Inc_Val12.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_005ae0b0_FUN_005ae0b0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Inc_Val12.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005ae0b0.cpp` |
| Legacy alias clean | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Client_RecvSkillStatusEffect_005ae0b0.cpp` |
| Raw | `docs/reconstruction/raw/aa_005ae0b0_FUN_005ae0b0.md` |
| Annotated | `docs/reconstruction/raw/aa_005ae0b0_FUN_005ae0b0.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### Obj_BodyDtor_SetVtbl_DestroyStdListAt10 (`0x005b3b20`)

- Port as **body dtor only**: final vtbl + destroy list at `+0x10`.
- Reuse sealed `StdList_Destroy_FreeHead` for the list member (do not reimplement free-loop here).
- Scalar `operator_delete` belongs to `FUN_005b44d0`, not this unit.
- Do not invent a product class name from shader-adjacent rdata.

### StdTree_Inc_Val12 (`0x005ae0b0`)

- Port as **generic Val12 tree iterator++**, not skill-status-specific.
- Preserve isnil@+0x19; do not substitute isnil@+0x15 / +0x29 peer families.
- Erase helpers must call this (or equivalent) for successor before unlink.
- Closes the long-standing “product role of FUN_005ae0b0” gap left open by W27 erase duals.

---

## Notes

- Tools used: `decompile_function`, `analyze_function_complete`, `read_memory`, `get_function_by_address`, `get_bulk_xrefs`, `get_assembly_context`, `analyze_data_region`. **No** `disassemble_bytes`. **No** Launcher. **No** parent ledger edits.
- Partition ownership: W28-N only for these two VAs.
