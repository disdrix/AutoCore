# Dual A/B report — WQ8R-H OWN `aa_0085ce20` + `aa_008e5ce0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual WQ8R-H  
**Scope:** VAs `0x0085ce20`, `0x008e5ce0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger / VERIFICATION_MATRIX / NAMING_REGISTRY.  
**Ghidra:** `batch_decompile` / `decompile_function` + `force_decompile` + `read_memory` + `analyze_function_complete` + `get_function_by_address` + `get_assembly_context` on xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** WQ-008 residual (`reviews/WAVE_2026-08-04_wq008_residual_partition_map.md`).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0085ce20` Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred | **accept-with-gaps** — EAX/EBX/cdecl, modes 0/4/5, product strings+RTTI, widget vtbl text/place sealed; helper English + runtime open |
| `aa_008e5ce0` Client_UI_CraftHost_BindObjectByTfid_Inferred | **accept-with-gaps** — stdcall host+TFID, invalid clear, FindItem/broken/equip→bind sealed; host class PDB + `FUN_00522000` open |

---

## VA `0x0085ce20` — sealed facts

1. **Body:** `0x0085ce20`–`0x0085d571` (**1873 B** / `0x751`).
2. **ABI:** **EAX→ESI** = item object\*, **EBX** = UI status widget\*, stack **`char strictMode`** (cdecl; callers `ADD ESP,4`). Decompiler `in_EAX`/`unaff_EBX` incomplete — **bytes + callers win**. Not thiscall.
3. **Semantics (craft-mode item status tooltip):**
   - Require `DAT_00d1b6d8` (local char), `DAT_00d1b9a8` (cursor host), non-null item/widget.
   - Branch on **`DAT_00d1d900`** (sealed abs of **`client+0x30c0`** multi-mode):
     - **0 — Reverse Engineer:** skill float `FUN_0052e640`; gates broken (`obj+0x17c>>19`, when `strictMode==0`), craft-mat type `def+0x38==0x1a`, `FUN_00522950`, recipe count `FUN_00599dd0`, stack (`vtbl+0x25c` + `FUN_00513e70` when `strictMode==0`), skill≤0 → “Requires At Least %d Reverse Engineering”; else optional cursor chrome if `widget+0xce`.
     - **5 — Gadget:** `InventoryGrid_FindItemByCoid(DAT_00d1d940,DAT_00d1d944)` + `__RTDynamicCast`→`CVOGGadget`; `FUN_00513400` codes → no slots / wrong type / duplicate / generic refuse; code 0 → ok chrome.
     - **4 — Tinkering Kit:** find `DAT_00d1d938/93c` + RTTI `CVOGTinkeringKit`; `FUN_00513c10` codes 0–3 messages (+ category labels Power Plants/Weapons/Vehicles/Wheelsets/Armor/Other); code 4 ok; broken hard-refuse string.
     - **else:** `widget vtbl+0x308(NULL)` + cursor `FUN_007fd420`; return **without** place epilogue.
   - Common epilogue: `vtbl+0x308(msg)`; cursor host `vtbl+0x120`; widget `vtbl+0x314(x,y)`.
4. **Classification:** worker / UI presenter — **no** C2S inventory mutation.
5. **Callers (6 xrefs):** `FUN_0085d900` push **0**; five item-widget sites push **1** (`008b59b2`, `008b90ad`, `008c218f`, `009059a4`, `00909b70`).
6. **Name:** `Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred` (Ghidra `FUN_0085ce20`). **Reject** scaffold `Skill_You_do_not_possess_the_Tinkering_skill_to_work_o*`.
7. **Decompile ≡ force** for CF/strings/RTTI; **bytes win** on EAX/EBX ABI.  
   Prologue hex (64 B): `558bec83e4f881ec780100008b15d8b6d100565733ff3bd78bf00f842c070000393da8b9d1000f84200700003bf70f84180700003bdf0f8410070000a100d9d1`

### Gaps

