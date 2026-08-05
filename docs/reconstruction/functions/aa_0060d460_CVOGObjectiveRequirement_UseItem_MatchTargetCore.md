# Function record: CVOGObjectiveRequirement_UseItem_MatchTargetCore

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060d460` |
| **Canonical name** | `CVOGObjectiveRequirement_UseItem_MatchTargetCore` |
| **Prior names** | `FUN_0060d460`, `Named_CalleeOf_CVOGObjectiveRequirement_UseItem_MatchTarget_0060d460` |
| **Address** | `0x0060d460` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` |
| **Calling convention** | MSVC `__thiscall` — `this` = UseItem requirement; **`ret 0x08`** (2 stack dwords) |
| **Completion status** | **Human-refined** — dual A/B sealed 2026-07-29 (identity + inventory + field gates; grid ECX) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Verdict** | **accept-with-gaps** |

## Purpose

Core predicate for **UseItem** objective **MatchTarget** (trampoline `aa_0060d7f0` @ `0x0060d7f0` → this body). Returns **1** when:

1. **Identity:** target instance COID matches `req+0x10/+0x14` (when that pair is not the all-ones sentinel), **or** target clonebase CBID (`*(obj+0xA8)+0x34`) matches `req+0x18` (when `+0x18 != -1`).
2. Character has inventory manager (`ch+0x250`) and cargo grid (`mgr+0x2B0`).
3. **Cargo presence** of target COID via `InventoryGrid_FindItemByCoid`, XOR-matched to invert flag `req+0x1D` (0 = must be present, 1 = must be absent).
4. Optional **secondary CBID** present via `InventoryGrid_FindItemByCbid(req+0x2C, 0, 0)` when `+0x2C != -1`.
5. Optional **character field** `req+0x54`: if `>= 1`, must equal character clonebase `+0xFC` (MI this-adjust).

## Signature (sealed)

```c
// this = UseItem requirement*
// ret 0x08
uint8_t __thiscall CVOGObjectiveRequirement_UseItem_MatchTargetCore(
    void* this,
    void* character,   // stack0
    void* target);     // stack1 — world/object with COID @+0x160/+0x164
// returns AL: 1 match, 0 fail
```

## Requirement layout (body-backed)

| Off | Width | Role | Confidence |
|----:|-------|------|------------|
| `+0x10` | u32 | Required instance COID lo | **High / Sealed** |
| `+0x14` | u32 | Required instance COID hi | **High / Sealed** |
| `+0x18` | i32 | Primary CBID; `-1` = unused | **High** (shared with InitActive give) |
| `+0x1D` | u8 | Invert cargo presence of target COID | **High / Sealed** (bytes `setz`/`xor`) |
| `+0x2C` | i32 | Secondary CBID gate; `-1` = skip | **High** (shared InitActive secondary) |
| `+0x54` | i32 | Optional character field gate; `<1` = skip | **High** |

## Character / target offsets

| Path | Role |
|------|------|
| `ch+0x250` | Inventory manager* |
| `*(ch+0x250)+0x2B0` | **InventoryGrid*** (ECX into FindByCoid/Cbid) |
| `obj+0x160/+0x164` | Instance COID lo/hi |
| `obj+0xA8` → `+0x34` | Clonebase CBID |
| `ch` MI `+0xA8` → `+0xFC` | Character field compared to `req+0x54` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0060d460_FUN_0060d460.md`
- Annotated: `docs/reconstruction/raw/aa_0060d460_FUN_0060d460.annotated.md`
- Clean (refined): `docs/reconstruction/reconstructed-exact/CVOGObjectiveRequirement_UseItem_MatchTargetCore.cpp`
- Scaffold clean: `docs/reconstruction/reconstructed-exact/FUN_0060d460.cpp`
- Named seed: `docs/reconstruction/reconstructed-exact/Named_CalleeOf_CVOGObjectiveRequirement_UseItem_MatchTarget_0060d460.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0060d460_CVOGObjectiveRequirement_UseItem_MatchTargetCore.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0060d460_CVOGObjectiveRequirement_UseItem_MatchTargetCore.md`
- Residual: `docs/reconstruction/reviews/a_0060d460.md`

## Callers / callees

| Kind | VA / name |
|------|-----------|
| Caller | `CVOGObjectiveRequirement_UseItem_MatchTarget` `0x0060d7f0` (trampoline) |
| Caller family | `Client_FindObjectiveMatchingTarget` / UseObject IDObjective path |
| Callee | `InventoryGrid_FindItemByCoid` `0x00571010` |
| Callee | `InventoryGrid_FindItemByCbid` `0x005710c0` |

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary / `ret 0x08` | **High** (bytes `C2 08 00`) |
| Signature (thiscall + char*, target*) | **High** |
| Control flow | **High** (live ≡ raw) |
| COID vs CBID identity OR | **High / Sealed** |
| Grid ECX path `+0x250/+0x2B0` | **High / Sealed** (bytes) |
| Invert flag `+0x1D` | **High / Sealed** |
| Secondary CBID `+0x2C` | **High** |
| Field `+0x54` vs clonebase `+0xFC` | **High** (CF); product name of field **Tentative** |
| Naming | **Probable** |
| Runtime / diff | **Open** |
| Overall | **accept-with-gaps** |

## Dual reviews

- A (fidelity): `reviews/A_aa_0060d460_CVOGObjectiveRequirement_UseItem_MatchTargetCore.md`
- B (adversarial): `reviews/B_aa_0060d460_CVOGObjectiveRequirement_UseItem_MatchTargetCore.md`
