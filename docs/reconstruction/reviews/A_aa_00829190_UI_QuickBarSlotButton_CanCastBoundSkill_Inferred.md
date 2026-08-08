# Review A (reconstruction fidelity): `aa_00829190` UI_QuickBarSlotButton_CanCastBoundSkill_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00829190` |
| **VA** | `0x00829190` |
| **Canonical name** | `UI_QuickBarSlotButton_CanCastBoundSkill_Inferred` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ sealed bytes) |
| **Counterpart** | `reviews/B_aa_00829190_UI_QuickBarSlotButton_CanCastBoundSkill_Inferred.md` |
| **System** | client UI / quickbar / skills-abilities |
| **Dual status** | **Present** (WQ8R-D; supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Return whether a QuickBar **slot-button** currently bound to a **skill** is cast-ready for UI (icon enable): world/skill gates → optional force-true → LocalCastValidate (busy-tolerant) → optional target resolve vs invalid TFID.

**Calling convention:** `__thiscall` — button in `ECX`; **no** stack formals; plain `RET`; bool in `AL`.

| Slot | Role | Evidence |
|------|------|----------|
| `this` | `UI_QuickBarSlotButton*` | Prologue uses `ECX+0x548` / `+0x558`; sole caller `MOV ECX,ESI` |
| return | `bool` | `SETZ AL` / `MOV AL,1` / `XOR AL,AL` paths |

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Raw + WQ8R-D append | `raw/aa_00829190_FUN_00829190.md` |
| Annotated | `raw/aa_00829190_FUN_00829190.annotated.md` |
| Clean | `reconstructed-exact/UI_QuickBarSlotButton_CanCastBoundSkill_Inferred.cpp` |
| Function record | `functions/aa_00829190_UI_QuickBarSlotButton_CanCastBoundSkill_Inferred.md` |
| Live decompile | ≡ raw 2026-07-23 |
| Live bytes | entry 256 B; validate/resolve region; epilogue; `DAT_00a1e810` 16 B |
| Layout sibling | `UI_QuickBarSlotButton_AssignSkill_Inferred` `0x00826860` |
| Callee duals | LocalCastValidate, ResolveCastTarget, TFID_EqualsObjectId |

**Not performed:** `disassemble_bytes`, Launcher.

---

## 3. Control flow seal

| Stage | Match |
|---|---|
| `DAT_00d1b6d8==0` → false | **Yes** |
| `+0x548 != 1` → false | **Yes** (`CMP dword [ECX+0x548],1`) |
| `+0x558 == 0` → false | **Yes** (skill in ESI) |
| force-true `DAT_00d1b644+0xf5` | **Yes** (decompile) |
| LocalCastValidate skipBusy=1 | **Confirmed** (`push 1`) |
| accept codes 0 and 6 only | **Confirmed** (`test/jz; cmp 6/jnz false`) |
| `+0x614 & 0x800` clear → resolve | **Confirmed** (test/jle/mov al,1) |
| Equals invalid → false (setz) | **Confirmed** |
| plain `RET` | **Confirmed** |

Decompiler corrections:

| Topic | Correction |
|-------|------------|
| `(char)skill` to LocalCastValidate | **full pointer** in ESI (`push esi`) |
| `__fastcall` free-form | **thiscall** button object |
| void-ish paths | **bool AL** all exits |

---

## 4. Evidence table

| Claim | Evidence | Conf |
|---|---|---|
| Body 458 B | Ghidra `00829190–00829359` | **Confirmed** |
| payloadKind skill | `+0x548==1` + AssignSkill dual | **Confirmed** |
| skill* | `+0x558` | **Confirmed** |
| skipBusy=1 / {0,6} | call-site bytes | **Confirmed** |
| invalid sentinel content | `read_memory` `DAT_00a1e810` | **Confirmed** |
| Sole xref `00829883` | `get_xrefs_to` | **Confirmed** |
| Role name | layout + skill cast helpers | **Inferred** |

---

## 5. Gaps

1. Product English for bit `0x800` and force flag `+0xf5`.  
2. Full owning function of call site (Ghidra gap between BuildSkillWidgets and next FUN).  
3. Runtime / bit-exact / image diff.  
4. Why UI uses skipBusy=1 vs RequestCast's 0 (policy residual).

---

## 6. Verdict

**accept-with-gaps** — CF, ABI, layout gates, validate accept set, and resolve/invalid path are sealed; product glosses remain `_Inferred`.
