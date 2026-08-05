# Function record: CVOGHBSkillBase_DefaultCtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00578830` |
| **Canonical name** | `CVOGHBSkillBase_DefaultCtor` |
| **Ghidra name** | `FUN_00578830` |
| **Address** | `0x00578830` |
| **Body range** | `0x00578830`–`0x005788c8` (152 bytes) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` / heartbeat |
| **Completion status** | **partial** — dual A/B **accept**; RTTI + CF + bytes sealed; runtime/diff open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00578830_CVOGHBSkillBase_DefaultCtor.md`, `reviews/B_aa_00578830_CVOGHBSkillBase_DefaultCtor.md` (2026-07-29 W23-S) |
| **Last reviewed** | `2026-07-29` |

## Alias

- `FUN_00578830`
- `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_00578830` (legacy scaffold)
- Class RTTI: `CVOGHBSkillBase` (Confirmed)
- Sibling full ctor: `CVOGHBSkillBase_ctor` @ `0x005788d0`

## Purpose

**Default / empty** `CVOGHBSkillBase` constructor used as factory intermediate:

1. `CVOGHBBase_ctor`
2. Install `PTR_FUN_009d3fdc` (CVOGHBSkillBase vtbl)
3. `FUN_0054f3c0` on `this+0x24` (skill-runtime partial default)
4. Zero skill-HB tails (`+0x688`, `+0x6a0`, `+0x6b0..0x6b8`)
5. `AttachOwner(null)`
6. Seed TFID at `+0x678` from invalid sentinel `DAT_009d3f88`

Factories allocate `0x6c0`, call this, then **overwrite subclass vtbl**. Distinct from full ctor (blob copy + ValidateTarget + attach target + period).

## Signature

```c
CVOGHBSkillBase* __thiscall CVOGHBSkillBase_DefaultCtor(CVOGHBSkillBase* this);
// ECX = this; no stack formals; returns this
```

## Algorithm

```
SEH enter
CVOGHBBase_ctor(this)
*this = CVOGHBSkillBase_vtbl
SkillRuntime_PartialCtor(this+0x24)
zero tails
AttachOwner(null)
this.tfid_block = InvalidTfidSentinel
SEH leave
return this
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00578830_FUN_00578830.md`
- Annotated: `docs/reconstruction/raw/aa_00578830_FUN_00578830.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGHBSkillBase_DefaultCtor.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_00578830.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00578830_FUN_00578830.md`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00578830-005b3210-w23s-report.md`

## Callers / callees

| Direction | VA | Name / role |
|---|---|---|
| Callee | `0x00508200` | `CVOGHBBase_ctor` |
| Callee | `0x0054f3c0` | `SkillRuntime_PartialCtor` (ECX=`this+0x24`) |
| Callee | `0x005083b0` | `CVOGHBBase_AttachOwnerObject` (null) |
| Caller | many | skill-element factories `0x005485b0`…`0x005492a0`, `0x00548bd0`, … |
| Caller | `0x0054a640` | `SkillElementFactory_RegisterCatalog_Inferred` |
| Caller | `0x0054f250` | skill-HB intermediate |
| Caller | `0x00618100` | skill-HB intermediate |
| Caller | `0x0061b990` | skill-HB intermediate |
| Caller | `0x00651100` | skill-HB intermediate |

## Confidence

| Claim | Level |
|---|---|
| Control flow + bytes | **High** |
| Vtbl / RTTI = `CVOGHBSkillBase` | **Confirmed** |
| Role = empty default shell for factories | **High** |
| Distinct from full ctor `005788d0` | **High** |
| Product English method name | **Inferred / Open** |
| Runtime / differential | Open |
