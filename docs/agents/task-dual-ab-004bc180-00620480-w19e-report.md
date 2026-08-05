# Dual A/B report — W19-E OWN-ONLY (`0x004bc180`, `0x00620480`)

**Date:** 2026-07-29  
**Agent:** W19-E OWN-ONLY  
**Scope:** OWN ONLY VAs `0x004bc180`, `0x00620480`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_004bc180` Object_RegisterListed | **accept-with-gaps** — **thiscall+ret4, COID/mode/list/handle CF sealed; `"VOG_DEBUG_STOP"` log-only; product type English open** |
| `aa_00620480` Skill_SpawnTemplateAndStartHB | **accept-with-gaps** — **ret0x18 dual-spawn+HB pipeline sealed; DATA `@0x009d1598`; floats 5.0/100.0; product handler English open** |

---

## `aa_004bc180` — Object_RegisterListed

### Sealed facts

1. **ABI:** `int32_t __thiscall Object_RegisterListed(ListingContext* this, Object* obj)` — **ECX=manager**, stack object*, epilogue **`ret 4`**. Body `0x004bc180`–`0x004bc41c`.

2. **Return surface:** `0` on success **or** already-listed; throws `0x80070057` (invalid COID / mode) or `0x8007000E` (OOM) or secondary `FUN_004bc680` HR `< 0`.

3. **COID:** object `+0x160/+0x164` (lo/hi). Invalid → log **`"VOG_DEBUG_STOP"`** (`@0x00a15844`) + throw. **Not** a debug-stop API.

4. **Mode gate:** object `+0x168` selects required manager flag `+0xd` vs `+0xc`.

5. **Already listed:** `FUN_004e77d0` → log **`"object %I64d (%d) is already listed"`** (`@0x009cb4a8`) → return `0`.

6. **Bucket key:** `vtbl+0x208` nonzero → imm **`0x30`**; else type at `*(obj+0xa8)+0x38`. Hash at manager `+0x18`; miss → `new(0x2c)` + `FUN_004bcb40` + `FUN_004bd1d0`.

7. **Handles via `FUN_004bc680`:** primary `+0xdc`; optional `+0xd0` (type `0x12` / special `0xe`), `+0xd4` (`FUN_005130e0(1)`), `+0xd8` (flag bit5 at `+0x17c`). Conditional `CVOGReaction_FailMissionNotify`.

8. **Name:** structural **`Object_RegisterListed`**. Parent-seed **`Mission_VOG_DEBUG_STOP` incomplete**.

9. **Live decompile ≡ 2026-07-23 raw** (append-only live section recorded).

### Gaps

1. Product/PDB symbol.  
2. English for types `0x12` / `0xe` / `0x14`.  
3. Full `FUN_004bc680` handle object contract.  
4. Runtime / bit-exact / differential — open.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004bc180_Object_RegisterListed.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004bc180_Object_RegisterListed.md` |
| Function record | `docs/reconstruction/functions/aa_004bc180_Object_RegisterListed.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_RegisterListed.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_004bc180.cpp` |
| Raw | `docs/reconstruction/raw/aa_004bc180_FUN_004bc180.md` |
| Annotated | `docs/reconstruction/raw/aa_004bc180_FUN_004bc180.annotated.md` |

---

## `aa_00620480` — Skill_SpawnTemplateAndStartHB

### Sealed facts

1. **ABI:** six stack dwords, epilogue **`ret 0x18`**. Returns **`0`** invalid template, **`1`** success / gate no-op. Body `0x00620480`–`0x00620a20`.

2. **Install:** DATA dword **`0x009d1598` = `0x00620480`** (no direct CALL xrefs).

3. **Gate:** `ctx+0x7e && source && source.vtbl+0x214()` related object.

4. **Dual spawn:**
   - `skillDef+0x22 == 0` → `new(0x690)` + `FUN_004c9aa0(1)` + vcall init(template `@+0x14c`, ctx, 1)
   - else → `FUN_0058bf50`; null → log **`"Skill %d had invalid template %d."`** (`@0x009e1c6c`) + return `0`

5. **Terrain:** `CVOGMap_CastTerrainHeight` with **`z + DAT_00aaa7ac`** where `DAT_00aaa7ac` = **100.0f**. `DAT_00aaa688` = **5.0f**.

6. **Skills:** `Skill_EnsureLoadedInTree` for nonzero `+0x154/+0x158/+0x15c`.

7. **HB:** `new(0x6c0)` + `FUN_006202f0`; owner null → dtor; else `CVOGHBList_Enqueue(ctx+0xe4ec)` + `CVOGHBBase_Start`.

8. **Effects:** if `skillDef+0x150` → ResolveTargets + `Skill_ApplyEffectsOnTarget_Inferred`.

9. **Name:** structural **`Skill_SpawnTemplateAndStartHB`**. String-seed invalid-template names **incomplete**.

10. **Live CF ≡ raw** (cosmetic type/name surface only).

### Gaps

1. Product/PDB / table-slot English.  
2. Exact `param_4` / `param_6` product roles.  
3. Dual `FUN_00404c90` arm residual (same callee both sides in decomp).  
4. Runtime / bit-exact / differential — open.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00620480_Skill_SpawnTemplateAndStartHB.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00620480_Skill_SpawnTemplateAndStartHB.md` |
| Function record | `docs/reconstruction/functions/aa_00620480_Skill_SpawnTemplateAndStartHB.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_SpawnTemplateAndStartHB.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00620480.cpp` |
| Raw | `docs/reconstruction/raw/aa_00620480_FUN_00620480.md` |
| Annotated | `docs/reconstruction/raw/aa_00620480_FUN_00620480.annotated.md` |

---

## Absolute roots

`C:\Users\josh\Documents\GitHub\AutoCore\` + paths above.

This report: `docs/agents/task-dual-ab-004bc180-00620480-w19e-report.md`

---

## AutoCore impact

- **Listing register (`0x004bc180`):** implement soft-duplicate + conditional mission notify; do **not** map the unit to a debug-stop. Multi-domain callers (spawn, grab, teleport, markers) share one listing service.
- **Skill spawn HB (`0x00620480`):** wire as table-dispatched skill spawn with terrain Z+100 and HB enqueue; invalid template is the only soft `0` return observed in-body.
