# Annotated low-level: Skill_StartCastAgainHeartbeat (`aa_00519200`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00519200` |
| **VA** | `0x00519200` |
| **System** | skills-abilities |
| **Source raw** | `aa_00519200_Skill_StartCastAgainHeartbeat.md` |

## Signature correction (asm-sealed 2026-07-29)

Plate names `(pOwnerCtx, pSkill, nChargeDelayMs)` as three stack formals are **falsified**.

| Slot | Asm use | Confidence |
|------|---------|------------|
| `this` (ECX) | Owner entity → ctor stack0; `this+0xa4` → world | **High** |
| stack0 | Skill runtime → ctor stack1 | **High** |
| stack1 | Charge delay ms → ctor stack2 | **High** |
| Epilogue | **`RET 0x8`** (exactly 2 stack dwords) | **High** |

Ctor call (this unit):

```
push chargeMs; push skill; push owner; ECX=new; call CVOGHBOKToCastAgain_ctor  // RET 0xC
```

Ghidra decomp `ctor(mem, this, (int)arg0)` **under-counted** — skill arg is real.

## Control flow

1. SEH frame
2. `operator_new(0x28)`
3. `CVOGHBOKToCastAgain_ctor(mem, owner, skill, chargeMs)` if alloc ok (type **8** in ctor)
4. `CVOGHBList_Enqueue(*(world+0xe4ec), hb)` where `world = *(owner+0xa4)`
5. `CVOGHBBase_Start(hb)`

Duration formula lives in **ctor**, not here. No in-unit type-8 dedup (always alloc).

## Callers (complete xref set — residual 2026-07-29)

| Caller | Call VA | Charge | Gate snapshot |
|--------|---------|--------|---------------|
| `Client_RequestCastSkill` | `0x00941731` | skill+**0x14** movsx | `+0x61c == 0` |
| `Client_QuickBarActivateSkillSlot` | `0x00921cfd` | skill+**0x14** movsx | `+0x61c == 0` |
| `Client_StanceOrGadgetActivatePath` | `0x0093a525` | skill+**0x14** movsx | `+0x61c == 0` |
| `Skill_ClearCastBindingAndMaybeRestartCd` | `0x0051a77c` | **0** | `+0x61c != 0` |
| `Skill_ApplyStatusEffectLocal` | `0x0051ac53` | packet+**0x10** | `world+0x7e != 0` ∧ `+0x61c == 0` |
| `Skill_LocalRangeTargetCheck` | `0x005531ac` | skill+**0x10** | accuracy-miss + flag; ret **0x0f** |

## Bytes re-seal (residual)

- Body `00519200`–`00519279`; epilogue **`C2 08 00`**
- `push 0x28` / three ctor pushes / `[edi+0xa4]` / `[eax+0xe4ec]`
- Null `new`: still Enqueue + Start (no early ret)
- Ctor type: **`C7 46 1C 08 00 00 00`**; ctor epilogue **`C2 0C 00`**

## Open

- Live multi-HB stacking / server CD sync.
- LocalRange `[esp+0x14]` flag meaning (caller-owned).
- Enqueue/Start null safety (callee).
- Runtime / bit-exact.
