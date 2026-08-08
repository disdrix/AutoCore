# Dual A/B report — MEGA-035 OWN-ONLY (`0x00513400`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-035**  
**Scope:** VA `0x00513400` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-035**.  
**Work item:** Mega residual dual seal — inventory-transfer gadget attach validator under dualed hover `0x0085ce20`.  
**Hint promoted:** `Item_ValidateGadgetAttach` → **`Item_ValidateGadgetAttach_Inferred`**.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00513400` Item_ValidateGadgetAttach_Inferred | **accept-with-gaps** — CF/ABI/RET4/codes 0..3/type gate/slot+dup sealed; product demangle + type-id English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): tinker-skill-plate / tinker-kit-merge / mutator / swapped-ABI / swapped-codes claims **falsified**; scaffold **retired**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00513400` — sealed facts

1. **Body:** `0x00513400`–`0x005134d4` inclusive (**213 B** / `0xD5`); `CC` pad follows.
2. **ABI:** **ECX** = host **item**; stack **gadget***; **EAX** = status `0..3`; **`RET 4`** ×4 exits.
3. **Semantics:** pure **gadget attach validation**:
   - Type: gadget `…+0x4c4` vs host `item+0xa8 → +0x38`; exceptions type **0x44**+subtype **10**, type **0x46**+subtype **11** → else **return 2**.
   - Capacity: vtbl **+0x8c** used (short) == vtbl **+0x80** cap → **return 1**.
   - Duplicate: loop vtbl **+0x7c**(i) low-16 vs gadget ac-node **+0x34** → **return 3**.
   - Else **return 0** (allow). Leaf (virtuals only).
4. **Return ↔ strings** (dualed parent + apply path):

| Code | String |
|-----:|--------|
| 0 | allow (confirm / cursor) |
| 1 | `"No gadget slots are available."` |
| 2 | `"This is the wrong type of gadget to use on this item."` |
| 3 | `"That gadget is already on the item, no duplicates allowed."` |

5. **Callers (named 3):** `FUN_00514190` @ `0x005141cc`; dualed `FUN_0085ce20` @ `0x0085d0ee` (mode **5** + `CVOGGadget`); `FUN_0085fa20` @ `0x0085fa49`.
6. **Xrefs:** 4 UNCONDITIONAL_CALL (includes unresolved owner @ `0x0085d6bb` outside `0085ce20` body end `0x0085d571`).
7. **Callees:** none (leaf).
8. **Name:** `Item_ValidateGadgetAttach_Inferred` (Ghidra `FUN_00513400`). Product demangle open → `_Inferred`.
9. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.
10. **Retired:** `Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to_00513400` (false tinker plate).

### Gaps

- Product/PDB demangle; vtbl slot English.  
- Type-id **0x44**/**0x46** and subtype **10**/**11** product labels.  
- Dual of apply callers `00514190` / `0085fa20`; orphan xref boundary.  
- Sibling tinker validator `00513c10` is MEGA-036 OWN (not dualled here).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00513400_Item_ValidateGadgetAttach_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00513400_Item_ValidateGadgetAttach_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00513400_FUN_00513400.md` |
| Annotated | `docs/reconstruction/raw/aa_00513400_FUN_00513400.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Item_ValidateGadgetAttach_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00513400.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Skill_You_do_not_possess_the_Tinkering_skill_to_00513400.cpp` |
| Function | `docs/reconstruction/functions/aa_00513400_FUN_00513400.md` |
| Function named | `docs/reconstruction/functions/aa_00513400_Item_ValidateGadgetAttach_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred  [dualed 0x0085ce20]
  mode 5:
    __RTDynamicCast → CVOGGadget
    FUN_00513400  Item_ValidateGadgetAttach_Inferred  [OWN MEGA-035]
      codes → gadget UI strings

FUN_0085fa20  apply-gadget confirm  [residual]
  └─ FUN_00513400  [OWN MEGA-035]
       0 → confirm dialogs
       1/2/3 → error strings

FUN_00514190  inventory type-8 gadget attach helper  [residual]
  └─ FUN_00513400  [OWN MEGA-035]
       0 → vtbl install path

FUN_00513c10  Item_ValidateTinkerKitUse (hint)  [MEGA-036 OWN]
  └─ mode 4 tinker — DO NOT MERGE with this unit
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00513400-mega-035-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00513400` | Port as **gadget attach validator**. **thiscall RET 4**; ECX=host item; stack=gadget. Returns **0 allow / 1 no slots / 2 wrong type / 3 duplicate**. Type exceptions: gadget type **0x44** needs host subtype word **10**; **0x46** needs **11**. |
| Distinct from | tinker-kit validator `00513c10`; RE eligibility helpers; hover presenter `0085ce20` (UI only). |
| Pair with | dualed hover `0085ce20` mode 5; apply confirm `0085fa20`; residual attach helper `00514190`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `Item_ValidateGadgetAttach_Inferred` @ `0x00513400` / `aa_00513400`.
- Verdict: **accept-with-gaps**; Terminal **false**.

---

## Process

- OWN VA only (`0x00513400`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs + assembly context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful `_Inferred` name; twin `FUN_00513400`; Named_CalleeOf tinker scaffold **retired**.  
- Odd behavior preserved: type exceptions 0x44/0x46; capacity re-queried each loop iter; used==cap gate before dup scan.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
