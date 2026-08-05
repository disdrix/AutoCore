# Review A (reconstruction fidelity): `aa_005769c0` WaterPhase_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005769c0` |
| **VA** | `0x005769c0`–`0x00576a07` exclusive (**71 B** / `0x47`) |
| **Canonical name** | `WaterPhase_Ctor_Inferred` |
| **Ghidra name** | `FUN_005769c0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-S) |
| **Counterpart** | `reviews/B_aa_005769c0_WaterPhase_Ctor_Inferred.md` |
| **System** | client / VOGEnvironmentSector water phase |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (body + vtbl). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Complete ctor of the **0x20** water-phase object:

1. SEH frame (`LAB_009a50ef`).
2. `this+0x04 = view` (stack formal).
3. `*this = PTR_FUN_009d3b04`.
4. Zero dwords at `+0x0C..+0x1C`.
5. **`+0x08` not written**; `RET 4`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W32-S) | `docs/reconstruction/raw/aa_005769c0_FUN_005769c0.md` |
| Annotated | `docs/reconstruction/raw/aa_005769c0_FUN_005769c0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/WaterPhase_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005769c0.cpp` |
| Function records | `functions/aa_005769c0_FUN_005769c0.md`, `functions/aa_005769c0_WaterPhase_Ctor_Inferred.md` |
| Related | W31-P `PalantirEnv_InitPhases_Inferred`; peer `WaterPhase_RegisterToken_Inferred` |
| Live | decompile ≡ raw CF; body 71 B; `C2 04 00`; vtbl `0x009d3b04` |

---

## 3. Signature (sealed)

```c
// __thiscall; ECX=self*; stack view*; RET 4; returns self
void *__thiscall WaterPhase_Ctor_Inferred(void *self, void *view);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B C1` → EAX) | **High** |
| view | stack; stored at `+0x04` | **High** |
| return | self (EAX preserved from early mov) | **High** |
| cleanup | `RET 4` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
SEH install
this+4 = view
*this  = vtbl 0x009d3b04
zero +0x0C,+0x10,+0x14,+0x18,+0x1C
SEH teardown; RET 4
```

| Stage | Match | Conf |
|---|---|---|
| Body 71 B / RET 4 | **Yes** | **High** |
| Vtbl constant | **Yes** | **High** |
| Skip +0x08 | **Yes** (bytes) | **High** |
| Water singleton role | **Yes** (W31-P caller) | **High** |

---

## 5. Gaps

- Product C++ demangle for water class.
- Field English for zero bank and unset `+0x08`.
- Full vtbl product method names.
- Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals ctor ABI, size context, vtbl, layout holes, and CF. Residual product English → **accept-with-gaps**.
