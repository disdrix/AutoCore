# Review A (reconstruction fidelity): `aa_00437cd0` ComPtr_ClearSlot

| Field | Value |
|---|---|
| **Stable ID** | `aa_00437cd0` |
| **VA** | `0x00437cd0` (0x00437cd0–0x00437cd6) |
| **Canonical name** | `ComPtr_ClearSlot` (structural) |
| **Ghidra name** | `FUN_00437cd0` |
| **Prior alias** | `Named_CalleeOf_Named_CalleeOf_Skill_IDSkillBattleMode1_00437cd0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W16-J) |
| **Counterpart** | `reviews/B_aa_00437cd0_ComPtr_ClearSlot.md` |
| **System** | COM / OLE DB plumbing |
| **Live tools** | Ghidra MCP `decompile_function` / `read_memory` / callers / xrefs (`autoassault.exe`) |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |
| **Parent ensure** | Nested of `OleDb_ReleaseAccessorHandleArray` `aa_00422de0` / peer DbLoad COM plumbing (`Skill_DbLoadSkillsCharacters` tree) |

---

## 1. Purpose

**Clear a COM interface pointer slot** — one-instruction contract:

1. `*slot = 0` where `slot` is the dword pointer in **EAX**

```c
// void /* EAX = IUnknown** */
void FUN_00437cd0(void)
{
  undefined4 *in_EAX;
  *in_EAX = 0;
  return;
}
```

Bytes (`read_memory` @ `0x00437cd0`):

```text
00437cd0  c7 00 00 00 00 00   mov dword ptr [eax], 0
00437cd6  c3                  ret
```

**Not** Release, free, CS enter/leave, or BSTR free. Used as QI out-param prelude across OLE DB helpers (parent dual already names this “zeros com_ptr slot”).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_00437cd0_*`, `reconstructed-exact/FUN_00437cd0.cpp` |
| Named alias scaffold | `Named_CalleeOf_Named_CalleeOf_Skill_IDSkillBattleMode1_00437cd0.cpp` |
| Function records | `functions/aa_00437cd0_FUN_00437cd0.md`, `functions/aa_00437cd0_ComPtr_ClearSlot.md` |
| Fresh decompile | Ghidra `decompile_function` @ `0x00437cd0` (2026-07-29) |
| Bytes | `read_memory` 32 B — body 7 B + INT3 pad |
| Callers | `00422de0`, `00423170`, `00422d10`, `00422d70`, `004231d0`, `00423370`, `00421aa0`, `00421c30`, `00421cd0`, `00422ce0`, `00763740` |
| Parent dual | `reviews/A_aa_00422de0_OleDb_ReleaseAccessorHandleArray_Inferred.md` |

**Not performed:** runtime golden (unnecessary for 7-byte store-null).

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| EAX holds `void**` / `IUnknown**` slot | **Confirmed** | bytes + decompiler `in_EAX` |
| Single store of 0 through slot | **Confirmed** | `c70000000000` |
| void; no stack args (`ret`) | **Confirmed** | |
| Not Release / not free | **Confirmed** | no call |
| Shared COM QI prelude helper | **High** | dualled parents call before QI |
| Product wrapper name | **Open** | structural name sealed |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| `*EAX = 0` | Yes |
| `return` | Yes |
| Live ≡ raw 2026-07-23 | **Yes** |
| No modernization | **Yes** |

### Recovered CF

```c
void ComPtr_ClearSlot(IUnknown** slot /*in EAX*/) {
  *slot = nullptr;
}
```

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `OleDb_ReleaseAccessorHandleArray` `0x00422de0` | zero com_ptr before QI IAccessor |
| Caller | `OleDb_ReleaseAccessorHandle` `0x00423170` | same |
| Caller | QI / bind helpers `00422d10` / `00422d70` / … | out-slot init |
| Callee | *(none)* | pure store |

---

## 6. Gaps / open

1. Product helper name if any (no strings in unit).
2. Formal MSVC calling-convention name for EAX-only arg (custom register ABI; not ECX `__thiscall`/`__fastcall`).
3. Runtime deferred (not needed).

**Verdict:** **accept-with-gaps** — CF Confirmed from live bytes; residual is product naming / English only.
