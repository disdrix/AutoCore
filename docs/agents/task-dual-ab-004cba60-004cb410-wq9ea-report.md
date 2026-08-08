# Dual A/B report — WQ9E-A OWN-ONLY (`aa_004cba60`, `aa_004cb410`)

**Date:** 2026-08-04  
**Agent:** WQ9E-A OWN-ONLY  
**Scope:** OWN ONLY VAs `0x004cba60`, `0x004cb410`. Dual A/B + trio raw/annotated/clean + function records.  
**Work item:** WQ-009 depth-2 residual — SkillCNDHash destroy / alloc-mask nested of dualed `SkillCNDHash_Recreate_Inferred`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth2_partition_map.md`  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / VERIFICATION_MATRIX / NAMING_REGISTRY / systems residual / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `analyze_function_complete` + `read_memory` + callers/xrefs + assembly_context. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Terminal:** **false**

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004cba60` SkillCNDHash_DestroyBucketTable_Inferred | **accept-with-gaps** — destroy CF/ABI/callers/free-shape sealed; product English + freelist helper dual open |
| `aa_004cb410` SkillCNDHash_AllocBucketTable_Inferred | **accept-with-gaps** — alloc CF/ABI/log2-gate/mask/stamp sealed; product English + OOM path open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): no CF rejects; inventory ABI-merge, mask-as-count-after, free-table-as-slab, soft-fail-on-bad-log2, owner-as-this all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## Sealed facts — `0x004cba60` SkillCNDHash_DestroyBucketTable_Inferred

1. **Body:** `0x004cba60`–`0x004cba93` inclusive (**52 B** / `0x34`); `CC` pad after bare `ret`. Ghidra body end `004cba93`.

2. **ABI:** MSVC **`__thiscall`**.  
   - `ECX` = skill CNDHash*  
   - no stack args  
   - **void**  
   - **bare `ret`** (`5E C3`)

3. **Algorithm:**  
   - Zero live entry count `@+0x0c` (**not** mask `@+0x08`).  
   - `FUN_004cb680` release bucket chains → freelist `@+0x20` (nested residual).  
   - If table `@+0x10` non-null: `free(*table)` (contiguous 0xc **slab**), `operator_delete[](table)`, null `+0x10`.

4. **Callers (2):**  
   - `SkillCNDHash_Recreate_Inferred` (`0x004cbdc0`) @ `0x004cbde6` — `mov ecx,esi` before call.  
   - Skill hash dtor body `FUN_0051de80` @ `0x0051dece` — after optional `"HashError:Destructor, already locked for traversal"`.

5. **Name:** `SkillCNDHash_DestroyBucketTable_Inferred` — role High (recreate/dtor chain + inventory twin pattern); product class English **Inferred**.  
   Reject type-merge with inventory `CNDHash_DestroyBucketTable_Inferred` `0x00413e20` (EAX custom ABI).

6. **Decompile ≡ bytes** for CF (live 2026-08-04 ≡ raw 2026-07-23).

### Gaps — `004cba60`

1. Product/PDB class name for skill CNDHash.  
2. Full dual of nested freelist helper `FUN_004cb680` (not OWN).  
3. Bit-identity of node layout vs inventory destroy family.  
4. Runtime / bit-exact open.

### Dual A/B — `004cba60`

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004cba60_SkillCNDHash_DestroyBucketTable_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004cba60_SkillCNDHash_DestroyBucketTable_Inferred.md` | **accept-with-gaps** |

### Files — `004cba60`

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004cba60_FUN_004cba60.md` |
| Annotated | `docs/reconstruction/raw/aa_004cba60_FUN_004cba60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SkillCNDHash_DestroyBucketTable_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004cba60.cpp` |
| Function | `docs/reconstruction/functions/aa_004cba60_FUN_004cba60.md` |
| Function named | `docs/reconstruction/functions/aa_004cba60_SkillCNDHash_DestroyBucketTable_Inferred.md` |

---

## Sealed facts — `0x004cb410` SkillCNDHash_AllocBucketTable_Inferred

1. **Body:** `0x004cb410`–`0x004cb4a0` inclusive (**145 B** / `0x91`); `CC` pad after throw call. Ghidra body end `004cb4a0`.

