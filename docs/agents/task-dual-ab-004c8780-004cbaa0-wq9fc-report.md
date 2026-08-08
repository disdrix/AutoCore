# Dual A/B report — WQ9F-C OWN-ONLY (`0x004c8780`, `0x004cbaa0`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9F-C**  
**Scope:** VAs `0x004c8780`, `0x004cbaa0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth3_partition_map.md` → **WQ9F-C**.  
**Work item:** WQ-009 depth-3 residual dual seal (erase/rebalance **callers** of dualed isnil29 tree erase `0x004cb740`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004c8780` Object_TFIDMap_FindFirstLive_EraseDead_Inferred | **accept-with-gaps** — CF/ABI/map+0x154 erase lea/return gates sealed; product English + 0 callers open |
| `aa_004cbaa0` StdTree_EraseRange_Isnil29_Inferred | **accept-with-gaps** — CF/ABI/RET0xC/full-clear/partial/6 xrefs sealed; product demangle + free-subtree residual open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): Map_EraseRange merge, wrong isnil family, host-as-map-ECX, always-erase, and VOG_DEBUG scaffold-as-product all **falsified/narrowed**.

---

## VA `0x004c8780` — sealed facts

1. **Body:** `0x004c8780`–`0x004c8963` exclusive (**483 B** / `0x1E3`). Ghidra end `004c8962`. Pad `CC`.
2. **ABI:** **`__thiscall`**; ECX = host*; no stack args; return object* / 0; **bare `ret`** after `add esp,0x24`.
3. **Semantics:** Walk TFID map at **`this+0x154`** (head **`+0x158`**):
   - Resolve TFID @ node+0x10 via `Object_ResolveFromTFID`.
   - **Dead:** if matches selected target MI `+0x44/+0x48/+0x4c` → host `vtbl+0x258` with null TFID `DAT_009cb8c0..`; successor; **`LEA ECX,[this+0x154]; CALL StdTree_EraseAndRebalance_Isnil29`** @ `0x004c893e`.
   - **Live:** `vtbl+0x210(0)` non-null → return obj; else `vtbl+0x214` + `Object_ResolveTfIdVtbl1dc` on blob `@+0x228` → return obj; else successor only.
   - Exhaust → 0.
4. **Layout:** isnil@+0x29 nodes (same family as erase dual); map shell embed at +0x154.
5. **Classification:** host worker (domain scrub + first-live), not pure STL.
6. **Callers:** **0** static xrefs recovered (open: vtable / dead). Sibling scrub `004c8610` live from `FUN_00638ac0`.
7. **Callees:** `Object_ResolveFromTFID`, `0x004cb740`, `0x004bb0d0`, indirect vtbls.
8. **Name:** `Object_TFIDMap_FindFirstLive_EraseDead_Inferred` (Ghidra `FUN_004c8780`). Product English open → `_Inferred`.
9. **Decompile ≡ raw CF**; erase ECX sealed by **assembly_context** (decomp omits `lea ecx,[ebp+0x154]`).

### Gaps

- Product method / host class English.  
- vtbl+0x210 / +0x214 / +0x258 English.  
- Caller recovery (0 xrefs).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004c8780_Object_TFIDMap_FindFirstLive_EraseDead_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004c8780_Object_TFIDMap_FindFirstLive_EraseDead_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004c8780_FUN_004c8780.md` |
| Annotated | `docs/reconstruction/raw/aa_004c8780_FUN_004c8780.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_TFIDMap_FindFirstLive_EraseDead_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c8780.cpp` |
| Function | `docs/reconstruction/functions/aa_004c8780_FUN_004c8780.md` |
| Function named | `docs/reconstruction/functions/aa_004c8780_Object_TFIDMap_FindFirstLive_EraseDead_Inferred.md` |

---

## VA `0x004cbaa0` — sealed facts

1. **Body:** `0x004cbaa0`–`0x004cbb54` exclusive (**180 B** / `0xB4`); terminal **`C2 0C 00`** both exits; pad `CC`.
2. **ABI:** **`__thiscall`**; ECX = map shell*; stack `outIt*`, `first`, `last`; **RET 0x0C**.
3. **Semantics:** MSVC `_Tree` **range erase** (isnil@+0x29):
   - if `first == head->left && last == head` → `FUN_004cb550(root)`; reset head L/P/R; size=0; `*outIt=begin`.
   - else while first≠last: successor isnil29; `MOV ECX,map; CALL 004cb740`; first=succ; `*outIt=first`.
4. **Classification:** worker (shared map range erase).
5. **Xrefs (6 UNCONDITIONAL_CALL):** `0x004cc3e2`, `0x004ca113`, `0x004ea63f`, `0x004ea94d`, `0x004eabd1`, `0x005dd8cb`.
6. **Callers (funcs):** `FUN_004cc3d0`, `FUN_004c9f80`, `FUN_004ea350`, + `0x005dd8cb` parent.
7. **Twins / peers (do not merge):**  
   - `Map_EraseRange` `0x0051c7c0` (free `0051bbc0` / erase `Map_EraseNode`)  
   - `Map_EraseRange_B` `0x0051d880` (free `0051be90`)  
   - isnil15 / isnil1d / Val12 range families  
   - Single erase OWN dual: `StdTree_EraseAndRebalance_Isnil29_Inferred` @ `0x004cb740`
8. **Name:** `StdTree_EraseRange_Isnil29_Inferred` (Ghidra `FUN_004cbaa0`). Prior VOG_DEBUG_STOP callee **narrow**. Product demangle open → `_Inferred`.
9. **Decompile ≡ raw CF**; RET 0x0C + erase ECX sealed by **bytes**.

### Gaps

- Product English / MSVC demangle for map value_type.  
- Full free-subtree algebra of `FUN_004cb550` (decomp residual).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004cbaa0_StdTree_EraseRange_Isnil29_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004cbaa0_StdTree_EraseRange_Isnil29_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004cbaa0_FUN_004cbaa0.md` |
| Annotated | `docs/reconstruction/raw/aa_004cbaa0_FUN_004cbaa0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseRange_Isnil29_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004cbaa0.cpp` |
| Function | `docs/reconstruction/functions/aa_004cbaa0_FUN_004cbaa0.md` |
| Function named | `docs/reconstruction/functions/aa_004cbaa0_StdTree_EraseRange_Isnil29_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004c8780` | Port as **TFID-map first-live finder with dead scrub**: walk map@+0x154; resolve; dead→optional clear-selected + isnil29 erase; live→v210 / related-resolve gates. **Do not** treat as pure STL. Erase **must** use map shell ECX (`this+0x154`), not host. |
| `004cbaa0` | Port as **MSVC range erase** on isnil@**0x29**: full-clear free `004cb550` + head reset; partial successor + `StdTree_EraseAndRebalance_Isnil29`. **Do not** merge with `Map_EraseRange` / `_B` (different free/erase pair). |
| Pair with | isnil29 single erase `004cb740`; min/max/rotates; sibling scrub `004c8610`; map lookup peer `004c8970` |

---

## Process

- OWN VAs only (`0x004c8780`, `0x004cbaa0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra iVar blank-line paste).  
- Odd behavior preserved: decomp omits erase `lea ecx,[this+0x154]`; 0 static callers on scrubber; free-subtree decomp may drop left recurse.  
- `_Inferred` where English unproven; Terminal **false**.

### Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` (or containers/shared tree + creature TFID map table)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004c8780-004cbaa0-wq9fc-report.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
