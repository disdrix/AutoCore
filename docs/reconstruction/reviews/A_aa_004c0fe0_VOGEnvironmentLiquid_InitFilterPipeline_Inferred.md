# Review A (reconstruction fidelity): `aa_004c0fe0` VOGEnvironmentLiquid_InitFilterPipeline_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c0fe0` |
| **VA** | `0x004c0fe0`–`0x004c16cf` (**1776 B**) |
| **Canonical name** | `VOGEnvironmentLiquid_InitFilterPipeline_Inferred` |
| **Ghidra name** | `FUN_004c0fe0` |
| **Review date** | `2026-08-04` (W37-F dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-F) |
| **Counterpart** | `reviews/B_aa_004c0fe0_VOGEnvironmentLiquid_InitFilterPipeline_Inferred.md` |
| **System** | VOGEnvironmentLiquid filter/RT pipeline init |
| **Evidence pass** | Live Ghidra decompile + `read_memory` prologue/epilogue + `analyze_function_complete` + sole caller + ctor context |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Initialize liquid-child filter effects (UIFluid*.fx) and cascaded buffer textures for the particle-fluid liquid presentation path (`VOGEnvironmentLiquid.cpp`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004c0fe0_FUN_004c0fe0.md` (+ W37-F append) |
| Annotated | `docs/reconstruction/raw/aa_004c0fe0_FUN_004c0fe0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VOGEnvironmentLiquid_InitFilterPipeline_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c0fe0.cpp` |
| Function | `docs/reconstruction/functions/aa_004c0fe0_*.md` |
| Live | decompile ≡ raw CF; body size; thiscall `8B F1`; ret 0 |
| Context | W34-O CreateLiquidChild; ctor `FUN_004c1800` |

---

## 3. Signature (sealed)

```c
uint32_t __thiscall VOGEnvironmentLiquid_InitFilterPipeline_Inferred(void* liquid_child);
```

| Slot | Source | Conf |
|---|---|---|
| ECX child | `MOV ESI,ECX`; caller passes child | **High** |
| Return 0 | `XOR EAX,EAX` | **High** |
| SEH | `LAB_009a1a6d` | **High** |

---

## 4. Control flow (clean ≡ raw stages)

| Stage | Match | Conf |
|---|---|---|
| Device dims from `DAT_00d1f058` | **Yes** | **High** |
| 4× `new(0x18)+FUN_009886d0` → `+0x20/28/30/38` | **Yes** | **High** |
| UIFluid*.fx load order + fail logs | **Yes** | **High** |
| BackBufferTexture / UIMapExtents0 | **Yes** | **High** |
| 4× `new(0xd4)+FUN_009685e0` + `>>2` cascade | **Yes** | **High** |
| `FUN_0096f0e0(0x15,…,0x4011,…)` ×3 | **Yes** | **High** |
| Pair setup + `+0x14=1` + return 0 | **Yes** | **High** |
| Sole caller CreateLiquidChild | **Yes** | **High** |
| Full EH-state bit-exact clean | contract-level | **N/A gap** |

---

## 5. Gaps

1. Product demangle for 0x18 / 0xd4 host classes.
2. Unowned FX/RT helper full contracts.
3. Clean is contract-level, not full 1776 B EH rewrite.
4. Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals ABI, product strings, slot map, sole caller, pipeline stages. Nested helper English residual. **accept-with-gaps**.
