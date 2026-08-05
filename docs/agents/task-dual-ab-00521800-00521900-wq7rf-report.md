# Dual A/B report — WQ7R-F OWN `aa_00521800` + `aa_00521900`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual WQ7R-F  
**Scope:** VAs `0x00521800`, `0x00521900` only. Dual A/B + trio artifacts.  
**Role hint:** Mission name/format helpers (callees of `FUN_005465c0` mission token expander).  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` + `read_memory` + `get_function_by_address` + `get_function_callers` + callee decompile. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq007_residual_partition_map.md` (WQ7R-F).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00521800` Character_GetRaceDisplayName_Inferred | **accept-with-gaps** — race map Human/Mutant/Biomek/Unknown + ECX-this + char\* ring sealed; product method English + deep this-type open |
| `aa_00521900` Character_GetClassDisplayName_Inferred | **accept-with-gaps** — class@+0x531 + race@+0x532 + 2-arg `FUN_0051f940` + ring sealed; class English table unowned |

**Terminal coverage:** false (no Launcher / runtime / bit-exact Confirmed).

---

## Shared context (parent, not owned)

`FUN_005465c0` expands mission/UI template tokens in a `std::string`:

| Token | Replacement source |
|-------|-------------------|
| `[$name]` | vtbl call `+0x160` |
| `[$class]` | **`FUN_00521900`** (owned) |
| `[$race]` | **`FUN_00521800`** (owned) |
| `[$credits]` | i64 delta `@this+0x720`… |
| `[$level]` | vtbl call `+0x27c` |

Both owned units share the nested character blob path:

```
blob = *( *( *( *(this+4)+4 ) + this + 0xac ) + 0x3c )
```

| Field | Offset on blob |
|-------|----------------|
| Class id | `+0x531` (uint8) |
| Race id | `+0x532` (uint8) |

---

## VA `0x00521800` — sealed facts

1. **Body:** `0x00521800`–`0x00521879` exclusive (**121 B** / `0x79`; pad `CC`).
2. **ABI:** **ECX = this**; plain **`RET`** (`C3`); returns **char\*** from `FUN_007a6de0` ring.
3. **Semantics:** Race display name for mission/UI:
   - Load `*(uint8*)(blob + 0x532)`.
   - Cascade: **0 → Human**, **1 → Mutant**, **2 → Biomek**, else **Unknown**.
   - Copy via `FUN_007a69d0` (TLS table*) + `FUN_007a6de0(src, -1)`.
4. **Product strings (read_memory):**
   - `"Human"` @ `0x00a40958`
   - `"Mutant"` @ `0x00a40950`
   - `"Biomek"` @ `0x00a40948`
   - `"Unknown"` @ `0x00a37c4c`
5. **Classification:** pure formatter leaf (no state write beyond TLS ring).
6. **Callers (3):** `FUN_005465c0` (`[$race]`); `FUN_005792d0` cases 3/4; `FUN_0092e710` Level/Race/Class line.
7. **Callees:** `FUN_007a69d0`, `FUN_007a6de0`.
8. **Name:** `Character_GetRaceDisplayName_Inferred` (Ghidra `FUN_00521800`; **Inferred** from product race strings + `[$race]` caller). **Reject** scaffold `Named_CalleeOf_…UpdateMissi_00521800`.
9. **Decompile vs bytes:** CF ≡ raw map; **bytes win** on char\* return and push→`007a6de0` arg ownership.  
   Full hex: raw WQ7R-F append (121 B body).

### Gaps

- Product/PDB method English.  
- Full C++ type of this / intermediate pointers.  
- Cross-link of race enum to mission-def race `+0x90` (ushort) without extra proof.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00521800_Character_GetRaceDisplayName_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00521800_Character_GetRaceDisplayName_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00521800_FUN_00521800.md` |
| Annotated | `docs/reconstruction/raw/aa_00521800_FUN_00521800.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_GetRaceDisplayName_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00521800.cpp` |
| Function | `docs/reconstruction/functions/aa_00521800_FUN_00521800.md` |
| Function named | `docs/reconstruction/functions/aa_00521800_Character_GetRaceDisplayName_Inferred.md` |

---

## VA `0x00521900` — sealed facts

1. **Body:** `0x00521900`–`0x0052193b` exclusive (**59 B** / `0x3b`; pad `CC`).
2. **ABI:** **ECX = this**; plain **`RET`**; returns **char\*** ring.
3. **Semantics:** Class display name for mission/UI:
   - Same nested blob as race helper.
   - `classId = *(uint8*)(blob+0x531)`, `raceId = *(uint8*)(blob+0x532)`.
   - `name = FUN_0051f940(classId, raceId)` — **cdecl, 2 args** (`add esp,8`).
   - Ring copy-out identical to race helper.
4. **Supporting class table** (unowned `FUN_0051f940` decompile — **not dual-owned here**):

| classId | race0 | race1 | race2 | else |
|---------|-------|-------|-------|------|
| 0 | Commando | Champion | Terminator | Commando |
| 1 | Engineer | Shaman | Constructor | Engineer |
| 2 | Lieutenant | Archon | MasterMind | Officer |
| 3 | Bounty Hunter | Avenger | Agent | Ranger |
| other | Unknown | | | |

5. **Classification:** thin wrapper worker.
6. **Callers (4):** `FUN_005465c0` (`[$class]`); `FUN_005792d0` cases 2/6; `FUN_0092e5d0`; `FUN_0092e710`.
7. **Callees:** `FUN_0051f940` (**unowned**), `FUN_007a69d0`, `FUN_007a6de0`.
8. **Name:** `Character_GetClassDisplayName_Inferred` (Ghidra `FUN_00521900`; **Inferred** from `[$class]` + class×race lookup). **Reject** scaffold `Named_CalleeOf_…UpdateMissi_00521900`.
9. **Decompile vs bytes:** CF ≡ raw; **bytes win** — phantom third `0xffffffff` on `FUN_0051f940` is **`FUN_007a6de0` length**, not a third lookup arg.  
   Full hex: raw WQ7R-F append (59 B body).

### Gaps

- Product/PDB method English.  
- Dual seal of class leaf `FUN_0051f940` @ `0x0051f940`.  
- Deep Character / blob C++ types.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00521900_Character_GetClassDisplayName_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00521900_Character_GetClassDisplayName_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00521900_FUN_00521900.md` |
| Annotated | `docs/reconstruction/raw/aa_00521900_FUN_00521900.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Character_GetClassDisplayName_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00521900.cpp` |
| Function | `docs/reconstruction/functions/aa_00521900_FUN_00521900.md` |
| Function named | `docs/reconstruction/functions/aa_00521900_Character_GetClassDisplayName_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00521800` | Port as **thiscall** race display-name getter: map race byte 0/1/2 → Human/Mutant/Biomek else Unknown. Return **ephemeral** string (copy if retaining). Wire mission templates: replace `[$race]`. |
| `00521900` | Port as **thiscall** class display-name getter: `(classId, raceId)` table lookup then ephemeral string. Wire `[$class]`. **Do not** invent a third arg to the lookup leaf. Dual `FUN_0051f940` before treating class English as sealed-owned. |
| Shared | Character sheet offsets **class +0x531 / race +0x532** on the nested blob; same chain used by both helpers and UI Level/Race/Class formatters. |

---

## Residual for parent merge (not edited here)

- Count +2 dual unique when parent merges WQ7R-F.
- Optional follow-up dual: `FUN_0051f940` (class×race name leaf).
- Optional follow-up dual: parent `FUN_005465c0` full token expander (owned by WQ7R-D per partition).