2. **ABI:** MSVC **`__thiscall`**.  
   - `ECX` = skill CNDHash*  
   - no stack args  
   - **void** on success; **noreturn throw** on fail  
   - success **bare `ret`** (`5F 5E 59 C3`)

3. **Log2 gate:** byte `@+0x1c` must be in **[1, 16]** (`cmp al,1; jl fail; cmp al,0x10; jg fail`).  
   Fail: `FUN_007a4480(0,"VOG_DEBUG_STOP")` + `_CxxThrowException` code **`0x80004003`** (`E_POINTER`; decomp signed `-0x7fffbffd`), `ThrowInfo` `DAT_00acc430`.

4. **Algorithm:**  
   - `N = *(hash+8)` provisional count (callers seed `1<<log2`).  
   - `operator_new[](N*4)` → table `@+0x10`.  
   - `malloc(N*0xc)` contiguous sentinel slab.  
   - Each bucket: stamp **`PTR_LAB_009cb970`**, `[+4]=0`, `[+8]=0`.  
   - `*(hash+8) = N - 1` — **COUNT → MASK**.

5. **Callers (2):**  
   - `SkillCNDHash_Recreate_Inferred` (`0x004cbdc0`) @ `0x004cbe0c`.  
   - `SkillCNDHash_Ctor_Inferred` (`0x0051dd60`) @ `0x0051ddba`.

6. **Name:** `SkillCNDHash_AllocBucketTable_Inferred` — role High (sole skill recreate/ctor alloc; stamp sealed); product English **Inferred**.  
   Reject type-merge with `CNDHash_AllocBucketTable_*` inventory/medal VAs (different stamp families).

7. **Decompile ≡ bytes** for CF (live 2026-08-04 ≡ raw 2026-07-23).

### Gaps — `004cb410`

1. Product English for class / sentinel behind `009cb970`.  
2. Full RTTI/method map of sentinel stamp.  
3. OOM null-check absence (preserve; open whether intentional).  
4. Runtime / bit-exact open.

### Dual A/B — `004cb410`

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004cb410_SkillCNDHash_AllocBucketTable_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004cb410_SkillCNDHash_AllocBucketTable_Inferred.md` | **accept-with-gaps** |

### Files — `004cb410`

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004cb410_FUN_004cb410.md` |
| Annotated | `docs/reconstruction/raw/aa_004cb410_FUN_004cb410.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SkillCNDHash_AllocBucketTable_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004cb410.cpp` |
| Function | `docs/reconstruction/functions/aa_004cb410_FUN_004cb410.md` |
| Function named | `docs/reconstruction/functions/aa_004cb410_SkillCNDHash_AllocBucketTable_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Object_CreateOrRecreateSkillHash_Inferred (0x00518e30)
  ├─ existing +0x70 → SkillCNDHash_Recreate_Inferred (0x004cbdc0)   [dualed WQ9D-A]
  │     ├─ SkillCNDHash_DestroyBucketTable_Inferred (0x004cba60)  [OWN WQ9E-A]
  │     │     └─ FUN_004cb680 freelist release                     [residual]
  │     └─ SkillCNDHash_AllocBucketTable_Inferred (0x004cb410)    [OWN WQ9E-A]
  └─ missing → new(0x34) + SkillCNDHash_Ctor_Inferred (0x0051dd60) [dualed WQ9D-A]
        └─ SkillCNDHash_AllocBucketTable_Inferred (0x004cb410)    [OWN WQ9E-A]

Skill hash dtor FUN_0051de80
  └─ SkillCNDHash_DestroyBucketTable_Inferred (0x004cba60)        [OWN WQ9E-A]
```

Parent WQ9D dual explicitly left these nested destroy/alloc helpers open; this wave seals them.

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004cba60` | Skill hash teardown must **freelist-release then dual-free** (slab via `free(*table)`, table via `delete[]`). Zero **`+0x0c`**, not mask. Use **thiscall ECX=hash**, not inventory EAX. |
| `004cb410` | After alloc, **`+8` is mask** `(1<<log2)-1`. Reject log2 outside 1..16 with throw. Stamp empty buckets with skill sentinel **`0x009cb970`**. Shared by recreate + ctor. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/xrefs/assembly_context).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean uses meaningful names (not Ghidra iVar paste); `_Inferred` where product English unproven.  
- Odd behavior preserved (no OOM checks; destroy leaves mask/`+0x20` to helpers).  
- **Terminal false.**
