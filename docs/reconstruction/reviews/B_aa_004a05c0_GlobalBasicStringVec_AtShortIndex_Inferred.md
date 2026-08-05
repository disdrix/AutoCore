# Review B (skeptical / adversarial): `aa_004a05c0` GlobalBasicStringVec_AtShortIndex_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a05c0` |
| **VA** | `0x004a05c0` |
| **Canonical name** | `GlobalBasicStringVec_AtShortIndex_Inferred` (**Inferred**) |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_004a05c0_GlobalBasicStringVec_AtShortIndex_Inferred.md` |
| **System** | Global string table / MSVC `basic_string` vector lookup |
| **Live tools** | Independent decompile + `read_memory` + caller assembly context |
| **Verdict** | **accept** — structure solid; reject scaffold product name and any map/hash theory |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Thiscall / ECX table | **Falsified** — no ECX use; pure stack args; `ADD ESP,8` at all 6 sites |
| 2 | Index is 32-bit | **Falsified** — `MOVSX` from stack **word**; callers load `word ptr [obj+off]` |
| 3 | Hash map / tree lookup | **Falsified** — dense `begin + index * 0x1c` |
| 4 | Returns pointer into table (no copy) | **Falsified** — constructs into caller out-string (empty ctor or copy-ctor) |
| 5 | Scaffold `Named_CalleeOf_Mission_…AudioTable…` | **Rejected** — structural name from layout only |
| 6 | Unchecked index always in range | **Falsified** — explicit `count <= index` → empty string |
| 7 | Stride is something other than `0x1c` | **Falsified** — div magic + `lea` scale path |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Global begin/end + stride 0x1c | **High** | Wrong element / crash |
| Short MOVSX bounds | **High** | Silent empty vs OOB read |
| cdecl out-string return | **High** | ABI mismatch |
| Product table identity | **None** | Wrong registry plate only |
| Dense id vs sparse key | **Medium** | Callers may pass non-dense shorts → empty |

---

## 3. Decompiler pitfalls (must survive port)

1. Signature shown as `undefined`/void in complete-analysis — **ignore**; returns out pointer.  
2. Do not promote index to unsigned without **MOVSX** (negative shorts must OOB).  
3. Scaffold Mission/Audio naming — **ignore**.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| Global vector of 0x1c `basic_string` | Product class / file that fills the vector |
| Short index, OOB → empty copy-out | That every caller index is valid dense id |
| cdecl, return out | that this is the only string table in the binary |

---

## 5. CF challenge of Review A

- Bounds + stride + copy-out: **agree Confirmed**  
- Product gap non-blocking: **agree accept**  

**Verdict:** **accept**
