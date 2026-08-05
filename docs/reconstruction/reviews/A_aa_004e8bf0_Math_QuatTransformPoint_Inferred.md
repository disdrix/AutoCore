# Review A (reconstruction fidelity): `aa_004e8bf0` Math_QuatTransformPoint_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e8bf0` |
| **VA** | `0x004e8bf0` |
| **Body span** | `004e8bf0` – `004e8db8` (**457** bytes; exclusive end `004e8db9`; epilogue `pop esi; mov esp,ebp; pop ebp; ret`) |
| **Canonical name (Ghidra)** | `FUN_004e8bf0` |
| **Proposed name** | `Math_QuatTransformPoint_Inferred` (**High** role; product string absent) |
| **Prior scaffold alias** | `Named_CalleeOf_Named_SkyBoxParticles_004e8bf0` — **too narrow** (skybox is one of many consumers) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile ≡ constants) |
| **Counterpart** | `reviews/B_aa_004e8bf0_Math_QuatTransformPoint_Inferred.md` |
| **Scratch** | `reviews/a_004e8bf0.md` |
| **System** | pure math / transform (camera, physics, particles, AI consumers) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Leaf helper: **transform a local 3-vector by a unit quaternion and add a world position**.

```
out.xyz = pos.xyz + R(quat) * vec.xyz
```

where `R` is the standard unit-quaternion → rotation matrix whose **columns** are the verified basis extractors:

| Column | Axis | Extractor VA |
|---|---|---|
| 0 | right (+X) | `FUN_004e8ad0` @ `0x004e8ad0` |
| 1 | up (+Y) | `FUN_004e8b60` @ `0x004e8b60` |
| 2 | forward (+Z) | `FUN_004e8a40` @ `0x004e8a40` |

Evidence peer: `docs/reconstruction/physics/verified/fn_004e8ad0_basisExtract.md`.

**Not** the inverse / delta helper `FUN_004e8590` (`out = Rᵀ·(p3−p1)` — no position add). **Not** a basis-column extractor.

**Calling convention:** MSVC **cdecl** — four stack `float*`, **no** ECX this, **`ret`** (not `ret N`). Leaf (no callees).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004e8bf0_FUN_004e8bf0.md` |
| Annotated | `docs/reconstruction/raw/aa_004e8bf0_FUN_004e8bf0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004e8bf0.cpp` |
| Scaffold alias | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_SkyBoxParticles_004e8bf0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004e8bf0_FUN_004e8bf0.md` |
| Sibling basis set | `fn_004e8ad0_basisExtract.md` (`004e8ad0` / `004e8a40` / `004e8b60`) |
| Inverse sibling | `FUN_004e8590` @ `0x004e8590` (live decompile this pass) |
| Camera consumer | `Client_Camera_ApplyLookOffset` / `FUN_0091a5f0` duals |

**This pass (live):** Ghidra `decompile_function` + `analyze_function_complete` @ `0x004e8bf0`; `get_function_callers` / `get_xrefs_to` (16 sites / 13 functions); `read_memory` body + `g_flOne@00a0f2a0` + `g_flLevelUpUiBase_Inferred@00a10e74`; sibling decompiles `004e8590` / known basis set. **Not performed:** Launcher, runtime, bit-exact image diff, ledger updates.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span `004e8bf0`–`004e8db8` (`ret` @ end) | **High** | `read_memory` epilogue `5E 8B E5 5D C3` |
| Leaf; cdecl; 4×`float*` stack; `ret` | **High** | decompile + stack params; no call outs |
| `param_1` = position XYZ (W unread) | **High** | only `*p1`, `p1[1]`, `p1[2]` used |
| `param_2` = quat XYZW (same layout as basis extractors) | **High** | terms match column math of `004e8ad0`/`b60`/`a40` |
| `param_3` = local vector XYZ (W unread) | **High** | only `*p3`, `p3[1]`, `p3[2]` |
| `param_4` = out XYZ; **W not written** | **High** | decompile stores only `[0..2]` |
| Factor `TWO` = **2.0f** @ `0x00a10e74` | **Confirmed** | `read_memory` → `00 00 00 40` |
| Factor `ONE` = **1.0f** @ `0x00a0f2a0` | **Confirmed** | `read_memory` → `00 00 80 3f` |
| `g_flLevelUpUiBase_Inferred` misnomer (shared 2.0 pool) | **High** | same as basis extract doc |
| Closed form `out = pos + R(q)·v` | **High** | three phases = cols 0,1,2 of R × v components |
| Matches camera comment `world = pos + R*lookVec` | **High** | `FUN_0091a5f0` @ `0091a951`; dual A/B sealed |
| Multi-domain leaf (not skybox-only) | **High** | 13 distinct callers incl. camera + particles + AI |
| Product C++ / mangled name | **Tentative** | no string/RTTI on body → keep `_Inferred` |
| Whether callers treat out as float3 vs float4 | **Partial** | W unwritten; camera packs `local_20` then gated set |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load `TWO`/`ONE` pool floats | **Yes** |
| Phase vx: accumulate col0(q)·vx + pos | **Yes** |
| Phase vy: accumulate col1(q)·vy | **Yes** |
| Phase vz: accumulate col2(q)·vz | **Yes** |
| No branches / no callees / single `return` | **Yes** |
| No invented normalize / conjugate / inverse | **Yes** |

