# Review A (reconstruction fidelity): `aa_004c9aa0` CVOGCreature_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c9aa0` |
| **VA** | `0x004c9aa0`–`0x004c9f7b` |
| **Canonical name (proposed)** | `CVOGCreature_ctor` |
| **Ghidra name** | `FUN_004c9aa0` |
| **Prior aliases** | `Named_CalleeOf_CVOGReaction_GiveItemByCbid_004c9aa0` (incomplete — multi-caller) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A) |
| **Counterpart** | `reviews/B_aa_004c9aa0_CVOGCreature_ctor.md` |
| **System tag** | creature runtime / factory |
| **Agent** | W21-F OWN-ONLY |
| **Verdict** | **accept-with-gaps** — ABI / mostDerived / vtbl / factory size / map+subobj **High**; field English dictionary open |

**Tools:** Ghidra `decompile_function` + `read_memory` (entry, epilogue, vtbl, floats) + `get_xrefs_to` + `get_assembly_context` + `get_function_by_address`. No `disassemble_bytes`. No Launcher. No parent ledger edits.

---

## 1. Purpose

`__thiscall` constructor: `CVOGCreature* Ctor(this, int mostDerivedFlag)`.

1. MSVC EH registration (`ExceptionList`, state machine `local_4`).
2. If `mostDerivedFlag != 0`: install dual-base cookies `this+0x4 = DAT_009d4d14`, `this+0x44 = DAT_009d4d0c`; `FUN_00518940` with **ECX = this+0x500** (image).
3. Always `FUN_005c82a0(this, 0)` — parent / simple-object base.
4. Install creature vtbls: primary `PTR_LAB_009cbe74`, SetupGraphics `PTR_CVOGCreature_SetupGraphics_009cbe38` @ +0x40, dual-base `009cbb74`, complete-object adjust **−0x4fc**.
5. Default large field run (flags, quats from `DAT_009cb8c0` family, float **15.0f** @ +0x124 from `DAT_00aaa7a4`, `g_flOne` scales, TFID-ish `0xFFFFFFFF` slots, byte `+0x309 = 1`, …).
6. Map head via `FUN_0058d9c0` → `this+0x158`; circular self-links + isnil/color.
7. `FUN_0096e0e0()` mid-init helper.
8. `operator_new(0x60)` + `FUN_005d55f0(this, 0)` → `this+0xF8` (null-safe).
9. Twin zero loop (**0x13** iters) + terminal byte `this+0x2f0 = 0`.
10. Return `this`.

### Factory / call sites (live xrefs)

| Site | Pattern |
|---|---|
| `CVOGSpawnPoint_CreateCreature` | `operator_new(0x690)`; `push 1; call` — type **0x12** template arm |
| `CVOGReaction_GiveItemByCbid` | `push 0x690` / `push 1; call` |
| `Skill_SpawnTemplateAndStartHB` | `new(0x690)` + `push 1` |
| `FUN_00568670` / `FUN_00503780` / `FUN_004ca150` / `FUN_00855810` | `push 1` after alloc |
| `CVOGCharacter_ctor` `0x00536920` | **`push 0`** — base subobject |

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live Ghidra decompile | `FUN_004c9aa0` @ `0x004c9aa0` (≡ raw CF) |
| Entry image | `read_memory` `0x004c9aa0` (128 B) — EH, mostDerived, cookies, `005c82a0`, vtbls |
| Epilogue image | `read_memory` `0x004c9f50` — `mov eax,esi; ret 4` |
| Vtbl / const | `009cbe74`, `009cbe38`, `009cb8c0`, `00aaa7a4` (=15.0f) |
| Xrefs + asm context | 8 call sites |
| Raw | `docs/reconstruction/raw/aa_004c9aa0_FUN_004c9aa0.md` |
| Annotated | `docs/reconstruction/raw/aa_004c9aa0_FUN_004c9aa0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCreature_ctor.cpp` |
| Function record | `docs/reconstruction/functions/aa_004c9aa0_CVOGCreature_ctor.md` |
| Related duals | `CVOGCharacter_ctor`, `Skill_SpawnTemplateAndStartHB`, `MapFloatTfid_AllocNode` (`0058d9c0`) |

**Not performed:** full line-by-line field English dictionary, runtime ctor watch, binary diff, `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall`; 1 stack arg; `ret 4`; EAX=`this` | **High** | image prolog/epilogue |
| mostDerivedFlag gate | **High** | `cmp`/decompile |
| Cookies `009d4d14` / `009d4d0c` | **High** | image immediates |
| `FUN_00518940` ECX=`this+0x500` | **High** | image `lea ecx,[esi+0x500]` |
| Parent `FUN_005c82a0(0)` | **High** | always |
| Primary + SetupGraphics vtbls | **High** | named SetupGraphics; CreateCreature consumer |
| Complete-object adjust −0x4fc | **High** | decompile |
| Heap size 0x690 most-derived | **High** | multiple factories |
| Character flag 0 base path | **High** | `00536976` push ebx |
| Map head `0058d9c0` @ +0x158 | **High** | |
| Subobj `new(0x60)+005d55f0` @ +0xF8 | **High** | |
| Twin loop count 0x13 | **High** | decompile |
| Clean ≡ raw CF | **High** | re-decompile 2026-07-29 |
| Every field product English | **Open** | |
| Retail symbol `CVOGCreature_ctor` | **Probable** | SetupGraphics + factories |

---

## 4. Sealed construction spine

```
CVOGCreature_ctor(this, mostDerivedFlag) -> this
  EH_register
  if mostDerivedFlag:
    this+0x4  = &DAT_009d4d14
    this+0x44 = &DAT_009d4d0c
    FUN_00518940(ecx=this+0x500)
  FUN_005c82a0(this, 0)
  *this = creature_vtbl_009cbe74
  this+0x40 = setupGraphics_vtbl_009cbe38
  dual_base_vtbl_009cbb74; co_adjust = vbOff - 0x4fc
  // defaults… mapHead@+0x158 … FUN_0096e0e0 …
  this+0xF8 = new(0x60) ? FUN_005d55f0(this,0) : 0
  twin_zero_loop(0x13); this+0x2f0 = 0
  return this
```

---

## 5. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| mostDerived cookies + `00518940` | **Yes** |
| `005c82a0(0)` | **Yes** |
| Vtbl triple + −0x4fc | **Yes** |
| Map head + self-links | **Yes** |
| `0096e0e0` | **Yes** |
| `new(0x60)` / null / `005d55f0` | **Yes** |
| Twin loop + return this | **Yes** |
| Invented branches | **None** |

---

## 6. Gaps / open questions

1. Full English for all defaulted offsets (layout doc).
2. Product type of `FUN_005d55f0` 0x60-byte object and `FUN_0096e0e0`.
3. Parent class product name for `FUN_005c82a0`.
4. Whether any non-creature factory ever uses this ctor (current xrefs all creature/item/skill/character-base).
5. Runtime / bit-diff vs retail EXE.

**Verdict:** Structure + ABI + creature identity + factory size **sealed High**. Overall **accept-with-gaps** for residual field/product English only.
