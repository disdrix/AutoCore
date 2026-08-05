# Function record: Skill_GetCategoryCooldownMap

| Field | Value |
|---|---|
| **Stable ID** | `aa_00518d70` |
| **Canonical name** | `Skill_GetCategoryCooldownMap` |
| **Address** | `0x00518d70` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **accept** dual A/B residual strengthen 2026-07-29 — CF/layout sealed; owner class residual |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Lazy-get category-cooldown map at map-owner **`+0x6c`**. First use: `operator_new(0xc)` header + empty tree head via **`FUN_005ae2b0`** (`operator_new(0x1c)`, flag `+0x19=1`, self-linked, size `+8=0`). Returns cached pointer thereafter. No insert/remaining math.

## Signature (sealed)

```c
void * __fastcall Skill_GetCategoryCooldownMap(void *pMapOwner);
// ECX = cast-owner / character-side map host (not skill runtime)
// RET  — unary; no stack args
```

## Behavior (Confirmed CF)

- `if (*(pMapOwner+0x6c)==0)` → alloc header; on success init empty RB-style map; store (null on OOM).
- `return *(pMapOwner+0x6c)`.

### Layout

| Object | Size | Fields |
|---|---|---|
| Map header | 0xC | +4 head, +8 size |
| Head node (`FUN_005ae2b0`) | 0x1C | L/P/R @0/4/8; flag @+0x19 |
| Value node (consumers) | 0x1C | key @+0xC, start @+0x10, duration @+0x14 |

### Twin

| VA | Slot | Factory | Name |
|---|---|---|---|
| `0x00518d70` | +0x6c | `FUN_005ae2b0` (0x1c, +0x19) | `Skill_GetCategoryCooldownMap` |
| `0x00518c20` | +0x68 | `FUN_0058d9c0` (0x30, +0x29) | `FUN_00518c20` (leave-FUN) |

## Callers (8 sites / 4 funcs)

| Caller | Sites | Role |
|---|---|---|
| `Skill_InsertCategoryCooldown` | `0x00518e1c` | insert API |
| `Skill_GetCategoryCooldownRemaining` | `0x00519168`, `0x00519176`, `0x005191a2` | remaining + expire erase |
| `CVOGHBOKToCastAgain_ctor` | `0x0051e35a` | arm category on cast-again (**owner** ECX) |
| `Client_RecvSkillStatusEffect` | `0x00811333`, `0x008116e9`, `0x00811705` | error abort / item-skill map |

## Callees

- `operator_new`
- `FUN_005ae2b0` (head factory — product name open)

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00518d70_Skill_GetCategoryCooldownMap.md`
- Annotated: `docs/reconstruction/raw/aa_00518d70_Skill_GetCategoryCooldownMap.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Skill_GetCategoryCooldownMap.cpp`
- Dual A/B: `docs/reconstruction/reviews/A_aa_00518d70_Skill_GetCategoryCooldownMap.md`, `B_aa_00518d70_Skill_GetCategoryCooldownMap.md`
- Related residual: `docs/reconstruction/reviews/a_0051e240.md` (owner vs skill host seal)

## Confidence

| Claim | Level |
|---|---|
| Control flow / lazy `+0x6c` | **Confirmed** (decompile + bytes) |
| Header/head layout | **Confirmed** |
| Accessor-only | **Confirmed** |
| Host is owner-side, not skill | **High** (caller duals) |
| Owner product class name | **Open** |
| `FUN_005ae2b0` product name | **Open** |
