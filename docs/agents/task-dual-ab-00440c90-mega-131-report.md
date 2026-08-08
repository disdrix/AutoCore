# Dual A/B report — MEGA-131 OWN-ONLY (`0x00440c90`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-131**  
**Scope:** VA `0x00440c90` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — free-subtree for dualed **gfxUIWindow_CompleteDtor** (`0x00759de0`) tree shell@+0x10.  
**Partition hint:** `StdTree_ClearShell_At10` (parent pattern; this VA = free-subtree core).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00440c90` StdTree_FreeSubtree_Isnil1d_DestroyTreeVal10_Inferred | **accept-with-gaps** — CF/ABI/RET4/isnil1d/left-walk/value-dtor/callers sealed; product map English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): clear-shell-as-this-VA / Map_FreeSubtree merge / shell+04 merge / bare-cdecl / decompiler-complete / product-method claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00440c90` — sealed facts

1. **Body:** `0x00440c90`–`0x00440cca` inclusive (**59 B** / `0x3B`); pad `CC` from `0x00440ccb`.
2. **ABI:** **ECX** = tree shell (threaded); stack `node*`; void; **`RET 4`**.
3. **Semantics:** free-subtree isnil@**+0x1d**:
   - Gate on isnil; loop: free **right**@+8; load **left**@+0; **`FUN_00442730`(EAX=node)** destroy embedded tree@+0x10; `operator_delete`; advance left.
   - Decompiler omits left-walk and false-noreturns on delete — **bytes override**.
4. **Value dtor (`FUN_00442730`):** `EDI=EAX`; `ADD EDI,0x10`; erase nested tree via `FUN_004413c0` (isnil@+0x3d free path); `operator_delete` head; zero head/size.
5. **Callers (3 external + self):**
   - `FUN_00441720` @ `0x00441740` — erase-range full-clear
   - `gfxUIWindow_CompleteDtor` `FUN_00759de0` @ `0x00759e20` — shell **this+0x10**
   - `FUN_00758c80` @ `0x00758d82` — shell **this+0x10**
6. **Xrefs:** 4 UNCONDITIONAL_CALL (includes self @ `0x00440ca7`).
7. **Callees:** self, `FUN_00442730`, `operator_delete` (`0x00489822`).
8. **Name:** `StdTree_FreeSubtree_Isnil1d_DestroyTreeVal10_Inferred` (Ghidra `FUN_00440c90`). Product map open → `_Inferred`. Scaffold `Named_CalleeOf_Named_gfxUIWindow_00440c90` **retired**.
9. **Decompile ≠ full CF**; ABI/offsets sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product map/key English for isnil1d + nested isnil3d@+0x10.  
- Residual duals: `FUN_00442730`, `FUN_004413c0`, `FUN_00440ab0`, `FUN_00441720`, `FUN_00758c80`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00440c90_StdTree_FreeSubtree_Isnil1d_DestroyTreeVal10_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00440c90_StdTree_FreeSubtree_Isnil1d_DestroyTreeVal10_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00440c90_FUN_00440c90.md` |
| Annotated | `docs/reconstruction/raw/aa_00440c90_FUN_00440c90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_FreeSubtree_Isnil1d_DestroyTreeVal10_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00440c90.cpp` |
| Function | `docs/reconstruction/functions/aa_00440c90_FUN_00440c90.md` |
| Function named | `docs/reconstruction/functions/aa_00440c90_StdTree_FreeSubtree_Isnil1d_DestroyTreeVal10_Inferred.md` |
| Retired scaffold clean | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_gfxUIWindow_00440c90.cpp` (superseded; do not use) |

---

## Chain context (not dualled; evidence only)

```text
FUN_00759de0  gfxUIWindow_CompleteDtor  [dualed WQ9L-F]
  ├─ clear shell @ this+0x10:
  │     push head->parent
  │     FUN_00440c90  StdTree_FreeSubtree_Isnil1d_DestroyTreeVal10_Inferred  [OWN MEGA-131]
  │     reset head self-links; size=0
  ├─ clear shell @ this+0x04:
  │     FUN_00440ab0  free isnil3d + FUN_00442720  [residual]
  └─ …

FUN_00441720  erase-range isnil1d (full-clear path)
  └─ FUN_00440c90  [OWN MEGA-131]

FUN_00440c90
  ├─ self (right)
  ├─ FUN_00442730  destroy embedded tree @ node+0x10  [residual]
  │     └─ FUN_004413c0 erase nested isnil3d → FUN_00440ab0 free
  └─ operator_delete
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00440c90-mega-131-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00440c90` | Port as **free-subtree** for isnil@**+0x1d** nodes with **value destroy** of embedded tree@+0x10. **ECX=tree_shell**, stack=node, **RET 4**. Do **not** treat as full clear (parents reset head/size). |
| Keep distinct from | `Map_FreeSubtree_Isnil1d` `0051be10` (no value dtor); shell+0x04 free `00440ab0` (isnil@+0x3d). |
| Pair with | dualed `gfxUIWindow_CompleteDtor` `00759de0`; residual `FUN_00442730` / `FUN_00440ab0` / erase `00441720`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming ledgers as applicable
- retire scaffold name from any index still pointing at `Named_CalleeOf_Named_gfxUIWindow_00440c90`
