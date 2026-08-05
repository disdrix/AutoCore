# Review A (reconstruction fidelity): `aa_00492dd0` PalantirEnv_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00492dd0` |
| **VA** | `0x00492dd0`–`0x004930ab` exclusive (**731 B** / `0x2DB`) |
| **Canonical name** | `PalantirEnv_Ctor_Inferred` |
| **Ghidra name** | `FUN_00492dd0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-P) |
| **Counterpart** | `reviews/B_aa_00492dd0_PalantirEnv_Ctor_Inferred.md` |
| **System** | client / Palantir env host |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + callers. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Complete ctor of **0x198** env host used by Palantir view-bundle factory:

1. Base/`FUN_007560d0` + vtbl `PTR_FUN_009c7928`.
2. Flag bank + six `FUN_0096ef70` subobject inits.
3. Store arg0 `@+0xBC`, parent `@+0xB8`.
4. Nested vtbl `PTR_LAB_009c7744` + this backlink; two `FUN_004933f0` slots.
5. RB sentinel via `FUN_0044e100` @ `+0x190` with self-links.
6. Child `new(0xC8)` + `FUN_00497920(parent)` @ `+0x100`.
7. Tail `FUN_0048f2d0`; return **this** (`RET 8`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W31-P) | `docs/reconstruction/raw/aa_00492dd0_FUN_00492dd0.md` |
| Annotated | `docs/reconstruction/raw/aa_00492dd0_FUN_00492dd0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/PalantirEnv_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00492dd0.cpp` |
| Function records | `functions/aa_00492dd0_FUN_00492dd0.md`, `functions/aa_00492dd0_PalantirEnv_Ctor_Inferred.md` |
| Related | W30-F factory `Client_InitPalantirViewBundle_Inferred`; `RbTree_AllocEmptyNode_0x30` |
| Live | decompile ≡ raw 2026-07-23; entry SEH+`8B F1`+vtbl store; epilogue `C2 08 00`; sole xref `0x004cdb79` |

---

## 3. Signature (sealed)

```c
// __thiscall; ECX=self; stack arg0 + parent; RET 8; returns self
void *__thiscall PalantirEnv_Ctor_Inferred(void *self, uint32_t arg0, void *parent);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B F1`) | **High** |
| arg0 | stack `[esp+4]` (factory **0**) | **High** |
| parent | stack `[esp+8]` | **High** |
| return | this | **High** |
| cleanup | `RET 8` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
SEH LAB_009a0b3b
FUN_007560d0
vtbl + flags (+0x87 from parent+0x7d)
FUN_0096ef70 ×4 (early)
store arg0/parent; zero cluster; nested vtbl
FUN_0096ef70 ×2
FUN_004933f0 ×2
zeros + flags +0x171
FUN_0044e100 → +0x190 self-links
+0x172 from desktop chain
+0x70 from parent+0x7d
new(0xC8)+FUN_00497920(parent) → +0x100
FUN_0048f2d0
return this
```

| Stage | Match | Conf |
|---|---|---|
| Body size 0x2DB / RET 8 | **Yes** | **High** |
| Size 0x198 factory | **Yes** (W30-F) | **High** |
| Sole caller factory path | **Yes** | **High** |
| RB sentinel pattern | **Yes** | **High** |

---

## 5. Gaps

- Product / MSVC demangle for env class.
- Exact this-adjust bases for each `FUN_0096ef70` (decompiler-omitted).
- `FUN_007560d0` / `FUN_0048f2d0` / `FUN_004933f0` product roles.
- Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals ctor role, ABI, size, sole factory wiring, key offsets, and RB/child arms. Residual product English and subobject bases → **accept-with-gaps**.
