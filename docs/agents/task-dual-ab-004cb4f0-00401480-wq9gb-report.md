# Dual A/B report — WQ9G-B OWN-ONLY (`0x004cb4f0`, `0x00401480`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9G-B**  
**Scope:** VAs `0x004cb4f0`, `0x00401480` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth4_partition_map.md` → **WQ9G-B**.  
**Work item:** WQ-009 depth-4 residual dual seal — insert predecessor residual + 2-dword key compare for insert-hint.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004cb4f0` StdTree_Predecessor_Isnil29_Inferred | **accept-with-gaps** — CF/ECX ABI/isnil@+0x29/three-arm pred/leaf sealed; product demangle residual |
| `aa_00401480` StdPairKey_Less_HiSignedLoUnsigned_Inferred | **accept-with-gaps** — CF/RET8/hi-signed lo-unsigned strict less/leaf sealed; product pair English residual |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): successor / isnil15 / EDX-it / always-signed-pair / lo-primary / VOG scaffold claims **falsified**.

---

## VA `0x004cb4f0` — sealed facts

1. **Body:** `0x004cb4f0`–`0x004cb540` exclusive (**80 B** / `0x50`); pad `CC`; next fn `004cb550`.
2. **ABI:** **ECX = Node**** (`8B 01`); bare **`C3`**; void; mutates `*it` only. Leaf (no callees).
3. **Semantics:** MSVC-style **tree predecessor** (iterator--):
   - isnil@**+0x29**; left@+0, parent@+4, right@+8.
   - isnil → `*it = right`; else left-subtree **rightmost**; else climb while left-child.
4. **Callers (5):** `FUN_00406040`; dualed `StdMap_InsertOrFind_IntKey_Isnil29_Inferred` (`0x004cbe20`); dualed `StdMap_InsertOrFind_PairKey_Isnil29_Inferred` (`0x004cbee0`); dualed `StdTree_InsertHint_Isnil29_Inferred` (`0x004cc220`); `FUN_005a3b00`.
5. **Xrefs:** 5 UNCONDITIONAL_CALL. Call-site: `LEA ECX,[ESP+…]` → `CALL 0x004cb4f0`.
6. **Name:** `StdTree_Predecessor_Isnil29_Inferred` (Ghidra `FUN_004cb4f0`). Scaffold VOGClient Named_CalleeOf **reject**. Product demangle open → `_Inferred`.
7. **Decompile ≡ raw CF**; isnil/ECX/C3 sealed via `read_memory` + assembly context.
8. **Peer:** algorithm matches dualed isnil15 predecessors; family is **isnil29** (insert rebalance / hint).

### Gaps

- Product / MSVC demangle for node value_type.  
- Whether every caller shares identical value payload layout.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004cb4f0_StdTree_Predecessor_Isnil29_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004cb4f0_StdTree_Predecessor_Isnil29_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004cb4f0_FUN_004cb4f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004cb4f0_FUN_004cb4f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Predecessor_Isnil29_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004cb4f0.cpp` |
| Function | `docs/reconstruction/functions/aa_004cb4f0_FUN_004cb4f0.md` |
| Function named | `docs/reconstruction/functions/aa_004cb4f0_StdTree_Predecessor_Isnil29_Inferred.md` |

---

## VA `0x00401480` — sealed facts

1. **Body:** `0x00401480`–`0x004014a5` exclusive (**37 B** / `0x25`); pad `CC`.
2. **ABI:** two stack `uint32_t*` args; **`C2 08 00` RET 8**; EAX = 0|1. Leaf.
3. **Semantics:** strict **less-than** on 2-dword key:
   - **hi** @+4 **signed** primary (`JG`/`JL`).
   - **lo** @+0 **unsigned** secondary (`JAE`).
   - `return (a.hi < b.hi) || (a.hi == b.hi && a.lo < b.lo)`.
4. **Callers (2; 10 xrefs):** `FUN_00406560` (5 sites); dualed `StdTree_InsertHint_Isnil29_Inferred` (`0x004cc220`, 5 sites). Node keys at **+0x10/+0x14**.
5. **Name:** `StdPairKey_Less_HiSignedLoUnsigned_Inferred` (Ghidra `FUN_00401480`). Scaffold VOG_DEBUG Named_CalleeOf **reject**. Pair product English open → `_Inferred`.
6. **Decompile ≡ raw CF**; signedness order sealed by bytes (not decompiler alone).
7. **Order match:** same hi/lo policy as dualed pair insert-or-find `0x004cbee0` (inlined there; this is the shared leaf for hint shells).

### Gaps

- Product pair type demangle (TFID vs custom).  
- Full map inventory beyond two hint callers.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00401480_StdPairKey_Less_HiSignedLoUnsigned_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00401480_StdPairKey_Less_HiSignedLoUnsigned_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00401480_FUN_00401480.md` |
| Annotated | `docs/reconstruction/raw/aa_00401480_FUN_00401480.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdPairKey_Less_HiSignedLoUnsigned_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00401480.cpp` |
| Function | `docs/reconstruction/functions/aa_00401480_FUN_00401480.md` |
| Function named | `docs/reconstruction/functions/aa_00401480_StdPairKey_Less_HiSignedLoUnsigned_Inferred.md` |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004cb4f0-00401480-wq9gb-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004cb4f0` | Port as **isnil29 tree predecessor**: **ECX = Node****, bare ret, isnil@**+0x29**, left/parent/right @0/4/8. Required by insert-or-find goLeft and insert-hint prev-neighbor. Do **not** use isnil15 peers or EDX ABI. |
| `00401480` | Port as **2-dword pair-key less**: hi **signed** primary, lo **unsigned** secondary, **RET 8**, returns 0\|1. Required by isnil29 insert-hint. Do **not** invert hi/lo or force both-signed. |
| Pair with | dualed insert `004cbb60`; insert-or-find `004cbe20`/`004cbee0`; insert-hint `004cc220`; peer hint residual `00406560` / successor residual `004cb270` (other partitions). |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` (tree predecessor + pair-key less residual)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x004cb4f0`, `0x00401480`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra iVar blank-line paste).  
- Odd behavior preserved: mixed signed/unsigned pair order; predecessor three-arm header path.  
- `_Inferred` where English unproven; Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
