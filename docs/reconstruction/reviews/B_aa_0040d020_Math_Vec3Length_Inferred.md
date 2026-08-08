# Review B (skeptical / adversarial): `aa_0040d020` Math_Vec3Length_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d020` |
| **Review type** | Skeptical / adversarial (Path B) |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_0040d020_Math_Vec3Length_Inferred.md` |
| **Work item** | MEGA-137 OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Returns **squared** length (missing `FSQRT`) | Port as `x*x+y*y+z*z` | **Falsified** — `D9 FA` `FSQRT` present before `RET` |
| 2 | Is 2D length (ignores Z) | Only two `FMUL` | **Falsified** — three stack slots `+4/+8/+c` all squared |
| 3 | Includes pick **0.015** scale | Merge `_DAT_00aaacbc` into leaf | **Falsified** — no data load; scale only in `Client_InteractClickPickTarget` after call |
| 4 | Normalizes vector (divide by length) | Port as unit vector | **Falsified** — single scalar return in ST0; no divide / store of components |
| 5 | `__thiscall` / ECX this | Interaction parent thiscall | **Falsified** — no ECX use; pure stack args; plain `RET` |
| 6 | `__stdcall` / `RET 0xC` | Stack cleanup by callee | **Falsified** — `C3` plain `RET`; caller cleans 12 B |
| 7 | XMM SSE path (`sqrtss`) | Modern SSE length | **Falsified** — classic x87 only |
| 8 | Exclusive pick-target helper | Scaffold `Named_CalleeOf_Client_InteractClickPickTarget_*` | **Falsified** — also called from `FUN_005ba440` @ `0x005bad63` |
| 9 | Distance between two points (6 args) | Misread as `dist(a,b)` | **Falsified** — three floats only; callers form deltas **before** call |
| 10 | Calls CRT `sqrt` / `_CIsqrt` | External math | **Falsified** — inline `FSQRT`; callees empty |
| 11 | Mutates args / globals | Side-effect fear | **Falsified** — leaf; only stack loads + FPU |
| 12 | Name is PDB-proven | Symbol inflation | **Not sealed** — **inferred**; Ghidra `FUN_0040d020` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Three-float Euclidean length | **High** | Wrong port formula |
| `FSQRT` present (not squared) | **High** | Off-by-sqrt in consumers |
| No internal scale | **High** | Double-scale if caller also multiplies |
| `__cdecl` ST0 return | **High** | ABI mismatch / stack imbalance |
| Caller list (3 sites) | **High** (addrs) | Miss shared math use |
| Product function name | **Low–Med** | Doc only |
| NaN / −0 behavior | **Low** | Rare edge divergence |
| `FUN_005ba440` product English | **Low** | Out of OWN |

---

## 3. Cross-check against raw

```text
// raw aa_0040d020 ≡ live decompile 2026-08-05 MEGA-137
return SQRT(param_3*param_3 + param_2*param_2 + param_1*param_1);
```

Assembly order (x then y then z) matches decompiler sum associativity; FPU add is commutative for finite values.

Body end: last insn `RET` @ `0x0040d03e`; next function `FUN_0040d040` @ `0x0040d040` after single `CC` pad — **no** hidden scale epilogue.

---

## 4. Surviving contract for AutoCore

```
Math_Vec3Length_Inferred(x, y, z) -> length in ST0:
  return sqrt(x*x + y*y + z*z)   // x87 FSQRT

// NOT: squared length, 2D length, normalize, dist(a,b) six-arg,
//      *0.015 scale, thiscall, CRT sqrt call
// CALLERS form deltas; pick multiplies by DAT_00aaacbc (0.015f) AFTER return
```

---

## 5. Residual gaps (accepted)

- Product / PDB name open → keep `_Inferred`.
- Runtime / bit-exact / differential not run (Terminal false; no Launcher).
- Residual caller `FUN_005ba440` not dualled here.

---

## 6. Verdict rationale

Path B falsifies squared-length, 2D, scale-merge, normalize, wrong ABI, exclusive-pick scaffold, and CRT-sqrt claims. Surviving contract matches Path A. **accept-with-gaps** for product-name + runtime residual only.
