# Review A (reconstruction fidelity): `aa_004280d0` CNDUIDialog_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004280d0` |
| **VA** | `0x004280d0`–`0x004280ee` exclusive (**30 B** / `0x1E`) |
| **Canonical name** | `CNDUIDialog_ScalarDeletingDtor` |
| **Ghidra name** | `FUN_004280d0` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY MEGA-140) |
| **Counterpart** | `reviews/B_aa_004280d0_CNDUIDialog_ScalarDeletingDtor.md` |
| **System** | CNDUIDialog / MSVC scalar-deleting destructor (partition: skills-abilities) |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body hex + vtbl/RTTI) + `get_xrefs_to` / `get_function_xrefs` + `disassemble_function` + `get_function_by_address`. **No** `disassemble_bytes`. |
| **Partition** | `WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-140** |
| **Parent dual** | `0x00792c20` CNDUIDialog_CompleteDtor (WQ9K-G) |
| **Verdict** | **accept** |

---

## 1. Purpose

MSVC scalar-deleting destructor (vtbl[0] of `PTR_FUN_00a98f44`): always run complete dtor `FUN_00792c20`; if `(flags & 1)` free the host with `operator_delete`; return `this`. Product class **CNDUIDialog** sealed by RTTI.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-140 append) | `docs/reconstruction/raw/aa_004280d0_FUN_004280d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004280d0_FUN_004280d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDUIDialog_ScalarDeletingDtor.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_004280d0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004280d0_CNDUIDialog_ScalarDeletingDtor.md` |
| Complete parent | `CNDUIDialog_CompleteDtor` / `FUN_00792c20` (WQ9K-G dualed) |
| Peer pattern | `CWndVehicle_ScalarDeletingDtor` (WQ9I-F **accept**) — identical 30 B shape |
| Live | decompile ≡ bytes; vtbl dword @ `0x00a98f44` = `0x004280d0`; COL → `.?AVCNDUIDialog@@` |

---

## 3. Signature (sealed)

```c
// ECX=this; stack flags; RET 4; returns this*
void* __thiscall CNDUIDialog_ScalarDeletingDtor(void* self, uint8_t flags);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`56 8B F1`) | **High** |
| flags | stack (`F6 44 24 08 01`) | **High** |
| return | EAX = ESI = this | **High** |
| cleanup | `C2 04 00` | **High** |

---

## 4. Control flow (bytes authority)

```
ESI = this
call FUN_00792c20              // complete dtor (thiscall)
if (flags & 1):
  operator_delete(this)
return this                    // RET 4
```

| Stage | Match | Conf |
|---|---|---|
| Complete-then-optional-free | decompile ≡ 30 B hex | **High** |
| bit0 gate only (not vector) | `test …,1` / `je` | **High** |
| False noreturn ignored | epilogue present after delete | **High** |
| vtbl[0] | DATA `00a98f44` → `004280d0` | **High** |
| RTTI product name | COL → `.?AVCNDUIDialog@@` | **High** |
| Parent complete does not free host | WQ9K-G dual + B review | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (30 B):

```
568bf1e848ab3600f644240801740956e83d17060083c4048bc65ec20400
```

Pad `CC CC` then next function SEH prologue at `0x004280f0`.

Relative calls sealed: `CALL` @ `004280d3` → `00792c20`; `CALL` @ `004280e0` → `00489822` (`operator_delete`).

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | DATA vtbl[0] only (no code CALL sites) — `analyze_function_complete` callers `[]`; xrefs `[{from:00a98f44}]` |
| Callees | `FUN_00792c20`, `operator_delete` |

Vtbl `0x00a98f44`: [0]=`0x004280d0`, [1]=`0x00790cc0`, [2]=`0x007a7de0`, [3]=`0x007567e0` (matches WQ9K-G plate).

---

## 7. Gaps

1. Complete dtor body / owned-slot English not owned here (`FUN_00792c20` dualed separately WQ9K-G).  
2. Runtime / bit-exact / differential — open (terminal false; no Launcher).

---

## 8. Verdict

**accept** — scalar-dtor CF/ABI/vtbl[0]/RTTI CNDUIDialog/`RET 4`/false-noreturn sealed. Product demangle closed (no `_Inferred`).
