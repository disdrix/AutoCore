# Review A (reconstruction fidelity): `aa_007258a0` CSoundManager_TryQueueProximitySound_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007258a0` |
| **VA** | `0x007258a0` |
| **Canonical name** | `CSoundManager_TryQueueProximitySound_Inferred` |
| **Ghidra symbol** | `FUN_007258a0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_007258a0_CSoundManager_TryQueueProximitySound_Inferred.md` |
| **System** | client audio / `CSoundManager` / SpecialFX play |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**`__thiscall`** on `CSoundManager` (`ECX = this`): given an FX sound **descriptor** (`param_2`) and a **world position** (`float* param_3`), optionally **resolve a sound path**, **clone a play slot**, and **queue it** on the manager’s list. Returns **1** on success, **0** on any gate fail.

Authoritative stages (live ≡ raw):

1. **Master enable:** if **`*(char*)(this+600) == 0`** (`+0x258`) → return **0**.
2. **Type gate for 0xC / 0xD:** if `descriptor+0x104` is **12 or 13**, call **`FUN_00722b80(descriptor+0x120, +0x124, type)`**; non-zero → return **0** (busy/conflict).
3. **Proximity / zero-pos gate:**
   - If `length(param_3) <= g_flZero` **OR**
   - `ABS( (this.x@+0x220 - px)^2 + (this.z@+0x228 - pz)^2 ) <= (descriptor+0x114)^2`  
     (horizontal XZ distance vs radius at **`descriptor+0x114`**; note Y from length check only on zero-vector short-circuit)
   - Else fail → return **0**.
4. **Resolve source path:** `_Source = FUN_007249c0(descriptor, DAT_00d1a614)` — sound-file resolve (logs `"Sound file doesn't exist"`). Null → **0**.
5. **Alloc clone buffer:** `FUN_00480460` size query → `FUN_00480170` alloc (or null).
6. **Copy / patch clone:** `strncpy(_Dest, _Source, 0x104)`; copy TFID `@+0x120..+0x12C`, type `@+0x104`, flags `@+0x10b/+0x10c/+0x109→+0x131 inverted`, radii/params `@+0x110..+0x11c`, clear `@+0x150..+0x153`, set `@+0x154 = g_flOne`.
7. **Queue:** `FUN_00480350(this+0x310)` insert clone into manager list.
8. Return **1**.

**Callers:** `FUN_004b7e50` (primary), `FUN_009526f0`.

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Raw / annotated / clean | `aa_007258a0_*` | CF ≡ live |
| Live decompile | Ghidra `0x007258a0` | **≡ raw** |
| Resolve helper | `FUN_007249c0` + string evidence | High |
| Parent dual | `A_aa_004b7e50` | proximity play helper |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `thiscall` ECX = manager | **High** | uses `this+600`, `+0x220/+0x228`, `+0x310` |
| Enable flag at `+0x258` (600) | **High** | early out |
| Type 0xC/0xD special busy check | **High** | `FUN_00722b80` |
| XZ radius vs `descriptor+0x114` | **High** | squared compare; **Y of listener not in radius** |
| Zero-length position always passes proximity | **High** | first OR arm |
| Path resolve `FUN_007249c0` | **High** | sound-file string |
| Clone + `FUN_00480350(this+0x310)` | **High** | queue insert |
| Return 1/0 bool | **High** | |
| Product English name | **Probable** | |
| Exact meaning of types 0xC/0xD | **Medium** | residual |
| `DAT_00d1a614` role (base path / locale) | **Medium** | passed into resolve |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Enable gate | Yes |
| Type 0xC/0xD busy | Yes |
| Proximity OR zero-pos | Yes |
| Resolve path | Yes |
| Clone fields + queue | Yes |
| return 1 / 0 | Yes |

```text
bool TryQueueProximity(this, desc, pos3):
  if !this.enabled(+0x258): return false
  if desc.type in {0xC,0xD} and BusyCheck(...): return false
  if len(pos)==0 or xzDist2(this.listenXZ, pos.xz) <= desc.radius(+0x114)^2:
    path = ResolveSoundPath(desc)
    if !path: return false
    slot = CloneSlot(path, desc fields...)
    Queue(this+0x310, slot)
    return true
  return false
```

---

## 5. Callers / callees

**Callees:** `FUN_00722b80`, `FUN_007249c0`, `FUN_00480460`, `FUN_00480170`, `strncpy`, `FUN_00480350`, `SQRT`/`ABS`/`g_flZero`/`g_flOne`.

**Callers:** `FUN_004b7e50`, `FUN_009526f0`.

---

## 6. Gaps / open

1. Duals for `FUN_00722b80`, `FUN_007249c0`, `FUN_00480350`.
2. Listener position fields `+0x220/+0x228` update site.
3. Why ABS applied to already-squared sum (always non-negative) — likely compiler artifact; port as `dist2 <= r2`.
4. Runtime not run.

**Verdict:** **accept-with-gaps** — gates, proximity math, clone/queue sealed.
