# Dual A/B report — MEGA-100 OWN-ONLY (`0x00522000`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-100**  
**Scope:** VA `0x00522000` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `force_decompile` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_callees` + `get_xrefs_to` + `read_memory` (entry + call sites). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — inventory-transfer equip TFID table count; partition parent `0x008e5ce0` Client_UI_CraftHost_BindObjectByTfid_Inferred; name hint Character_GetEquipTfidTableCount.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00522000` Character_GetEquipTfidTableCount_Inferred | **accept** — CF/ABI/RET0/formula/clamp-8/leaf/7 xrefs/equip-table role sealed |

Path A (fidelity): **accept**.  
Path B (adversarial): mission-UI scaffold / void-return / no-this / no-shift / max-7 / RET4 / grid-count / mutate claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00522000` — sealed facts

1. **Body:** `0x00522000`–`0x00522016` inclusive (**23 B** / `0x17`); pad `CC` before sibling `FUN_00522020` @ `0x00522020`.
2. **ABI:** **ECX** = Character*; no stack args; **EAX** = count; **bare RET**.
3. **Semantics:** equip TFID table length leaf:
   - `count = (*(uint8_t*)(this + 0x59a) >> 1) + 3`
   - if `count >= 8` then `count = 8`
   - return count
   - No stores; no callees.
4. **Bytes:** `0f b6 81 9a 05 00 00 d1 e8 83 c0 03 83 f8 08 7c 05 b8 08 00 00 00 c3`
5. **Callees:** none (leaf).
6. **Callers (5 named + 2 extra xrefs):**  
   - `FUN_008e5ce0` @ `008e5d80` (dualed craft-host bind parent)  
   - `FUN_008e5e00` @ `008e61c4`  
   - `FUN_008b2f00` @ `008b2f21`  
   - `FUN_008b3400` @ `008b343c`  
   - `FUN_008b3670` @ `008b369d`  
   - xrefs also `008b31f7`, `008e83c8`  
   All sampled sites: `mov ecx, [DAT_00d1b6d8]` then `call`. UI null-char paths store **literal 8**.
7. **Role:** every named caller walks **`character+0x5a0`** as lo/hi TFID pairs (stride 8) with this return as exclusive upper bound (often `CVOGReaction_ResolveObjectTarget`).
8. **Name:** `Character_GetEquipTfidTableCount_Inferred` (Ghidra `FUN_00522000`). Product field/method English open → `_Inferred`. Scaffold `Named_CalleeOf_*` **retired**.
9. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product/PDB English for method and `+0x59a` budget byte.  
- Low-bit meaning of `+0x59a` (ignored by `>>1`).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00522000_Character_GetEquipTfidTableCount_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00522000_Character_GetEquipTfidTableCount_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00522000_FUN_00522000.md` |
| Annotated | `docs/reconstruction/raw/aa_00522000_FUN_00522000.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_GetEquipTfidTableCount_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00522000.cpp` |
| Function | `docs/reconstruction/functions/aa_00522000_FUN_00522000.md` |
| Function named | `docs/reconstruction/functions/aa_00522000_Character_GetEquipTfidTableCount_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_UI_CraftHost_BindObjectByTfid_Inferred  0x008e5ce0  [dualed parent WQ8R-H]
  cargo/locker FindItemByCoid …
  broken/miss → equip scan:
    n = FUN_00522000()  Character_GetEquipTfidTableCount_Inferred  [OWN MEGA-100]
    for i in 0..n-1:
      lo/hi = *(char + 0x5a0 + i*8)
      match → CVOGReaction_ResolveObjectTarget(1, lo, hi)
    bind via FUN_008e5990

FUN_008e5e00 / FUN_008b2f00 / FUN_008b3400 / FUN_008b3670
  same n = FUN_00522000(); walk +0x5a0

FUN_00522020  Character_SelectInventoryGridByMode  [sibling residual MEGA-045]
  DISTINCT — not this unit
```

### Formula table (illustrative)

| `+0x59a` | `>>1` | `+3` | clamp |
|--------:|------:|----:|------:|
| 0–1 | 0 | 3 | 3 |
| 2–3 | 1 | 4 | 4 |
| 4–5 | 2 | 5 | 5 |
| 10–11 | 5 | 8 | 8 |
| ≥12 | ≥6 | ≥9 | **8** |

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00522000-mega-100-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00522000` | Port as **Character equip TFID table count** leaf: `min(8, (*(u8*)(this+0x59a)>>1)+3)`. **ECX=Character\***, bare RET, EAX count. **Do not** drop the `>>1` or change clamp to 7. Pair with equip table at **`this+0x5a0`** (8-byte TFID pairs). Keep distinct from inventory-grid select sibling `00522020` and from cargo/locker grid capacity. Null-character UI paths may hardcode **8** without calling. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history (retire `Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_00522000`)  
- `systems/*` inventory-transfer residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  
- Optional: refresh parent clean `Client_UI_CraftHost_BindObjectByTfid_Inferred.cpp` to name `Character_GetEquipTfidTableCount_Inferred` instead of bare `FUN_00522000`

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00522000`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + force + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name; twin `FUN_00522000.cpp` retained; Named_CalleeOf scaffold **retired**.  
- `_Inferred` for product method/field English. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
