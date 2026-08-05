# Review A (reconstruction fidelity): `aa_00604e10` MedalDef_ZeroOwnedStrings_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00604e10` |
| **VA** | `0x00604e10`–`0x00604e20` (**0x11** bytes; bare `RET`) |
| **Canonical name** | `MedalDef_ZeroOwnedStrings_Inferred` |
| **Ghidra name** | `FUN_00604e10` |
| **Prior alias** | `Named_CalleeOf_Named_VOG_DEBUG_STOP_00604e10` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00604e10_MedalDef_ZeroOwnedStrings_Inferred.md` |
| **System** | missions-progression (medal / achievement def) |
| **Live tools** | `batch_decompile`, `disassemble_function`, parent listing |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**Partial ctor / field zero** for a 0x1c `MedalDef`-shaped object: clear four owned string pointer slots, leave id and tail dwords untouched by this unit.

```c
// __fastcall / thiscall  (ECX = def*)
// returns this in EAX
MedalDef* MedalDef_ZeroOwnedStrings(MedalDef *this);
```

Body:

```text
00604e10  MOV EAX, ECX
00604e12  XOR ECX, ECX
00604e14  MOV [EAX+0x04], ECX   ; str0*
00604e17  MOV [EAX+0x08], ECX   ; str1*
00604e1a  MOV [EAX+0x0c], ECX   ; str2*
00604e1d  MOV [EAX+0x10], ECX   ; str3*
00604e20  RET                   ; EAX = this
```

Sole static caller: `FUN_00519660` after `operator_new(0x1c)`:

```
MOV ECX, newBlock
CALL FUN_00604e10   ; zeros string slots; EDI = EAX = this
CALL FUN_00605090   ; fill from row
```

Does **not** set id (`+0`) or dwords `+0x14/+0x18` — those come from `FUN_00605090`.

---

## 2. Layout (sealed with sibling fill)

| Off | Field | This unit |
|---|---|---|
| `+0x00` | id | **untouched** |
| `+0x04` | char* name-like | **zeroed** |
| `+0x08` | char* | **zeroed** |
| `+0x0c` | char* | **zeroed** |
| `+0x10` | char* | **zeroed** |
| `+0x14` | dword | untouched |
| `+0x18` | dword | untouched |

String setters that own these slots: `FUN_00604e90`/`+4`, `FUN_00604f10`/`+8`, `FUN_00604f90`/`+0xc`, `FUN_00605010`/`+0x10` (each free-old + strdup).

---

## 3. Confidence

| Claim | Level |
|---|---|
| Four dword zeros at +4..+0x10 | **Confirmed** |
| Returns this (EAX=ECX in) | **Confirmed** |
| No free of previous strings | **Confirmed** (zeros only — safe on fresh `new`) |
| Part of MedalDef 0x1c path | **High** (parent medal loader + row size 0x3d4) |
| English field names for each string | **Open** |
| Full product type name | **Probable** medal/achievement |

**Verdict:** **accept-with-gaps.**
