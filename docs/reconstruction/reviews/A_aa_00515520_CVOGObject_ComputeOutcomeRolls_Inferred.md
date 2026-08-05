# Review A (reconstruction fidelity): `aa_00515520` CVOGObject_ComputeOutcomeRolls_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00515520` |
| **VA** | `0x00515520`–`0x00516706` |
| **Body** | **4583 bytes** |
| **Canonical name** | `CVOGObject_ComputeOutcomeRolls_Inferred` |
| **Prior scaffold** | `FUN_00515520` |
| **Review date** | `2026-07-29` (W27-M dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00515520_CVOGObject_ComputeOutcomeRolls_Inferred.md` |
| **System** | object / combat-outcome virtual |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** on ABI/xref/phase spine; **accept-with-gaps** on full temp recovery + product English |

**Tools:** Ghidra decompile_function + read_memory + analyze_function_complete + get_function_by_address + xrefs/callees. No disassemble_bytes. No Launcher.

---

## 1. Purpose

Virtual outcome-roll method shared across many object vtables: validate, gather levels/theory, 6-channel short rolls, optional reaction apply, return clamped int.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra @ `0x00515520` (+ tmp dump) |
| Bytes | sub esp 0xC0; ret 0x28 |
| Constants | 0.004f / 0.5f / DAT_009cdf9c table |
| Xrefs | 26 DATA; 0 CODE |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| thiscall + ret 0x28 | **Confirmed** | C2 28 00 |
| Virtual-only | **Confirmed** | DATA only |
| 6-channel loop | **Confirmed** | |
| RNG callees | **Confirmed** | |
| Exact 10 stack formals | **Partial** | |
| Product English | **Inferred** | |
| Shared float = multi-kill | **Rejected** | pool labels |

---

## 4. Control flow spine: clean equiv raw equiv live

| Stage | Match |
|---|---|
| Early gates + return 0 | Yes |
| Level / theory gather | Yes |
| 6-channel build + roll | Yes |
| Reaction flag paths | Yes |
| Post-scale + clamp | Yes |
| Optional ResolveUseObjectPending | Yes |
| ret 0x28 | Yes |

---

## 5. Gaps / open

1. Product/PDB method name and award type.
2. Complete 10-arg map.
3. Predicate labs not OWN.
4. unaff_* recovery / bit-diff.
5. Runtime differential.

**Verdict:** **accept** (ABI + virtual + phase spine sealed).
