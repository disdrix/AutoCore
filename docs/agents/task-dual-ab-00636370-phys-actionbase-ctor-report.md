# Dual A/B report — `aa_00636370` Phys_ActionBase_ctor

**Date:** 2026-07-29  
**Agent:** W17-P OWN-ONLY  
**Scope:** OWN ONLY VA `0x00636370`. Dual A/B + artifacts. Seal dual-vtbl action base ctor.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER.  
**Ghidra:** `decompile_function` + `read_memory` only. No `disassemble_bytes`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00636370` Phys_ActionBase_ctor | **accept-with-gaps** — **CF/bytes/host-link sealed; product name + host type residual** |

---

## Sealed facts

1. **ABI:** `__thiscall` — **ECX = action**, one stack arg = **host** (nullable), epilogue **`ret 4`**, returns **this** in EAX. Body **`0x00636370`–`0x006363b2`**.

2. **Refcount:** `*(u16*)(this+6) = 1`. Does **not** write `+4` (size/flags left to allocator / caller).

3. **Dual vtables (MSVC MI order):**
   - Intermediate secondary `this+8 = PTR_LAB_009e3a68` (`0x009e3a68`)
   - Clear `+0xc`, `+0x14`
   - Primary `*this = PTR_FUN_009e39f4` (`0x009e39f4`)
   - Final secondary `this+8 = PTR_LAB_009e5e78` (`0x009e5e78`)

4. **Host link:** `this+0x18 = host`. If host ≠ 0:
   - **`FUN_00507290`**: thiscall **ECX=host**, stack **action*** — append into growable list at **host+0x94** (count +0x98, cap +0x9c)
   - **`*(u16*)(host+6) += 1`** host addref  
   Decompiler display `FUN_00507290(param_1)` is **incomplete** — machine seal wins.

5. **Callers (exactly 3):**
   - `VehicleAction_ctor` `0x00597f90`
   - `FUN_00600140` (Phys_FlipperConstraint_ctor)
   - `FUN_00658bf0`  
   Each overwrites class vtables after return.

6. **Name:** `Phys_ActionBase_ctor` (descriptive). Havok `hkAction` product string **not** in body — inferred from layout + physics plates only. Parent-seed CVOGHBAIDriver alias is noise.

7. **Live decompile ≡ 2026-07-23 raw** (append-only re-verify recorded).

---

## Gaps

1. Product/PDB English (hkAction vs custom).  
2. Unified host C++ type across callers.  
3. Field names for zeroed `+0xc` / `+0x14`.  
4. Sibling dtor `FUN_00636290` dual (not owned).  
5. Host-vector helper `FUN_00507290` dual (not owned).  
6. Runtime / bit-exact / differential — open.

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00636370_Phys_ActionBase_ctor.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00636370_Phys_ActionBase_ctor.md` |
| Function record | `docs/reconstruction/functions/aa_00636370_Phys_ActionBase_ctor.md` |
| Function record (FUN alias) | `docs/reconstruction/functions/aa_00636370_FUN_00636370.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Phys_ActionBase_ctor.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00636370.cpp` |
| Raw (authoritative + live append) | `docs/reconstruction/raw/aa_00636370_FUN_00636370.md` |
| Annotated | `docs/reconstruction/raw/aa_00636370_FUN_00636370.annotated.md` |
| This report | `docs/agents/task-dual-ab-00636370-phys-actionbase-ctor-report.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

- Port VehicleAction / flipper / related actions with a **shared base ctor** establishing dual vtbls + refcount before class init.
- Optional host link: when present, **register action on host list** and **addref host** — do not skip if mirroring client ownership.
- Do **not** conflate this host-list append with world/island register `FUN_0055fe50` used after `Vehicle_createVehicleAction` — different path.
- Correct any decompiler-driven ports that called the append helper with the **action** as `this`.
