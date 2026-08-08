# Dual A/B report — R12-016 OWN-ONLY (`0x005140d0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R12-016**  
**Scope:** VA `0x005140d0` (`aa_005140d0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r12_residual_partition_map.md` → **R12-016**.  
**Work item:** Residual dual seal — inventory-transfer; item rarity BGRA palette leaf (parent dual `0x00847240`).  
**Dual start:** retry (prior agent hung).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005140d0` UI_ItemRarity_WriteBgraFromIndex_Inferred | **accept-with-gaps** — CF/ABI/cdecl/JT palette 0..5+default/BGRA/EAX=out/7 callers sealed; product demangle open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): thiscall / name-table / tooltip-merge / mission scaffold / Runtime Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005140d0` — sealed facts

1. **Body:** `0x005140d0`–`0x0051416a` exclusive (**154 B** / `0x9A`); pad `8B FF` @ `0x0051416a`; jump table 6×DWORD @ `0x0051416c`; `CC` pad after JT. All exits bare **`C3`**.
2. **ABI:** **cdecl** — stack **`out*`** @ `[ESP+4]`, **`int16 index`** @ `[ESP+8]` (`MOVSX`); bare **`RET`**; returns **`out`** in **EAX**.
3. **Semantics:** Leaf **rarity-index → BGRA palette** writer:
   - `CMP index,5` / `JA` default / `JMP [JT+index*4]`.
   - Cases 0..5 write fixed BGRA quartets; default cyan.
   - No callees; no globals.
4. **Classification:** **leaf**.
5. **Callers (7 UNCONDITIONAL_CALL):** `FUN_00847240`, `FUN_0084b890`, `FUN_00843a60`, `FUN_008becd0`, `FUN_008b6590`, `FUN_008c03c0`, `FUN_00904d50`.
6. **Callees:** none.
7. **Parent use:** dualed `UI_ItemTooltip_AppendTypeMetaLines_Inferred` (`0x00847240`) — when item type ≠ 4: rarity name from `DAT_00b04214[blob+0x4b8]` + color via this unit → text-host `vtbl+0x22c`.
8. **Name:** `UI_ItemRarity_WriteBgraFromIndex_Inferred` (Ghidra `FUN_005140d0`). Retires `Named_CalleeOf_Mission_Mission_Object_005140d0`. **`_Inferred`** — no RTTI/PDB.
9. **Decompile ≡ raw CF**; decompiler `void` corrected to return `out` (EAX).  
   Entry hex: `0fbf44240883f805777cff24856c415100…`.
10. **Partition parent** `0x00847240` is dualed tooltip twin; **do not merge** with name table `005129b0` or entity name palette `00930f40`.

### Palette (AARRGGBB)

| Index | Color |
|------:|-------|
| 0 | `0xFF919191` gray |
| 1 | `0xFFFFFFFF` white |
| 2 | `0xFF2828FF` blue |
| 3 | `0xFFF014F0` purple |
| 4 | `0xFFFF0A23` orange-red |
| 5 | `0xFFFF8A0A` gold |
| default | `0xFFF0E43C` cyan |

### Gaps

- Product English tier labels (table strings residual).  
- PDB symbol.  
- Runtime / bit-exact / differential.  
- Non-tooltip callers not dualled (may pass other index domains; body still pure map).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005140d0_UI_ItemRarity_WriteBgraFromIndex_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005140d0_UI_ItemRarity_WriteBgraFromIndex_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005140d0_FUN_005140d0.md` |
| Annotated | `docs/reconstruction/raw/aa_005140d0_FUN_005140d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_ItemRarity_WriteBgraFromIndex_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005140d0.cpp` |
| Function | `docs/reconstruction/functions/aa_005140d0_FUN_005140d0.md` |
| Function named | `docs/reconstruction/functions/aa_005140d0_UI_ItemRarity_WriteBgraFromIndex_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
UI_ItemTooltip_AppendTypeMetaLines_Inferred (0x00847240)   [parent dual R11-029]
  └─ if type != 4:
       EnsureLootRarityTableLoaded  0x005129b0  [dualed]
       rarity name DAT_00b04214[blob+0x4b8]
       FUN_005140d0  UI_ItemRarity_WriteBgraFromIndex_Inferred  [OWN R12-016]
       textHost.AppendColor(vtbl+0x22c)

UI_ItemDetailPanel_Refresh_Inferred (0x0084b890)  [dualed]
  └─ FUN_005140d0  (rarity label color)

Ui_NameColorPalette_WriteArgb_Inferred (0x00930f40)  [dualed sibling]
  └─ entity name colors — different ABI/palette — do not merge
```

Partition host "inventory-transfer" names the **item UI color** residual of the dualed tooltip meta-line parent.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005140d0-r12-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005140d0` | Port as **fixed rarity→BGRA palette**: cdecl `(out, int16 index)`, write 4 bytes, return out; indices 0..5 + cyan default. |
| Distinct from | Rarity name table `005129b0`; tooltip appender `00847240`; entity name palette `00930f40`. |
| Pair with | dualed parent `00847240`; dualed `005129b0`; dualed detail panel `0084b890`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `UI_ItemRarity_WriteBgraFromIndex_Inferred` @ `0x005140d0` / `aa_005140d0`.
- Retire: `Named_CalleeOf_Mission_Mission_Object_005140d0`.
- Verdict: **accept-with-gaps**; Terminal **false**.

---

## Process

- OWN VA only (`0x005140d0`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses meaningful product name + machine twin; ABI correction (return out; cdecl).
- Odd behavior preserved: decompiler showed `void` but EAX=out is live; negative indices fall to default via signed MOVSX + unsigned JA.
- Product name open → `_Inferred`. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
