# Review B (skeptical / adversarial): `aa_0059d890` CVOGObjective_SetCompleteCount

| Field | Value |
|---|---|
| **Stable ID** | `aa_0059d890` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W21-J) |
| **Counterpart** | `reviews/A_aa_0059d890_CVOGObjective_SetCompleteCount.md` |
| **Verdict** | **accept** on sealed CF; reject listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Getter / read-only | Body stores `[ecx+0x164]` | **Falsified** |
| 2 | Bare `ret` like getter | Setter is `ret 4`; getter is bare `c3` | **Falsified** if conflated |
| 3 | Same VA as `0x0059d880` | Adjacent sibling; different bytes | **Falsified** |
| 4 | Writes multiple objective fields | Single offset only | **Falsified** |
| 5 | Validates range / clamps CompleteCount | No branches | **Falsified** |
| 6 | Anim-slot / `0x0074e910` related | Mission field only | **Falsified** |
| 7 | High fan-in like getter (5 sites) | **1** static CALL xref | **Falsified** if claimed multi |
| 8 | Bit-exact / runtime verified | Static dual only | **Fail** if claimed |
| 9 | Product name sealed as SetCompleteCount | Structural pair with getter | **Overstated** if claimed PDB |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Body bytes / `ret 4` | **High** | Wrong ABI |
| Offset `+0x164` | **High** | Wrong mission threshold field |
| CompleteCount identity | **High** | via getter/XML |
| Sole caller | **High** | missing writers only if dynamic/vtbl (none observed) |
| Product setter spelling | **Low–Med** | naming |
| Parent XML key mapping | **Med** | load path residual |

---

## 3. Cross-check

| Item | Result |
|---|---|
| Raw ≡ live decompile | **Yes** |
| Body hex | `8b442404 898164010000 c20400` |
| Next pad / next fn | `cc` then unrelated body @ `0059d8a0` |
| Sibling getter dual | agrees offset + CompleteCount English |
| Call site `005478a9` | `push eax; call` after load obj into ECX |

**Attack on “field is something other than CompleteCount”:** **Fails** — getter dual sealed product tag via XML string dump; same offset.

**Attack on “setter is dead code”:** **Fails** — live UNCONDITIONAL_CALL from load parent.

**Attack on “must implement complex validation”:** **Fails** — retail does raw assign.

---

## 4. Surviving contract for AutoCore

```
// thiscall objective; one uint32; ret 4
// *(obj+0x164) = completeCount;  // CompleteCount
// no clamp, no notify, no secondary fields
```

**Falsified port mistakes:**

- Using bare `ret` (getter ABI).
- Writing a different offset than `0x164`.
- Inventing min/max validation in the setter.
- Conflating with anim `0x0074e910`.
- Assuming high fan-in symmetric to getter.

---

## 5. Open questions

1. Product setter name / PDB.
2. Which mission XML attribute feeds the push-eax at `0x005478a9`.
3. Runtime / bit-exact.

**Verdict:** **accept** — CompleteCount setter stub sealed; no blocking residual for this VA.
