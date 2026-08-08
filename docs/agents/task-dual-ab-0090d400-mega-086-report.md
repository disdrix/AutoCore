# Dual A/B report — MEGA-086 OWN-ONLY (`0x0090d400`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-086**  
**Scope:** VA `0x0090d400` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_function_by_address` + `get_function_callers` / `get_xrefs_to`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_mega_residual_partition_map.md` → **MEGA-086**.  
**Work item:** residual dual seal — **UI_CloseRelatedChrome** (interaction-menu optional close + chrome table flush leaf).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0090d400` UI_CloseRelatedChrome_Inferred | **accept-with-gaps** — CF/ABI/ESI-primary/EDI-secondary/vtbl offsets/25 xrefs/call-site families sealed; product class + vtbl English open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): ECX-thiscall / OnKeyDown-scaffold / fixed host-chrome mapping / empty-leaf / runtime-Confirmed claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x0090d400` — sealed facts

1. **Body:** `0x0090d400`–`0x0090d465` inclusive (**102 B** / `0x66`); last insn **`RET`** (`C3`); pad **`CC`** then `FUN_0090d470` @ `0x0090d470`.

2. **ABI:** **register contract** (not ECX-thiscall entry).  
   - **ESI** = **primary** UI object closed  
   - **EDI** = **secondary** UI object notified/reset  
   - **No** stack formals; bare **`RET`** (`C3`)

3. **Semantics — close primary, notify secondary:**
   - Gate: `ESI != 0` and `ESI->vtbl+0x3d8()` (visible/active).
   - `ESI->vtbl+0xcc(0)` then `ESI->vtbl+0x440()` (hide + close/flush).
   - `EDI->vtbl+0xb0(ESI)` (detach/notify).
   - Optional: if `DAT_00d1b978` non-null and visible → `EDI->vtbl+0x3bc(DAT_00d1b978)`.
   - Always (after primary closed): `EDI->vtbl+0x3f4(-1)`.

4. **Static callees:** **none** (virtual only; analyze classifies leaf).

5. **Callers (9 named functions; 25 UNCONDITIONAL_CALL xrefs):**  
   `FUN_0082c780`, `FUN_0082fe20` (×2), `FUN_00830010`, `FUN_00830aa0` (×2), `FUN_00830b40`, `FUN_00866400`, `FUN_008a1e60`, `FUN_0090dab0`, `FUN_00916450`, plus additional sites (`00832a*`, `008316*`, `008f7786`, `008eb82f`, …).

6. **Call-site families:**
   - **Menu:** ESI = menu host, EDI = `*(host+0x2B0)` related chrome (parent dual optional-close path).
   - **Table flush `0090dab0`:** EDI = host (EAX), ESI = chrome from `DAT_00d09a38`..`00d09a4c`.
   - **Global chrome:** ESI loaded from chrome globals; EDI ambient host.

7. **Name:** `UI_CloseRelatedChrome_Inferred` (Ghidra `FUN_0090d400`). Scaffold `Named_CalleeOf_*OnKeyDown*` **retired**. Product class **Inferred**.

8. **Decompile ≡ raw CF**; body/ABI sealed via `disassemble_function` + `read_memory` + call-site listings.

9. **System:** skills-abilities (partition; parent interaction-menu dual).

### Gaps

- Product / MSVC demangle for host and chrome classes.  
- English for vtbl `+0x3d8` / `+0xcc` / `+0x440` / `+0xb0` / `+0x3bc` / `+0x3f4`.  
- Product identity of `DAT_00d1b978` (Tell/chat indicated only).  
- Single product symbol vs dual call-site host/chrome assignment (static dual-use sealed; English open).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0090d400_UI_CloseRelatedChrome_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0090d400_UI_CloseRelatedChrome_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0090d400_FUN_0090d400.md` |
| Annotated | `docs/reconstruction/raw/aa_0090d400_FUN_0090d400.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_CloseRelatedChrome_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0090d400.cpp` |
| Scaffold (retired) | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Client_Input_OnKeyDown_MatchActio_0090d400.cpp` |
| Function | `docs/reconstruction/functions/aa_0090d400_FUN_0090d400.md` |
| Function named | `docs/reconstruction/functions/aa_0090d400_UI_CloseRelatedChrome_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0082fe20  UI_InteractionMenu_PopulateTargetButtons_Inferred  [dualed WQ9E-D]
  ├─ gate host+0x4C0; shell FUN_0082d2b0; resolve TFID @+0x578
  ├─ skip pack paths:
  │     if host+0x2B0: FUN_0090d400  UI_CloseRelatedChrome_Inferred  [OWN MEGA-086]
  └─ else pack order via vtbl+0x478 → social button packs

FUN_0082c780 / FUN_00830010 / FUN_00830aa0 / FUN_00830b40
  └─ command / close paths → FUN_0090d400 (ESI=host, EDI=*+0x2B0)

FUN_0090dab0  chrome table flush  [residual]
  └─ for each DAT_00d09a38..4c: ESI=entry, EDI=host(EAX) → FUN_0090d400

DAT_00d1b978  optional global panel re-bind (also Tell 0x11176 peer)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0090d400-mega-086-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0090d400` | Port as **register-contract UI close leaf**: **ESI=primary closed**, **EDI=secondary notified**, bare RET, no stack args. Sequence: visible? → `+0xcc(0)` → `+0x440` → secondary `+0xb0(primary)` → optional `+0x3bc(DAT_00d1b978)` → `+0x3f4(-1)`. Do **not** model as ECX-thiscall or OnKeyDown helper. Menu callers pass host/chrome inverted vs table flush — preserve **register roles**, not fixed class mapping. |
| Pair with | dualed parent `UI_InteractionMenu_PopulateTargetButtons_Inferred` (`0082fe20`); residual table flush `0090dab0`; residual command routers `0082c780` / `00830010`; dualed dismiss vocabulary peers (progress bar / mission flush) for vtbl English only. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history (retire Named_CalleeOf OnKeyDown scaffold)  
- `systems/skills-abilities.md` interaction-menu close leaf  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x0090d400`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + disassemble_function + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name; Named_CalleeOf scaffold retired.  
- Odd behavior preserved: dual call-site host/chrome assignment into ESI/EDI; optional global re-bind; decompiler unaff registers corrected via listing.  
- `_Inferred` where English unproven; Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
