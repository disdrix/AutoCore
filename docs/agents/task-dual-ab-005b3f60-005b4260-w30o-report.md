# Dual A/B report — W30-O OWN-ONLY (`0x005b3f60`, `0x005b4260`)

**Date:** 2026-07-29  
**Agent:** W30-O OWN-ONLY  
**Scope:** OWN ONLY VAs `0x005b3f60`, `0x005b4260`. Dual A/B + artifacts.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave30_partition_map.md`  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / xrefs / complete analysis). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_005b3f60` Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20 | **accept-with-gaps** — default ctor: vtbl + empty list@+0x10 + zero F4@+0x20; size 0x30; 2 live callers; product class open |
| `aa_005b4260` Obj_Ctor_SetVtbl_EmptyListAt10_ZeroF4_ThenPopulate | **accept-with-gaps** — convenience ctor = same shell + `FUN_005b3fa0`; `ret 0x14`; **zero live callers**; product class open |

---

## `aa_005b3f60` — Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20

### Sealed facts

1. **Body:** `0x005b3f60`–`0x005b3f9a` exclusive (**58** B / `0x3A`). Final **`C3`**; pad `CC`.

2. **ABI:** ECX=`this`; returns `this` in EAX; bare **RET**.

3. **Algorithm (bytes authority):**
   ```
   *this = PTR_FUN_009d95b4
   list = this + 0x10
   head = FUN_005b43b0()   // operator_new(0x30) self-linked sentinel
   list+4 = head; list+8 = 0
   *(float*)(this+0x20..0x2c) = 0   // xorps + movss ×4
   return this
   ```

4. **Decompile gap:** indexes `param_1[5]/[6]/[8..0xb]` match offsets but omit list-base LEA and `movss` form of zeros — **bytes win**.

5. **Vtbl:** `0x009d95b4[0]` = `0x005b44d0` (scalar-deleting dtor). Adjacent rdata is shader text (`vs.1.1…`), not class name.

6. **Callers (2):** `FUN_004cd8f0` @ `0x004cd93f`; `FUN_004cd9a0` @ `0x004cd9f8` — both `operator_new(0x30)` then this; store at host `+0xe4fc`.

7. **Object size:** **0x30** sealed from caller allocs.

8. **Name:** structural `Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20`. No product plate.

### Gaps

1. Product English class name.  
2. Unwritten fields `+0x04..+0x0C`, `+0x1C`.  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_005b3f60_Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_005b3f60_Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005b3f60_Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005b3f60_Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20.md` |
| Function record | `docs/reconstruction/functions/aa_005b3f60_Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_005b3f60_FUN_005b3f60.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005b3f60.cpp` |
| Raw | `docs/reconstruction/raw/aa_005b3f60_FUN_005b3f60.md` |
| Annotated | `docs/reconstruction/raw/aa_005b3f60_FUN_005b3f60.annotated.md` |

---

## `aa_005b4260` — Obj_Ctor_SetVtbl_EmptyListAt10_ZeroF4_ThenPopulate

### Sealed facts

1. **Body:** `0x005b4260`–`0x005b42e6` exclusive (**134** B / `0x86`). Final **`C2 14 00`** (`ret 0x14`); pad `CC`.

2. **ABI:** ECX=`this`; **five** stack args; returns `this` in EAX; callee cleans **20** B.

3. **Algorithm:**
   ```
   SEH prolog (handler 0x009a6860, state -1)
   same shell as default ctor (vtbl + empty list@+0x10 + zero F4@+0x20)
   state = 0
   FUN_005b3fa0(this, p2, p3, p4, p5, p6)
   SEH epilog; return this; ret 0x14
   ```

4. **Callees:** `FUN_005b43b0`, `FUN_005b3fa0` (populate not owned this wave).

5. **Callers:** **none** (bulk xrefs empty). Live hosts use `FUN_005b3f60` then separate populate.

6. **Name:** structural `Obj_Ctor_SetVtbl_EmptyListAt10_ZeroF4_ThenPopulate`.

### Gaps

1. Why zero live callers (dead convenience / unused).  
2. Product class + full populate arg semantics.  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_005b4260_Obj_Ctor_SetVtbl_EmptyListAt10_ZeroF4_ThenPopulate.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_005b4260_Obj_Ctor_SetVtbl_EmptyListAt10_ZeroF4_ThenPopulate.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005b4260_Obj_Ctor_SetVtbl_EmptyListAt10_ZeroF4_ThenPopulate.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005b4260_Obj_Ctor_SetVtbl_EmptyListAt10_ZeroF4_ThenPopulate.md` |
| Function record | `docs/reconstruction/functions/aa_005b4260_Obj_Ctor_SetVtbl_EmptyListAt10_ZeroF4_ThenPopulate.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_005b4260_FUN_005b4260.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Obj_Ctor_SetVtbl_EmptyListAt10_ZeroF4_ThenPopulate.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_005b4260.cpp` |
| Raw | `docs/reconstruction/raw/aa_005b4260_FUN_005b4260.md` |
| Annotated | `docs/reconstruction/raw/aa_005b4260_FUN_005b4260.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20 (`0x005b3f60`)

- Port as **default ctor only**: vtbl + empty list member at `+0x10` + zero four floats at `+0x20`.
- Alloc size **0x30**; host stores pointer at `+0xe4fc`.
- Reuse / pair with sealed body dtor `Obj_BodyDtor_SetVtbl_DestroyStdListAt10` (list destroy at `+0x10`).
- Do **not** fold populate into this unit (live path calls `FUN_005b3fa0` separately).
- Do not invent product class name from shader-adjacent rdata.

### Obj_Ctor_SetVtbl_EmptyListAt10_ZeroF4_ThenPopulate (`0x005b4260`)

- Optional convenience = default shell + `FUN_005b3fa0`; preserve `ret 0x14` and SEH if ever exercised.
- Prefer the **split live path** (default ctor + populate) for AutoCore ports.
- Do not assume callers exist.

---

## Notes

- Tools used: `decompile_function` / `batch_decompile`, `analyze_function_complete`, `read_memory`, `get_function_by_address`, `get_bulk_xrefs`, `get_assembly_context`, `analyze_data_region`. **No** `disassemble_bytes`. **No** Launcher. **No** parent ledger edits.
- Partition ownership: W30-O only for these two VAs.
- Closes ctor side of the W28-N body-dtor pair for vtbl `0x009d95b4` / list@`+0x10`.
