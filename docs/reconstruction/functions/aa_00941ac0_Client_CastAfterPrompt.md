# Function record: Client_CastAfterPrompt

| Field | Value |
|---|---|
| **Stable ID** | `aa_00941ac0` |
| **Canonical name** | `Client_CastAfterPrompt` |
| **Address** | `0x00941ac0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Completion status** | **human-refined + dual A/B 2026-07-29** — `+0x30c0` → RequestCastSkill sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

| Name | Notes |
|---|---|
| `FUN_00941ac0` | Ghidra default / frozen raw header |
| `Named_CalleeOf_Client_InteractClickPickTarget_00941ac0` | old scaffold alias |
| cast-after-prompt | wave partition shorthand |

## Purpose

Complete the skill target-select prompt: cast pending skill id at `client+0x30c0` at the picked target TFID (`ESI`, typically `object+0x160`), then clear the prompt. Skips the send when `Client_CastBlockFeedback` reports blocked, but still clears.

## Signature (retail)

```c
// EDI = client*, ESI = TFID* (16 bytes), stack = aim float3*
void Client_CastAfterPrompt(void *pAim);  // RET 4
```

Clean readability form may thread client/TFID as explicit parameters; CF unchanged.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00941ac0_FUN_00941ac0.md`
- Annotated: `docs/reconstruction/raw/aa_00941ac0_FUN_00941ac0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Client_CastAfterPrompt.cpp`
- Residual: `docs/reconstruction/reviews/a_00941ac0.md`
- Dual A: `docs/reconstruction/reviews/A_aa_00941ac0_Client_CastAfterPrompt.md`
- Dual B: `docs/reconstruction/reviews/B_aa_00941ac0_Client_CastAfterPrompt.md`

## Callers / callees

**Callers (2 xrefs):**

| Address | Function | Gate / notes |
|---|---|---|
| `0x00924e29` | `Client_InteractClickPickTarget` | `DAT_00d1d900 != -1`; aim `DAT_00d1a640` |
| `0x00861a52` | `FUN_00861680` | same pending gate; aim `DAT_00d1a660` |

**Callees:**

| Address | Symbol | Role |
|---|---|---|
| `0x0093b7f0` | `Client_CastBlockFeedback` | allow/block + toast |
| `0x00941590` | `Client_RequestCastSkill` | C2S 0x2030 |
| `0x0093bac0` | `Client_PromptSkillTargetSelect` | clear pending (`EAX=-1`) |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + asm | **Confirmed** |
| `*(client+0x30c0)` → RequestCast skillId | **Confirmed** |
| EDI/ESI/aim ABI | **Confirmed** |
| `DAT_00d1d900` ≡ `+0x30c0` | **Confirmed** |
| Product name string in binary | N/A (role name) |
