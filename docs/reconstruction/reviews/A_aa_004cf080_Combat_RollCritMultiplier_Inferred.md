# Review A (reconstruction fidelity): `aa_004cf080` Combat_RollCritMultiplier_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cf080` |
| **VA** | `0x004cf080`–`0x004cf0f4` |
| **Canonical name** | `Combat_RollCritMultiplier_Inferred` |
| **Ghidra name** | `FUN_004cf080` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W21-I) |
| **Counterpart** | `reviews/B_aa_004cf080_Combat_RollCritMultiplier_Inferred.md` |
| **System** | combat-crit |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory`; callers `0x0056e000`, `0x0058c850` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Roll a **crit damage multiplier** for weapon/skill hit application:

1. Null attacker → **1.0**.
2. `level = attacker->vtbl[+0x27c]()` (int).
3. `chance = FUN_004cef70(attacker, target)`.
4. If `(roll % 100) <= chance * 100.0` → **`level * 0.01 + ~1.2`**.
5. Else → **1.0**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004cf080_FUN_004cf080.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_004cf080_FUN_004cf080.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Combat_RollCritMultiplier_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004cf080.cpp` |
| Function record | `docs/reconstruction/functions/aa_004cf080_FUN_004cf080.md` |
| Callers | `Weapon_ApplyDamageToTargets_Inferred`, `Skill_ApplyMultiTargetHits_Inferred` |
| Live | decompile ≡ raw; `read_memory` 117 B body; constants sealed |

---

## 3. Signature (sealed)

```c
// cdecl; ST0 return
float Combat_RollCritMultiplier_Inferred(void *attacker, void *target, uint16_t roll);
```

| Formal | Source | Conf |
|---|---|---|
| attacker | stack +0x4 → ESI; null gate | **High** |
| target | stack +0x8 → `FUN_004cef70` arg | **High** |
| roll | stack +0xC word; `% 100` | **High** |
| Return | ST0; miss/null = `g_flOne` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if attacker == 0: return 1.0
level  = vcall(attacker, +0x27c)
chance = FUN_004cef70(attacker, target)
if (roll % 100) <= chance * 100.0:
  return level * 0.01 + ~1.2
return 1.0
```

| Stage | Match | Conf |
|---|---|---|
| Null early exit | **Yes** | **High** |
| Level via `vtbl+0x27c` + FILD | **Yes** | **High** |
| Chance callee `0x004cef70` | **Yes** | **High** |
| `% 100` + `* 100.0` compare | **Yes** | **High** |
| Mult `*0.01 + ~1.2` (doubles) | **Yes** | **High** |
| Miss → `g_flOne` | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Hex body (117 B):
```
51568b74240c85f674628b068bceff907c0200008944240cdb44240cd95c24040fb744241499b964000000f7f98954240cdb44240c8b5424105256d95c2414e8acfeffffd80daca7aa00d944241483c408d9c9dff1ddd87213d94424045edc0dc8c19c00dc05c0c19c0059c3d905a0f2a0005e59c3
```

| Constant | VA | Value |
|---|---|---|
| percent | `0x00aaa7ac` | `100.0f` |
| scale | `0x009cc1c8` | double `0.01` |
| base | `0x009cc1c0` | double `≈1.2000000476837158` |
| one | `0x00a0f2a0` | `1.0f` |

Callee target: **`FUN_004cef70` @ `0x004cef70`**.

---

## 6. Confidence / gaps

| Claim | Conf |
|---|---|
| CF + formula | **High** |
| Two combat callers | **High** |
| Product English name | **Open** (inferred OK) |
| `vtbl+0x27c` always level | **Probable** |
| Chance semantics of `FUN_004cef70` | **Open** (residual dual) |
| Runtime distribution | **Open** |

**Verdict: accept-with-gaps** — formula and CF sealed; product names / chance helper dual residual.
