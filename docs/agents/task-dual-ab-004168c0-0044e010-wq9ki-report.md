# Dual A/B report — WQ9K-I OWN-ONLY (`0x004168c0`, `0x0044e010`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9K-I**  
**Scope:** VAs `0x004168c0`, `0x0044e010` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth8_partition_map.md` → **WQ9K-I**.  
**Work item:** WQ-009 depth-8 residual dual seal (Class_00a733ec peer factory + tree left-rotate isnil2D).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004168c0` Class_00a733ec_Factory_NullFreeCallback_Inferred | **accept-with-gaps** — alloc/ABI/vtbl/null free-cb/twin-diff sealed; product English + static callers open |
| `aa_0044e010` StdTree_LeftRotate_Isnil2D_Inferred | **accept-with-gaps** — left-rotate CF/ABI/isnil@+0x2D/10 call sites sealed; product map English residual |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): thiscall-on-factory, callback-install, freelist/CNDHash, right-rotate mislabel, isnil29/31 merge, UNI_BUTTONS-as-class, runtime Confirmed **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004168c0` — sealed facts

1. **Body:** `0x004168c0`–`0x0041691f` inclusive (**96 B** / `0x60`).
2. **ABI:** **1 stack arg** (context); **EAX** = object\* or null; **`RET 4`** (`C2 04 00`). Not thiscall.
3. **Semantics:** MSVC-style **Class_00a733ec factory** with **null free-callback**:
   - SEH (`LAB_009ab4eb`) + `operator_new(0x14)`.
   - `*obj = PTR_FUN_00a733ec`; `+4` = context; `+8`/`+0xc` = 0; **`+0x10` = 0**.
4. **Twin:** `FUN_00416830` (WQ9K-H OWN) identical except `+0x10 = LAB_00573240`.
5. **Dtor peer:** `Class_00a733ec_ScalarDeletingDtor_Inferred` @ `0x00416f00` = `*(u32*)0x00a733ec`.
6. **Xrefs:** Ghidra **0** CALL/DATA to entry (same empty surface as twin factory).
7. **Name:** `Class_00a733ec_Factory_NullFreeCallback_Inferred` (Ghidra `FUN_004168c0`). Product English open → `_Inferred`. Adjacent UTF-16 `"UNI_BUTTONS"` **not** sealed as class name.
8. **Decompile ≡ raw CF**; size/vtbl/null-cb/RET sealed via `read_memory`.

### Gaps

- Product / RTTI demangle.  
- Static caller recovery.  
- Twin factory dual is WQ9K-H.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004168c0_Class_00a733ec_Factory_NullFreeCallback_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004168c0_Class_00a733ec_Factory_NullFreeCallback_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004168c0_FUN_004168c0.md` |
| Annotated | `docs/reconstruction/raw/aa_004168c0_FUN_004168c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Class_00a733ec_Factory_NullFreeCallback_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004168c0.cpp` |
| Function | `docs/reconstruction/functions/aa_004168c0_FUN_004168c0.md` |
| Function named | `docs/reconstruction/functions/aa_004168c0_Class_00a733ec_Factory_NullFreeCallback_Inferred.md` |

---

## VA `0x0044e010` — sealed facts

1. **Body:** `0x0044e010`–`0x0044e05b` inclusive (**76 B** / `0x4C`); pad `CC` after last `RET 4`.
2. **ABI:** **`__thiscall`** — **ECX** = node X; stack **map\***; three exits all **`RET 4`** (`C2 04 00`). Void.
3. **Semantics:** MSVC-style **tree left rotate** (promote X.right):
   - Y = X.right; X.right = Y.left; if Y.left non-nil → parent fix.
   - Rewire root / left-child / right-child; Y.left = X; X.parent = Y.
4. **Layout:** left@+0, parent@+4, right@+8, **isnil@+0x2D** (`80 7A 2D 00`); color@+0x2C on callers only.
5. **Callees:** none (leaf).
6. **Callers (10 CALL / 4 funcs):** `FUN_0042a930`×3, `FUN_00430b60`×2, `FUN_004094c0`×3, `FUN_00401db0`×2.
7. **Name:** `StdTree_LeftRotate_Isnil2D_Inferred` (Ghidra `FUN_0044e010`). Reject scaffold `Named_CalleeOf_*`.
8. **Peer R-rotate:** `FUN_0042a840` (WQ9K-J OWN). Do **not** merge isnil29 pair `004192a0`/`004192f0`.
9. **Decompile ≡ raw CF**; isnil/RET/call-site ECX sealed via bytes + assembly context.

### Gaps

- Product / English host map type.  
- Right-rotate peer dual is WQ9K-J.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0044e010_StdTree_LeftRotate_Isnil2D_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0044e010_StdTree_LeftRotate_Isnil2D_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0044e010_FUN_0044e010.md` |
| Annotated | `docs/reconstruction/raw/aa_0044e010_FUN_0044e010.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_LeftRotate_Isnil2D_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0044e010.cpp` |
| Function | `docs/reconstruction/functions/aa_0044e010_FUN_0044e010.md` |
| Function named | `docs/reconstruction/functions/aa_0044e010_StdTree_LeftRotate_Isnil2D_Inferred.md` |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004168c0-0044e010-wq9ki-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004168c0` | Port as **Class_00a733ec factory** with **null free-callback**. Stack context; **RET 4**; size **0x14**; vtbl `PTR_FUN_00a733ec`. Pair with dtor `00416f00` and twin factory `00416830` (callback path). |
| `0044e010` | Port as **shared tree left-rotate** for **isnil@+0x2D**. **ECX**=node, stack map, **RET 4**. Pair with R-rotate `0042a840`; use from StringKey insert/erase rebalance — not isnil29 rotates. |
| Pair with | dtor `00416f00`; factory twin `00416830` (WQ9K-H); R-rotate `0042a840` (WQ9K-J); erase `004094c0`; insert `00430b60`. |
| Naming caution | **OWN pair is two families** (Class_00a733ec factory vs isnil2D left-rotate) — shared only by residual VA partition, not layout. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual table (or util/container note — rotate is **tree** helper; factory is **vtbl class** util)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x004168c0`, `0x0044e010`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + assembly context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not blank Ghidra paste).  
- Odd behavior preserved: factory 0 xrefs; decompiler `void` on rotate (correct — no return value).  
- `_Inferred` where English unproven; Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
