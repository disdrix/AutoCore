# Function record: Client_CastBlockFeedback

| Field | Value |
|---|---|
| **Stable ID** | `aa_0093b7f0` |
| **Canonical name** | `Client_CastBlockFeedback` |
| **Address** | `0x0093b7f0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `skills-abilities` |
| **Completion status** | **Dual A/B accept-with-gaps** — dead/waiting/town strings sealed; predicate product names open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Ghidra: `FUN_0093b7f0`
- Prior scaffold: `Named_CalleeOf_Client_CastSkillFromQuickBarSlot_0093b7f0`
- Role: **cast-block feedback helper** — client-side gate that builds state toast and blocks cast

## Purpose

Client helper called before cast send. If the local character is in a blocked state, builds the message  
`You can't do that while you are <suffix>!`  
(with sealed suffixes including **dead.** / **waiting.** / **in town.**), posts a chat toast (channel `0x18`), and returns **1** (blocked). Returns **0** when no block applies so the cast path may continue.

## Signature (decompiler-derived)

```c
// client / this in EAX (fastcall-style); 0 stack formals
uint8_t Client_CastBlockFeedback(void);
// returns 1 = blocked (or null character); 0 = allow cast
```

## Sealed strings (2026-07-29)

| Literal | VA | Sole DATA xref |
|---|---|---|
| `You can't do that while you are ` | `0x00a2e098` | `0x0093b811` |
| `in town.` | `0x00a2e060` | `0x0093b934` |
| `waiting.` | `0x00a2e06c` | `0x0093b8e3` |
| `dead.` | `0x00a2e078` | `0x0093b892` |
| `in your enhanced state.` | `0x00a2e080` | `0x0093b841` |
| `"!"` word | `DAT_00a156cc` @ `0x00a156cc` = `21 00` | append after suffix |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0093b7f0_FUN_0093b7f0.md`
- Annotated: `docs/reconstruction/raw/aa_0093b7f0_FUN_0093b7f0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_0093b7f0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0093b7f0_Client_CastBlockFeedback.md`
- Review B: `docs/reconstruction/reviews/B_aa_0093b7f0_Client_CastBlockFeedback.md`
- Prior scaffold record: `docs/reconstruction/functions/aa_0093b7f0_FUN_0093b7f0.md`

## Callers / callees

**Callers (Confirmed xrefs):**

| Site | Function |
|---|---|
| `0x00941927` | `Client_CastSkillFromQuickBarSlot` |
| `0x00941ac5` | `FUN_00941ac0` (then `Client_RequestCastSkill` if allow) |

**Callees:**

| VA | Role |
|---|---|
| `FUN_007a69d0` | string-pool / locale context |
| `FUN_007a6de0` | localize / intern string |
| `FUN_00580a20` | status display name from id |
| `FUN_008f8200` | chat/UI toast (ch `0x18`) |
| entity vtbl `+0x198`, `+0x194` | dead / waiting predicates |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | **High** |
| dead/waiting/town string VAs + sole ownership | **Confirmed** |
| Return polarity (1=block) | **Confirmed** (caller CF) |
| vtbl predicate product names | **High by string**; bodies not owned |
| Parameter semantic names | Client-in-EAX **High**; types Tentative |
