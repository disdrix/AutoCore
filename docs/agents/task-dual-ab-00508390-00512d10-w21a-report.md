# Dual A/B report — W21-A OWN VAs `0x00508390`, `0x00512d10`

**Date:** 2026-07-29  
**Scope:** OWN ONLY VAs `0x00508390`, `0x00512d10`. Dual A/B + artifacts.  
**Agent:** W21-A  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00508390` `CVOGHBBase_dtor` | **accept** — 32-byte complete dtor body sealed (vtbl + optional list detach) |
| `aa_00512d10` `Object_ApplyFxWithTargetBind_Inferred` | **accept-with-gaps** — ABI/CF/dual resolve/TFID bind sealed; product name + nested attach residual |

---

## Sealed facts — `0x00508390`

1. **ABI:** `void __fastcall CVOGHBBase_dtor(void *thisHb /* ECX */)` — bare **`RET`**.
2. **Body:** `0x00508390`–`0x005083af` (**32 bytes**).
3. **Algorithm:** always `*this = PTR_FUN_009cdab0`; if `this+0x18` owner and `*(owner+0xB0)` listMgr non-null → `FUN_005085b0(listMgr, this)`.
4. **Decompiler caveat:** shows `FUN_005085b0(hb)` — machine ECX=listMgr (same as AttachOwner dual).
5. **Not scalar:** free lives in sibling `FUN_00508630`.
6. **Name:** `CVOGHBBase_dtor` — class RTTI family known; role sealed.

---

## Sealed facts — `0x00512d10`

1. **ABI:** `__thiscall`, **8 stack args**, **`ret 0x20`**.
2. **Body:** `0x00512d10`–`0x00512ead` (~413 B).
3. **Dual resolve:** full `FxCache_ApplyWithNfxEnsure` when `!skip && subsystem+0x6c live && !fx`; else light `FxCache_EnsureMasterAndResolve(...,1)`.
4. **Post-resolve:** `*fx |= 2`; optional target TFID (`+0x160` / nested `+0x164`) + offset `{0,0,u32float(param_7),0}` via `NDSpecialFX_SetTargetTfidAndOffset`; attach vtbl+0xf8; `FUN_004b7e50` zeros.
5. **Constant:** `DAT_00aaa5dc` = **2^32** float (`0x4f800000`).
6. **Dispatch:** DATA vtbl installs (no direct CALL callers).
7. **Name:** `Object_ApplyFxWithTargetBind_Inferred` — structural; no product string.

---

## Gaps

### `00508390`
1. PDB mangled dtor symbol.  
2. Runtime / differential — open.

### `00512d10`
1. Product method English.  
2. Nested vtbl+0xf8 full arg list residual.  
3. Flag bit 2 product meaning.  
4. Runtime / differential — open.

---

## Files

### `aa_00508390`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00508390_CVOGHBBase_dtor.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00508390_CVOGHBBase_dtor.md` |
| Function record | `docs/reconstruction/functions/aa_00508390_CVOGHBBase_dtor.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBBase_dtor.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_00508390.cpp` |
| Raw | `docs/reconstruction/raw/aa_00508390_FUN_00508390.md` |
| Annotated | `docs/reconstruction/raw/aa_00508390_FUN_00508390.annotated.md` |

### `aa_00512d10`

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00512d10_Object_ApplyFxWithTargetBind_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00512d10_Object_ApplyFxWithTargetBind_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_00512d10_Object_ApplyFxWithTargetBind_Inferred.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_ApplyFxWithTargetBind_Inferred.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_00512d10.cpp` |
| Raw | `docs/reconstruction/raw/aa_00512d10_FUN_00512d10.md` |
| Annotated | `docs/reconstruction/raw/aa_00512d10_FUN_00512d10.annotated.md` |

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00508390-00512d10-w21a-report.md` |

---

## AutoCore impact

- **HB dtor:** When tearing down client heartbeat objects, restore base vtbl and detach from `owner+0xB0` list manager; do **not** free in this unit (scalar sibling owns delete).
- **FX apply:** Port as vtbl method with dual resolve paths sharing the same post-bind/attach/post sequence; preserve unsigned float conversion for the single offset component and flag bit 2.
