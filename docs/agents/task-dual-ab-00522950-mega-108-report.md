# Dual A/B report — MEGA-108 OWN-ONLY (`0x00522950`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-108**  
**Scope:** VA `0x00522950` (`aa_00522950`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Role hint:** UI_ItemHover_FormatCraftStatus family helper (partition host `0x0085ce20`).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + `read_memory` + `get_function_by_address` + caller decompile/disasm + `list_strings`. **No** `disassemble_bytes` primary.  
**Image:** `autoassault.exe` base `0x400000`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00522950` Item_PatenteeMatchesCharacterOrEmpty_Inferred | **accept-with-gaps** — CF/ABI/RET4/body/4 callers/patented-by field sealed; vtbl+0x160 product English + PDB name open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): mission misname / host-as-this-VA / craft-discipline field / full-RE merge / ECX=item / case-sensitive claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00522950` — sealed facts

1. **Body:** `0x00522950`–`0x005229b1` inclusive (**98 B** / `0x62`); pad `CC CC` before peer `FUN_005229c0`.
2. **ABI:** **thiscall** — **ECX = Character***; stack **Item***; **AL** bool; **`RET 4`** ×3 exits.
3. **Semantics:** patentee empty-or-name-match gate:
   - null item → false
   - C-string at **`item+0x101`** empty → true
   - else `_stricmp(item+0x101, character MI vtbl+0x160())` → true iff equal
4. **Classification:** worker.
5. **Callers (4 UNCONDITIONAL_CALL):**
   - `FUN_0085ce20` @ `0085cee3` — ItemHover RE/tinker/gadget tooltip (dualed)
   - `FUN_0093d110` @ `0093d507` — Inv Reverse Engineer action
   - `FUN_00847240` @ `0084797c` — item detail / `"Patented By: "` line
   - `FUN_0052e640` @ `0052e699` — RE eligibility float helper
6. **Callees:** `_stricmp` (IAT `0x009c6678`); virtual character **+0x160** only.
7. **Name:** `Item_PatenteeMatchesCharacterOrEmpty_Inferred` (Ghidra `FUN_00522950`). Product map open → `_Inferred`. Scaffold `Named_CalleeOf_Mission_Mission_Object_00522950` **retired**.
8. **Decompile ≡ raw CF**; ABI/offset sealed via `disassemble_function` + `read_memory` + caller framing (`MOV ECX, character; PUSH item`).

### Gaps

- Product/PDB English for character vtbl+0x160.  
- Character MI vbtable type names.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00522950_Item_PatenteeMatchesCharacterOrEmpty_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00522950_Item_PatenteeMatchesCharacterOrEmpty_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00522950_FUN_00522950.md` |
| Annotated | `docs/reconstruction/raw/aa_00522950_FUN_00522950.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Item_PatenteeMatchesCharacterOrEmpty_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00522950.cpp` |
| Function | `docs/reconstruction/functions/aa_00522950_FUN_00522950.md` |
| Function named | `docs/reconstruction/functions/aa_00522950_Item_PatenteeMatchesCharacterOrEmpty_Inferred.md` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Mission_Mission_Object_00522950.cpp` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0085ce20  Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred  [dualed]
  ├─ mode DAT_00d1d900 (RE / gadget / tinker)
  ├─ broken / craft-material 0x1a gates
  ├─ CALL FUN_00522950 @ 0085cee3   [OWN MEGA-108]
  │     fail → "Cannot be Reverse Engineered."
  └─ recipe / skill / stack messages …

FUN_0093d110  Inv_Client_ReverseEngineerItem (residual)
  ├─ cargo / broken / type 0x1a
  ├─ CALL FUN_00522950 @ 0093d507   [OWN MEGA-108]
  │     fail → "Cannot be Reverse Engineered."
  └─ stack / recipe / send craft RE …

FUN_00847240  item detail text (residual)
  ├─ "Patented By: " + item+0x101
  └─ CALL FUN_00522950 @ 0084797c   [OWN MEGA-108]

FUN_0052e640  RE eligibility float helper (residual / MEGA-117 family)
  └─ CALL FUN_00522950 @ 0052e699   [OWN MEGA-108]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00522950-mega-108-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00522950` | Port as **patentee empty-or-name-match** bool. **thiscall** character, stack item, **RET 4**. Empty `item.PatentedBy` → allow; else ordinal-ignore-case name match vs character display name. Do **not** fold broken/recipe/stack into this leaf. |
| Pair with | dualed ItemHover `0085ce20`; residual RE action `0093d110`; residual detail `00847240`; residual eligibility `0052e640`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming ledgers if applicable

**Terminal:** false.
