# Review A (reconstruction fidelity): `aa_0060d460` CVOGObjectiveRequirement_UseItem_MatchTargetCore

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060d460` |
| **VA** | `0x0060d460` |
| **Canonical name** | `CVOGObjectiveRequirement_UseItem_MatchTargetCore` |
| **Prior names** | `FUN_0060d460`, `Named_CalleeOf_CVOGObjectiveRequirement_UseItem_MatchTarget_0060d460` |
| **Review date** | `2026-07-29` (dual A/B seal; supersedes 2026-07-23 scaffold) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live + bytes) |
| **Counterpart** | `reviews/B_aa_0060d460_CVOGObjectiveRequirement_UseItem_MatchTargetCore.md` |
| **Residual scratch** | `reviews/a_0060d460.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present** (A + B + residual) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**UseItem MatchTarget core** — sole non-trivial body under trampoline `CVOGObjectiveRequirement_UseItem_MatchTarget` (`0x0060d7f0`, vtable **+0x38**).

1. Null-check character and target.
2. **Identity OR:** instance COID (`req+0x10/+0x14` vs `obj+0x160/+0x164`) when `(lo & hi) != 0xFFFFFFFF`, else/also primary CBID `req+0x18` vs `*(obj+0xA8)+0x34` when `+0x18 != -1`.
3. Require inventory manager `ch+0x250` and cargo grid `mgr+0x2B0`.
4. `InventoryGrid_FindItemByCoid(grid, obj COID)` vs invert flag **`req+0x1D`**.
5. Optional `InventoryGrid_FindItemByCbid(grid, req+0x2C, 0, 0)` when `+0x2C != -1`.
6. Optional `req+0x54 >= 1` must equal character clonebase `+0xFC`.
7. Return **1** / **0** in **AL**.

**Calling convention:** MSVC `__thiscall` — requirement in `ECX`; **`ret 0x08`**.

| Slot | Role | Evidence |
|------|------|----------|
| `this` | UseItem requirement* | `mov esi, ecx`; field loads `esi+0x10…` |
| stack0 | character* | `mov ebx, [esp+8]` after `push ebx` |
| stack1 | target object* | `mov eax, [esp+0x10]` after two pushes |

**Side effects:** none local — only callees may lock inventory lists.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0060d460_FUN_0060d460.md` |
| Annotated | `docs/reconstruction/raw/aa_0060d460_FUN_0060d460.annotated.md` |
| Clean (refined) | `docs/reconstruction/reconstructed-exact/CVOGObjectiveRequirement_UseItem_MatchTargetCore.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0060d460.cpp` |
| Function record | `docs/reconstruction/functions/aa_0060d460_CVOGObjectiveRequirement_UseItem_MatchTargetCore.md` |
| Residual | `docs/reconstruction/reviews/a_0060d460.md` |
| Live re-decompile | Ghidra MCP `decompile_function` @ `0x0060d460` (2026-07-29) ≡ raw CF |
| Bytes | Ghidra MCP `read_memory` 220 B @ entry — grid ECX, invert, `ret 8` |
| Callee duals | `aa_00571010` FindItemByCoid; `aa_005710c0` FindItemByCbid |
| Caller | `aa_0060d7f0` MatchTarget trampoline; InitActive `aa_0060d540` shares `+0x18/+0x2C` |

**Not performed:** `disassemble_bytes`, Launcher, live inventory tests, bit-exact image diff.

---

## 3. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null char / target → 0 | **Yes** |
| COID path when `(+0x10 & +0x14) != -1` | **Yes** |
| Else CBID path `+0x18` vs clonebase+0x34 | **Yes** |
| Fail identity → 0 | **Yes** |
| `ch+0x250` / `+0x2B0` non-null | **Yes** (bytes) |
| FindByCoid(target COID) | **Yes** — ECX=`edi` grid |
| Invert vs `+0x1D` (`setz`/`xor`/`jnz`) | **Yes** |
| FindByCbid optional `+0x2C` | **Yes** — same grid ECX |
| Field `+0x54` vs clonebase+0xFC | **Yes** |
| Success AL=1 / fail AL=0; `ret 8` | **Yes** |

### 3.1 Grid ECX (SEALED)

```
ecx = *(character + 0x250)     ; inventory manager
edi = *(ecx + 0x2B0)           ; InventoryGrid*
; push coidHi; push coidLo; mov ecx, edi; call FindItemByCoid
; same edi into FindItemByCbid
```

### 3.2 Invert presence (SEALED)

```
found = FindItemByCoid(...)
cl = (found == 0)              ; setz
xor cl, byte [req+0x1D]
jnz fail
```

`+0x1D == 0` → require present; `+0x1D != 0` → require absent.

### 3.3 Contrast: not FindByCbid for target identity

Primary identity uses **object** COID/CBID fields. FindByCoid only checks whether that instance is **in cargo**. Secondary FindByCbid is a **separate** requirement CBID at `+0x2C` (same field InitActive can give).

---

## 4. Offsets (body-backed)

| Offset | Width | Role | Evidence |
|--------|-------|------|----------|
| req `+0x10/+0x14` | u32×2 | required instance COID | cmp vs obj+0x160/164 |
| req `+0x18` | i32 | primary CBID / −1 | cmp clonebase+0x34 |
| req `+0x1D` | u8 | invert cargo presence | `movzx` / xor |
| req `+0x2C` | i32 | secondary CBID / −1 | push → FindByCbid |
| req `+0x54` | i32 | char field gate / `<1` skip | signed test + cmp |
| ch `+0x250` | ptr | inventory manager | `mov ecx,[ebx+0x250]` |
| mgr `+0x2B0` | ptr | cargo InventoryGrid | `mov edi,[ecx+0x2b0]` |
| obj `+0x160/+0x164` | i32×2 | instance COID | match + FindByCoid args |
| obj `+0xA8`→`+0x34` | i32 | CBID | primary identity |
| ch MI `+0xA8`→`+0xFC` | i32 | character field | gate |

---

## 5. Naming

| Claim | Confidence |
|---|---|
| Core behind UseItem MatchTarget trampoline | **High / Sealed** |
| Canonical `…_MatchTargetCore` | **Probable** (role); PDB unknown |
| COID/CBID vocabulary | **High** (aligned with inventory duals) |
| Product name of `+0x54` field | **Tentative** |

---

## 6. Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary / `ret 0x08` | **High** |
| Signature | **High** |
| Control flow | **High** (live ≡ raw) |
| Identity OR COID/CBID | **High / Sealed** |
| Grid ECX path | **High / Sealed** |
| Invert `+0x1D` | **High / Sealed** |
| Secondary CBID / field gate | **High** |
| Original symbol | **Open** |
| Runtime / diff | **Open** |
| Overall | **accept-with-gaps** |

## 7. Gaps

- Runtime golden (mission UseItem on correct/incorrect targets)
- Product English for `req+0x54` / character `clonebase+0xFC`
- Whether COID-all-ones and CBID−1 simultaneously can ever pass (static: no identity → 0)
- Server-side authority vs client MatchTarget (out of unit)

**Verdict:** accept-with-gaps. Static CF, inventory keys, and grid ECX sealed.
