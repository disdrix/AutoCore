# Dual A/B report — W24-H OWN VAs `0x00518ca0` + `0x0051d150`

**Date:** 2026-07-29  
**Agent:** W24-H (OWN-ONLY dual A/B)  
**Workspace:** `C:\Users\josh\Documents\GitHub\AutoCore`  
**Module / base:** `autoassault.exe` @ `0x400000`  
**Owned VAs only:** `0x00518ca0`, `0x0051d150`  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / callers / callees / xrefs). **No** `disassemble_bytes`.  
**Programs open:** `autoassault.exe` only (dual A/B = fidelity vs adversarial reviews).

---

## Verdicts

| Unit | Proposed name | Verdict |
|------|---------------|---------|
| `aa_00518ca0` @ `0x00518ca0` | `Skill_InsertActiveCastBinding_Inferred` | **accept-with-gaps** |
| `aa_0051d150` @ `0x0051d150` | `CNDHash_FreeBuckets` | **accept-with-gaps** |

Both A and B reviews agree per VA.

---

## VA1 — `0x00518ca0` Skill_InsertActiveCastBinding_Inferred

### Sealed facts

1. **Body:** `00518ca0`–`00518ce4` (**0x44** B). Prolog `sub esp,0x18`; epilogue `add esp,0x18; ret 0x14` (`83 C4 18 C2 14 00`).
2. **ABI:** MSVC **`__thiscall`**, **ECX = mapOwner**, **5 stack dwords** (skillId + TFID16 as 4×u32).
3. **Contract:** Pack local `{skillId, pad?, tfid[4]}` with **intentional unwritten +4**; `map = FUN_00518c20(owner)` (lazy `+0x68`); `FUN_004cbe20(map, &out, &local)` insert-or-find; discard result.
4. **Decompiler noise:** multi-arg `FUN_00518c20` is staged-push pattern for insert (same as Lookup/Clear duals).
5. **Family:** insert leg of active-cast binding triangle with leave-FUN getter `FUN_00518c20`, `Skill_LookupActiveCastBinding`, `Skill_ClearCastBindingAndMaybeRestartCd`.
6. **Callers:** sole site `Skill_HB_FireTail_FxTargetAndPeriodStamp` @ `0x00578c55` (vtbl+0x214 + flag `0x02`; skillId `HB+0x620`; TFID `HB+0x678`).
7. **Name:** role-inferred; reject `Named_CalleeOf_Skill_…frequency…` (parent string only).

### Gaps

- Product / PDB symbol  
- Map owner product type  
- Pad dword @+4 / node+0x14 readers  
- Duplicate-key keep-old vs other policy inside `FUN_004cbe20`  
- Runtime / bit-exact / diff  

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00518ca0_Skill_InsertActiveCastBinding_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00518ca0_Skill_InsertActiveCastBinding_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00518ca0_FUN_00518ca0.md` |
| Annotated | `docs/reconstruction/raw/aa_00518ca0_FUN_00518ca0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00518ca0.cpp` |
| Named | `docs/reconstruction/reconstructed-exact/Skill_InsertActiveCastBinding_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_00518ca0_Skill_InsertActiveCastBinding_Inferred.md` |
| Function record (FUN_) | `docs/reconstruction/functions/aa_00518ca0_FUN_00518ca0.md` |
| Review A | `docs/reconstruction/reviews/A_aa_00518ca0_Skill_InsertActiveCastBinding_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00518ca0_Skill_InsertActiveCastBinding_Inferred.md` |

---

## VA2 — `0x0051d150` CNDHash_FreeBuckets

### Sealed facts

1. **Body:** `0051d150`–`0051d183` (**0x33** B). `push esi; mov esi,ecx`; plain `ret`.
2. **ABI:** MSVC **`__thiscall`**, no stack args.
3. **Contract:** `count(+0xC)=0` → `FUN_0051bfb0` reclaim-to-freelist → if `buckets(+0x10)`: `free(*buckets)` slab + `delete[]` table + null.
4. **Alloc twin:** `FUN_0051ba40` — `new[]` pointer table + `malloc` sentinel slab (`009ce090`); explains free-through-first-entry.
5. **Not** full dtor: freelist `+0x20` and list ends untouched here.
6. **Callers:** `CNDHash_Recreate` @ `0x0051d256`; dtor `FUN_0051dfe0` @ `0x0051e02e` (vtbl `009ce1a0`).
7. **Name:** `CNDHash_FreeBuckets` (family role); closes Recreate residual “full destroy semantics of FUN_0051d150”. Reject VOG_DEBUG_STOP Named_CalleeOf as identity.

### Gaps

- Product / PDB FreeBuckets English  
- Full value-ownership matrix inside `FUN_0051bfb0`  
- Optional stamped rename if registry collides  
- Runtime / bit-exact / diff  

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_0051d150_CNDHash_FreeBuckets.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_0051d150_CNDHash_FreeBuckets.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0051d150_FUN_0051d150.md` |
| Annotated | `docs/reconstruction/raw/aa_0051d150_FUN_0051d150.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0051d150.cpp` |
| Named | `docs/reconstruction/reconstructed-exact/CNDHash_FreeBuckets.cpp` |
| Function record | `docs/reconstruction/functions/aa_0051d150_CNDHash_FreeBuckets.md` |
| Function record (FUN_) | `docs/reconstruction/functions/aa_0051d150_FUN_0051d150.md` |
| Review A | `docs/reconstruction/reviews/A_aa_0051d150_CNDHash_FreeBuckets.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0051d150_CNDHash_FreeBuckets.md` |

---

## AutoCore impact

- **`00518ca0`:** client skill HB fire-tail inserts sticky cast binding (skillId→TFID) used by Lookup/Clear/LocalCastValidate. Server ports that track active cast targets should mirror map semantics (int key, 16-byte TFID value, insert-or-find). Do not confuse with category-cooldown map at `+0x6c`.
- **`0051d150`:** medal (and same-family) CNDHash clear helper for Recreate/dtor. Port as: zero count → reclaim nodes (value-owning) → free slab + bucket table. Leave freelist teardown to dtor path.
- No server Launcher / live runtime work performed this pass.

---

## Compliance

| Rule | Status |
|---|---|
| OWN VAs only | **Yes** (`00518ca0`, `0051d150`) |
| decompile_function + read_memory | **Yes** |
| No disassemble_bytes | **Yes** |
| No Launcher | **Yes** |
| No parent ledger edits | **Yes** |
| raw / annotated / reconstructed-exact / functions / reviews A+B | **Yes** (both VAs) |
