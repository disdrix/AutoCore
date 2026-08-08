# Dual A/B report — R10-034 OWN-ONLY (`0x00521970`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-034**  
**Scope:** VA `0x00521970` (`aa_00521970`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Role hint:** skills-abilities character display residual under dualed parent leaf `0x0051f940` (`LookupClassDisplayName_Inferred`).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + callers/xrefs/`get_bulk_xrefs` + `read_memory` + `search_byte_patterns` + callee decompiles. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r10_residual_partition_map.md` (R10-034).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00521970` Character_FormatClassAndLevelDisplay_Inferred | **accept-with-gaps** — CF/ABI/RET4/class×level sprintf + product strings + 2-arg leaf call sealed; callers + product method English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): decompiler 3-arg lookup / char\* return / always-level / invent-callers claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00521970` — sealed facts

1. **Body:** `0x00521970`–`0x00521a62` exclusive (**242 B** / `0xF2`); `CC` pad follows.
2. **ABI:** **ECX** = character-like `this`; stack **`char* out`**; **void**; **`RET 4`** both exits.
3. **Semantics:**
   - `tls = FUN_007a69d0()` (kept for `"Level"` localization).
   - `level = this` nested-obj **vcall `+0x27c`** (same slot as mission `[$level]`).
   - Nested blob `*( *( *( *(this+4)+4 ) + this + 0xac ) + 0x3c )`.
   - `classId = *(u8*)(blob+0x531)`, `raceId = *(u8*)(blob+0x532)`.
   - `className = ring( FUN_0051f940(classId, raceId) )` — **cdecl 2-arg** (`add esp,8`).
   - If `level >= 0`: re-fetch level; `levelWord = ring_tls("Level")`; `sprintf(out, "%s, %s %i", className, levelWord, level)`.
   - Else: `sprintf(out, "%s", className)`.
4. **Product strings (`read_memory`):**
   - `"Level"` @ `0x00a41404`
   - `"%s, %s %i"` @ `0x009cf10c`
   - `"%s"` @ `0x00a2c2a4`
5. **Callees:** `FUN_0051f940` (dualed leaf), `FUN_007a69d0`, `FUN_007a6de0`, IAT `sprintf`, vcall `+0x27c`.
6. **Callers:** live Ghidra **0** code xrefs; absolute pattern `70 19 52 00` **no hits** (gap).
7. **Name:** `Character_FormatClassAndLevelDisplay_Inferred` (Ghidra `FUN_00521970`). Role **Inferred** from formats + sibling class/race display family + dualed class leaf. **No** product plate string in body.
8. **Decompiler ≠ assembly** on 3-arg `FUN_0051f940` phantom and bare TLS/`007a6de0` ownership — clean uses assembly authority.

### Gaps

- Direct callers / out-buffer producers.  
- Product/PDB method English.  
- Deep Character / intermediate C++ types.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00521970_Character_FormatClassAndLevelDisplay_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00521970_Character_FormatClassAndLevelDisplay_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00521970_FUN_00521970.md` |
| Annotated | `docs/reconstruction/raw/aa_00521970_FUN_00521970.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_FormatClassAndLevelDisplay_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00521970.cpp` |
| Function | `docs/reconstruction/functions/aa_00521970_FUN_00521970.md` |
| Function named | `docs/reconstruction/functions/aa_00521970_Character_FormatClassAndLevelDisplay_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Character_FormatClassAndLevelDisplay_Inferred  [0x00521970]  OWN R10-034
  ├─ LookupClassDisplayName_Inferred           [0x0051f940 dualed WQ9G-E]
  ├─ FUN_007a69d0 / FUN_007a6de0               TLS ring
  ├─ sprintf (IAT)
  └─ vcall +0x27c                              level (mission [$level] slot)

Siblings (not owned):
  Character_GetClassDisplayName_Inferred       [0x00521900]  ring char* class only
  Character_GetRaceDisplayName_Inferred        [0x00521800]  ring char* race only
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00521970-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00521970` | Port as **`Character::FormatClassAndLevelDisplay`** (Inferred). **thiscall RET 4** with `char* out`. Format `"Class, Level N"` when level ≥ 0 else class-only. Class English via dualed `LookupClassDisplayName_Inferred(class, race)`. **Do not** trust raw Ghidra 3-arg `FUN_0051f940` or void/plain-ret decompiler display. |
| Pair with | dualed leaf `0051f940`; siblings `00521900` / `00521800`; level vcall consumers of `+0x27c`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent may lockstep:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md` + rename-history
- `systems/*` skills-abilities residual tables
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00521970`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + string VAs. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) filed.
- Scaffold raw body preserved; re-verify **appended** only.
