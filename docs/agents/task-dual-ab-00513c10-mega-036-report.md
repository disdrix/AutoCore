# Dual A/B report — MEGA-036 OWN-ONLY (`0x00513c10`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-036**  
**Scope:** VA `0x00513c10` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + `get_assembly_context` + `read_memory` + `batch_decompile` (callees/callers). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA-036 residual dual seal — inventory-transfer **Item_ValidateTinkerKitUse** (hint).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00513c10` Item_ValidateTinkerKitUse_Inferred | **accept-with-gaps** — CF/ABI/RET8/status 0..4/caller string map sealed; product PDB + field lexicon open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): thiscall-deny / arg-swap / bool-only / gadget-merge / mutate-or-packet / success=0 claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00513c10` — sealed facts

1. **Body:** `0x00513c10`–`0x00513cde` inclusive (**207 B** / `0xCF`); next dualed peer `Item_HasModSlotConfig_Inferred` @ `0x00513cf0`.
2. **ABI:** **ECX** = target item; stack `character*`, `CVOGTinkeringKit* kit`; **EAX** = status 0..4; **`RET 8`** on every exit.
3. **Semantics:** Tinkering Kit apply-eligibility validator (read-only):
   - null kit / category fail (`FUN_00513bc0`) / null character → **3**
   - Broken bit19 @ `item+0x17c` → **0**
   - `vtbl[+0x8c]` opened count ≥ def max `@+0x4b4` → **0**
   - skill tier (`FUN_00521eb0` on character) < need (`cur+1`) and `character+0x6b4 < 1` → **1**
   - kit level `@kit+0xb0` ≥ need → **4** else **2**
4. **Callees:** `FUN_00513bc0`, item vtbl `+0x8c` (×2), `FUN_00521eb0`.
5. **Callers / xrefs:** **3** `UNCONDITIONAL_CALL`:
   - `FUN_0085ce20` @ `0x0085d2bb` (dualed mode-4 tooltip)
   - gap body @ `0x0085d767` (allow iff code==4)
   - `FUN_0085f660` @ `0x0085f675` (apply / success-chance dialog)
6. **Name:** `Item_ValidateTinkerKitUse_Inferred` (Ghidra `FUN_00513c10`). Scaffold `Named_CalleeOf_Skill_…_00513c10` **retired**.
7. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.
8. **System:** `inventory-transfer`.

### Gaps

- Product/PDB English name.  
- Lexicon for `character+0x6b4`, vtbl `+0x8c`, def `+0x4b4`.  
- Unowned callees `FUN_00513bc0`, `FUN_00521eb0` full dual.  
- Orphan gate caller @ `0x0085d767`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00513c10_Item_ValidateTinkerKitUse_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00513c10_Item_ValidateTinkerKitUse_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00513c10_FUN_00513c10.md` |
| Annotated | `docs/reconstruction/raw/aa_00513c10_FUN_00513c10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Item_ValidateTinkerKitUse_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00513c10.cpp` |
| Scaffold retired | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to_00513c10.cpp` |
| Function | `docs/reconstruction/functions/aa_00513c10_FUN_00513c10.md` |
| Function named | `docs/reconstruction/functions/aa_00513c10_Item_ValidateTinkerKitUse_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred  [0x0085ce20]  [dualed]
  mode DAT_00d1d900 == 4:
    RTTI CVOGTinkeringKit (DAT_00d1d938/d93c)
    └─ FUN_00513c10  Item_ValidateTinkerKitUse_Inferred  [OWN MEGA-036]
         codes → tooltip strings (slots/skill/primitive/category)
         code 4 → ok chrome

FUN_0085f660  tinker apply dialog
  └─ FUN_00513c10  [OWN]
       code 4 → success-chance sprintf + confirm
       else → same status strings via FUN_007fdfb0

FUN_00513bc0  category kit↔item match     [residual leaf]
FUN_00521eb0  character skill tier map    [residual leaf]
FUN_00513400  gadget apply codes          [sibling; not this VA]
```

### Status → string (dualed callers)

| Code | String / path |
|-----:|---|
| 0 | `"The object has no available slots to open."` (Broken message is caller-side override) |
| 1 | `"You do not possess the Tinkering skill to work on this object."` |
| 2 | `"This Tinkering Kit is too primitive to use on this object."` |
| 3 | `"This Tinkering Kit can only be used on %s."` (+ category label from `kit+0xb4`) |
| 4 | OK / success-chance path |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00513c10-mega-036-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00513c10` | Port as **Tinkering Kit use validator**. **thiscall RET 8**: ECX=item, stack character + kit. Return **enum 0..4** — do not collapse to bool. Success is **4**, not 0/1. |
| Broken | Body returns 0 on Broken; UI must still special-case Broken string (as retail `0085ce20` does after code≠4). |
| Pair with | dualed tooltip `0085ce20`; residual apply dialog `0085f660`; residual category `00513bc0`; residual skill-tier `00521eb0`; gadget sibling `00513400` (keep distinct). |
| Do not | Treat as skill-only helper (scaffold name was misleading); do not merge with gadget validator. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history (`Named_CalleeOf_…` → `Item_ValidateTinkerKitUse_Inferred`)  
- `systems/*` residual tables (inventory-transfer / tinkering)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00513c10`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + assembly context + dualed caller string map. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful `_Inferred` name; leave-FUN twin kept; Named_CalleeOf scaffold retired to redirect stub.  
- Odd behavior preserved: Broken shares code 0 with “no slots”; skill bypass via `character+0x6b4`; success code **4**.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
