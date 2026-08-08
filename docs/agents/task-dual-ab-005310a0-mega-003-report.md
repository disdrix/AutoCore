# Dual A/B report — MEGA-003 OWN-ONLY (`0x005310a0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-003**  
**Scope:** VA `0x005310a0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `analyze_control_flow` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — UseItem give-by-cbid / GiveItemByCbid+inventory (parents `0x0060d630`, `0x0060d540`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005310a0` Character_GiveItemByCbid_Inventory_Inferred | **accept-with-gaps** — CF/ABI/RET8/cbid+count loop/factory+SendAdd/callers sealed; class English + vtbl/bind open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): log-only / factory-only / wrong-arity / free-function / while-infinite claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x005310a0` — sealed facts

1. **Body:** `0x005310a0`–`0x00531247` inclusive (**424 B** / `0x1A8`); 133 instructions; 10 basic blocks; cyclomatic ~10.
2. **ABI:** **ECX** = character dual-base this; stack **cbid**, **count**; **AL** bool; **`RET 8`** (`C2 08 00`) ×2 exits.
3. **Semantics:** Give **count** items of catalog **cbid** into inventory:
   - Dual-base char at `*( *(this+4)+4 ) + 0xa8 + this`.
   - If `*(char*)(char+0x7e)==0` → return **true** (no grant).
   - Loop remaining←count: `CVOGReaction_GiveItemByCbid(cbid, 0)`; null → log `"Invalid CBID: %d (bad item)"` @ `0x009cfea4` → **false**.
   - Per unit: `vtbl+8` init; 64-bit serial from `char+0xe6e0` via `FUN_00512160`; transform zero-pose (`g_flOne` @ `0x00a0f2a0`); owner `vtbl+0x2a4`/`+0x218`; first-item `FUN_00513e70` may collapse multi-grant; `Client_SendInventoryAddItem(this, item, flag)`.
4. **Callees:** `CVOGReaction_GiveItemByCbid` `0x0051a170`; `FUN_00512160`; `FUN_00513e70`; `Client_SendInventoryAddItem` `0x00530df0`; `FUN_007a4480`; item vtbl slots.
5. **Callers (6 / 8 xrefs):**  
   - `CVOGObjectiveRequirement_UseItem_InitActive` `0x0060d540` @ `0x0060d57f`, `0x0060d5e5`  
   - `FUN_0060d630` @ `0x0060d694`, `0x0060d78b`  
   - `FUN_00531570` @ `0x00531696`  
   - `FUN_005316c0` @ `0x005318cf`  
   - `FUN_00607a00` @ `0x00607a20`  
   - `FUN_00610e60` @ `0x00610e8b`
6. **Name:** `Character_GiveItemByCbid_Inventory_Inferred` (Ghidra `FUN_005310a0`). Class English open → `_Inferred`. Retired `Named_CalleeOf_CVOGObjectiveRequirement_UseItem_InitActive_005310a0`.
7. **Decompile surface ≠ full ABI:** arity/loop corrected by `disassemble_function`; clean follows assembly.

### Gaps

- Product English for character dual-base class.  
- Item vtable method names (`+8`, `+0x1cc`, `+0x2a4`, `+0x218`, `+0x260`).  
- Full `FUN_00513e70` bind/trade-lock vs notify-flag model.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005310a0_Character_GiveItemByCbid_Inventory_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005310a0_Character_GiveItemByCbid_Inventory_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005310a0_FUN_005310a0.md` |
| Annotated | `docs/reconstruction/raw/aa_005310a0_FUN_005310a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_GiveItemByCbid_Inventory_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005310a0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_CVOGObjectiveRequirement_UseItem_InitActive_005310a0.cpp` |
| Function | `docs/reconstruction/functions/aa_005310a0_FUN_005310a0.md` |
| Function named | `docs/reconstruction/functions/aa_005310a0_Character_GiveItemByCbid_Inventory_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
CVOGObjectiveRequirement_UseItem_InitActive  0x0060d540
FUN_0060d630  (UseItem progress/complete)
  └─ Character_GiveItemByCbid_Inventory_Inferred  0x005310a0  [OWN MEGA-003]
        ├─ CVOGReaction_GiveItemByCbid  0x0051a170  [dualed]
        ├─ FUN_00512160  (serial stamp item+0x160..)
        ├─ FUN_00513e70  (bind/lock gate)
        └─ Client_SendInventoryAddItem  0x00530df0

FUN_00531570 / FUN_005316c0  craft paths
FUN_00607a00  outpost reward (hard cbid 0x21a3)
FUN_00610e60  objective grant helper
  └─ same 0x005310a0
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-005310a0-mega-003-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005310a0` | Port as **character give-by-cbid inventory grant**. **thiscall RET 8**; args `(cbid, count)`; returns bool. Gate `char+0x7e` clear → success no-op. Fail only on factory null + log. Pair with dualed factory `CVOGReaction_GiveItemByCbid` and `Client_SendInventoryAddItem`. Do **not** treat as log-only helper. |
| Pair with | dualed `CVOGReaction_GiveItemByCbid` `0x0051a170`; UseItem parents `0x0060d540` / `0x0060d630`; residual `FUN_00513e70` bind gate; craft parents `0x00531570` / `0x005316c0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA only:

- `VERIFICATION_MATRIX.md` / coverage / naming registry entries when parent wave merges  
- Do **not** claim runtime Confirmed without Launcher verification
