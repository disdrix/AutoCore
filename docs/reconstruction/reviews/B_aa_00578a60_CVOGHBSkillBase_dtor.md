# Review B (skeptical / adversarial): `CVOGHBSkillBase_dtor` / `FUN_00578a60` @ `0x00578a60`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00578a60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R12-026 OWN dual) |
| **Counterpart** | `reviews/A_aa_00578a60_CVOGHBSkillBase_dtor.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** on CF/ABI/class/offsets; product mangled + field English + destroy-order open |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Same as scalar deleting dtor `00578de0` | **Falsified** — no flags, no `operator_delete(this)`, no `ret 4` |
| 2 | Bare `ret` / stack args | **Falsified** — tail **JMP** base dtor; ECX only |
| 3 | Frees the skill-HB object | **Falsified** — only owned array + vector buffer |
| 4 | Walks `+0x6b0` elements + FX teardown (OnEnd clear) | **Falsified** — buffer free only; no `004b99c0` loop |
| 5 | `operator_delete` never returns (Ghidra) | **Falsified** — `ADD ESP,4` then zero stores |
| 6 | Base dtor is CALL+return | **Falsified** — `E9` JMP `0x00508390` |
| 7 | Class unknown / generic HB | **Falsified** — restores RTTI-sealed `PTR_FUN_009d3fdc` |
| 8 | Array free uses scalar `delete` | **Falsified** — `+0x6a0` uses **delete[]** stub `0048981c` |
| 9 | Vector free uses delete[] | **Falsified** — `+0x6b0` uses scalar `delete` stub `00489822` |
| 10 | cdecl / fastcall with stack this | **Falsified** — `MOV ESI,ECX` thiscall shape |
| 11 | Product mangled sealed | **Open** |
| 12 | Runtime / bit-exact | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Bytes / CF | **Confirmed** | Wrong free order / leak |
| ABI thiscall + tail JMP | **Confirmed** | Stack imbalance if inventing ret4 |
| Offsets 0x6a0 / 0x6b0 triad | **Confirmed** | Neighbor field corruption |
| delete[] vs delete split | **Confirmed** | CRT heap mismatch |
| Class family CVOGHBSkillBase | **Confirmed** | Port to wrong HB subclass |
| Element ownership at dtor time | **Medium** | If OnEnd skipped, element objects may leak (buffer freed) |
| Product mangled / field English | **Open** | Docs only |

---

## 3. Surviving contract for AutoCore

```
// __thiscall  ECX=this  — no stack formals; does NOT free this
void CVOGHBSkillBase_dtor(CVOGHBSkillBase* this):
  *this = PTR_FUN_009d3fdc
  if this->arr6a0: operator_delete[](this->arr6a0)
  this->arr6a0 = null
  if this->vec6b0.begin: operator_delete(this->vec6b0.begin)
  this->vec6b0.begin = this->vec6b0.end = this->vec6b0.cap = null
  JMP CVOGHBBase_dtor(this)

// NOT CVOGHBSkillBase_ScalarDeletingDtor @ 0x00578de0 (flags&1 free + ret 4).
// NOT Skill_HB_ClearPtrVectorAt6b0_Inferred @ 0x00578ac0 (element teardown walk).
// NOT CVOGHBBase_dtor @ 0x00508390 alone (missing skill-owned frees).
// Scalar virtual delete path: vtbl[0] → 00578de0 → this complete body.
```

---

## 4. Falsification notes

### 4.1 Collapse with scalar deleting dtor

Ports that `delete this` inside the complete body invent free for stack/member skill-HB objects destroyed without `delete`. Keep the pair split (same argument as R11-006 B dual).

### 4.2 Collapse with OnEnd vector clear

OnEnd `00578ac0` walks pointers and calls `NDSpecialFX_TeardownCore` before free. Complete dtor **skips** element teardown. Merging would double-teardown on normal paths or invent teardown on EH-only paths.

### 4.3 Decompiler "does not return"

Ghidra marks second `operator_delete` non-returning; machine continues to zero `+0x6b0/+0x6b4/+0x6b8` then tail-jumps base. Clean preserves zeros + base chain.

### 4.4 Listing gap on `ADD ESP,4`

`disassemble_function` dropped the second `83 C4 04`; `read_memory` hex restores it. Prefer bytes over incomplete listings. (**No** `disassemble_bytes` used.)

### 4.5 Fastcall vs thiscall label

Decompiler prints `__fastcall`; entry is MSVC thiscall (`ECX=this`). For this single-register shape the codegen matches; do not invent stack-this formals.

---

## 5. Open questions

1. Product mangled complete-body name.  
2. Product English for `FUN_0058ab60` heap @ `+0x6a0` and vector @ `+0x6b0`.  
3. Lifetime guarantee that OnEnd (or equivalent) clears vector elements before complete dtor.  
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** on sealed CF, ABI, class, free split, and base tail. Reject scalar-collapse, OnEnd-merge, free-this, and noreturn-delete fantasies. Product mangled + field English + runtime remain open.
