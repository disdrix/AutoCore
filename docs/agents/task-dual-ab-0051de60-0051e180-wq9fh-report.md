# Dual A/B report — WQ9F-H OWN-ONLY (`aa_0051de60`, `aa_0051e180`)

**Date:** 2026-08-04  
**Agent:** WQ9F-H OWN-ONLY  
**Scope:** OWN ONLY VAs `0x0051de60`, `0x0051e180`. Dual A/B + trio raw/annotated/clean + function records.  
**Work item:** WQ-009 depth-3 residual — map/skill-neighborhood helpers near dualed erase/tidy.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth3_partition_map.md` → **WQ9F-H**.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / VERIFICATION_MATRIX / NAMING_REGISTRY / systems residual / other parent ledgers.  
**Ghidra:** `batch_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Terminal:** **false**

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0051de60` SkillCNDHash_ScalarDeletingDtor_Inferred | **accept-with-gaps** — scalar dtor CF+ABI+vtbl[0] sealed; product English open; complete dtor not OWN |
| `aa_0051e180` Map_Tidy_FreeHead_B | **accept-with-gaps** — tidy CF/ABI/nulls sealed by bytes (decomp incomplete); product map host open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): no CF rejects; complete-as-this-VA, vector-dtor, facade-dtor, identity-merge-with-Tidy_A all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## Sealed facts — `0x0051de60` SkillCNDHash_ScalarDeletingDtor_Inferred

1. **Body:** `0x0051de60`–`0x0051de7d` inclusive (**30 B** / `0x1E`); `CC` pad then complete dtor `0x0051de80`.

2. **ABI:** MSVC **`__thiscall`**.  
   - `ECX` = this (skill CNDHash*)  
   - stack flags byte  
   - returns this in EAX  
   - **`RET 4`** (`C2 04 00`)

3. **Algorithm:**  
   - Always `FUN_0051de80()` (complete dtor; HashError:Destructor on lock)  
   - If `(flags & 1)`: `operator_delete(this)`  
   - Return this

4. **Identity:** vtbl[0] of `PTR_FUN_009ce1b8` @ DATA `0x009ce1b8` = `0x0051de60`. Same vtbl as dualed `SkillCNDHash_Ctor_Inferred` (`0x0051dd60`). No code CALL sites (virtual dispatch only).

5. **Name:** `SkillCNDHash_ScalarDeletingDtor_Inferred` — family High; product English **Inferred**.  
   Reject complete-dtor identity for this VA; reject vector deleting dtor.

6. **Decompile ≡ disasm** for CF; false noreturn on delete ignored (epilogue sealed).

### Gaps — `0051de60`

1. Product/PDB demangle for host class.  
2. Complete dtor `FUN_0051de80` dual (not OWN).  
3. Full vtbl method map beyond slot 0.  
4. Runtime / bit-exact open.

### Dual A/B — `0051de60`

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051de60_SkillCNDHash_ScalarDeletingDtor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051de60_SkillCNDHash_ScalarDeletingDtor_Inferred.md` | **accept-with-gaps** |

### Files — `0051de60`

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0051de60_FUN_0051de60.md` |
| Annotated | `docs/reconstruction/raw/aa_0051de60_FUN_0051de60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/SkillCNDHash_ScalarDeletingDtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051de60.cpp` |
| Function | `docs/reconstruction/functions/aa_0051de60_FUN_0051de60.md` |
| Function named | `docs/reconstruction/functions/aa_0051de60_SkillCNDHash_ScalarDeletingDtor_Inferred.md` |

---

## Sealed facts — `0x0051e180` Map_Tidy_FreeHead_B

1. **Body:** `0x0051e180`–`0x0051e1ad` inclusive (**46 B** / `0x2E`); `CC` pad after bare `ret`.

2. **ABI:** **`__fastcall`/`__thiscall`-style** ECX = map*; void; **bare `RET`** (`C3`). head@+4, size@+8.

3. **Algorithm (bytes authority — decompiler incomplete):**  
   - Full-range erase: `Map_EraseRange_B(map, &out, *head, head)` @ `0x0051d880`  
   - `operator_delete(head)`  
   - Null head and size  
   - **Does not free map facade**

4. **Identity:** 46 B twin of dualed `Map_Tidy_FreeHead` (`0x0051da30`); erase callee is dualed `Map_EraseRange_B` (not `Map_EraseRange`). Discriminate vs `FUN_0051e150` (isnil15 tidy).

5. **Caller (1 external):** atexit thunk `FUN_009c3970` = `MOV ECX,0x00b0427c` / `JMP 0x0051e180`.

6. **Name:** `Map_Tidy_FreeHead_B` — structural High; pairs `Map_EraseRange_B`. Reject facade complete dtor; reject identity merge with `Map_Tidy_FreeHead`.

7. **Decompile ⊊ bytes** for post-delete nulls; **bytes sealed**.

### Gaps — `0051e180`

1. Product `map<K,V>` / host class at static `0x00b0427c`.  
2. Peer tidy `FUN_0051e150` not OWN.  
3. Runtime / bit-exact open.

### Dual A/B — `0051e180`

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051e180_Map_Tidy_FreeHead_B.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051e180_Map_Tidy_FreeHead_B.md` | **accept-with-gaps** |

### Files — `0051e180`

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0051e180_FUN_0051e180.md` |
| Annotated | `docs/reconstruction/raw/aa_0051e180_FUN_0051e180.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_Tidy_FreeHead_B.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051e180.cpp` |
| Function | `docs/reconstruction/functions/aa_0051e180_FUN_0051e180.md` |
| Function named | `docs/reconstruction/functions/aa_0051e180_Map_Tidy_FreeHead_B.md` |

---

## Chain context (not dualled; evidence only)

```text
SkillCNDHash_Ctor_Inferred (0x0051dd60)                 [prior dual WQ9D-A]
  └─ installs PTR_FUN_009ce1b8
       └─ [0] SkillCNDHash_ScalarDeletingDtor_Inferred (0x0051de60)  [OWN]
              └─ FUN_0051de80 complete dtor                  [not OWN]
                   ├─ SkillCNDHash_DestroyBucketTable (0x004cba60) [prior]
                   └─ lock check HashError:Destructor

Map_EraseRange_B (0x0051d880)                           [prior dual WQ9D]
  └─ Map_Tidy_FreeHead_B (0x0051e180)                   [OWN]
       └─ atexit FUN_009c3970 → static map 0x00b0427c

Map_Tidy_FreeHead (0x0051da30)                          [prior dual WQ9E-J]
  └─ uses Map_EraseRange (0x0051c7c0) — peer A, not this VA
```

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0051de60` | Port as MSVC scalar deleting dtor only: complete then optional free on bit0; **ret 4**; return this. Do not inline complete dtor member teardown into this VA. Virtual entry for skill CNDHash. |
| `0051e180` | Port as map tidy free-head: full erase via **EraseRange_B**, free sentinel, null head+size. Do **not** free facade. Bare RET. Trust bytes over Ghidra noreturn collapse after delete. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ disassemble_function / callers / xrefs / assembly_context).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean uses meaningful names (not Ghidra iVar paste); `_Inferred` where product English unproven.  
- Odd behavior preserved (false-noreturn decompiler truncation documented).  
- **Terminal false.**
