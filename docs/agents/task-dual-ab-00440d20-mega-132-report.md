# Dual A/B report — MEGA-132 OWN-ONLY (`0x00440d20`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-132**  
**Scope:** VA `0x00440d20` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** WAVE residual dual seal — free-subtree helper for gfxUIWindow tree shell `@+0xA4` (partition hint `StdTree_ClearShell_AtA4`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00440d20` StdTree_FreeSubtree_Isnil11_Inferred | **accept-with-gaps** — CF/ABI/RET4/isnil11/left-walk/no-value-dtor/callers sealed; product map open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): decompiler-complete / cdecl-only / value-dtor / isnil29-merge / thiscall-on-node / right-only / scaffold-product claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00440d20` — sealed facts

1. **Body:** `0x00440d20`–`0x00440d54` inclusive (**53 B** / `0x35`); pad `CC`.
2. **ABI:** **ECX** = tree_base (threaded); stack `node*`; void; **`RET 4`** (`C2 04 00`).
3. **Semantics:** classic MSVC **free-subtree** (isnil@**+0x11**):
   - Gate on isnil; recurse free **right** `@+8`; `operator_delete` node; walk **left** `@+0`.
   - **No** value/payload destroy.
   - Decompiler collapses to right-only + false noreturn — **bytes override**.
4. **Callers (4 xrefs):**
   - self @ `0x00440d37`
   - `FUN_00441960` @ `0x00441980` (erase-all full-clear)
   - `FUN_00759de0` `gfxUIWindow_CompleteDtor` @ `0x00759ed6` (shell **`+0xA4`**)
   - `FUN_00759090` @ `0x0075911a` (head `@+0xA8` / same shell)
5. **Callees:** self; `operator_delete` @ `0x00489822`.
6. **Name:** `StdTree_FreeSubtree_Isnil11_Inferred` (Ghidra `FUN_00440d20`). Partition alias `StdTree_ClearShell_AtA4`. Scaffold `Named_CalleeOf_Named_gfxUIWindow_00440d20` **retired**.
7. **Decompile ≉ full body**; **`read_memory` + disasm hex seal CF**.

### Full body hex (53 B)

```
53 56 57 8B 7C 24 10 80 7F 11 00 8B D9 8B F7 75 1E
8B 46 08 50 8B CB E8 E4 FF FF FF 8B 36 57 E8 DE 8A 04 00
83 C4 04 80 7E 11 00 8B FE 74 E2 5F 5E 5B C2 04 00
```

### Gaps

- Product / MSVC demangle for isnil@+0x11 map value type.  
- Erase-all parent `00441960` residual (MEGA-136).  
- Value-dtor siblings `00440ab0` / `00440c90` residual (MEGA-130/131).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00440d20_StdTree_FreeSubtree_Isnil11_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00440d20_StdTree_FreeSubtree_Isnil11_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00440d20_FUN_00440d20.md` |
| Annotated | `docs/reconstruction/raw/aa_00440d20_FUN_00440d20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_FreeSubtree_Isnil11_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00440d20.cpp` |
| Scaffold retired | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_gfxUIWindow_00440d20.cpp` |
| Function | `docs/reconstruction/functions/aa_00440d20_FUN_00440d20.md` |
| Function named | `docs/reconstruction/functions/aa_00440d20_StdTree_FreeSubtree_Isnil11_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00759de0  gfxUIWindow_CompleteDtor  [dualed WQ9L-F]
  ├─ free shell @ +0x10 via FUN_00440c90   [residual MEGA-131]
  ├─ free shell @ +0x04 via FUN_00440ab0   [residual MEGA-130]
  ├─ free shell @ +0xA4 via FUN_00440d20   [OWN MEGA-132]
  └─ EH residual erase-all FUN_00441960    [residual MEGA-136]
        └─ full-clear → FUN_00440d20

FUN_00759090  UI rebuild clear
  └─ free head@+0xA8 parent → FUN_00440d20

FUN_00440d20  StdTree_FreeSubtree_Isnil11_Inferred
  ├─ self (right)
  └─ operator_delete
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00440d20-mega-132-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00440d20` | Port as **free-subtree leaf** for isnil@**+0x11** nodes. **ECX=tree_base**, stack=node, **RET 4**. No value dtor. Keep distinct from isnil29 FreeSubtree twins and value-dtor siblings `00440ab0`/`00440c90`. Shell self-link / size=0 stay in callers. |
| Pair with | dualed `gfxUIWindow_CompleteDtor` `00759de0`; residual erase-all `00441960`; residual ClearShell siblings `00440ab0`/`00440c90`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (skills-abilities / gfxUIWindow shells)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN-ONLY agent **MEGA-132**: exclusive VA `0x00440d20`; no parent ledger edits; no Launcher.  
- Live tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed — verdicts **accept-with-gaps** both paths.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name; scaffold `Named_CalleeOf_*` retired to redirect.  
- Odd behavior preserved: Ghidra false-noreturn + missing left-walk; ECX threaded unused in body.  
- Product demangle open → `_Inferred`. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
