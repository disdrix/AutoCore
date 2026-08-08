# Review A (reconstruction fidelity): `aa_0054cc10` SkillStaging_ZeroPayloadFields_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054cc10` |
| **VA** | `0x0054cc10`–`0x0054d43f` (2096 B / `0x830`) |
| **Canonical name** | `SkillStaging_ZeroPayloadFields_Inferred` (Ghidra `FUN_0054cc10`) |
| **Review date** | `2026-08-05` (OWN-ONLY dual A — R13-038) |
| **Reviewer role** | Independent reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_0054cc10_SkillStaging_ZeroPayloadFields_Inferred.md` |
| **System** | skills-abilities |
| **Dual status** | **Present (create / residual seal)** |
| **Dual start** | 2686 |
| **Partition parent dual** | `0x0054cbb0` (adjacency; not semantic) |
| **Semantic caller** | `0x0054a290` `SkillDef_InstallLoadedRecord` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_callers` + `get_function_xrefs` + `get_assembly_context` + `read_memory` + `get_function_by_address`. **No** `disassemble_bytes`. Caller dual of install path used for staging context only (not dualled here).

---

## 1. Purpose

**Skill-staging payload mid-field zero** (leaf):

1. `this` in ECX (thiscall).
2. Zero every dword/float slot from **`this+0x28` through `this+0x534`** inclusive (`0x144` dwords).
3. Retail encoding: `XORPS xmm0,xmm0` + `MOVSS`/`MOV` stores; terminal bare `RET`.
4. No callees, no branches, no SEH.

Sole direct use: prep step inside `SkillDef_InstallLoadedRecord` after the “no skill elements” gate, targeting a stack staging buffer of size **`0x538`** (`0x14e` dwords). Caller then fully clears that buffer with `REP STOSD`.

Does **not** allocate, does **not** install vtbls, does **not** touch skill-map trees, does **not** zero `this+0x00..+0x27`.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_0054cc10_FUN_0054cc10.md` | Append R13-038 re-verify |
| Annotated | `docs/reconstruction/raw/aa_0054cc10_FUN_0054cc10.annotated.md` | Refined |
| Clean named | `docs/reconstruction/reconstructed-exact/SkillStaging_ZeroPayloadFields_Inferred.cpp` | New/replace |
| Clean alias | `docs/reconstruction/reconstructed-exact/FUN_0054cc10.cpp` | Refined compact |
| Function record | `docs/reconstruction/functions/aa_0054cc10_SkillStaging_ZeroPayloadFields_Inferred.md` | New |
| Scaffold record | `docs/reconstruction/functions/aa_0054cc10_FUN_0054cc10.md` | Updated |
| Live decompile | Ghidra @ `0x0054cc10` | ≡ raw CF |
| Live bytes | `read_memory` entry + exit + body bounds | size/range/ret sealed |
| Xrefs / callers | complete + assembly context | 1 CALL; 0 DATA |
| Caller context | `FUN_0054a290` decompile + call-site bytes | staging ECX + post `REP STOSD` |

**Not performed:** Launcher, runtime golden, dual of caller/callees of install path, parent ledger edits.

---

## 3. Signature (image-sealed)

```c
// thiscall; ECX=self; 0 stack args; bare RET; void
void __fastcall SkillStaging_ZeroPayloadFields_Inferred(void *self);
```

| Item | Evidence | Conf |
|---|---|---|
| ECX = this at entry | `MOV EAX,ECX`; stores via `[EAX+imm]`; call-site `LEA ECX,[ESP+0x1a0]` | **High** |
| 0 stack args | bare `C3`; no stack arg loads | **High** |
| Void return | no EAX result path | **High** |
| Range `+0x28`..`+0x534` | decompile stores + exit `movss [eax+0x534]` | **High** |
| Count `0x144` dwords | arithmetic on sealed bounds | **High** |
| Body size `0x830` / end `0x0054d43f` | `get_function_by_address` + exit bytes | **High** |
| Leaf | callees empty; no CALL in body | **High** |
| Role “SkillStaging ZeroPayloadFields” | sole caller + staging size context | **Inferred** |
| Not PossessCreature factory | adjacent VA only; different CF | **High** |

---

## 4. Byte seal (entry / exit / call site)

| Site | Bytes / fact | Meaning |
|---|---|---|
| `0x0054cc10` | `0F 57 C0` | `xorps xmm0,xmm0` |
| `0x0054cc13` | `8B C1` | `mov eax,ecx` (this) |
| `0x0054cc15` | `F3 0F 11 40 2C` | `movss [eax+0x2c],xmm0` |
| `0x0054cc1a` | `F3 0F 11 40 30` | `movss [eax+0x30],xmm0` |
| `0x0054cc1f` | `33 C9` | `xor ecx,ecx` (zero source) |
| `0x0054cc21` | `89 48 28` | `mov [eax+0x28],ecx` |
| `0x0054d438` | `F3 0F 11 80 34 05 00 00` | `movss [eax+0x534],xmm0` |
| `0x0054d43f` | `C3` | bare ret |
| Call `0x0054a2ca` | `8D 8C 24 A0 01 00 00` | `lea ecx,[esp+0x1a0]` |
| Call `0x0054a2d1` | `E8 …` → `0x0054cc10` | sole CALL |
| Post `0x0054a2d8` | `B9 4E 01 00 00` + `F3 AB` | `mov ecx,0x14e; rep stosd` |

---

## 5. Control flow: clean ≡ raw ≡ live decompile ≡ bytes

| Stage | Match |
|---|---|
| No branches / no SEH / no calls | **Yes** |
| Zero `+0x28`..`+0x534` inclusive | **Yes** |
| Bare RET void | **Yes** |
| Compact loop ≡ store cloud final state | **Yes** |
| Not factory / not map insert / not full memset of object | **Yes** |

---

## 6. Gaps / open

1. Product English for individual fields inside `+0x28..+0x534`.
2. Why mid-zero runs before full `0x14e` clear on the only path (subset redundancy).
3. Indirect reachability beyond the single CALL (none found; catalog still open for non-static).
4. Runtime / bit-exact / differential — open (Terminal false).

**Verdict:** **accept-with-gaps** — CF/ABI/range/leaf/caller sealed; role English Inferred; per-slot names + runtime open.
