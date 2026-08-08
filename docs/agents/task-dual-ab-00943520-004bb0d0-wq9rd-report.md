# Dual A/B report — WQ9R-D OWN `0x00943520` + `0x004bb0d0`

**Date:** 2026-08-04  
**Agent:** WQ9R-D (OWN-ONLY dual)  
**Scope:** OWN ONLY VAs `0x00943520`, `0x004bb0d0`. Trio + clean + dual A/B.  
**Wave:** WQ-009 residual (skills-abilities priority 93)  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / parent ledgers / cross-agent VAs.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_00943520` `Client_SelectNearestHostileInRange_Inferred` | **accept-with-gaps** — EAX-this + mode-2 nearest gather + resolve/select sealed; product keybind names open |
| `aa_004bb0d0` `Object_ResolveTfIdVtbl1dc_Inferred` | **accept-with-gaps** — resolve + `vtbl+0x1dc` + ECX passthrough sealed; product vtbl name open |

---

## `0x00943520` — Client_SelectNearestHostileInRange_Inferred

### Sealed facts

1. **Body** `0x00943520`–`0x009436bb`; **411 B** (`0x19B`).
2. **ABI:** **this in EAX** (client host; PollBound loads `DAT_00d1a840`); stack **float rangeArg**; **`RET 4`**. Prologue `MOV ESI,EAX`.
3. **Busy gate:** `char = *(client+0xe98)`; if `*(u8*)(char+0x4f1) != 0` → return (shared with `Client_SelectTargetObject_Inferred`).
4. **Origin:** MI(char) → `vtbl+0x1a0()` float4 copy to stack.
5. **Seed TFID** from `g_abTfidInvalid_A15870` @ `0x00a15870` = `FF×8 + 00×8`.
6. **Gather ×1–2** via `Skill_GatherTargetsInArea`:
   - maxTargets **1**, mode **2** (hostile), filterA=0, chain=0, allowSelf=1, filterB=0, filterC=1, scoreArg **−1.0f** (`0xbf800000`);
   - pass1 **sortByDistance=1**; if still invalid, pass2 **sort=0**;
   - invalid: `(lo & hi) == 0xffffffff && bGlobal == 0`.
7. **Miss:** bare return — **no** `SelectTarget(0)` clear (unlike screen hostile pick).
8. **Hit:** `ECX = *(*(char_comp+0xa8)+0xe4e8)`; `Object_ResolveFromTFID` (`0x004bb950`); if non-null → `Client_SelectTargetObject_Inferred` (`0x0093e120`).
9. **Callers:** `Client_Input_PollBoundActions` ×3 with range **110.0f** (`0x42dc0000`); when `DAT_00d1d888` set, sibling `FUN_00943340` cycles instead (prev/next). Orphan CODE xref `0x00925467` (no containing function in Ghidra).

### Gaps

1. Product keybind English for edge DAT pairs (`d1beca`, `d1be96`, `d1befe`, …).  
2. Product type of `*(char_comp+0xa8)` (query / host with `+0xe4e8`).  
3. Orphan site `0x00925467` function boundary.  
4. Runtime / bit-exact / image diff.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00943520_Client_SelectNearestHostileInRange_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00943520_Client_SelectNearestHostileInRange_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00943520_Client_SelectNearestHostileInRange_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00943520_Client_SelectNearestHostileInRange_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00943520_Client_SelectNearestHostileInRange_Inferred.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_00943520_FUN_00943520.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_SelectNearestHostileInRange_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00943520.cpp` |
| Raw | `docs/reconstruction/raw/aa_00943520_FUN_00943520.md` |
| Annotated | `docs/reconstruction/raw/aa_00943520_FUN_00943520.annotated.md` |

---

## `0x004bb0d0` — Object_ResolveTfIdVtbl1dc_Inferred

### Sealed facts

1. **Body** `0x004bb0d0`–`0x004bb0f9`; **42 B**; leaf-thin wrapper.
2. **ABI:** stack blob* cleaned by **`RET 4`**; **ECX = resolve context** supplied by caller and preserved into `CVOGReaction_ResolveObjectTarget` (`0x004bae70`). Decompiler omits ECX (same trap as `Object_ResolveFromTFID` / `Vtbl1d4`).
3. **Algorithm:** unpack blob `+0` coidLo, `+4` coidHi, `+8` bGlobal → Resolve → if null return 0 else **`obj->vtbl[+0x1dc]()`**.
4. **Bytes ≡ decompile**  
   `8b4424048b5004528b108a40085250e88cfdffff85c0740d8b108bc8ff92dc010000c2040033c0c20400`.
5. **Virtual encoding:** `FF 92 DC 01 00 00` = `CALL [EDX+0x1dc]`.
6. **Callers (9 xrefs / 8 funcs):** `Skill_FilterTargetForResolveList_Inferred`, `CVOGHBAIBase_FindTargetToAttack`, `FUN_004c44c0`, `FUN_004c8780`, `FUN_005139f0` (×2), `FUN_00638be0`, `FUN_0080cfc0`, `FUN_00836410`.
7. **Siblings:** `004bb950` resolve-only; `004bb010` `+0x1d4` blob; `004bb070` `+0x1d8` identity; `004bb0a0` `+0x1dc` **free 3-arg** Lookup (`RET 0xc`) — same slot, different ABI.

### Gaps

1. Product name of `vtbl+0x1dc`.  
2. Whether return is always identity-equal to resolved `obj`.  
3. Runtime / bit-exact / image diff.  
4. Exhaustive per-caller ECX provenance.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_004bb0d0_Object_ResolveTfIdVtbl1dc_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_004bb0d0_Object_ResolveTfIdVtbl1dc_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004bb0d0_Object_ResolveTfIdVtbl1dc_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004bb0d0_Object_ResolveTfIdVtbl1dc_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_004bb0d0_Object_ResolveTfIdVtbl1dc_Inferred.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_004bb0d0_FUN_004bb0d0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_ResolveTfIdVtbl1dc_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004bb0d0.cpp` |
| Raw | `docs/reconstruction/raw/aa_004bb0d0_FUN_004bb0d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004bb0d0_FUN_004bb0d0.annotated.md` |

---

## AutoCore impact

- **Target cycle / nearest hostile:** client nearest-hostile is **mode-2 gather max1** with fixed poll range **110.0f**, not screen-ray math. Ports that only implement click-pick or drive combat look will miss bound-action nearest select.
- **Miss behavior:** nearest path does **not** clear selection on empty gather (contrast `Client_SelectHostileUnderScreenPick` which selects null).
- **TFID resolve family:** blob form of `+0x1dc` (`004bb0d0`) is the sibling of free-arg Lookup (`004bb0a0`) and of blob `+0x1d4` (`004bb010`). Skill filter / AI target paths use the blob form; do not collapse ABIs.
- **Cycle sibling** `FUN_00943340` (WQ9R-C owned) is the next/prev list walker when `DAT_00d1d888` is non-null — keep nearest and cycle separate.

---

## This report

`docs/agents/task-dual-ab-00943520-004bb0d0-wq9rd-report.md`
