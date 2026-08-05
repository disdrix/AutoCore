# Dual A/B report — WQ7R-D OWN `aa_005465c0` + `aa_00411180`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual WQ7R-D  
**Scope:** VAs `0x005465c0`, `0x00411180` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + `get_assembly_context` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq007_residual_partition_map.md` (WQ7R-D).  
**Role hint:** Mission string/state helpers.  
**Terminal coverage claimed:** **false** (agent report; no parent ledger update).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005465c0` Mission_ExpandPlayerTokenPlaceholders_Inferred | **accept-with-gaps** — cdecl 5-token expand; credits i64 delta + vcalls sealed; getter product English open |
| `aa_00411180` StdVector_PushBack_Dword_EaxVec_EsiVal_Inferred | **accept-with-gaps** — EAX=vec / ESI=value / bare RET dword push; grow `0040b6d0` residual (WQ7R-E) |

---

## VA `0x005465c0` — sealed facts

1. **Body:** `0x005465c0`–`0x005467f5` (Ghidra); measured **566 B** / `0x236` incl. final `C3`; pad `CC` follows.
2. **ABI:** **cdecl** `(Character* character, std::string* text)`; callers `PUSH; PUSH; CALL; ADD ESP,8`. Image: ESI=text, EDI=character after prologue.
3. **Semantics:** Replace-all loops for five **literal** player tokens in order:
   | Token | VA | Len | Source |
   |-------|-----|-----|--------|
   | `[$name]` | `0x009d0620` | 7 | MI vcall `vtbl+0x160` |
   | `[$class]` | `0x009d0614` | 8 | `FUN_00521900` (ECX=char) |
   | `[$race]` | `0x009d060c` | 7 | `FUN_00521800` (ECX=char) |
   | `[$credits]` | `0x009d0600` | 10 | `sprintf("%I64d", *(i64*)(ch+0x720) − *(i64*)(ch+0x728))` |
   | `[$level]` | `0x009d05f4` | 8 | MI vcall `vtbl+0x27c` → `sprintf("%i")` |
4. **Classification:** worker — mission dialog/UI string prep (not free-form macro parser; no wallet write).
5. **Callers (2):** `FUN_008aaf60` @ `0x008aafc1`; `FUN_008a3510` @ `0x008a3f5c`.
6. **Callees:** `std::string::find` / `replace`; `sprintf`; `FUN_00521800`; `FUN_00521900`; vcalls.
7. **Name:** `Mission_ExpandPlayerTokenPlaceholders_Inferred` (Ghidra `FUN_005465c0`; **Inferred** from token strings). **Reject** scaffold-only `Named_credits`.
8. **Decompile ≡ bytes** for five-loop CF; string immediates and credits `SUB`/`SBB` sealed via `read_memory`.  
   Full hex: raw WQ7R-D append (566 B).

### Gaps

- Product English for vtbl `+0x160` / `+0x27c`.  
- Product English for race/class helpers (WQ7R-F owns `0x00521800` / `0x00521900`).  
- Semantic label of subtractand at `char+0x728`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005465c0_Mission_ExpandPlayerTokenPlaceholders_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005465c0_Mission_ExpandPlayerTokenPlaceholders_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005465c0_FUN_005465c0.md` |
| Annotated | `docs/reconstruction/raw/aa_005465c0_FUN_005465c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Mission_ExpandPlayerTokenPlaceholders_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005465c0.cpp` |
| Function | `docs/reconstruction/functions/aa_005465c0_FUN_005465c0.md` |
| Function named | `docs/reconstruction/functions/aa_005465c0_Mission_ExpandPlayerTokenPlaceholders_Inferred.md` |

---

## VA `0x00411180` — sealed facts

1. **Body:** `0x00411180`–`0x004111c9` (Ghidra); measured **74 B** / `0x4A` incl. final `C3`; pad `CC` @ next.
2. **ABI:** **EAX=`vec*`**, **ESI=`const uint32_t* value`**, bare **`RET`** (`C3`). Decompiler showed `void` / `in_EAX` / `unaff_ESI` — **bytes + call sites win**.
3. **Semantics:** MSVC-style **`vector<uint32_t>::push_back`**:
   - Layout `+0x04 begin / +0x08 end / +0x0c cap_end`; size/cap via `SAR …,2`.
   - **Spare:** `*end = *value; end += 4`.
   - **Full / null begin:** `FUN_0040b6d0(end, value)` with EDI=vec threaded (`E8` → `0x0040b6d0`).
4. **Classification:** worker — generic container helper (journal is a consumer, not the only one).
5. **Callers (9 xrefs):** `Client_UpdateMissionJournal` ×3 (`0x008ae429`, `0x008ae4ef`, `0x008ae5ef` — host vecs `+0x728/+0x738`); `FUN_008071c0`, `FUN_0092a440`, `FUN_00800d80`, `FUN_008a2df0`, `FUN_00952ec0`, `FUN_008028e0`.
6. **Callees:** `FUN_0040b6d0` only (WQ7R-E).
7. **Name:** `StdVector_PushBack_Dword_EaxVec_EsiVal_Inferred` (Ghidra `FUN_00411180`; **Inferred** structural). **Reject** identity with thiscall `Vector_PushDword` @ `0x004149d0` (different ABI + grow chain).
8. **Decompile ≡ bytes** for size/cap/fast store; **bytes win** on formals.  
   Full hex: raw WQ7R-D append (74 B).

### Gaps

- Product English for grow helper `FUN_0040b6d0` (not owned).  
- Element product type per site.  
- Journal host field English for `+0x728/+0x738`.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00411180_StdVector_PushBack_Dword_EaxVec_EsiVal_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00411180_StdVector_PushBack_Dword_EaxVec_EsiVal_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00411180_FUN_00411180.md` |
| Annotated | `docs/reconstruction/raw/aa_00411180_FUN_00411180.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_PushBack_Dword_EaxVec_EsiVal_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00411180.cpp` |
| Function | `docs/reconstruction/functions/aa_00411180_FUN_00411180.md` |
| Function named | `docs/reconstruction/functions/aa_00411180_StdVector_PushBack_Dword_EaxVec_EsiVal_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005465c0` | Port as **cdecl** token expand on mission/UI strings. Replace-all only the five fixed needles. Credits display = signed i64 delta `char+0x720 − char+0x728` (no writeback). Name/level via character vtbl; class/race via sealed WQ7R-F helpers when dualed. |
| `00411180` | Port as **register push_back**: **EAX=vec**, **ESI=value***, bare ret. Fast path dword store + end+=4; slow path `FUN_0040b6d0`. **Do not** use thiscall `Vector_PushDword` (`004149d0`) ABI here. |
| Pair with | Journal `Client_UpdateMissionJournal` (`0x008ae130`); dialog `FUN_008aaf60` (WQ7R-A); race/class `00521800`/`00521900` (WQ7R-F); grow `0040b6d0` (WQ7R-E). |

Shared context (not owned):

| VA | Role |
|---|---|
| `0x0040b6d0` | Grow/insert for EAX/ESI dword push (WQ7R-E) |
| `0x00521800` / `0x00521900` | Race / class string getters (WQ7R-F) |
| `0x004149d0` | Sibling thiscall `Vector_PushDword` (already dual-sealed) |
| `0x008aaf60` | Mission dialog consumer of token expand (WQ7R-A) |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + analyze_function_complete + assembly context + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural / string-evidence `_Inferred` names only.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).  
- Closes WQ-007 residual pair **WQ7R-D** (mission string + journal vector push helper).
