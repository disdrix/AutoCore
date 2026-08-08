# Review A (reconstruction fidelity): `aa_00548f90` CVOGHBSkillBase_dtor_Thunk_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00548f90` |
| **VA** | `0x00548f90`–`0x00548f94` inclusive (**5 B** / `0x5`) |
| **Canonical name** | `CVOGHBSkillBase_dtor_Thunk_Inferred` |
| **Ghidra name** | `thunk_FUN_00578a60` |
| **Prior scaffold** | `thunk_FUN_00578a60` |
| **Review date** | `2026-08-05` (R13-006 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00548f90_CVOGHBSkillBase_dtor_Thunk_Inferred.md` |
| **System** | skills-abilities / CVOGHBSkillBase lifecycle |
| **Parent dual** | `aa_00578a60` `CVOGHBSkillBase_dtor` (R12-026 **accept-with-gaps**) |
| **Partition** | R13 residual map → **R13-006**; dual start **2686** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_by_address` + `get_function_callers` + `get_function_xrefs` + `get_xrefs_to` + `get_xrefs_from`. **No** `disassemble_bytes`. No Launcher. Parent dual used as evidence only (not re-dualed).

---

## 1. Purpose

Pure **JMP thunk** alias of dualed complete dtor `CVOGHBSkillBase_dtor` @ `0x00578a60`.

```text
00548f90  JMP 0x00578a60     ; E9 CB FA 02 00
```

Primary product CALL site is dualed shared subclass scalar deleting dtor `CVOGHBSkill_SharedScalarDeletingDtor_Inferred` @ `0x00651190`. Three EH Unwind frames also CALL here. Base-class scalar `0x00578de0` CALLs the **parent** VA directly (not this thunk).

**Not** a second complete-destructor implementation — **no local vtbl/delete/zero/base-tail** at this VA.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | follows thunk → parent body (false noreturn on `operator_delete`) |
| Full body | `disassemble_function` → sole `JMP 0x00578a60` |
| Bytes | `read_memory` 32 B: `E9 CB FA 02 00 CC…` |
| Function range | `get_function_by_address` body `00548f90`–`00548f94` |
| Classification | `analyze_function_complete` `is_thunk: true` |
| Callers | `FUN_00651190` + 3 Unwind CALL xrefs |
| Xrefs-from | sole UNCONDITIONAL_JUMP → `FUN_00578a60` |
| Parent dual | R12-026 A/B **accept-with-gaps** (`CVOGHBSkillBase_dtor`) |
| Shared scalar dual | R12-001 `CVOGHBSkill_SharedScalarDeletingDtor_Inferred` (CALL site) |

**Not performed:** Launcher, runtime, parent ledger edits, dual of parent or callers.

---

## 3. Signature (sealed)

```c
// ECX = CVOGHBSkillBase* this; inherited from parent __thiscall
// Body at this VA: JMP CVOGHBSkillBase_dtor
void __thiscall CVOGHBSkillBase_dtor_Thunk_Inferred(void *thisHb /* ECX */);
```

| Formal | Source | Conf |
|---|---|---|
| this | **ECX** (inherited; parent `MOV ESI,ECX`; caller thiscall) | **Confirmed** |
| stack formals | none | **Confirmed** |
| cleanup | parent tail JMP base dtor | **Confirmed** (parent dual) |
| local body size | **5 B** JMP only | **Confirmed** |
| target | `0x00578a60` (rel32 `0x0002FACB`) | **Confirmed** |
| classification | thunk | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Sole insn `JMP 0x00578a60` | `disassemble_function` + bytes `E9 CB FA 02 00` | **Confirmed** |
| Rel32 target math | `0x00548f90+5+0x2FACB = 0x00578A60` | **Confirmed** |
| No local complete-dtor body | no further code before CC pad | **Confirmed** |
| Decompile expands parent | Ghidra thunk-follow; bytes win | **Confirmed** |
| Parent CF sealed R12-026 | vtbl / delete[] / delete / base JMP | **Confirmed** (parent dual) |
| Shared scalar CALL site | `00651193 E8 F8 7D EF FF` → here | **Confirmed** (R12-001) |

```c
void CVOGHBSkillBase_dtor_Thunk_Inferred(void *thisHb) {
  // JMP 0x00578a60
  CVOGHBSkillBase_dtor(thisHb); // ECX preserved by JMP
}
```

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | **thunk** |
| External xrefs | **4** UNCONDITIONAL_CALL |
| Direct product CALL | `FUN_00651190` (shared skill subclass scalar dtor) |
| EH | 3 Unwind frames CALL |
| Callees | JMP → `FUN_00578a60` only |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Pure JMP to dualed parent | **Yes** |
| Parent name `CVOGHBSkillBase_dtor` sealed | **Yes** (R12-026; RTTI class Confirmed) |
| Thunk role (alias for CALL density / EH) | **Yes** |
| Product demangle of **thunk** symbol | **No** → keep `_Inferred` |
| Independent complete-dtor body at this VA | **No** |
| Distinct from base scalar `00578de0` / shared scalar `00651190` | **Yes** |

**Decision:** promote **`CVOGHBSkillBase_dtor_Thunk_Inferred`**. Retire scaffold `thunk_FUN_00578a60` as final name (keep Ghidra alias). `_Inferred` is honest for the thunk demangle (parent class sealed without it).

---

## 7. Gaps

- Product/PDB demangle of the thunk symbol itself (if any).
- Parent field English residuals (`+0x6a0` / `+0x6b0`) — inherited; non-blocking.
- Runtime / bit-exact / differential.

---

## 8. Verdict

Thunk body fully sealed; ABI/role sealed via CALL sites + dualed parent → **accept**.
