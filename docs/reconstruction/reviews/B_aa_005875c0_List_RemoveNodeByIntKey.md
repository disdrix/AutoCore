# Review B (skeptical / adversarial): `aa_005875c0` List_RemoveNodeByIntKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_005875c0` |
| **VA** | `0x005875c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005875c0_List_RemoveNodeByIntKey.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept** — remove-by-key sealed; residual "register" **falsified** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Registers/inserts reward id | Only unlink + delete | **Falsified register** |
| 2 | operator_delete noreturn | Listing continues loop | **Falsified Ghidra warning** |
| 3 | Mission-only | Callers include FX teardown / clear staging peers | **Falsified exclusive** |
| 4 | Compares pointer of pKey as id | Loads `*pKey` | **Falsified** |
| 5 | Stops at first match | Loop resumes at next | **May remove multiples** |
| 6 | Parent residual Probable name OK | "Resolve/register" wrong verb | **Correct to remove** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Remove CF | **High** | Leaked staging nodes |
| `char+0xcc4` list use | **High** at CO | Wrong list |
| Insert counterpart elsewhere | **Open** | Incomplete staging model |
| Product list name | **Low** | |

---

## 3. Surviving contract for AutoCore

```
// Port as list erase-by-int-key, NOT register/insert.
// Call before grant-or-delete so staging cannot double-hand object.
// Ignore decompiler noreturn on operator_delete.
```
