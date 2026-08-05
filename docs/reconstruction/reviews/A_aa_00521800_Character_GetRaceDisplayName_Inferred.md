# Review A (reconstruction fidelity): `aa_00521800` Character_GetRaceDisplayName_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00521800` |
| **VA** | `0x00521800` |
| **Body** | `0x00521800`–`0x00521879` (**121 B** / `0x79`); pad `CC` |
| **Canonical name** | `Character_GetRaceDisplayName_Inferred` (**Inferred**); Ghidra `FUN_00521800` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00521800_Character_GetRaceDisplayName_Inferred.md` |
| **System** | missions-progression / character display |
| **Live tools** | Ghidra `batch_decompile`, `get_function_by_address`, `get_function_callers`, `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — race map + strings + ABI sealed; product method English + deep this-type open |
| **Dual status** | **Present (WQ7R-F)** |

---

## 1. Purpose

Character **race → English display name** helper used by mission token substitution (`[$race]`) and UI formatters.

```
race = *(uint8*)(nested_blob + 0x532);
switch-cascade: 0 Human / 1 Mutant / 2 Biomek / else Unknown
→ FUN_007a69d0(); FUN_007a6de0(name, -1); return char*
```

**ABI:** ECX-this; plain **`RET`**; returns **char\*** (TLS ring).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | Ghidra `batch_decompile` `0x00521800` — 4-way race cascade |
| Body bounds | `get_function_by_address` → `00521800`–`00521879` |
| Machine | `read_memory` 128 B @ entry; string VAs confirmed |
| Callers | `FUN_005465c0`, `FUN_005792d0`, `FUN_0092e710` |
| Parent context | `FUN_005465c0` find/replace `[$race]` (len 7) |
| Scaffold | prior raw/annotated/clean updated WQ7R-F |

**Not performed:** Launcher, runtime golden, bit-exact image diff, parent ledger edits.

---

## 3. Machine seal (`read_memory`)

| Claim | Evidence | Conf |
|---|---|---|
| ECX-this | `8b 41 04` first | **Confirmed** |
| Nested path +0xac / +0x3c / +0x532 | `8b 84 0a ac 00 00 00` / `8b 48 3c` / `0f b6 81 32 05 00 00` | **Confirmed** |
| sub/jz cascade 0/1/2 | `83 e8 00 74 … 83 e8 01 74 … 83 e8 01 74 …` | **Confirmed** |
| Fallthrough Unknown @ `0x00a37c4c` | `b8 4c 7c a3 00` + `read_memory` `"Unknown"` | **Confirmed** |
| Biomek @ `0x00a40948` | `b8 48 09 a4 00` + `"Biomek"` | **Confirmed** |
| Mutant @ `0x00a40950` | `b8 50 09 a4 00` + `"Mutant"` | **Confirmed** |
| Human @ `0x00a40958` | `b8 58 09 a4 00` + `"Human"` | **Confirmed** |
| Buffer path | push -1; push str; call `007a69d0`; mov ecx,eax; call `007a6de0`; ret | **Confirmed** |
| Plain RET | `c3` each arm | **Confirmed** |
| char\* return | parent `replace(..., pcVar2)`; format strcpy loops | **Confirmed** |

---

## 4. Gaps

- Product/PDB method English.
- Full C++ type of `this` and intermediate `+0xac` / `+0x3c` objects.
- Whether race enum is shared with mission-def race field `+0x90` (ushort) without zero-extend proof.
- Runtime / bit-exact / differential.

---

## 5. Verdict

**accept-with-gaps** — CF, race map, product strings, and ABI sealed; residual is naming + deep layout types only.
