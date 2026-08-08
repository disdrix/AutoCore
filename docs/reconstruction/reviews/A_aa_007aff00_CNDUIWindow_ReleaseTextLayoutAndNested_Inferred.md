# Review A (reconstruction fidelity): `aa_007aff00` CNDUIWindow_ReleaseTextLayoutAndNested_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007aff00` |
| **VA** | `0x007aff00`–`0x007aff51` (**82 B**) |
| **Canonical name** | `CNDUIWindow_ReleaseTextLayoutAndNested_Inferred` |
| **Ghidra name** | `FUN_007aff00` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9L-G) |
| **Counterpart** | `reviews/B_aa_007aff00_CNDUIWindow_ReleaseTextLayoutAndNested_Inferred.md` |
| **System** | UI / CNDUIWindow complete-dtor helper |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Partial teardown helper on `CNDUIWindow`: when gate `+0x20C` is set, complete-dtor + delete owned text layout at `+0x28C`; always clear nested CS-list at `+0x1E8` and zero `+0x128`/`+0x12C`. Does not free `this`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ WQ9L-G append) | `docs/reconstruction/raw/aa_007aff00_FUN_007aff00.md` |
| Annotated | `docs/reconstruction/raw/aa_007aff00_FUN_007aff00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDUIWindow_ReleaseTextLayoutAndNested_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_007aff00.cpp` |
| Function records | `aa_007aff00_FUN_007aff00.md`, named record |
| Parent | `CNDUIWindow_CompleteDtor` (`0x007b5be0`) calls at `0x007b5c8a` |
| Layout dtor | `UiTextLayout_CompleteDtor_Inferred` (`0x00797d70`, WQ9L-F) |

---

## 3. Signature (sealed)

```c
// ECX = this; bare RET (C3); void
void __fastcall CNDUIWindow_ReleaseTextLayoutAndNested_Inferred(void* self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F1`) | **High** |
| return | void; does not free this | **High** |
| cleanup | `C3` @ `0x007aff51` | **High** |

---

## 4. Control flow (bytes authority)

```
ESI=this
if [ESI+0x20C] != 0:
  EDI=[ESI+0x28C]
  if EDI: FUN_00797d70(EDI); operator_delete(EDI)
  [ESI+0x28C]=0
LEA ECX,[ESI+0x1E8]; CALL FUN_00424060
[ESI+0x128]=0; [ESI+0x12C]=0
RET
```

| Stage | Match | Conf |
|---|---|---|
| ECX this | `8B F1` | **High** |
| Gate `+0x20C` | `83 BE 0C 02 00 00 00` / `76 25` | **High** |
| Layout free pair | push+call `00797d70` + push+delete + `83 C4 04` | **High** |
| Nested this LEA | `8D 8E E8 01 00 00` | **High** (decompiler missed) |
| Zero `+0x128`/`+0x12C` | `C7 86 28/2C 01 00 00 00…` | **High** |
| Bare RET | `C3` | **High** |
| Parent call site | `007b5c88 MOV ECX,ESI; CALL 007aff00` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full 82 B hex in raw WQ9L-G append. Entry: `56 8B F1 83 BE 0C 02…`. Epilogue: `5E C3` then `CC` pad.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker (complete-dtor helper) |
| Code caller | `CNDUIWindow_CompleteDtor` / `FUN_007b5be0` |
| DATA xrefs | many subclass vtbl slots |
| Callees | `FUN_00797d70`, `operator_delete`, `FUN_00424060` |

---

## 7. Gaps

1. Product English for gate `+0x20C` and zeroed `+0x128`/`+0x12C`.  
2. Product class of nested object at `+0x1E8` (CS + list; parent vtbls known).  
3. Design reason for gated early free vs parent’s later unconditional free of `+0x28C`.  
4. Runtime / bit-exact / differential — open.

---

## 8. Verdict

ABI, body size, gated layout free, nested LEA thiscall, field zeros, and parent call site sealed. Decompiler LEA gap closed by bytes. Residual product English → **accept-with-gaps**.
