# Dual A/B report — WQ9F-E OWN-ONLY (`0x004cc220`, `0x0051be10`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9F-E**  
**Scope:** VAs `0x004cc220`, `0x0051be10` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth3_partition_map.md` → **WQ9F-E**.  
**Work item:** WQ-009 depth-3 residual dual seal (insert-path peer of dualed isnil29 rebalance; map free helper for isnil1d erase family).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004cc220` StdTree_InsertHint_Isnil29_Inferred | **accept-with-gaps** — hint-insert CF/ABI/RET0x0c/isnil@+0x29/7× rebalance + fallback sealed; product key English open |
| `aa_0051be10` Map_FreeSubtree_Isnil1d | **accept-with-gaps** — free-subtree isnil@+0x1d; byte left-walk sealed; sole caller Map_EraseRange_Isnil1d |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): no CF rejects; decompiler noreturn free + where-alias after prev/next closed via bytes; Val12/isnil29 free collapse and VOG scaffold names rejected.

---

## VA `0x004cc220` — sealed facts

1. **Body:** `0x004cc220`–`0x004cc3c4` inclusive (**421 B** / `0x1A5`); exclusive end `0x004cc3c5`; pad `CC`.
2. **ABI:** **`__thiscall`**; ECX = map* (`head@+4`, `size@+8`); stack `Node** outIt`, `Node* hint`, `Val* value`; **RET 0x0c**.
3. **Semantics:** MSVC-style **unique insert-with-hint**:
   - Empty → `StdTree_InsertAndRebalance_Isnil29_Inferred` (`0x004cbb60`) addLeft=1 under head.
   - Hint == leftmost and value < hint → Insert left.
   - Hint == head (end) and rightmost < value → Insert right of rightmost.
   - Neighbor: Prevnode / Nextnode (`004cb4f0` / `004cb270`); open-side Insert via isnil@+0x29 on attachment right.
   - Else → `FUN_004cbee0` insert-or-find; `*outIt = node`.
4. **Key:** 2-dword ordered pair; less via `FUN_00401480` (hi then lo) on value +0/+4 and node +0x10/+0x14.
5. **isnil / color:** **+0x29** / **+0x28** (family of dualed insert rebalance).
6. **Caller (1):** `FUN_004cc400` @ `0x004cc457`.
7. **Xrefs:** 1 UNCONDITIONAL_CALL.
8. **Name:** `StdTree_InsertHint_Isnil29_Inferred` (Ghidra `FUN_004cc220`). Peer of `StdTree_InsertHint_Val12`. Product demangle open → `_Inferred`. Reject VOG_DEBUG_STOP scaffold.
9. **Decompile ≡ raw CF**; open-side **where** after prev/next sealed by **bytes** (decomp aliases slightly).

### Gaps

- Product / MSVC demangle for map value_type and `FUN_004cc400` host.  
- English for 2-dword key (structural only).  
- Nested dual of `FUN_004cbee0` / key-less / prev-next (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004cc220_StdTree_InsertHint_Isnil29_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004cc220_StdTree_InsertHint_Isnil29_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004cc220_FUN_004cc220.md` |
| Annotated | `docs/reconstruction/raw/aa_004cc220_FUN_004cc220.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertHint_Isnil29_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004cc220.cpp` |
| Function | `docs/reconstruction/functions/aa_004cc220_FUN_004cc220.md` |
| Function named | `docs/reconstruction/functions/aa_004cc220_StdTree_InsertHint_Isnil29_Inferred.md` |

---

## VA `0x0051be10` — sealed facts

1. **Body:** `0x0051be10`–`0x0051be44` inclusive (**53 B** / `0x35`); exclusive end `0x0051be45`; pad `CC`.
2. **ABI:** stack **`node*`**; ECX threaded unused; **`ret 4`** (`C2 04 00`).
3. **Identity:** MSVC map/set **subtree free** for node family **`isnil@+0x1d`** (same header as `Map_EraseRange_Isnil1d_Inferred` / erase-node `FUN_0051c880`).
4. **Byte-correct algebra** (decomp incomplete — false-noreturn on `operator_delete` drops left walk):
   - if isnil → return  
   - loop: free(right @ +8); left = *node; `operator_delete(node)`; node = left; until isnil  
5. **Callers:** self (right recurse); sole external **`Map_EraseRange_Isnil1d_Inferred` / `FUN_0051d700`** full-clear @ `0x0051d71c`.
6. **Name:** `Map_FreeSubtree_Isnil1d` — free discriminator for sealed isnil1d range erase (vs `Map_FreeSubtree_Isnil29` / `Map_FreeSubtree_B`).
7. **Live decomp plate ≡ original raw;** bytes supersede decomp for left-walk.

### Gaps

- Product/PDB map type / value size for isnil1d family.  
- tree_base unused (threading only).  
- Full host inventory beyond EraseRange_Isnil1d.  
- Runtime / bit-exact / differential open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051be10_Map_FreeSubtree_Isnil1d.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051be10_Map_FreeSubtree_Isnil1d.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0051be10_FUN_0051be10.md` |
| Annotated | `docs/reconstruction/raw/aa_0051be10_FUN_0051be10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_FreeSubtree_Isnil1d.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051be10.cpp` |
| Function | `docs/reconstruction/functions/aa_0051be10_FUN_0051be10.md` |
| Function named | `docs/reconstruction/functions/aa_0051be10_Map_FreeSubtree_Isnil1d.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_004cc400 (operator[] / get-or-insert shell)           [not OWN]
  └─ StdTree_InsertHint_Isnil29_Inferred (0x004cc220)     [OWN]
       ├─ StdTree_InsertAndRebalance_Isnil29 (0x004cbb60) [WQ9E-E dualed]
       ├─ FUN_004cbee0 insert-or-find                     [WQ9F-D residual]
       ├─ FUN_00401480 key-less (2-dword)
       └─ Prev/Next FUN_004cb4f0 / FUN_004cb270

Map_EraseRange_Isnil1d_Inferred (0x0051d700)              [WQ9E-I dualed]
  └─ Map_FreeSubtree_Isnil1d (0x0051be10)                 [OWN]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004cc220-0051be10-wq9fe-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004cc220` | Port as **unique insert-with-hint** for **isnil@+0x29** maps with **2-dword** ordered keys — not skill logic. **RET 0x0c**. Pair with always-insert `004cbb60` and insert-or-find `004cbee0`. Do **not** merge with Val12 InsertHint (`0053a8e0`) or int-key `004cbe20`. |
| `0051be10` | Free-subtree only — **no** value dtor. Use **right-recurse + left-walk**; do not trust Ghidra noreturn collapse. **isnil@+0x1d**. RET 4; ECX may be unused but must be threaded from callers. Keep **separate** from Isnil29 / FreeSubtree_B frees. |
| Pair with | dualed isnil29 insert rebalance; dualed Map_EraseRange_Isnil1d; residual erase-node isnil1d `0051c880` (WQ9F-F). |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` (tree insert-hint + isnil1d free residual)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x004cc220`, `0x0051be10`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
