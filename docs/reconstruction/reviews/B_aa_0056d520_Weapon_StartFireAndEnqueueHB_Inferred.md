# Review B (skeptical / adversarial): `aa_0056d520` Weapon_StartFireAndEnqueueHB_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056d520` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0056d520_Weapon_StartFireAndEnqueueHB_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Also heat-checks weapon | Body has no heat probe; heat is `FUN_004f5290` at input parent | **Falsified** |
| 2 | Vehicle thiscall (ECX=vehicle) | Parents load hardpoint weapon\* into ECX; body writes weapon flag offsets | **Falsified** |
| 3 | Returns void / always succeeds | Explicit `return 0` on `+0xCB`; `return 1` otherwise | **Falsified** |
| 4 | Clears fire flags | Writes **1** to `+0xC7/+0xC8/+0xC9`; clear is `Weapon_SetFireFlagPair(…,0)` elsewhere | **Falsified** |
| 5 | Fires all hardpoints itself | Unit is per-weapon; multi-slot loop is `004f50d0` / `004f5110` | **Falsified** |
| 6 | Many callers (AI, skills, UI) | Only 2 xrefs: primary + secondary fire-all | **Falsified multi-caller** |
| 7 | Product name sealed retail | No string/RTTI | **Hold `_Inferred`** |
| 8 | `+0xCB` is “ammo empty” | Sibling notes: `FUN_0056b400` sets `+0xCB`; English open | **English residual**; CF “nonzero blocks start” sealed |
| 9 | No HB / only flags | Alloc + Enqueue + Start present | **Falsified “flags only”** |
| 10 | Same as SetFireFlagPair | SetFireFlagPair is leaf dual-byte write; this unit adds `+0xC9`, prep, HB | **Falsified as identical** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `+0xCB` early-out | **High** | Fire when blocked / never fire |
| Flag latch `+0xC7/+0xC8/+0xC9` | **High** | Stuck fire chrome / recovery miss |
| HB enqueue+start | **High** | Miss continuous fire tick |
| Caller set = fire-all only (static) | **High** | Miss alternate start path if dynamic |
| `FUN_0056d160` product | **Probable** | Miss net/ammo side effect |
| HB ctor arg framing | **Probable** | Wrong period / owner attach in port |
| Product name | **Inferred** | Cosmetic registry only |

---

## 3. Cross-check against raw

```
if weapon[+0xCB]: return 0
optional FUN_00514ff0
[+0xC7]=1; maybe [+0xC8]=1; [+0xC9]=1
FUN_0056d160(global,0)
new 0x24 → FUN_005fe6a0 → Enqueue → Start
return 1
```

Live Ghidra re-decompile 2026-07-29 matches 2026-07-23 raw. Callers sealed: `FUN_004f50d0`, `FUN_004f5110` only.

---

## 4. Surviving contract for AutoCore

```
Client hardpoint weapon start (after caller group filter + heat):
  Weapon_StartFireAndEnqueueHB_Inferred(weapon):
    if weapon.blockFlag(+0xCB): return false
    latch fireDesired(+0xC7)=1, fireLatched(+0xC8)=1 if needed, fireExtra(+0xC9)=1
    shared prep FUN_0056d160
    spawn weapon-fire HB (0x24), enqueue on owner list, Start
    return true

Do NOT:
  - put heat or hardpoint walk inside this unit
  - treat as vehicle thiscall
  - assume return always 1
  - use for clear/recovery (use SetFireFlagPair 0)
```

---

## 5. Open questions

1. Live: `+0xCB` set mid-burst → next StartFire returns 0; fire-all aggregate may still OR siblings.
2. English for `+0xC9` vs `+0xC7/+0xC8` pair (third latch).
3. Full `FUN_0056d160` / HB vtbl product names.
4. Runtime / diff / bit-exact.

**Verdict:** **accept-with-gaps**
