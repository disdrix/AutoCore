# Review A (reconstruction fidelity): `aa_00864f20` NDUIFxPanel_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00864f20` |
| **VA** | `0x00864f20` |
| **Canonical name** | `NDUIFxPanel_Ctor_Inferred` (Ghidra `FUN_00864f20`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00864f20_NDUIFxPanel_Ctor_Inferred.md` |
| **System** | `client-ui` / NDUI FX / special panel |
| **Live tools** | Ghidra `batch_decompile` + `get_function_signature` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**High.** **FX / special chrome panel subclass ctor**. Used once per CreateChildWidgets host for `*_wnd_fx.xml` (Arena `this+0x538`, Trade `this+0x518`, options dialogs, etc.).

Flow: SEH → `FUN_007b5dd0(this, 0)` → vtbl `PTR_FUN_00a61504` → FX-specific fields (scale from screen height × `_DAT_00aaab40`, mode `3`, flag `+0x489=1`).

Caller size class: **`operator_new(0x4bc)`**.

---

## 2. Artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00864f20_FUN_00864f20.md` |
| Annotated | `docs/reconstruction/raw/aa_00864f20_FUN_00864f20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00864f20.cpp` |
| Function record | `docs/reconstruction/functions/aa_00864f20_FUN_00864f20.md` |
| Live | decompile ≡ raw (38 insn, 1 BB) |

---

## 3. Signature / flow

```c
undefined4 * FUN_00864f20(undefined4 *param_1 /*this*/);
// always passes cookie 0 into base
```

| Field write | Value | Conf |
|---|---|---|
| Base | `FUN_007b5dd0(this, 0)` | **High** |
| Vtbl | `PTR_FUN_00a61504` | **High** |
| `[0x128]` | `DAT_00aaa8fc` | **High** |
| `+0xbf` | 0 | **High** |
| `[0x122]` | 0 | **High** |
| `+0x489` | 1 | **High** |
| `[0x125..0x127]`, `[0x129]` | 0 | **High** |
| `[0x12a]` | `(float)DAT_00d1e81c * _DAT_00aaab40` | **High** (resolution-scaled) |
| `[300]` / `[0x12c]` | `g_nInferredThreatDefault` (Ghidra name; residual product meaning) | **Probable name / High store** |
| `[0x12d]`, `[299]`, `[0x12e]` | 0 | **High** |
| `[0x123]` | 3 | **High** |

---

## 4. Confidence

| Claim | Confidence | Notes |
|---|---|---|
| Role = FX panel ctor | **High** | sole `0x4bc` factory + `wnd_fx.xml` sites |
| Distinct subclass | **High** | unique vtbl `00a61504` |
| Product class / threat global name | **Tentative** | Ghidra symbol may be misapplied |
| Runtime | **Open** | — |

---

## 5. Gaps

1. True meaning of `g_nInferredThreatDefault` at this site (likely unrelated rename residual).
2. Mode `3` enum.
3. Why cookie is hard-coded 0 vs base param.
