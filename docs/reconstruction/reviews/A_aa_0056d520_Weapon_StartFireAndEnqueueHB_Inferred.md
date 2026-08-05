# Review A (reconstruction fidelity): `aa_0056d520` Weapon_StartFireAndEnqueueHB_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056d520` |
| **VA** | `0x0056d520` |
| **Canonical name** | `Weapon_StartFireAndEnqueueHB_Inferred` (was `FUN_0056d520`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0056d520_Weapon_StartFireAndEnqueueHB_Inferred.md` |
| **System** | `combat` / vehicle hardpoint weapons |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Weapon **thiscall** (ECX = hardpoint weapon\*): **start fire** if not blocked by `weapon+0xCB`, latch fire-flag triple `+0xC7/+0xC8/+0xC9 = 1`, run shared fire prep `FUN_0056d160`, allocate a **0x24** `CVOGHBBase` subclass via `FUN_005fe6a0`, **enqueue + Start** that heartbeat on the owner character/vehicle HB list. Returns **1** on success path, **0** if `+0xCB` blocks.

Sole static consumers: primary / secondary vehicle fire-all walkers `FUN_004f50d0` / `FUN_004f5110` (OR-accumulate return).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0056d520_FUN_0056d520.md` |
| Annotated | `docs/reconstruction/raw/aa_0056d520_FUN_0056d520.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0056d520.cpp` |
| Function record | `docs/reconstruction/functions/aa_0056d520_FUN_0056d520.md` |
| Parent dual | `reviews/A_aa_004f50d0_Vehicle_FireAllPrimaryWeapons_Inferred.md` |
| Fire-flag sibling | `reviews/A_aa_0056a260_Weapon_SetFireFlagPair_Inferred.md` |
| Ghidra | `batch_decompile` + `analyze_function_complete` + `get_function_callers`; HB ctor `decompile_function` `0x005fe6a0` |

**Live re-decompile 2026-07-29 ≡ frozen raw body.**

---

## 3. Signature (sealed CF)

```c
// MSVC thiscall: weapon* in ECX (decompiler shows __fastcall for single ECX arg)
uint32_t /* bool-ish AL */ __thiscall Weapon_StartFireAndEnqueueHB_Inferred(
    WeaponHardpoint* weapon /* ECX */);
// return: 0 if weapon+0xCB != 0; else 1 after flags + HB start
```

| Item | Evidence | Conf |
|---|---|---|
| ECX = weapon | Parent `mov ecx,esi` before call; body uses `param_1+0xC7…` same as SetFireFlagPair object | **High** |
| Return 0 / 1 | Early `return 0` on `+0xCB`; fallthrough `return 1` | **High** |
| No stack args | Callee list / parent relative call with ECX only | **High** |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| `if (*(char*)(weapon+0xCB) != 0) return 0` | **Yes** |
| Optional `FUN_00514ff0(0)` when nested `*(…+0xb0+weapon) != 0` | **Yes** |
| `weapon+0xC7 = 1` always | **Yes** (199 decimal) |
| `if (weapon+0xC8 != 1) weapon+0xC8 = 1` | **Yes** (same dual-byte pattern as SetFireFlagPair with value 1) |
| `weapon+0xC9 = 1` | **Yes** |
| `FUN_0056d160(&DAT_00b047c0, 0)` | **Yes** |
| `operator_new(0x24)` → `FUN_005fe6a0(...)` → `CVOGHBList_Enqueue` → `CVOGHBBase_Start` | **Yes** |
| `return 1` | **Yes** |
| No heat check / no hardpoint walk / no turret | **Yes** |

### Sealed CF sketch

```
Weapon_StartFireAndEnqueueHB_Inferred(weapon):
  if weapon[+0xCB] != 0: return 0          // blocked (FUN_0056b400 latch)
  if related_slot[+0xb0] != 0: FUN_00514ff0(0)   // residual helper
  weapon[+0xC7] = 1
  if weapon[+0xC8] != 1: weapon[+0xC8] = 1
  weapon[+0xC9] = 1
  FUN_0056d160(&DAT_00b047c0, 0)           // shared fire prep / net?
  hb = new(0x24) → FUN_005fe6a0(/* HB ctor, owner=weapon family */)
  CVOGHBList_Enqueue(owner_list[+0xe4ec path], hb)
  CVOGHBBase_Start(hb)
  return 1
```

### HB ctor side effects (callee, not owned)

`FUN_005fe6a0` @ `0x005fe6a0` (re-decompiled): `CVOGHBBase_ctor`, vtbl `PTR_FUN_009dd43c`, attach owner from weapon chain, `param_1[7]=9`, may call `FUN_0056b400(1)` and `weapon->vtbl[+0x2c](1)`. Period/`1000` arg framing residual in parent decompile (Ghidra often mangles `new`+ctor ECX).

### Owner list path (CF sealed shape; English open)

```
list = *(*( *( *(weapon+4) + 4 ) + 0xa8 + weapon ) + 0xe4ec)
CVOGHBList_Enqueue(list, hb)
```

Same `weapon+4` → outer-object indirection family as other weapon/HB units.

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Weapon thiscall start-fire | **High** | parents + flag offsets match SetFireFlagPair object |
| `+0xCB` gate → return 0 | **High** | body; parent B residual cited |
| Inlined `+0xC7/+0xC8=1` + `+0xC9=1` | **High** | ≡ SetFireFlagPair value-1 + extra `+0xC9` |
| Alloc 0x24 HB + Enqueue + Start | **High** | callees named in Ghidra |
| Only 2 static callers (primary + secondary fire-all) | **High** | xrefs `004f50fa`, `004f513a` |
| Product English name | **Inferred** | no string/RTTI → `_Inferred` |
| `FUN_0056d160` / `FUN_00514ff0` full product | **Probable** CF only | not owned |
| Exact `FUN_005fe6a0` stack/ECX framing vs period 1000 | **Probable** | decompiler ctor framing residual |
| Nested `+0xb0` field English | **Tentative** | gate only |

---

## 6. Gaps / open

1. Retail / PDB name for unit and for HB subclass `PTR_FUN_009dd43c`.
2. Full semantics of `FUN_0056d160(&DAT_00b047c0,0)` (net / audio / ammo residual).
3. Precise identity of `+0xb0` probe and `FUN_00514ff0`.
4. Runtime / bit-exact / image diff.
5. Whether `FUN_005fe6a0` also forces `+0xCB=1` via `FUN_0056b400` **after** this unit already passed the gate (ordering: gate then ctor — re-entry blocked next frame).

**Verdict:** **accept-with-gaps** — start-fire CF + flag latch + HB enqueue sealed under `_Inferred`.
