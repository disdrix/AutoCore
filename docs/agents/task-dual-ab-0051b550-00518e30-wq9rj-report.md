# Dual A/B report — WQ9R-J OWN-ONLY (`0x0051b550`, `0x00518e30`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9R-J**  
**Scope:** VAs `0x0051b550`, `0x00518e30` only. Dual A/B + trio artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers / VERIFICATION_MATRIX / NAMING_REGISTRY.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_residual_partition_map.md` → **WQ9R-J**.  
**Wave:** WQ-009 residual skill-bank helpers.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0051b550` Object_LoadCloneBaseSkillTrio_Inferred | **accept-with-gaps** — wipe-hash-then-three-clonebase-skills CF/ABI/callers sealed; product English open |
| `aa_00518e30` Object_CreateOrRecreateSkillHash_Inferred | **accept-with-gaps** — create-or-recreate skill CNDHash at `+0x70` CF/ABI/`ret 4`/sizeof 0x34 sealed; product English open |

---

## VA `0x0051b550` — sealed facts

1. **Body:** `0x0051b550`–`0x0051b5d0` exclusive (**128 B** / `0x80`). Final **`5F 5E C3`** (`pop edi; pop esi; ret`). Next code @ `0x0051b5d0`.
2. **ABI:** **`__thiscall`/`__fastcall`**; ECX=`owner*`; no stack formals; void; bare **`C3`**.
3. **Semantics:** Shared virtual method — **clonebase default skill trio** load after skill-hash reset:
   - `Object_CreateOrRecreateSkillHash_Inferred(this, /*log2*/ 1)` (`FUN_00518e30`) — **recreates** existing hash (not soft ensure).
   - `cloneBase = *(*(this+0xA8)+0x3C)`.
   - Skill ids: `cloneBase+0x3BC`, `+0x3C0`, `+0x3C4`.
   - Ranks: byte returns of vfuncs **`vtbl+0x264`**, **`+0x268`**, **`+0x26C`** (`movzx` → ushort).
   - Each slot: `Skill_EnsureLoadedInTree(this, skillId, rank)` (`0x0051a980`, prior dual — void).
4. **Classification:** worker / virtual method (many DATA vtbl xrefs).
5. **Callers:** code **`FUN_004c8a60`** @ `0x004c8a75` (bulk loadout — calls this **first**, then walks equip skill tree); **~24** additional vtbl DATA xrefs (**25** total).
6. **Name:** `Object_LoadCloneBaseSkillTrio_Inferred` (Ghidra `FUN_0051b550`). Scaffold auto name **narrow** — do not promote. Product demangle open → `_Inferred`.
7. **Decompile ≡ raw CF**; entry `6A 01` + clonebase/vfunc offsets sealed by `read_memory`.

### Gaps

- Product English / MSVC demangle.  
- Clonebase slot labels; rank vfunc English per class.  
- Exact type of `*(this+0xA8)`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051b550_Object_LoadCloneBaseSkillTrio_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051b550_Object_LoadCloneBaseSkillTrio_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0051b550_FUN_0051b550.md` |
| Annotated | `docs/reconstruction/raw/aa_0051b550_FUN_0051b550.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_LoadCloneBaseSkillTrio_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051b550.cpp` |
| Function | `docs/reconstruction/functions/aa_0051b550_FUN_0051b550.md` |
| Function named | `docs/reconstruction/functions/aa_0051b550_Object_LoadCloneBaseSkillTrio_Inferred.md` |

---

## VA `0x00518e30` — sealed facts

1. **Body:** `0x00518e30`–`0x00518ebe` exclusive (**142 B** / `0x8E`). All exits **`C2 04 00`** (`ret 4`); pad **`CC CC`**. Next fn `Object_SharedBase_Dtor` `0x00518ec0` (prior dual; not this unit).
2. **ABI:** **`__thiscall`**; ECX=`owner*`; one stack formal **`log2`** (byte width, dword push); void; clean **4** B.
3. **Semantics:** Owner skill-hash **create or recreate** at **`owner+0x70`** (same slot as `Skill_EnsureLoadedInTree` / `Object_RefreshSkillHash_Inferred`):
   - SEH frame `LAB_009a3627`.
   - If `*(owner+0x70) ≠ 0`: `mov ecx, hash`; `FUN_004cbdc0(log2)` — skill-family **CNDHash recreate** (strings `"HashError:Recreate, already locked for traversal"`, `"VOG_DEBUG_STOP"`; does not hard-abort).
   - Else: `operator_new(0x34)` + `FUN_0051dd60(log2)` ctor (vtbl `PTR_FUN_009ce1b8`, mask `1<<log2`, log2 @ `hash+0x1c`) → store at `+0x70`; OOM → store **0**.
4. **Classification:** worker (hash factory / reset helper).
5. **Callers / xrefs (2):**
   - `FUN_0051b550` @ `0x0051b556` — **`push 1`**.
   - Orphan CODE @ `0x0052a2c5` — **`push 4`** (no Ghidra function name on that body).
6. **Name:** `Object_CreateOrRecreateSkillHash_Inferred` (Ghidra `FUN_00518e30`). **Do not** merge type-identity with inventory `CNDHash_Recreate` `0x004138d0` (analogous pattern only).
7. **Decompile ≡ raw CF**; asm restores hash ECX on recreate path (decomp can elide).

### Gaps

- Product English / MSVC demangle for skill CNDHash class.  
- Full dual of support callees `FUN_004cbdc0` / `FUN_0051dd60`.  
- Owning function for `0x0052a2c5`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00518e30_Object_CreateOrRecreateSkillHash_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00518e30_Object_CreateOrRecreateSkillHash_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00518e30_FUN_00518e30.md` |
| Annotated | `docs/reconstruction/raw/aa_00518e30_FUN_00518e30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_CreateOrRecreateSkillHash_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00518e30.cpp` |
| Function | `docs/reconstruction/functions/aa_00518e30_FUN_00518e30.md` |
| Function named | `docs/reconstruction/functions/aa_00518e30_Object_CreateOrRecreateSkillHash_Inferred.md` |

---

## Pair relationship (same wave)

```text
FUN_004c8a60 (bulk loadout)
  └─ Object_LoadCloneBaseSkillTrio_Inferred (0x0051b550)
        ├─ Object_CreateOrRecreateSkillHash_Inferred (0x00518e30, log2=1)  // wipe/create +0x70
        └─ Skill_EnsureLoadedInTree ×3  (cloneBase skills + vfunc ranks)
  └─ … walk equip tree, more EnsureLoadedInTree …
```

Both units are **skill-bank residual helpers**: hash lifecycle + default trio seed for the bulk skill path.

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00518e30` | Port **create-or-recreate** skill hash at owner `+0x70`. Existing hash must be **recreated** (not no-op). sizeof **0x34**. log2 stack arg; **`ret 4`**. |
| `0051b550` | Port after hash reset: three ensure calls from clonebase `+0x3BC/C0/C4` and ranks from class vfuncs `+0x264/268/26C`. Void; bare ret. Call before bulk loadout walk. |
| Pair with | `Skill_EnsureLoadedInTree` (`0x0051a980`), bulk `FUN_004c8a60`, `Object_RefreshSkillHash_Inferred` (`0x00517400` — different role). |
| Avoid | Soft-ensure on existing hash; inventing returns; mapping vtbl offsets to vehicle hardpoint fields; merging inventory CNDHash type identity. |

---

## Process

- OWN VAs only; no Launcher; **no parent ledger edits**.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/xrefs). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Names skill-domain + `_Inferred` (no product plate strings on these VAs).  
- Terminal: **false** (no Confirmed runtime).

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
