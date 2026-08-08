# Dual A/B report — WQ9F-A OWN-ONLY (`aa_004cb680`, `aa_005a2de0`)

**Date:** 2026-08-04  
**Agent:** WQ9F-A OWN-ONLY  
**Scope:** OWN ONLY VAs `0x004cb680`, `0x005a2de0`. Dual A/B + trio raw/annotated/clean + function records.  
**Work item:** WQ-009 depth-3 residual — SkillCNDHash freelist release nested under destroy + StdTree buynode for isnil29 insert.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth3_partition_map.md`  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / VERIFICATION_MATRIX / NAMING_REGISTRY / systems residual / other parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Terminal:** **false**

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004cb680` SkillCNDHash_ReleaseChainsToFreelist_Inferred | **accept-with-gaps** — freelist CF/ABI/sole destroy caller/mask-walk sealed; product English + freelist-pop dual open |
| `aa_005a2de0` StdTree_Buynode_Isnil29_Val24_Inferred | **accept-with-gaps** — buynode CF/ABI/RET14/0x30 layout/3 callers sealed; product value_type English open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): false-noreturn delete, Val12 merge, skill-gather product name, void-return, exclusive mask-walk all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## Sealed facts — `0x004cb680` SkillCNDHash_ReleaseChainsToFreelist_Inferred

1. **Body:** `0x004cb680`–`0x004cb6e1` inclusive (**98 B** / `0x62`); terminal `5F 5E 5D 5B C3` + `CC` pad. Ghidra body end `004cb6e1`.

2. **ABI:** MSVC **`__thiscall`**.  
   - `ECX` = skill CNDHash*  
   - no stack args  
   - **void**  
   - **bare `ret`**  
   - Entry: `push ebx/ebp/esi; mov ebx,ecx`

3. **Algorithm:**  
   - For `i = 0 .. mask(@+0x08)` **inclusive**:  
   - `node = table[i]->head` where head is **bucket[+4]**  
   - While node: save next `@+0x0c`; stamp `PTR_FUN_009cb968`; if payload `@+0x08` non-null → `operator_delete`; zero payload; push node to freelist `@+0x20` (overwrite `*node` with next link); advance.  
   - Clear bucket head to 0.  
   - Does **not** free table/slab or zero live count (parent destroy does).

4. **Callers (1):**  
   - `SkillCNDHash_DestroyBucketTable_Inferred` (`0x004cba60`) @ `0x004cba6a` only.

5. **Name:** `SkillCNDHash_ReleaseChainsToFreelist_Inferred` — role High (sole destroy nested freelist helper + layout match to WQ9E-A destroy dual); product class English **Inferred**.  
   Reject scaffold VOG_DEBUG_STOP path name as product identity.

6. **Decompile ≡ bytes** for CF (live 2026-08-04 ≡ raw 2026-07-23). False-noreturn on `operator_delete` corrected by bytes (`add esp,4` continues).

### Gaps — `004cb680`

1. Product/PDB class name for skill CNDHash / node behind `009cb968`.  
2. Freelist pop / host teardown consumer (e.g. post-dtor `FUN_0059c8a0`) not dualled.  
3. Runtime / bit-exact open.

### Dual A/B — `004cb680`

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004cb680_SkillCNDHash_ReleaseChainsToFreelist_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004cb680_SkillCNDHash_ReleaseChainsToFreelist_Inferred.md` | **accept-with-gaps** |

### Files — `004cb680`

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004cb680_FUN_004cb680.md` |
| Annotated | `docs/reconstruction/raw/aa_004cb680_FUN_004cb680.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SkillCNDHash_ReleaseChainsToFreelist_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004cb680.cpp` |
| Function | `docs/reconstruction/functions/aa_004cb680_FUN_004cb680.md` |
| Function named | `docs/reconstruction/functions/aa_004cb680_SkillCNDHash_ReleaseChainsToFreelist_Inferred.md` |

---

## Sealed facts — `0x005a2de0` StdTree_Buynode_Isnil29_Val24_Inferred

