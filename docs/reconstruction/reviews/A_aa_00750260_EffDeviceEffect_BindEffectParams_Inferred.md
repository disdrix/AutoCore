# Review A (reconstruction fidelity): `aa_00750260` EffDeviceEffect_BindEffectParams_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00750260` |
| **VA** | `0x00750260`–`0x0075184F` (**5616 B** / `0x15F0`) |
| **Canonical name** | `EffDeviceEffect_BindEffectParams_Inferred` |
| **Ghidra name** | `FUN_00750260` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-C) |
| **Counterpart** | `reviews/B_aa_00750260_EffDeviceEffect_BindEffectParams_Inferred.md` |
| **System** | palantir `effDeviceEffect.cpp` post-create effect bind |
| **Evidence pass** | Live `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (prologue/epilogue) + callers/callees + caller decompile `FUN_00751890`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Bind/parse a compiled `ID3DXEffect` into the device-effect object: technique/pass walk, light name construction (`LightCount_`/`LightSupport_`), matrix semantic classification (`WorldView`, `InvWorldViewProjection`, …), material color tags, and table allocation. Invoked from fallback-effect path after `D3DXCreateEffect`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W34-C append) | `docs/reconstruction/raw/aa_00750260_FUN_00750260.md` |
| Annotated | `docs/reconstruction/raw/aa_00750260_FUN_00750260.annotated.md` |
| Clean (structural) | `docs/reconstruction/reconstructed-exact/EffDeviceEffect_BindEffectParams_Inferred.cpp` |
| Scaffold clean | `FUN_00750260.cpp` / `Named_effDeviceEffect_00750260.cpp` |
| Function record | `docs/reconstruction/functions/aa_00750260_EffDeviceEffect_BindEffectParams_Inferred.md` |
| Caller | `FUN_00751890` live decompile — `D3DXCreateEffect` then `FUN_00750260(obj, path)` |
| Live | body bounds `00750260`–`00751850`; prologue `55 8B EC 83 E4 F8`; string table sealed |

---

## 3. Signature (sealed / partial)

```c
// EBP frame; object* at [EBP+8]; call site second stack arg = path/name string*.
// Returns int: 0 success, 0xFFFFFFFF fail.
int EffDeviceEffect_BindEffectParams_Inferred(void* device_effect /*, path? */);
```

| Formal | Source | Conf |
|---|---|---|
| device_effect | `[EBP+8]` → EBX; fields `+0xC` effect COM, `+0x30` pass array | **High** |
| path/name (2nd) | Call site push only; decompiler lost formal | **Med** |
| return int | fail `return -1`; success epilogue `XOR EAX,EAX` | **High** |
| SEH | `LAB_009b1b66` | **High** |

---

## 4. Control flow (decompile authority; types noisy)

| Stage | Evidence | Conf |
|---|---|---|
| Body size 0x15F0 | Ghidra function bounds | **High** |
| Effect COM vtable walk via `param_1+0xC` | repeated `+0x30/+0x4C/+0x54/+0xEC` | **High** |
| Light name build via `FUN_00416410` + `"LightCount_"` | decompile | **High** |
| Matrix name table → slot IDs | `_stricmp` chain | **High** |
| Fail on empty pass table | `return 0xffffffff` @ ~`0x750bd5` path | **High** |
| Source plate | `effDeviceEffect.cpp` log string | **High** |
| Full typed field map | type-prop WARNING | **Low** |

---

## 5. Gaps

- Full type recovery (decompiler: type propagation not settling).
- Exact role/reads of call-site 2nd stack formal (path string).
- Nested callees unowned (except `FUN_00416410` dual-owned W33-F).
- Line-faithful clean rewrite deferred (structural clean only).
- Runtime / bit-exact / differential.
- Product method English beyond source path inference.

---

## 6. Verdict

Product identity, body bounds, ABI skeleton, string semantic table, sole caller, and fail/success return shape are sealed. Residual type/2nd-arg/nested/runtime gaps → **accept-with-gaps**.
