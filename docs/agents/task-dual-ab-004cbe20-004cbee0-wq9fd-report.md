# Dual A/B report — WQ9F-D OWN-ONLY (`0x004cbe20`, `0x004cbee0`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9F-D**  
**Scope:** VAs `0x004cbe20`, `0x004cbee0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth3_partition_map.md` → **WQ9F-D**.  
**Work item:** WQ-009 depth-3 residual dual seal — insert-or-find **callers** of dualed `StdTree_InsertAndRebalance_Isnil29` (`0x004cbb60`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004cbe20` StdMap_InsertOrFind_IntKey_Isnil29_Inferred | **accept-with-gaps** — CF/ABI/RET8/signed int key@+0x10/isnil@+0x29/equal-no-write/insert callee sealed; product T residual |
| `aa_004cbee0` StdMap_InsertOrFind_PairKey_Isnil29_Inferred | **accept-with-gaps** — CF/ABI/RET8/pair hi-signed lo-unsigned/isnil@+0x29/equal-no-write sealed; product pair English residual |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): always-insert / Val12 / product Named_CalleeOf / unsigned-int-key / hit-rewrite claims **falsified**; pair vs int-key mix-up **falsified**.

---

## VA `0x004cbe20` — sealed facts

1. **Body:** `0x004cbe20`–`0x004cbed8` exclusive (**184 B** / `0xB8`); pad `CC`; next fn `004cbee0`.
2. **ABI:** **`__thiscall`**; ECX = map shell*; stack `InsertPair* out`, `Val* value`; **RET 8** (`C2 08 00` ×3).
3. **Semantics:** MSVC **insert-or-find** (unique key):
   - Walk from root; isnil@**+0x29**; **signed** key @ node**+0x10** / `*value` (`SETL`).
   - goLeft && leftmost → insert addLeft=1 via `FUN_004cbb60`.
   - goLeft else → predecessor `FUN_004cb4f0` then maybe insert.
   - `node.key < key` → insert; else **equal** `{it, inserted=0}` **no** mapped rewrite.
4. **Insert worker:** dualed `StdTree_InsertAndRebalance_Isnil29_Inferred` (`0x004cbb60`).
5. **Callers (2):** `FUN_004c9380` @ `0x004c93d1`; `FUN_00518ca0` (`Skill_InsertActiveCastBinding_Inferred`) @ `0x00518cda`.
6. **Xrefs:** 2 UNCONDITIONAL_CALL.
7. **Name:** `StdMap_InsertOrFind_IntKey_Isnil29_Inferred` (Ghidra `FUN_004cbe20`). Scaffold GetTargetFromAggro alias **reject**. Product demangle open → `_Inferred`.
8. **Decompile ≡ raw CF**; RET/isnil/SETL sealed via `read_memory`.

### Gaps

- Product / MSVC demangle for map value_type.  
- Predecessor `FUN_004cb4f0` undualed residual.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004cbe20_StdMap_InsertOrFind_IntKey_Isnil29_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004cbe20_StdMap_InsertOrFind_IntKey_Isnil29_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004cbe20_FUN_004cbe20.md` |
| Annotated | `docs/reconstruction/raw/aa_004cbe20_FUN_004cbe20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFind_IntKey_Isnil29_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004cbe20.cpp` |
| Function | `docs/reconstruction/functions/aa_004cbe20_FUN_004cbe20.md` |
| Function named | `docs/reconstruction/functions/aa_004cbe20_StdMap_InsertOrFind_IntKey_Isnil29_Inferred.md` |

---

## VA `0x004cbee0` — sealed facts

1. **Body:** `0x004cbee0`–`0x004cbfb2` exclusive (**210 B** / `0xD2`); pad `CC`.
2. **ABI:** **`__thiscall`**; ECX = map shell*; stack `InsertPair* out`, `PairKey* value`; **RET 8**.
3. **Semantics:** MSVC **insert-or-find** with **pair key**:
   - **hi** signed primary @ node**+0x14** / `value[1]`; **lo** unsigned secondary @ node**+0x10** / `value[0]`.
   - go right when `node <= key` (hi signed, lo unsigned `JAE`); same insert/pred/equal pattern as int-key peer.
4. **Insert worker:** same dualed `0x004cbb60`.
5. **Caller (1):** `FUN_004cc220` @ `0x004cc3ae` (hint-insert fallthrough).
6. **Xrefs:** 1 UNCONDITIONAL_CALL.
7. **Name:** `StdMap_InsertOrFind_PairKey_Isnil29_Inferred` (Ghidra `FUN_004cbee0`). Scaffold VOG_DEBUG alias **reject**. Pair product English open → `_Inferred`.
8. **Decompile ≡ raw CF**; pair order sealed by bytes.

### Gaps

- Product pair type (TFID vs custom) demangle.  
- Hint parent `FUN_004cc220` / predecessor undualed (other partitions).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004cbee0_StdMap_InsertOrFind_PairKey_Isnil29_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004cbee0_StdMap_InsertOrFind_PairKey_Isnil29_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004cbee0_FUN_004cbee0.md` |
| Annotated | `docs/reconstruction/raw/aa_004cbee0_FUN_004cbee0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_InsertOrFind_PairKey_Isnil29_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004cbee0.cpp` |
| Function | `docs/reconstruction/functions/aa_004cbee0_FUN_004cbee0.md` |
| Function named | `docs/reconstruction/functions/aa_004cbee0_StdMap_InsertOrFind_PairKey_Isnil29_Inferred.md` |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004cbe20-004cbee0-wq9fd-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004cbe20` | Port as **unique insert-or-find** shell: **signed** int key @+0x10, isnil@**+0x29**, **RET 8** thiscall. Equal → no mapped rewrite (skill active-cast map depends on this). Insert via dualed `004cbb60`. Do **not** merge with Val12 / isnil15 peers. |
| `004cbee0` | Port as **pair-key** insert-or-find on same node family: **hi signed primary**, **lo unsigned secondary**. Same insert worker. Do **not** merge with int-key peer compares. |
| Pair with | dualed insert `004cbb60`; predecessor residual `004cb4f0`; skill caller `00518ca0`; hint parent `004cc220` (WQ9F-E). |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` (tree insert-or-find residual)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x004cbe20`, `0x004cbee0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra iVar blank-line paste).  
- Odd behavior preserved: equal-key no rewrite; pair mixed signed/unsigned order.  
- `_Inferred` where English unproven; Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
