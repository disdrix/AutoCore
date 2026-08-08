# Function record: CVOGPhysics_WriteNotFullyReadyOut_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404e00` |
| **Canonical name** | `CVOGPhysics_WriteNotFullyReadyOut_Inferred` |
| **Ghidra name** | `FUN_00404e00` |
| **Address** | `0x00404e00`–`0x00404e22` inclusive (**35 B** / `0x23`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | physics |
| **Partition seed** | skills-abilities / RecvSkillStatusEffect nested (MEGA-049) |
| **Completion status** | **Dual sealed MEGA-049** — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `reviews/A_aa_00404e00_CVOGPhysics_WriteNotFullyReadyOut_Inferred.md`, `reviews/B_aa_00404e00_CVOGPhysics_WriteNotFullyReadyOut_Inferred.md` |
| **Report** | `docs/agents/task-dual-ab-00404e00-mega-049-report.md` |

## Alias

- Ghidra: `FUN_00404e00`
- Retired: `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_00404e00`
- Twin record: `aa_00404e00_FUN_00404e00.md`

## Purpose

Leaf helper on **CVOGPhysics**: write whether the object is **not** fully ready into a caller out-byte.

```text
fully_ready = (byte(phys+0x40) != 0) && (dword(phys+0x08) != 0)
*out = fully_ready ? 0 : 1
return out   // EAX
```

Callers branch on `*out != 0` to take soft physics / heading / AI state paths. Same `+0x40`/`+0x08` dual gate as dualed `CVOGPhysics_SetRotation` fully-ready skip (inverted consumer polarity).

## Signature

```c
// ECX = CVOGPhysics*; stack = uint8_t* out; RET 4; EAX = out
uint8_t *__thiscall CVOGPhysics_WriteNotFullyReadyOut_Inferred(int phys, uint8_t *out);
```

## Layout (this = CVOGPhysics)

| Off | Use |
|---:|---|
| `+0x08` | Nonzero contributes to fully-ready (with `+0x40`) |
| `+0x40` | Byte; nonzero contributes to fully-ready |

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_00404e00_FUN_00404e00.md`
- Annotated: `docs/reconstruction/raw/aa_00404e00_FUN_00404e00.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGPhysics_WriteNotFullyReadyOut_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_00404e00.cpp`
- Scaffold retired: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_00404e00.cpp`

## Callers / callees

| Item | Value |
|---|---|
| Callees | none (leaf) |
| Callers | `Skill_ApplyBoundStatusMotionTable_Inferred` (`FUN_005d0d60`) @ `0x005d0fb6`; `CVOGHBAICreatureBase_DoLogic` (`FUN_005d7f70`) @ `0x005d80a5` |
| Call-site this | `ECX = *(entity + 0x08)` (phys) |
| xref_count | 2 |

## Family

| Peer | VA | Relation |
|---|---|---|
| `CVOGPhysics_SetRotation` | `0x00404dc0` | same fully-ready fields; skips body vtbl when ready |
| setPosition peer | `0x0040d2a0` | same fully-ready skip; vtbl +0x40 |
| ready probe | `0x005070b0` | different fields (`+0x44` / `+0x29`) |

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / RET 4 / leaf / polarity | **High** |
| CVOGPhysics this via entity+8 | **High** |
| `_Inferred` product English | required — no PDB |
| Runtime Confirmed | Open |

## Gaps

1. Product English for `+0x40` / `+0x08`.
2. Runtime / bit-exact / differential.
3. Parent ledger lockstep (OWN-ONLY — not done here).
