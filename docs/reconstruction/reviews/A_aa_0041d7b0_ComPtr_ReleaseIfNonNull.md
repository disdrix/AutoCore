# Review A (reconstruction fidelity): `aa_0041d7b0` ComPtr_ReleaseIfNonNull

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041d7b0` |
| **VA** | `0x0041d7b0` (0x0041d7b0–0x0041d7bc) |
| **Canonical name** | `ComPtr_ReleaseIfNonNull` (structural) |
| **Ghidra name** | `FUN_0041d7b0` |
| **Prior alias** | `Named_CalleeOf_Named_CalleeOf_Skill_IDSkillBattleMode1_0041d7b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W16-J) |
| **Counterpart** | `reviews/B_aa_0041d7b0_ComPtr_ReleaseIfNonNull.md` |
| **System** | COM / OLE DB plumbing |
| **Live tools** | Ghidra MCP `decompile_function` / `read_memory` / callers / xrefs (`autoassault.exe`) |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |
| **Parent ensure** | Nested of `OleDb_ReleaseAccessorHandleArray` `aa_00422de0` / peer DbLoad COM plumbing + SEH Unwind tables |

---

## 1. Purpose

**Release a COM interface if the slot is non-null** — no store-back:

1. `iface = *slot` (slot in **EAX**)
2. if `iface != 0`: `iface->Release()` via **vtbl+8**
3. **does not** write `*slot = 0`

```c
void FUN_0041d7b0(void)
{
  int *piVar1;
  int *in_EAX;

  piVar1 = (int *)*in_EAX;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}
```

Bytes (`read_memory` @ `0x0041d7b0`):

```text
0041d7b0  8b 00          mov  eax, [eax]       ; iface = *slot
0041d7b2  85 c0          test eax, eax
0041d7b4  74 06          jz   0041d7bc         ; skip if null
0041d7b6  8b 08          mov  ecx, [eax]       ; vtbl
0041d7b8  50             push eax              ; this
0041d7b9  ff 51 08       call dword ptr [ecx+8]; Release
0041d7bc  c3             ret
```

**Extremely common cleanup:** OLE DB QI tails (`00422de0`, `00423170`, `00422d10`, …) and **dozens of `Unwind@*` SEH sites**.

Sibling clear-only: `aa_00437cd0` `ComPtr_ClearSlot`. Contrast free+null: `aa_0040d230` `Bstr_FreeAndNull`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_0041d7b0_*`, `reconstructed-exact/FUN_0041d7b0.cpp` |
| Named alias scaffold | `Named_CalleeOf_Named_CalleeOf_Skill_IDSkillBattleMode1_0041d7b0.cpp` |
| Function records | `functions/aa_0041d7b0_FUN_0041d7b0.md`, `functions/aa_0041d7b0_ComPtr_ReleaseIfNonNull.md` |
| Fresh decompile | Ghidra `decompile_function` @ `0x0041d7b0` (2026-07-29) |
| Bytes | `read_memory` 48 B — body 13 B + pad into next fn |
| Callers | COM helpers + many Unwind@* (see raw live section) |
| Parent dual | `reviews/A_aa_00422de0_OleDb_ReleaseAccessorHandleArray_Inferred.md` |

**Not performed:** live IUnknown refcount golden.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| EAX holds `IUnknown**` slot | **Confirmed** | |
| Null guard before call | **Confirmed** | `test`/`jz` |
| vtbl+8 = IUnknown::Release | **High** | standard COM layout; parent dual same pattern |
| Slot **not** re-nulled | **Confirmed** | no store after call |
| void; no stack args (`ret`) | **Confirmed** | |
| SEH unwind helper as well as normal call | **Confirmed** | many Unwind@* xrefs |
| Product wrapper name | **Open** | structural name sealed |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| load `*slot` | Yes |
| if non-null → vtbl+8(this) | Yes |
| no null store | Yes |
| Live ≡ raw 2026-07-23 | **Yes** |
| No modernization | **Yes** |

### Recovered CF

```c
void ComPtr_ReleaseIfNonNull(IUnknown** slot /*in EAX*/) {
  IUnknown* iface = *slot;
  if (iface != nullptr)
    iface->Release();
  // *slot intentionally unchanged
}
```

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `OleDb_ReleaseAccessorHandleArray` `0x00422de0` | drop QI'd IAccessor after handle loop |
| Caller | `OleDb_ReleaseAccessorHandle` `0x00423170` | same for single handle |
| Caller | QI helpers `00422d10` / `00422d70` / … | post-QI cleanup |
| Caller | `Unwind@009a…` family | SEH local com_ptr Release |
| Callee | indirect only | `IUnknown::Release` |

---

## 6. Gaps / open

1. Product helper name if any.
2. Formal register-ABI label (EAX-only; not ECX thiscall).
3. Whether any caller expects slot to remain non-null after Release for a second path (observed: scope exit / Unwind — residual low risk).
4. Runtime refcount verification deferred.

**Verdict:** **accept-with-gaps** — CF Confirmed from live bytes; residual is product naming / formal ABI English.
