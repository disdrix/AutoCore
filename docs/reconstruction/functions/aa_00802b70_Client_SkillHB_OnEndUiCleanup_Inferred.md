# Function record: Client_SkillHB_OnEndUiCleanup_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00802b70` |
| **Canonical name** | `Client_SkillHB_OnEndUiCleanup_Inferred` |
| **Ghidra** | `FUN_00802b70` |
| **Address** | `0x00802b70`–`0x00802c7b` exclusive (**0x10B** / **267 B**) |
| **Module** | `autoassault.exe` base `0x400000` |
| **System** | `skills-abilities` |
| **Wave** | MEGA-020 dual seal 2026-08-05 |
| **Verdict** | **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (no Launcher) |

## Alias

| Name | Role |
|---|---|
| `FUN_00802b70` | Ghidra / scaffold twin |
| `Client_SkillHB_OnEndUiCleanup_Inferred` | dual preferred (`_Inferred`: no product string) |
| `Named_CalleeOf_Named_Client_InitInstance_00802b70` | **retired** |

## Purpose

Client-side skill HB OnEnd **UI cleanup** installed at `PTR_FUN_00af31e0` by Client InitInstance and called first from dualed `Skill_HB_OnEnd_ClearTargetFxAndCastBinding_Inferred` (`0x00578ce0`) as `(hb, 0)`.

### Sealed behavior

1. Null-check `skillHb`.
2. If `DAT_00d1d8e0+0x514 == skillHb` → `FUN_007fc970` with ESI = client `0x00d1a840` (clear UI sheet bind).
3. Require `DAT_00d1b6d8` (local player) and `skillHb+0x18` (owner).
4. **Local owner** (`owner.vtbl+0x1dc == local` or `owner.vtbl+0x1d4 == local+0x250`):
   - If vehicle inv sheet `DAT_00d1b8b8` ready (`vtbl+0x3d8`) → `UI_VehicleInvSheet_RebuildStatsLabels_Inferred`.
5. **Non-local owner**:
   - Gate `skillHb+0xfe`; resolve via `Object_ResolveTargetViaReaction_Inferred` (×3 sites);
   - If resolved is local-keyed → `FUN_008027e0(owner)`.
6. If `DAT_00d1b8ec+0x590` → `FUN_0083bf40(list, skillHb)`.

## Signature

```c
void __stdcall Client_SkillHB_OnEndUiCleanup_Inferred(void* skillHb, int unused /* always 0 from OnEnd */);
// RET 0x8; not thiscall; void return
```

## Artifacts

| Kind | Path |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00802b70_FUN_00802b70.md` |
| Annotated | `docs/reconstruction/raw/aa_00802b70_FUN_00802b70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_SkillHB_OnEndUiCleanup_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00802b70.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_Client_InitInstance_00802b70.cpp` |
| Function scaffold | `docs/reconstruction/functions/aa_00802b70_FUN_00802b70.md` |
| A/B | `reviews/A_aa_00802b70_Client_SkillHB_OnEndUiCleanup_Inferred.md`, `B_…` |
| Report | `docs/agents/task-dual-ab-00802b70-mega-020-report.md` |

## Callers / callees

**DATA registration:** `FUN_0094a6a0` Client InitInstance → `PTR_FUN_00af31e0`.

**Indirect CODE:** dualed OnEnd `0x00578ce0`.

**Sibling:** `FUN_00802c80` @ `PTR_FUN_00af31e4` (FireTail client hook — not this unit).

**Callees:** `FUN_007fc970`, `0x00578270` (dualed resolve), `FUN_008027e0`, `0x0087d810` (dualed sheet rebuild), `FUN_0083bf40`.

## Gaps

- Product / PDB symbol.
- Residual callee duals (`007fc970`, `008027e0`, `0083bf40`).
- Owner/target vfunc English; UI host globals English.
- Runtime / bit-exact / differential.

## Port notes

- Port as **stdcall RET 8** client OnEnd UI hook, not thiscall skill body.
- Wire via the same function-pointer slot parent OnEnd uses.
- Keep distinct from FireTail twin `00802c80` / `00af31e4`.
- Preserve local vs non-local branch split and three re-resolve calls.
- Terminal **false**.
