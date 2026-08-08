# Dual A/B report — WQ9G-J OWN-ONLY (`0x00406f20`, `0x00406fc0`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9G-J**  
**Scope:** VAs `0x00406f20`, `0x00406fc0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth4_partition_map.md` → **WQ9G-J**.  
**Work item:** WQ-009 depth-4 residual dual seal (tree-neighborhood residual leaves — sealed as CNDHash bucket alloc/destroy, not RB tree).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00406f20` CNDHash_AllocBucketTable_00a2c2e4 | **accept-with-gaps** — alloc CF/ABI/log2-gate/mask/stamp sealed; product English + OOM open |
| `aa_00406fc0` CNDHash_DestroyBucketTable_00a2c2e4 | **accept-with-gaps** — destroy CF/ABI/free-shape/callers sealed; freelist helper dual + product open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): no CF rejects; thiscall-merge, mask-as-count-after, free-table-as-slab, soft-fail-on-bad-log2, tree-insert/erase, skill-ABI-merge all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00406f20` — sealed facts

1. **Body:** `0x00406f20`–`0x00406faf` inclusive (**144 B** / `0x90`); `CC` pad `0x00406fb0`–`0x00406fbf`.
2. **ABI:** custom **ESI = CNDHash\***; no stack args; success **bare `ret`** (`5F 59 C3`); fail **noreturn throw**. Entry `51 8A 46 1C` (not thiscall).
3. **Semantics:** MSVC-style CNDHash **alloc empty bucket table**:
   - Gate log2 `@+0x1c` ∈ **[1,16]** else `VOG_DEBUG_STOP` + throw **`0x80004003`**.
   - `N = *(+8)`; `new[](N*4)` → `+0x10`; `malloc(N*0xc)` slab.
   - Each sentinel: stamp **`PTR_LAB_00a2c2e4`**, next=0, val=0.
   - `*(+8) = N-1` (**COUNT → MASK**).
4. **Callers (2):** `FUN_004063a0` (ctor, vtbl `PTR_FUN_00a2c2b0`) @ `0x004063fc`; `FUN_004195d0` (Recreate) @ `0x00419612`.
5. **Xrefs:** 2 UNCONDITIONAL_CALL.
6. **Name:** `CNDHash_AllocBucketTable_00a2c2e4` (Ghidra `FUN_00406f20`). Reject `Named_VOG_DEBUG_STOP_00406f20`.
7. **Decompile ≡ raw CF**; gate/mask/stamp sealed via `read_memory`.

### Gaps

- Product / PDB English for host class behind vtbl `00a2c2b0` / stamp `00a2c2e4`.  
- OOM null-check absence (preserve).  
- Full dual of Recreate/ctor parents (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00406f20_CNDHash_AllocBucketTable_00a2c2e4.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00406f20_CNDHash_AllocBucketTable_00a2c2e4.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00406f20_FUN_00406f20.md` |
| Annotated | `docs/reconstruction/raw/aa_00406f20_FUN_00406f20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_AllocBucketTable_00a2c2e4.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00406f20.cpp` |
| Function | `docs/reconstruction/functions/aa_00406f20_FUN_00406f20.md` |
| Function named | `docs/reconstruction/functions/aa_00406f20_CNDHash_AllocBucketTable_00a2c2e4.md` |

---

## VA `0x00406fc0` — sealed facts

1. **Body:** `0x00406fc0`–`0x00406ff3` inclusive (**52 B** / `0x34`); `CC` pad after bare `ret`.
2. **ABI:** custom **EAX = CNDHash\***; no stack args; **void**; bare **`ret`** (`5B C3`). Entry `53 8B D8` (EBX=hash for freelist).
3. **Semantics:** CNDHash **destroy bucket table**:
   - Zero live count `@+0x0c` (**not** mask `@+0x08`).
   - `FUN_004085e0` release chains → freelist `@+0x20` (EBX=hash; nested residual).
   - If table `@+0x10`: `free(*table)` (0xc **slab**), `delete[] table`, null `+0x10`.
4. **Callers (2):** `FUN_00406420` (dtor; optional `HashError:Destructor…`) @ `0x0040646e` — `mov eax,esi`; `FUN_004195d0` (Recreate) @ `0x004195f6` — `mov eax,esi`.
5. **Xrefs:** 2 UNCONDITIONAL_CALL.
6. **Name:** `CNDHash_DestroyBucketTable_00a2c2e4` (Ghidra `FUN_00406fc0`). Reject scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_00406fc0`.
7. **Decompile ≡ raw CF**; free-shape sealed via `read_memory`.

### Gaps

- Product / PDB English.  
- Full dual of nested freelist `FUN_004085e0` (not OWN).  
- Null-table freelist safety (callers construct table first).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00406fc0_CNDHash_DestroyBucketTable_00a2c2e4.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00406fc0_CNDHash_DestroyBucketTable_00a2c2e4.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00406fc0_FUN_00406fc0.md` |
| Annotated | `docs/reconstruction/raw/aa_00406fc0_FUN_00406fc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_DestroyBucketTable_00a2c2e4.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00406fc0.cpp` |
| Function | `docs/reconstruction/functions/aa_00406fc0_FUN_00406fc0.md` |
| Function named | `docs/reconstruction/functions/aa_00406fc0_CNDHash_DestroyBucketTable_00a2c2e4.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_004063a0  (hash ctor, vtbl PTR_FUN_00a2c2b0)
  └─ CNDHash_AllocBucketTable_00a2c2e4 (0x00406f20)     [OWN WQ9G-J]

FUN_00406420  (hash dtor; HashError:Destructor if locked)
  └─ CNDHash_DestroyBucketTable_00a2c2e4 (0x00406fc0)   [OWN WQ9G-J]
        └─ FUN_004085e0 freelist release                 [residual]

FUN_004195d0  (Recreate; HashError:Recreate if locked)
  ├─ CNDHash_DestroyBucketTable_00a2c2e4 (0x00406fc0)   [OWN WQ9G-J]
  ├─ seed log2 / N=1<<log2 / clear +0x14,+0x18
  └─ CNDHash_AllocBucketTable_00a2c2e4 (0x00406f20)     [OWN WQ9G-J]
```

Partition labeled these “tree neighborhood residual leaves” by VA proximity to dualed StdTree units; machine CF is **CNDHash bucket alloc/destroy**, not RB insert/erase.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00406f20-00406fc0-wq9gj-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00406f20` | Port as **shared CNDHash alloc-bucket-table** for stamp **`00a2c2e4`**. **ESI** ABI (not thiscall). Max log2 **16**; post-condition **mask = N-1**. Pair with destroy `00406fc0`. Do not merge with skill thiscall alloc `004cb410`. |
| `00406fc0` | Port as **destroy bucket table** twin. **EAX** ABI; freelist via `004085e0` (EBX); `free(*table)` + `delete[]`. Pair with inventory EAX destroy pattern; contrast skill ECX thiscall `004cba60`. |
| Pair with | host ctor/dtor/Recreate when dualed; freelist `004085e0`; other stamp-family alloc/destroy twins. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` (or container/CNDHash residual table — these are general CNDHash, not skill-specific)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x00406f20`, `0x00406fc0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra iVar blank-line paste).  
- Odd behavior preserved: no OOM checks; freelist always called even when table may be null (caller construction).  
- Stamp-suffix naming (product English unproven); Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
