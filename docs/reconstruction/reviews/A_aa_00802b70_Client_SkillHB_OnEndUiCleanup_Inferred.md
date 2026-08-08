# Review A (reconstruction fidelity): `aa_00802b70` Client_SkillHB_OnEndUiCleanup_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00802b70` |
| **VA** | `0x00802b70`–`0x00802c7b` exclusive (**0x10B** / **267 B**) |
| **Canonical name** | `Client_SkillHB_OnEndUiCleanup_Inferred` |
| **Ghidra name** | `FUN_00802b70` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_00802b70_Client_SkillHB_OnEndUiCleanup_Inferred.md` |
| **System** | `skills-abilities` |
| **Agent** | MEGA-020 OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** — CF/ABI/registration/OnEnd invoker sealed; product English + nested residual callees open |

---

## 1. Purpose

Client-side **skill HB OnEnd UI cleanup** function-pointer body. Registered at `PTR_FUN_00af31e0` during Client InitInstance; invoked first by dualed `Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred` as `(hb, 0)`. Clears UI skill bind, rebuilds vehicle inv labels when local-owned, tears down owner UI panels when non-player path matches local target, and removes the skill from a UI list controller.

```c
// __stdcall; RET 0x8; arg2 unused
void Client_SkillHB_OnEndUiCleanup_Inferred(void* skillHb, int unused);
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00802b70_FUN_00802b70.md` |
| Annotated | `docs/reconstruction/raw/aa_00802b70_FUN_00802b70.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Client_SkillHB_OnEndUiCleanup_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00802b70.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_Client_InitInstance_00802b70.cpp` |
| Live Ghidra | `decompile_function` / `analyze_function_complete` / `disassemble_function` / `read_memory` / xrefs / callees / `get_assembly_context` |
| Parent OnEnd dual | `A_aa_00578ce0_Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred` |
| Resolve dual | `aa_00578270_Object_ResolveTargetViaReaction_Inferred` |
| Sheet rebuild dual | `aa_0087d810_UI_VehicleInvSheet_RebuildStatsLabels_Inferred` |

**No** `disassemble_bytes`. Constants/gates from decompile + `disassemble_function` + `read_memory`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `0x00802b70`–`0x00802c7b` excl. | **Confirmed** | `get_function_by_address` + epilogue `RET 8` |
| `__stdcall` two stack args; `RET 0x8` | **Confirmed** | `C2 08 00`; OnEnd pushes `(hb, 0)` |
| Arg2 unused | **Confirmed** | no read of second stack slot in body |
| Not thiscall | **Confirmed** | ECX reused for vfunc this only |
| Live decompile ≡ raw CF | **Confirmed** | 2026-08-05 re-decompile |
| `PTR_FUN_00af31e0` registration | **Confirmed** | InitInstance `MOV [00af31e0], 802b70` @ `0x0094a981` |
| OnEnd invoker | **Confirmed** | dualed `00578ce0` first call via PTR |
| Sibling FireTail PTR `00af31e4` | **Confirmed** | InitInstance next store `FUN_00802c80` |
| UI bind clear when `d1d8e0+0x514 == hb` | **Confirmed** | CMP + `FUN_007fc970` with ESI=`0xd1a840` |
| Local-owner → sheet rebuild `0087d810` | **Confirmed** | dualed callee; gate `vtbl+0x3d8` |
| Non-local → resolve + `008027e0(owner)` | **Confirmed** | three `00578270` thiscall sites; gate `+0xfe` |
| Common `0083bf40(ui+0x590, hb)` | **Confirmed** | dual push order |
| Product C++ name | **Inferred** | no string/RTTI on this VA → `_Inferred` |

---

## 4. Control flow summary

| Stage | Behavior |
|---|---|
| Null HB | early return |
| Tracker match | clear client UI skill bind (`007fc970`) |
| No local / no owner | return after optional bind clear |
| Owner is local (`vtbl+0x1dc`/`+0x1d4` vs `d1b6d8`/`+0x250`) | optional vehicle inv sheet rebuild |
| Else | gate `+0xfe`; resolve target; if local-related → `008027e0(owner)` |
| Join | if UI host list non-null → `0083bf40(list, hb)` |

---

## 5. Gaps (acceptable)

1. Product / PDB symbol (keep `_Inferred`).
2. English for owner/target `vtbl+0x1dc` / `+0x1d4` and `local+0x250`.
3. Nested residual callees not OWN: `FUN_007fc970`, `FUN_008027e0`, `FUN_0083bf40`.
4. Full type English for `DAT_00d1d8e0` / `DAT_00d1b8ec` / client `0x00d1a840`.
5. Runtime / bit-exact / differential (Terminal false; no Launcher).

**Verdict:** **accept-with-gaps** under `_Inferred` name.

---

## Checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **Pass** |
| ABI / epilogue sealed (`RET 8`) | **Pass** |
| Registration + OnEnd invoker | **Pass** |
| Named clean + scaffold twin; Named_CalleeOf retired | **Pass** |
| Verdict | **accept-with-gaps** |
