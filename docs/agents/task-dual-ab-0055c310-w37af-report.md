# Dual A/B report — W37-AF OWN-ONLY (`0x0055c310`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-AF  
**Scope:** OWN ONLY VA `0x0055c310`. Dual A/B + artifacts (trio + function + A/B).  
**Optional:** decompile callees lacking duals; dual **one** additional undualed callee **not** on exclusive list — **N/A** (sole callee already dualed).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` / `get_function_by_address` / `get_function_callees` / `get_function_callers` / `get_function_xrefs` / `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_0055c310` StdVector_InsertOne_RebindIt_Elem28 | **accept-with-gaps** — thiscall insert-one RET 0x0C; stride 0x1c; index-before-insert rebind sealed; sole callee W34-R InsertN |

---

## `aa_0055c310` — StdVector_InsertOne_RebindIt_Elem28

### Sealed facts

1. **Body:** `0x0055c310`–`0x0055c383` exclusive (**115 B** / `0x73`). Final **`C2 0C 00`** (`ret 0x0C`); pad `CC` from `0x0055c383`.

2. **ABI:** **`__thiscall`**; ECX=`vector*`; stack **outIt*, where, value***; **void** (writes `*outIt` only). Confirmed `8B F9` + `C2 0C 00`.

3. **Layout:** begin@`+4`, end@`+8` (capEnd@`+0xC` unused here). Element stride **`0x1c`**. Div magic **`0x92492493`**.

4. **Algorithm:**
   - Snapshot `index = empty ? 0 : (where − begin) / 0x1c`
   - Call `StdVector_InsertN_Elem28` (`0x0055be00`) with **count=1** (`push value*; push 1; push where; ECX=vec`; call site `0x0055c363`)
   - `*outIt = begin' + index * 0x1c` (survives realloc)

5. **Classification:** worker (thin insert-one + rebind wrapper for POD Elem28).

6. **Callers (1):** `FUN_0055c710` @ `0x0055c78d` — push_back: spare capacity → `FUN_0055b7a0` fill-one at end; else this insert-one at `end` with rebind.

7. **Callees (1):** `FUN_0055be00` / `StdVector_InsertN_Elem28` — **already dual-sealed W34-R**. No undualed callee available for optional extra dual.

8. **Related:** size helper `StdVector_Elem28_Size` (`0x00469c50`, W33-J); resize sibling `0x0055c250` (other-agent exclusive); dword thiscall twin `0x0040dbf0`; RC insert-one `0x004612d0`; Elem28 ValueEdx twin `0x00469e20`.

9. **Name:** `StdVector_InsertOne_RebindIt_Elem28` (Ghidra `FUN_0055c310`). **Reject** scaffold `Named_CalleeOf_*VOG_DEBUG*`.

10. **Decompile ≡ raw CF** (live 2026-08-04 ≡ raw 2026-07-23); ABI sealed by `read_memory`.

### Full body hex (115 B)

```
538b5c240c56578bf98b770485f6741e8b4f082bceb893244992f7e903d1c1fa048bc2c1e81f03c289442414750433f6eb178bcb2bceb893244992f7e903d1c1fa048bf2c1ee1f03f28b4c2418516a01538bcfe898faffff8b47048d14f5000000002bd65f8d0c908b44240c5e89085bc20c00
```

### Gaps

1. Product English for the 0x1c POD element type in this host domain.  
2. Parent push_back `FUN_0055c710` / fill helper `FUN_0055b7a0` not dual-owned.  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_0055c310_StdVector_InsertOne_RebindIt_Elem28.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_0055c310_StdVector_InsertOne_RebindIt_Elem28.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0055c310_StdVector_InsertOne_RebindIt_Elem28.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0055c310_StdVector_InsertOne_RebindIt_Elem28.md` |
| Function record | `docs/reconstruction/functions/aa_0055c310_StdVector_InsertOne_RebindIt_Elem28.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0055c310_FUN_0055c310.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertOne_RebindIt_Elem28.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0055c310.cpp` |
| Raw (+ W37-AF append) | `docs/reconstruction/raw/aa_0055c310_FUN_0055c310.md` |
| Annotated | `docs/reconstruction/raw/aa_0055c310_FUN_0055c310.annotated.md` |

---

## Optional extra dual

| Check | Result |
|---|---|
| Callees of `0x0055c310` | only `0x0055be00` |
| Dual status of callee | **full dual W34-R** (`StdVector_InsertN_Elem28`) |
| On exclusive list? | N/A — already dualed |
| Extra dual filed? | **No** |

Exclusive list VAs deliberately **not** touched (including sibling `0055c250`, `0055ca90`, etc.).

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0055c310-w37af-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0055c310` | Port as **`vector<Elem28>::insert(where, value)` rebind wrapper**: thiscall + **RET 0x0C**; stride **0x1c**; snapshot index then call insert-n with **count=1**; write rebased `*outIt`. Do **not** use EDI-vec ABI of RC twin `004612d0`, ValueEdx twin `00469e20`, or dword stride-4 twin `0040dbf0` without a shim. Product type of Elem28 residual (same as insert-n). |

### Shared context (not owned)

| VA | Role |
|---|---|
| `0x0055be00` | `StdVector_InsertN_Elem28` (W34-R) — sole callee |
| `0x0055c710` | push_back parent (spare-cap vs insert-one) |
| `0x0055b7a0` | fill-n one at end (push_back fast path) |
| `0x0055c250` | resize sibling — **other-agent exclusive** |
| `0x00469c50` | `StdVector_Elem28_Size` (W33-J) |
| `0x0040dbf0` | dword thiscall insert-one rebind twin |
| `0x004612d0` | RC Elem28 insert-one (EDI) |
| `0x00469e20` | Elem28 insert-one ValueEdx/EDI |

---

## Process

- OWN VA only (`0x0055c310`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + function meta + xrefs/callees/callers + `read_memory`. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- No invented product names; structural family name `StdVector_InsertOne_RebindIt_Elem28` only.  
