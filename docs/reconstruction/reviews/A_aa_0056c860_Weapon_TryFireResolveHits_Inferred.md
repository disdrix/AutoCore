# Review A (reconstruction fidelity): `aa_0056c860` Weapon_TryFireResolveHits_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056c860` |
| **VA** | `0x0056c860` |
| **Canonical name** | `Weapon_TryFireResolveHits_Inferred` (was `FUN_0056c860`) |
| **Ghidra symbol** | `FUN_0056c860` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0056c860_Weapon_TryFireResolveHits_Inferred.md` |
| **System** | combat / vehicle weapon |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Weapon fire attempt + hit resolve + damage dispatch** vtable worker.

1. Resolve **owner** via adjustor-`this` + **`vtbl+0x214`**; fail if null.
2. **`Weapon_ApplyShotHeatAndPowerCost(this)`** — fail if low-byte zero.
3. Re-fetch owner; reject if status byte at **`owner_adj+0xB8`** has **`0x10`** or **`0x02`**.
4. Zero 100 dwords of hit work buffer; if stack **`targetOrZero == 0`**, load owner selected target at **`owner_adj+0xA4`**.
5. **`weapon vtbl+0x50`(target, hitBuf, &flags)** — resolve shot.
6. If hit-count field &gt; 0 **or** resolve returned 0: null-host assert (`VOG_DEBUG_STOP`), set flags low byte 1, dispatch **`FUN_004d7e30`** (null list) or **`FUN_004da2e0`** (list).
7. If resolve ≠ 0: **`weapon vtbl+0x48`(resolve, scratch16)**.
8. Return **1** on gated path; **0** if any gate failed.

`"VOG_DEBUG_STOP"` is a **null-host debug assert** only — **not** a product name for this VA.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0056c860_FUN_0056c860.md` |
| Annotated | `docs/reconstruction/raw/aa_0056c860_FUN_0056c860.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0056c860.cpp` |
| Function record | `docs/reconstruction/functions/aa_0056c860_FUN_0056c860.md` |
| Fresh decompile | Ghidra `decompile_function` @ `0x0056c860` (2026-07-29) |
| Complete analysis | Ghidra `analyze_function_complete` — worker; DATA xref only |
| Bytes | `read_memory` entry `55 8B EC 83 E4 F8 81 EC 24 0E 00 00`; exit **`C2 04 00`**; fail **`32 C0`**, success **`B0 01`** |
| Body range | `0x0056c860` – `0x0056ca6a` |
| Vtable | DATA `@ 0x009d3320` (neighbor `0x0056e000` @ `0x009d331c`) |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Signature `__thiscall(weapon*, int targetOrZero)`; **ret 4** | **Confirmed** | `C2 04 00`; one stack formal |
| Owner via adj + `vtbl+0x214` | **Confirmed** | repeated in all gates |
| Heat/power gate before fire | **Confirmed** | call to `Weapon_ApplyShotHeatAndPowerCost` |
| Owner `+0xB8` bits `0x10` and `0x02` block fire | **Confirmed** | `test byte` masks in body |
| Zero target → owner `+0xA4` fill | **Confirmed** | body |
| Resolve via `vtbl+0x50` | **Confirmed** | body |
| Damage dispatch `004d7e30` / `004da2e0` | **Confirmed** | null-list vs list branch |
| Post-step `vtbl+0x48` when resolve ≠ 0 | **Confirmed** | body |
| Return 1 gated / 0 fail | **Confirmed** | `B0 01` / `32 C0` |
| Vtable-only entry (no direct callers) | **Confirmed** | single DATA xref |
| `"VOG_DEBUG_STOP"` is product name | **Falsified** | assert-only string |
| Hit-buffer field map (count vs pointer overlay) | **Open** | Ghidra stack overlay |
| Exact English of `vtbl+0x50` / `+0x48` | **Open** | callee duals |
| Product RTTI class | **Open** | structural `_Inferred` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Owner null → return 0 | Yes |
| Heat fail → return 0 | Yes |
| Flag 0x10 / 0x02 → return 0 | Yes |
| Zero hit buffer; default target | Yes |
| vtbl+0x50 resolve | Yes |
| Damage dispatch branch | Yes |
| vtbl+0x48 post | Yes |
| return 1 / 0 | Yes |
| No invent product name from assert string | Yes |

### Recovered CF

```c
// uint32_t __thiscall Weapon_TryFireResolveHits(Weapon *this, int targetOrZero)
// ret 4
if (!Owner(this) || !Weapon_ApplyShotHeatAndPowerCost(this)) return 0;
if (OwnerFlags(this) & 0x10) return 0;
if (OwnerFlags(this) & 0x02) return 0;
// clear hitBuf; if targetOrZero==0: target = OwnerSelected(+0xA4)
resolve = this->vtbl[+0x50](target, hitBuf, &flags);
if (hitCount > 0 || resolve == 0) {
  if (Host(this) == 0) DebugStop("VOG_DEBUG_STOP");
  flags.b0 = 1;
  if (hitList == 0) FUN_004d7e30(...self...);
  else              FUN_004da2e0(...list...);
}
if (resolve) this->vtbl[+0x48](resolve, scratch16);
return 1;
```

---

## 5. Callers / callees

| Kind | Site / symbol |
|---|---|
| Callers | virtual only via vtable `@0x009d3320` |
| Callees | `Weapon_ApplyShotHeatAndPowerCost`, `FUN_007a4480`, `FUN_004d7e30`, `FUN_004da2e0`, owner `+0x214`, weapon `+0x50`, weapon `+0x48` |
| Sibling | `Weapon_ApplyDamageToTargets_Inferred` (`0x0056e000`) — adjacent vtable slot |

---

## 6. Gaps / open

1. Product / RTTI name for weapon class (keep structural `_Inferred`).
2. Full hit work-buffer schema (decompiler overlays `auStack_c88` as count and pointer).
3. Exact roles of `vtbl+0x50` / `vtbl+0x48` / damage callees — owned by those VAs.
4. Runtime / bit-exact image diff.

**Verdict:** **accept-with-gaps**
