# Review B (skeptical / adversarial): `aa_004e8bf0` Math_QuatTransformPoint_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e8bf0` |
| **VA** | `0x004e8bf0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004e8bf0_Math_QuatTransformPoint_Inferred.md` |
| **Scratch** | `reviews/a_004e8bf0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function is skybox-particle–specific | 13 callers incl. camera `0091a5f0`, AI, multiple FX; scaffold alias only named from one parent | **Falsified** — generic leaf |
| 2 | `out = pos + R(q)·v` (forward transform) | Could be inverse `Rᵀ` or pure rotate without pos | **Holds** — pos terms always added on first phase; matrix terms match **forward** columns of `004e8ad0`/`b60`/`a40`, not `004e8590` inverse |
| 3 | Quat layout XYZW | Could be WXYZ | **Holds as XYZW** — same index pattern as verified basis extractors; identity `(0,0,0,1)` → R=I |
| 4 | Writes full float4 out | Decompile only `out[0..2]` | **Falsified if claimed** — **W not written** (gap, not math error) |
| 5 | Factor is “level-up UI base” | `read_memory` `0xa10e74` = `00 00 00 40` = **2.0f** | **Misnomer only** — value sealed |
| 6 | thiscall / object method | Stack four pointers; `ret` not `ret N`; no ECX use in prolog beyond frame | **Falsified** — **cdecl free function** |
| 7 | Same as `FUN_004e8590` | Live decompile sibling: delta then different coefficient set | **Distinct** — inverse-delta helper |
| 8 | Product name recovered | No body string/RTTI | **Holds as false** — `_Inferred` required |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Leaf CF / no branches | **Confirmed** | Port wrong side effects |
| `out = pos + R·v` (XYZ) | **High** | Camera look attach wrong |
| Shared `TWO`/`ONE` pool | **Confirmed** | Numeric drift |
| XYZW quat layout | **High** (family-consistent) | Axis swap catastrophe |
| Exact product symbol | Tentative | Cosmetic |
| out.w consumer contract | Open | Rare float4 pack bugs |
| Full non-camera caller English | Partial | Mis-bucket system map only |

---

## 3. Surviving contract

```
// cdecl; leaf; no normalize
Math_QuatTransformPoint_Inferred(const float *pos,   // XYZ used
                                 const float *quat,  // XYZW unit expected
                                 const float *vec,   // XYZ used
                                 float *out)         // XYZ written; W untouched
{
  // R from unit quat (cols = right, up, forward)
  out[0..2] = pos[0..2] + R(quat) * vec[0..2];
}
```

Camera consumer (`FUN_0091a5f0`): `pos`/`quat` from rigid-body or entity-local fallback; `vec` = look offset; result to gated position apply.

---

## 4. Residual uncertainty

| # | Item | Blocks math seal? |
|---|---|---|
| R1 | Product / mangled name | No |
| R2 | Whether any path needs out.w | No (document unwritten) |
| R3 | Per-caller domain labels beyond camera | No |
| R4 | Runtime float bit-exact vs SSE reassoc | Mild (retail uses SSE mul/add order) |

---

## 5. Concrete checks performed

1. Re-decompile `0x004e8bf0` — three accumulate phases match col0/col1/col2.
2. `read_memory` constants: `0xa0f2a0` → 1.0; `0xa10e74` → 2.0.
3. `read_memory` epilogue `5E 8B E5 5D C3` seals end VA `004e8db8`.
4. Xrefs: 16 sites / 13 functions — not skybox-only.
5. Sibling `004e8590` decompile — different contract (inverse delta).
6. Cross-check terms vs `fn_004e8ad0_basisExtract.md` columns.

---

## 6. Falsifications locked in

- **Reject** primary name `Named_CalleeOf_Named_SkyBoxParticles_004e8bf0` as role label.
- **Reject** reading `g_flLevelUpUiBase_Inferred` as a UI scale in this unit (it is **2.0**).
- **Reject** treating this as basis-extract sibling that zeroes W on out.
- **Reject** conflating with `FUN_004e8590`.

---

## 7. Verdict

**accept-with-gaps** — transform math, constants, calling convention, and multi-caller leaf role sealed High/Confirmed. Keep `Math_QuatTransformPoint_Inferred` until a product symbol appears. Residual: out.w, product name, runtime/diff.