### 4.1 Sealed closed form

Quaternion `q = (x,y,z,w) = param_2[0..3]`. Vector `v = param_3[0..2]`. Position `p = param_1[0..2]`.

```
// TWO = 2.0f @ 0xa10e74; ONE = 1.0f @ 0xa0f2a0
// R columns = right / up / forward (fn_004e8ad0_basisExtract)

out.x = p.x + vx*(ONE - (y*y + z*z)*TWO) + vy*( (x*y - z*w)*TWO ) + vz*( (x*z + y*w)*TWO )
out.y = p.y + vx*( (x*y + z*w)*TWO )     + vy*(ONE - (x*x + z*z)*TWO) + vz*( (y*z - x*w)*TWO )
out.z = p.z + vx*( (x*z - y*w)*TWO )     + vy*( (y*z + x*w)*TWO )     + vz*(ONE - (x*x + y*y)*TWO )
// out.w not written
```

Decompiler phases match this accumulate form (col0 first, then col1, then col2).

### 4.2 Hand checks (identity + pure translation)

| Input | Expected out.xyz |
|---|---|
| `q=(0,0,0,1)`, `v=(a,b,c)`, `p=(px,py,pz)` | `(px+a, py+b, pz+c)` |
| `q` any unit, `v=(0,0,0)` | `p` |
| `q` any unit, `p=(0,0,0)` | `R(q)·v` (= col0·vx + col1·vy + col2·vz) |

---

## 5. Callers (live xrefs)

16 unconditional call sites across **13** functions (`analyze_function_complete` / `get_xrefs_to`):

| Caller VA | Function | Sites |
|---|---|---|
| `0x0091a5f0` | `Client_Camera_ApplyLookOffset` / `FUN_0091a5f0` | 1 (`0091a951`) |
| `0x004b75d0` | `FUN_004b75d0` | 4 |
| `0x004b9300` | `FUN_004b9300` | 1 |
| `0x0056c0a0` | `FUN_0056c0a0` | 1 |
| `0x0056ca70` | `FUN_0056ca70` | 1 |
| `0x0058e980` | `FUN_0058e980` | 1 |
| `0x005911b0` | `FUN_005911b0` | 1 |
| `0x005a8650` | `FUN_005a8650` | 1 |
| `0x005bc3c0` | `FUN_005bc3c0` (skybox / particles path; scaffold parent) | 1 |
| `0x005cd220` | `FUN_005cd220` | 1 |
| `0x005cedf0` | `FUN_005cedf0` | 1 |
| `0x00615020` | `FUN_00615020` | 1 |
| `0x00620480` | `FUN_00620480` | 1 |

Camera binding (High CF from existing dual): pos = rb`+0xb0` (else entity-local `+0x84`); quat = rb`+0x30` (else `+0x94`); vec = look offset; out → `FUN_004c3a40` gated apply.

---

## 6. Sibling contrast (OWN math family)

| VA | Role | Contract |
|---|---|---|
| `0x004e8ad0` | right column of R | `out = col0(q)`, W=0 |
| `0x004e8b60` | up column of R | `out = col1(q)`, W=0 |
| `0x004e8a40` | forward column of R | `out = col2(q)`, W=0 |
| **`0x004e8bf0`** | **transform point** | **`out = pos + R(q)·v`**, W unwritten |
| `0x004e8590` | inverse delta (sibling) | `out = Rᵀ·(p3−p1)` (no add) |

---

## 7. Gaps

1. Product / PDB mangled name.
2. Full English taxonomy of non-camera callers (particles, AI, spawn) — role sealed as generic math.
3. Whether any caller depends on **stale out.w**.
4. Runtime / bit-exact / diff open.

**Verdict:** **accept-with-gaps** — math + constants + multi-caller leaf sealed; keep `_Inferred`.

---

## Checklist

| Check | Result |
|---|---|
| Live decompile matches raw/clean CF | **Pass** |
| Constants `1.0` / `2.0` via `read_memory` | **Pass** |
| Matches basis-column family | **Pass** |
| Skybox-only name rejected | **Pass** |
| Product name without `_Inferred` | **Fail** (expected) |
| Verdict | **accept-with-gaps** |
