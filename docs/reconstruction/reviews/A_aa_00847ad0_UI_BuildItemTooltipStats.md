# Review A (reconstruction fidelity): `aa_00847ad0` UI_BuildItemTooltipStats

| Field | Value |
|---|---|
| **Stable ID** | `aa_00847ad0` |
| **VA** | `0x00847ad0` |
| **Canonical name** | `UI_BuildItemTooltipStats` |
| **Prior names** | `FUN_00847ad0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity) |
| **Counterpart** | `reviews/B_aa_00847ad0_UI_BuildItemTooltipStats.md` |
| **System** | inventory-transfer / client UI (item tooltips) |
| **Verdict** | **accept-with-gaps** — role, ABI shell, type switch, power-plant offsets, return-as-line-count **sealed**; per-type English labels and full string catalog residual |

---

## 1. Purpose

Client **inventory / garage / drive-loading** tooltip builder: given a **tooltip text host** (`this`) and an **item object**, append type-specific stat lines (via host vfuncs `+0x224` / `+0x250` / related) and return the **count of lines contributed**.

Not a network path. Not a skill cast. Pure client UI string assembly.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00847ad0_FUN_00847ad0.md` |
| Annotated | `docs/reconstruction/raw/aa_00847ad0_FUN_00847ad0.annotated.md` |
| Clean (scaffold) | `docs/reconstruction/reconstructed-exact/FUN_00847ad0.cpp` |
| Clean (named) | `docs/reconstruction/reconstructed-exact/UI_BuildItemTooltipStats.cpp` |
| Function record | `docs/reconstruction/functions/aa_00847ad0_UI_BuildItemTooltipStats.md` |
| Live decompile | Ghidra `decompile_function` / `analyze_function_complete` `0x00847ad0` (2026-07-29) |
| Live bytes | `read_memory` entry `0x00847ad0` len 64; epilogue `0x0084aef0` len 32 |
| Meta | `get_function_by_address` → body **`00847ad0`–`0084af04`** (0x3434 bytes) |
| Callers | `get_function_callers` → `FUN_00843a60`, `FUN_0084b890`, `FUN_0088d980` (4 xrefs) |
| Callees | 50+ (localization `FUN_007a6de0`, `sprintf`, hash lookup, skill resolve, RTTI, …) |

---

## 3. Sealed residuals

### 3.1 ABI / frame — **SEALED**

| Fact | Evidence |
|---|---|
| Entry | `55 8B EC 83 E4 F8 6A FF 68 0F D2 9A 00 … 81 EC B8 09 00 00 53 56 57 8B D9` |
| `this` | **ECX** → **EBX** (`8B D9`); decompiler `param_1` = tooltip host |
| Stack args | `param_2` item* @ `[ebp+8]` / `Stack[0x4]`; `param_3` char detail @ `Stack[0x8]`; `param_4` char detail @ `Stack[0xc]` |
| Locals | `SUB ESP, 0x9B8`; large format buffers |
| SEH | `LAB_009ad20f` plate; `ExceptionList` frame |
| Epilogue | `MOV EAX,[ESP+0xC]` (line count) → pop EDI/ESI → restore FS:0 → pop EBX → `MOV ESP,EBP; POP EBP; **RET** (`C3`)` |
| Stack cleanup | **Caller cleans** three stack dwords (`RET` not `RET 0xC`) — hybrid this-in-ECX + cdecl arg cleanup |
| Return | **EAX = line count** (`local_9cc`). Decompiler types as `int*` are a casting artifact; callers treat as integer (`if (iVar4 != 0)`) |

```c
// Hybrid: ECX = tooltip host (thiscall-this); stack cleaned by caller.
int UI_BuildItemTooltipStats(void *tooltipHost /*ECX*/,
                             void *item /*stack*/,
                             char showDetail /*stack*/,
                             char showExtra  /*stack*/);
```

Caller sites (Drive loading / Inv equipped) pass `(item, 1, 0)` with host in ECX.

### 3.2 Early exits — **SEALED**

1. `DAT_00d1b6d8 == 0` → return **0** (no local player / context).
2. `FUN_00524520()` (`CVOGCharacter_FindActiveObjectiveIdForInteract`) **non-zero** → append one localized line via host vfunc `+0x224`, return **1**.

### 3.3 Type dispatch — **SEALED** (architecture)

```
itemData = item[0x2a]           // +0xA8
type     = *(itemData + 0x38)   // dword type id
switch (type):
  4, 0x34:  break (no type-specific body)
  6:        chassis/component family via *(short*)(*(itemData+0x3c)+0x3f4)
            subtypes 8 / 10 / 0xB (weapon-ish / helper / skill-linked)
  8:        3 fixed lines (name/desc/count style via vfuncs +0x1fc / helpers)
  10:       power plant (RTTI cast → offsets below)
  0x0C:     weapon / combat item (DPS, heat, range, …; param_3/param_4 gates)
  0x0E:     vehicle-ish stats block (HP/Power/Heat strings in decomp)
  0x10:     tire / surface friction lines (Ice/Snow, Sand, …)
  0x1A:     component with skill-id table + CNDHash_LookupByKey
  0x1C:     armor / resist-style short stats
  0x32:     2-line generic
  default:  item flags |= 0x10 at item[0x5f] (+0x17C); FUN_00512670()
```

