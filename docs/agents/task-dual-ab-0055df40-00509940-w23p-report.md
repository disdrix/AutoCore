# OWN-ONLY dual agent report — W23-P

| Field | Value |
|---|---|
| Agent | W23-P |
| Workspace | `C:\Users\josh\Documents\GitHub\AutoCore` |
| Module | `autoassault.exe` base `0x400000` |
| Owned VAs | `0x0055df40`, `0x00509940` |
| Tools | Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`) |
| Launcher | **not** started |
| Parent ledger | **not** edited |
| Date | 2026-07-29 |

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_0055df40` `ActionManager_UnregisterAndRelease_Inferred` | **accept-with-gaps** — 54 B thiscall ret 4; notify+list-remove+clear+0xC+release sealed; product English open |
| `aa_00509940` `GetModifierSkillID` | **accept-with-gaps** — 312 B thiscall ret 4; product name High; map→type→tables→`+0x9c`; fallthrough-on-miss sealed |

---

## VA `0x0055df40` — ActionManager_UnregisterAndRelease_Inferred

| Field | Value |
|---|---|
| Ghidra | `FUN_0055df40` |
| Canonical | `ActionManager_UnregisterAndRelease_Inferred` (**Inferred** — no plate string) |
| Body | `0x0055df40`–`0x0055df76` exclusive (**54** / `0x36` B); last `ret 4` |
| Role | Unregister action from manager listeners + reverse host list; clear `action+0xC`; release short ref `@+6` |
| ABI | ECX=`manager` (often `*(world+0xe4a4)`), stack `action*`, **`ret 4`**, void |
| Callers | `FUN_004f7d60` (Vehicle_DestroyVehicleAction_Inferred), `FUN_00507830`, `FUN_006427e0`, `FUN_00642860` |
| Callees | `FUN_0062a410`, `FUN_00628f10` |
| Live ≡ raw | Yes (+ decomp residual: `00628f10` this = `*(action+0x10)`) |
| **Verdict** | **accept-with-gaps** |

### Sealed facts

1. **Bytes:** full 54 B body via `read_memory`; `C2 04 00` epilogue.
2. **Order:** `FUN_0062a410(manager, action)` → `FUN_00628f10(*(action+0x10), action)` → `ref@+6--` → `*(action+0xC)=0` → if ref==0 `(*vtbl[0])(action,1)`.
3. **Not pure Release** — always notifies and unlinks first.
4. **Callers may re-release** short@+6 after return (seen in `004f7d60`).

### Gaps

1. Product English for manager / action classes.  
2. Nested duals of `0062a410` / `00628f10` / `005fff20` (not owned).  
3. Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_0055df40_ActionManager_UnregisterAndRelease_Inferred.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_0055df40_ActionManager_UnregisterAndRelease_Inferred.md` | **accept-with-gaps** |

### Artifacts

- `docs/reconstruction/raw/aa_0055df40_FUN_0055df40.md`
- `docs/reconstruction/raw/aa_0055df40_FUN_0055df40.annotated.md`
- `docs/reconstruction/reconstructed-exact/ActionManager_UnregisterAndRelease_Inferred.cpp`
- `docs/reconstruction/reconstructed-exact/FUN_0055df40.cpp`
- `docs/reconstruction/functions/aa_0055df40_ActionManager_UnregisterAndRelease_Inferred.md`
- `docs/reconstruction/functions/aa_0055df40_FUN_0055df40.md`
- `docs/reconstruction/reviews/A_aa_0055df40_ActionManager_UnregisterAndRelease_Inferred.md`
- `docs/reconstruction/reviews/B_aa_0055df40_ActionManager_UnregisterAndRelease_Inferred.md`

---

## VA `0x00509940` — GetModifierSkillID

| Field | Value |
|---|---|
| Ghidra | `FUN_00509940` |
| Canonical | `GetModifierSkillID` (**High** — plate string @ `0x009cdc88`) |
| Body | `0x00509940`–`0x00509a78` exclusive (**312** / `0x138` B); jump table @ `0x00509a7c` |
| Role | IDPrefix → map type → handler table → skill id at `entry+0x9c`, else `-1` |
| ABI | ECX=`registry`, stack `idPrefix`, **`ret 4`**, return `int32` / `-1` |
| Callers | `FUN_004fdcb0` (×2), `FUN_005cb8f0`, `FUN_005cbb20`, `FUN_005cc070`, `FUN_005cc2a0` |
| Callees | `Map_LowerBoundFindByIntKey`, `FUN_00508ac0`/`b10`/`b60`/`bb0`/`c00`/`c50`, `FUN_007a4480` |
| Live ≡ raw | Yes (+ ABI residual: thiscall ECX) |
| **Verdict** | **accept-with-gaps** |

### Sealed facts

1. **Product name** sealed by `"GetModifierSkillID() passed an invalid IDPrefix: %i\n"`.
2. **Map** `DAT_00b041dc` / end `DAT_00b041e0`; type at node `+0x10`.
3. **Cases:** `0xC→00508ac0`, `0x1C→00508b10`, `0xA→00508b60`, `0xE→00508bb0`, `0x46→00508c00` (HandlerTable54), `0x44→00508c50` (HandlerTable58).
4. **Success:** `*(entry+0x9c)`; **fail:** log + `0xFFFFFFFF`.
5. **Fallthrough-on-miss:** failed lookup continues into subsequent case bodies.
6. Map-miss log reuses GetTypeFromIDPrefix plate — **does not** rename this unit.

### Gaps

1. Registry class English.  
2. Type-code taxonomy labels.  
3. Intent of fallthrough failover.  
4. Runtime prefix→skill golden.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00509940_GetModifierSkillID.md` | **accept-with-gaps** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00509940_GetModifierSkillID.md` | **accept-with-gaps** |

### Artifacts

- `docs/reconstruction/raw/aa_00509940_FUN_00509940.md`
- `docs/reconstruction/raw/aa_00509940_FUN_00509940.annotated.md`
- `docs/reconstruction/reconstructed-exact/GetModifierSkillID.cpp`
- `docs/reconstruction/reconstructed-exact/FUN_00509940.cpp`
- `docs/reconstruction/reconstructed-exact/Skill_GetModifierSkillID_passed_an_invalid_IDPrefix_i_00509940.cpp`
- `docs/reconstruction/functions/aa_00509940_GetModifierSkillID.md`
- `docs/reconstruction/functions/aa_00509940_FUN_00509940.md`
- `docs/reconstruction/reviews/A_aa_00509940_GetModifierSkillID.md`
- `docs/reconstruction/reviews/B_aa_00509940_GetModifierSkillID.md`

---

## Notes

- No Launcher. No parent ledger / `ACTIVE_WORK` / partition map edits.
- Did not write dual artifacts for non-owned helpers (`0062a410`, `00628f10`, `00508ac0`…`00508bb0`, `Map_LowerBoundFindByIntKey`, `007a4480`, …). Nested handler duals `00508c00`/`00508c50` already sealed by prior agents.
- Prior raw bodies preserved; W23-P live seal sections appended.
- Clean plates prefer named CF; FUN_* / string-scaffold aliases updated to sealed bodies.

## This report

`docs/agents/task-dual-ab-0055df40-00509940-w23p-report.md`
