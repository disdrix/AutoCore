# Dual A/B report — W23-O OWN VAs `0x004e8590` + `0x00916090`

**Date:** 2026-07-29  
**Agent:** W23-O (OWN-ONLY dual A/B)  
**Workspace:** `C:\Users\josh\Documents\GitHub\AutoCore`  
**Module / base:** `autoassault.exe` @ `0x400000`  
**Owned VAs only:** `0x004e8590`, `0x00916090`  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / callers / xrefs / callee decompiles). **No** `disassemble_bytes`.  
**Programs open:** `autoassault.exe` only (dual A/B = fidelity vs adversarial reviews).

---

## Verdicts

| Unit | Proposed name | Verdict |
|------|---------------|---------|
| `aa_004e8590` @ `0x004e8590` | `Math_QuatInverseRotateDelta_Inferred` | **accept-with-gaps** |
| `aa_00916090` @ `0x00916090` | `Client_Map_RaySegmentHitDistance_Inferred` | **accept-with-gaps** |

Both A and B reviews agree per VA.

---

## VA1 — `0x004e8590` Math_QuatInverseRotateDelta_Inferred

### Sealed facts

1. **Body:** `004e8590`–`004e87ce` (**575** B). Prolog `sub esp,0x30`; epilogue `add esp,0x30; ret` (`83 C4 30 C3`).
2. **ABI:** MSVC **cdecl**, four stack `float*`, leaf, no ECX this.
3. **Contract:** `out.xyz = R(q_xyzw)^T * (point.xyz − origin.xyz)`; **out.w unwritten**.
4. **Constants:** `ONE=1.0f@0x00a0f2a0`, `TWO=2.0f@0x00a10e74` (`g_flLevelUpUiBase_Inferred` misnomer).
5. **Family:** inverse sibling of `Math_QuatTransformPoint_Inferred` (`0x004e8bf0`); coeffs = transpose of basis extractors `004e8ad0` / `8b60` / `8a40`.
6. **Callers:** sole site `FUN_004b1100` @ `0x004b12ea`.
7. **Name:** role-inferred; reject long Named_CalleeOf_… scaffold alias.

### Gaps

- Product / PDB symbol  
- Sole-caller domain English  
- out.w consumer contract  
- Runtime / bit-exact / diff  

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_004e8590_Math_QuatInverseRotateDelta_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_004e8590_Math_QuatInverseRotateDelta_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004e8590_FUN_004e8590.md` |
| Annotated | `docs/reconstruction/raw/aa_004e8590_FUN_004e8590.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004e8590.cpp` |
| Named | `docs/reconstruction/reconstructed-exact/Math_QuatInverseRotateDelta_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_004e8590_Math_QuatInverseRotateDelta_Inferred.md` |
| Function record (FUN_) | `docs/reconstruction/functions/aa_004e8590_FUN_004e8590.md` |
| Review A | `docs/reconstruction/reviews/A_aa_004e8590_Math_QuatInverseRotateDelta_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004e8590_Math_QuatInverseRotateDelta_Inferred.md` |

---

## VA2 — `0x00916090` Client_Map_RaySegmentHitDistance_Inferred

### Sealed facts

1. **Body:** `00916090`–`00916225` (**405** B). Epilogue `ret 0x18` (`C2 18 00`).
2. **ABI:** MSVC **stdcall**, **6 stack floats** (start XYZ + end XYZ), return **x87 ST0** distance; optional **ESI** = `int* hitOut`.
3. **Map wiring:** `edx = DAT_00d1b644` (client map); cast `ecx = [edx+0xe4a4]` → `FUN_0055e530` (same ctx field as `CVOGMap_CastTerrainHeight`).
4. **Ray packet:** start/end XYZ, filter **`7`**, hit fraction init **1.0**, hit token init **0**.
5. **Hit:** optional `*ESI = token`; `hitPoint = lerp(start,end,t)`; return `|hitPoint − start|` (start copied via `FUN_004e9530`).
6. **Miss:** optional `*ESI = 0`; return **0.0** (`fld g_flZero`).
7. **Callers:** `FUN_009168d0` @ `0x00916e3d`, `FUN_0091b1c0` @ `0x0091b6bd` (camera paths; not VOG_DEBUG-only).
8. **Not** terrain-height Y helper; **not** Havok wheel `TtPhantom::castRay`.

### Gaps

- Product camera method name  
- Filter-7 English  
- Full result-blob layout  
- Null-map edge case  
- Runtime / bit-exact / diff  

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00916090_Client_Map_RaySegmentHitDistance_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00916090_Client_Map_RaySegmentHitDistance_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00916090_FUN_00916090.md` |
| Annotated | `docs/reconstruction/raw/aa_00916090_FUN_00916090.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00916090.cpp` |
| Named | `docs/reconstruction/reconstructed-exact/Client_Map_RaySegmentHitDistance_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_00916090_Client_Map_RaySegmentHitDistance_Inferred.md` |
| Function record (FUN_) | `docs/reconstruction/functions/aa_00916090_FUN_00916090.md` |
| Review A | `docs/reconstruction/reviews/A_aa_00916090_Client_Map_RaySegmentHitDistance_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00916090_Client_Map_RaySegmentHitDistance_Inferred.md` |

---

## AutoCore impact

- **`004e8590`:** port as pure math `Vector3 local = InverseRotate(quat, worldPoint - origin)` using unit-quat transpose (or conjugate-rotate). Do not fold into forward `pos + R*v` helper.
- **`00916090`:** client-only camera/map probe. Server ports that need analogous queries should use map collision segment cast + distance, **not** vehicle wheel phantom casts. Filter value **7** must be preserved for retail parity if collision layers are mirrored.
- No server Launcher / live runtime work performed this pass.

---

## Compliance

| Rule | Status |
|---|---|
| OWN VAs only | **Yes** (`004e8590`, `00916090`) |
| decompile_function + read_memory | **Yes** |
| No disassemble_bytes | **Yes** |
| No Launcher | **Yes** |
| No parent ledger edits | **Yes** |
| raw / annotated / reconstructed-exact / functions / reviews A+B | **Yes** (both VAs) |
