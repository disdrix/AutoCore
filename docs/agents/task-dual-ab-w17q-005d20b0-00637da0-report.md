# Dual A/B report — W17-Q OWN-ONLY (`0x005d20b0`, `0x00637da0`)

**Date:** 2026-07-29  
**Agent:** W17-Q  
**Scope:** OWN VAs only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory`. No `disassemble_bytes`.  
**Program:** `autoassault.exe` base `0x400000`.

---

## Verdicts

| Unit | VA | Canonical | Verdict |
|------|-----|-----------|---------|
| `aa_005d20b0` | `0x005d20b0` | `Map_InsertNodeAndRebalance_IntKey` | **accept-with-gaps** — insert+RB core sealed |
| `aa_00637da0` | `0x00637da0` | `CVOGObjectiveRequirement_ctor` | **accept-with-gaps** — base ctor ABI/vfptr/parent sealed |

---

## `0x005d20b0` — Map_InsertNodeAndRebalance_IntKey

### Sealed facts

1. MSVC map/set **always-insert + RB rebalance** (not insert-or-find).  
2. Throws **`"map/set<T> too long"`** when `size > 0x1FFFFFFD` (`cmp [map+8], 0x1FFFFFFE`).  
3. Node via `FUN_006173a0`: **`operator_new(0x18)`**, key `+0x0C`, mapped `+0x10`, color **`+0x14`**, isnil **`+0x15`**.  
4. Map shell: head `+4`, size `+8`.  
5. ABI: **`__thiscall`**, **`RET 0x10`** (outNode, insertLeft, parent, value).  
6. Rotates: `FUN_004e22d0` left, `FUN_006753b0` right; one L-rotate **inlined**.  
7. **Sole static caller:** `Map_InsertOrFind_IntKey` @ `0x005d2360` (×2). Domain: NPC AI post-cast timer map.

### Gaps

- Product STL/RTTI name of map instantiation.  
- Formal rotate helper product names.  
- Runtime / bit-exact.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005d20b0_Map_InsertNodeAndRebalance_IntKey.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005d20b0_Map_InsertNodeAndRebalance_IntKey.md` |
| Function record | `docs/reconstruction/functions/aa_005d20b0_Map_InsertNodeAndRebalance_IntKey.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_InsertNodeAndRebalance_IntKey.cpp` |
| Raw | `docs/reconstruction/raw/aa_005d20b0_FUN_005d20b0.md` |
| Annotated | `docs/reconstruction/raw/aa_005d20b0_FUN_005d20b0.annotated.md` |

---

## `0x00637da0` — CVOGObjectiveRequirement_ctor

### Sealed facts

1. **Base ctor** for RTTI `.?AVCVOGObjectiveRequirement@@` @ `0x00afe9dc`.  
2. Bytes: `*this = 0x009e3bac`; `this+0x04 = parent`; **`RET 4`**; returns **this** in EAX.  
3. Leaf (no callees). No RequirementType write (`+0x0c` is subclass).  
4. **14** subclass ctor callers including Collect `0x00611690` and Deliver `0x00610bc0`.  
5. Temporary base vfptr — subclasses overwrite after return.

### Gaps

- Base vfptr slot English names.  
- Per-caller parent semantics.  
- Runtime / bit-exact.

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00637da0_CVOGObjectiveRequirement_ctor.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00637da0_CVOGObjectiveRequirement_ctor.md` |
| Function record | `docs/reconstruction/functions/aa_00637da0_CVOGObjectiveRequirement_ctor.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGObjectiveRequirement_ctor.cpp` |
| Raw | `docs/reconstruction/raw/aa_00637da0_FUN_00637da0.md` |
| Annotated | `docs/reconstruction/raw/aa_00637da0_FUN_00637da0.annotated.md` |

---

## AutoCore impact

- **Map insert core:** keep private under `Map_InsertOrFind_IntKey`; do not expose without walk; node layout 0x18 / color+0x14 must not be mixed with GhostNet 0x30 or staging 0x50 families.  
- **Requirement base:** all client objective-requirement subclasses share this base init; server/GLM mirrors only need type codes from subclass ctors (Collect=2, Deliver=3, …), not from this unit.

---

## Compliance

| Rule | Status |
|------|--------|
| OWN VAs only (`005d20b0`, `00637da0`) | Yes |
| Dual A + B per VA | Yes |
| raw + annotated + reconstructed-exact + function record | Yes |
| `decompile_function` + `read_memory` only | Yes |
| No `disassemble_bytes` | Yes |
| No Launcher | Yes |
| No parent ledger edits | Yes |
