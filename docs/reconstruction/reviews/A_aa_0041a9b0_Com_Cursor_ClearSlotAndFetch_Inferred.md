# Review A (reconstruction fidelity): `aa_0041a9b0` Com_Cursor_ClearSlotAndFetch_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041a9b0` |
| **VA** | `0x0041a9b0` |
| **Canonical name** | `Com_Cursor_ClearSlotAndFetch_Inferred` |
| **Ghidra name** | `FUN_0041a9b0` |
| **Prior alias** | `Named_CalleeOf_Skill_DbLoadSkillsCharacters_0041a9b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Path A — fidelity (OWN-ONLY dual; Skill_DbLoadSkillsCharacters nested) |
| **Counterpart** | `reviews/B_aa_0041a9b0_Com_Cursor_ClearSlotAndFetch_Inferred.md` |
| **System** | skills-abilities / COM row cursor |
| **Live tools** | Ghidra `batch_decompile`, `read_memory`, callees of parent |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Cursor / field-slot advance helper** with object in **EDI**:

```
if (EDI[3] != 0):                         // dword at EDI+0x0C
  (*(*EDI)->vtbl)[+0x18](*EDI, 1, &EDI[3], 0, 0, 0)
  EDI[3] = 0
hr = (*(*EDI)->vtbl)[+0x1C](*EDI, 0)
if (hr >= 0):
  FUN_0041c000(0, 1)                      // this/EDI context; bind fields
return
```

In `Skill_DbLoadSkillsCharacters` ADO/DB branch (`DAT_00d1793c == 0`): initial call then `while (status == 0) { … process row … status = FUN_0041c000(); }`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_0041a9b0_*`, `reconstructed-exact/FUN_0041a9b0.cpp` |
| Function record | `functions/aa_0041a9b0_FUN_0041a9b0.md` |
| Live bytes | `read_memory` @ `0x0041a9b0` length 80 — body ends `C3` then `CC` |
| Sole named callee | `FUN_0041c000` @ `0x0041c000` |
| Parent | `0x007e34b0` (DB branch row loop) |
| Related loaders | many `007d*` / `007e*` table readers share this pattern |

---

## 3. Assembly-sealed body

```text
0041a9b0  837F0C00        cmp  dword ptr [edi+0xC], 0
0041a9b4  56              push esi
0041a9b5  8D770C          lea  esi, [edi+0xC]
0041a9b8  7417            jz   skip_clear
0041a9ba  8B07            mov  eax, [edi]          ; *cursor = iface*
0041a9bc  8B08            mov  ecx, [eax]          ; vtbl
0041a9be  6A00 6A00 6A00  push 0,0,0
0041a9c4  56              push esi                 ; &slot
0041a9c5  6A01            push 1
0041a9c7  50              push eax                 ; this
0041a9c8  FF5118          call dword ptr [ecx+0x18]
0041a9cb  C70600000000    mov  dword ptr [esi], 0
skip_clear:
0041a9d1  8B07            mov  eax, [edi]
0041a9d3  8B10            mov  edx, [eax]
0041a9d5  6A00            push 0
0041a9d7  50              push eax
0041a9d8  FF521C          call dword ptr [edx+0x1C]
0041a9db  85C0            test eax, eax
0041a9dd  5E              pop  esi
0041a9de  7C0B            jl   ret                 ; hr < 0 → skip bind
0041a9e0  6A01            push 1
0041a9e2  6A00            push 0
0041a9e4  8BC7            mov  eax, edi
0041a9e6  E815160000      call FUN_0041c000
0041a9eb  C3              ret
```

Hex head: `837f0c00568d770c7417…ff5118…ff521c…e815160000c3`

| Claim | Conf |
|---|---|
| Slot at **`EDI+0x0C`** | **High** |
| Clear method **vtbl+0x18** args `(1, &slot, 0,0,0)` | **High** |
| Fetch method **vtbl+0x1C** arg `0` | **High** |
| Success gate **`hr >= 0`** before `0041c000` | **High** |
| `0041c000(0,1)` with EDI/EAX = cursor | **High** |
| No stack formals / `ret` only | **High** |
| Product names MoveNext / GetFields | **Medium** (behavioral) |

---

## 4. Confidence / parent loop

| Claim | Conf |
|---|---|
| Skill loader uses this for first-row enter | **High** (decompile of `007e34b0`) |
| Loop continuation often via bare `0041c000` | **High** |
| Shared across non-skill DB readers | **High** (callers list) |

---

## 5. Gaps

1. Exact COM interface for cursor (`*EDI` and vtbl methods).
2. Dual of `FUN_0041c000` field-bind (still missing `A_aa` at batch time).
3. Return value of this unit: decompiler `void`; parent treats call as status — may be EAX from `0041c000` or prior hr residual (**Medium**).

**Verdict:** **accept-with-gaps**
