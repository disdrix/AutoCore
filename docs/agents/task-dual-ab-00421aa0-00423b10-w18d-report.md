# Dual A/B report — W18-D OWN-ONLY (`aa_00421aa0`, `aa_00423b10`)

**Date:** 2026-07-29  
**Agent:** W18-D OWN-ONLY  
**Scope:** OWN ONLY VAs `0x00421aa0`, `0x00423b10`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / other parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00421aa0` OleDb_CommandExecuteIRowset_Inferred | **accept-with-gaps** — SetProperties + Execute(IRowset) + QI IRowsetChange sealed; decompiler this-ptr residual documented |
| `aa_00423b10` NDResource_GetDefaultTypeToken_Inferred | **accept** — once-init type-token singleton sealed |

---

## Sealed facts — `0x00421aa0`

1. **ABI:** Entry **EAX = bind ctx**, **EBX = rgPropertySets** (null skips props). Stack **stdcall** `ppRowset, pParams, pcRowsAffected, cPropertySets` — epilogue **`ret 0x10`**. Body **`0x00421aa0`–`0x00421b4f`**.

2. **Optional props path (EBX≠0):** `cSets = param_4 ? param_4 : 1`; clear slot; QI `*(ctx+0x24)` for **IID_ICommandProperties** (`DAT_00a860e8` = `{0C733A79-2A1C-11CE-ADE5-00AA0044773D}`); **SetProperties** @ **vtbl+0x10** on QI iface (bytes; **not** decompiler `param_1`); Release; fail-fast.

3. **Execute:** `*(ctx+0x24)` **vtbl+0x10** with `(0, IID_IRowset DAT_00a8608c, param_2, param_3|scratch, param_1)`. **IID_IRowset** = `{0C733A7C-2A1C-11CE-ADE5-00AA0044773D}`.

4. **Post-success:** if `*(ctx+0x10)≠0`, QI for **IID_IRowsetChange** (`DAT_00a860f8` = `{0C733A05-…}`) into **`ctx+0x14`**; HRESULT ignored.

5. **Sole caller:** `Com_BindContinuation_Inferred` `0x0041de50` @ `0x0041de9e` (wires EAX/EBX + `&ctx->+0x10`).

6. **Name:** `OleDb_CommandExecuteIRowset_Inferred` — structural from sealed IIDs + CF.

---

## Sealed facts — `0x00423b10`

1. **ABI:** no args; returns **`&DAT_00d1f734`**. Body **`0x00423b10`–`0x00423b3f`**.

2. **Once-init:** if bit0 of `0x00d1f738` clear → set bit, store **`PTR_FUN_00a95ae8`** into `DAT_00d1f734`, **`atexit(LAB_009c3070)`**.

3. **Sole caller:** `NDResource_LoadByKey` `0x00423ac0` uses return as **type token** into `NDResourceCache_LookupOrCreate`.

4. **Name:** `NDResource_GetDefaultTypeToken_Inferred`.

---

## Gaps

### `00421aa0`
1. Product English for command object at `ctx+0x24` (ICommand vs ICommandText).  
2. Exact `DBPARAMS` / continuation blob layout.  
3. Runtime / bit-exact / differential — open.  
4. Scaffold clean retains decompiler SetProperties target residual; named clean is authoritative.

### `00423b10`
1. Product class name for `PTR_FUN_00a95ae8`.  
2. Full vtable method map — out of owned scope.  
3. Runtime — open.

---

## Files

### `aa_00421aa0`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00421aa0_OleDb_CommandExecuteIRowset_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00421aa0_OleDb_CommandExecuteIRowset_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00421aa0_OleDb_CommandExecuteIRowset_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00421aa0_FUN_00421aa0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/OleDb_CommandExecuteIRowset_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00421aa0.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_00421aa0_FUN_00421aa0.md` |
| Annotated | `docs/reconstruction/raw/aa_00421aa0_FUN_00421aa0.annotated.md` |

### `aa_00423b10`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00423b10_NDResource_GetDefaultTypeToken_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00423b10_NDResource_GetDefaultTypeToken_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00423b10_NDResource_GetDefaultTypeToken_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_00423b10_FUN_00423b10.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDResource_GetDefaultTypeToken_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00423b10.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_00423b10_FUN_00423b10.md` |
| Annotated | `docs/reconstruction/raw/aa_00423b10_FUN_00423b10.annotated.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00421aa0-00423b10-w18d-report.md` |

---

## AutoCore impact

- **`00421aa0`:** Port as OLE DB **Execute(IRowset)** with optional **SetProperties**; keep IRowsetChange QI best-effort (ignore hr). Do not implement SetProperties against the rowset out-pointer. Preserve `ctx+0x10` / `+0x14` / `+0x24` until full bind-ctx layout is sealed.
- **`00423b10`:** Port as process-wide default type-token singleton; `NDResource_LoadByKey` must pass its address as the cache type key — not a caller formal.
