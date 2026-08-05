# Review B (skeptical / adversarial): `aa_0056c860` Weapon_TryFireResolveHits_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056c860` |
| **VA** | `0x0056c860` |
| **Canonical name** | `Weapon_TryFireResolveHits_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0056c860_Weapon_TryFireResolveHits_Inferred.md` |
| **System** | combat / vehicle weapon |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function product-named `VOG_DEBUG_STOP` | String only when host `+0xA8` is null via assert helper | **Falsified** product name — assert-only |
| 2 | Always fires / no gates | Owner null, heat fail, flags `0x10`/`0x02` all return 0 | **Falsified always** |
| 3 | Applies damage itself as pure math | Damage is delegated to `004d7e30`/`004da2e0` after resolve | **Agree** — orchestrator, not damage formula body |
| 4 | Free function / static helper | Single DATA xref into vtable `@0x009d3320` | **Falsified** — vtable method |
| 5 | Two stack arguments (stdcall-ish) | Exit **`ret 4`** | **Falsified** — **one** stack formal |
| 6 | Heat applied after hit resolve | `Weapon_ApplyShotHeatAndPowerCost` is **before** buffer zero / resolve | **Attack fails** — heat first |
| 7 | `param_2` always required from caller | Zero triggers owner `+0xA4` fill | **Falsified always-required** |
| 8 | Same as `Weapon_FireHelper` (`0x0056d160`) | Different CF: no `+0xc4` bit7 path; resolve+dispatch vs muzzle/message | **Falsified** identity |
| 9 | `auStack_c88` is a true 3204-byte independent array | Overlayed count (`0 < (int)`) and null-pointer checks on same name | **Agree decompiler trap** — one resolve buffer |
| 10 | Product class known | No RTTI string in this VA | **Agree leave `_Inferred`** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Gate order (owner → heat → flags) | **Confirmed** | Port fires without heat or while status blocked |
| `ret 4` / one stack arg | **Confirmed** | Stack imbalance modeling callers |
| Vtable worker (virtual call) | **Confirmed** | Miss when grepping for CALL sites |
| Heat before resolve | **Confirmed** | Double-bill or free shots |
| Flag bits 0x10 / 0x02 block | **Confirmed** | Fire through stunned/disabled owner |
| Damage via 004d7e30/004da2e0 | **Confirmed** | Invent local damage math |
| Hit-buffer layout | **Open** | Mis-parse count vs list pointer |
| Target id type at `+0xA4` | **Open** | Wrong default aim slot |
| Product name | **Open** | Cosmetic only |

---

## 3. Cross-check against raw / live / bytes

```
raw scaffold CF ≡ live decompile (2026-07-29).
read_memory @ 0x0056c860:
  55 8B EC 83 E4 F8 81 EC 24 0E 00 00   ; prologue, sub esp,0xE24
  ... call Weapon_ApplyShotHeatAndPowerCost ...
  F6 84 .. B8 00 00 00 10               ; test owner+0xB8 bit 0x10
  ... later mask 02 ...
exit:
  B0 01 / 32 C0 ... C2 04 00            ; return 1|0, ret 4
xrefs: DATA only @ 0x009d3320
vtable cluster: 009d331c=0056e000, 009d3320=0056c860 (siblings)
callees: Weapon_ApplyShotHeatAndPowerCost, FUN_007a4480,
         FUN_004d7e30, FUN_004da2e0 + vtbls
```

### Naming trap

Do **not** promote `Named_VOG_DEBUG_STOP_*` for this VA. The string is the same global assert used across hundreds of null-check sites. Structural name reflects **fire → resolve → dispatch**.

### ABI trap

Ghidra may list signature as `undefined FUN_0056c860(void)`. Bytes prove **`ret 4`**. Model:

```
Weapon_TryFireResolveHits(weapon, targetOrZero);  // thiscall
```

### Overlay trap

Do **not** treat `auStack_c88` as both a free-standing 3KB array and a raw integer count without mapping the `vtbl+0x50` result structure. Port must recover the resolve-result fields from that call, not invent parallel arrays.

---

## 4. Surviving contract for AutoCore

```
Weapon_TryFireResolveHits(weapon, targetOrZero) -> 0|1
  // thiscall; ret 4
  // FAIL: no owner | heat/power blocked | owner flags 0x10|0x02
  // OK path: zero hit buffer; default target from owner+0xA4 if 0;
  //          resolve = weapon.vtbl+0x50; maybe damage dispatch;
  //          maybe weapon.vtbl+0x48; return 1

AutoCore must NOT:
  - skip heat gate or reorder after resolve
  - ignore owner +0xB8 bits 0x10 / 0x02
  - invent product name from VOG_DEBUG_STOP
  - model as free function (vtable slot only)
  - assume two stack formals
  - reimplement damage math inside this VA
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Fire resolve + dispatch orchestrator | **Agree Confirmed** |
| Owner / heat / flag gates | **Agree Confirmed** |
| ret 4; one stack formal | **Agree Confirmed** |
| Vtable-only; sibling of 0056e000 | **Agree Confirmed** |
| VOG_DEBUG_STOP not product name | **Agree Confirmed** |
| Hit-buffer layout Open | **Agree** |
| clean ≡ raw ≡ live (CF) | **Agree** |
| accept-with-gaps | **Agree** |

**Verdict:** **accept-with-gaps**
