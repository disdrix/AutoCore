# Function record: CVOGHBBase_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508200` |
| **Canonical name** | `CVOGHBBase_ctor` |
| **Address** | `0x00508200`–`0x0050822c` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `heartbeat` / timed-actions |
| **Completion status** | **Dual residual sealed 2026-07-29** — layout + init High; type-tag enum incomplete |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Construct generic heartbeat base object (`sizeof` **0x28**): install base vtbl, zero dual period fields + owner + type tag, set **fDormant**, seed **dwLastFireTickMs** from **g_dwClientTickMs**. Subclasses overwrite vtbl and configure period/type/owner before `Start`.

## Signature (machine-sealed)

```c
void __thiscall CVOGHBBase_ctor(void *this);  // ECX = this; bare ret
```

## Sealed facts (residual)

| Claim | Level |
|---|---|
| Init store set (vtbl, periods, lastFire, dormant/stopped, owner, type, ref) | **High** |
| `sizeof(CVOGHBBase)==0x28`; dual period +0x08 / +0x0C | **High** |
| `g_dwClientTickMs` @ `0x00b041cc` | **High** |
| +0x1C type-tag role; values 0/1/4/8 from siblings | **High** (role) / enum open |
| +0x22..+0x27 not written by ctor | **High** |
| Control flow decompile ≡ machine | **High** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00508200_CVOGHBBase_ctor.md`
- Annotated: `docs/reconstruction/raw/aa_00508200_CVOGHBBase_ctor.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBBase_ctor.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_00508200_CVOGHBBase_ctor.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00508200_CVOGHBBase_ctor.md`
- Residual: `docs/reconstruction/reviews/a_00508200.md`

## Callers / callees

- **Callees:** none
- **Callers:** many HB subclass ctors (Regeneration, OKToCastAgain, SkillBase, WeaponTrack, WakeupSkill, mission/token factories, …) — see residual xref list

## Gaps

- Full product enum for `nTypeTag`
- `nRefOrFlags` readers
- Allocator pre-zero of tail bytes
