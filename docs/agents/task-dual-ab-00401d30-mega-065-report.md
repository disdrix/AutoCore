# Dual A/B report — MEGA-065 OWN-ONLY (`0x00401d30`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-065**  
**Scope:** VA `0x00401d30` (`aa_00401d30`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — Mission null dialog nested residual → **generic StringFlag construct-from-parts**.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00401d30` BasicStringFlag_CtorFromStringAndChar_Inferred | **accept-with-gaps** — CF/ABI/RET0xC/layout sealed; product flag + map English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): mission-dialog / plain-string-only / param3-as-string / thiscall-ECX-aggregate / cdecl / merge-with-00402040 claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00401d30` — sealed facts

1. **Body:** `0x00401d30`–`0x00401d83` inclusive (**84 B** / `0x54`); pad `CC` before `FUN_00401d90` @ `0x00401d90`.
2. **ABI:** stack **dest***, **src string***, **char***; **EAX** = dest*; **`RET 0xC`**.
3. **Semantics:** construct-from-parts for `{ basic_string<char> @+0 (0x1c); uint8_t flag @+0x1c }`:
   - SEH frame (`LAB_009bbfb9` / FS:[0]).
   - IAT `[0x009c62ec]` → `basic_string::basic_string(const basic_string&)` (demangle `...QAE@ABV01@@Z`).
   - `dest.flag = *flag_src` at `+0x1c` (**byte** load; decompiler string typing corrected).
4. **Callees:** string copy-ctor only.
5. **Callers:** **1** UNCONDITIONAL_CALL:
   - `FUN_00980160` @ `0x009801af` — after substr; then `MOV EDI,EAX; CALL 00402040`.
6. **Xrefs:** 1 UNCONDITIONAL_CALL (same).
7. **Name:** `BasicStringFlag_CtorFromStringAndChar_Inferred` (Ghidra `FUN_00401d30`). Product flag English open → `_Inferred`.
8. **Retired scaffold:** `Named_CalleeOf_Named_CalleeOf_Mission_Attempting_to_open_null_d_00401d30`.
9. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product English for flag byte.  
- Parent map/node value_type product name (`FUN_00401c50` / `FUN_00401fe0`).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00401d30_BasicStringFlag_CtorFromStringAndChar_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00401d30_BasicStringFlag_CtorFromStringAndChar_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00401d30_FUN_00401d30.md` |
| Annotated | `docs/reconstruction/raw/aa_00401d30_FUN_00401d30.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/BasicStringFlag_CtorFromStringAndChar_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00401d30.cpp` |
| Function | `docs/reconstruction/functions/aa_00401d30_FUN_00401d30.md` |
| Function named | `docs/reconstruction/functions/aa_00401d30_BasicStringFlag_CtorFromStringAndChar_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00980160  (mission-chain residual parent; string parse with ")")
  ├─ basic_string::find / substr
  ├─ FUN_00401d30  BasicStringFlag_CtorFromStringAndChar_Inferred  [OWN MEGA-065]
  ├─ FUN_00402040  BasicStringFlag_CopyCtor_EdiSrc_Inferred  [dualed MEGA-080]
  └─ FUN_00401c50  map insert/find peer  [residual]

FUN_00401fe0  tree/map node ctor  [residual]
  └─ FUN_00402040  embeds StringFlag at node+0xc  [dualed MEGA-080]
```

Partition hint "Mission null dialog nested" explains **why** this VA was queued (depth under mission null-dialog chain), not the unit's semantics.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00401d30-mega-065-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00401d30` | Port as **construct of `{string, byte}` aggregate from string + char***. Native sites use **3 stack args**, **RET 0xC**. Managed code can use ordinary ctor. Do **not** implement as mission-dialog open. Keep distinct from copy twin `00402040` (EDI src, RET 4) and string dtor `004020f0`. |
| Pair with | dualed copy twin `00402040`; residual `00401fe0` (node ctor); residual `004020f0` (string dtor); residual `00980160` (parse/insert parent); residual `00401c50` (map insert/find). |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (shared string+flag aggregate — not mission-dialog UI)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00401d30`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful name; machine ABI corrections (3 stack args RET 0xC; param_3 = char* byte).  
- Odd behavior preserved: decompiler string-types param_3; assembly is byte store at +0x1c.  
- `_Inferred` where English unproven; scaffold Named_CalleeOf retired. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
