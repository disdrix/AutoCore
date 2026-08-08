# Dual A/B report — MEGA-033 OWN-ONLY (`0x0091a350`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-033**  
**Scope:** VA `0x0091a350` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + `disassemble_function` + `get_function_by_address` + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-033**.  
**Work item:** residual dual seal — **soft-cast / clear-select alternate** under dualed `Client_InteractWorldClickHub` (`0x00925820`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0091a350` Client_InteractWorldClick_SoftCastAlt_Inferred | **accept-with-gaps** — CF/ABI/ESI-this/AL bool/sole hub caller/`d1a860==0` alt/soft-cast clear+FX sealed; product English + FX dual + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): free-void / ECX-entry-thiscall / select-clear-owner / multi-caller / UseObject-hub / always-FX / runtime-Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0091a350` — sealed facts

1. **Body:** `0x0091a350`–`0x0091a54a` inclusive (**507 B** / `0x1FB`); pad `CC` after.
2. **ABI:** **ESI** = client* (caller `MOV ESI,EDI`); no stack args; void-looking decomp is wrong; **AL** bool; bare **`RET`** (`C3`) ×2 exits; 16-byte stack align.
3. **Semantics:** non-drop world-click alternate:
   - Gate `vtbl+0x3D8`; fail → 0.
   - `client+0x558 = -1.0f` (`DAT_00aaa668` = `00 00 80 BF`); `+0xA32 = 0`; `vtbl+0x478()`.
   - If select `+0x758`: `Ui_ResolveEntityNameColor_Inferred` (ECX=entity).
   - If soft-cast `entity+0x106`: clear `+0x107`; optional type-2 FX `FUN_007a0120` (ECX from `DAT_00d17944`) with 0.4f/1.0f/3.0f/`0x61` pack from body `+0x284`.
   - Return 1.
4. **Does not** zero select or call `FUN_0093e120(0)` (ItemPickup sibling).
5. **Callers / xrefs:** **1** UNCONDITIONAL_CALL — hub @ `0x00925958` after `CMP [DAT_00d1a860],AL` / `JNZ` drop-ray.
6. **Callees:** `FUN_00930fc0` (dualed name-color), `FUN_007a0120` (residual FX), 2 vtbl slots.
7. **Name:** `Client_InteractWorldClick_SoftCastAlt_Inferred` (Ghidra `FUN_0091a350`). Product map open → `_Inferred`. No `Named_CalleeOf_*` scaffold to retire.
8. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product English for vtbl `+0x3D8`/`+0x478`, flags `+0xA32`/`+0x558`, `DAT_00d1a860`.  
- Full dual of `FUN_007a0120` FX host/args.  
- Name-color local sink (call preserved; sink open).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0091a350_Client_InteractWorldClick_SoftCastAlt_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0091a350_Client_InteractWorldClick_SoftCastAlt_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0091a350_FUN_0091a350.md` |
| Annotated | `docs/reconstruction/raw/aa_0091a350_FUN_0091a350.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_InteractWorldClick_SoftCastAlt_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0091a350.cpp` |
| Function | `docs/reconstruction/functions/aa_0091a350_FUN_0091a350.md` |
| Function named | `docs/reconstruction/functions/aa_0091a350_Client_InteractWorldClick_SoftCastAlt_Inferred.md` |

---

## Chain context (not dualled here; evidence only)

```text
Client_InteractWorldClickHub  (0x00925820)  [dualed W17-C]
  ├─ DAT_00d1a860 == 0:
  │    └─ FUN_0091a350  Client_InteractWorldClick_SoftCastAlt_Inferred  [OWN MEGA-033]
  │         ├─ vtbl+0x3D8 / +0x478
  │         ├─ FUN_00930fc0  Ui_ResolveEntityNameColor_Inferred  [dualed WQ9D-J]
  │         └─ FUN_007a0120  FX type-2  [residual]
  └─ DAT_00d1a860 != 0:
       ├─ drop-destroy modal (char+0xCD0) OR
       └─ ray 100f + gather 20f mode6
            ├─ SoftCastHitList_SortIfCountGt1  [MEGA-116]
            ├─ FUN_0040afb0 resolve  [MEGA-028 residual]
            └─ ItemPickup → clear select[+0x758] + FUN_0093e120(0)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0091a350-mega-033-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0091a350` | Port as **non-drop world-click alternate**: gate → cancel markers → optional name-color → optional soft-cast clear+FX → bool. |
| ABI | **ESI=client*** (or explicit client param in managed); **no stack args**; bare **RET**; return **bool**. |
| Do **not** | Zero select here; claim ItemPickup/UseObject ownership; always spawn FX; claim ECX-thiscall-on-entry without ESI fixup. |
| Pair with | dualed hub `00925820`; dualed name-color `00930fc0`; residual FX `007a0120`; soft-cast sort `0048a060`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` interaction-activation residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x0091a350`); no Launcher; no parent ledger edits; no other VAs dualed.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful `_Inferred` name; machine ABI corrections (ESI client; bare RET; AL bool).  
- Odd behavior preserved: name-color into local without visible store; decompiler void/unaff_ESI corrected via assembly; does not clear select slot.  
- `_Inferred` where English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
