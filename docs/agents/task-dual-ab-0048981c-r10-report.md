# Dual A/B report — R10-010 OWN-ONLY (`0x0048981c`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-010**  
**Scope:** VA `0x0048981c` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (incl. sibling `0x00489822`, parent body `0x005725a0`).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R10 residual dual seal — undualed callee of dualed InventoryGrid complete dtor.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r10_residual_partition_map.md` (R10-010).  
**Inventory name:** `operator_delete[]`.  
**Parent dual:** `0x005725a0` InventoryGrid_CompleteDtor (seed only).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0048981c` operator_delete_array (`operator delete[]`) | **accept** — 6 B IAT thunk CF/ABI/IAT slot/array-vs-scalar split sealed; CRT body external by design |

Path A (fidelity): **accept**.  
Path B (adversarial): jumptable / recursive-body / scalar-merge / inventory-only / noreturn / thiscall claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0048981c` — sealed facts

1. **Body:** `0x0048981c`–`0x00489821` inclusive (**6 B** / `0x6`); next function scalar `operator_delete` @ `0x00489822`.
2. **Bytes:** `FF 25 98 66 9C 00` = `JMP dword ptr [0x009c6698]`.
3. **ABI:** **`__cdecl`**; stack arg0 = `void*`; void; caller `ADD ESP,4` after CALL (sample `0x0057072d`→`0x00570732`).
4. **Semantics:** MSVC CRT **`operator delete[]`** import thunk. No local free logic.
5. **IAT:** slot `0x009c6698` (sole INDIRECTION from this VA); process-resolved target observed `0x006ea814` (CRT, not dualed).
6. **Callees:** none in-image (indirection only).
7. **Callers:** ≥100 xrefs (analyze cap) — InventoryGrid cells, cookie-vectors, UI/string arrays, skill buffers, Unwind helpers, etc.
8. **Parent seed:** dualed `InventoryGrid_CompleteDtor` `0x005725a0` frees cells `@+0x28` via this thunk.
9. **Name:** `operator_delete_array` (canonical FS-safe); CRT `operator delete[]`; Ghidra `operator_delete[]`; decomp `operator_delete__`. **No** `_Inferred`.
10. **Sibling (not OWN):** `operator_delete` @ `0x00489822` → IAT `[0x009c6694]`.
11. **Decompile artifacts:** jumptable warning + recursive self-call — **discarded**; assembly authoritative.

### Gaps

- External CRT `operator delete[]` implementation (correctly out of scope).  
- Runtime / bit-exact image-wide / differential.  

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0048981c_operator_delete_array.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0048981c_operator_delete_array.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_0048981c_operator_delete__.md` |
| Annotated | `docs/reconstruction/raw/aa_0048981c_operator_delete__.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/operator_delete_array.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/operator_delete__.cpp` |
| Function FUN | `docs/reconstruction/functions/aa_0048981c_FUN_0048981c.md` |
| Function named | `docs/reconstruction/functions/aa_0048981c_operator_delete_array.md` |
| Function alias | `docs/reconstruction/functions/aa_0048981c_operator_delete__.md` |

---

## Chain context (not dualled; evidence only)

```text
InventoryGrid_CompleteDtor  0x005725a0  [dualed MEGA-061 accept]  parent seed
  └─ operator_delete[]      0x0048981c  [OWN R10-010]
        └─ JMP [IAT 0x009c6698] → CRT operator delete[]  [external]

InventoryGrid_AllocateCellArray_Inferred  0x00570720
  └─ CALL 0x0048981c; ADD ESP,4   (cdecl returns)

Sibling (do not merge):
  operator_delete  0x00489822  → JMP [0x009c6694]  [R10-001 OWN if dualed separately]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0048981c-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0048981c` | Port as **CRT `operator delete[]` / `delete[]`**. **cdecl** `void(void*)`. Prefer host CRT; if emulating import thunk, single `JMP [IAT]`. **Do not** invent free body. **Do not** merge with scalar `operator_delete` `00489822`. **Do not** treat as InventoryGrid API. |
| Pair with | scalar `operator_delete` `00489822`; `operator_new` / `operator_new[]` family; callers that pair with `new[]` cookie vectors. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (CRT — not inventory product)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Not written by this agent.**

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x0048981c`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + assembly context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean uses meaningful CRT name `operator_delete_array`; twin keeps `operator_delete__`.  
- Odd behavior preserved: decompiler jumptable/self-call discarded in favor of bytes.  
- No `_Inferred` (CRT identity sealed). Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
