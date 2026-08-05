# Review A (reconstruction fidelity): `aa_004e8590` Math_QuatInverseRotateDelta_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e8590` |
| **VA** | `0x004e8590` |
| **Body span** | `004e8590` – `004e87ce` (**575** bytes; exclusive end `004e87cf`; epilogue `add esp,0x30; ret`) |
| **Canonical name (Ghidra)** | `FUN_004e8590` |
| **Proposed name** | `Math_QuatInverseRotateDelta_Inferred` (**High** role; product string absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_CalleeOf_…_004e8590` — **too narrow** |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B W23-O) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile ≡ constants) |
| **Counterpart** | `reviews/B_aa_004e8590_Math_QuatInverseRotateDelta_Inferred.md` |
| **System** | pure math / transform |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Leaf helper: **transform a world-space delta into the local frame of a unit quaternion** via the transpose of the standard rotation matrix.

```
out.xyz = R(quat)^T * (point.xyz - origin.xyz)
```

where `R` columns are the verified basis extractors:

| Column | Axis | Extractor VA |
|---|---|---|
| 0 | right (+X) | `FUN_004e8ad0` @ `0x004e8ad0` |
| 1 | up (+Y) | `FUN_004e8b60` @ `0x004e8b60` |
| 2 | forward (+Z) | `FUN_004e8a40` @ `0x004e8a40` |

**Not** the forward transform `FUN_004e8bf0` (`out = pos + R·v`). **Not** a basis-column extractor.

**Calling convention:** MSVC **cdecl** — four stack `float*`, no ECX this, **`ret`** (not `ret N`). Leaf (no callees).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004e8590_FUN_004e8590.md` |
| Annotated | `docs/reconstruction/raw/aa_004e8590_FUN_004e8590.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004e8590.cpp` |
| Named | `docs/reconstruction/reconstructed-exact/Math_QuatInverseRotateDelta_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_004e8590_Math_QuatInverseRotateDelta_Inferred.md` |
| Sibling basis set | `fn_004e8ad0_basisExtract.md` |
| Forward sibling | `Math_QuatTransformPoint_Inferred` @ `0x004e8bf0` (dual sealed) |

**This pass (live):** Ghidra `decompile_function` + `get_function_by_address` @ `0x004e8590`; `get_function_callers` / `get_function_xrefs` (1 site); `read_memory` prolog/epilogue + `g_flOne@00a0f2a0` + `g_flLevelUpUiBase_Inferred@00a10e74`; caller decompile `FUN_004b1100`. **Not performed:** Launcher, runtime, bit-exact image diff, ledger updates. **No** `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span `004e8590`–`004e87ce` (`ret` @ end) | **High** | `read_memory` epilogue `83 C4 30 C3` |
| Leaf; cdecl; 4×`float*` stack; `ret` | **High** | decompile + stack params; no call outs |
| `param_1` = origin XYZ (W unread) | **High** | only `*p1`, `p1[1]`, `p1[2]` used |
| `param_2` = quat XYZW (family layout) | **High** | terms match transpose of basis columns |
| `param_3` = world point XYZ (W unread) | **High** | only `*p3`, `p3[1]`, `p3[2]` |
| `param_4` = out XYZ; **W not written** | **High** | decompile stores only `[0..2]` |
| Factor `TWO` = **2.0f** @ `0x00a10e74` | **Confirmed** | `read_memory` → `00 00 00 40` |
| Factor `ONE` = **1.0f** @ `0x00a0f2a0` | **Confirmed** | `read_memory` → `00 00 80 3f` |
| `g_flLevelUpUiBase_Inferred` misnomer | **High** | same shared 2.0 pool as basis extract |
| Closed form `out = R^T·(p3−p1)` | **High** | coefficients = transpose of forward R |
| Distinct from `004e8bf0` | **High** | no pos add; subtract first; Rᵀ terms |
| Product C++ / mangled name | **Tentative** | no string/RTTI on body → keep `_Inferred` |
| Sole-caller domain English | **Partial** | `FUN_004b1100` physics/FX path |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load `TWO`/`ONE` pool floats | **Yes** |
| Build Rᵀ coefficients from quat | **Yes** |
| `d = p3 − p1` | **Yes** |
| `out = Rᵀ · d` (three components) | **Yes** |
| No branches / no callees / single `return` | **Yes** |
| No invented normalize / conjugate API | **Yes** (math ≡ conjugate-rotate for unit q) |

### 4.1 Sealed closed form

Quaternion `q = (x,y,z,w) = param_2[0..3]`. Points `p1`, `p3`. Delta `d = p3 − p1`.

```
// TWO = 2.0f @ 0xa10e74; ONE = 1.0f @ 0xa0f2a0
// out = R(q)^T * d

out.x = d.x*(ONE - (y*y + z*z)*TWO) + d.y*( (x*y + z*w)*TWO ) + d.z*( (x*z - y*w)*TWO )
out.y = d.x*( (x*y - z*w)*TWO )     + d.y*(ONE - (x*x + z*z)*TWO) + d.z*( (y*z + x*w)*TWO )
out.z = d.x*( (x*z + y*w)*TWO )     + d.y*( (y*z - x*w)*TWO )     + d.z*(ONE - (x*x + y*y)*TWO )
// out.w not written
```

### 4.2 Hand checks

| Input | Expected out.xyz |
|---|---|
| `q=(0,0,0,1)`, `p3−p1=(a,b,c)` | `(a,b,c)` |
| `q` any unit, `p3=p1` | `(0,0,0)` |
| `q` any unit, `p1=0`, `p3=v` | `R^T · v` (= local coords of world vector v) |

---

## 5. Callers (live xrefs)

1 unconditional call site:

| Caller VA | Function | Site |
|---|---|---|
| `0x004b1100` | `FUN_004b1100` | `0x004b12ea` |

Call shape (from live decompile of caller):

```
FUN_004e8590(*param_1 + 0x814, &local_10, pfVar1, local_1c);
// origin = host+0x814; quat = local_10 (after basis helpers); point = this+0x178-ish velocity/pos block; out local_1c
```

---

## 6. Sibling contrast (OWN math family)

| VA | Role | Contract |
|---|---|---|
| `0x004e8ad0` | right column of R | `out = col0(q)`, W=0 |
| `0x004e8b60` | up column of R | `out = col1(q)`, W=0 |
| `0x004e8a40` | forward column of R | `out = col2(q)`, W=0 |
| `0x004e8bf0` | transform point | `out = pos + R(q)·v`, W unwritten |
| **`0x004e8590`** | **inverse-rotate delta** | **`out = Rᵀ·(p3−p1)`**, W unwritten |

---

## 7. Gaps

1. Product / PDB mangled name.
2. Full English taxonomy of sole caller (`FUN_004b1100`) — role sealed as generic math.
3. Whether any path depends on **stale out.w**.
4. Runtime / bit-exact / diff open.

**Verdict:** **accept-with-gaps** — math + constants + calling convention + sole-caller leaf role sealed; keep `_Inferred`.

---

## Checklist

| Check | Result |
|---|---|
| Live decompile matches raw/clean CF | **Pass** |
| Constants `1.0` / `2.0` via `read_memory` | **Pass** |
| Matches transpose of basis-column family | **Pass** |
| Distinct from forward `004e8bf0` | **Pass** |
| Product name without `_Inferred` | **Fail** (expected) |
| Verdict | **accept-with-gaps** |
