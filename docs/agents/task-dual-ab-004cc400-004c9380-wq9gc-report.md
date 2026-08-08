# Dual A/B report — WQ9G-C OWN-ONLY (`0x004cc400`, `0x004c9380`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9G-C**  
**Scope:** VAs `0x004cc400`, `0x004c9380` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` + `disassemble_function` + `read_memory` + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth4_partition_map.md` → **WQ9G-C**.  
**Work item:** WQ-009 depth-4 residual dual seal — sole caller of insert-hint `004cc220` + caller of insert-or-find int key `004cbe20`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004cc400` StdMap_OperatorIndex_Tfid_Isnil29_Inferred | **accept-with-gaps** — thiscall RET4 / TFID pair LB+eq / insert-hint sole caller / mapped@+0x20 default0 sealed; product English open |
| `aa_004c9380` Object_AggroMap_ExportToIntKeyMap_Inferred | **accept-with-gaps** — thiscall RET4 / head+0x158 inorder / score-key export via dualed int insert-or-find sealed; decomp ABI gap closed by bytes; product English open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): always-insert / int-key op[] / mutates-source / is-insert-or-find / fastcall-no-arg mix-ups **rejected**.

---

## VA `0x004cc400` — sealed facts

1. **Body:** `0x004cc400`–`0x004cc469` exclusive (**105 B** / `0x69`); terminal **`C2 04 00`**; pad `CC`.
2. **ABI:** **`__thiscall`**; ECX = map shell* (`head@+4`); stack `uint32_t* key16` (4 dwords); returns **`int32_t*` mapped** at node+0x20; **RET 4**.
3. **Semantics:** MSVC **`map::operator[]`** (get-or-insert mapped):
   - `StdMap_LowerBound_Tfid_Isnil29` (`0x004cb4b0`).
   - Hit if not-end ∧ ¬(key < node): hi **signed** primary @ +0x14, lo **unsigned** secondary @ +0x10.
   - Miss: stage `{key[0..3], mapped=0}`; **`StdTree_InsertHint_Isnil29_Inferred`** (`0x004cc220`).
   - Return `node + 0x20`.
4. **Sole caller of insert-hint** `0x004cc220` (WQ9F-E dual; 1 xref).
5. **Callers:** `FUN_004ca760` (writes score into returned mapped*); `FUN_004ea350` ×3; site `0x005dd869`.
6. **Xrefs:** 5 UNCONDITIONAL_CALL.
7. **Name:** `StdMap_OperatorIndex_Tfid_Isnil29_Inferred` (Ghidra `FUN_004cc400`). Product demangle open → `_Inferred`.
8. **Decompile ≡ raw CF**; RET 4 + `ADD EAX,0x20` sealed via `read_memory`.

### Gaps

- Product / MSVC demangle for map value_type / owning method.  
- Full 16 B TFID storage vs 8 B ordered-pair compare English.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004cc400_StdMap_OperatorIndex_Tfid_Isnil29_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004cc400_StdMap_OperatorIndex_Tfid_Isnil29_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004cc400_FUN_004cc400.md` |
| Annotated | `docs/reconstruction/raw/aa_004cc400_FUN_004cc400.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_OperatorIndex_Tfid_Isnil29_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004cc400.cpp` |
| Function | `docs/reconstruction/functions/aa_004cc400_FUN_004cc400.md` |
| Function named | `docs/reconstruction/functions/aa_004cc400_StdMap_OperatorIndex_Tfid_Isnil29_Inferred.md` |

---

## VA `0x004c9380` — sealed facts

1. **Body:** `0x004c9380`–`0x004c9428` exclusive (**168 B** / `0xA8`); terminal **`C2 04 00`**; pad `CC`.
2. **ABI:** **`__thiscall`**; ECX = object* with aggro **head @ +0x158**; stack `MapShell* dest`; void; **RET 4**. Decompiler `__fastcall`/no-arg **wrong** (bytes supersede).
3. **Semantics:** **Export** aggro map → dest int-key tree:
   - Inorder from `*head` until head; isnil@**+0x29** successor.
   - Per node: value **key = score @ +0x20**; TFID dwords from **+0x10** packed at value **+8**; value **+4 unwritten**.
   - `StdMap_InsertOrFind_IntKey_Isnil29_Inferred` (`0x004cbe20`) with **ECX = dest**.
4. **Odd:** equal scores → insert-or-find **no rewrite** (may drop dup TFID payloads).
5. **Caller (1):** `CVOGHBAIBase_GetTargetFromAggro` (`0x00638ec0`) @ `0x00638f50`.
6. **Xrefs:** 1 UNCONDITIONAL_CALL.
7. **Name:** `Object_AggroMap_ExportToIntKeyMap_Inferred` (Ghidra `FUN_004c9380`). Product method English open → `_Inferred`.
8. **Walk CF ≡ decompile**; ABI/value pack sealed by `disassemble_function` + `read_memory`.

### Gaps

- Product / PDB method + host class English (Object vs AI layout).  
- Dest value_type English; intent of unwritten value[+4].  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004c9380_Object_AggroMap_ExportToIntKeyMap_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004c9380_Object_AggroMap_ExportToIntKeyMap_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004c9380_FUN_004c9380.md` |
| Annotated | `docs/reconstruction/raw/aa_004c9380_FUN_004c9380.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_AggroMap_ExportToIntKeyMap_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c9380.cpp` |
| Function | `docs/reconstruction/functions/aa_004c9380_FUN_004c9380.md` |
| Function named | `docs/reconstruction/functions/aa_004c9380_Object_AggroMap_ExportToIntKeyMap_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004cc400` | Port as **map operator[]** for TFID pair-key / isnil29: LB → eq → return mapped*; else insert-hint with **mapped=0**. **RET 4** thiscall. Pair only with lower_bound `004cb4b0` + hint `004cc220`. Do **not** merge with int-key insert-or-find or Val12 peers. |
| `004c9380` | Port as **aggro export**: walk head **+0x158**, insert-or-find into dest keyed by **score**. Preserve unwritten value dword1 + equal-score collapse. Used by `GetTargetFromAggro` temp tree. |
| Pair with | insert-hint `004cc220`; int insert-or-find `004cbe20`; lower_bound TFID `004cb4b0`; aggro decay `004c8610`; caller `CVOGHBAIBase_GetTargetFromAggro` |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` (or containers / aggro residual table)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x004cc400`, `0x004c9380`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Clean sources use meaningful names (not Ghidra iVar blank-line paste).  
- Odd behavior preserved: mapped default 0 on op[]; unwritten export dword1; equal-score no-rewrite.  
- `_Inferred` where English unproven; Terminal **false**.

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004cc400-004c9380-wq9gc-report.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
