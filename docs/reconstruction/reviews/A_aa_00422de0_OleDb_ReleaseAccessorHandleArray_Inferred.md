# Review A (reconstruction fidelity): `aa_00422de0` OleDb_ReleaseAccessorHandleArray_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00422de0` |
| **VA** | `0x00422de0` (0x00422de0-~0x00422e50) |
| **Canonical name** | `OleDb_ReleaseAccessorHandleArray_Inferred` |
| **Ghidra name** | `FUN_00422de0` |
| **Prior alias** | `Named_CalleeOf_Skill_IDSkillBattleMode1_00422de0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_00422de0_OleDb_ReleaseAccessorHandleArray_Inferred.md` |
| **System** | COM / OLE DB IAccessor |
| **Live tools** | Ghidra HTTP `batch_decompile` / `read_memory` / callers / callees / xrefs (`autoassault.exe`) |
| **Verdict** | **accept-with-gaps** |
| **Dual status** | **Present (first full dual)** |
| **Parent ensure** | `Skill_DbLoadSkillsCharacters` `aa_007e34b0` nested (or shared DbLoad plumbing) |

---

## 1. Purpose

Release every **HACCESSOR** in a growable array, then free the array.

`DAT_00a860ac` GUID bytes `8C3A730C-1C2A-CE11-ADE5-00AA0044773D` -> **`{{0C733A8C-2A1C-11CE-ADE5-00AA0044773D}}` = IID_IAccessor**.

1. If `count==0`: return 0.
2. `FUN_00437cd0` zeros com_ptr slot (live: `*slot=0`).
3. QI source for IID_IAccessor.
4. For each handle (stride **8**): `vtbl+0x18` ReleaseAccessor.
5. `count=0`; `operator_delete[](base)`; base=0.
6. `FUN_0041d7b0` Releases QI'd iface if non-null.

Callee of `AdoRowsetHolder_Teardown` (`0041bf70`).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile` @ `0x00422de0` (2026-07-29) ≡ raw |
| Raw / annotated / clean | `raw/aa_00422de0_*`, `reconstructed-exact/FUN_00422de0.cpp` |
| Function record | `functions/aa_00422de0_*.md` |
| Parent dual | `reviews/A_aa_007e34b0_Skill_DbLoadSkillsCharacters.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| IID is IAccessor OLE DB | **Confirmed** | read_memory GUID + OLE DB docs |
| vtbl+0x18 is ReleaseAccessor | **High** | IAccessor layout after IUnknown |
| Array elements stride 8 | **High** | index*8 |
| Frees array with operator_delete[] | **High** | operator_delete__ |
| 00437cd0/0041d7b0 are com_ptr init/Release not CS | **High** | live decompile of helpers |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Body CF from scaffold clean | **Yes** |
| Live batch_decompile ≡ raw 2026-07-23 | **Yes** |
| No modernization | **Yes** |

---

## 5. Gaps

1. Why handle records are 8 bytes (handle + pad/status).
2. Caller register pairing (ESI/EAX) formal signature.

**Verdict:** Structural contract sealed from live decompile + xrefs. Product type names remain inferred. **accept-with-gaps.**
