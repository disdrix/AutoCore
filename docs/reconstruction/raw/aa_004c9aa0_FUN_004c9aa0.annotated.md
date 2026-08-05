# Annotated low-level: FUN_004c9aa0 / CVOGCreature_ctor

| Field | Value |
|---|---|
| Stable ID | `aa_004c9aa0` |
| VA | `0x004c9aa0`–`0x004c9f7b` |
| System | creature runtime / world object factory |
| Date | 2026-07-29 (W21-F) |
| Proposed name | `CVOGCreature_ctor` |

## Machine-level notes

- **`__thiscall`**: ECX = `this` (ESI after prolog); one stack arg **mostDerivedFlag**; epilogue **`ret 4`** (`C2 04 00`); returns `this` in EAX.
- **MSVC EH**: `ExceptionList` chain + `LAB_009a1d1c`; state `local_4` advances through field-init phases (0 → 1 → 6 → 7 → 8 around `operator_new(0x60)`).
- **Most-derived arm** (`flag != 0`):
  - `this[1] = &DAT_009d4d14` (vbtable / dual-base cookie @ +0x4)
  - `this[0x11] = &DAT_009d4d0c` (@ +0x44)
  - `lea ecx, [this+0x500]`; `FUN_00518940()` base-cookie init
- **Always**: `FUN_005c82a0(0)` — parent object / simple-object base ctor with flag 0 (base already handled or not most-derived).
- **Vtbl install** (creature identity — **High**):
  - `*this = PTR_LAB_009cbe74`
  - `this[0x10] = PTR_CVOGCreature_SetupGraphics_009cbe38` (@ +0x40) — Ghidra-named SetupGraphics vtbl
  - Dual-base slot: `*(this + *(this[1]+4) + 4) = PTR_LAB_009cbb74`
  - Complete-object adjust: `*(this + *(this[1]+4)) = *(this[1]+4) + (-0x4fc)`
- **Field defaults** (selected High anchors; full list in raw):
  - `*(u8*)(this+0x100) = 1` (`param_1+0x40` as byte at dword 0x40 → wait: `param_1 + 0x40` is dword index 0x40 = offset **0x100**)
  - Quat/default block `this[0x42..0x45]` ← `DAT_009cb8c0..cc` (image `FFFFFFFF FFFFFFFF 0 0`)
  - `this[0x49]` ← `DAT_00aaa7a4` = **15.0f**
  - Several u16 pairs set to 1 @ +0x13c..+0x142; u16 `10` @ +0x12e
  - Scales `g_flOne` at `this[0x4c]`, `this[0x7a]`
  - TFID-ish `-1` slots `this[0x84..0x89]`, `this[0xb7]`
  - Flag byte `this+0x309 = 1` (skill spawn later clears this)
  - `FUN_0058d9c0()` → map head at `this[0x56]` (+0x158); isnil/color init + circular self-links
  - `FUN_0096e0e0()` mid-init helper (unscoped here)
  - `operator_new(0x60)` + `FUN_005d55f0(this, 0)` → `this[0x3e]` (+0xF8) or null
  - Twin zero loop count **0x13**: zeros `this[0xa4 + i]` and `this[0xa4 + i - 0x89]` for i=0..0x12
  - Terminal `*(u8*)(this+0x2f0) = 0` (`param_1+0xbc`)
- **Factory size**: most-derived heap **`0x690`** (CreateCreature / GiveItem / Skill spawn).
- **Character path**: `CVOGCharacter_ctor` calls with **flag 0** as parent base sub-ctor.

## Pseudocode (structure; full body in raw)

```c
// CVOGCreature* __thiscall CVOGCreature_ctor(CVOGCreature* this, int mostDerivedFlag)
CVOGCreature* FUN_004c9aa0(void* this, int mostDerivedFlag)
{
  // EH register...
  if (mostDerivedFlag != 0) {
    this->vbtable_slot = &DAT_009d4d14;      // +0x4
    this->vbtable_slot2 = &DAT_009d4d0c;     // +0x44
    FUN_00518940(/* ecx = this+0x500 */);
  }
  FUN_005c82a0(/*this,*/ 0);                 // parent base ctor
  *this = &PTR_LAB_009cbe74;
  this->setupGfxVtbl = &PTR_CVOGCreature_SetupGraphics_009cbe38; // +0x40
  // dual-base vtbl + complete-object adjust -0x4fc
  // ... extensive zero/default field init ...
  this->mapHead = FUN_0058d9c0();            // +0x158
  // link head to self; isnil/color
  // ... more zeros / quat copy / flags ...
  FUN_0096e0e0();
  // ... more zeros ...
  void* p = operator_new(0x60);
  this->subObj_0x3e = p ? FUN_005d55f0(this, 0) : 0;  // +0xF8
  // twin zero loop x0x13; flag +0x2f0 = 0
  return this;
}
```

## Sealed facts

| Fact | Evidence | Confidence |
|---|---|---|
| thiscall + ret 4 + return this | image prolog `mov esi,ecx`; epilogue `mov eax,esi; ret 4` | **High** |
| mostDerivedFlag gate | `cmp [esp+…],0` / decompile `if (param_2 != 0)` | **High** |
| Creature SetupGraphics vtbl | Ghidra name on `009cbe38`; slot0 → `004c8b60` | **High** |
| Parent base `FUN_005c82a0(0)` | decompile + image call | **High** |
| Heap size 0x690 most-derived | CreateCreature / GiveItem / Skill | **High** |
| Character uses flag 0 | `00536976` push ebx=0 | **High** |
| Map head via `0058d9c0` @ +0x158 | decompile `param_1[0x56]` | **High** |
| Subobject `new(0x60)+005d55f0` @ +0xF8 | decompile `param_1[0x3e]` | **High** |
| Every field product English | — | **Open** / Tentative |
| Full retail ctor symbol | SetupGraphics naming chain | **Probable** `CVOGCreature_ctor` |

## Open questions

- Full English dictionary for every zeroed/defaulted slot.
- Exact type of `FUN_005d55f0` 0x60-byte subobject and `FUN_0096e0e0`.
- Whether any non-creature type shares this ctor (evidence: factories + SetupGraphics vtbl argue creature-only).
