# Review A (reconstruction fidelity): `aa_0051b850` CVOGHBPlayerTargetingLink_ClearOwnerSelectedTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b850` |
| **VA** | `0x0051b850` |
| **Body** | `0x0051b850`–`0x0051b861` (**18 B**, bare `ret`) |
| **Canonical name** | `CVOGHBPlayerTargetingLink_ClearOwnerSelectedTarget` (**Inferred**; Ghidra `FUN_0051b850`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0051b850_CVOGHBPlayerTargetingLink_ClearOwnerSelectedTarget.md` |
| **System** | `heartbeat` / targeting link |
| **Live tools** | Ghidra `create_function`, `decompile_function`, `read_memory`, `get_xrefs_to` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — CF **High**; product virtual name / call-site catalog open |

---

## 1. Purpose

**Derived vtbl slot 7** override for `CVOGHBPlayerTargetingLink` (`PTR_FUN_009cdfd4+0x1C`):

```
if (pOwnerObject /* this+0x18 */ != null)
  *(pOwnerObject + 0xA0) = 0;   // clear entity selected-target pointer
```

Base family slot 7 is **`FUN_0056f570`** (empty `ret` / nop). Only the player-targeting **self-side** HB clears the owner's selected target field when this virtual runs.

`entity+0xA0` is the **selected combat/target pointer** sealed in `Object_SetSelectedTarget` (`0x005172d0`) dual — same offset.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function created | Ghidra `create_function` @ `0x0051b850` (was undefined; DATA-only xref) |
| Fresh decompile | `decompile_function` @ `0x0051b850` |
| Machine | `read_memory` @ `0x0051b850` length 20 |
| Xref | DATA from `0x009cdff0` = `009cdfd4 + 0x1C` (slot 7) |
| Base slot 7 | `FUN_0056f570` — empty body |
| Ctor dual | `A_aa_00512090_*` — derived differs only slot 0 + slot 7 |
| Selected-target dual | `A_aa_005172d0_Object_SetSelectedTarget` — field `+0xA0` |
| Owner field | `CVOGHBBase.pOwnerObject` @ `+0x18` (AttachOwnerObject dual) |

**Note:** No prior raw/clean/function scaffold existed for this VA (undefined function until this dual).

---

## 3. Authoritative body

```c
void __fastcall FUN_0051b850(int param_1 /* this */)
{
  if (*(int *)(param_1 + 0x18) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x18) + 0xa0) = 0;
  }
  return;
}
```

---

## 4. Machine seal (`read_memory`)

Hex:  
`8b 41 18 85 c0 74 0a c7 80 a0 00 00 00 00 00 00 00 c3`

| Claim | Evidence | Conf |
|---|---|---|
| `this` in ECX | `mov eax,[ecx+0x18]` | **High** |
| Null owner early-out | `test eax,eax; jz +0x0a` | **High** |
| Store 0 at `owner+0xA0` | `mov dword ptr [eax+0xA0], 0` | **High** |
| No stack args; bare `ret` | ends `c3` (not `ret N`) | **High** |
| Body size 18 B | through `c3`; then `cc` pad | **High** |
| Vtbl slot 7 derived | DATA xref `009cdff0` | **High** |
| Base counterpart is nop | `FUN_0056f570` empty | **High** |
| `+0xA0` = selected target | sealed in SetSelectedTarget dual | **High** |

---

## 5. Vtbl contrast (first 8 slots)

| Slot | Base `0x009cdfb0` | Derived `0x009cdfd4` |
|---|---|---|
| 0 | `0x00512070` | **`0x0051b870`** (scalar dtor) |
| 1–6 | shared | shared |
| 7 | `0x0056f570` (nop) | **`0x0051b850`** (this) |

---

## 6. Gaps / open

1. Product virtual method English (OnEnd / OnDetach / partner-clear — **INFERRED** role only).
2. Exhaustive call sites that dispatch slot 7 (list Tick destroy path vs explicit vcall).
3. Whether target-side base HB ever needs equivalent (base is nop — intentional asymmetry).
4. No raw/clean artifacts yet (OWN dual-only this pass).

**Verdict:** **accept-with-gaps**
