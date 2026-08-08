# Dual A/B report — MEGA-076 OWN-ONLY (`0x0082fa60`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-076**  
**Scope:** VA `0x0082fa60` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_by_address` + callers/xrefs + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-076**.  
**Work item:** Mega residual dual seal — child of dualed **UI_InteractionMenu_PopulateTargetButtons_Inferred** (`0x0082fe20`): **clan Invite/Kick button pack**.  
**Hint:** `UI_InteractionMenu_AddClanInviteOrKick`.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0082fa60` UI_InteractionMenu_AddClanInviteOrKick_Inferred | **accept-with-gaps** — CF/ABI/strings/IDs/slots/callers/clan-table path sealed; product host class + field English + same-clan kick semantics open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): skill-cast / thiscall / convoy-merge / dual-button / ECX=target claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0082fa60` — sealed facts

1. **Body:** `0x0082fa60`–`0x0082fb2b` exclusive (**203 B** / `0xCB`); pad `CC` before convoy pack `0x0082fb30`. Epilogue **`POP ESI; RET`** (`C3`); invite path also `POP EDI` before store/ret.

2. **ABI:** parent-preserved registers — **not** thiscall, **not** stack formals:
   - **EAX** = target object* (entry `MOV ESI,EAX`; parent `MOV EAX,EBP`)
   - **EBX** = menu host* (stores + helper `MOV ECX,EBX`; parent `MOV EBX,ESI`)
   - **`ret 0`**

3. **Semantics:** interaction-menu **clan** button pack:
   - Gate: `(target+0x6B4 < 1) || (local+0x6B4 > 0)` and `DAT_00d1da30 != 0`
   - Local/target clan entries via `FUN_004c22a0(this=DAT_00d1da30, key_lo, key_hi)` with keys from type-secondary `+0x164/+0x168`
   - **Invite To Clan** if local has entry, target has none, `localClan+0x24 >= 2` → store host `+0x548`, id **`0x11173`**
   - **Kick From Clan** if both have entries and `targetClan+0x24 < localClan+0x24` → store host `+0x54C`, id **`0x11174`**
   - Plate: `i_m_int_2d_btn_generic.xml` via helper `FUN_0082f7d0`

4. **Callees:** `FUN_004c22a0` ×2; `FUN_0082f7d0` ×1 (invite or kick arm).

5. **Callers:** **1** function — dualed `FUN_0082fe20` / `UI_InteractionMenu_PopulateTargetButtons_Inferred`.

6. **Xrefs:** **2** UNCONDITIONAL_CALL @ `0x0082fed0`, `0x0082ff14` (both pack orders).

7. **Strings (`read_memory`):**
   - `0x00a72174` → `"Invite To Clan"`
   - `0x00a72164` → `"Kick From Clan"`
   - `0x00a721ac` → `"i_m_int_2d_btn_generic.xml"`

8. **Sibling (not OWN):** convoy pack `0x0082fb30` — ids `0x11171/2`, slots `+0x540/544`, ESI/EDX ABI, crew `+0xCB0` path.

9. **Name:** `UI_InteractionMenu_AddClanInviteOrKick_Inferred` (Ghidra `FUN_0082fa60`). Product class open → `_Inferred`. **Retires** plate-only `UI_int_btn_generic_0082fa60`.

10. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + parent call-site context.

### Gaps

- Product menu-host / clan-table class English.  
- English for `+0x6B4`, membership keys `+0x164/+0x168`, entry rank-like `+0x24`.  
- Whether kick path product-requires same clan (CF has no explicit compare).  
- Dual of `FUN_004c22a0` / `FUN_0082f7d0` (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0082fa60_UI_InteractionMenu_AddClanInviteOrKick_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0082fa60_UI_InteractionMenu_AddClanInviteOrKick_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify append) | `docs/reconstruction/raw/aa_0082fa60_FUN_0082fa60.md` |
| Annotated | `docs/reconstruction/raw/aa_0082fa60_FUN_0082fa60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_InteractionMenu_AddClanInviteOrKick_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0082fa60.cpp` |
| Retired plate | `docs/reconstruction/reconstructed-exact/UI_int_btn_generic_0082fa60.cpp` |
| Function | `docs/reconstruction/functions/aa_0082fa60_FUN_0082fa60.md` |
| Function named | `docs/reconstruction/functions/aa_0082fa60_UI_InteractionMenu_AddClanInviteOrKick_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0082fe20  UI_InteractionMenu_PopulateTargetButtons_Inferred  [dualed WQ9E-D]
  ├─ shell rebuild FUN_0082d2b0
  ├─ resolve TFID @ host+0x578 → target (EBP)
  ├─ pack order via host.vtbl+0x478:
  │     A: Ignore, Friends, Tell, Trade, Clan, Convoy, Name
  │     B: Name, Convoy, Clan, Trade, Tell, Friends, Ignore
  ├─ FUN_0082fa60  UI_InteractionMenu_AddClanInviteOrKick_Inferred  [OWN MEGA-076]
  │     ├─ FUN_004c22a0 ×2  (this = DAT_00d1da30 clan table)  [residual]
  │     └─ FUN_0082f7d0     (create+label generic btn)        [residual]
  └─ FUN_0082fb30  UI_InteractionMenu_AddConvoyInviteOrKick_Inferred  [dualed WQ9D-I]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0082fa60-mega-076-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0082fa60` | Port as **interaction-menu clan Invite/Kick button pack**. Register ABI: **EAX=target**, **EBX=menu host**, **ret 0**. Do **not** assume convoy sibling ESI/EDX contract. |
| Buttons | Invite id **`0x11173`** → host **`+0x548`**; Kick id **`0x11174`** → host **`+0x54C`**; plate `i_m_int_2d_btn_generic.xml`. |
| Lookup | Clan table global **`DAT_00d1da30`**; key pair from object secondary **`+0x164/+0x168`**; rank-like field **`entry+0x24`** (invite needs `>= 2`). |
| Pair with | dualed parent `0082fe20`; dualed convoy sibling `0082fb30`; residual `004c22a0` / `0082f7d0`. |
| Not | skill cast, convoy crew, or thiscall member. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY.md` ← `UI_InteractionMenu_AddClanInviteOrKick_Inferred`
- `COVERAGE_LEDGER.md` / system map skills-abilities or interaction-activation social UI row
- Progress / inventory as required by wave closeout

**Terminal:** **false**
