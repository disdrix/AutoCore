# Review A (reconstruction fidelity): `aa_00427040` StdVector_DestroyRuns_0x80_Thunk_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00427040` |
| **VA** | `0x00427040`–`0x00427044` inclusive (**5 B** / `0x5`) |
| **Canonical name** | `StdVector_DestroyRuns_0x80_Thunk_Inferred` |
| **Ghidra name** | `thunk_FUN_004271c0` |
| **Prior scaffold** | `thunk_FUN_004271c0` |
| **Review date** | `2026-08-05` (R10-003 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00427040_StdVector_DestroyRuns_0x80_Thunk_Inferred.md` |
| **System** | skills-abilities / UI text-layout SEH alias |
| **Parent dual** | `aa_004271c0` `StdVector_DestroyRuns_0x80_Inferred` (MEGA-128 **accept**) |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_callers` + `get_function_xrefs` + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher. Parent dual used as evidence only (not re-dualed).

---

## 1. Purpose

Pure **JMP thunk** alias of dualed vector tidy `StdVector_DestroyRuns_0x80_Inferred` @ `0x004271c0`.

```text
00427040  JMP 0x004271c0     ; E9 7B 01 00 00
```

SEH Unwind frames jump here with **EBX = layout+0x80** (vector shell of 0x80-stride "run" elements owning `wstring` @+0x0C). Direct product CALL sites hit the parent VA instead.

**Not** a second implementation of the tidy — **no local loop/delete/zero** at this VA.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | follows thunk → parent body (false noreturn on `operator_delete`) |
| Full body | `disassemble_function` → sole `JMP 0x004271c0` |
| Bytes | `read_memory` 32 B: `E9 7B 01 00 00 CC…` |
| Callers | 2 Unwind JMP xrefs (`009ac305`, `009add47`) |
| Call-site ABI | both: `MOV EBX,[EBP+4]; ADD EBX,0x80; JMP here` |
| Parent dual | MEGA-128 A/B **accept** (`StdVector_DestroyRuns_0x80_Inferred`) |
| Host dtor | dualed `UiTextLayout_CompleteDtor_Inferred` `LEA EBX,[ESI+0x80]; CALL 004271c0` |

**Not performed:** Launcher, runtime, parent ledger edits, dual of `FUN_00426f70`.

---

## 3. Signature (sealed)

```c
// EBX = vector*; bare RET in parent; void
// Body at this VA: JMP StdVector_DestroyRuns_0x80_Inferred
void StdVector_DestroyRuns_0x80_Thunk_Inferred(void /* EBX */);
```

| Formal | Source | Conf |
|---|---|---|
| vector* | **EBX** (inherited; SEH `MOV EBX` + parent loads) | **Confirmed** |
| stack formals | none | **Confirmed** |
| cleanup | parent `RET` (`C3`) | **Confirmed** |
| local body size | **5 B** JMP only | **Confirmed** |
| target | `0x004271c0` (rel32 `0x17B`) | **Confirmed** |
| classification | thunk | **Confirmed** |

---

## 4. Control flow (sealed)

| Stage | Match | Conf |
|---|---|---|
| Sole insn `JMP 0x004271c0` | `disassemble_function` + bytes `E9 7B 01 00 00` | **Confirmed** |
| No local begin/end/delete | no further code before CC pad | **Confirmed** |
| Decompile expands parent | Ghidra thunk-follow; bytes win | **Confirmed** |
| Parent CF sealed MEGA-128 | stride 0x80 / ~wstring / delete / zero | **Confirmed** (parent dual) |
| SEH sites set EBX = host+0x80 | assembly context both Unwinds | **Confirmed** |

```c
void StdVector_DestroyRuns_0x80_Thunk_Inferred(void) {
  // JMP 0x004271c0
  StdVector_DestroyRuns_0x80_Inferred(); // EBX preserved
}
```

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | **thunk** |
| External xrefs | **2** Unwind JMP (not CALL) |
| Direct product CALL | **none** to this VA (parent has CALL from `00797df0`) |
| Callees | JMP → `FUN_004271c0` only |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Pure JMP to dualed parent | **Yes** |
| Parent name `StdVector_DestroyRuns_0x80_Inferred` sealed | **Yes** (MEGA-128) |
| SEH alias role (EBX = +0x80) | **Yes** |
| Product element English demangle | **No** → keep `_Inferred` |
| Independent tidy body at this VA | **No** |

**Decision:** promote **`StdVector_DestroyRuns_0x80_Thunk_Inferred`**. Retire scaffold `thunk_FUN_004271c0` as final name (keep Ghidra alias).

---

## 7. Gaps

- Product English for 0x80 element ("runs") — inherited from parent; non-blocking `_Inferred`.
- Unowned residual dual `FUN_00426f70` (R10-026).
- Runtime / bit-exact / differential.

---

## 8. Verdict

Thunk body fully sealed; ABI/role sealed via SEH sites + dualed parent → **accept**.
