# Dual A/B report — `aa_0053d970` Object_SetPhysBodyTypeIfNotReady_Inferred

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x0053d970`. Dual A/B + artifacts. Seal soft-ready phys body-type request (type-6 cleanup helper).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER.  
**Ghidra:** `decompile_function`, `force_decompile`, `read_memory`, `analyze_function_complete`, `get_assembly_context`. No `disassemble_bytes`.

**Programs open:** `autoassault.exe` only (dual A/B = fidelity vs adversarial reviews).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0053d970` Object_SetPhysBodyTypeIfNotReady_Inferred | **accept-with-gaps** — machine CF + flag→{1,6} + soft gate + tail sealed |

Path A (fidelity): **accept-with-gaps**  
Path B (adversarial): **accept-with-gaps** — rejects decompiler-only / null-this / “always type 6”

---

## Sealed facts

1. **ABI:** MSVC **`__thiscall`**. `ECX` = entity/object. One stack **`flag`**. Epilogue **`RET 4`**. Body **`0x0053d970`–`0x0053d9ac`**.

2. **Phys load:** `phys = *(entity+0x08)`. Null → no-op.

3. **Soft-ready gate (not fully ready):** `(phys+0x40 == 0) || (phys+0x08 == 0)`. Identical dual field to network soft path (`FUN_0053eec0`). Fully ready → **no-op** (no mode switch).

4. **Flag → target type map (machine):**
   - `flag == 0` → request type **1**
   - `flag != 0` → request type **6**  
   Callers push **0/1**, not the type id.

5. **Tail:** rewrite stack slot to target type; **`JMP FUN_005d4440`** with **`ECX = phys`** (not entity).

6. **Decompiler gap:** live decompile shows bare `FUN_005d4440()` and omits stack flag / `RET 4` — **insufficient for ports**. Machine authoritative.

7. **Vehicle “type-6 cleanup” pattern:** `Vehicle_setDrivingInputs` probes body type == **6**, then calls with **flag 0** → soft request type **1** (leave type-6). Name is caller-role, not “always set 6”.

8. **Fan-in:** **22** static xrefs — vehicles, creatures, spawn, camera, respawn, etc. (not vehicle-only).

9. **Name:** `Object_SetPhysBodyTypeIfNotReady_Inferred` — product/PDB open; `_Inferred` retained.

---

## Gaps

1. Product English for body types **1** / **6** / sibling **7** (in leave-FUN).  
2. Full dual A/B of `FUN_005d4440` @ `0x005d4440`.  
3. Whether any caller pushes flag outside {0,1} (machine treats all ≠0 as type 6).  
4. Runtime / CE / bit-exact not run.  
5. Precise English of `phys+0x40` (ready vs type-7 sticky) — CF sealed, label open.

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0053d970_Object_SetPhysBodyTypeIfNotReady_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0053d970_Object_SetPhysBodyTypeIfNotReady_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_0053d970_Object_SetPhysBodyTypeIfNotReady_Inferred.md` |
| Function record (alias) | `docs/reconstruction/functions/aa_0053d970_FUN_0053d970.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0053d970.cpp` |
| Raw (authoritative body + re-verify append) | `docs/reconstruction/raw/aa_0053d970_FUN_0053d970.md` |
| Annotated | `docs/reconstruction/raw/aa_0053d970_FUN_0053d970.annotated.md` |
| Scratch | `tmp/a_0053d970.md` |
| This report | `docs/agents/task-dual-ab-0053d970-object-setphysbodytypeifnotready-report.md` |

Related (not owned): `FUN_005d4440`, `Vehicle_setDrivingInputs` dual, `fn_0053eec0_networkApply`.

---

## AutoCore impact

- Port soft mode requests as **entity thiscall + boolean flag**, mapping **0→type1 / 1→type6**, only when the phys shell is soft/not-ready.
- Vehicle ghost type-6 branch must pass **entity this** and **flag 0** (not null this, not type id 6 on the stack).
- Do not call body switcher when phys is null or fully ready — retail intentionally skips.
- Keep full body/AI swap logic in the `FUN_005d4440` port; this unit is only the soft gate + 1/6 map + tail.
