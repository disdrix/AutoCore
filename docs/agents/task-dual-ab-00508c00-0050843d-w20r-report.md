# Dual A/B report — W20-R OWN `0x00508c00` + `0x0050843d`

**Date:** 2026-07-29  
**Scope:** OWN ONLY VAs `0x00508c00`, `0x0050843d`. Dual A/B + artifacts.  
**Agent:** W20-R  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00508c00` HandlerTable54_FindById6c | **accept** — **66-byte leaf sealed** (table `+0x54`, id `@+0x6c`, count `DAT_00d02988`, `ret 4`) |
| `aa_0050843d` CVOGHBBase_EndOrDestroy_HardListUnlink | **accept-with-gaps** — **39-byte SEH hard-tail sealed**; decomp soft-inline + `FUN_005085b0` arity fixed from bytes |

---

## Sealed facts — `0x00508c00`

1. **ABI:** `void* __thiscall HandlerTable54_FindById6c(registry*, int32_t id)` — ECX=registry, `[esp+4]=id`, **`ret 4`**.
2. **Body:** `0x00508c00`–`0x00508c41` (**66 bytes**). Leaf.
3. **Algorithm:** if `id != -1` and `DAT_00d02988 > 0`, scan `*(registry+0x54)[i]` until `*(entry+0x6c) == id`; return entry or 0.
4. **Family:** twins at `+0x44`/`00508ac0`, `+0x50`/`00508bb0`, `+0x58`/`00508c50` (equip subtype **0xa**).
5. **Callers:** equip hooks `FUN_004fe380`, loot type-prefix family, `FUN_00513580`.
6. **Name:** `HandlerTable54_FindById6c` — role-sealed **INFERRED**.
7. **Live decomp ≡ raw 2026-07-23**; no unaff residuals.

---

## Sealed facts — `0x0050843d`

1. **Role:** SEH continuation of parent **`CVOGHBBase_EndOrDestroy`** (`0x005083f0`), not a free-standing prologue function.
2. **Body (Ghidra):** `0x0050843d`–`0x00508463` (**39 bytes**).
3. **Incoming:** ESI=HB this, EBX=0, EBP=parent frame; **`[ebp+0xc]=flag_hard`**; SEH state → **3**.
4. **Hard path:** if flag_hard and `this+0x18` and `*(owner+0xb0)` → **`FUN_005085b0(listMgr, this)`** then **`FUN_0050846f`**.
5. **Soft path:** jump directly to **`FUN_0050846f`** (`this+0x20=1`, clear `+0x18`, ExceptionList / **ret 8** parent).
6. **Decomp gaps fixed:** `FUN_005085b0` is listMgr thiscall + HB key (not HB-only); soft stores attributed to `0050846f`.
7. **Sole caller:** `FUN_005083f0`.
8. **Name:** `CVOGHBBase_EndOrDestroy_HardListUnlink` — **INFERRED**.

---

## Gaps

1. Product/PDB English for registry/entry (`00508c00`) and owner/listMgr types (`0050843d`).
2. Dual of soft-tail `FUN_0050846f` if promoted as its own unit.
3. Runtime / bit-exact / differential — open.
4. Who populates `DAT_00d02988` and table vectors.

---

## Files

### `aa_00508c00` HandlerTable54_FindById6c

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00508c00_HandlerTable54_FindById6c.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00508c00_HandlerTable54_FindById6c.md` |
| Function record | `docs/reconstruction/functions/aa_00508c00_FUN_00508c00.md` |
| Clean | `docs/reconstruction/reconstructed-exact/HandlerTable54_FindById6c.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_00508c00.cpp` |
| Legacy alias | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Skill_GetModifierSkillID_passed_an_invalid_IDPre_00508c00.cpp` |
| Raw (authoritative + re-verify) | `docs/reconstruction/raw/aa_00508c00_FUN_00508c00.md` |
| Annotated | `docs/reconstruction/raw/aa_00508c00_FUN_00508c00.annotated.md` |
| Scratch | `tmp/a_00508c00.md` |

### `aa_0050843d` CVOGHBBase_EndOrDestroy_HardListUnlink

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0050843d_CVOGHBBase_EndOrDestroy_HardListUnlink.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0050843d_CVOGHBBase_EndOrDestroy_HardListUnlink.md` |
| Function record | `docs/reconstruction/functions/aa_0050843d_FUN_0050843d.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBBase_EndOrDestroy_HardListUnlink.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_0050843d.cpp` |
| Legacy alias | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_CVOGHBMissionPatrol_Fn6_0050843d.cpp` |
| Raw (authoritative + re-verify) | `docs/reconstruction/raw/aa_0050843d_FUN_0050843d.md` |
| Annotated | `docs/reconstruction/raw/aa_0050843d_FUN_0050843d.annotated.md` |
| Scratch | `tmp/a_0050843d.md` |

| Report | `docs/agents/task-dual-ab-00508c00-0050843d-w20r-report.md` |

---

## AutoCore impact

- **HandlerTable54_FindById6c:** port as linear scan over `registry+0x54` with global count `DAT_00d02988` and id at **`entry+0x6c`**. Keep distinct from **`+0x58`/`00508c50`** (subtype 0xa). Id **`-1`** must short-circuit to null.
- **EndOrDestroy hard tail:** when porting HB teardown, hard flag must call list remove as **`RemoveByKey(listMgr, hb)`** with listMgr from **`*(owner+0xb0)`**, then always soft-mark dead. Do not treat `FUN_0050843d` as a normal thiscall export.
