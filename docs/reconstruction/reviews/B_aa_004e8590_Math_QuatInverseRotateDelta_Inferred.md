# Review B (skeptical / adversarial): `aa_004e8590` Math_QuatInverseRotateDelta_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e8590` |
| **VA** | `0x004e8590` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004e8590_Math_QuatInverseRotateDelta_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function is a deep named chain / FX-only helper | Sole leaf with generic math; 1 caller but coefficients match family basis extract | **Falsified as exclusive-domain name** — keep math role |
| 2 | `out = Rᵀ·(p3−p1)` (inverse) | Could be forward `R` or pure rotate without subtract | **Holds** — subtract first; terms are transpose of `004e8ad0`/`b60`/`a40` columns (not forward `004e8bf0`) |
| 3 | Quat layout XYZW | Could be WXYZ | **Holds as XYZW** — same index pattern as verified basis extractors; identity `(0,0,0,1)` → R=I |
| 4 | Writes full float4 out | Decompile only `out[0..2]` | **Falsified if claimed** — **W not written** |
| 5 | Factor is “level-up UI base” | `read_memory` `0xa10e74` = `00 00 00 40` = **2.0f** | **Misnomer only** — value sealed |
| 6 | thiscall / object method | `sub esp,0x30` / `add esp,0x30; ret`; four stack pointers | **Falsified** — **cdecl free function** |
| 7 | Same as `FUN_004e8bf0` | Live decompile: no pos add; different coefficient set | **Distinct** — inverse-delta helper |
| 8 | Product name recovered | No body string/RTTI | **Holds as false** — `_Inferred` required |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Leaf CF / no branches | **Confirmed** | Port wrong side effects |
| `out = Rᵀ·(p3−p1)` (XYZ) | **High** | Local-frame consumers flipped axes |
| Shared `TWO`/`ONE` pool | **Confirmed** | Numeric drift |
| XYZW quat layout | **High** (family-consistent) | Axis swap catastrophe |
| Exact product symbol | Tentative | Cosmetic |
| out.w consumer contract | Open | Rare float4 pack bugs |
| Caller domain English | Partial | Mis-bucket system map only |

---

## 3. Surviving contract

```
// cdecl; leaf; no normalize
Math_QuatInverseRotateDelta_Inferred(const float *origin, // XYZ used
                                     const float *quat,   // XYZW unit expected
                                     const float *point,  // XYZ used
                                     float *out)          // XYZ written; W untouched
{
  // R from unit quat (cols = right, up, forward)
  out[0..2] = transpose(R(quat)) * (point[0..2] - origin[0..2]);
}
```

Sole consumer (`FUN_004b1100`): origin at host`+0x814`, quat stack local after basis prep, point from entity block, out to further local physics/FX math.

---

## 4. Residual uncertainty

| # | Item | Blocks math seal? |
|---|---|---|
| R1 | Product / mangled name | No |
| R2 | Whether any path needs out.w | No (document unwritten) |
| R3 | Full English of `FUN_004b1100` | No |
| R4 | Runtime float bit-exact vs SSE reassoc | Mild |

---

## 5. Concrete checks performed

1. Re-decompile `0x004e8590` — Rᵀ coefficients + delta match sealed form.
2. `read_memory` constants: `0xa0f2a0` → 1.0; `0xa10e74` → 2.0.
3. `read_memory` epilogue `83 C4 30 C3` seals end VA `004e87ce`.
4. Xrefs: **1** site / **1** function — leaf math, multi-domain-capable.
5. Sibling `004e8bf0` dual already sealed — different contract (forward).
6. Cross-check terms vs `fn_004e8ad0_basisExtract.md` columns (transpose).

---

## 6. Falsifications locked in

- **Reject** primary name `Named_CalleeOf_Named_CalleeOf_…_004e8590` as role label.
- **Reject** reading `g_flLevelUpUiBase_Inferred` as a UI scale in this unit (it is **2.0**).
- **Reject** treating this as forward transform `pos + R·v`.
- **Reject** conflating with basis extractors that force `out.w = 0`.

---

## 7. Verdict

**accept-with-gaps** — inverse-rotate math, constants, calling convention, and leaf role sealed High/Confirmed. Keep `Math_QuatInverseRotateDelta_Inferred` until a product symbol appears. Residual: out.w, product name, runtime/diff, sole-caller English.
