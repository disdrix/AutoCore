# Dual A/B report — W29-L OWN `aa_005ccff0` + `aa_004e2940`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W29-L  
**Scope:** VAs `0x005ccff0`, `0x004e2940` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `get_function_by_address` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave29_partition_map.md`

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005ccff0` CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred | **accept-with-gaps** — thiscall/plain ret + TFID resolve/mode0/promote/LinkedDeath CF sealed; product vtbl English residual |
| `aa_004e2940` StdMap_FreeSubtree_Val12 | **accept** — Val12 isnil@+0x19 free-subtree; left-walk sealed by bytes; closes W28-P free residual |

---

## VA `0x005ccff0` — sealed facts

1. **Body:** `0x005ccff0`–`0x005cd220` exclusive (**560 B / `0x230`**). Ghidra listed end `005cd21f`; next fn `FUN_005cd220`.
2. **ABI:** **thiscall**; ECX = HBAI; **0** stack formals; epilogue `ADD ESP,0x18; RET` (`C3`).
3. **Semantics:** Copy TFID from `owner(this+0x64)+0x228`; resolve-manager ECX (`MI+0xA8`/`+0xE4E8`) + `Object_ResolveFromTFID` @ `0x004bb950`. Miss → `Object_SetMode278_SelectFromTFID228_Inferred(owner,0)` @ `0x004c3c80`. Hit: prefer `resolved+0xA0` via owner `vtbl+0x298` + candidate `vtbl+0x1c8` → `Object_SetSelectedTarget` @ `0x005172d0`. Else optional `FUN_004c8970`; else locked-list walk (`FUN_004294f0` + `LockedList_TryAdvanceIterator` `0x004022a0`) for type-2 `CVOGHBLinkedDeath` partner promote.
4. **Classification:** worker (multiple sealed callees + virtuals + RTTI).
5. **Callers (1):** `CVOGHBAICreatureBase_OnHeartBeat` @ `0x005d0704` (engage when no target or mode==1).
6. **Name:** `CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred` (Ghidra `FUN_005ccff0`); `_Inferred` for product English residual on vtbl/mode.
7. **Decompile ≡ CF** for main paths; residuals closed: manager ECX from bytes; SetSelectedTarget arity **1** (not decompiler `unaff_EDI`).

### Gaps

- Product English for mode `+0x278` and vtbl slots `+0x298` / `+0x1c8` / `+0x214` / `+0x19c`.  
- Product role of `FUN_004c8970`.  
- Runtime / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005ccff0_CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005ccff0_CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005ccff0_FUN_005ccff0.md` |
| Annotated | `docs/reconstruction/raw/aa_005ccff0_FUN_005ccff0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005ccff0.cpp` |
| Function | `docs/reconstruction/functions/aa_005ccff0_FUN_005ccff0.md` |
| Function named | `docs/reconstruction/functions/aa_005ccff0_CVOGHBAI_EngageSelectTargetFromOwnerTFID_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_005ccff0.md` |

---

## VA `0x004e2940` — sealed facts

1. **Body:** `0x004e2940`–`0x004e2975` exclusive (**53 B**); pad `CC` after **`RET 4`**. Ghidra listed end `004e2974`.
2. **ABI:** stack `node*`; **`ret 4`** (`C2 04 00`). ECX saved/threaded on recursion but **unused for loads** (same as isnil15 peer).
3. **Semantics:** MSVC `_Tree` **subtree free** Val12: if isnil@+0x19 return; else free **right@+8** recursively, `operator_delete` self, walk **left@+0** until isnil.
4. **Callees:** self; `operator_delete` @ `0x00489222`.
5. **Callers:** `StdMap_EraseRange_Val12` (`0x004e5120` @ `004e513c`); self; additional sites `004d968e`, `004d96de` (no named enclosing function in Ghidra).
6. **Node:** Val12 — left@0 parent@4 right@8; **isnil@+0x19**. Peer isnil@+0x15: `StdMap_FreeSubtree_Isnil15_Inferred` (`0x004ba770`).
7. **Name:** `StdMap_FreeSubtree_Val12` (Ghidra `FUN_004e2940`).
8. **Decompile ≢ full CF** — false-noreturn + missing left walk; **bytes authoritative**. Clean restores left walk.

### Gaps

- Product / mangled map type name.  
- Named owners of orphan xrefs `004d968e` / `004d96de`.  
- Runtime / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004e2940_StdMap_FreeSubtree_Val12.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004e2940_StdMap_FreeSubtree_Val12.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004e2940_FUN_004e2940.md` |
| Annotated | `docs/reconstruction/raw/aa_004e2940_FUN_004e2940.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_FreeSubtree_Val12.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004e2940.cpp` |
| Function | `docs/reconstruction/functions/aa_004e2940_FUN_004e2940.md` |
| Function named | `docs/reconstruction/functions/aa_004e2940_StdMap_FreeSubtree_Val12.md` |
| Scratch | `docs/reconstruction/tmp/a_004e2940.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005ccff0` | Engage retarget: resolve owner TFID first; fail clears **mode 0** only (no target). Prefer **`resolved+0xA0`** under `vtbl+0x298`/`+0x1c8`. Fallback LinkedDeath partner via locked list type **2**. Preserve plain ret / thiscall. |
| `004e2940` | Port Val12 **subtree free** with isnil@+0x19, right-recurse + left-walk. **Do not** use isnil@+0x15 free (`004ba770`) offsets. Callers must not expect value dtors inside this free. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory (+ function bounds / xrefs). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates: TFID/mode/vtbl offsets from bytes; callees from dual-sealed VAs; `_Inferred` only where product English residual.
