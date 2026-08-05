# Dual A/B report — W20-H OWN-ONLY (`0x004e24d0`, `0x0056c0a0`)

**Date:** 2026-07-29  
**Agent:** W20-H OWN-ONLY  
**Scope:** OWN ONLY VAs `0x004e24d0`, `0x0056c0a0`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / xrefs / complete analysis). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_004e24d0` Mem_MoveDwordRange_ToExclusiveEnd | **accept** — **cdecl exclusive-end dword memmove sealed; distinct from 004e2e80** |
| `aa_0056c0a0` Weapon_SelectMultiTargets_Inferred | **accept** — **thiscall ret8 multi-target select CF + Weaopn string + vtable sealed** |

---

## `aa_004e24d0` — Mem_MoveDwordRange_ToExclusiveEnd

### Sealed facts

1. **Body:** `0x004e24d0`–`0x004e24f3` exclusive (**35** B). Final bare **`c3`**; following `cc` pad.

2. **ABI:** three stack formals; **cdecl bare `ret`**. **Not** stdcall `ret 0xC` (sibling `aa_004e2e80`).

3. **Algorithm:**
   ```
   count = (srcEnd - srcBegin) >> 2;
   size  = count * 4;          // double ADD, not LEA
   memmove(destEndExcl - size, srcBegin, size);
   ```

4. **Callees:** CRT `memmove` only via IAT `[0x009c652c]`.

5. **Callers:** 25 code xrefs — vector insert/grow family (`FUN_004073a0`, `FUN_004507a0`, `FUN_004e39d0`, `FUN_005064e0`, `FUN_00539810`, …).

6. **Distinct from** `aa_004e2e80` (`Mem_MoveDwordRange_ReturnEnd`: dest=`param3` forward, return end, `ret 0xC`) and `aa_00506430` (same forward pattern).

7. **Name:** structural `Mem_MoveDwordRange_ToExclusiveEnd`. Auto-seed `Named_CalleeOf_…_CVOGSectorMap_AddCharacter` is **misleading**.

### Gaps

1. Product/PDB symbol spelling.  
2. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_004e24d0_Mem_MoveDwordRange_ToExclusiveEnd.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_004e24d0_Mem_MoveDwordRange_ToExclusiveEnd.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004e24d0_Mem_MoveDwordRange_ToExclusiveEnd.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004e24d0_Mem_MoveDwordRange_ToExclusiveEnd.md` |
| Function record | `docs/reconstruction/functions/aa_004e24d0_Mem_MoveDwordRange_ToExclusiveEnd.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_004e24d0_FUN_004e24d0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Mem_MoveDwordRange_ToExclusiveEnd.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_004e24d0.cpp` |
| Raw | `docs/reconstruction/raw/aa_004e24d0_FUN_004e24d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004e24d0_FUN_004e24d0.annotated.md` |

---

## `aa_0056c0a0` — Weapon_SelectMultiTargets_Inferred

### Sealed facts

1. **Body:** `0x0056c0a0`–`0x0056c856` exclusive (**1974** B / `0x7B6`). Final **`c2 08 00`** (`ret 8`); following `cc` pad.

2. **ABI:** **`__thiscall`** — ECX=weapon*; stack: locked-list*, preferred-target*. **`ret 8`**.

3. **Return:** **`0xffffffff` (−1)** on early fail; else selected-target **count**.

4. **Fail gates:** owner null/invalid (`vtbl+0x198`); null locked list; null list host `@this+0x13c`; owner physics missing (`vtbl+0x1c8`, field+8). Optional `FUN_0056bf70` clear on first gate.

5. **Max targets:** `FUN_0056ac50`; if `>100` log severity 0 `"WARNING Weaopn <%s> has invalid # of maxtargets(%d) set!"` @ `0x009d2fcc` (product typo **Weaopn**); force 100.

6. **Aim basis:** type `0xE` hardpoint path (`004f8c50`/`004e8bf0`/normalize) vs default `004e8a40`.

7. **Preferred target:** if valid → `CVOGPhysicsUtils_FindDistanceToTarget` (`004e9aa0`); non-zero distance seeds slot0 via `FUN_005770d0`.

8. **Fill:** locked-list walk (`004294f0`/`004022a0`); filters (alive, `vtbl+0x298`, flag bits, `005134e0`, optional `0040b1b0`); distance insert/append into ≤maxTargets slots (init best-dist sentinel **2560.0f** @ `0x009d2fc8`).

9. **Commit:** merge secondary list fields; `FUN_0056f0b0`; `FUN_0056eca0` each slot into host `@this+0x13c`; free leftovers; return count.

10. **Callers:** **none direct** — DATA-only vtable slots `@ 0x009d3330` and `@ 0x009ddad8`. Neighbor slot0: `Weapon_TryFireResolveHits` (`0x0056c860`) @ `0x009d3320`.

11. **Not this VA:** TryFire (`0056c860`); area-style `0056d600`/`0056db30` (GetObjectsInArea ABI).

12. **Name:** structural `Weapon_SelectMultiTargets_Inferred` (product method English residual).

### Gaps

1. Product/RTTI class + exact virtual slot English.  
2. Complete filter-bit dictionary.  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_0056c0a0_Weapon_SelectMultiTargets_Inferred.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_0056c0a0_Weapon_SelectMultiTargets_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0056c0a0_Weapon_SelectMultiTargets_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0056c0a0_Weapon_SelectMultiTargets_Inferred.md` |
| Function record | `docs/reconstruction/functions/aa_0056c0a0_Weapon_SelectMultiTargets_Inferred.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_0056c0a0_FUN_0056c0a0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Weapon_SelectMultiTargets_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0056c0a0.cpp` |
| Raw | `docs/reconstruction/raw/aa_0056c0a0_FUN_0056c0a0.md` |
| Annotated | `docs/reconstruction/raw/aa_0056c0a0_FUN_0056c0a0.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### Mem_MoveDwordRange_ToExclusiveEnd (`0x004e24d0`)

- Port as **vector tail right-shift** helper: dest = exclusiveEnd − size.
- Do **not** substitute `Mem_MoveDwordRange_ReturnEnd` (`0x004e2e80`) — different dest, return, and **stdcall**.
- Keep dword stride (`>>2` / `*4`); bare cdecl ret.

### Weapon_SelectMultiTargets_Inferred (`0x0056c0a0`)

- Port as **weapon multi-target list fill**, not fire/damage.
- Preserve **−1 fail** vs **count success**; maxTargets via def helper + clamp 100.
- Range via **FindDistanceToTarget**; preferred target optional seed.
- Virtual entry only — wire via weapon vtable, not direct call invent.
- Distinct from TryFire (`0056c860`) and area-gather siblings.

---

## This report

`docs/agents/task-dual-ab-004e24d0-0056c0a0-w20h-report.md`
