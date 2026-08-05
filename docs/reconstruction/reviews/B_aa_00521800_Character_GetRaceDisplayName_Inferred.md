# Review B (skeptical / adversarial): `aa_00521800` Character_GetRaceDisplayName_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00521800` |
| **VA** | `0x00521800` |
| **Canonical name** | `Character_GetRaceDisplayName_Inferred` (**Inferred**) |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00521800_Character_GetRaceDisplayName_Inferred.md` |
| **System** | missions-progression / character display |
| **Live tools** | Independent decompile + `read_memory` + caller decompiles |
| **Verdict** | **accept-with-gaps** — accept race map/strings/ABI; reject void-return, cdecl-free, durable-heap claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | `void` return (Ghidra signature) | **Falsified** — callers treat EAX as `char*` for `std::string::replace` / byte copies |
| 2 | Free function / stack this | **Falsified** — first load `[ecx+4]`; no stack arg for object |
| 3 | Direct race field on this | **Falsified** — nested `+4 → +4 → +0xac+this → +0x3c → +0x532` |
| 4 | Race order Human/Biomek/Mutant scrambled | **Falsified** — sub cascade 0/1/2 maps Human/Mutant/Biomek; strings at sealed VAs |
| 5 | Returns durable heap string | **Falsified** — `FUN_007a6de0` ring buffer; must copy if retaining |
| 6 | Scaffold `Named_CalleeOf_…UpdateMissi…` is product | **Rejected** — parent-seed noise |
| 7 | Only mission-journal use | **Falsified** — also `FUN_005792d0`, `FUN_0092e710` UI formatters |
| 8 | Race 3+ named something other than Unknown | **Falsified** — fallthrough Unknown only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Race id → string map | **High** | Wrong race labels in journal/UI |
| String VAs | **High** | Misread constants |
| ECX-this + char\* | **High** | ABI / stack bugs |
| TLS ring semantics | **High** | Use-after-reuse if stored raw |
| Product method English | **None** | Overclaim symbol |
| Full Character C++ type | **Low** | Offset port errors outside this leaf |

---

## 3. Decompiler pitfalls (must survive port)

1. Do **not** treat return as void — port as `const char*` / `char*` ring.
2. Do **not** free the return pointer.
3. Pushes before `FUN_007a69d0` are args for **`FUN_007a6de0`**, not for `FUN_007a69d0`.
4. Scaffold UpdateMissionJournal alias — **ignore**.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| 0/1/2 → Human/Mutant/Biomek | Official `GetRaceName` PDB symbol |
| else → Unknown | Race field is plain `this+0x532` |
| ECX-this leaf formatter | Only used by missions |
| `_Inferred` structural name | Confirmed product method English |

---

## 5. CF challenge of Review A

- Race cascade + string VAs: **agree Confirmed**
- Nested blob path +0x532: **agree Confirmed**
- char\* ring return: **agree Confirmed**
- accept-with-gaps (not bare accept): **agree** — type/product English residual is real

**Verdict:** **accept-with-gaps**
