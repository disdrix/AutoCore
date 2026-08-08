# Dual A/B report — WQ9D-G OWN-ONLY (`0x00421b50`, `0x00574a90`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9D-G**  
**Scope:** VAs `0x00421b50`, `0x00574a90` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `get_function_callers` / xrefs + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth_partition_map.md` → **WQ9D-G**.  
**Work item:** WQ-009 depth residual dual seal (skills-abilities nested callees, priority depth).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00421b50` StdTree_Max_Isnil29_Inferred | **accept-with-gaps** — CF/ABI/EAX return/isnil@0x29/5 erase callers sealed; product demangle open |
| `aa_00574a90` VehicleCrew_ClearMemberObject_Inferred | **accept-with-gaps** — CF/ABI/partial clear/sole caller sealed; COID leave-behind design open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): no CF rejects; decompiler void on Max and “full remove” on Clear both falsified.

---

## VA `0x00421b50` — sealed facts

1. **Body:** `0x00421b50`–`0x00421b6c` exclusive (**28 B** / `0x1C`). Final **`C3`**; pad `CC`.
2. **ABI:** **cdecl**; stack `node*`; plain **RET**; **EAX = rightmost non-nil** (or start if right is nil). Decompiler `void` **rejected**.
3. **Semantics:** MSVC `_Tree_max` for **isnil@+0x29** nodes:
   - `right = node[2]` (`+8`)
   - if `right->isnil` → return `node`
   - else walk right while next non-nil; return current
4. **Layout:** `+0` left, `+4` parent, `+8` right, `+0x28` color, `+0x29` isnil (0 = real).
5. **Classification:** leaf worker (shared map erase helper).
6. **Callers (5):** `FUN_00409220`, `FUN_004cb740`, `FUN_0051cb40`, `FUN_0058dc30`, `FUN_00603830` — all recompute `head+8` rightmost after erase.
7. **Xrefs:** 5 UNCONDITIONAL_CALL.
8. **Twins / peers:** min `FUN_0051b5d0` (leftmost isnil29, OWN WQ9D-B); peer `StdTree_Max_Val12` (`0x00418bf0`, isnil@+0x19).
9. **Name:** `StdTree_Max_Isnil29_Inferred` (Ghidra `FUN_00421b50`). Prior auto “GetTargetFromAggro callee” **narrow** — shared tree helper. Product demangle open → `_Inferred`.
10. **Decompile ≡ raw CF display**; empty-right early return sealed by **bytes** (decompiler walk model defective).

### Gaps

- Product English / MSVC demangle for map value_type.  
- Twin min dual owned by WQ9D-B.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00421b50_StdTree_Max_Isnil29_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00421b50_StdTree_Max_Isnil29_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00421b50_FUN_00421b50.md` |
| Annotated | `docs/reconstruction/raw/aa_00421b50_FUN_00421b50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Max_Isnil29_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00421b50.cpp` |
| Function | `docs/reconstruction/functions/aa_00421b50_FUN_00421b50.md` |
| Function named | `docs/reconstruction/functions/aa_00421b50_StdTree_Max_Isnil29_Inferred.md` |

---

## VA `0x00574a90` — sealed facts

1. **Body:** `0x00574a90`–`0x00574af4` exclusive (**100 B** / `0x64`); pad `CC`.
2. **ABI:** **`__thiscall`**; ECX = crew host*; stack `candidate*`; **RET 4**; **AL bool** `0`/`1`.
3. **Semantics:** 4-slot crew partial clear:
   - COID lo/hi from candidate via SharedBase offBase `+0x164`/`+0x168` (same as Contains/Insert).
   - Scan `this+0x198`, slots `i=0..3`, stride **`0x10`**.
   - On match: `*(this + (i+0x1A)*0x10) = 0` (object*); `FUN_00520330(0)` with **ECX=candidate** → `candidate+0xCB0 = 0`; return 1.
   - Miss → 0.
4. **Does not:** free COID (`0xFFFFFFFF` sentinel); decrement `+0x1D8` count.
5. **Callee:** `FUN_00520330` — `*(this+0xCB0)=arg`; `ret 4` (bytes sealed).
6. **Classification:** worker (crew unlink on object teardown).
7. **Callers (1):** `Client_ClearObjectReferences` (`FUN_00944d50` @ `0x009451dc`) — ECX = `*(localPlayerObj+0xCB0)` when non-null; stack = destroyed `vtbl+0x1dc()`.
8. **Xrefs:** 1.
9. **Twins:** Contains `VehicleCrew_ContainsMember_Inferred` (`0x005749d0`, dualed WQ9R-A); Insert `FUN_005755b0` (OWN WQ9D-D).
10. **Name:** `VehicleCrew_ClearMemberObject_Inferred` (Ghidra `FUN_00574a90`). Product demangle open → `_Inferred`.
11. **Decompile ≡ raw CF**; setter-this sealed by register liveness + callee bytes.

### Gaps

- Product English / MSVC demangle for crew-host class.  
- Design intent of leaving COID occupied after clear.  
- Null-candidate if called without sole-caller gate (no early null check).  
- Insert twin dual owned by WQ9D-D.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00574a90_VehicleCrew_ClearMemberObject_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00574a90_VehicleCrew_ClearMemberObject_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00574a90_FUN_00574a90.md` |
| Annotated | `docs/reconstruction/raw/aa_00574a90_FUN_00574a90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VehicleCrew_ClearMemberObject_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00574a90.cpp` |
| Function | `docs/reconstruction/functions/aa_00574a90_FUN_00574a90.md` |
| Function named | `docs/reconstruction/functions/aa_00574a90_VehicleCrew_ClearMemberObject_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00421b50` | Port as **MSVC tree max** on isnil@**0x29** nodes: walk **right** (`+8`) until next is nil; return rightmost real node (or start if right already nil). Use for map erase head-rightmost recompute. **Do not** trust decompiler `void`. **Do not** merge with Val12 max (`isnil@+0x19`). Pair with min twin `0051b5d0` for leftmost. |
| `00574a90` | Port as **crew partial clear** on host with `+0x198` table (4×0x10): match COID → null object* at `(slot+0x1A)*0x10` + `candidate+0xCB0=0`. **Do not** implement as full remove (no FFFFFFFF free, no count--). Sole client path: `Client_ClearObjectReferences`. Pair with Contains `005749d0` / Insert `005755b0`. Skill gather mode 0xb uses Contains only. |
| Pair with | Map erase clones (`00409220` family); `Client_ClearObjectReferences` (`00944d50`); `VehicleCrew_ContainsMember_Inferred`; insert `005755b0`; `FUN_00520330` CB0 setter; gather mode 0xb residual. |

---

## Process

- OWN VAs only (`0x00421b50`, `0x00574a90`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra iVar blank-line paste).  
- Odd behavior preserved: Max empty-right returns start; Clear leaves COID/count.  
- `_Inferred` where English unproven; Terminal **false**.

### Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md`  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00421b50-00574a90-wq9dg-report.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
