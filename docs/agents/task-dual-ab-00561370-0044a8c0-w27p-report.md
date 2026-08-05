# Dual A/B report — W27-P OWN-ONLY (`0x00561370`, `0x0044a8c0`)

**Date:** 2026-07-29  
**Agent:** W27-P OWN-ONLY  
**Scope:** OWN ONLY VAs `0x00561370`, `0x0044a8c0`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` (+ `analyze_function_complete` / `get_function_by_address`). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave27_partition_map.md` → W27-P  

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_00561370` WorldMgr_RebindAllObjects_Inferred | **accept-with-gaps** — manager thiscall + 3-list unbind/bind/flag rebind sealed; list English + `0055f7a0` dual open |
| `aa_0044a8c0` Map_TreeInsertAndRebalance_Val12_EsiBuy_Inferred | **accept-with-gaps** — Val12 always-insert + RB rebalance; EDI map; ESI buy `0046c6c0`; `ret 0x10`; throw sealed |

---

## `aa_00561370` — WorldMgr_RebindAllObjects_Inferred

### Sealed facts

1. **Body:** `0x00561370`–`0x0056144a` exclusive (**218** B / `0xDA`); pad `CC` after bare `ret`.

2. **ABI:** `void __thiscall RebindAll(Manager* this)` — **ECX=manager**, **0** stack args, bare **`ret` (`c3`)**. Decompiler `__fastcall` label corrected by bytes (`mov esi,ecx`).

3. **Pass A:** vector `this+0x08` / count `+0x0c`. For each island, bodies at island `+0x3c` / count `+0x40`.

4. **Pass B:** vector `this+0x14` / count `+0x18` — same nested unbind/bind/flag.

5. **Per body:** `FUN_0055fbf0` (Unbind, W26-D) → `FUN_0055fa40` (Bind, W26-E) with **ECX=manager**; then `*(uint8_t*)(*(body+0x44)+0x28) = 1`.

6. **Pass C:** vector `this+0x120` / count `+0x124`; `FUN_0055f7a0(obj, flag=1)` with ECX=manager.

7. **Caller (1):** `FUN_00562530` @ xref `0x005625b3` — profile swap on `+0xd0` / links; calls this when `param_3 != 0`.

8. **Name:** structural `WorldMgr_RebindAllObjects_Inferred`. Not pair-flush (`0x00561320`) and not single-object RebindActivate (`0x00560e90`).

9. **Live ≡ raw** scaffold CF (2026-07-29 ≡ 2026-07-23 + W27-P append).

### Gaps

1. Product English for island list A vs B vs extras C.  
2. Full dual of `FUN_0055f7a0` (not OWN).  
3. Host `+0x28` product meaning.  
4. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00561370_WorldMgr_RebindAllObjects_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00561370_WorldMgr_RebindAllObjects_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00561370_WorldMgr_RebindAllObjects_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00561370_WorldMgr_RebindAllObjects_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00561370_WorldMgr_RebindAllObjects_Inferred.md` |
| Function Ghidra | `docs/reconstruction/functions/aa_00561370_FUN_00561370.md` |
| Clean | `docs/reconstruction/reconstructed-exact/WorldMgr_RebindAllObjects_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_00561370.cpp` |
| Raw | `docs/reconstruction/raw/aa_00561370_FUN_00561370.md` |
| Annotated | `docs/reconstruction/raw/aa_00561370_FUN_00561370.annotated.md` |

---

## `aa_0044a8c0` — Map_TreeInsertAndRebalance_Val12_EsiBuy_Inferred

### Sealed facts

1. **Body:** `0x0044a8c0`–`0x0044aa46` exclusive (**390** B / `0x186`); epilogue `add esp,0x50; ret 0x10`; pad `CC`.

2. **ABI:** map in **EDI** (caller `mov edi, ebx`); stack `(outIt*, addLeft, where*, value*)`; **`ret 0x10`**. No `mov edi,ecx` in body.

3. **Max size / throw:** `cmp [edi+8], 0x15555553` → `"map/set<T> too long"` @ `0x00a1530c` → `_CxxThrowException(..., DAT_00acc388)`.

4. **Buynode:** `FUN_0046c6c0(head, where, head, color=0)` with **ESI = value***; `operator_new(0x1c)`; copy **3 dwords**; isnil@`+0x19`=0; color@`+0x18`. **Not** `FUN_005ae220`.

5. **Link:** empty head → root/leftmost/rightmost; else left (`addLeft≠0`) or right; extremity updates on head.

6. **RB loop:** while parent red → recolor uncle or rotate; root painted black; `*outIt = n`.

7. **Rotates:** `FUN_00573170` Lrotate / `FUN_00418c10` Rrotate with **ECX=map** (W26-Q **accept** Val12).

8. **Caller (1 / 2 xrefs):** `FUN_0044a730` owns 2×uint key walk; always-insert only on miss.

9. **Twin (not equal):** `Map_TreeInsertAndRebalance_Val12` @ `0x0051c1c0` (ECX thiscall + `FUN_005ae220`).

10. **Name:** structural `Map_TreeInsertAndRebalance_Val12_EsiBuy_Inferred`.

11. **Live ≡ raw** scaffold CF; bytes seal 4th arg + EDI this.

### Gaps

1. Product/MSVC demangle for map type (2×uint key + dword payload).  
2. Full dual of `FUN_0046c6c0` / parent `FUN_0044a730` (not OWN).  
3. Buynode null OOM path.  
4. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0044a8c0_Map_TreeInsertAndRebalance_Val12_EsiBuy_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0044a8c0_Map_TreeInsertAndRebalance_Val12_EsiBuy_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0044a8c0_Map_TreeInsertAndRebalance_Val12_EsiBuy_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0044a8c0_Map_TreeInsertAndRebalance_Val12_EsiBuy_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_0044a8c0_Map_TreeInsertAndRebalance_Val12_EsiBuy_Inferred.md` |
| Function Ghidra | `docs/reconstruction/functions/aa_0044a8c0_FUN_0044a8c0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_TreeInsertAndRebalance_Val12_EsiBuy_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0044a8c0.cpp` |
| Raw | `docs/reconstruction/raw/aa_0044a8c0_FUN_0044a8c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0044a8c0_FUN_0044a8c0.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### WorldMgr_RebindAllObjects (`0x00561370`)

- Port as **full manager rebind** after profile swap — not a per-tick step and not pair-flush.
- Preserve **unbind → bind → host+0x28=1** on every body in both island vectors.
- Extras path must call the `0055f7a0` equivalent with **flag 1** (different from island unbind/bind).
- Nested unbind/bind require **manager as this** (sealed W26-D/E).

### Map_TreeInsertAndRebalance_Val12_EsiBuy (`0x0044a8c0`)

- Port as **always-insert + RB fixup** Val12; parent owns uniqueness.
- Do **not** alias to `0x0051c1c0` without matching **EDI-this + ESI-value buy** (`FUN_0046c6c0`).
- Max size threshold is **`0x15555553`**, same family as category-cooldown insert, not SkillElementTypeMap `0x1ffffffd`.
- Prefer shared L/R rotate helpers (`StdTree_Lrotate_Val12` / `StdTree_Rrotate_Val12`).

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory (+ analyze/meta). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` suffix used.  
- Avoided bare `undefined4` in clean (`uint32_t` / `uint8_t` / `int32_t`).

---

## Report path

`docs/agents/task-dual-ab-00561370-0044a8c0-w27p-report.md`
