# Review A (reconstruction fidelity): `aa_008e55e0` UI_CraftHost_RefreshCraftEnableAndStatus (**INFERRED**)

| Field | Value |
|---|---|
| **Stable ID** | `aa_008e55e0` |
| **VA** | `0x008e55e0`–`0x008e598d` inclusive (**942 B** / `0x3AE`) |
| **Canonical name** | `UI_CraftHost_RefreshCraftEnableAndStatus` (**INFERRED**) |
| **Ghidra symbol** | `FUN_008e55e0` |
| **Prior scaffold** | `Named_CalleeOf_Client_RefreshOpenMissionUiWindows_008e55e0` (retired) |
| **Review date** | `2026-08-05` |
| **Agent** | R13-015 OWN-ONLY |
| **Counterpart** | `reviews/B_aa_008e55e0_UI_CraftHost_RefreshCraftEnableAndStatus_Inferred.md` |
| **System** | `inventory-transfer` — craft/RE host enable + status refresh |
| **Parent dual** | `0x00520340` `Character_CalcCommodityTierMaxCapacity_Inferred` (tier-max leaf; called in discarded 1..5 loop) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Refresh a **craft / reverse-engineering host** panel after bind or mission-UI refresh:

1. Gate on global character pointer `DAT_00d1b6d8 != 0`.
2. Clear a ~0x200-byte status message buffer; set `host+0x7d8 = 1`.
3. Call residual helper `FUN_008e54a0` (host in ESI).
4. Probe dualed tier-max leaf `Character_CalcCommodityTierMaxCapacity` for tiers **1..5** with `ECX=character` (return values **discarded**).
5. Build enable gates:
   - **Station in range** via dualed `Character_Craft_HasMatchingStationInRange` (`0x0052eb90`) on bound object `host+0x7cc`.
   - **Credits afford** when `FUN_005202d0(char, obj.tfid_lo, obj.tfid_hi)` is true: cost = `(int)ceil(Item_GetStoreSellPrice(obj) * 0.85f)`; compare to i64 credits `(char+0x720)−(char+0x728)`.
   - **Craft readiness** via residual `FUN_0052d450(char, object, &statusOut)` (bool AL + integer status codes in out dword).
6. **Enable path** (all gates true + `host+0x7d8`): enable craft button `host+0x748` vtbl+`0xd4`(1); clear status widget; show localized **"Chance of Success"** with **100.0** (`DAT_00aaa708`) as `%.1f%%`; white color bytes.
7. **Disable path**: if button was enabled, disable + refresh; clear status; then message ladder (no object / broken / status codes / memory cost / components / station / integer % fallback).
8. Always (when character present): apply color to status widget, call residual Complexity UI `FUN_008e41b0`, refresh button, optional status string paint, show + refresh status widget.

**Not** material-list refresh (`008e5e00`), **not** object bind (`008e5990`/`008e5ce0`), **not** the tier-max leaf itself.

---

## 2. Inspected artifacts

| Artifact | Evidence |
|---|---|
| Live decompile | ≡ raw scaffold CF (with known type-confusion on status ints-as-float) |
| Full listing | `disassemble_function` — EBP frame; `AND ESP,-8`; `MOV EBX,EAX`; plain `RET` |
| Entry/exit bytes | `read_memory` @ `0x008e55e0` / `0x008e5980` |
| Float / double | `DAT_00aaa680` = **0.85f** (`9a 99 59 3f`); `DAT_00aaa708` = **100.0** double |
| Call sites | 3× `MOV EAX,host; CALL 008e55e0` via `get_assembly_context` |
| Parent dual | `A/B_aa_00520340_Character_CalcCommodityTierMaxCapacity_Inferred` |
| Station dual | `A/B_aa_0052eb90_Character_Craft_HasMatchingStationInRange_Inferred` |
| Sell-price dual | `A/B_aa_005142a0_Item_GetStoreSellPrice_Inferred` |
| Credits spine | family `[$credits]` = i64 `(+0x720)−(+0x728)` |

**Not performed:** `disassemble_bytes`, Launcher, runtime.

---

## 3. Signature (sealed)

```c
// EAX = craft/UI host*; no stack args; void; plain RET (C3)
void UI_CraftHost_RefreshCraftEnableAndStatus_Inferred(void* host /*EAX*/);
```

| Formal | Source | Conf |
|---|---|---|
| host | **EAX** on entry → `MOV EBX,EAX`; all 3 sites `MOV EAX,ESI\|EDI` before CALL | **High** |
| stack args | none | **High** |
| return | void (no EAX contract) | **High** |
| cleanup | plain **`RET`** (`C3`) | **High** |
| ECX-thiscall | **No** — not `MOV reg,ECX` for host | **High** |

---

## 4. Control flow: bytes ≡ decompile (with ABI / type seals)

