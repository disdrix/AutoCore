# Dual A/B report — MEGA-092 OWN-ONLY (`0x00573900`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-092**  
**Scope:** VA `0x00573900` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `create_function` + `decompile_function` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — InventoryGrid vtbl+0x14 secondary-owner setter; parent dualed cargo create `0x004f3a30`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00573900` InventoryGrid_SetSecondaryOwner_Inferred | **accept-with-gaps** — CF/ABI/RET4/10 B body/`+0x58`/vtbl+0x14 sealed; product English + pointee type open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): SetOwner-merge / SetOwnerFlag-merge / item-rebind / direct-CALL / product-string / Terminal claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00573900` — sealed facts

1. **Body:** `0x00573900`–`0x00573909` inclusive (**10 B** / `0x0A`); pad `CC`×6 before scalar dtor `0x00573910`.
2. **ABI:** **ECX** = InventoryGrid* this; stack `secondaryOwner*`; void; **`RET 4`** (`C2 04 00`).
3. **Semantics:** leaf field setter:
   - `*(this + 0x58) = arg`
   - No branches, no callees, no list walk, no flag/`+0x24` stores.
4. **Bytes:** `8b442404894158c20400`
   ```
   MOV EAX, [ESP+4]
   MOV [ECX+0x58], EAX
   RET 4
   ```
5. **Callees:** none.
6. **Callers:** none UNCONDITIONAL_CALL; virtual only.
7. **Xrefs:** **1** DATA — `0x009d33a4` = `PTR_FUN_009d3390 + 0x14`; dword = `0x00573900`.
8. **Ghidra note:** entry was **undefined** code (orphan between prior leaf and `FUN_00573910`); MEGA-092 `create_function` → live decompile.
9. **Parent:** dualed `Vehicle_CreateCargoInventoryFromPageCount` `0x004f3a30` calls `(grid.vtbl+0x14)(char_expr)` after SetOwnerFlag + vfunc+0x18.
10. **Name:** `InventoryGrid_SetSecondaryOwner_Inferred` (Ghidra `FUN_00573900`). Product map open → `_Inferred`.
11. **Decompile ≡ raw CF**; ABI/offset sealed via `disassemble_function` + `read_memory`.

### Gaps

- Product / PDB symbol for method and field `+0x58`.  
- Exact pointee type (character vs abstract owner).  
- Exhaustive virtual call-site list.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00573900_InventoryGrid_SetSecondaryOwner_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00573900_InventoryGrid_SetSecondaryOwner_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00573900_FUN_00573900.md` |
| Annotated | `docs/reconstruction/raw/aa_00573900_FUN_00573900.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/InventoryGrid_SetSecondaryOwner_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00573900.cpp` |
| Function | `docs/reconstruction/functions/aa_00573900_FUN_00573900.md` |
| Function named | `docs/reconstruction/functions/aa_00573900_InventoryGrid_SetSecondaryOwner_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Vehicle_CreateCargoInventoryFromPageCount  0x004f3a30  [dualed]
  ├─ destroy old grid via vtbl[0](1)  FUN_00573910  [dualed]
  ├─ InventoryGrid_ctor_Inferred  0x00572650  [dualed]
  ├─ InventoryGrid_SetOwnerFlag_Inferred  0x00570600  → grid+0x4
  ├─ (grid.vtbl+0x18)  FUN_005718a0  SetOwner  → grid+0x24 + item rebind  [dualed]
  └─ (grid.vtbl+0x14)  FUN_00573900  SetSecondaryOwner  → grid+0x58  [OWN MEGA-092]

PTR_FUN_009d3390  InventoryGrid vtbl
  +0x00  0x00573910  ScalarDeletingDtor
  +0x14  0x00573900  SetSecondaryOwner  [OWN]
  +0x18  0x005718a0  SetOwner
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00573900-mega-092-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00573900` | Port as **InventoryGrid secondary-owner leaf setter**: `*(grid+0x58)=ptr`. **thiscall RET 4**. Distinct from SetOwner (`+0x24` + rebind) and SetOwnerFlag (`+0x4`). |
| Cargo create | After SetOwnerFlag + SetOwner, call this with the vehicle character/owner-char expression (parent dual). Skipping diverges from client. |
| Pair with | dualed cargo create `004f3a30`; dualed SetOwner `005718a0`; dualed SetOwnerFlag `00570600`; dualed scalar dtor `00573910`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / progress / naming as applicable  
- **not** modified by MEGA-092
