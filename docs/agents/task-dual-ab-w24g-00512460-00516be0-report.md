# Dual A/B report — W24-G OWN VAs `0x00512460` + `0x00516be0`

**Date:** 2026-07-29  
**Agent:** W24-G (OWN-ONLY dual A/B)  
**Workspace:** `C:\Users\josh\Documents\GitHub\AutoCore`  
**Module / base:** `autoassault.exe` @ `0x400000`  
**Owned VAs only:** `0x00512460`, `0x00516be0`  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / callers / xrefs / callee context). **No** `disassemble_bytes`.  
**Programs open:** `autoassault.exe` only (dual A/B = fidelity vs adversarial reviews).

---

## Verdicts

| Unit | Proposed name | Verdict |
|------|---------------|---------|
| `aa_00512460` @ `0x00512460` | `Object_SetRaceIdOwnerChain_Inferred` | **accept-with-gaps** |
| `aa_00516be0` @ `0x00516be0` | `Object_DoFullInit_Inferred` | **accept-with-gaps** |

Both A and B reviews agree per VA.

---

## VA1 — `0x00512460` Object_SetRaceIdOwnerChain_Inferred

### Sealed facts

1. **Body:** `00512460`–`00512487` (**39** B). Epilogue `ret 4` (`C2 04 00`).
2. **ABI:** MSVC **`__thiscall`**: ECX = object, stack DWORD = race/faction id, void.
3. **Contract:** Write `+0x10` on **self**, then walk owners at `+0xAC` writing the same id (**includes root**).
4. **Leaf:** no callees; no plate comment; no magic float constants.
5. **Companion getter:** `Object_GetRootRaceId` @ `0x00512440` (walk same chain, **return** root `+0x10`).
6. **Callers:** spawn create creature/template vehicle (`FactionDirty`), `VehicleNet_ReconcilePrediction`, reaction/dispatch sites, several `FUN_005*` / `FUN_006*` helpers.
7. **Name:** role-inferred from sibling + spawn domain; reject long `Named_CalleeOf_…` scaffold alias.

### Gaps

- Product field names for `+0xAC` / `+0x10`  
- Full faction/race id table beyond known 0/1/2/−1/−100  
- Cycle policy  
- Runtime / bit-exact / diff  

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00512460_Object_SetRaceIdOwnerChain_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00512460_Object_SetRaceIdOwnerChain_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00512460_FUN_00512460.md` |
| Annotated | `docs/reconstruction/raw/aa_00512460_FUN_00512460.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00512460.cpp` |
| Named | `docs/reconstruction/reconstructed-exact/Object_SetRaceIdOwnerChain_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_00512460_Object_SetRaceIdOwnerChain_Inferred.md` |
| Function record (FUN_) | `docs/reconstruction/functions/aa_00512460_FUN_00512460.md` |
| Review A | `docs/reconstruction/reviews/A_aa_00512460_Object_SetRaceIdOwnerChain_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00512460_Object_SetRaceIdOwnerChain_Inferred.md` |

---

## VA2 — `0x00516be0` Object_DoFullInit_Inferred

### Sealed facts

1. **Body:** `00516be0`–`00516c30` (**80** B). Epilogue `pop esi; ret`.
2. **ABI:** object in **ECX** (thiscall); void; no stack args.
3. **Sequence:** `vtbl+0x1d4` related → if null or `related+0x2ac==0` then `vtbl+0x100` → always `vtbl+0x48` → if clonebase type ∉ {`0x12`,`0x14`} then `FUN_00516a00(1)`.
4. **Skill callee:** `Object_RefreshActiveSkillEffects_Inferred` with **param_2 = 1** (all active skills).
5. **Callers:** `CLoadNode::_initFull` (`FUN_005c78a0`), `FUN_0053e0d0`, `FUN_00581b30`, `FUN_005d5140`; DATA/vtable slots at `009ce300`, `009d3478`, `009d4200`, `009dbcb0`.
6. **Role name:** inferred from `_initFull` + nearby caller string `"DoFullInit Anim"`; keep `_Inferred`.
7. **Not** faction writer; **not** entire load-node stage.

### Gaps

- Product names for virtuals `+0x1d4` / `+0x100` / `+0x48` and flag `+0x2ac`  
- Type 0x12/0x14 English + why skills skipped  
- Full vtable class set  
- Runtime / bit-exact / diff  

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00516be0_Object_DoFullInit_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00516be0_Object_DoFullInit_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00516be0_FUN_00516be0.md` |
| Annotated | `docs/reconstruction/raw/aa_00516be0_FUN_00516be0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00516be0.cpp` |
| Named | `docs/reconstruction/reconstructed-exact/Object_DoFullInit_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_00516be0_Object_DoFullInit_Inferred.md` |
| Function record (FUN_) | `docs/reconstruction/functions/aa_00516be0_FUN_00516be0.md` |
| Review A | `docs/reconstruction/reviews/A_aa_00516be0_Object_DoFullInit_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00516be0_Object_DoFullInit_Inferred.md` |

---

## AutoCore impact

- **`00512460`:** Port already aligned with `SpawnPoint.ApplySpawnFactionOverride` (FactionDirty). Keep **self + owner-chain** write semantics if owner links exist; pair with root read for map-authored faction. Do not write leaf-only when chain present.
- **`00516be0`:** Client load/create full-init epilogue. Server skill reapply ports must use **unrestricted** refresh (param `1`) and **skip** types `0x12`/`0x14` if parity with retail full-init is required. Virtual steps remain class-specific.
- No server Launcher / live runtime work performed this pass.

---

## Compliance

| Rule | Status |
|---|---|
| OWN VAs only | **Yes** (`00512460`, `00516be0`) |
| decompile_function + read_memory | **Yes** |
| No disassemble_bytes | **Yes** |
| No Launcher | **Yes** |
| No parent ledger edits | **Yes** |
| raw / annotated / reconstructed-exact / functions / reviews A+B | **Yes** (both VAs) |
