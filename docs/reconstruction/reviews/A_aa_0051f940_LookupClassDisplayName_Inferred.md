# Review A (reconstruction fidelity): `aa_0051f940` LookupClassDisplayName_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051f940` |
| **VA** | `0x0051f940` |
| **Body** | `0x0051f940`–`0x0051f9f9` (**185 B** / `0xb9`); pad `CC` |
| **Canonical name** | `LookupClassDisplayName_Inferred` (**Inferred**); Ghidra `FUN_0051f940` |
| **Review date** | `2026-08-04` (WQ9G-E dual seal) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0051f940_LookupClassDisplayName_Inferred.md` |
| **System** | missions-progression / character display |
| **Live tools** | `batch_decompile`, `analyze_function_complete`, `get_function_by_address`, callers/xrefs, `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — class×race table + cdecl leaf + product strings sealed; method English Inferred |

---

## 1. Purpose

Pure leaf: map **(classId, raceId)** to a **static product English** class display name. Closes the residual left open by dual of `Character_GetClassDisplayName_Inferred` (`aa_00521900`), which documented this table as unowned callee evidence.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | Ghidra `batch_decompile(0x0051f940)` 2026-08-04 |
| Body bounds | `get_function_by_address` → `0051f940`–`0051f9f9` |
| Machine | `read_memory` entry + jump table + string VAs |
| Callers | `FUN_00521900`, `FUN_00521970`, `FUN_00845360`, `FUN_00846820`, `FUN_008967b0`, `FUN_008a3510` |
| Wrapper dual | `A_aa_00521900_Character_GetClassDisplayName_Inferred` (2-arg cdecl + `add esp,8`) |
| Scaffold raw | prior 2026-07-23 capture (CF unchanged) |

**Not performed:** `disassemble_bytes`; Launcher; parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| cdecl 2-arg leaf; plain `ret`; char\* return | **Confirmed** | bytes + caller cleanup |
| No callees | **Confirmed** | analyze callees=[] |
| Jump-table switch on classId 0..3 / default | **Confirmed** | entry + table dwords |
| Product string table content | **Confirmed** | imm `mov eax` + `read_memory` strings |
| Argument order (class, race) | **Confirmed** | wrapper dual + switch outer=class |
| Static literal return (not TLS ring) | **Confirmed** | no ring callees; wrappers ring |
| Role = class display name lookup | **High** | callers + string content |
| Product/PDB method name | **Inferred** | `_Inferred` suffix |
| Race id English (Human/Mutant/Biomek) | **Peer dual** | not re-owned here |
| Runtime / bit-exact | **Open** | |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| classId switch 0..3 / default Unknown | **Yes** |
| Per-class race branches | **Yes** |
| Immediate string returns | **Yes** |
| No side effects / stores | **Yes** |

---

## 5. Gaps

1. Product method English (name is role-Inferred).
2. Authoritative race enumeration docs (peer race dual).
3. Runtime golden matrix of all class×race pairs.
4. Bit-exact / differential.

**Verdict:** **accept-with-gaps** — table + ABI sealed; naming residual Inferred.
