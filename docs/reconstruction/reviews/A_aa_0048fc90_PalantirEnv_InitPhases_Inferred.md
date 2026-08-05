# Review A (reconstruction fidelity): `aa_0048fc90` PalantirEnv_InitPhases_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048fc90` |
| **VA** | `0x0048fc90`–`0x0048fed0` exclusive (**576 B** / `0x240`) |
| **Canonical name** | `PalantirEnv_InitPhases_Inferred` |
| **Ghidra name** | `FUN_0048fc90` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-P) |
| **Counterpart** | `reviews/B_aa_0048fc90_PalantirEnv_InitPhases_Inferred.md` |
| **System** | client / VOGEnvironmentSector phases |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + callers. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Env host method that bootstraps VOG environment **phases**:

1. Prelude `FUN_00756320(flag)` / `FUN_0048f370` / `FUN_0048ed00`.
2. Lazy Water singleton (`new(0x20)` + view@`+0xC0`) if `DAT_00b04808==0`.
3. Lazy Distort singleton (`new(0x18)` + view) if `DAT_00b04818==0`.
4. Always: owned `0x170`/`0xA0`/`0xC8` at `+0xC4/+0xC8/+0xCC` from parent@`+0xB8`, each with follow-up `(1)`.
5. `FUN_004982d0`; load `"NDRiver.fx"`; zero `+0x178`; return **0**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W31-P) | `docs/reconstruction/raw/aa_0048fc90_FUN_0048fc90.md` |
| Annotated | `docs/reconstruction/raw/aa_0048fc90_FUN_0048fc90.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/PalantirEnv_InitPhases_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0048fc90.cpp` |
| Function records | `functions/aa_0048fc90_FUN_0048fc90.md`, `functions/aa_0048fc90_PalantirEnv_InitPhases_Inferred.md` |
| Related | W30-F factory; ctor peer `PalantirEnv_Ctor_Inferred` |
| Live | decompile ≡ raw; epilogue `33 C0` + `C2 04 00`; sole xref `0x004cdbf0`; strings water/distort/NDRiver |

---

## 3. Signature (sealed)

```c
// __thiscall; ECX=env*; stack flag; RET 4; returns 0
uint32_t __thiscall PalantirEnv_InitPhases_Inferred(void *env, void *flag);
```

| Formal | Source | Conf |
|---|---|---|
| env | ECX (`8B F1`); factory loads from `parent+0xE894` | **High** |
| flag | stack; factory **1** | **High** |
| return | 0 (`XOR EAX,EAX`) | **High** |
| cleanup | `RET 4` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
SEH LAB_009a08ac
prelude(flag)
if !water: new(0x20)+ctor(view); owner=this; vcall+0x20; init; log on fail
if !distort: new(0x18)+ctor(view); owner=this; vcall+0x20; init; log on fail
new(0x170)+ctor(parent)→+0xC4; enable(1)
new(0xA0)+ctor(parent)→+0xC8; enable(1)
new(0xC8)+ctor(parent)→+0xCC; enable(1)
FUN_004982d0; load NDRiver.fx; +0x178=0
return 0
```

| Stage | Match | Conf |
|---|---|---|
| Body 0x240 / RET 4 / return 0 | **Yes** | **High** |
| Water/distort path strings | **Yes** | **High** |
| Owned sizes + offs | **Yes** | **High** |
| Sole caller after cross-wire | **Yes** | **High** |

---

## 5. Gaps

- Product demangle for phase classes beyond log strings.
- Semantics of flag formal beyond factory constant **1**.
- Product meaning of `FUN_004982d0` / FX string helpers.
- Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals method role, ABI, singleton vs owned split, sizes, strings, and sole caller. Residual product English → **accept-with-gaps**.
