# Dual A/B report — MEGA-130 OWN-ONLY (`0x00440ab0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-130**  
**Scope:** VA `0x00440ab0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs + `disassemble_function` + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — skills-abilities free-subtree for gfxUIWindow tree shell @ **+0x04** (`StdTree_ClearShell_At04` partition role).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00440ab0` StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred | **accept-with-gaps** — CF/ABI/RET4/isnil3D/val@+0x0C/callers sealed; product map English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): decompiler-only CF / bare-RET / ECX=node / isnil1D-or-11 merge / full-clear-in-body / gfxUIWindow-method / scaffold-as-product claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00440ab0` — sealed facts

1. **Body:** `0x00440ab0`–`0x00440aeb` exclusive (**59 B** / `0x3B`); pad `CC` then `FUN_00440af0`.
2. **ABI:** **ECX** = tree host; stack **node\***; void; **`RET 4`** (`C2 04 00`).
3. **Semantics:** MSVC-style **`_Tree` free-subtree** (isnil@**+0x3D**, value@**+0x0C**):
   - Early-out if `node.isnil != 0`.
   - Loop left spine: free **right** recursively, destroy value via **`FUN_00442720`** (`ADD EAX,0xC` → `FUN_00440770`), `operator_delete`, advance left.
   - Does **not** reset head/size (callers do empty-sentinel fixup).
4. **Classification:** worker.
5. **Callers (xref_count=4):**
   - self @ `0x00440ac7` (right recurse)
   - `FUN_004413c0` @ `0x004413e0` (erase-all whole-tree path)
   - `FUN_00759de0` @ `0x00759e79` (**gfxUIWindow** complete: shell **this+0x04**)
   - `Catch@004424ff` @ `0x00442506` (EH free)
6. **Callees:** self, `FUN_00442720`, `operator_delete` @ `0x00489822`.
7. **Name:** `StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred` (Ghidra `FUN_00440ab0`). Partition alias `StdTree_ClearShell_At04`. Scaffold `Named_CalleeOf_Named_gfxUIWindow_00440ab0` **retired**.
8. **Decompile ≉ full CF** (false-noreturn collapses left-walk); **bytes seal complete loop**. Full hex in raw MEGA-130 append.

### Gaps

- Product/MSVC demangle for map T and value type (`00440770` / `00440230`).  
- Peer duals isnil1D `00440c90` / isnil11 `00440d20` residual.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00440ab0_StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00440ab0_StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00440ab0_FUN_00440ab0.md` |
| Annotated | `docs/reconstruction/raw/aa_00440ab0_FUN_00440ab0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00440ab0.cpp` |
| Scaffold clean (retired) | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_gfxUIWindow_00440ab0.cpp` |
| Function | `docs/reconstruction/functions/aa_00440ab0_FUN_00440ab0.md` |
| Function named | `docs/reconstruction/functions/aa_00440ab0_StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00759de0  gfxUIWindow_CompleteDtor  [dualed WQ9L-F]
  ├─ LEA shell = this+0x04
  ├─ FUN_00440ab0(root)   StdTree_FreeSubtree_Isnil3D_DestroyVal0C_Inferred  [OWN MEGA-130]
  └─ empty-reset head/size

FUN_004413c0  StdTree_EraseAll / erase range isnil3D  [residual]
  └─ whole-tree path → FUN_00440ab0(root) then reset

FUN_00440ab0  [OWN]
  ├─ self (right)
  ├─ FUN_00442720  val dtor trampoline (node → node+0x0C)  [residual]
  │    └─ FUN_00440770  value destroy  [residual]
  └─ operator_delete

Peers (partition ClearShell family; residual):
  FUN_00440c90  isnil@+0x1D  ClearShell_At10   [MEGA-131]
  FUN_00440d20  isnil@+0x11  ClearShell_AtA4   [MEGA-132]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00440ab0-mega-130-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00440ab0` | Port as **free-subtree** for isnil@**+0x3D** nodes with value destroy at **+0x0C**. **ECX=host**, stack=node, **RET 4**. Do **not** reset head/size inside this helper. Ignore Ghidra noreturn collapse of left-walk — implement the full left-spine loop from bytes. |
| Pair with | dualed `gfxUIWindow_CompleteDtor` `00759de0`; residual erase-all `004413c0`; residual val trampoline `00442720`; peer ClearShell `00440c90` / `00440d20`. |
| Distinct from | Val12 free-subtree `0040d630` (no val dtor; isnil@+0x19); isnil1D/11 shell peers. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming / system maps as applicable
- retire any residual queue entry for `0x00440ab0` / MEGA-130
