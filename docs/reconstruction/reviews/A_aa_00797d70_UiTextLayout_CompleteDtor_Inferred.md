# Review A (reconstruction fidelity): `aa_00797d70` UiTextLayout_CompleteDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00797d70` |
| **VA** | `0x00797d70`–`0x00797e17` (**168 B**) |
| **Canonical name** | `UiTextLayout_CompleteDtor_Inferred` |
| **Ghidra name** | `FUN_00797d70` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9L-F) |
| **Counterpart** | `reviews/B_aa_00797d70_UiTextLayout_CompleteDtor_Inferred.md` |
| **System** | UI owned text-layout complete destructor |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Complete destructor of a heap-owned text-layout block: merge float metrics, finalize layout, free buffer + run vectors, destroy embedded `wstring`. Does not free host (callers pair with `operator_delete`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9L-F append) | `docs/reconstruction/raw/aa_00797d70_FUN_00797d70.md` |
| Annotated | `docs/reconstruction/raw/aa_00797d70_FUN_00797d70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UiTextLayout_CompleteDtor_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00797d70.cpp` |
| Function records | `aa_00797d70_FUN_00797d70.md`, `aa_00797d70_UiTextLayout_CompleteDtor_Inferred.md` |
| Owner path | `CNDUIWindow_CompleteDtor` free of `+0x28C` |
| Live | decompile ≡ CF with noreturn warning; `RET 4` sealed by bytes |

---

## 3. Signature (sealed)

```c
// stack arg = layout*; SEH LAB_009add5a; RET 4 (C2 04 00); void
void __stdcall UiTextLayout_CompleteDtor_Inferred(void* layout);
```

| Formal | Source | Conf |
|---|---|---|
| layout | stack (`MOV ESI,[ESP+0x18]`) | **High** |
| return | void; **not** free host | **High** |
| cleanup | `C2 04 00` @ `0x00797e16` | **High** |

---

## 4. Control flow (bytes authority)

```
SEH; ESI=layout
float@+0xA4 += float@+0xA8; +0xA8=0
EBX=ESI; FUN_00797530(1)
free vector @+0x94 + null triple
EBX=layout+0x80; FUN_004271c0
~wstring(layout+0x0C)
SEH restore; RET 4
```

| Stage | Match | Conf |
|---|---|---|
| Float merge SSE | `MOVSS/ADDSS/MOVSS` + `XORPS` zero | **High** |
| Finalize call | `PUSH 1; CALL 00797530` | **High** |
| Free + always-null | disasm after delete | **High** |
| Run vector shell | `LEA EBX,[ESI+0x80]; CALL 004271c0` | **High** |
| wstring dtor | `LEA ECX,[ESI+0xC]; CALL [IAT]` | **High** |
| RET 4 | epilogue hex | **High** |

---

## 5. Machine bytes (`read_memory`)

| Span | Result |
|---|---|
| Entry 64 B @ `0x00797d70` | SEH + ESI load + float merge sealed |
| Epilogue @ `0x00797e00` | `~string` + FS restore + `RET 4` sealed |

---

## 6. Gaps (accepted)

- Product demangle / exact class English (hence `_Inferred`).
- Element type of 0x80-stride runs; metric semantics beyond “merge then zero delta”.
- Runtime / bit-exact / differential.

---

## 7. Verdict rationale

Fidelity path accepts stdcall complete-dtor role, offset map, and caller pairing with `operator_delete`. Product name remains inferred — gap only.
