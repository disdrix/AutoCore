# Function record: Skill_LookupActiveCastBinding

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518cf0` |
| **Canonical name** | `Skill_LookupActiveCastBinding` |
| **Address** | `0x00518cf0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **Dual residual complete (accept-with-gaps)** — 2026-07-29 (ABI/ECX re-seal); prior scaffold 2026-07-23 |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Read-only **active-cast binding** lookup by skill id. Writes a **16-byte TFID** to the out buffer from map node value fields `+0x18…+0x24`, or the invalid TFID sentinel `g_abTfidInvalid_9CDF88` when the skill id is not bound. Map shell: leave-FUN `FUN_00518c20` (`owner+0x68`). Find: `FUN_0051c150` (key @ `node+0x10`). **Entry ECX** = map owner.

## Signature (decompiler-derived + body-byte residual)

```c
/* Skill_LookupActiveCastBinding(mapOwner_ECX, outTfid16, skillId)
   void — writes 16 bytes through pOutTfid.
   Stack: [+4]=pOut, [+8]=nSkillId; ECX=mapOwner (Ghidra may omit).
   Epilogue both arms: ret 8  (__stdcall stack cleanup Confirmed). */

void Skill_LookupActiveCastBinding(void *pOutTfid, int nSkillId /* + ECX mapOwner */);
```

## Behavior (High CF — dual A/B residual 2026-07-29)

```c
// Noise-corrected CF (do not trust multi-arg FUN_00518c20 in raw decompile)
// mapOwner = ECX on entry (mov esi,ecx)
pMap = FUN_00518c20(mapOwner);              // lazy map* @ +0x68; sites 0x00518d00, 0x00518d0e
FUN_0051c150(pMap, &it, &nSkillId);         // find; key int @ node+0x10
if (it != *(int *)(pMap + 4)) {             // not end (_Myhead)
  copy16(pOutTfid, it + 0x18);              // TFID value
} else {
  copy16(pOutTfid, g_abTfidInvalid_9CDF88); // 0x009cdf88 = (-1,-1,0,0)
}
// ret 8
```

| Item | Value | Conf |
|---|---|---|
| Out width | **16 bytes** (TFID) | **Confirmed** |
| Hit source | `node+0x18…+0x24` | **Confirmed** |
| Miss sentinel | `g_abTfidInvalid_9CDF88` @ `0x009cdf88` | **Confirmed** |
| Sentinel bytes | `FF×8 + 00×8` | **Confirmed** (`read_memory`) |
| Twin invalid (callers) | `g_abTfidInvalid_A15870` @ `0x00a15870` (same static bytes; **not** map) | **Confirmed** |
| Map getter | `FUN_00518c20` leave-FUN | **Confirmed** |
| Find | `FUN_0051c150` (exact) | **Confirmed** |
| Entry ECX = mapOwner | **Yes** | **Confirmed** (body bytes) |
| `__stdcall` `ret 8` | both arms | **Confirmed** (body bytes) |
| Mutates map | **No** | **Confirmed** |

## Decision notes (residual)

| Prior gap | Residual result |
|---|---|
| Full out-struct layout | **Sealed** TFID16 |
| DAT_00a15870 map identity | **Falsified** — invalid TFID twin, not map |
| `__stdcall` / ret cleanup | **Sealed** `ret 8` both arms |
| Map owner register | **Sealed** entry ECX |
| Map owner product type | **Still open** (with `aa_00518c20`) |

Do **not** rename `FUN_00518c20` from this unit (sibling leave-FUN bar).

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00518cf0_Skill_LookupActiveCastBinding.md`
- Annotated: `docs/reconstruction/raw/aa_00518cf0_Skill_LookupActiveCastBinding.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Skill_LookupActiveCastBinding.cpp`
- Dual A/B: `docs/reconstruction/reviews/A_aa_00518cf0_Skill_LookupActiveCastBinding.md`, `B_aa_00518cf0_Skill_LookupActiveCastBinding.md`
- Residual scratch: `docs/reconstruction/reviews/a_00518cf0.md`
- Map getter: `docs/reconstruction/functions/aa_00518c20_FUN_00518c20.md`

## Callers / callees

### Callees

| Address | Name | Role |
|---|---|---|
| `0x00518c20` | `FUN_00518c20` | Lazy active-cast map shell @ `this+0x68` |
| `0x0051c150` | `FUN_0051c150` | Map find by skill id |

### Callers (9 sites / 8 funcs)

| Caller | Sites | Notes |
|---|---|---|
| `Skill_LocalCastValidate` | `0x0051a83d` | unbound → skill gate ladder |
| `Client_RequestCastSkill` | `0x009416e4`, `0x00941762` | unbound → HB / FX |
| `Client_Skill_ResolveCastTarget` | `0x0093b759` | sticky: bound → silent invalid list |
| `Client_StanceOrGadgetActivatePath` | `0x0093a4de` | cast-again gate |
| `Skill_ApplyStatusEffectLocal` | `0x0051ab1c` | status apply |
| `Client_RecvSkillStatusEffect` | `0x00811496` | S2C 0x2031 |
| `FUN_00521650` | `0x005216a7` | summon HB |
| `FUN_00525cc0` | `0x00525d4a` | packet helper |

## Confidence

| Claim | Level |
|---|---|
| Control flow hit/miss | **Confirmed** |
| Out = TFID16 | **Confirmed** |
| Key = skill id | **Confirmed** |
| Entry ECX = mapOwner | **Confirmed** |
| Parameter names (`pOutTfid`, `nSkillId`) | **High** (callers + plate) |
| Map owner product type | **Open** |
| `__stdcall` `ret 8` | **Confirmed** (body bytes) |
| Runtime / bit-exact | **Open** |
