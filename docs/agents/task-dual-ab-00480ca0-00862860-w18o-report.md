# Dual A/B report — W18-O OWN `0x00480ca0` + `0x00862860`

**Date:** 2026-07-29  
**Scope:** OWN ONLY VAs `0x00480ca0`, `0x00862860`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ complete analysis / callers / callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_00480ca0` `StdVector_PushBack12_Inferred` | **accept-with-gaps** — 120 B body, EAX EAX/EBX, stride 0xC, fast/slow sealed; grow dual + product name open |
| `aa_00862860` `Client_ItemMatchesActiveHardpointMode_Inferred` | **accept-with-gaps** — ECX/ESI ABI, class→mode table, jump table sealed; product mode enum names open |

---

## `0x00480ca0` — StdVector_PushBack12_Inferred

### Sealed facts

1. **Body** `0x00480ca0`–`0x00480d17` (**120 bytes**).
2. **ABI:** **EAX** = vector* (`+4` begin, `+8` end, `+0xc` capacityEnd); **EBX** = `const Element12*` (12 bytes / 3 dwords); bare **`RET`**.
3. **Fast path:** `begin != 0` and `(end-begin)/12 < (capEnd-begin)/12` → `FUN_0042acc0(count=1, dest=end, src=EBX)` then `end += 0xC`.
4. **Slow path:** `FUN_0042a710` grow/insert (vector via EDI into callee).
5. **Stride** Confirmed: `add esi,0xC`; signed `/12` magic `0x2AAAAAAB`.
6. **Callers:** `FUN_0071dec0` (`LEA EBX, local12`), `FUN_007866e0` (thread table; parent uses `/0xc`).
7. Decompiler `__fastcall param_1` / `unaff_EBX` is **noisy** — bytes + call sites override.

### Gaps

1. Product/STL symbol.  
2. Dual of grow chain `FUN_0042a710` / `FUN_00480d20`.  
3. Element12 product type (caller-specific).  
4. Runtime / bit-exact / image diff.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00480ca0_StdVector_PushBack12_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00480ca0_StdVector_PushBack12_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00480ca0_StdVector_PushBack12_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00480ca0_StdVector_PushBack12_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00480ca0_FUN_00480ca0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_PushBack12_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00480ca0.cpp` |
| Raw (authoritative + re-verify append) | `docs/reconstruction/raw/aa_00480ca0_FUN_00480ca0.md` |
| Annotated | `docs/reconstruction/raw/aa_00480ca0_FUN_00480ca0.annotated.md` |
| Scratch | `tmp/a_00480ca0.md` |

---

## `0x00862860` — Client_ItemMatchesActiveHardpointMode_Inferred

### Sealed facts

1. **Body** `0x00862860`–`0x008629a1` (**322 bytes**).
2. **ABI:** **ECX** = item*; **ESI** = uiHost* (`vtbl+0x3cc` → active mode int); return **bool AL**.
3. **Null item → false.** CloneBase at `item+0xA8`, class at `+0x38`.
4. **Jump table** @ `0x008629a4` + **byte map** @ `0x008629c0` after `class - 6` range check.
5. **Class → expected mode:**

| Class | Notes | Mode |
|---|---|---|
| 10 | power plant | 1 |
| 0x10 | wheelset | 2 |
| 0x1c | armor | 3 |
| 0x0c | weapon; flags/subtype | 4 / 5 / 6 / 7 |
| 6 | ornament subtype 0xb / 10 | 8 / 9 |
| 0x0e | town-gated class (parent string) | 0x0d |

6. **Callers:** `Client_SendInventoryDrop_Hardpoint` (false → abort), `Client_UI_InventoryItemClickDispatch`, `FUN_00862b70`.
7. **Callees:** `vtbl+0x3cc`, item `vtbl+0x1e0` (weapon), `FUN_0040da70`.

### Gaps

1. Product helper name and `vtbl+0x3cc` / mode enum English.  
2. Weapon `+0x536` flag product meanings.  
3. Runtime / bit-exact / image diff.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00862860_Client_ItemMatchesActiveHardpointMode_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00862860_Client_ItemMatchesActiveHardpointMode_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00862860_Client_ItemMatchesActiveHardpointMode_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00862860_Client_ItemMatchesActiveHardpointMode_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00862860_FUN_00862860.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_ItemMatchesActiveHardpointMode_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00862860.cpp` |
| Legacy alias clean | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Client_SendInventoryDrop_Hardpoint_00862860.cpp` |
| Raw (authoritative + re-verify append) | `docs/reconstruction/raw/aa_00862860_FUN_00862860.md` |
| Annotated | `docs/reconstruction/raw/aa_00862860_FUN_00862860.annotated.md` |
| Scratch | `tmp/a_00862860.md` |

---

## AutoCore impact

- **Containers:** 12-byte vector push is a generic MSVC-ish helper — only port if a server structure needs the same layout; do not assume Element12 is float3.
- **Inventory UI / hardpoint drop:** client refuses hardpoint equip drop when active mode mismatches item class. Server equip validation remains authoritative; this is a **client UI gate** only.
- Align client automation / DevTool hardpoint actions with the class→mode table if simulating UI drops.

---

## This report

`docs/agents/task-dual-ab-00480ca0-00862860-w18o-report.md`
