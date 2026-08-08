# Dual A/B report — WQ9F-G OWN-ONLY (`0x0051ce00`, `0x0051e120`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9F-G**  
**Scope:** VAs `0x0051ce00`, `0x0051e120` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / systems residual / other parent ledgers.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth3_partition_map.md` → **WQ9F-G**.  
**Work item:** WQ-009 depth-3 residual dual seal (map erase node isnil15 + map host tidy calling erase-range isnil1d).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0051ce00` Map_EraseNode_Isnil15 | **accept-with-gaps** — erase CF/ABI/RET8/post-delete size--/*out + isnil@+0x15 sealed; product residual |
| `aa_0051e120` Map_Tidy_FreeHead_Isnil1d_Inferred | **accept-with-gaps** — tidy CF/ABI/null epilogue + dualed erase-range callee sealed; host English residual |

Path A (fidelity): as above.  
Path B (adversarial): no CF rejects; decompiler noreturn/unreachable traps closed via bytes; isnil29/IntKey/same-VA mix-ups rejected.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0051ce00` — sealed facts

1. **Body:** `0x0051ce00`–`0x0051d0b5` inclusive (**694 B** / `0x2B6`); exclusive end `0x0051d0b6`; pad `CC`.
2. **ABI:** **`__thiscall`**; ECX = map*; stack `Node** outIt`, `Node* pNode`; **RET 8** (`C2 08 00`).
3. **Semantics:** MSVC-style **single-node erase**:
   - isnil@+0x15 non-zero → throw `"invalid map/set<T> iterator"` @ `0x00a152f0`.
   - Successor via `FUN_00673070`; unlink + RB rebalance.
   - Leftmost/rightmost: `FUN_004e12a0` / `FUN_00421b70`.
   - Black fixup: Lrotate `FUN_004e22d0` / Rrotate `FUN_006753b0` (ECX=map).
   - `operator_delete(node)` **falls through** (decomp false-noreturn).
   - If `size > 0` then `size--`; `*outIt = successor`.
4. **isnil / color:** **+0x15** / **+0x14**.
5. **Two-child path:** bytes `0x0051cf20`–`0x0051cf77` (decomp "unreachable" — live).
6. **Callers (3):** `Map_EraseRange_Isnil15` (`0x0051d7c0`) @ `0x0051d85f`; `FUN_0051d940` @ `0x0051d9df`; `FUN_0052c930` @ `0x0052c988`.
7. **Xrefs:** 3 UNCONDITIONAL_CALL.
8. **Name:** `Map_EraseNode_Isnil15` (Ghidra `FUN_0051ce00`). Structural; pairs dualed `Map_EraseRange_Isnil15`. Distinct from `Map_EraseNode_IntKey` (`0x005d1df0`).
9. **Decompile ≡ raw CF** with post-delete commit sealed by `read_memory`.

### Gaps — `0051ce00`

1. Product / PDB for this isnil15 instantiation vs `Map_EraseNode_IntKey`.  
2. Value size / K type English.  
3. Nested duals of Min/Max/rot callees (not OWN).  
4. Runtime / bit-exact / differential.

### Dual A/B — `0051ce00`

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051ce00_Map_EraseNode_Isnil15.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051ce00_Map_EraseNode_Isnil15.md` | **accept-with-gaps** |

### Files — `0051ce00`

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0051ce00_FUN_0051ce00.md` |
| Annotated | `docs/reconstruction/raw/aa_0051ce00_FUN_0051ce00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_EraseNode_Isnil15.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051ce00.cpp` |
| Function | `docs/reconstruction/functions/aa_0051ce00_FUN_0051ce00.md` |
| Function named | `docs/reconstruction/functions/aa_0051ce00_Map_EraseNode_Isnil15.md` |

---

## VA `0x0051e120` — sealed facts

1. **Body:** `0x0051e120`–`0x0051e14d` inclusive (**46 B** / `0x2E`); exclusive end `0x0051e14e`; pad `CC`.
2. **ABI:** **`__fastcall`/`__thiscall`-style**; ECX = map facade*; no stack args; bare **RET** (`C3`); void.
3. **Semantics:** MSVC-style **map tidy**:
   - Full-range erase via dualed `Map_EraseRange_Isnil1d_Inferred` (`0x0051d700`): `out=&scratch`, `first=*head`, `last=head`.
   - `operator_delete(head)` **falls through** (decomp false-noreturn).
   - Null `head` (`map+4`) and `size` (`map+8`).
   - **Does not free** map facade.
4. **Callees:** `Map_EraseRange_Isnil1d_Inferred`; `operator_delete`.
5. **Caller (1):** atexit thunk `FUN_009c3940` @ `0x009c3940`: `MOV ECX,0xb04240; JMP 0x0051e120`.
6. **Peer:** dualed `Map_Tidy_FreeHead` `0x0051da30` (same 46 B template; isnil@+0x29 erase).
7. **Name:** `Map_Tidy_FreeHead_Isnil1d_Inferred` (Ghidra `FUN_0051e120`). Structural twin + isnil discriminator; product host English open → `_Inferred`.
8. **Decompile ≡ raw CF** with null epilogue sealed by `read_memory`.

### Gaps — `0051e120`

1. Product/RTTI English for global host `0x00b04240`.  
2. Exact `map<K,V>` of isnil@+0x1d family.  
3. Nested free/erase-node duals of erase-range (not OWN).  
4. Runtime / bit-exact / differential.

### Dual A/B — `0051e120`

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051e120_Map_Tidy_FreeHead_Isnil1d_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051e120_Map_Tidy_FreeHead_Isnil1d_Inferred.md` | **accept-with-gaps** |

### Files — `0051e120`

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0051e120_FUN_0051e120.md` |
| Annotated | `docs/reconstruction/raw/aa_0051e120_FUN_0051e120.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_Tidy_FreeHead_Isnil1d_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051e120.cpp` |
| Function | `docs/reconstruction/functions/aa_0051e120_FUN_0051e120.md` |
| Function named | `docs/reconstruction/functions/aa_0051e120_Map_Tidy_FreeHead_Isnil1d_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Map_EraseRange_Isnil15 (0x0051d7c0)                    [dualed WQ9E-J]
  └─ Map_EraseNode_Isnil15 (0x0051ce00)                [OWN WQ9F-G]
       ├─ Tree_Successor isnil15 (0x00673070)
       ├─ Min (0x004e12a0) / Max (0x00421b70)
       └─ Lrot (0x004e22d0) / Rrot (0x006753b0)

atexit FUN_009c3940 (ECX=0xb04240)
  └─ Map_Tidy_FreeHead_Isnil1d_Inferred (0x0051e120)  [OWN WQ9F-G]
       └─ Map_EraseRange_Isnil1d_Inferred (0x0051d700) [dualed WQ9E-I]
```

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0051ce00` | Port as **shared RB single-node erase** for **isnil@+0x15 / color@+0x14** maps — not skill logic. **RET 8**; post-delete **size--** + **`*outIt=succ`**. Do not trust decomp noreturn on delete. Pair with range `Map_EraseRange_Isnil15`. Do not reuse isnil@+0x29 `Map_EraseNode` offsets. |
| `0051e120` | Port as **map tidy**: full-range erase (`Map_EraseRange_Isnil1d_Inferred`) + free head + null head/size. Same template as `Map_Tidy_FreeHead`. Does **not** free facade. Static global host `0xb04240` only known consumer. |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0051ce00-0051e120-wq9fg-report.md` |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual table  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x0051ce00`, `0x0051e120`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra iVar blank-line paste).  
- Odd behavior preserved: decomp false-noreturn on delete; “unreachable” two-child blocks live.  
- `_Inferred` where English unproven (`Map_Tidy_FreeHead_Isnil1d_Inferred`); structural High for erase node.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
