# Review B (skeptical / adversarial): `aa_004c0fe0` VOGEnvironmentLiquid_InitFilterPipeline_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c0fe0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-F) |
| **Counterpart** | `reviews/A_aa_004c0fe0_VOGEnvironmentLiquid_InitFilterPipeline_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Fastcall with free `int* param_1` only | **Partial** — ECX is this (`8B F1`); liquid child object, not bare int array API |
| 2 | This is `CreateFluidParticles` / NDRiver | **Falsified** — UIFluid*.fx + VOGEnvironmentLiquid.cpp; CreateFluidParticles is phase-level (W33-S) |
| 3 | Multiple independent callers | **Falsified** — single xref `FUN_004c1960` |
| 4 | Returns “width” / meaningful status | **Falsified** — always `return 0` (`33 C0`); decompiler width label is noise |
| 5 | Scaffold `Named_VOGEnvironmentLiquid_*` alone is enough | **Careful** — path string seals file family; keep **InitFilterPipeline** structural role from body |
| 6 | Clean is bit-exact 1776 B | **Falsified / noted** — contract-level rewrite only; full EH state machine residual |
| 7 | Filter indices are random | **Falsified** — Downsample→BlurH→BlurV→SurfaceBlend order + paired RT cascade sealed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall ECX + ret 0 + body size | **High** | ABI |
| UIFluid / VOGEnvironmentLiquid product plate | **High** | Naming |
| Slot offsets for filters/RTs | **High** | Layout |
| Sole CreateLiquidChild caller | **High** | Lifecycle |
| Nested helper English | **Low** | Naming only |
| Full clean EH fidelity | **Medium** (contract) | Port detail |
| Runtime | **Open** | Matrix |

---

## 3. Cross-check against raw + bytes + xrefs

- `get_function_by_address`: `004c0fe0–004c16cf`.
- Prologue `8B F1`; epilogue `33 C0 … C3`.
- Stores `89 46 20/28/30/38` seal filter slots after 0x18 ctors.
- Caller tool: only `FUN_004c1960`.
- W34-O seals create → this init → activate order.
- Format `0x15` + `0x4011` matches W32-R effect-texture peer pattern (same helper family).

---

## 4. Surviving contract for AutoCore

```
// Port as liquid-child pipeline init (not phase create, not particle spawn):
uint32_t LiquidChild_InitFilterPipeline(LiquidChild* child /*ECX, 0x40*/) {
  // dims from global device
  // 4 filters (0x18) @ +0x20,+0x28,+0x30,+0x38
  // load UIFluidDownsample/BlurH/BlurV/SurfaceBlend.fx
  // bind BackBufferTexture; UIMapExtents0 = (1,1,1/w,1/h)
  // 4 RTs (0xd4): full @ +0x3c; cascade >>2 @ +0x24,+0x2c,+0x34
  // create textures fmt 0x15 flags 0x4011; wire parent+0x98
  // pair setup; surface-blend +0x14 = 1
  return 0;
}
// Call only after FUN_004c1800 ctor. Nested FX helpers stay free.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI, product plate, slots, sole caller, pipeline order. Contract-level clean + helper English residual. **accept-with-gaps**.
