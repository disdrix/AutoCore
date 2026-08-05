# Review A (reconstruction fidelity): `aa_0048f370` PalantirEnv_RebuildDefaultLights_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0048f370` |
| **VA** | `0x0048f370`–`0x0048f65f` exclusive (**751 B** / `0x2EF`) |
| **Canonical name** | `PalantirEnv_RebuildDefaultLights_Inferred` |
| **Ghidra name** | `FUN_0048f370` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-R) |
| **Counterpart** | `reviews/B_aa_0048f370_PalantirEnv_RebuildDefaultLights_Inferred.md` |
| **System** | client / Palantir env default lights |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (+ callers). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Env host method that **rebuilds** the default directional + hemispheric light pair:

1. `FUN_0048eb10` — destroy prior `+0x104` / `+0x108`.
2. `new(0x94)` + `FUN_0096e4b0` → `env+0x108` (directional): `"Direction"` + `"Color"`.
3. `new(0x94)` + `FUN_0096e4b0` → `env+0x104` (hemispheric): `"Hemispheric"` / `"ColorTop"` / `"ColorBottom"`.
4. Optional `FUN_005b3520` if `env+0xC4 != 0`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W32-R) | `docs/reconstruction/raw/aa_0048f370_FUN_0048f370.md` |
| Annotated | `docs/reconstruction/raw/aa_0048f370_FUN_0048f370.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/PalantirEnv_RebuildDefaultLights_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0048f370.cpp` |
| Function records | `functions/aa_0048f370_FUN_0048f370.md`, `functions/aa_0048f370_PalantirEnv_RebuildDefaultLights_Inferred.md` |
| Related | W31-P `PalantirEnv_InitPhases_Inferred`; teardown peer `FUN_0048eb10` |
| Live | decompile ≡ raw; prologue `8B F1`; epilogue bare `C3`; 3 xrefs; floats/ARGB sealed |

---

## 3. Signature (sealed)

```c
// __thiscall; ECX=env*; bare RET; void
void __thiscall PalantirEnv_RebuildDefaultLights_Inferred(void *env);
```

| Formal | Source | Conf |
|---|---|---|
| env | ECX (`8B F1`); callers load from `parent+0xE894` | **High** |
| return | void (no EAX setup) | **High** |
| cleanup | bare `C3` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
SEH LAB_009a0822
FUN_0048eb10(env)                         // tear old lights
new(0x94)+ctor → +0x108                   // directional
  setup Direction (-0.1,-0.5,1.0); Color
  refcount++ / flag+0xd0=1
new(0x94)+ctor → +0x104                   // hemispheric
  "Hemispheric"; ColorTop; ColorBottom
  refcount++ / flag+0xd0=1
if +0xC4: FUN_005b3520()
RET
```

| Stage | Match | Conf |
|---|---|---|
| Body 0x2EF / bare RET / thiscall | **Yes** | **High** |
| Slots +0x108 / +0x104 size 0x94 | **Yes** | **High** |
| Strings Direction/Color/Hemispheric/ColorTop/ColorBottom | **Yes** | **High** |
| Dir floats -0.1 / -0.5 / 1.0 | **Yes** (`read_memory`) | **High** |
| ARGB 0xFF707B8F / 0xFFD1A56D / 0xFF3E2F2D | **Yes** | **High** |
| 3 callers all pass env in ECX | **Yes** | **High** |

---

## 5. Gaps

- Product/PDB English for light host class (`FUN_0096e4b0`) and first `FUN_0096e430` (no stack string at first site).
- Exact product meaning of `FUN_0074e310` / `FUN_0074e0d0` / `FUN_0076f5f0` / `FUN_009733d0`.
- Whether teardown-path caller (`FUN_00944b20`) is rebuild-on-session-edge vs misnamed.
- Runtime / bit-exact / differential.

---

## 6. Verdict

CF/ABI/slots/strings/floats/callers sealed against live decompile + `read_memory`. Residual product demangle + helper English → **accept-with-gaps**.
