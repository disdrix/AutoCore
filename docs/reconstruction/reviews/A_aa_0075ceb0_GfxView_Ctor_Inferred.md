# Review A (reconstruction fidelity): `aa_0075ceb0` GfxView_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075ceb0` |
| **VA** | `0x0075ceb0`–`0x0075d1fc` (**0x54D B**) |
| **Canonical name** | `GfxView_Ctor_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_0075ceb0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-O) |
| **Counterpart** | `reviews/B_aa_0075ceb0_GfxView_Ctor_Inferred.md` |
| **System** | graphics / client camera (GfxView) |
| **Evidence pass** | Live `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (prologue/epilogue + constants); 2 callers; string path |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Construct **GfxView** on pre-allocated **0x150** storage: vtbl, transform, matrices, default camera params, background VB + `PalViewBackground.fx`, or hard-abort.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0075ceb0_FUN_0075ceb0.md` (+ 2026-07-29 W31-O append) |
| Annotated | `docs/reconstruction/raw/aa_0075ceb0_FUN_0075ceb0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxView_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0075ceb0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0075ceb0_FUN_0075ceb0.md` |
| Named record | `docs/reconstruction/functions/aa_0075ceb0_GfxView_Ctor_Inferred.md` |
| Live | decompile ≡ raw CF/strings; prologue `MOV EBP,ECX`; epilogue `ADD ESP,0x2C; RET` |
| Context | W30-F factory `FUN_004cda90`; EnsureProjection layout siblings |

---

## 3. Signature (sealed)

```c
// ECX=GfxView* (0x150); returns this; SEH; plain RET
GfxView * __fastcall GfxView_Ctor_Inferred(GfxView *this);
```

| Slot | Source | Conf |
|---|---|---|
| this | **ECX** (prologue `8B E9`) | **High** |
| return | **EAX = this** on success | **High** |
| size | factories `new(0x150)` | **High** |

---

## 4. Control flow (clean ≡ raw)

```
SEH install
vtbl; +0x04=0; +0x08 transform via aligned_malloc(0xC0,16)+FUN_00972cc0; +0x0C=1.0
FUN_0073f590(this+0x10)
dirty +0x48/+0x49; two identity mats @ +0x50/+0x54
near=0.5, far=10000, FOV=π/3, +0x104=1000, mode=0, dirties +0xCC
FUN_00414bc0(0x144); FUN_00414c20(4,vb,3,0); FUN_00414b60
if VB fail && report==3 → crash path
else load PalViewBackground.fx; if fail && report==3 → crash path
else +0x40=this; zero +0x5C..0xBB (0x18 dwords); return this
crash: VOGCRASH log; raise(0x16); ExitProcess(3)
```

| Stage | Match | Conf |
|---|---|---|
| Ctor / return this | **Yes** | **High** |
| Path / effect strings | **Yes** | **High** |
| Default near/far/FOV | **Yes** (`read_memory`) | **High** |
| Dirty init 1 | **Yes** | **High** |
| Nested D3D helper English | open | **Medium** |

---

## 5. Constants (`read_memory`)

| Symbol | Value | Field |
|---|---|---|
| `g_flOne` | 1.0 | `+0x0C` |
| `DAT_00a0f298` | 0.5 | `+0xF0` near |
| `DAT_00aaa880` | 10000.0 | `+0xF4` far |
| `DAT_00a0f520` | 1000.0 | `+0x104` |
| `DAT_00aaa628` | π/3 | `+0x10C` FOV |
| `DAT_00afdf70` | I₄ | matrix seed |

---

## 6. Gaps

- Nested helper product names (`FUN_00414c20`, `FUN_00972cc0`, matrix allocator).
- Transform return register pairing (decompiler `extraout_EDX`).
- Full field English for secondary flags / nested `PTR_FUN_00a9db18` objects.
- Runtime / bit-exact / differential.
- MSVC demangled class name beyond path evidence.

---

## 7. Verdict

Core ctor CF, ABI, size, camera defaults, product path sealed; nested D3D residual → **accept-with-gaps**.
