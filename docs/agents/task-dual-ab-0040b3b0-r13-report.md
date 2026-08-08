# Dual A/B report — R13-017 OWN-ONLY (`0x0040b3b0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R13-017**  
**Scope:** VA `0x0040b3b0` (`aa_0040b3b0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (including residual buyhead `0040bfc0`, siblings `0040b440`/`0040b890`/`0040bc10`, parent re-dual `0092b2a0`).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_xrefs` / `get_xrefs_to` + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r13_residual_partition_map.md` → **R13-017**.  
**System:** inventory-transfer (partition assignment; unit role is generic MSVC `_Tree` empty construct).  
**Parent dual:** `0x0092b2a0` MissionTracker_FillTrackedTargetSlots_Inferred (R12-008).  
**Dual start:** 2686.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0040b3b0` StdTree_ConstructEmpty_Isnil19_Inferred | **accept-with-gaps** — CF/ABI/RET4/isnil19/self-link/size0 sealed; product residual |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): void-ABI / thiscall / isnil29-merge / isnil31-merge / freelist / MissionTracker-product-name / Runtime Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0040b3b0` — sealed facts

1. **Body:** `0x0040b3b0`–`0x0040b40a` exclusive (**90 B** / `0x5A`); pad `CC` @ `0x0040b40a+`; next `FUN_0040b410`. Ghidra body end inclusive `0x0040b409`.
2. **ABI:** **`__stdcall`** 1 stack arg (`shell*`); **`ret 4`** (`C2 04 00` @ `0x0040b407`); returns **EAX = shell***. **Not** ECX-thiscall (`MOV ESI,[ESP+0x14]`).
3. **Semantics:** MSVC-style **`_Tree` empty construct** for **isnil@+0x19 / node 0x1c**:
   - SEH frame (`LAB_009bda98` / FS:[0]).
   - Buy head via residual `FUN_0040bfc0` (`operator_new(0x1c)`; color@+0x18=1; isnil@+0x19=0).
   - Install `_Myhead` @ shell+4; force head isnil=1 @ +0x19.
   - Self-link L/P/R to head; `_Mysize` @ shell+8 = 0.
   - Return shell*.
4. **Layout:** shell head@+4, size@+8; node left@0, parent@+4, right@+8, color@**+0x18**, isnil@**+0x19**; node **0x1c**.
5. **Callees:** `FUN_0040bfc0` only (residual buyhead).
6. **Callers (1):** `FUN_0092b2a0` @ `0x0092b319` — `LEA EAX,[ESP+0x38]; PUSH EAX; CALL` (stack-local shell under MissionTracker secondary multi-target fill).
7. **Xrefs:** 1 UNCONDITIONAL_CALL (same).
8. **Name:** `StdTree_ConstructEmpty_Isnil19_Inferred` (Ghidra `FUN_0040b3b0`). Product demangle open → `_Inferred`.
9. **Family peers (do not merge):** ConstructEmpty isnil31 `00405f20`; ConstructEmpty isnil2d `00406190`; BuyHead isnil29/31/2d; sibling residual helpers under same parent `0040b440`/`0040b890`/`0040bc10` (other R13 slots).
10. **Decompile ≡ raw CF**; epilogue sealed via `read_memory` + `disassemble_function`. Ghidra `undefined …(void)` signature **false**.

### Gaps

- Product / MSVC demangle for temp map key/value under MissionTracker fill.  
- Dual of residual buyhead `FUN_0040bfc0` and sibling helpers.  
- Shell+0 allocator/comp identity.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0040b3b0_StdTree_ConstructEmpty_Isnil19_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0040b3b0_StdTree_ConstructEmpty_Isnil19_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0040b3b0_FUN_0040b3b0.md` |
| Annotated | `docs/reconstruction/raw/aa_0040b3b0_FUN_0040b3b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_ConstructEmpty_Isnil19_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040b3b0.cpp` |
| Function | `docs/reconstruction/functions/aa_0040b3b0_FUN_0040b3b0.md` |
| Function named | `docs/reconstruction/functions/aa_0040b3b0_StdTree_ConstructEmpty_Isnil19_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
MissionTracker_RefreshTrackedTargets_Inferred  0x0092bf60  [dualed R11-040]
  └─ MissionTracker_FillTrackedTargetSlots_Inferred  0x0092b2a0  [dualed R12-008 — parent]
        ├─ StdTree_ConstructEmpty_Isnil19_Inferred (0x0040b3b0)  [OWN R13-017]
        │     └─ FUN_0040bfc0  BuyHead isnil19 / 0x1c  [residual]
        ├─ FUN_0040b440 / FUN_0040b890 / FUN_0040bc10  sibling map helpers  [R13-018…020 residual slots]
        └─ … emit ≤4 tracked target slots …

Peer ConstructEmpty plates (do not merge):
  00405f20  ConstructEmpty_Isnil31  [WQ9K-C dualed]
  00406190  ConstructEmpty_Isnil2D  [dualed]
```

Partition system **inventory-transfer** explains why this VA was queued under that residual set (parent MissionTracker / inventory-transfer host proximity), not a product inventory-grid name for the unit itself.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0040b3b0-r13-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0040b3b0` | Port as **shared StdTree empty construct** for **isnil@+0x19 / color@+0x18 / node 0x1c**. **`__stdcall`** shell*; **ret 4**; EAX=shell*. Pair with residual buyhead `0040bfc0` (`operator_new(0x1c)`). Do not merge with isnil21/29/2d/31 ConstructEmpty peers. |
| Pair with | residual buyhead `0040bfc0`; dualed peer ConstructEmpty isnil31 `00405f20`; parent MissionTracker fill `0092b2a0` (stack-local shell only). |
| Naming caution | **Not** MissionTracker product method. **Not** inventory-grid UI. **Not** buyhead itself. **Not** isnil29/31 empty construct despite shared plate shape. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/inventory-transfer.md` residual tables (generic STL construct — not inventory UI)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x0040b3b0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + get_assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful `_Inferred` name; machine ABI corrections (stdcall RET 4; not void).  
- Odd behavior preserved: Ghidra listed void prototype; assembly has stack arg + ret 4.  
- `_Inferred` where English unproven. Terminal **false**. Never Runtime Confirmed.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
