# Dual A/B report — WQ9R-A OWN-ONLY (`0x0051b720`, `0x005749d0`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9R-A**  
**Scope:** VAs `0x0051b720`, `0x005749d0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `get_function_callers` + `read_memory` (+ xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_residual_partition_map.md` → **WQ9R-A**.  
**Work item:** WQ-009 skills residual (priority 93).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0051b720` Rng_CopyUnitTableWindow_Inferred | **accept-with-gaps** — CF/ABI/wrap/copy/cursor++/return-seed/2 callers sealed; product English open |
| `aa_005749d0` VehicleCrew_ContainsMember_Inferred | **accept-with-gaps** — CF/ABI/4×0x10 table/AL bool/mode-0xb this sealed; product English open |

---

## VA `0x0051b720` — sealed facts

1. **Body:** `0x0051b720`–`0x0051b768` exclusive (**72 B** / `0x48`). Final **`C2 08 00`**; pad `CC`.
2. **ABI:** **`__thiscall`**; ECX = RNG host*; stack `nWords`, `dst*`; **RET 8**; **EAX = pre-increment cursor** (decompiler `void` is wrong).
3. **Semantics:** caller-buffer window sampler on global RNG unit table:
   - If `cursor + nWords > 0xFFFFF` → `cursor = 0`.
   - Source = `*(this+0x08) + cursor*2` (ushort index).
   - Copy `nWords*2` bytes (`rep movsd` + residual `rep movsb`) → `dst`.
   - `cursor += 1` (**not** `+= nWords`) — preserve sliding-window oddity.
   - Return old cursor (used as **`lDiceSeed`** / `packet+0x3C`).
4. **`this`:** always `CVOGReaction_RandomUnitScalar()` → `&DAT_00d20c1c` (`mov ecx,eax` after 0-arg getter; stack args reserved for this call).
5. **Classification:** leaf worker (RNG stream helper).
6. **Callers (2):**
   - `Skill_ApplyStatusEffectLocal` @ `0x0051aafb` — sim re-roll when `world+0x7e != 0`; `push buf; push 600; …; mov [pkt+0x3C],eax`.
   - `FUN_0061fdf0` @ `0x0061ffdc` — same (600, buf); return discarded; buffer later reused as TFID out-list.
7. **Xrefs:** 2.
8. **Sibling:** `Rng_CloneSeededTable_Inferred` (`0x0058ab60`) = alloc `0x4B0` + force seed + fixed-600 inline same algorithm. Single-word unit float: `FUN_007a4170`.
9. **Name:** `Rng_CopyUnitTableWindow_Inferred` (Ghidra `FUN_0051b720`). Product demangle open → `_Inferred`.
10. **Decompile ≡ raw CF**; ABI/return sealed by `read_memory` + call-site store.

### Gaps

- Product English / MSVC demangle for RNG host method.  
- Whether ApplyStatusEffectLocal stack buffer is ever read after the call (seed path sealed).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0051b720_Rng_CopyUnitTableWindow_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0051b720_Rng_CopyUnitTableWindow_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0051b720_FUN_0051b720.md` |
| Annotated | `docs/reconstruction/raw/aa_0051b720_FUN_0051b720.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Rng_CopyUnitTableWindow_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0051b720.cpp` |
| Function | `docs/reconstruction/functions/aa_0051b720_FUN_0051b720.md` |
| Function named | `docs/reconstruction/functions/aa_0051b720_Rng_CopyUnitTableWindow_Inferred.md` |

---

## VA `0x005749d0` — sealed facts

1. **Body:** `0x005749d0`–`0x00574a2e` exclusive (**94 B** / `0x5E`); pad `CC`.
2. **ABI:** **`__thiscall`**; ECX = crew-table host*; stack `candidate*`; **RET 4**; **AL bool** `0`/`1` (decompiler `uint3`/`CONCAT31` noise rejected).
3. **Semantics:** 4-slot crew roster membership:
   - Null candidate → 0.
   - COID lo/hi from candidate via SharedBase offBase: `*(candidate+4)→*(+4)` then `offBase+obj+0x164/0x168`.
   - Scan `this+0x198`, slots `i=0..3`, stride **`0x10`**: match `slot[0]/`slot[4]` → 1; else 0.
4. **Classification:** leaf worker (crew membership predicate).
5. **Callers (8):** `Skill_FilterTargetForResolveList_Inferred`, `FUN_0058a810`, `FUN_0058cd60`, `FUN_005755b0`, `Client_RecvDestroyObject`, `FUN_007ffef0`, `FUN_0082fb30`, `FUN_00930fc0`.
6. **Xrefs:** 14 call sites.
7. **Mode 0xb:** gather helper loads ECX from **`vehicle+0xCB0`** (`mov ecx,[edi+0xCB0]`); same-vehicle short-circuit via `vtbl+0x210` first.
8. **Twins:** insert `FUN_005755b0` (free slot / `0xFFFFFFFF` sentinel); clear `FUN_00574a90`.
9. **Name:** `VehicleCrew_ContainsMember_Inferred` (Ghidra `FUN_005749d0`). Product demangle open → `_Inferred`. Prior gather dual already labeled role “same vehicle / plant crew.”
10. **Decompile ≡ raw CF**; bool return sealed by epilogue bytes.

### Gaps

- Product English / MSVC demangle for crew-host class.  
- Slot bytes beyond COID pair (writer stores object* at `(slot+0x1A)*0x10`).  
- Whether members are always vehicle vs character COIDs.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005749d0_VehicleCrew_ContainsMember_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005749d0_VehicleCrew_ContainsMember_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005749d0_FUN_005749d0.md` |
| Annotated | `docs/reconstruction/raw/aa_005749d0_FUN_005749d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VehicleCrew_ContainsMember_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005749d0.cpp` |
| Function | `docs/reconstruction/functions/aa_005749d0_FUN_005749d0.md` |
| Function named | `docs/reconstruction/functions/aa_005749d0_VehicleCrew_ContainsMember_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0051b720` | Port as **RNG host method** on global singleton (`DAT_00d20c1c`), not a free function. Copy `nWords` ushorts from `table[cursor]`; wrap at `0xFFFFF`; advance cursor by **1**; return old cursor as dice seed. Skill sim path: when `world+0x7e`, re-roll `SkillStatusEffect+0x3C` with `nWords=600`. Keep distinct from `Rng_CloneSeededTable` (heap + force seed) and `FUN_007a4170` (single unit float). |
| `005749d0` | Port as **crew-host membership** on object with `+0x198` table (4×0x10). Compare COID lo/hi only. Mode 0xb: same `vtbl+0x210` vehicle OR `Contains(*(veh+0xCB0), other)`. Pair with insert `005755b0` / clear `00574a90`. Do **not** treat as faction (`vtbl+0x298`). |
| Pair with | `Skill_ApplyStatusEffectLocal` (`0x0051aa00`), `Rng_CloneSeededTable_Inferred` (`0x0058ab60`), `CVOGReaction_RandomUnitScalar` (`0x007a4330`), `FUN_0058a810` / `Skill_GatherTargetsInArea` mode 0xb, `Skill_FilterTargetForResolveList_Inferred` (`0x0054ff00`). |

---

## Process

- OWN VAs only (`0x0051b720`, `0x005749d0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra iVar blank-line paste).  
- Odd behavior preserved: cursor `+1` after large window; decompiler bool/void artifacts corrected from bytes.  
- `_Inferred` where English unproven; Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