- PDB English for widget class / vtbl slot names.  
- Full contracts of unowned apply helpers (`FUN_00513400`, `FUN_00513c10`, …).  
- Runtime hover vs refresh `strictMode` UX.  
- Bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0085ce20_Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0085ce20_Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0085ce20_FUN_0085ce20.md` |
| Annotated | `docs/reconstruction/raw/aa_0085ce20_FUN_0085ce20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0085ce20.cpp` |
| Function | `docs/reconstruction/functions/aa_0085ce20_FUN_0085ce20.md` |
| Function named | `docs/reconstruction/functions/aa_0085ce20_Client_UI_ItemHover_ApplyRETinkerGadgetTooltip_Inferred.md` |

---

## VA `0x008e5ce0` — sealed facts

1. **Body:** `0x008e5ce0`–`0x008e5df3` (**275 B** / `0x113`; pad `CC`).
2. **ABI:** **stdcall** `RET 0x0C` — `(void* host, uint32_t coidLo, uint32_t coidHi)`. Prologue maps **EDI**=lo, **ESI**=hi. Host becomes **ECX** for thiscall `FUN_008e5990`. Decompiler “unused param_1” is wrong — **bytes win**.
3. **Semantics (TFID → craft host bind):**
   - If `(coidLo & coidHi) == 0xFFFFFFFF` → `FUN_008e5990(host, NULL)`; return.
   - If no local character → return.
   - Prefer `InventoryGrid_FindItemByCoid` when vehicle cargo and/or locker+`DAT_00d1b644+0xf5`.
   - If null or **Broken** (`obj+0x17c>>19`) → scan equip TFID pairs at `char+0x5a0` (count `FUN_00522000`); match → `CVOGReaction_ResolveObjectTarget(1, lo, hi)`.
   - If object non-null → `FUN_008e5990(host, obj)` (stores `host+0x7cc`, rebuilds name/recipe chrome — unowned body).
4. **Classification:** worker — selection bind only; no network.
5. **Callers (2 xrefs):** `FUN_008e5e00` @ `008e6345` (TFID change after list rebuild); `008e82ef` (sibling panel path). Both push TFID from subwidget **vtbl+0x44c**.
6. **Name:** `Client_UI_CraftHost_BindObjectByTfid_Inferred` (Ghidra `FUN_008e5ce0`). **Reject** scaffold `Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_008e5ce0`.
7. **Decompile ≡ force** for CF; **bytes win** on stdcall + host thiscall setup.  
   Prologue hex (64 B): `568b742410578b7c24108bc723c683f8ff75108b4c240c6a00e892fcffff5f5ec20c008b0dd8b6d10085c90f84de0000008b895002000033c085c974238b89b0`

### Gaps

- Product RTTI/class name of craft host.  
- `FUN_00522000` full ABI/contract (unowned).  
- Broken object after Resolve may still bind (open edge).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_008e5ce0_Client_UI_CraftHost_BindObjectByTfid_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_008e5ce0_Client_UI_CraftHost_BindObjectByTfid_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_008e5ce0_FUN_008e5ce0.md` |
| Annotated | `docs/reconstruction/raw/aa_008e5ce0_FUN_008e5ce0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_UI_CraftHost_BindObjectByTfid_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_008e5ce0.cpp` |
| Function | `docs/reconstruction/functions/aa_008e5ce0_FUN_008e5ce0.md` |
| Function named | `docs/reconstruction/functions/aa_008e5ce0_Client_UI_CraftHost_BindObjectByTfid_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0085ce20` | Port as **register + cdecl** item hover status: **EAX=item**, **EBX=widget**, stack **strictMode**. Branch on client craft multi-mode **0/4/5** (same field as pending skill id abs `+0x30c0`). Compose **local** product strings only; set widget text + place at cursor. Do **not** invent C2S RE/tinker packets here. Share Broken bit `+0x17c>>19` with inventory gates. Pending gadget/kit TFIDs live in `DAT_00d1d940/944` and `DAT_00d1d938/93c`. |
| `008e5ce0` | Port as **stdcall** `Bind(host, coidLo, coidHi)`. Invalid both-half `0xFFFFFFFF` clears selection. Resolve cargo/locker via sealed `InventoryGrid_FindItemByCoid`, skip Broken to equip TFID table `@char+0x5a0`, then bind through host panel (`FUN_008e5990`). Do **not** treat as mission UI refresh. |

Shared:

- Both are **inventory-transfer UI** residuals under WQ-008 craft-adjacent paths (not grab/drop packet managers).
- Both consume sealed **FindItemByCoid** and the **Broken** flag at `object+0x17c` bit 19.
- Pair with prior RE units: `Inv_Client_ReverseEngineerItem` (`0x0093d110`), `Client_OnReverseEngineerFailure` (`0x0080df40`).

| Symbol | Role |
|--------|------|
| `DAT_00d1b6d8` | Local character |
| `DAT_00d1b9a8` | Cursor / UI host (tooltip unit) |
| `DAT_00d1d900` | `client+0x30c0` multi-mode / pending |
| `DAT_00d1d938`/`93c` | Tinkering kit TFID |
| `DAT_00d1d940`/`944` | Gadget TFID |
| `char+0x5a0` | Equip TFID pair table |
| `char+0x250` / `+0xcbc` | Vehicle / locker inventory roots |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + force_decompile + read_memory + function/xref/call-site helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Trio: raw + annotated + clean named (FUN twin plates point at named).  
- Rejected single-string / Named_CalleeOf scaffolds.  
- `_Inferred` retained where product class English is structural not PDB.

---

## This report

`docs/agents/task-dual-ab-0085ce20-008e5ce0-wq8rh-report.md`
