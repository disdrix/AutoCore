# Annotated low-level: Skill_RangeCheckTargetForResolveList_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_0058c0a0` |
| VA | `0x0058c0a0` |
| Canonical name | `Skill_RangeCheckTargetForResolveList_Inferred` |
| Prior | `FUN_0058c0a0` |
| System | skills-abilities |
| Date | 2026-07-29 |

## Machine-level notes

- **Sole caller:** `Skill_ResolveTargetList` (`0x00550300`) — range stage **after** `Skill_FilterTargetForResolveList_Inferred` and optional type `0x12`/`0x14` vehicle remap.
- Formals (cdecl-style stack args in decompiler):
  - `param_1` = **pTarget** (object pointer; may be vehicle body after remap)
  - `param_2` = **pSource** (caster / source object from ResolveTargetList `param_4`)
  - `param_3` = **flRangeMin** from `skill+0x2c`
  - `param_4` = **flRangeMax** from `skill+0x28`
  - `param_5` = skill field `skill+0x34` (passed into target vtbl `+0x1c8` path prep)
  - `param_6` = flag byte `skill+0x5e7` (gates a vehicle-transform branch)
- **Return contract (caller-visible):**
  - `g_flZero` (0.0) → **out of range / fail** — ResolveTargetList does `*outFlags |= 2` then falls into no-primary path
  - non-zero → **in range / pass** — primary TFID written to out list
    - measured distance when `flRangeMin <= dist <= flRangeMax`
    - `g_flOne` on several **auto-pass** paths (self, same parent, missing geometry, etc.) without band test
- Does **not** write `outFlags` itself; only supplies the zero/non-zero signal for bit **2**.

## Control flow (ordered)

```text
1. if pSource == pTarget OR pSource == pTarget[0x2b] (parent/owner slot):
     return g_flOne                          // auto-pass (self / same parent)
2. sourcePhys = pSource.vtbl+0x1c8()
   vehicleish = pSource.vtbl+0x214()         // optional vehicle/body handle
   if vehicleish:
     occupantOrBody = *(vehicleish + 0x250)
     if (target shares occupantOrBody via vtbl+0x1d4) OR
        (target.vtbl+0x1d8() == vehicleish): return g_flOne  // same vehicle
3. parent = pTarget[0x2b]
   if parent != null AND (parent type == 0xe OR parent == pSource):
     // hardpoint / seat ownership gate with FUN_004f70f0(TFID)
     either auto-pass (g_flOne) or fail (g_flZero)
4. if (no sourcePhys or sourcePhys+8==0) AND no vehicleish: return g_flOne
5. Build two stack quads from globals DAT_00af32a0 / DAT_00b04dd0
   Transform via FUN_00404a20 / FUN_004e8a40 / FUN_00404c90
   Optional vehicle matrix path when vehicleish+0x30c set / skill+0x5e7 clear
6. scale = g_flOne; maybe scale from phys vtbl+0x19c → +0x34
   flag = phys vtbl+0x210(0) ? 1 : 0
7. pTarget.vtbl+0x1c8(&stackTransform, skill+0x34, flag)
8. dist = FUN_004e9aa0(&posQuad, scale, flRangeMax, flagResult)
9. if flRangeMin <= dist <= flRangeMax: return dist
   else: return g_flZero
```

## Call-site binding (ResolveTargetList)

```c
// after FilterTarget accept + optional type 0x12/0x14 remap → piVar6
fVar7 = Skill_RangeCheckTargetForResolveList_Inferred(
          piVar6, param_4 /* source */,
          *(float*)(skill + 0x2c),   // min
          *(float*)(skill + 0x28),   // max
          *(uint32*)(skill + 0x34),
          *(char*)(skill + 0x5e7));
if (fVar7 == g_flZero) {
  *outFlags |= 2;   // range — CastSkillOnTarget maps bit2 → eSkillResponses 0x0D
  // fallthrough no-primary path
}
```

## Field map

| Offset | Object | Role |
|---|---|---|
| `skill+0x28` | float | range **upper** (max) — `param_4` / band high |
| `skill+0x2c` | float | range **lower** (min) — `param_3` / band low |
| `skill+0x34` | ? | into target vtbl `+0x1c8` with transform |
| `skill+0x5e7` | u8 | when clear, enables vehicle-transform branch with `FUN_00567ce0` / `FUN_004cb590` |
| obj `[0x2b]` | ptr | parent / owner object |
| type via `[0x2a]+0x38` | i32 | `0xe` used in parent-type gate |
| vehicleish `+0x250` | ptr | linked occupant/body |
| vehicleish `+0x30c` | char | vehicle ready/valid flag |

## Callees

| Addr | Role (this unit) |
|------|------------------|
| `FUN_00404a20` | transform/copy helper |
| `FUN_004e8a40` | matrix/quat apply |
| `FUN_00404c90` | extract position/quad after transform |
| `FUN_004cb590` | vehicle-related transform |
| `FUN_004e9aa0` | distance / range measure (returns float10) |
| `FUN_004f70f0` | TFID-related gate on parent path |
| `FUN_00567ce0` | rotate/orient helper with `DAT_00af3290` |

## Confidence

| Claim | Level |
|---|---|
| Sole caller ResolveTargetList | **Confirmed** (callers + single xref `00550416`) |
| Return 0 → outFlags bit2 in caller | **Confirmed** |
| Band uses skill+0x2c min / +0x28 max | **Confirmed** (call site + body compare) |
| Auto-pass returns `g_flOne` without band | **Confirmed** |
| Product original name | **Inferred** (no string/RTTI) |
| Full geometry of FUN_004e9aa0 / vtbl slots | Partial / open |

## Open questions

1. English product names for skill `+0x28/+0x2c/+0x34/+0x5e7`.
2. Exact vtbl `+0x1c8` / `+0x214` / `+0x1d4` / `+0x1d8` / `+0x210` product methods.
3. Whether measured distance is consumed anywhere beyond zero/non-zero (ResolveTargetList only tests `== g_flZero`).

---

## Dual residual append 2026-07-29 — return0 → outFlags bit2 (asm)

| Item | Detail | Conf |
|------|--------|------|
| Call | `00550416 CALL 0x0058c0a0` sole xref | **Confirmed** |
| Zero load | `0055041b FLD [0x00a0f518]` = `g_flZero` (`00 00 00 00`) | **Confirmed** |
| Equal fail | MSVC `FUCOMIP` / `TEST AH,0x44` / `JNP 005504ce` | **Confirmed** |
| OR bit2 | `005504d1 OR dword [EAX], 0x2` (`EAX` = outFlags*) | **Confirmed** |
| Fallthrough | no-primary `LAB_005504d7` (same as null-filter path) | **Confirmed** |
| `g_flOne` | `0x00a0f2a0` = `00 00 80 3f` | **Confirmed** |

Closes decomp-only residual on the bit2 OR. Dual A/B + function record updated. Does **not** touch WORK_QUEUE/RESUME/ACTIVE_WORK/CHANGE_LOG.