Post-switch common tail (if `item[0x5f] bit 19` set **or** `DAT_00d1791c`): optional modular/hardpoint / requirement lines when `param_3 != 0`, plus level/req block when `*(itemData+0x3c)+0x4ac >= 0`.

Return **`local_9cc`** after all appends.

### 3.4 Power plant (type **10**) field map — **SEALED** (plate ≡ decompile)

Plate comment + case body:

| Field | Offset on cast object | Decomp access | Format hint |
|---|---|---|---|
| HeatMax | `+0xB0` | `obj[0x2c]` | `%i\n` |
| PowerMax | `+0xB4` | `obj[0x2d]` | `%i %s\n` |
| PowerRegenRate | `+0xB8` | `(short)obj[0x2e]` | `%+.02f %s\n` |
| CoolRate | `+0xBA` | `*(short*)(obj+0xBA)` | `%.02f /%s\n` |

Plate states regen/cool display uses **⅓ rate scale** (3000 ms pulse average / `g_flDisplayRateScaleOneThird`). **Static body of this unit** does not multiply by an explicit ⅓ constant in the case-10 sprintf path (value may already be stored scaled, or scale is inside a callee / string unit). **Do not bit-seal ⅓ multiply inside this VA** without further dataflow; plate is product intent residual.

### 3.5 UI host vfuncs used (this unit) — **SEALED** (slots, not product names)

| Vtbl off | Role in this unit |
|---|---|
| `+0x224` | Append labeled / colored text (dominant) |
| `+0x250` | Append newline / blank / secondary line |
| `+0x22c` | Append in req/level tail |
| `+0x1b8` | Fetch color/style node (`+0x7c` color dwords) |

Item vfuncs include `+0x1fc`, `+0x200`, `+0x264`, `+0x268`, `+0x15c`, `+0x5c`, `+0x60` (type-specific).

### 3.6 Notable callees (role only; product names residual)

| Callee | Role |
|---|---|
| `FUN_007a6de0` | Localization / string table (×100+) |
| `sprintf` | Format into stack buffers |
| `FUN_00524520` | Interact-objective early tooltip line |
| `CNDHash_LookupByKey` | Skill / def lookup via `*(DAT_00b041fc+0xf10)` or `DAT_00d1b570+0xf10` |
| `CVOGReaction_ResolveSkillTargets` | Skill object for tooltip skill lines |
| `__RTDynamicCast` | Type 10 / 0xC / 0xE / 0x10 / 0x1C specialization |
| `FUN_008465a0` / `FUN_008467e0` | Shared addon / “has more stats” helpers |
| `FUN_00845030` | Alloc helper for skill description chunks (delete path noisy in decomp) |
| `g_flMsToSeconds_Inferred` @ `0x00a0f72c` = **0.001f** | Time display (`%0.1fs`) |
| `DAT_00a0f298` = **0.5f** | Weapon DPS path scale (shared float pool) |
| `DAT_00aaa664` ≈ **1e-4f** | Threshold compare for range/extra lines |
| `g_flZero` | Zero compares |

### 3.7 Callers — **SEALED** (set)

| Caller | Sites | Context |
|---|---|---|
| `FUN_00843a60` | 1 | Inv currently-equipped tooltip |
| `FUN_0084b890` | 1 | Related inventory tooltip host |
| `FUN_0088d980` | 2 | Drive loading vehicles UI (`param_3=1`, `param_4=0`) |

Xrefs: `00843ea2`, `0084c0dc`, `0088da41`, `0088daf6`.

### 3.8 Live ≡ raw — **SEALED**

Live 2026-07-29 decompile matches raw capture structure: same switch cases, same early exits, same return of `local_9cc`, same power-plant offsets, same post-switch flag gate. No material CF drift. Scaffold clean is decompiler body with width renames only.

---

## 4. Gaps (explicit)

1. Full English product names for every localization key (`FUN_007a6de0` args not recovered in bulk).
2. Complete item-type enum dictionary beyond switch case numbers.
3. Subtype `*(+0x3f4)` product names for case 6 (8 / 10 / 0xB).
4. Whether ⅓ display scale is applied inside case 10 vs stored rates (plate residual).
5. Product RTTI names for each `__RTDynamicCast` target.
6. Exact meaning of `param_3` / `param_4` beyond “detail gates” (weapon hardpoint loops / range block).
7. Decompiler noise: `operator_delete` “does not return”, `unaff_EBX`/`unaff_EDI`, stack string overlays — **do not port as written**.
8. Runtime / bit-exact / differential verification open.
9. Server has **no** equivalent — client display only.

---

## 5. Confidence

| Claim | Level |
|---|---|
| Role = client item tooltip stat lines | **High** |
| ABI ECX host + 3 stack args + RET C3 + EAX line count | **High** |
| Type switch on `*(item[0x2a]+0x38)` | **High** |
| Power plant offsets B0/B4/B8/BA | **High** |
| Early interact objective branch | **High** |
| Per-line English strings | **Low–Med** (format strings High; labels via 007a6de0 residual) |
| Full bit-exact clean of 0x3434-byte body | **Not claimed** |

---

## 6. AutoCore impact

- **Client UI only** — do not implement on server.
- Tooltips: host text widget + item; return **number of lines** for spacing (`if (lines) append blank`).
- Port strategy: type-switch table of formatters; reuse localization keys when catalog recovered.
- Do not confuse with inventory equip wire (`Client_RecvInventoryEquip`) or skill cast paths.
