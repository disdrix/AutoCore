# Dual A/B report — R10-001 OWN-ONLY (`0x00489822`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-001**  
**Scope:** VA `0x00489822` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (incl. `0x0048981c` operator_delete[], parent `0x005725a0`).  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs + `get_xrefs_to` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** R10 residual dual seal — partition row R10-001 / inventory-transfer residual under parent `0x005725a0` (body is shared CRT free thunk).  
**Hint consumed:** inventory-transfer parent seed → **ranking only**; not this VA's identity.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00489822` operator_delete | **accept** — 6 B IAT JMP sealed; cdecl scalar delete; CRT name; noreturn/jumptable decompiler artifacts rejected |

Path A (fidelity): **accept**.  
Path B (adversarial): inventory-product / true-noreturn / recursive-body / merge-with-delete[]-or-free / thiscall **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00489822` — sealed facts

1. **Body:** `0x00489822`–`0x00489827` inclusive (**6 B** / `0x6`); next import thunk @ `0x00489828`.
2. **Hex:** `FF 25 94 66 9C 00` → **`JMP dword ptr [0x009C6694]`**.
3. **ABI:** **cdecl** `void operator_delete(void *block)`; stack formal; caller `ADD ESP,4`; **returns**.
4. **Semantics:** MSVC **IAT import thunk** for CRT scalar `operator delete` — no local free body.
5. **Callees:** none static (indirect IAT); live IAT dword sample `0x006EA824` @ `009C6694`.
6. **Callers / xrefs:** **5045** Ghidra callers (~2463 FUN/Catch + ~2568 Unwind); xref list tool-capped at 100.
7. **Name:** `operator_delete` (Ghidra custom CRT symbol). No `_Inferred`. No `FUN_00489822`.
8. **Siblings (do not merge):** `operator_delete[]` @ `0x0048981c`; C `free` @ `0x004898f4`.
9. **Decompile ≡ raw** as artifact; machine CF via `read_memory` (false noreturn / jumptable / recursive call discarded).

### Gaps (non-blocking)

- CRT module/export behind IAT (runtime bind).  
- Runtime / bit-exact / differential of free internals.  
- Terminal Confirmed open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00489822_operator_delete.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00489822_operator_delete.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00489822_operator_delete.md` |
| Annotated | `docs/reconstruction/raw/aa_00489822_operator_delete.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/operator_delete.cpp` |
| Function named | `docs/reconstruction/functions/aa_00489822_operator_delete.md` |
| Function FUN pair | `docs/reconstruction/functions/aa_00489822_FUN_00489822.md` |

---

## Chain context (not dualled; evidence only)

```text
Parent seed 0x005725a0  (inventory-transfer residual rank)  [not OWN]
  └─ (calls / freelist paths eventually)
       └─ operator_delete @ 0x00489822  [OWN R10-001]
            └─ JMP [0x009C6694]  → CRT scalar operator delete  [external]

Sibling island (not OWN):
  0x0048981c  operator_delete[]  JMP [0x009C6698]   [R10-010]
  0x004898f4  free               (C free import)

Sample in-image consumers (not OWN):
  FUN_00402280  StdList_Destroy_FreeHead_ViaClearEsi  → free sentinel
  many Unwind@* SEH cleanups
  scalar-deleting dtors (flags&1 → operator_delete(this))
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00489822-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00489822` | Port as **CRT `operator delete`**: call platform/heap free for a single object block. **cdecl**, returns. Prefer linking/runtime `operator delete` / matching heap free — **do not** reimplement a 6-byte IAT stub unless matching retail import layout. |
| Pair with | `operator_delete[]` `0048981c`; `operator_new` residual `00489892`; C `free` `004898f4`; all destroy/free call sites. |
| Do not | Treat as inventory-only API; mark noreturn; merge with array delete. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (shared CRT — not inventory-specific)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Not written by this agent.**

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00489822`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + get_function_by_address + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses CRT name; documents IAT bytes and false decompiler narrative.  
- Odd behavior preserved: Ghidra noreturn/jumptable warnings on import JMP.  
- No `_Inferred` (CRT symbol sealed). Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