1. **Body:** `0x005a2de0`–`0x005a2e3a` inclusive (**91 B** / `0x5B`); terminal **`C2 14 00`** + `CC` pad.

2. **ABI:** MSVC **`__stdcall`**.  
   - stack: `left*`, `parent*`, `right*`, `value6*`, `color` (u8)  
   - **`ret 0x14`**  
   - **EAX = Node*** (null on OOM) — decomp `void` is wrong

3. **Algorithm:**  
   - `operator_new(0x30)`  
   - if non-null: L/P/R; copy **6 dwords** to `+0x10`; color `@+0x28`; **isnil=0** `@+0x29`  
   - does not write `+0x0c`

4. **Callers (3):**  
   - `StdTree_InsertAndRebalance_Isnil29_Inferred` (`0x004cbb60`) @ `0x004cbbf2`  
   - `FUN_0058da40` @ `0x0058dad2` (insert twin)  
   - `FUN_005a3310` @ `0x005a33a2` (insert twin)  
   - Insert family always passes **color=0** (red).

5. **Name:** `StdTree_Buynode_Isnil29_Val24_Inferred` — role High (size/layout/insert consumers); product demangle **Inferred**.  
   Reject Val12 merge (`0x005ae220`, node 0x1c, isnil@+0x19).  
   Reject scaffold skill-gather path name as product identity.

6. **Decompile ≡ bytes** for CF; RET 0x14 sealed by **bytes**.

### Gaps — `005a2de0`

1. Product English / MSVC demangle for value_type (6-dword payload).  
2. Key vs mapped field split inside Val24.  
3. Full dual of extra insert shells `0058da40` / `005a3310` (not OWN).  
4. Runtime / bit-exact open.

### Dual A/B — `005a2de0`

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005a2de0_StdTree_Buynode_Isnil29_Val24_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005a2de0_StdTree_Buynode_Isnil29_Val24_Inferred.md` | **accept-with-gaps** |

### Files — `005a2de0`

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005a2de0_FUN_005a2de0.md` |
| Annotated | `docs/reconstruction/raw/aa_005a2de0_FUN_005a2de0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Buynode_Isnil29_Val24_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005a2de0.cpp` |
| Function | `docs/reconstruction/functions/aa_005a2de0_FUN_005a2de0.md` |
| Function named | `docs/reconstruction/functions/aa_005a2de0_StdTree_Buynode_Isnil29_Val24_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
SkillCNDHash_Recreate_Inferred (0x004cbdc0) / skill hash dtor FUN_0051de80
  └─ SkillCNDHash_DestroyBucketTable_Inferred (0x004cba60)   [dualed WQ9E-A]
        └─ SkillCNDHash_ReleaseChainsToFreelist_Inferred (0x004cb680)  [OWN WQ9F-A]
              // then parent free(*table) + delete[] table

StdTree_InsertAndRebalance_Isnil29_Inferred (0x004cbb60)   [dualed WQ9E-E]
  └─ StdTree_Buynode_Isnil29_Val24_Inferred (0x005a2de0)   [OWN WQ9F-A]
        // also shared by insert twins FUN_0058da40 / FUN_005a3310
```

Parent WQ9E duals explicitly left freelist `004cb680` and buynode `005a2de0` open; this wave seals them.

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004cb680` | Skill hash destroy must **drain all bucket chains to freelist** (mask-inclusive) and **delete node payloads** before free of slab/table. Preserve freelist head `@+0x20`. Do not treat decomp noreturn on delete. |
| `005a2de0` | Port as **stdcall ret 0x14** buynode for isnil29 trees: size **0x30**, Val24 @+0x10, color@+0x28, isnil0@+0x29. Shared by insert `004cbb60` family. **Do not** merge with Val12 buynode (`0x1c` / isnil@+0x19). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/xrefs). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean uses meaningful names (not Ghidra iVar paste); `_Inferred` where product English unproven.  
- Odd behavior preserved: false-noreturn delete; temp vtbl stamp then freelist overwrite; OOM returns null without throw.  
- **Terminal false.**

### Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` (and/or containers table for buynode)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004cb680-005a2de0-wq9fa-report.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
