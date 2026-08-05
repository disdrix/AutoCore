# Review A (reconstruction fidelity): `aa_008aaf60` Client_MissionDialog_SetHeaderCaption_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aaf60` |
| **VA** | `0x008aaf60`–`0x008ab098` (312 B) |
| **Canonical name** | `Client_MissionDialog_SetHeaderCaption_Inferred` |
| **Ghidra name** | `FUN_008aaf60` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual WQ7R-A) |
| **Counterpart** | `reviews/B_aa_008aaf60_Client_MissionDialog_SetHeaderCaption_Inferred.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Apply or clear the mission dialog **header caption** widget at `dialog+0x6e0`. Register `EDI` selects clear (0) vs set (string key). Non-zero path resolves text, optionally formats through `FUN_005465c0`, expands/applies via `FUN_008aab00`, layouts, and conditionally shows. Common tail: `vtbl+0x214(0)` + `FUN_008aa610`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | Ghidra `decompile_function` `0x008aaf60` (2026-08-04) ≡ raw |
| Body bounds | `get_function_by_address` → `008aaf60`–`008ab098` |
| Entry bytes | `read_memory` 320 B @ `0x008aaf60` |
| Callers/xrefs | 6 sites: ShowNpc×3, UpdateJournal×2, FUN_0093e450×1 |
| Raw / annotated | `docs/reconstruction/raw/aa_008aaf60_*` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_MissionDialog_SetHeaderCaption_Inferred.cpp` |
| Function records | `functions/aa_008aaf60_*` |
| Parent journals | `Client_UpdateMissionJournal`, `Client_ShowNpcMissionDialogUI` |

**Not performed:** dual of nested `005465c0` / `008aab00` / `008aa610` (other OWN); Launcher; vtable product names.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 312 B / end `008ab098` | **Confirmed** | `get_function_by_address` |
| ECX = dialog context | **Confirmed** | `mov esi,ecx` + `+0x6e0/+0x648` |
| EDI = caption key (0 clear) | **Confirmed** | `test edi` / `push edi` → `007a6de0` |
| Null widget `+0x6e0` → no-op | **Confirmed** | early je |
| Clear path: `+0x1d8` then `+0x34c` | **Confirmed** | bytes + decomp |
| Set path: resolve → optional `005465c0` → `+0x1d8` → `008aab00` → `+0x1f0` → `+0x34c` → cond `+0x1fc` | **Confirmed** | order |
| `+0x1d8` args **(0,1,1)** not (0) | **Confirmed** | `6a016a016a00` both branches |
| Cond show: `DAT_00d1b21c==0` OR state∈{2,3} | **Confirmed** | decomp ≡ bytes |
| Common tail `+0x214(0)` + `FUN_008aa610` | **Confirmed** | both branches join |
| Plain `ret` after SEH teardown | **Confirmed** | `c3` |
| Product English for widget/vtables | **Open** | `_Inferred` |
| Nested callee bodies | **Out of OWN** | call order only |
| Runtime / bit-exact | **Open** | terminal false |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| SEH register | Yes |
| widget null → return | Yes |
| EDI==0 clear branch | Yes |
| EDI!=0 set branch + string + optional format | Yes |
| State/flag gate for `+0x1fc` | Yes |
| Common `+0x214` + `008aa610` | Yes |
| ExceptionList restore | Yes |

---

## 5. Gaps

1. Product / PDB function and widget class names.
2. Exact EDI key type (id vs pointer) beyond `007a6de0` consumption.
3. Semantic dictionary for vtable slots `+0x1d8/+0x1f0/+0x1fc/+0x214/+0x34c`.
4. `DAT_00d1b21c` product meaning.
5. Nested residual duals (`005465c0`, `008aab00`, `008aa610`).
6. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — register ABI, branch CF, vcall order, and decompiler lag on `+0x1d8` sealed.
