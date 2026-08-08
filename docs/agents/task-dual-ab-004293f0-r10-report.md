# Dual A/B report — R10-009 OWN-ONLY (`0x004293f0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-009**  
**Scope:** VA `0x004293f0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_xrefs` + `read_memory` (body + vtbl). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r10_residual_partition_map.md` → **R10-009**.  
**Work item:** Residual dual seal — undualed scalar peer of dualed HP complete dtor `0x0078ca80`.  
**Parent dual (evidence only):** `0x0078ca80` `CNDUIWndBuffered_CompleteDtor`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004293f0` CNDUIWndBuffered_ScalarDeletingDtor | **accept** — scalar-dtor CF/ABI/vtbl[0]/false-noreturn + product class (parent RTTI) sealed |

Path A (fidelity): **accept**.  
Path B (adversarial): complete-body / vector-dtor / always-free / never-free / cdecl / noreturn-truncate / invent-name claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004293f0` — sealed facts

1. **Body:** `0x004293f0`–`0x0042940d` exclusive (**29 B** / `0x1D`; pad `CC CC`; next sibling pattern @ `0x00429410`).
2. **ABI:** **ECX=`this`**; stack **flags**; **`RET 4`** (`C2 04 00`); returns **`this`** in EAX.
3. **Semantics:** MSVC **scalar-deleting destructor** for vtbl family **`PTR_FUN_00a99f74`** / class **`CNDUIWndBuffered`**:
   - Always call complete dtor **`FUN_0078ca80`** / `CNDUIWndBuffered_CompleteDtor`.
   - If `(flags & 1)`: `operator_delete(this)` @ `0x00489822`.
   - Return `this`.
4. **Classification:** worker.
5. **Callers:** DATA only — dword @ `0x00a99f74` = `0x004293f0` (vtbl[0]).
6. **Callees:** `FUN_0078ca80`, `operator_delete`.
7. **Name:** `CNDUIWndBuffered_ScalarDeletingDtor` (Ghidra `FUN_004293f0`; product class sealed via parent RTTI — **not** `_Inferred`).
8. **Decompile ≡ bytes**; Ghidra false-noreturn on `operator_delete` ignored (epilogue present).  
   Full hex: raw R10-009 append (29 B):
   ```
   568bf1e888363600f644240801740956e81d04060083c4048bc65ec20400
   ```

### Gaps

- Complete dtor body not owned here (`FUN_0078ca80` — parent dual WQ9K-F).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004293f0_CNDUIWndBuffered_ScalarDeletingDtor.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004293f0_CNDUIWndBuffered_ScalarDeletingDtor.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004293f0_FUN_004293f0.md` |
| Annotated | `docs/reconstruction/raw/aa_004293f0_FUN_004293f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDUIWndBuffered_ScalarDeletingDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004293f0.cpp` |
| Function | `docs/reconstruction/functions/aa_004293f0_FUN_004293f0.md` |
| Function named | `docs/reconstruction/functions/aa_004293f0_CNDUIWndBuffered_ScalarDeletingDtor.md` |
| Report | `docs/agents/task-dual-ab-004293f0-r10-report.md` |

---

## Chain context (not dualled; evidence only)

```text
PTR_FUN_00a99f74[0]  →  FUN_004293f0  CNDUIWndBuffered_ScalarDeletingDtor  [OWN R10-009]
                          ├─► FUN_0078ca80  CNDUIWndBuffered_CompleteDtor  [parent dual WQ9K-F]
                          │     ├─ vtbl install PTR_FUN_00a99f74
                          │     ├─ FUN_007a8580 / FUN_0078c3d0
                          │     ├─ nested free @ this+0x2A8
                          │     └─ FUN_007b5be0  CNDUIWindow complete
                          └─► operator_delete (if flags&1)  [0x00489822]

Derived complete caller (not OWN): CWndVehicle_CompleteDtor @ 0x00834520 → base 0078ca80
```

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004293f0` | Port as **scalar deleting only**: call complete dtor (`CNDUIWndBuffered_CompleteDtor` / `FUN_0078ca80`), then optional `operator_delete` on bit0. vtbl[0] of `PTR_FUN_00a99f74`. Do **not** inline complete body (vtbl install / +0x2A8 nested free / base window) into this VA. |
| Pair with | Parent complete `aa_0078ca80`; ctor `CNDUIWndBuffered_Ctor_Inferred` @ `0x0078caf0`; derived vehicle complete `0x00834520`. |

---

## Process

- OWN VA only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Terminal **false**.
