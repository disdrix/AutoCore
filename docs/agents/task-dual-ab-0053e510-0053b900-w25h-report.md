# OWN-ONLY dual agent report — W25-H

| Field | Value |
|---|---|
| Agent | W25-H |
| Workspace | `C:\Users\josh\Documents\GitHub\AutoCore` |
| Module | `autoassault.exe` base `0x400000` |
| Owned VAs | `0x0053e510`, `0x0053b900` |
| Tools | Ghidra `decompile_function` + `get_function_by_address` + `read_memory` + `get_bulk_xrefs` / callers / callees (no `disassemble_bytes`) |
| Launcher | **not** started |
| Parent ledger | **not** edited |
| Date | 2026-07-29 |

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0053e510` Object_SurfaceDistance3D_Inferred | **accept-with-gaps** — **3D center Euclidean − both +0x34 radii; dual world-pos paths ≡ `00404c90` sealed; product name open** |
| `aa_0053b900` CNDHash_scalar_dtor_009cfa7c | **accept-with-gaps** — **MSVC scalar dtor, vtbl[0] of `009cfa7c`, body `0053b920` then flags&1 delete this; product mangled name open** |

---

## VA `0x0053e510` — Object_SurfaceDistance3D_Inferred

| Field | Value |
|---|---|
| Ghidra | `FUN_0053e510` |
| Canonical | `Object_SurfaceDistance3D_Inferred` (**Inferred**) |
| Body | `0x0053e510`–`0x0053e5ad` (158 B / `0x9E`, **ret 4**) |
| Role | Surface-to-surface 3D distance between two objects |
| ABI | `__thiscall` ECX=objA, stack objB; float10/ST0 result |
| Callees | none (inline `fsqrt`) |
| Callers | 11+ CALL sites (AI pursue/fire, interact objectives, …) |
| Live ≡ raw surface | Yes; machine seals radii fsub + ret 4 |
| **Verdict** | **accept-with-gaps** |

### Sealed facts

1. World position resolve **identical dual** to `Object_GetWorldPositionPtr` (`FUN_00404c90`): phys `*(*(obj+8)+0x3c)+0xb0` else entity `*(*(obj+4)+4)+obj+0x84`.
2. Both objects independently resolve; full **XYZ** Euclidean (not XZ-only).
3. Subtract **both** radii at **`obj+0x34`** after `fsqrt`.
4. Not the heavy `CVOGPhysicsUtils::FindDistanceToTarget` util.

### Gaps

1. Product symbol name.
2. Product English for `+0x34` radius field.
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0053e510_Object_SurfaceDistance3D_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0053e510_Object_SurfaceDistance3D_Inferred.md` | **accept-with-gaps** |

### Artifacts

- `docs/reconstruction/raw/aa_0053e510_FUN_0053e510.md`
- `docs/reconstruction/raw/aa_0053e510_FUN_0053e510.annotated.md`
- `docs/reconstruction/reconstructed-exact/Object_SurfaceDistance3D_Inferred.cpp`
- `docs/reconstruction/reconstructed-exact/FUN_0053e510.cpp`
- `docs/reconstruction/reconstructed-exact/Named_CalleeOf_CVOGHBAIFollowVehicle_FireWeapons_0053e510.cpp` (legacy alias updated)
- `docs/reconstruction/functions/aa_0053e510_Object_SurfaceDistance3D_Inferred.md`
- `docs/reconstruction/functions/aa_0053e510_FUN_0053e510.md`
- `docs/reconstruction/reviews/A_aa_0053e510_Object_SurfaceDistance3D_Inferred.md`
- `docs/reconstruction/reviews/B_aa_0053e510_Object_SurfaceDistance3D_Inferred.md`

---

## VA `0x0053b900` — CNDHash_scalar_dtor_009cfa7c

| Field | Value |
|---|---|
| Ghidra | `FUN_0053b900` |
| Canonical | `CNDHash_scalar_dtor_009cfa7c` (**Inferred**) |
| Body | `0x0053b900`–`0x0053b91d` (30 B incl. CC pad, **ret 4**) |
| Role | MSVC scalar-deleting dtor — **vtbl[0]** of `PTR_FUN_009cfa7c` |
| ABI | `__thiscall` ECX=this, stack flags; returns this |
| Callees | `FUN_0053b920` (body), `operator_delete` |
| Callers | DATA only from vtbl `0x009cfa7c` (virtual) |
| Live ≡ raw surface | Yes; machine seals call body + flags&1 + ret 4 |
| **Verdict** | **accept-with-gaps** |

### Sealed facts

1. Always call owning body dtor **`FUN_0053b920`** / `CNDHash_Dtor_009cfa7c` (W24-M).
2. If **`flags & 1`**: `operator_delete(this)` (cdecl +4).
3. Return **this**; **`ret 4`**.
4. Vtbl dword0 at **`0x009cfa7c`** = **`0x0053b900`**.
5. Decompiler “noreturn” on `operator_delete` is residual — epilogue continues.

### Gaps

1. Product mangled name / RTTI.
2. Full `009cfa7c` method map (out of sole ownership).
3. Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0053b900_CNDHash_scalar_dtor_009cfa7c.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0053b900_CNDHash_scalar_dtor_009cfa7c.md` | **accept-with-gaps** |

### Artifacts

- `docs/reconstruction/raw/aa_0053b900_FUN_0053b900.md`
- `docs/reconstruction/raw/aa_0053b900_FUN_0053b900.annotated.md`
- `docs/reconstruction/reconstructed-exact/CNDHash_scalar_dtor_009cfa7c.cpp`
- `docs/reconstruction/reconstructed-exact/FUN_0053b900.cpp`
- `docs/reconstruction/functions/aa_0053b900_CNDHash_scalar_dtor_009cfa7c.md`
- `docs/reconstruction/functions/aa_0053b900_FUN_0053b900.md`
- `docs/reconstruction/reviews/A_aa_0053b900_CNDHash_scalar_dtor_009cfa7c.md`
- `docs/reconstruction/reviews/B_aa_0053b900_CNDHash_scalar_dtor_009cfa7c.md`

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### Surface distance (`0x0053e510`)

- Port as **pure geometry leaf**: no physics query, no zero-fail gate.
- Reuse the same world-position dual as entity pose readers (`phys rb+0xb0` vs `entity+0x84`).
- AI/interact range ports should use **surface** distance (`− rA − rB`), not raw center distance.
- Do not substitute `CVOGPhysicsUtils::FindDistanceToTarget` for this site.

### CNDHash scalar dtor (`0x0053b900`)

- Keep **wrapper separate** from body `0053b920` (FreeBuckets + freelist).
- Virtual delete path: body then optional heap free of the hash object itself.
- Sibling freelist teardown remains at body → `this+0x20` (already sealed W24-M).

---

## Notes

- No Launcher. No parent ledger / `ACTIVE_WORK` / `WORK_QUEUE` / partition map edits.
- Owned VAs only; referenced but did not re-seal `0053b920`, `0059c8a0`, `00404c90`.
- Scratch helper: `docs/reconstruction/tmp/_w25h_append_raw.py`