| Stage | Match |
|---|---|
| Frame `PUSH EBP; MOV EBP,ESP; AND ESP,-8; SUB ESP,0x214` | **Yes** |
| Early-out if `DAT_00d1b6d8 == 0` | **Yes** (`JZ 0x008e5987`) |
| Host = EAX → EBX; message buffer zero via `REP STOSD` | **Yes** |
| `host+0x7d8 = 1`; `CALL FUN_008e54a0` | **Yes** |
| Loop tiers 1..5: `ECX=DAT_00d1b6d8; PUSH tier; CALL 00520340` (discard EAX) | **Yes** |
| Station: `PUSH host+0x7cc; ECX=char; CALL 0052eb90` → flag @ `[ESP+0x13]` | **Yes** |
| Memory/recipe gate `FUN_005202d0` on obj TFID `+0x160/+0x164` | **Yes** |
| Cost: `CALL 005142a0`; `FILD`; `FMUL 0.85f`; CRT `ceil`; FISTP → int cost | **Yes** |
| Credits i64 sub + signed compare vs cost → afford flag `[ESP+0x12]` | **Yes** |
| `FUN_0052d450` out-param @ `[ESP+0x18]`; status ints **0x2/0x4/0x5** (not floats) | **Yes** (asm `CMP ECX,4/2/5`) |
| Enable vs disable branch on AL + three flags | **Yes** |
| Success display uses **100.0** double, not out-float | **Yes** |
| Tail: color apply, `FUN_008e41b0`, button/status refresh | **Yes** |
| Epilogue `POP EDI/ESI/EBX; MOV ESP,EBP; POP EBP; RET` | **Yes** |

### Body

| Field | Value |
|---|---|
| Start | `0x008e55e0` |
| End inclusive | `0x008e598d` |
| Size | **942 B** (`0x3AE`) |
| Pad | `CC CC` then sibling `FUN_008e5990` @ `0x008e5990` |

### Host / character offsets

| Offset | Role | Conf |
|---|---|---|
| `host+0x7cc` | bound craft object* | **High** (bind dual family) |
| `host+0x7d8` | craft-enable gate byte (set 1; may be cleared by `008e54a0`) | **High** CF / **Med** English |
| `host+0x748` | craft action button widget | **High** (enable vtbl+`0xd4` / query +`0xd8` / refresh +`0x34c`) |
| `host+0x528` | status / info text widget | **High** |
| `host+0x754` | material list (null/empty → message select) | **High** (material-list dual) |
| `char+0x720..0x72c` | i64 credits pair (avail = a−b) | **High** (family) |
| `obj+0x160/+0x164` | TFID lo/hi | **High** |

### Product strings (sealed)

| String | Role |
|---|---|
| `"You must select an item to craft!"` | no bound object + empty/invalid list |
| `"You need a broken item to craft!"` | no bound object + list has rows (`vtbl+0x490` ≤ 0 path inverted) |
| `"You don't have the right components!"` | status out == **2** |
| `"To craft this from Memory costs"` | afford fail (`[ESP+0x12]==0`) with object |
| `"Chance of Success"` + `"\n%s: %.1f%%"` / `"\n%s: %i%%"` | success / fallback status |

---

## 5. Callers (context, not owned)

| Caller | Site | Setup |
|---|---|---|
| `UI_CraftHost_BindResolvedObject_Inferred` `0x008e5990` | `0x008e5caa` | `MOV EAX,ESI` (host); after recipe fill; before `008e47d0` |
| `Client_RefreshOpenMissionUiWindows` `0x0093a940` | `0x0093a9c1` | `MOV EAX,EDI` (host panel) |
| Craft-host tick/orphan body | `0x008e63e3` | `MOV EAX,EDI`; after `008e2d60`; before `008e41b0` / `008e5e00` |

Xrefs: **3** UNCONDITIONAL_CALL.

### Callees (OWN not dualled here)

| Callee | Role |
|---|---|
| `FUN_008e54a0` | residual pre-refresh (may touch `+0x7d8`) |
| `FUN_00520340` | dualed tier max (returns discarded) |
| `FUN_0052eb90` | dualed station-in-range |
| `FUN_005202d0` | residual memory/recipe TFID gate |
| `FUN_005142a0` | dualed store sell price |
| CRT `ceil` IAT `[0x009c6588]` | cost round-up |
| `FUN_0052d450` | residual craft readiness + status code |
| `FUN_008e3820` / `FUN_008e3940` | residual status formatters (codes 4 / station-fail) |
| `FUN_007a69d0` / `FUN_007a6de0` | localize |
| `sprintf` IAT | message buffer |
| `FUN_0040f4e0` / `FUN_00977a30` | memory-cost value paint |
| `FUN_008e41b0` | residual Complexity label refresh |

---

## 6. Confidence

| Claim | Confidence |
|---|---|
| ABI EAX-host / no stack args / plain RET | **High** |
| Body bounds 942 B + pad into `008e5990` | **High** |
| Enable gate = readiness ∧ station ∧ `+0x7d8` ∧ afford | **High** |
| Cost = ceil(sellPrice × 0.85f); credits i64 compare | **High** |
| Status codes 2/4/5 are integers (decompiler float poison) | **High** |
| Success UI hardcodes 100.0% display double | **High** |
| Role = craft host enable + status refresh | **High** |
| Product host class / demangle English | **Open** |
| Why tier-max loop discards results | **Open** (vestigial vs intentional warm) |
| Exact English of `FUN_005202d0` / `FUN_0052d450` / `008e54a0` | **Open** (not OWN) |
| Runtime | **Open** |

**Verdict:** **accept-with-gaps** — sealed craft-host enable/status refresh; name `_Inferred`; residual helpers + product demangle open.

---

## 7. Gaps

1. Product / MSVC demangle for craft host / widget classes.  
2. Dual seals for `FUN_008e54a0`, `FUN_0052d450`, `FUN_005202d0`, `FUN_008e41b0`, `FUN_008e3820`, `FUN_008e3940`.  
3. Purpose of discarded 1..5 `00520340` loop.  
4. Whether success-path 100.0% is intentional product UX or missing chance wire-up.  
5. Runtime / bit-exact / differential.
