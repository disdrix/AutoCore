# Dual A/B report — WQ9D-D OWN-ONLY (`0x004192f0`, `0x005755b0`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9D-D**  
**Scope:** VAs `0x004192f0`, `0x005755b0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth_partition_map.md` → **WQ9D-D**.  
**Work item:** WQ-009 depth residual dual seal (skills-abilities nested residual).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004192f0` StdTree_Rrotate_Isnil29_Inferred | **accept** — Rrotate CF/ABI/isnil@+0x29/leaf/25 xrefs sealed |
| `aa_005755b0` VehicleCrew_InsertMember_Inferred | **accept-with-gaps** — CF/ABI/4-slot insert/back-link sealed; 0 callers + product English open |

Path A (fidelity): as above.  
Path B (adversarial): no CF rejects; decompiler `FUN_00520330(host)` this-arg trap closed; isnil Val12 mix-up rejected.

---

## VA `0x004192f0` — sealed facts

1. **Body:** `0x004192f0`–`0x00419341` exclusive (**81 B**); pad `CC`.
2. **ABI:** **`__thiscall`**; ECX = tree*; stack `Node* x`; **RET 4** ×3 exits; void (no EAX contract).
3. **Semantics:** MSVC-style **right-rotate**:
   - `y = x->left`
   - `x->left = y->right`; if `!y->right->isnil` then `y->right->parent = x`
   - `y->parent = x->parent`
   - reattach y at root / parent-right / parent-left
   - `y->right = x`; `x->parent = y`
4. **isnil:** byte at **node+0x29** (`80 7E 29 00`).
5. **Classification:** leaf worker (0 callees).
6. **Callers (10):** `FUN_00406c40`, `FUN_00409220`, `FUN_004cb740`, `FUN_004cbb60`, `FUN_0051cb40`, `FUN_0058da40`, `FUN_0058dc30`, `FUN_005a3310`, `FUN_00603830`, `FUN_00603c90`.
7. **Xrefs:** 25 UNCONDITIONAL_CALL.
8. **Twins / peers:** Lrotate `FUN_004192a0` (WQ9D-C); Val12 peer `StdTree_Rrotate_Val12` @ `0x00418c10` (isnil@+0x19).
9. **Name:** `StdTree_Rrotate_Isnil29_Inferred` (Ghidra `FUN_004192f0`). Product demangle open → `_Inferred`. Supersedes aggro-xref scaffold human name.
10. **Decompile ≡ raw CF**; body hex sealed via `read_memory`.

### Gaps

- Product / MSVC demangle for each map value type.  
- Exact value payload size (color likely @+0x28).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004192f0_StdTree_Rrotate_Isnil29_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004192f0_StdTree_Rrotate_Isnil29_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004192f0_FUN_004192f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004192f0_FUN_004192f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Rrotate_Isnil29_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004192f0.cpp` |
| Function | `docs/reconstruction/functions/aa_004192f0_FUN_004192f0.md` |
| Function named | `docs/reconstruction/functions/aa_004192f0_StdTree_Rrotate_Isnil29_Inferred.md` |

---

## VA `0x005755b0` — sealed facts

1. **Body:** `0x005755b0`–`0x00575694` exclusive (**228 B** / `0xE4`); pad `CC`.
2. **ABI:** **`__thiscall`**; ECX = crew host*; stack `member*`; **RET 4**; **AL** bool (`32 C0` / `B0 01`).
3. **Semantics:** crew roster **insert**:
   - Capacity: `(u8)this+0x1D8 + (i32)this+0x1E4 > 3` → 0.
   - Guard: `VehicleCrew_ContainsMember_Inferred(member)` non-zero → 0.
   - Scan slots `i=0..3` at `this+0x198` stride `0x10`; free when `(lo & hi) == 0xFFFFFFFF`.
   - Write COID lo/hi from member via SharedBase offBase `+0x164/+0x168`.
   - Store `member*` at `(i+0x1A)*0x10` (= `+0x1A0+i*0x10`).
   - **`FUN_00520330(member, host)`** → **`member+0xCB0 = host`** (decompiler this-arg wrong).
   - **`FUN_00418d70` on `host+0x1F4`** appends COID pair.
   - `*(u8*)(host+0x1D8)++`; return 1.
   - No free slot → `FUN_007a4480(0,"VOG_DEBUG_STOP")` then 0.
4. **Classification:** worker (Contains + setter + vector push + debug).
5. **Callers:** **0** direct CALL xrefs in Ghidra (orphan gap).
6. **Twins:** reader `VehicleCrew_ContainsMember_Inferred` (`0x005749d0`); clear `FUN_00574a90` (WQ9D-G).
7. **Name:** `VehicleCrew_InsertMember_Inferred` (Ghidra `FUN_005755b0`). Product demangle open → `_Inferred`.
8. **Decompile ≡ raw CF** with call-site corrections sealed by `read_memory`.

### Gaps

- Product English / MSVC demangle for crew-host class.  
- Zero resolved callers (vtable / stripped / dead?).  
- English for `+0x1E4` bias and `+0x1F4` vector consumers.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005755b0_VehicleCrew_InsertMember_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005755b0_VehicleCrew_InsertMember_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005755b0_FUN_005755b0.md` |
| Annotated | `docs/reconstruction/raw/aa_005755b0_FUN_005755b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VehicleCrew_InsertMember_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005755b0.cpp` |
| Function | `docs/reconstruction/functions/aa_005755b0_FUN_005755b0.md` |
| Function named | `docs/reconstruction/functions/aa_005755b0_VehicleCrew_InsertMember_Inferred.md` |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004192f0-005755b0-wq9dd-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004192f0` | Port as **shared RB right-rotate** for **isnil@+0x29** maps — not skill logic. Keep separate from Val12 rotate (`isnil@+0x19`). Pair with Lrotate `004192a0` in rebalance/erase. |
| `005755b0` | Port as **crew-host insert** on `+0x198` 4×0x10 table. Free sentinel **both COID FFs**; capacity `(u8)+0x1D8+(i32)+0x1E4<=3`; uniqueness via Contains; **member+0xCB0=host**; COID vector @ **+0x1F4**. Pair with Contains `005749d0` / clear `00574a90`. Mode 0xb gather still uses Contains, not Insert. |
| Pair with | `VehicleCrew_ContainsMember_Inferred`, `StdTree_Rrotate_Val12`, Map erase `0051cb40`, gather mode 0xb `FUN_0058a810`. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` (Insert; rotate may sit under containers/shared)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x004192f0`, `0x005755b0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra iVar blank-line paste).  
- Odd behavior preserved: isnil@+0x29; free `(lo&hi)==~0`; decompiler 00520330 this corrected from bytes.  
- `_Inferred` where English unproven; Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
