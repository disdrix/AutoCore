# Review A (reconstruction fidelity): `aa_0051f910` LookupRaceShortCode_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051f910` |
| **VA** | `0x0051f910` |
| **Body span** | `0051f910` – `0051f93b` exclusive (**43** bytes / `0x2B`); pad `CC` |
| **Canonical name** | `FUN_0051f910` (Ghidra) |
| **Proposed name** | `LookupRaceShortCode_Inferred` (**High** role) |
| **Rejected alias** | `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOGClient_0051f910` — chain plate wrong; sole caller is UI formatter |
| **Review date** | `2026-08-05` (OWN-ONLY dual A/B **R13-032**) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile ≡ instructions) |
| **Counterpart** | `reviews/B_aa_0051f910_LookupRaceShortCode_Inferred.md` |
| **System** | skills-abilities / client race short codes |
| **Parent (partition)** | `0x0051f8e0` `LookupRaceDisplayName_Inferred` |
| **Dual status** | **Present (first dual seal)** |
| **Dual start** | 2686 |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Pure leaf helper that maps an integer **race id** to a **static product 3-letter short code**:

| raceId | String | VA |
|---:|---|---|
| 0 | `"HUM"` | `0x009cef04` |
| 1 | `"MUT"` | `0x009cef08` |
| 2 | `"BIO"` | `0x009cef0c` |
| else | `"Unknown"` | `0x00a37c4c` |

Used by UI host `FUN_00871150` when formatting **`"%d/%s/%s"`** (level / class-short / race-short) after class-short peer `FUN_0051fa10`.

**ABI:** cdecl; raceId on stack; plain `ret`; returns `const char*` (rodata immediate).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R13 re-verify) | `docs/reconstruction/raw/aa_0051f910_FUN_0051f910.md` |
| Annotated | `docs/reconstruction/raw/aa_0051f910_FUN_0051f910.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0051f910.cpp` |
| Named clean | `docs/reconstruction/reconstructed-exact/LookupRaceShortCode_Inferred.cpp` |
| Function records | `docs/reconstruction/functions/aa_0051f910_FUN_0051f910.md`, `aa_0051f910_LookupRaceShortCode_Inferred.md` |
| English twin | `LookupRaceDisplayName_Inferred` `0x0051f8e0` (dualed R12-017; partition parent) |
| Class English peer | `LookupClassDisplayName_Inferred` `0x0051f940` (dualed) |
| Class short peer | `FUN_0051fa10` (residual) |
| Path suffix peer | `BuildRaceClassSuffix_Inferred` `0x0051f550` (dualed; `_h/_m/_b`) |
| Sole caller | `FUN_00871150` @ `0x00871273` |

**This pass (live):** `decompile_function` @ `0x0051f910`; `analyze_function_complete`; `disassemble_function`; `get_function_by_address`; `get_function_callers`; `get_function_xrefs`; `get_assembly_context` @ call site; `read_memory` body + four product strings + format `"%d/%s/%s"`; caller decompile of `0x00871150`. **Not performed:** `disassemble_bytes`, Launcher, runtime, parent ledger edits, other VAs dualled.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span 43 B / exclusive end `0051f93b` / pad CC / next `0051f940` | **High** | `get_function_by_address` + `read_memory` |
| cdecl 1-arg; `[esp+4]`; plain RET (`c3`) | **High** | entry + four exits |
| Leaf / no callees | **High** | analyze callees=[] |
| Race short map 0/1/2/else + product strings | **High** | imm `mov eax` + `read_memory` ASCII |
| Contiguous pack HUM/MUT/BIO @ `0x009cef04` | **High** | 12 B rodata |
| Shared `"Unknown"` with English twin | **High** | same VA `0x00a37c4c` |
| Static rodata return (not TLS ring / heap) | **High** | no callees; imm string ptrs |
| Sole caller: UI `FUN_00871150` format line | **High** | 1 UNCONDITIONAL_CALL xref |
| Role = race short-code lookup | **High** | strings + English twin + class short peer |
| Product/PDB method symbol | **Probable** | role High; symbol open → `_Inferred` |
| Runtime / bit-exact | **Open** | Terminal false |

---

## 4. Control flow: clean ≡ raw ≡ live ≡ instructions

| Stage | Match |
|---|---|
| raceId==0 → HUM | **Yes** |
| raceId==1 → MUT | **Yes** |
| raceId==2 → BIO | **Yes** |
| else → Unknown | **Yes** |
| sub/jz cascade (not switch table) | **Yes** |
| four plain RET exits | **Yes** |
| Ghidra analyze `void` signature wrong; decompile `char*` correct | **Yes** (machine sealed) |

---

## 5. Gaps (accept-with-gaps)

1. Product / MSVC demangle for short-code helper method name.
2. Host English name / full dual for sole caller `FUN_00871150`.
3. Dual of class-short peer `FUN_0051fa10` (not OWN this partition).
4. Runtime / bit-exact / differential verification.

---

## 6. Verdict

**accept-with-gaps** — CF/ABI/strings/caller sealed; product symbol Inferred; Terminal **false**.
